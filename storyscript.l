%option yylineno

%{
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include "storyscript.tab.h"

using namespace std;

extern FILE *yyin;
extern int yylineno;
extern YYLTYPE yylloc;

enum TokenType {
    T_KEYWORD,
    T_IDENTIFIER,
    T_NUMBER,
    T_OPERATOR,
    T_SYMBOL,
    T_INVALID
};

struct Token {
    TokenType type;
    string lexeme;
};

vector<Token> tokenTable;

void addToken(TokenType t, const string& lex) {
    tokenTable.push_back({t, lex});
    cout << lex << endl;
}
%}

DIGIT   [0-9]
LETTER  [a-zA-Z_]
ID      {LETTER}({LETTER}|{DIGIT})*
NUMBER  {DIGIT}+

%%

"story" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: story");
    return STORY;
}

"begins" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: begins");
    return BEGINS;
}

"end story" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: end story");
    return ENDSTORY;
}

"character" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: character");
    return CHARACTER;
}

"holds" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: holds");
    return HOLDS;
}

"when" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: when");
    return WHEN;
}

"otherwise" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: otherwise");
    return OTHERWISE;
}

"end choice" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: end choice");
    return ENDCHOICE;
}

"during" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: during");
    return DURING;
}

"journey" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: journey");
    return JOURNEY;
}

"end cycle" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: end cycle");
    return ENDCYCLE;
}

"chapter" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: chapter");
    return CHAPTER;
}

"takes" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: takes");
    return TAKES;
}

"return" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: return");
    return RETURN;
}

"end chapter" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: end chapter");
    return ENDCHAPTER;
}

"narrate" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: narrate");
    return NARRATE;
}

"listen" {
    yylloc.first_line = yylineno;
    addToken(T_KEYWORD,"KEYWORD: listen");
    return LISTEN;
}

"and" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"LOGICAL OPERATOR: and");
    return AND;
}

"or" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"LOGICAL OPERATOR: or");
    return OR;
}

"not" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"LOGICAL OPERATOR: not");
    return NOT;
}

"==" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: ==");
    return EQ;
}

"!=" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: !=");
    return NE;
}

">=" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: >=");
    return GE;
}

"<=" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: <=");
    return LE;
}

">" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: >");
    return GT;
}

"<" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: <");
    return LT;
}

"=" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: =");
    return ASSIGN;
}

"+" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: +");
    return PLUS;
}

"-" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: -");
    return MINUS;
}

"*" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: *");
    return MUL;
}

"/" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: /");
    return DIV;
}

"%" {
    yylloc.first_line = yylineno;
    addToken(T_OPERATOR,"OPERATOR: %");
    return MOD;
}

"{" {
    yylloc.first_line = yylineno;
    addToken(T_SYMBOL,"SYMBOL: {");
    return LBRACE;
}

"}" {
    yylloc.first_line = yylineno;
    addToken(T_SYMBOL,"SYMBOL: }");
    return RBRACE;
}

"(" {
    yylloc.first_line = yylineno;
    addToken(T_SYMBOL,"SYMBOL: (");
    return LPAREN;
}

")" {
    yylloc.first_line = yylineno;
    addToken(T_SYMBOL,"SYMBOL: )");
    return RPAREN;
}

";" {
    yylloc.first_line = yylineno;
    addToken(T_SYMBOL,"SYMBOL: ;");
    return SEMICOLON;
}

"," {
    yylloc.first_line = yylineno; 
    addToken(T_SYMBOL,"SYMBOL: ,");
    return COMMA; 
}

{NUMBER} {
    yylloc.first_line = yylineno;
    addToken(T_NUMBER,string("NUMBER: ") + yytext);
    yylval.num = atoi(yytext);
    return NUMBER;
}

{ID} {
    yylloc.first_line = yylineno;
    addToken(T_IDENTIFIER,string("IDENTIFIER: ") + yytext);
    yylval.id = strdup(yytext);
    return IDENTIFIER;
}

[ \t]+     ;
\n         ;

. {
    yylloc.first_line = yylineno;
    addToken(T_INVALID,string("INVALID TOKEN: ") + yytext);
}

%%
int yywrap() {
    return 1;
}