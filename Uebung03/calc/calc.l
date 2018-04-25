%{
extern int yylval; 
extern int sym[];
#include "y.tab.h"
int hex();
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

0x[0-9a-fA-F]+ {  
	yylval = hex(yytext);
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

"+"		return UPLUS;
"-"		return UMIX;

"++"	return UPLUS;
"--"	return UMINUS;
"+-"	return UMIX;
"-+"	return UMIX;

"<"		return LESS;
"<="	return LT;
"=="	return EQ;
"!="	return NOTEQ;
">="	return GT;
">"		return GREATER;

","	return COMMA;

"max"	return MAX;
"min"	return MIN;

"?" return QUESTION;
":" return COLON;

"\n"    return NEWLINE;

[ \t]   ;

.       yyerror("Invalid character");

%%
int hex(char *str)
{
	int num;

	sscanf(str+2, "%x", &num);
	return num;
}

int yywrap() {
 return 1;
}
