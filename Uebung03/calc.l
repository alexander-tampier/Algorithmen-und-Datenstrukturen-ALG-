%{
extern int yylval; 
extern int sym[];
#include "y.tab.h"
%}

%%

[a-z]   {
	   yylval = *yytext - 'a';
	   return VARIABLE;
        }

[0-9]+  {  
           yylval = atoi(yytext);
           return INTEGER;
        }

":="    return ASSIGN;
"+"     return PLUS;
"*"     return TIMES;
"-"		return MINUS;
"/" 	return DIVIDE;
"%"		return MODULO;
"("		return LB;
")"		return RB;
"++"	return UPLUS;
"--"	return UMINUS;
"+-"	return UMIX;
"-+"	return UMIX;

"\n"    return NEWLINE;

[ \t]   ;

.       yyerror("Invalid character");

%%

int yywrap() {
 return 1;
}
