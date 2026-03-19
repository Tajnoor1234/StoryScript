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

Node* root=nullptr;

int eval(Node* n);
void exec(Node* n);

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
%type <node> output input expression condition parameter_list

%%

program
: STORY IDENTIFIER BEGINS statement_list ENDSTORY
{
    root = $4;
}
;

statement_list
: statement statement_list
{
    Node* n = new Node("block");
    n->children.push_back($1);
    if($2) n->children.push_back($2);
    $$ = n;
}
|
{
    $$ = nullptr;
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

/* function rule EXACTLY matching grammar */
function
: CHAPTER IDENTIFIER TAKES parameter_list statement_list RETURN expression ENDCHAPTER
{
    Node* n = new Node("function");
    n->id = $2;
    n->children.push_back($4);  // parameters
    n->children.push_back($5);  // body
    n->left = $7;               // return expression
    $$ = n;
}
;

parameter_list
: IDENTIFIER
{
    Node* n = new Node("param");
    n->id = $1;
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

    return 0;
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
        cout<<"Function "<<n->id<<" parsed"<<endl;
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

    /* Execution (also does semantic checking) */
    cout << "\n[COMPILER] Executing Program...\n\n";

    exec(root);

    /* STOP if semantic error */
    if(hasSemanticError){
        cout << "\n[COMPILER] Semantic Analysis Failed\n";
        return 1;
    }

    printPhase("Execution");

    printSymbolTable();

    cout << "\n=====================================\n";
    cout << "Compilation Successful\n";
    cout << "=====================================\n";

    return 0;
}