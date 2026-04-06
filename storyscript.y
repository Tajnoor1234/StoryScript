%{
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <unistd.h>

using namespace std;

extern int yylex();
extern FILE *yyin;
extern int yylineno;
void yyerror(const char *s);
typedef void* YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char *);

map<string,int> symbolTable;
bool hasSyntaxError = false;
bool hasSemanticError = false;

/* AST Node */
struct Node{
    string type;
    string id;
    int value;
    int line;

    Node *left;
    Node *right;

    vector<Node*> children;

    Node(string t){
        type=t;
        value=0;
        line=0; 
        left=right=nullptr;
    }
};

map<string, Node*> functionTable;

Node* root=nullptr;

int tempCount = 0;
int labelCount = 0;

string newTemp() {
    return "t" + to_string(tempCount++);
}

string newLabel() {
    return "L" + to_string(labelCount++);
}

int eval(Node* n);
void exec(Node* n);

string generateExpr(Node* n);
void generateIR(Node* n);

string genExpr(Node* n, int lang);
void generateCode(Node* n, int lang, int indent = 0);
string indentStr(int indent);

int getLine()
{
    return yylineno - 1;
}

void printCompilerHeader()
{
    cout << "\n=====================================\n";
    cout << "        StoryScript Compiler v1.0\n";
    cout << "=====================================\n";
}

void printPhase(string phase)
{
    cout << "[COMPILER] " << phase << " completed.\n";
}
%}

/* forward declaration for header */
%code requires {
    struct Node;
}

%locations

%union{
    int num;
    char* id;
    Node* node;
}

/* tokens */
%token STORY BEGINS ENDSTORY
%token CHARACTER HOLDS
%token WHEN OTHERWISE ENDCHOICE
%token DURING JOURNEY ENDCYCLE
%token CHAPTER TAKES RETURN ENDCHAPTER
%token NARRATE LISTEN

%token <id> IDENTIFIER
%token <num> NUMBER

%token PLUS MINUS MUL DIV MOD
%token ASSIGN
%left PLUS MINUS
%left MUL DIV MOD
%token GT LT GE LE EQ NE
%token AND OR NOT
%left OR
%left AND
%right NOT

%token LBRACE RBRACE
%token LPAREN RPAREN
%token SEMICOLON COMMA

/* node types */
%type <node> program statement_list statement
%type <node> declaration assignment conditional loop function
%type <node> output input expression condition parameter_list argument_list


%%

program
: STORY IDENTIFIER BEGINS statement_list ENDSTORY
{
    root = $4;
}
;

statement_list
: statement
{
    Node* n = new Node("block");
    n->children.push_back($1);
    $$ = n;
}
| statement_list statement
{
    $1->children.push_back($2);
    $$ = $1;
}
;

statement
: declaration
| assignment
| conditional
| loop
| function
| input
| output
| error SEMICOLON   { 
      hasSyntaxError = true; 
      yyerrok; 
      cout << "Recovered from syntax error\n"; 
  }
;

declaration
: CHARACTER IDENTIFIER HOLDS expression SEMICOLON
{
    Node* n = new Node("declare");
    n->id = $2;
    n->left = $4;
    n->line = @2.first_line;
    $$ = n;
}
| CHARACTER IDENTIFIER HOLDS expression
{
    hasSyntaxError = true;
    cout << "Line " << @4.first_line << ": Missing ';' after declaration\n";
}
;

assignment
: IDENTIFIER HOLDS expression SEMICOLON
{
    Node* n = new Node("assign");
    n->id = $1;
    n->left = $3;
    n->line = @1.first_line;
    $$ = n;
}
| IDENTIFIER HOLDS expression
{
    hasSyntaxError = true;
    cout << "Line " << @3.first_line << ": Missing ';' after assignment\n";
}
;

output
: NARRATE expression SEMICOLON
{
    Node* n = new Node("print");
    n->left = $2;
    $$ = n;
}
| NARRATE expression
{
    hasSyntaxError = true;
    cout << "Line " << @2.first_line << ": Missing ';' after narrate\n";
}
;

input
: LISTEN IDENTIFIER SEMICOLON
{
    Node* n = new Node("input");
    n->id = $2;
    $$ = n;
}
;

conditional
: WHEN condition statement_list OTHERWISE statement_list ENDCHOICE
{
    Node* n = new Node("if");
    n->left = $2;
    n->children.push_back($3);
    n->children.push_back($5);
    $$ = n;
}
;

loop
: DURING condition statement_list ENDCYCLE
{
    Node* n = new Node("loop");
    n->left = $2;
    n->children.push_back($3);
    $$ = n;
}
;

function
: CHAPTER IDENTIFIER TAKES parameter_list statement_list RETURN expression ENDCHAPTER
{
    Node* n = new Node("function");
    n->id = $2;
    n->line = @2.first_line;
    n->children.push_back($4);
    n->children.push_back($5);
    n->left = $7;
    $$ = n;
}
| CHAPTER IDENTIFIER TAKES parameter_list RETURN expression ENDCHAPTER
{
    Node* n = new Node("function");
    n->id = $2;
    n->line = @2.first_line;
    n->children.push_back($4);

    Node* emptyBody = new Node("block");   // ✅ empty body
    n->children.push_back(emptyBody);

    n->left = $6;
    $$ = n;
}
;

parameter_list
: IDENTIFIER
{
    Node* n = new Node("param");
    n->id = $1;
    n->line = @1.first_line;
    $$ = n;
}
| IDENTIFIER COMMA parameter_list
{
    Node* n = new Node("param");
    n->id = $1;
    if($3) n->children.push_back($3);
    $$ = n;
}
;

argument_list
: expression
{
    Node* n = new Node("arg");
    n->children.push_back($1);
    $$ = n;
}
| expression COMMA argument_list
{
    Node* n = new Node("arg");
    n->children.push_back($1);
    if($3) n->children.push_back($3);
    $$ = n;
}
;

/* conditions */

condition
: expression GT expression
{
    Node* n = new Node("gt");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| expression LT expression
{
    Node* n = new Node("lt");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| expression EQ expression
{
    Node* n = new Node("eq");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| expression NE expression
{
    Node* n = new Node("ne");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| expression GE expression
{
    Node* n = new Node("ge");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| expression LE expression
{
    Node* n = new Node("le");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| condition AND condition
{
    Node* n = new Node("and");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| condition OR condition
{
    Node* n = new Node("or");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| NOT condition
{
    Node* n = new Node("not");
    n->left = $2;
    $$ = n;
}
| LPAREN condition RPAREN
{
    $$ = $2;
}
;
/* expressions */

expression
: expression PLUS expression
{
    Node* n = new Node("add");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| expression MINUS expression
{
    Node* n = new Node("sub");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| expression MUL expression
{
    Node* n = new Node("mul");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| expression DIV expression
{
    Node* n = new Node("div");
    n->left = $1;
    n->right = $3;
    $$ = n;
}
| LPAREN expression RPAREN
{
    $$ = $2;
}
| NUMBER
{
    Node* n = new Node("num");
    n->value = $1;
    $$ = n;
}
| IDENTIFIER
{
    Node* n = new Node("var");
    n->id = $1;
    n->line = @1.first_line;
    $$ = n;
}
| IDENTIFIER LPAREN argument_list RPAREN
{
    Node* n = new Node("call");
    n->id = $1;
    n->children.push_back($3);
    n->line = @1.first_line;
    $$ = n;
}
;

%%

/* expression evaluation */

int eval(Node* n)
{
    if(n->type=="num") return n->value;

    if(n->type=="var")
    {
        if(symbolTable.find(n->id) == symbolTable.end())
        {
            cout << "Semantic Error (Line " << n->line << "): Variable '" << n->id << "' not declared\n";
            hasSemanticError = true;
            return 0; // continue execution
        }
        return symbolTable[n->id];
    }

    if(n->type=="add") return eval(n->left)+eval(n->right);
    if(n->type=="sub") return eval(n->left)-eval(n->right);
    if(n->type=="mul") return eval(n->left)*eval(n->right);
    if(n->type=="div") return eval(n->left)/eval(n->right);

    if(n->type=="gt") return eval(n->left)>eval(n->right);
    if(n->type=="lt") return eval(n->left)<eval(n->right);
    if(n->type=="and") return eval(n->left)&&eval(n->right);
    if(n->type=="or") return eval(n->left)||eval(n->right);
    if(n->type=="not") return !eval(n->left);
    if(n->type=="eq") return eval(n->left)==eval(n->right);
    if(n->type=="ne") return eval(n->left)!=eval(n->right);
    if(n->type=="ge") return eval(n->left)>=eval(n->right);
    if(n->type=="le") return eval(n->left)<=eval(n->right);
    
    if(n->type == "call"){

       if(functionTable.find(n->id) == functionTable.end()){
           cout << "Semantic Error (Line " << n->line 
             << "): Function '" << n->id << "' not defined\n";
           hasSemanticError = true;
           return 0;
       }

       Node* func = functionTable[n->id];


       map<string,int> oldTable = symbolTable;

    
       vector<string> params;
       Node* p = func->children[0];

       while(p){
           params.push_back(p->id);
           if(p->children.empty()) break;
           p = p->children[0];
       }

   
       vector<int> args;
       Node* argNode = n->children[0];

       while(argNode){
           args.push_back(eval(argNode->children[0]));

           if(argNode->children.size() < 2) break;
           argNode = argNode->children[1];
       }

    
       if(params.size() != args.size()){
           cout << "Semantic Error (Line " << n->line 
             << "): Argument count mismatch in function '" << n->id << "'\n";
           hasSemanticError = true;
           return 0;
       }

    
       symbolTable.clear();

       for(int i = 0; i < params.size(); i++){
           symbolTable[params[i]] = args[i];
       }

   
       exec(func->children[1]);

    
       int ret = eval(func->left);

       symbolTable = oldTable;

       return ret;
    }

    return 0;
}

void checkParams(Node* p, string fname) {
    map<string, bool> seen;

    while(p){
        if(seen[p->id]){
            cout << "Semantic Error (Line " << p->line 
             << "): Duplicate parameter '" << p->id 
             << "' in function '" << fname << "'\n";
            hasSemanticError = true;
            return;
        }
        seen[p->id] = true;

        if(p->children.empty()) break;
        p = p->children[0];
    }
}

/* execute AST */

void exec(Node* n)
{
    if(!n) return;

    if(n->type=="block"){
        for(auto c:n->children)
            exec(c);
    }

    else if(n->type=="declare"){
        symbolTable[n->id]=eval(n->left);
        cout<<"Declared "<<n->id<<" = "<<symbolTable[n->id]<<endl;
    }

    else if(n->type=="assign"){
        int val = eval(n->left);

        if(symbolTable.find(n->id) == symbolTable.end()){
            cout << "Semantic Error (Line " << n->line << "): Variable '" << n->id << "' not declared\n";
            hasSemanticError = true;
        } else {
        symbolTable[n->id] = val;
        cout << n->id << " updated to " << symbolTable[n->id] << endl;
       }
    }

    else if(n->type=="print"){
        cout<<eval(n->left)<<endl;
    }

    else if(n->type=="input"){
        int val = 0;

        cout<<"Enter value for "<<n->id<<": ";

        if(!(cin >> val)){
             cout<<"Invalid input. Default value 0 used.\n";
             cin.clear();
        }

        symbolTable[n->id]=val;
   }

    else if(n->type=="if"){
        if(eval(n->left)){
             if(n->children.size()>0) exec(n->children[0]);
        }
        else{
             if(n->children.size()>1) exec(n->children[1]);
        }
    }

    else if(n->type=="loop"){
        while(eval(n->left)){
            exec(n->children[0]);
        }
    }

    else if(n->type=="function"){

    
        if(functionTable.find(n->id) != functionTable.end()){
            cout << "Semantic Error (Line " << n->line 
             << "): Function '" << n->id << "' already defined\n";
            hasSemanticError = true;
            return;
        }

    
        functionTable[n->id] = n;


        if(n->left == nullptr){
            cout << "Semantic Error (Line " << n->line 
             << "): Function '" << n->id 
             << "' missing return value\n";
            hasSemanticError = true;
        }

    
        checkParams(n->children[0], n->id);

        cout << "Function " << n->id << " registered" << endl;
     }
}

// ================= INTERMEDIATE CODE =================

string generateExpr(Node* n) {
    if (!n) return "";
    if (n->type == "num") return to_string(n->value);
    if (n->type == "var") return n->id;
    if (n->type == "call") {
       string temp = newTemp();

       string args = "";
       Node* argNode = n->children[0];

       vector<string> argList;

       while(argNode){
           argList.push_back(generateExpr(argNode->children[0]));

           if(argNode->children.size() < 2) break;
           argNode = argNode->children[1];
       }

       for(int i = 0; i < argList.size(); i++){
           args += argList[i];
           if(i != argList.size() - 1) args += ", ";
       }

       cout << temp << " = call " << n->id << ", " << args << endl;

       return temp;
    }
    

    string left = generateExpr(n->left);
    string right = generateExpr(n->right);

    string temp = newTemp();

    string op;
    if (n->type == "add") op = "+";
    if (n->type == "sub") op = "-";
    if (n->type == "mul") op = "*";
    if (n->type == "div") op = "/";
    if (n->type == "gt") op = ">";
    if (n->type == "lt") op = "<";
    if (n->type == "and") op = "&&";
    if (n->type == "or") op = "||";
    if (n->type == "eq") op = "==";
    if (n->type == "ne") op = "!=";
    if (n->type == "ge") op = ">=";
    if (n->type == "le") op = "<=";

    cout << temp << " = " << left << " " << op << " " << right << endl;

    return temp;
}

void generateIR(Node* n) {
    if (!n) return;

    if (n->type == "block") {
        for (auto c : n->children)
            generateIR(c);
    }

    else if (n->type == "declare") {
        string val = generateExpr(n->left);
        cout << n->id << " = " << val << endl;
    }

    else if (n->type == "assign") {
        string val = generateExpr(n->left);
        cout << n->id << " = " << val << endl;
    }

    else if (n->type == "print") {
        string val = generateExpr(n->left);
        cout << "print " << val << endl;
    }

    else if (n->type == "input") {
        cout << "read " << n->id << endl;
    }

    else if (n->type == "if") {
        string cond = generateExpr(n->left);

        string L1 = newLabel();
        string L2 = newLabel();

        cout << "ifFalse " << cond << " goto " << L1 << endl;

        generateIR(n->children[0]);
        cout << "goto " << L2 << endl;

        cout << L1 << ":" << endl;
        if (n->children.size() > 1)
            generateIR(n->children[1]);

        cout << L2 << ":" << endl;
    }

    else if (n->type == "loop") {
        string Lstart = newLabel();
        string Lend = newLabel();

        cout << Lstart << ":" << endl;

        string cond = generateExpr(n->left);
        cout << "ifFalse " << cond << " goto " << Lend << endl;

        generateIR(n->children[0]);

        cout << "goto " << Lstart << endl;
        cout << Lend << ":" << endl;
    }

    else if (n->type == "function") {
        cout << "\nfunction " << n->id << ":" << endl;

        Node* params = n->children[0];
        while (params) {
            cout << "param " << params->id << endl;
            if (params->children.empty()) break;
            params = params->children[0];
        }

        generateIR(n->children[1]);

        string ret = generateExpr(n->left);
        cout << "return " << ret << endl;

        cout << "end function\n";
    }
}

void generateFunctions(Node* n, int lang) {
    if (!n) return;

    if (n->type == "function") {
        generateCode(n, lang, 0); // print globally
    }

    for (auto c : n->children)
        generateFunctions(c, lang);
}

// ================= TARGET CODE GENERATION =================

string indentStr(int indent) {
    return string(indent * 4, ' ');
}

string genExpr(Node* n, int lang) {
    if (n->type == "num") return to_string(n->value);
    if (n->type == "var") return n->id;
    if (n->type == "call") {
       string args = "";

       Node* argNode = n->children[0];

       vector<string> argList;

       while(argNode){
           argList.push_back(genExpr(argNode->children[0], lang));

           if(argNode->children.size() < 2) break;
           argNode = argNode->children[1];
       }

       for(int i = 0; i < argList.size(); i++){
           args += argList[i];
           if(i != argList.size() - 1) args += ", ";
       }

       return n->id + "(" + args + ")";
   }
    

    string left = genExpr(n->left, lang);
    string right = (n->right) ? genExpr(n->right, lang) : "";

    string op;

    if (n->type == "add") op = "+";
    if (n->type == "sub") op = "-";
    if (n->type == "mul") op = "*";
    if (n->type == "div") op = "/";
    if (n->type == "gt") op = ">";
    if (n->type == "lt") op = "<";
    if (n->type == "eq") op = "==";
    if (n->type == "ne") op = "!=";
    if (n->type == "ge") op = ">=";
    if (n->type == "le") op = "<=";

    if (n->type == "and")
        op = (lang == 4) ? "and" : "&&";

    if (n->type == "or")
        op = (lang == 4) ? "or" : "||";

    if (n->type == "not") {
        if (lang == 4)
            return "not " + left;
        else
            return "!(" + left + ")";
    }

    return "(" + left + " " + op + " " + right + ")";
}

void generateCode(Node* n, int lang, int indent) {
    if (!n) return;

    string ind = indentStr(indent);

    if (n->type == "block") {
       for (auto c : n->children) {
           if (c->type != "function") 
               generateCode(c, lang, indent);
      }
    }

    else if (n->type == "declare") {
        string val = genExpr(n->left, lang);

        if (lang == 4)
            cout << ind << n->id << " = " << val << "\n";
        else
            cout << ind << "int " << n->id << " = " << val << ";\n";
    }

    else if (n->type == "assign") {
        string val = genExpr(n->left, lang);
        cout << ind << n->id << " = " << val << (lang==4 ? "" : ";") << "\n";
    }

    else if (n->type == "print") {
        string val = genExpr(n->left, lang);

        if (lang == 1)
            cout << ind << "printf(\"%d\\n\", " << val << ");\n";
        else if (lang == 2)
            cout << ind << "cout << " << val << " << endl;\n";
        else if (lang == 3)
            cout << ind << "System.out.println(" << val << ");\n";
        else
            cout << ind << "print(" << val << ")\n";
    }

    else if (n->type == "input") {
        if (lang == 1)
            cout << ind << "scanf(\"%d\", &" << n->id << ");\n";
        else if (lang == 2)
            cout << ind << "cin >> " << n->id << ";\n";
        else if (lang == 3)
            cout << ind << n->id << " = scanner.nextInt();\n";
        else
            cout << ind << n->id << " = int(input())\n";
    }

    else if (n->type == "if") {
        string cond = genExpr(n->left, lang);

        if (lang == 4)
            cout << ind << "if " << cond << ":\n";
        else
            cout << ind << "if (" << cond << ") {\n";

        generateCode(n->children[0], lang, indent + 1);

        if (lang == 4)
            cout << ind << "else:\n";
        else
            cout << ind << "} else {\n";

        if (n->children.size() > 1)
            generateCode(n->children[1], lang, indent + 1);

        if (lang != 4)
            cout << ind << "}\n";
    }

    else if (n->type == "loop") {
        string cond = genExpr(n->left, lang);

        if (lang == 4)
            cout << ind << "while " << cond << ":\n";
        else
            cout << ind << "while (" << cond << ") {\n";

        generateCode(n->children[0], lang, indent + 1);

        if (lang != 4)
            cout << ind << "}\n";
    }

    else if (n->type == "function") {

    // extract parameters
    vector<string> params;
    Node* p = n->children[0];

    while (p) {
        params.push_back(p->id);
        if (p->children.empty()) break;
        p = p->children[0];
    }

    if (lang == 4) {
        cout << "\ndef " << n->id << "(";
    }
    else if (lang == 3) {
        cout << "\nstatic int " << n->id << "(";
    }
    else {
        cout << "\nint " << n->id << "(";
    }

    // print params
    for (int i = 0; i < params.size(); i++) {
        if (lang == 4)
            cout << params[i];
        else
            cout << "int " << params[i];

        if (i != params.size() - 1) cout << ", ";
    }

    if (lang == 4)
        cout << "):\n";
    else
        cout << ") {\n";

    generateCode(n->children[1], lang, indent + 1);

    string ret = genExpr(n->left, lang);
    cout << indentStr(indent+1) << "return " << ret << (lang==4 ? "" : ";") << "\n";

    if (lang != 4)
        cout << "}\n";
}
}

void printErrorBanner()
{
    cout << "\n=====================================\n";
    cout << "           COMPILATION ERROR\n";
    cout << "=====================================\n";
}

void printAST(Node* n, int depth = 0)
{
    if(!n) return;

    for(int i=0;i<depth;i++)
        cout << "  ";

    cout << "|-- " << n->type;

    if(n->id != "")
        cout << " (" << n->id << ")";

    if(n->type == "num")
        cout << " = " << n->value;

    cout << endl;

    if(n->left)
        printAST(n->left, depth+1);

    if(n->right)
        printAST(n->right, depth+1);

    for(auto c : n->children)
        printAST(c, depth+1);
}

void printSymbolTable()
{
    cout << "\n---------------------------------\n";
    cout << "Symbol Table\n";
    cout << "---------------------------------\n";

    for(auto &p : symbolTable)
    {
        cout << p.first << " : " << p.second << endl;
    }

    cout << "---------------------------------\n";
}

void yyerror(const char *s)
{
    extern int yylineno;

    hasSyntaxError = true;

    printErrorBanner();

    cout << "Line: " << getLine() << endl;

    if(string(s) == "syntax error")
        cout << "Error: Invalid syntax near this line\n";
    else
        cout << "Error: " << s << endl;

    cout << "=====================================\n";
}

int main(int argc, char* argv[])
{
    printCompilerHeader();

    int targetLang;
    cout << "\nSelect Target Language:\n";
    cout << "1. C\n2. C++\n3. Java\n4. Python\nChoice: ";
    cin >> targetLang;

    cout << "\n[COMPILER] Starting Lexical Analysis...\n";

    /* Input handling */
    if(argc > 1)
    {
        FILE *fp = fopen(argv[1], "r");

        if(!fp)
        {
            cout << "Error: Cannot open " << argv[1] << endl;
            return 1;
        }

        yyin = fp;
    }
    else
    {
        cout << "[COMPILER] Enter StoryScript program (CTRL+D to finish)\n\n";

        string program;
        char buffer[1024];
        int n;

        while((n = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
        {
            program.append(buffer, n);
        }
        yylineno = 1;

        yy_scan_string(program.c_str());
    }

    /* Parsing */
    yyparse();

    /* STOP if syntax error */
    if(hasSyntaxError){
        cout << "\n[COMPILER] Syntax Analysis Failed\n";
        return 1;
    }

    printPhase("Lexical Analysis");
    printPhase("Syntax Analysis");
    printPhase("AST Generation");

    cout << "\n================ AST ================\n";
    if(root)
        printAST(root);
    cout << "=====================================\n";

    
    cout << "\n[COMPILER] Executing Program...\n\n";

    exec(root);

    
    if(hasSemanticError){
        cout << "\n[COMPILER] Semantic Analysis Failed\n";
        return 1;
    }

    cout << "\n[COMPILER] Intermediate Code Generation...\n\n";
    generateIR(root);
    
    cout << "\n[COMPILER] Target Code Generation...\n\n";
    
    

   /* ================= C ================= */
    if (targetLang == 1) {
       cout << "#include <stdio.h>\n\n";

       generateFunctions(root, targetLang);

       cout << "int main() {\n";
       generateCode(root, targetLang);
       cout << "return 0;\n}\n";
   }

   /* ================= C++ ================= */
    else if (targetLang == 2) {
       cout << "#include <iostream>\nusing namespace std;\n\n";

       generateFunctions(root, targetLang);   

       cout << "int main() {\n";
       generateCode(root, targetLang);
       cout << "return 0;\n}\n";
    }

    /* ================= JAVA ================= */
    else if (targetLang == 3) {
       cout << "import java.util.*;\n\n";
       cout << "public class Main {\n";
       cout << "    static Scanner scanner = new Scanner(System.in);\n\n";

       generateFunctions(root, targetLang);

       cout << "    public static void main(String[] args) {\n";
       generateCode(root, targetLang);
       cout << "    }\n";
       cout << "}\n";
    }

    /* ================= PYTHON ================= */
    else if (targetLang == 4) {

       generateFunctions(root, targetLang);   // functions first

       cout << "\nif __name__ == '__main__':\n";
       generateCode(root, targetLang, 1);     // indent main
    }

    

    

    printPhase("Execution");

    printSymbolTable();

    cout << "\n=====================================\n";
    cout << "Compilation Successful\n";
    cout << "=====================================\n";

    return 0;
}