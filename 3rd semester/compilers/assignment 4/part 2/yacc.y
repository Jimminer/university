%{
    // Ergasia 4 Askisi 2
    // Gkoumas Dimitrios (4502)
	// Kintzios Spiridon (4557)

    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    int yyerror(const char *s); 
    int yylex(void);

    void updateSymbol(char *name, double value);
    int findSymbol(char *name);
    double getSymbol(char *name);

    typedef struct symbol{
        char name[256];
        double value;
        bool valid;
    } symbol;

    symbol symbolTable[8192];

    int valid = 1;
%}

%union{
    double value;
    char *id;
}

%token <value> NUMBER
%token <id> ID
%token PLUS MINUS MULTIPLY DIVIDE POWER
%token LPAR RPAR
%token LINE_END
%token EQUALS

%left PLUS MINUS
%left MULTIPLY DIVIDE
%right POWER
%right EQUALS

%start Input

%type <value> Expression

%%

Input: 
	        | Input Line
;

Line:         LINE_END
	        | Expression LINE_END { if (valid) printf("Result: %lf\n\n", $1); valid = 1; }
            | ID EQUALS Expression LINE_END { printf("\n"); updateSymbol($1, $3); }
;

Expression:   NUMBER { $$=$1; }
            | ID{
                    if (!findSymbol($1)){
                        printf("%s is undefined!\n", $1);
                        $$ = 0;
                    }
                    else
                        $$ = getSymbol($1);
                }
			| Expression PLUS Expression { $$=$1+$3; }
			| Expression MINUS Expression { $$=$1-$3; }
			| Expression MULTIPLY Expression { $$=$1*$3; }
			| Expression DIVIDE Expression { $$=$1/$3; }
			| Expression POWER Expression { $$=pow($1,$3); }
			| LPAR Expression RPAR { $$=$2; }
;

%%

int main(){
    printf("Compilers - Ergasia 4 Askisi 2\n\nGkoumas Dimitrios (4502)\nKintzios Spyridon (4557)\n\n");

	yyparse();

    free(yylval.id);
}

void updateSymbol(char *name, double value){
    int i=0;
    while(symbolTable[i].valid){
        /* printf("checking %s = %s\n", symbolTable[i].name, name); */
        if (strcmp(symbolTable[i].name, name) == 0)
            break;
        i++;
    }

    strcpy(symbolTable[i].name, name);
    symbolTable[i].value = value;
    symbolTable[i].valid = 1;
}

int findSymbol(char *name){
    int i=0;
    while(symbolTable[i].valid){
        if (strcmp(symbolTable[i].name, name) == 0)
            break;
        i++;
    }
    if (symbolTable[i].valid && strcmp(symbolTable[i].name, name) == 0)
        return 1;
    return 0;
}

double getSymbol(char *name){
    int i=0;
    while(symbolTable[i].valid){
        if (strcmp(symbolTable[i].name, name) == 0)
            break;
        i++;
    }
    return symbolTable[i].value;
}

int yyerror(const char *s){
	printf("%s\n", s);
}