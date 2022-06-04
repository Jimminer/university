#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include "dataStructuresVars.h"
/* STACK (STIVA) */

struct Stack{
    int current;
    int size;
    StackData *items;
};

typedef struct Stack Stack;

Stack *createStack(int size);
int getSizeStack(Stack *stack);
int isEmptyStack(Stack *stack);
int isFullStack(Stack *stack);
void emptyStack(Stack *stack);
void deleteStack(Stack *stack);
void addStack(Stack *stack, StackData data);
StackData removeStack(Stack *stack);
StackData peekStack(Stack *stack);

/* QUEUE (OURA) */

struct Queue{
    int front;
    int back;
    int size;
    int entries;
    QueueData *items;
};

typedef struct Queue Queue;

Queue *createQueue(int size);
int getSizeQueue(Queue *queue);
int isEmptyQueue(Queue *queue);
int isFullQueue(Queue *queue);
void emptyQueue(Queue *queue);
void deleteQueue(Queue *queue);
void addQueue(Queue *queue, QueueData data);
QueueData removeQueue(Queue *queue);
QueueData peekQueue(Queue *queue);

/* PRIORITY QUEUE (OURA PROTERAIOTITAS) */

typedef struct PQItem PQItem;

struct PQueue{
    int type;
    int entries;
    PQItem *front;
    PQItem *back;
};

typedef struct PQueue PQueue;

struct PQItem{
    int key;
    PQData data;
    PQItem *nextItem;
};

PQueue *createPQueue(int type);

int getSizePQueue(PQueue *pqueue);
int isEmptyPQueue(PQueue *pqueue);
void emptyPQueue(PQueue *pqueue);
void deletePQueue(PQueue *pqueue);
void addPQueue(PQueue *pqueue, int key, PQData data);
PQData removePQueue(PQueue *pqueue);
PQData peekPQueue(PQueue *pqueue);

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

LList *createLList();
int getSizeLList(LList *llist);
int isEmptyLList(LList *llist);
void emptyLList(LList *llist);
void deleteLList(LList *llist);
void addLList(LList *llist, int position, LLData data);
LLData removeLList(LList *llist, int position);
LLData peekLList(LList *llist, int position);

#endif
