#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include "dataStructuresVars.h"
/* STACK (STIVA) */

struct Stack{
    int cur;
    int size;
    int* items;
};

typedef struct Stack Stack;

Stack* createStack(int);
int getSizeStack(Stack*);
int isEmptyStack(Stack*);
int isFullStack(Stack*);
void emptyStack(Stack*);
void deleteStack(Stack*);
void addStack(Stack*, int);
int removeStack(Stack*);
int peekStack(Stack*);

/* QUEUE (OURA) */

struct Queue{
    int front;
    int back;
    int size;
    int* items;
};

typedef struct Queue Queue;

Queue* createQueue(int);
int getSizeQueue(Queue*);
int isEmptyQueue(Queue*);
int isFullQueue(Queue*);
void emptyQueue(Queue*);
void deleteQueue(Queue*);
void addQueue(Queue*, int);
int removeQueue(Queue*);
int peekQueue(Queue*);

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
    int value;
    LLItem *nextItem;
};

struct LList{
    int entries;
    LLItem *front;
};

typedef struct LList LList;

LList *createLList(int type);
int getSizeLList(LList *llist);
int isEmptyLList(LList *llist);
void emptyLList(LList *llist);
void deleteLList(LList *llist);
void addLList(LList *llist, int item);
int removeLList(LList *llist);
int peekLList(LList *llist);

#endif
