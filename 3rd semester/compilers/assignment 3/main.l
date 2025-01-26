%{
    // Ergasia 3
    // Gkoumas Dimitrios (4502)
	// Kintzios Spiridon (4557)

	#include <stdio.h>
	#include <stdbool.h>
	#include <math.h>

	#include "stack.h"

	#define OP_PLUS		0
	#define OP_MINUS	1
	#define OP_MULTIPLY	2
	#define OP_DIVIDE	3
	#define OP_MODULO	4
	#define OP_POWER	5
	#define LPAR		6
	#define RPAR		7

	#define LEFT_TO_RIGHT 1
	#define RIGHT_TO_LEFT 2

	double numStorage = 0;
	int opStorage = 0;
	
	int lPars = 0;
	int rPars = 0;

	// explanation for minusPars:
	//
	// if a minus is found and it is determined to be a sign (not an operator)
	// a parenthesis is created which contains the following numbers being
	// subtracted from zero
	//
	// e.g.
	// For input: 5 * -(2+3)
	// we parse it as 5 * (0-(2+3))
	int minusPars = 0;
	int unexpected = 0;

	bool handle = true;
	bool newBlock = true;
	bool foundNumber = false;
	bool foundMinus = false;

	Stack *outputStack;
	Stack *operatorStack;
	ItemData data;

	bool isValid();
	void handleOperator(Stack *outputStack, Stack *operatorStack, int operator);
%}

%option noyywrap

NUMBER		[0-9]
LETTER		[a-zA-Z]


%%

{NUMBER}+("."{NUMBER}*)?			{
										foundNumber = true;
										newBlock = false;
										numStorage = atof(yytext);

										data.value = numStorage;
										data.operator = false;

										stackPush(outputStack, data);

										// If next to a "minusPar" is a number, remove the minusPar
										//
										// e.g.
										// For input: 2 * -3:
										// 2 * (0 - 3) becomes 0 - 2 * 3
										if (foundMinus){
											stackPop(operatorStack);
											stackPop(operatorStack);

											data.value = OP_MINUS;
											data.operator = true;
											stackPush(outputStack, data);

											foundMinus = false;
										}
									}

"+"|"-"|"*"|"/"|"%"|"^"|"("|")" 	{
										handle = true;
										foundMinus = false;

										// Explanation for the below switch:
										//
										//
										// "newBlock" is true either at the start of an expression or at the start of an open parenthesis
										//
										// "foundNumber" is true if the previous input was a number
										//
										// "foundMinus" is true if a minus is found (as a sign and not as an operator)
										//
										// "handle" is wether to call handleOperator at the end of the switch
										//
										//
										// If an operator is found at a newBlock, it is unexpected (except for plus and minus)

										switch(yytext[0]){
											case '+':
												if (!newBlock)
													opStorage = OP_PLUS;
												else
													handle = false;

												foundNumber = false;

												break;
											
											case '-':
												if (!newBlock && foundNumber)
													opStorage = OP_MINUS;
												else if (newBlock || !foundNumber){
													minusPars++;
													foundMinus = true;

													data.value = 0;
													data.operator = false;
													stackPush(outputStack, data);

													data.value = LPAR;
													data.operator = true;
													stackPush(operatorStack, data);

													data.value = OP_MINUS;
													stackPush(operatorStack, data);

													handle = false;
												}
												else
													handle = false;

												foundNumber = false;

												break;
											
											case '*':
												if (!newBlock)
													opStorage = OP_MULTIPLY;
												else{
													unexpected++;
													handle = false;
												}
												foundNumber = false;

												break;
											
											case '/':
												if (!newBlock)
													opStorage = OP_DIVIDE;
												else{
													unexpected++;
													handle = false;
												}
												foundNumber = false;

												break;
											
											case '%':
												if (!newBlock)
													opStorage = OP_MODULO;
												else{
													unexpected++;
													handle = false;
												}
												foundNumber = false;

												break;
											
											case '^':
												if (!newBlock)
													opStorage = OP_POWER;
												else{
													unexpected++;
													handle = false;
												}
												foundNumber = false;

												break;
											
											case '(':
												opStorage = LPAR;
												newBlock = true;
												lPars++;
												foundNumber = false;
												
												break;
											
											case ')':
												opStorage = RPAR;
												rPars++;

												break;
										}

										if (handle)
											handleOperator(outputStack, operatorStack, opStorage);
									}

[\n]								{
										if (isValid()){

											// Pop what's left on the operator stack and push it to the output stack
											while(true){
												data = stackPop(operatorStack);

												// Ignore any remaining parentheses
												if (data.value == LPAR || data.value == RPAR) continue;
												
												// Stop once the stack is empty (the stack returns {value = -1, operator = -1} in case it is empty)
												if (data.value == -1 && data.operator == -1) break;

												stackPush(outputStack, data);
											}

											// Flip the output stack (since stack is LIFO)
											Stack *tempStack = stackCreate();
											while(true){
												data = stackPop(outputStack);

												// Stop once the stack is empty (the stack returns {value = -1, operator = -1} in case it is empty)
												if (data.value == -1 && data.operator == -1) break;

												stackPush(tempStack, data);
											}

											// Calculate
											ItemData lOperand, rOperand;
											while(true){
												data = stackPop(tempStack);

												// Stop once the stack is empty (the stack returns {value = -1, operator = -1} in case it is empty)
												if (data.value == -1 && data.operator == -1) break;

												// Found operator so pop the last two operands and do the calculation
												if (data.operator){
													rOperand = stackPop(outputStack);
													lOperand = stackPop(outputStack);
													
													switch((int)data.value){
														case OP_PLUS:
															data.value = lOperand.value + rOperand.value;
															break;
														
														case OP_MINUS:
															data.value = lOperand.value - rOperand.value;
															break;

														case OP_MULTIPLY:
															data.value = lOperand.value * rOperand.value;
															break;

														case OP_DIVIDE:
															data.value = lOperand.value / rOperand.value;
															break;

														case OP_MODULO:
															data.value = fmod(lOperand.value, rOperand.value);
															break;

														case OP_POWER:
															data.value = pow(lOperand.value, rOperand.value);
															break;
													}

													data.operator = false;
												}

												stackPush(outputStack, data);
											}

											data = stackPop(outputStack);
											printf("Output: %f\n", data.value);

											stackDelete(tempStack);
										}
										
										lPars = 0;
										rPars = 0;
										minusPars = 0;
										unexpected = 0;

										newBlock = true;
										foundNumber = false;
										foundMinus = false;

										printf("\n");
									}

[ \t]								{
										// Ignore whitespace
									}

"exit"								{
										return 0;
									}

{LETTER}							{
										// Letters are unexpected
										unexpected++;
									}

.									{
										// Anything not found in the above expressions is unexpected
										unexpected++;
									}

%%

void main(int argc, char **argv) {
    printf("Compilers - Ergasia 3\n\nGkoumas Dimitrios (4502)\nKintzios Spyridon (4557)\n\n");

	outputStack = stackCreate();
	operatorStack = stackCreate();

    ++argv, --argc; // Remove the program's name from the arguments

    // Check if a file was provided
    if ( argc > 0 ){
        printf("Starting flex on the file %s\n\n", argv[0]);
        yyin = fopen( argv[0], "r" );
    }else{
        printf("Type an expression and press enter to calculate\n'exit' or (Ctrl-C) to quit\n\n");
        yyin = stdin;
    }

    yylex();

	stackDelete(outputStack);
	stackDelete(operatorStack);
}

bool isValid(){
	bool valid = true;

	if (unexpected){
		printf("Error! %i unexpected characters!\n", unexpected);
		valid = false;
	}
	if (lPars > rPars){
		printf("Error! %i unmatched left parentheses!\n", lPars - rPars);
		valid = false;
	}
	if (rPars > lPars){
		printf("Error! %i unmatched right parentheses!\n", rPars - lPars);
		valid = false;
	}
	
	return valid;
}

int getPriority(int operator){
	switch(operator){
		case OP_PLUS:
		case OP_MINUS:
			return 2;

		case OP_MULTIPLY:
		case OP_DIVIDE:
		case OP_MODULO:
			return 3;
		
		case OP_POWER:
			return 4;

		default:
			return 1;
	}
}

int getAssociativity(int operator){
	switch(operator){
		case OP_PLUS:
		case OP_MINUS:
		case OP_MULTIPLY:
		case OP_DIVIDE:
		case OP_MODULO:
			return LEFT_TO_RIGHT;

		case OP_POWER:
			return RIGHT_TO_LEFT;

		default:
			return 0;
	}
}

void handleOperator(Stack *outputStack, Stack *operatorStack, int operator){
	ItemData data;

	while(true){
		data = stackTop(operatorStack);

		// In case of a left parenthesis we do not need to check the operator stack so just break
		if (operator == LPAR) break;

		// In case of a right parenthesis we pop everything until a left parenthesis is found and push it to the output stack
		if (operator == RPAR){
			while(true){
				data = stackPop(operatorStack);

				if (data.value == LPAR){

					// If there is an open "minusPar" and all normal parentheses are closed, repeat the popping process
					if (minusPars != 0 && (lPars == rPars)){
						minusPars--;
						continue;
					}
					
					else break;
				}

				if (data.value == -1) break;

				stackPush(outputStack, data);
			}
			break;
		}

		// If stack is empty, break
		if (data.operator == -1) break;

		// If the top of the stack has lower priority than the operator we are trying to push, break
		if (getPriority(data.value) < getPriority(operator)) break;
		
		// If the top of the stack has higher priority than the operator we are trying to push, pop it and push it to the output stack
		if (getPriority(data.value) > getPriority(operator)){
			stackPop(operatorStack);
			stackPush(outputStack, data);
		}
		// If the top of the stack has equal priority with the operator we are trying to push, check it's associativity
		else if (getPriority(data.value) == getPriority(operator)){
			// If the top of the stack has right to left associativity break
			if (getAssociativity(data.value) == RIGHT_TO_LEFT) break;

			// Else, pop it and push it to the output stack
			stackPop(operatorStack);
			stackPush(outputStack, data);
		}
	}

	// Finally, push the operator to the operator stack
	data.value = (double)operator;
	data.operator = true;
	if (operator != RPAR)
		stackPush(operatorStack, data);
}