#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack *stackCreate(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    stack->size = 0;
    stack->start = NULL;
    stack->top = NULL;

    return stack;
}

void stackDelete(Stack *stack){
    if (stack->start != NULL){
        StackItem *temp1, *temp2;
        temp1 = stack->start;

        while(temp1 != NULL){
            temp2 = temp1;
            temp1 = temp1->nextItem;
            free(temp2);
        }
    }

    free(stack);
}

ItemData stackTop(Stack *stack){
    if (stack->top == NULL)
        return (ItemData){-1, -1};

    return stack->top->data;
}

ItemData stackPop(Stack *stack){
    if (stack->top == NULL)
        return (ItemData){-1, -1};

    StackItem *temp = stack->top;
    ItemData data = temp->data;

    if (temp->prevItem != NULL){
        temp->prevItem->nextItem = NULL;
        stack->top = temp->prevItem;
    }
    else{
        stack->start = NULL;
        stack->top = NULL;
    }

    free(temp);

    stack->size--;

    return data;

    // while(temp->nextItem != NULL){
    //     if (temp->nextItem->nextItem == NULL) break;

    //     temp = temp->nextItem;
    // }

    // temp
}

void stackPush(Stack *stack, ItemData data){
    StackItem *item = (StackItem*)malloc(sizeof(StackItem));

    item->nextItem = NULL;
    item->prevItem = NULL;
    item->data = data;

    if (stack->top == NULL){
        stack->top = item;
        stack->start = item;
    }
    else{
        item->prevItem = stack->top;
        stack->top->nextItem = item;
        stack->top = item;
    }

    stack->size++;
}

int stackSize(Stack *stack){
    return stack->size;
}