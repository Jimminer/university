
%{

	#undef yywrap
	#define yywrap() 1
	#include <stdio.h>
	void display(int);
	int forCounter=0;

%}

%%

[0-9]+			{
					printf("Number %s\n", yytext);
				}

["+"\-"*""/"]?	{
					printf("Sign %s\n", yytext);
				}

[ \f\n\r\t]+	{
					printf("Formatting Character %s\n", yytext);
				}

"if"			{
					printf("If found\n");
				}


"while"			{
					printf("While found\n");
				}


"for"			{
					printf("For found\n");
					forCounter++;
				}

"exit"			{
					return;
				}

.				{
					printf("Nothing %s\n", yytext);
				}

%%

main()
{
	printf("Type 'exit' to stop the program\n");
	yylex();
	printf("For counter is at: %i\n", forCounter);
}
