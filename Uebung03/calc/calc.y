%{
#include <stdio.h>
int sym[26];
%}

%token VARIABLE ASSIGN INTEGER NEWLINE
%left MIN MAX
%left COMMA
%left QUESTION COLON
%left LESS LT EQ NOTEQ GT GREATER
%left PLUS MINUS
%left TIMES DIVIDE MODULO
%left LB RB UPLUS UMINUS UMIX

%%

program: program statement
       | 
       ;

statement: expr NEWLINE 
       { printf("%d\n", $1); }
         | VARIABLE ASSIGN expr NEWLINE
             { sym[$1] = $3; }
         ;

minlist: expr
  | minlist COMMA expr { $$ = $1 <= $3 ? $1 : $3; };

maxlist: expr
  | maxlist COMMA expr { $$ = $1 >= $3 ? $1 : $3; };

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

      | expr LESS expr   { $$ = $1<$3 ? 1 : 0; }
      | expr LT expr   { $$ = $1<=$3 ? 1 : 0; }

      | expr GREATER expr   { $$ = $1>$3 ? 1 : 0; }
      | expr GT expr   { $$ = $1>=$3 ? 1 : 0; }

      | expr EQ expr   { $$ = $1==$3 ? 1 : 0; }
      | expr NOTEQ expr   { $$ = $1!=$3 ? 1 : 0; }

      | MIN LB minlist RB { $$ = $3; } 
      | MAX LB maxlist RB { $$ = $3; }

      | expr QUESTION expr COLON expr { $$ = $1 ? $3 : $5; }
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
