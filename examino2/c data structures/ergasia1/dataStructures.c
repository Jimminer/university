/*
LIBRARY MADE BY DIMITRIOS GKOUMAS (cs04502)
*/

#include <stdlib.h>
#include <stdio.h>
#include "dataStructuresVars.h"


/* STACK (STIVA) */


struct Stack{
    int current;
    int size;
    int *items;
};

typedef struct Stack Stack;

Stack *createStack(int size){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->current = -1;
    stack->size = size;
    stack->items = (int*)malloc(sizeof(int) * size);
    return stack;
}

int getSizeStack(Stack *stack){
    return stack->current + 1;
}

int isEmptyStack(Stack *stack){
    if (stack->current == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFullStack(Stack *stack){
    if (stack->current + 1 == stack->size){
        return 1;
    }
    else{
        return 0;
    }
}

void emptyStack(Stack *stack){
    stack->current = -1;
}

void deleteStack(Stack *stack){
    free(stack);
}

void addStack(Stack *stack, int item){
    if (!isFullStack(stack)){
        stack->items[++stack->current] = item;
    }
}

int removeStack(Stack *stack){
    if (!isEmptyStack(stack)){
        int item = stack->items[stack->current];
        stack->current--;
        return item;
    }
    return 0;
}

int peekStack(Stack *stack){
    if (!isEmptyStack(stack)){
        return stack->items[stack->current];
    }
    return 0;
}


/* QUEUE (OURA) */


struct Queue{
    int front;
    int back;
    int size;
    int entries;
    int *items;
};

typedef struct Queue Queue;

Queue *createQueue(int size){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->back = -1;
    queue->size = size;
    queue->entries = 0;
    queue->items = (int*)malloc(sizeof(int) * size);
    return queue;
}

int getSizeQueue(Queue *queue){
    return queue->entries;
}

int isEmptyQueue(Queue *queue){
    if (queue->entries == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int isFullQueue(Queue *queue){
    if (queue->entries == queue->size){
        return 1;
    }
    else{
        return 0;
    }
}

void emptyQueue(Queue *queue){
    queue->front = -1;
    queue->back = -1;
    queue->entries = 0;
}

void deleteQueue(Queue *queue){
    free(queue);
}

void addQueue(Queue *queue, int item){
    if (!isFullQueue(queue)){
        queue->back++;
        queue->items[queue->back % queue->size] = item;
        queue->entries++;
    }
}

int removeQueue(Queue *queue){
    if (!isEmptyQueue(queue)){
        queue->front = (queue->front + 1) % queue->size;
        queue->entries--;
        return queue->items[queue->front];
    }
    return 0;
}

int peekQueue(Queue *queue){
    if (!isEmptyQueue(queue)){
        return queue->items[(queue->front + 1) % queue-> size];
    }
    return 0;
}


/* PRIORITY QUEUE (OURA PROTERAIOTITAS) */


typedef struct PQItem PQItem;

struct PQItem{
    int key;
    PQData data;
    PQItem *nextItem;
};

struct PQueue{
    int type;
    int entries;
    PQItem *front;
};

typedef struct PQueue PQueue;

PQueue *createPQueue(int type){
    PQueue *pqueue = (PQueue*)malloc(sizeof(PQueue));
    pqueue->type = type;
    pqueue->front = NULL;
    pqueue->entries = 0;
    return pqueue;
}

int getSizePQueue(PQueue *pqueue){
    return pqueue->entries;
}

int isEmptyPQueue(PQueue *pqueue){
    if (pqueue->entries == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void emptyPQueue(PQueue *pqueue){
    if (!isEmptyPQueue(pqueue)){
        int i;
        PQItem *pqitem, *temp;
        pqitem = pqueue->front;
        for(i=0;i<pqueue->entries;i++){
            temp = pqitem;
            free(pqitem);
            pqitem = temp->nextItem;
        }
        pqueue->entries = 0;
    }
}

void deletePQueue(PQueue *pqueue){
    emptyPQueue(pqueue);
    free(pqueue);
}

void addPQueue(PQueue *pqueue, int key, PQData data){
    PQItem *pqitem = (PQItem*)malloc(sizeof(PQItem));
    pqitem->key = key;
    pqitem->data = data;
    pqitem->nextItem = NULL;

    if (isEmptyPQueue(pqueue)){
        pqueue->front = pqitem;
    }
    else{
        // ASCENDING ORDER (AFKSOUSA SEIRA)
        if (pqueue->type == 0){
            if (key < pqueue->front->key){
                pqitem->nextItem = pqueue->front;
                pqueue->front = pqitem;
            }
            else{
                if (pqueue->entries == 1){
                    pqueue->front->nextItem = pqitem;
                }
                else{
                    int i;
                    PQItem *pqitem2 = pqueue->front;
                    for (i=0; i<pqueue->entries-1; i++){
                        if (key < pqitem2->nextItem->key){
                            pqitem->nextItem = pqitem2->nextItem;
                            pqitem2->nextItem = pqitem;
                            break;
                        }
                        else if (pqitem2->nextItem->nextItem == NULL){
                            pqitem2->nextItem->nextItem = pqitem;
                            break;
                        }
                        pqitem2 = pqitem2->nextItem;
                    }
                }
            }
        }
        // DESCENDING ORDER (FTHINOUSA SEIRA)
        else{
            if (key > pqueue->front->key){
                pqitem->nextItem = pqueue->front;
                pqueue->front = pqitem;
            }
            else{
                if (pqueue->entries == 1){
                    pqueue->front->nextItem = pqitem;
                }
                else{
                    int i;
                    PQItem *pqitem2 = pqueue->front;
                    for (i=0; i<pqueue->entries-1; i++){
                        if (key > pqitem2->nextItem->key){
                            pqitem->nextItem = pqitem2->nextItem;
                            pqitem2->nextItem = pqitem;
                            break;
                        }
                        else if (pqitem2->nextItem->nextItem == NULL){
                            pqitem2->nextItem->nextItem = pqitem;
                            break;
                        }
                        pqitem2 = pqitem2->nextItem;
                    }
                }
            }
        }
    }
    pqueue->entries++;
}

PQData removePQueue(PQueue *pqueue){
    PQData data;
    if (!isEmptyPQueue(pqueue)){
        PQItem *pqitem = pqueue->front;
        data = pqitem->data;
        pqueue->front = pqitem->nextItem;
        pqueue->entries--;
        free(pqitem);
    }
    return data;
}

PQData peekPQueue(PQueue *pqueue){
    PQData data;
    if (!isEmptyPQueue(pqueue)){
        PQItem *pqitem = pqueue->front;
        data = pqitem->data;
    }
    return data;
}


/* LINKED LIST (SINDEDEMENI LISTA) */


typedef struct LLItem LLItem;

struct LLItem{
    int value;
    LLItem *nextItem;
};

struct LList{
    int entries;
    LLItem *front;
};

typedef struct LList LList;

LList *createLList(int type){
    LList *llist = (LList*)malloc(sizeof(LList));
    llist->front = NULL;
    llist->entries = 0;
    return llist;
}

int getSizeLList(LList *llist){
    return llist->entries;
}

int isEmptyLList(LList *llist){
    if (llist->entries == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void emptyLList(LList *llist){
    if (!isEmptyLList(llist)){
        int i;
        LLItem *llitem;
        llitem = llist->front;
        for(i=0;i<llist->entries;i++){
            free(llitem);
            llitem = llitem->nextItem;
        }
        llist->entries = 0;
    }
}

void deleteLList(LList *llist){
    emptyLList(llist);
    free(llist);
}

void addLList(LList *llist, int item){
    LLItem *llitem = (LLItem*)malloc(sizeof(LLItem));
    llitem->value = item;
    llitem->nextItem = NULL;

    if (isEmptyLList(llist)){
        llist->front = llitem;
    }
    else{
        return;
    }
    llist->entries++;
}

int removeLList(LList *llist){
    if (!isEmptyLList(llist)){
        int value;
        LLItem *llitem = llist->front;
        value = llitem->value;
        llist->front = llitem->nextItem;
        llist->entries--;
        free(llitem);
        return value;
    }
    return 0;
}

int peekLList(LList *llist){
    if (!isEmptyLList(llist)){
        LLItem *llitem;
        llitem = llist->front;
        for(int i=0; i<llist->entries; i++){
            printf("\n%i", llitem->value);
            llitem = llitem->nextItem;
        }
        return 0;
    }
    return 0;
}