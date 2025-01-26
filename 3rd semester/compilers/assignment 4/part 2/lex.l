%{
    // Ergasia 4 Askisi 2
    // Gkoumas Dimitrios (4502)
	// Kintzios Spiridon (4557)
    
    #include <stdlib.h>
    #include "y.tab.h"
%}

%option noyywrap

CHARACTER   [a-zA-Z]
STRING      {CHARACTER}+
NUMBER 	    [0-9]
FLOAT       {NUMBER}+("."{NUMBER}*)?
WHITESPACE 	[ \t]

%%

{FLOAT}	        {
                    yylval.value = atof(yytext); 
                    return NUMBER;
                }

{STRING}        {
                    yylval.id = strdup(yytext);
                    return ID;
                }

{WHITESPACE}	{ }

"+" 	        return PLUS;
"-" 	        return MINUS;
"*" 	        return MULTIPLY;
"/" 	        return DIVIDE;
"^" 	        return POWER;
"(" 	        return LPAR;
")" 	        return RPAR;
"="             return EQUALS;
"\n" 	        return LINE_END;

%%