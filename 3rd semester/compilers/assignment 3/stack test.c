#include <stdio.h>
#include "stack.h"

int main(){
    Stack *stack = stackCreate();
    ItemData data = {0, 0};

    data.value = 3.5;
    stackAdd(stack, data);

    data.value = 5;
    stackAdd(stack, data);

    data.value = 15.3;
    stackAdd(stack, data);

    data.value = 8.1;
    stackAdd(stack, data);
    data.value = 7.1;
    stackAdd(stack, data);
    stackDelete(stack);

    // printf("%f == 5.0\n", stackTop(stack));
    // printf("%i == 2\n", stackSize(stack));
    // printf("%f == 5.0\n", stackPop(stack));
    // printf("%i == 1\n", stackSize(stack));
    // data.value = 7.21;
    // stackAdd(stack, data);
    // printf("%f == 7.21\n", stackPop(stack));
    // printf("%i == 1\n", stackSize(stack));
    // printf("%f == 3.5\n", stackPop(stack));
    // printf("%i == 0\n", stackSize(stack));


    return 0;
}