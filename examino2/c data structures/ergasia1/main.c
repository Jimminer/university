#include <stdio.h>
#include "dataStructures.h"
#include "dataStructuresVars.h"

int main(){
    Stack *stack = createStack(10);
    StackData data;
    data.number = 10;
    addStack(stack, data);
    data.number = 35;
    addStack(stack, data);
    data.number = 4;
    addStack(stack, data);
    data.number = 31;
    addStack(stack, data);
    data = removeStack(stack);
    printf("\nREMOVED: %i", data.number);
    data = removeStack(stack);
    printf("\nREMOVED: %i", data.number);
    data = removeStack(stack);
    printf("\nREMOVED: %i", data.number);
    data = removeStack(stack);
    printf("\nREMOVED: %i", data.number);
    return 0;
}