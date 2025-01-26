#ifndef _STACK_H
#define _STACK_H

typedef struct Stack Stack;
typedef struct StackItem StackItem;
typedef struct ItemData ItemData;

struct ItemData{
    double value;
    int operator;
};

struct StackItem{
    StackItem *prevItem;
    StackItem *nextItem;
    ItemData data;
};

struct Stack{
    int size;
    StackItem *start;
    StackItem *top;
};

Stack *stackCreate();
void stackDelete(Stack *stack);
ItemData stackTop(Stack *stack);
ItemData stackPop(Stack *stack);
void stackPush(Stack *stack, ItemData data);
int stackSize(Stack *stack);

#endif