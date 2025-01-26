%{
    // Ergasia 1
    // Gkoumas Dimitrios (4502)

	#include <stdio.h>
    #include <string.h>
    #include <signal.h>

    void signalHandler(int _);
    void after();

    int chars = 0;
    int words = 0;
    int lines = 0;
    int tabs = 0;
    int spaces = 0;
%}

%option noyywrap

%%

"exit"          {
                    signalHandler(0);
                }

[a-zA-Z]+       {
                    words++;
                    chars += strlen(yytext);
                }

" "             {
                    spaces++;
                    chars++;
                }

[\n]            {
                    lines++;
                    chars++;
                }

[\t]            {
                    tabs++;
                    chars++;
                }


.               {
                    chars++;
                }

<<EOF>>         {
                    // Run 'after' uppon the end of a file or when Ctrl-D is received
                    signalHandler(0);
                }

%%

void main(int argc, char **argv) {
    printf("Ergasia 1\nGkoumas Dimitrios (4502)\n\n");

    signal(SIGINT, signalHandler); // Capture SIGINT (Ctrl-C)

    ++argv, --argc; // Remove the program's name from the arguments

    // Check if a file was provided
    if ( argc > 0 ){
        printf("Starting flex on the file %s\n\n", argv[0]);
        yyin = fopen( argv[0], "r" );
    }else{
        printf("Type and press enter to validate\n'exit' or (Ctrl-C) to quit\n\n");
        yyin = stdin;
    }

    yylex();
}

void signalHandler(int _){
    after();
    exit(0);
}

void after(){
    printf("\n\nResults:\n");
    printf("%-3i Characters\n", chars);
    printf("%-3i Words\n", words);
    printf("%-3i Lines\n", lines);
    printf("%-3i Tabs\n", tabs);
    printf("%-3i Spaces\n", spaces);
}