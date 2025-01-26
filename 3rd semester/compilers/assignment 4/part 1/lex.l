%{
    // Ergasia 4 Askisi 1
    // Gkoumas Dimitrios (4502)
	// Kintzios Spiridon (4557)

	#include <stdio.h>
    #include "y.tab.h"
%}

%option noyywrap

NUMBER		[0-9]

%%

{NUMBER}?   {
                yylval.value = atoi(yytext);
                return NUMBER;
            }

[\n]        return LINE_END;

.           {}

%%
