%{
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
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
"story"         { addToken(T_KEYWORD, "KEYWORD: story"); }
"begins"        { addToken(T_KEYWORD, "KEYWORD: begins"); }
"end story"     { addToken(T_KEYWORD, "KEYWORD: end story"); }

"character"     { addToken(T_KEYWORD, "KEYWORD: character"); }
"holds"         { addToken(T_KEYWORD, "KEYWORD: holds"); }

"when"          { addToken(T_KEYWORD, "KEYWORD: when"); }
"otherwise"     { addToken(T_KEYWORD, "KEYWORD: otherwise"); }
"end choice"    { addToken(T_KEYWORD, "KEYWORD: end choice"); }

"during"        { addToken(T_KEYWORD, "KEYWORD: during"); }
"journey"       { addToken(T_KEYWORD, "KEYWORD: journey"); }
"end cycle"     { addToken(T_KEYWORD, "KEYWORD: end cycle"); }

"chapter"       { addToken(T_KEYWORD, "KEYWORD: chapter"); }
"return"        { addToken(T_KEYWORD, "KEYWORD: return"); }

"narrate"       { addToken(T_KEYWORD, "KEYWORD: narrate"); }
"listen"        { addToken(T_KEYWORD, "KEYWORD: listen"); }

"and"           { addToken(T_OPERATOR, "LOGICAL OPERATOR: and"); }
"or"            { addToken(T_OPERATOR, "LOGICAL OPERATOR: or"); }
"not"           { addToken(T_OPERATOR, "LOGICAL OPERATOR: not"); }

"=="            { addToken(T_OPERATOR, "OPERATOR: =="); }
"!="            { addToken(T_OPERATOR, "OPERATOR: !="); }
">="            { addToken(T_OPERATOR, "OPERATOR: >="); }
"<="            { addToken(T_OPERATOR, "OPERATOR: <="); }
">"             { addToken(T_OPERATOR, "OPERATOR: >"); }
"<"             { addToken(T_OPERATOR, "OPERATOR: <"); }
"="             { addToken(T_OPERATOR, "OPERATOR: ="); }

"+"             { addToken(T_OPERATOR, "OPERATOR: +"); }
"-"             { addToken(T_OPERATOR, "OPERATOR: -"); }
"*"             { addToken(T_OPERATOR, "OPERATOR: *"); }
"/"             { addToken(T_OPERATOR, "OPERATOR: /"); }
"%"             { addToken(T_OPERATOR, "OPERATOR: %"); }


"{"             { addToken(T_SYMBOL, "SYMBOL: {"); }
"}"             { addToken(T_SYMBOL, "SYMBOL: }"); }
"("             { addToken(T_SYMBOL, "SYMBOL: ("); }
")"             { addToken(T_SYMBOL, "SYMBOL: )"); }
";"             { addToken(T_SYMBOL, "SYMBOL: ;"); }

{NUMBER}        { addToken(T_NUMBER, string("NUMBER: ") + yytext); }
{ID}            { addToken(T_IDENTIFIER, string("IDENTIFIER: ") + yytext); }

[ \t\n]+        ;

.               { addToken(T_INVALID, string("INVALID TOKEN: ") + yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    cout << "=== Story Script Lexical Analyzer (C++) ===\n";

    yyin = fopen("input.story", "r");
    if (!yyin) {
        cerr << "Error: cannot open input.story file\n";
        return 1;
    }

    yylex();
    fclose(yyin);



    return 0;
}
