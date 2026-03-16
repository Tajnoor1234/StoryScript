%{
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unistd.h>

using namespace std;

extern int yylex();
extern FILE *yyin;
void yyerror(const char *s);

map<string,int> symbolTable;

/* AST Node definition */
struct Node{
    string type;
    string id;
    int value;

    Node *left;
    Node *right;

    vector<Node*> children;

    Node(string t){
        type=t;
        value=0;
        left=right=nullptr;
    }
};

Node* root=nullptr;

int eval(Node* n);
void exec(Node* n);
%}

/* This part goes into storyscript.tab.h */
%code requires {
    struct Node;
}

/* union */
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
%token GT LT GE LE EQ NE
%token AND OR NOT
%token ASSIGN

%token LBRACE RBRACE
%token LPAREN RPAREN
%token SEMICOLON COMMA

%type <node> program statement_list statement
%type <node> declaration assignment conditional loop output input
%type <node> expression condition

%%

program
: STORY IDENTIFIER BEGINS statement_list ENDSTORY
{
    root=$4;
}
;

statement_list
: statement statement_list
{
    Node* n=new Node("block");
    n->children.push_back($1);
    if($2) n->children.push_back($2);
    $$=n;
}
|
{
    $$=nullptr;
}
;

statement
: declaration
| assignment
| conditional
| loop
| output
| input
;

declaration
: CHARACTER IDENTIFIER HOLDS expression SEMICOLON
{
    Node* n=new Node("declare");
    n->id=$2;
    n->left=$4;
    $$=n;
}
;

assignment
: IDENTIFIER HOLDS expression SEMICOLON
{
    Node* n=new Node("assign");
    n->id=$1;
    n->left=$3;
    $$=n;
}
;

output
: NARRATE expression SEMICOLON
{
    Node* n=new Node("print");
    n->left=$2;
    $$=n;
}
;

input
: LISTEN IDENTIFIER SEMICOLON
{
    Node* n=new Node("input");
    n->id=$2;
    $$=n;
}
;

conditional
: WHEN condition statement_list OTHERWISE statement_list ENDCHOICE
{
    Node* n=new Node("if");
    n->left=$2;
    n->children.push_back($3);
    n->children.push_back($5);
    $$=n;
}
;

loop
: DURING condition statement_list ENDCYCLE
{
    Node* n=new Node("loop");
    n->left=$2;
    n->children.push_back($3);
    $$=n;
}
;

condition
: expression GT expression
{
    Node* n=new Node("gt");
    n->left=$1;
    n->right=$3;
    $$=n;
}
| expression LT expression
{
    Node* n=new Node("lt");
    n->left=$1;
    n->right=$3;
    $$=n;
}
| condition AND condition
{
    Node* n=new Node("and");
    n->left=$1;
    n->right=$3;
    $$=n;
}
| condition OR condition
{
    Node* n=new Node("or");
    n->left=$1;
    n->right=$3;
    $$=n;
}
| NOT condition
{
    Node* n=new Node("not");
    n->left=$2;
    $$=n;
}
| LPAREN condition RPAREN
{
    $$=$2;
}
;

expression
: expression PLUS expression
{
    Node* n=new Node("add");
    n->left=$1;
    n->right=$3;
    $$=n;
}
| expression MINUS expression
{
    Node* n=new Node("sub");
    n->left=$1;
    n->right=$3;
    $$=n;
}
| expression MUL expression
{
    Node* n=new Node("mul");
    n->left=$1;
    n->right=$3;
    $$=n;
}
| expression DIV expression
{
    Node* n=new Node("div");
    n->left=$1;
    n->right=$3;
    $$=n;
}
| NUMBER
{
    Node* n=new Node("num");
    n->value=$1;
    $$=n;
}
| IDENTIFIER
{
    Node* n=new Node("var");
    n->id=$1;
    $$=n;
}
;

%%

/* evaluate expressions */
int eval(Node* n)
{
    if(n->type=="num")
        return n->value;

    if(n->type=="var")
        return symbolTable[n->id];

    if(n->type=="add")
        return eval(n->left)+eval(n->right);

    if(n->type=="sub")
        return eval(n->left)-eval(n->right);

    if(n->type=="mul")
        return eval(n->left)*eval(n->right);

    if(n->type=="div")
        return eval(n->left)/eval(n->right);

    if(n->type=="gt")
        return eval(n->left)>eval(n->right);

    if(n->type=="lt")
        return eval(n->left)<eval(n->right);
    if(n->type=="and")
        return eval(n->left) && eval(n->right);

    if(n->type=="or")
        return eval(n->left) || eval(n->right);

    if(n->type=="not")
        return !eval(n->left);

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

    else if(n->type=="input"){
        int val = 0;   // initialize
        cout << "Enter value for " << n->id << ": ";
        if(!(cin >> val)) cin.clear();
        symbolTable[n->id] = val;
    }

    else if(n->type=="assign"){
        symbolTable[n->id]=eval(n->left);
        cout<<n->id<<" updated to "<<symbolTable[n->id]<<endl;
    }

    else if(n->type=="print"){
        cout<<eval(n->left)<<endl;
    }

    else if(n->type=="if"){
        if(eval(n->left))
            exec(n->children[0]);
        else
            exec(n->children[1]);
    }

    else if(n->type=="loop"){
        while(eval(n->left)){
            exec(n->children[0]);
        }
    }
}

void yyerror(const char *s)
{
    cout<<"Syntax Error"<<endl;
}

int main()
{
    cout<<"Parsing StoryScript Program...\n";

    /* if no input redirection, open input.story */
    if(isatty(fileno(stdin))){
        FILE *fp = fopen("input.story","r");
        if(!fp){
            cout<<"Cannot open input.story\n";
            return 1;
        }
        yyin = fp;
    }

    yyparse();

    exec(root);

    return 0;
}