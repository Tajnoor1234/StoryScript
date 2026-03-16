%{
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include "storyscript.tab.h"

using namespace std;

extern FILE *yyin;

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

"story"         { addToken(T_KEYWORD,"KEYWORD: story"); return STORY; }
"begins"        { addToken(T_KEYWORD,"KEYWORD: begins"); return BEGINS; }
"end story"     { addToken(T_KEYWORD,"KEYWORD: end story"); return ENDSTORY; }

"character"     { addToken(T_KEYWORD,"KEYWORD: character"); return CHARACTER; }
"holds"         { addToken(T_KEYWORD,"KEYWORD: holds"); return HOLDS; }

"when"          { addToken(T_KEYWORD,"KEYWORD: when"); return WHEN; }
"otherwise"     { addToken(T_KEYWORD,"KEYWORD: otherwise"); return OTHERWISE; }
"end choice"    { addToken(T_KEYWORD,"KEYWORD: end choice"); return ENDCHOICE; }

"during"        { addToken(T_KEYWORD,"KEYWORD: during"); return DURING; }
"journey"       { addToken(T_KEYWORD,"KEYWORD: journey"); return JOURNEY; }
"end cycle"     { addToken(T_KEYWORD,"KEYWORD: end cycle"); return ENDCYCLE; }

"chapter"       { addToken(T_KEYWORD,"KEYWORD: chapter"); return CHAPTER; }
"takes"         { addToken(T_KEYWORD,"KEYWORD: takes"); return TAKES; }
"return"        { addToken(T_KEYWORD,"KEYWORD: return"); return RETURN; }
"end chapter"   { addToken(T_KEYWORD,"KEYWORD: end chapter"); return ENDCHAPTER; }

"narrate"       { addToken(T_KEYWORD,"KEYWORD: narrate"); return NARRATE; }
"listen"        { addToken(T_KEYWORD,"KEYWORD: listen"); return LISTEN; }

"and"           { addToken(T_OPERATOR,"LOGICAL OPERATOR: and"); return AND; }
"or"            { addToken(T_OPERATOR,"LOGICAL OPERATOR: or"); return OR; }
"not"           { addToken(T_OPERATOR,"LOGICAL OPERATOR: not"); return NOT; }

"=="            { addToken(T_OPERATOR,"OPERATOR: =="); return EQ; }
"!="            { addToken(T_OPERATOR,"OPERATOR: !="); return NE; }
">="            { addToken(T_OPERATOR,"OPERATOR: >="); return GE; }
"<="            { addToken(T_OPERATOR,"OPERATOR: <="); return LE; }
">"             { addToken(T_OPERATOR,"OPERATOR: >"); return GT; }
"<"             { addToken(T_OPERATOR,"OPERATOR: <"); return LT; }

"="             { addToken(T_OPERATOR,"OPERATOR: ="); return ASSIGN; }

"+"             { addToken(T_OPERATOR,"OPERATOR: +"); return PLUS; }
"-"             { addToken(T_OPERATOR,"OPERATOR: -"); return MINUS; }
"*"             { addToken(T_OPERATOR,"OPERATOR: *"); return MUL; }
"/"             { addToken(T_OPERATOR,"OPERATOR: /"); return DIV; }
"%"             { addToken(T_OPERATOR,"OPERATOR: %"); return MOD; }

"{"             { addToken(T_SYMBOL,"SYMBOL: {"); return LBRACE; }
"}"             { addToken(T_SYMBOL,"SYMBOL: }"); return RBRACE; }
"("             { addToken(T_SYMBOL,"SYMBOL: ("); return LPAREN; }
")"             { addToken(T_SYMBOL,"SYMBOL: )"); return RPAREN; }
";"             { addToken(T_SYMBOL,"SYMBOL: ;"); return SEMICOLON; }

{NUMBER} {
    addToken(T_NUMBER,string("NUMBER: ") + yytext);
    yylval.num = atoi(yytext);
    return NUMBER;
}

{ID} {
    addToken(T_IDENTIFIER,string("IDENTIFIER: ") + yytext);
    yylval.id = strdup(yytext);
    return IDENTIFIER;
}

[ \t\n]+        ;

.               { addToken(T_INVALID,string("INVALID TOKEN: ") + yytext); }

%%

int yywrap() {
    return 1;
}