%{
    // Ergasia 4 Askisi 1
    // Gkoumas Dimitrios (4502)
	// Kintzios Spiridon (4557)

    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>

    int yyerror(const char *s); 
    int yylex(void);

    int valid = 1;
%}

%union{
	int value;
}

%token <value> NUMBER
%token LINE_END

%start Input

%type <value> Binary

%%

Input: 
	    | Input Line
;

Line:     LINE_END
        | Binary LINE_END { if (valid) printf("Result: %i\n\n", $1); valid = 1; }
;

Binary  : NUMBER { $$ = $1; }
        | Binary NUMBER { 
                            $$ *= 2;
                            if ($2 == 1)
                                $$ += 1;
                            else if ($2 != 0 && valid){
                                yyerror("Incorrect binary number provided!\n");
                                valid = 0;
                            }
                        }
;

%%

int yyerror(const char *s){
	printf("%s\n", s);
}

int main(){
    printf("Compilers - Ergasia 4 Askisi 1\n\nGkoumas Dimitrios (4502)\nKintzios Spyridon (4557)\n\n");

	yyparse();
}