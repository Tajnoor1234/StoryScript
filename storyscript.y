%{
#include <iostream>
#include <string>
using namespace std;

extern int yylex();
void yyerror(const char *s);
%}

/* Keywords */
%token STORY BEGINS ENDSTORY
%token CHARACTER HOLDS
%token WHEN OTHERWISE ENDCHOICE
%token DURING JOURNEY ENDCYCLE
%token CHAPTER TAKES RETURN ENDCHAPTER
%token NARRATE LISTEN

/* Identifiers and numbers */
%token IDENTIFIER NUMBER

/* Operators */
%token PLUS MINUS MUL DIV MOD
%token GT LT GE LE EQ NE
%token AND OR NOT
%token ASSIGN

/* Symbols */
%token LBRACE RBRACE
%token LPAREN RPAREN
%token SEMICOLON COMMA

%left PLUS MINUS
%left MUL DIV MOD

%%

program
    : STORY IDENTIFIER BEGINS statement_list ENDSTORY
      {
        cout << "Program parsed successfully\n";
      }
    ;

statement_list
    : statement statement_list
    |
    ;

statement
    : declaration
    | assignment
    | conditional
    | loop
    | function
    | input
    | output
    ;

declaration
    : CHARACTER IDENTIFIER HOLDS expression SEMICOLON
      {
        cout << "Declaration statement\n";
      }
    ;

assignment
    : IDENTIFIER HOLDS expression SEMICOLON
      {
        cout << "Assignment statement\n";
      }
    ;

conditional
    : WHEN condition statement_list OTHERWISE statement_list ENDCHOICE
      {
        cout << "Conditional statement\n";
      }
    ;

loop
    : DURING condition statement_list ENDCYCLE
      {
        cout << "Loop statement\n";
      }
    ;

function
    : CHAPTER IDENTIFIER TAKES parameter_list statement_list RETURN expression ENDCHAPTER
      {
        cout << "Function definition\n";
      }
    ;

parameter_list
    : IDENTIFIER
    | IDENTIFIER COMMA parameter_list
    |
    ;

input
    : LISTEN IDENTIFIER SEMICOLON
      {
        cout << "Input statement\n";
      }
    ;

output
    : NARRATE expression SEMICOLON
      {
        cout << "Output statement\n";
      }
    ;

condition
    : expression GT expression
    | expression LT expression
    | expression GE expression
    | expression LE expression
    | expression EQ expression
    | expression NE expression
    ;

expression
    : expression PLUS expression
    | expression MINUS expression
    | expression MUL expression
    | expression DIV expression
    | expression MOD expression
    | IDENTIFIER
    | NUMBER
    ;

%%

void yyerror(const char *s)
{
    cout << "Syntax Error: " << s << endl;
}

int main()
{
    cout << "Parsing StoryScript Program...\n";
    yyparse();
    return 0;
}