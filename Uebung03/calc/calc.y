%{
#include <stdio.h>
int sym[26];
%}

%token VARIABLE ASSIGN INTEGER NEWLINE
%token LB RB
%left PLUS
%left MINUS
%left TIMES
%left DIVIDE
%left MODULO
%left UPLUS UMINUS UMIX


%%

program: program statement
       | 
       ;

statement: expr NEWLINE 
	     { printf("%d\n", $1); }
         | VARIABLE ASSIGN expr NEWLINE
             { sym[$1] = $3; }
         ;

expr: INTEGER            { $$ = $1; }
      | VARIABLE         { $$ = sym[$1]; }
      | expr PLUS expr   { $$ = $1 + $3; }
      | expr MINUS expr  { $$ = $1 - $3; }
      | expr TIMES expr  { $$ = $1 * $3; }
      | expr DIVIDE expr  { $$ = $1 / $3; }
      | expr MODULO expr  { $$ = $1 % $3; }
      | LB expr RB        { $$ = $2; } | expr LB expr RB   
      | UPLUS expr        { $$ = +$2; }
      | UMINUS expr        { $$ = +$2; }
      | expr UPLUS expr    { $$ = $1 + $3; }
      | expr UMINUS expr    { $$ = $1 + $3; }
      | UMIX expr           { $$ = -$2; }
      | expr UMIX expr    { $$ = $1 - $3; }
      ;

%%

int yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
  return 0;
}

int main() {
  yyparse();
  return 0;
}
