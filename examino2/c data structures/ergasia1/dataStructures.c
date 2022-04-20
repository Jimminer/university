/*
LIBRARY MADE BY DIMITRIOS GKOUMAS (cs04502)
*/

#include <stdlib.h>

#include "dataStructuresVars.h"


/* STACK (STIVA) */


struct Stack{
    int current;
    int size;
    StackData *items;
};

typedef struct Stack Stack;

Stack *createStack(int size){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->current = -1;
    stack->size = size;
    stack->items = (StackData*)malloc(sizeof(StackData) * size);
    return stack;
}

int getSizeStack(Stack *stack){
    return stack->current + 1;
}

int isEmptyStack(Stack *stack){
    return (stack->current == -1);
}

int isFullStack(Stack *stack){
    return (stack->current + 1 == stack->size);
}

void emptyStack(Stack *stack){
    stack->current = -1;
}

void deleteStack(Stack *stack){
    free(stack->items);
    free(stack);
}

void addStack(Stack *stack, StackData data){
    if (!isFullStack(stack)){
        stack->items[++stack->current] = data;
    }
}

StackData removeStack(Stack *stack){
    StackData data;
    if (!isEmptyStack(stack)){
        data = stack->items[stack->current];
        stack->current--;
    }
    return data;
}

StackData peekStack(Stack *stack){
    StackData data;
    if (!isEmptyStack(stack)){
        data = stack->items[stack->current];
    }
    return data;
}


/* QUEUE (OURA) */


struct Queue{
    int front;
    int back;
    int size;
    int entries;
    QueueData *items;
};

typedef struct Queue Queue;

Queue *createQueue(int size){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->back = -1;
    queue->size = size;
    queue->entries = 0;
    queue->items = (QueueData*)malloc(sizeof(QueueData) * size);
    return queue;
}

int getSizeQueue(Queue *queue){
    return queue->entries;
}

int isEmptyQueue(Queue *queue){
    return (queue->entries == 0);
}

int isFullQueue(Queue *queue){
    return (queue->entries == queue->size);
}

void emptyQueue(Queue *queue){
    queue->front = -1;
    queue->back = -1;
    queue->entries = 0;
}

void deleteQueue(Queue *queue){
    free(queue->items);
    free(queue);
}

void addQueue(Queue *queue, QueueData data){
    if (!isFullQueue(queue)){
        queue->back++;
        queue->items[queue->back % queue->size] = data;
        queue->entries++;
    }
}

QueueData removeQueue(Queue *queue){
    QueueData data;
    if (!isEmptyQueue(queue)){
        queue->front = (queue->front + 1) % queue->size;
        queue->entries--;
        data = queue->items[queue->front];
    }
    return data;
}

QueueData peekQueue(Queue *queue){
    QueueData data;
    if (!isEmptyQueue(queue)){
        data = queue->items[(queue->front + 1) % queue-> size];
    }
    return data;
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
    return (pqueue->entries == 0);
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
                    PQItem *temp = pqueue->front;
                    for (i=0; i<pqueue->entries-1; i++){
                        if (key < temp->nextItem->key){
                            pqitem->nextItem = temp->nextItem;
                            temp->nextItem = pqitem;
                            break;
                        }
                        else if (temp->nextItem->nextItem == NULL){
                            temp->nextItem->nextItem = pqitem;
                            break;
                        }
                        temp = temp->nextItem;
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
                    PQItem *temp = pqueue->front;
                    for (i=0; i<pqueue->entries-1; i++){
                        if (key > temp->nextItem->key){
                            pqitem->nextItem = temp->nextItem;
                            temp->nextItem = pqitem;
                            break;
                        }
                        else if (temp->nextItem->nextItem == NULL){
                            temp->nextItem->nextItem = pqitem;
                            break;
                        }
                        temp = temp->nextItem;
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
    LLData data;
    LLItem *nextItem;
};

struct LList{
    int entries;
    LLItem *front;
};

typedef struct LList LList;

LList *createLList(){
    LList *llist = (LList*)malloc(sizeof(LList));
    llist->front = NULL;
    llist->entries = 0;
    return llist;
}

int getSizeLList(LList *llist){
    return llist->entries;
}

int isEmptyLList(LList *llist){
    return (llist->entries == 0);
}

void emptyLList(LList *llist){
    if (!isEmptyLList(llist)){
        int i;
        LLItem *llitem, *temp;
        llitem = llist->front;
        for(i=0;i<llist->entries;i++){
            temp = llitem;
            free(llitem);
            llitem = temp->nextItem;
        }
        llist->entries = 0;
    }
}

void deleteLList(LList *llist){
    emptyLList(llist);
    free(llist);
}

void addLList(LList *llist, int position, LLData data){
    LLItem *llitem = (LLItem*)malloc(sizeof(LLItem));
    llitem->data = data;
    llitem->nextItem = NULL;

    if (isEmptyLList(llist)){
        llist->front = llitem;
    }
    else{
        if (position > llist->entries || position < 0) position = llist->entries;

        if (position == 0){
            llitem->nextItem = llist->front;
            llist->front = llitem;
        }
        else{
            int i;
            LLItem *temp = llist->front;
            for (i=0; i<position-1; i++){
                temp = temp->nextItem;
            }
            if (temp->nextItem == NULL){
                temp->nextItem = llitem;
            }
            else{
                llitem->nextItem = temp->nextItem;
                temp->nextItem = llitem;
            }
        }
    }
    llist->entries++;
}

LLData removeLList(LList *llist, int position){
    LLData data;
    if (!isEmptyLList(llist)){
        LLItem *llitem = llist->front;
        int i;
        if (position >= llist->entries || position < 0) position = 0;
        if (position == 0){
            data = llitem->data;
            llist->front = llitem->nextItem;
        }
        else{
            LLItem *temp = llist->front;
            for (i=0; i<position-1; i++){
                temp = temp->nextItem;
            }
            llitem = temp->nextItem;
            data = llitem->data;
            temp->nextItem = llitem->nextItem;
        }
        llist->entries--;
        free(llitem);
    }
    return data;
}

LLData peekLList(LList *llist, int position){
    LLData data;
    if (!isEmptyLList(llist)){
        LLItem *llitem = llist->front;
        int i;
        if (position >= llist->entries || position < 0) position = 0;
        if (position == 0){
            data = llitem->data;
        }
        else{
            LLItem *temp = llist->front;
            for (i=0; i<position-1; i++){
                temp = temp->nextItem;
            }
            llitem = temp->nextItem;
            data = llitem->data;
        }
    }
    return data;
}