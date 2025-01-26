#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include "dataStructuresVars.h"

/* STACK (STIVA) */

typedef struct Stack Stack;

struct Stack{
    int current;
    int size;
    StackData *items;
};

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

typedef struct Queue Queue;

struct Queue{
    int front;
    int back;
    int size;
    int entries;
    QueueData *items;
};

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

typedef struct PQueue PQueue;

struct PQueue{
    int type;
    int entries;
    PQItem *front;
    PQItem *back;
};

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

typedef struct LList LList;

struct LLItem{
    LLData data;
    LLItem *nextItem;
};

struct LList{
    int entries;
    LLItem *front;
};

LList *createLList();
int getSizeLList(LList *llist);
int isEmptyLList(LList *llist);
void emptyLList(LList *llist);
void deleteLList(LList *llist);
void addLList(LList *llist, int position, LLData data);
LLData removeLList(LList *llist, int position);
LLData peekLList(LList *llist, int position);

/* BINARY TREE (DIADIKO DENTRO) */

typedef struct BTItem BTItem;

typedef struct BinTree BinTree;

struct BTItem{
    int key;
    BTData data;
    BTItem *LChild;
    BTItem *RChild;
};

struct BinTree{
    int entries;
    BTItem *root;
};

BinTree *createBinTree();
int getSizeBinTree(BinTree *bintree);
int isEmptyBinTree(BinTree *bintree);
void emptyBinTree(BinTree *bintree);
void deleteBinTree(BinTree *bintree);
void addBinTree(BinTree *bintree, int key, BTData data);
// BTData removeBinTree(BinTree *bintree, int key);
BTData findBinTree(BinTree *bintree, int key);
int *preOrderBinTree(BinTree *bintree);
int *inOrderBinTree(BinTree *bintree);
int *postOrderBinTree(BinTree *bintree);

/* GRAPH (GRAFOS) */

typedef struct GRVert GRVert;

typedef struct GREdge GREdge;

typedef struct Graph Graph;

struct GRVert{
    int index;
    int visited;
    GRData data;
    GRVert *nextVert;
    GREdge *nextEdge;
};

struct GREdge{
    int index;
    float grav;
    GRVert *connectedVert;
    GREdge *nextEdge;
};

struct Graph{
    int entries;
    GRVert *firstVert;
};

Graph *createGraph();
int getSizeGraph(Graph *graph);
int isEmptyGraph(Graph *graph);
void emptyGraph(Graph *graph);
void deleteGraph(Graph *graph);
void addGraphVert(Graph *graph, GRData data);
void addGraphEdge(Graph *graph, int index1, int index2, int direction, float grav);
GRData findGraphVert(Graph *graph, int index);
int findGraphEdge(Graph *graph, int index1, int index2);
void printPathsGraph(Graph *graph, int index1, int index2);
void printGraphList(Graph *graph);
void printGraphMatrix(Graph *graph);

/* HASHING TABLE (KATAKERMATISMOS) */

typedef struct HTEntry HTEntry;

typedef struct HTList HTList;

typedef struct HTable HTable;

struct HTEntry{
    int index;
};

struct HTList{
    HTEntry *nextEntry;
};

struct HTable{
    int entries;
    HTList *firstList;
};

#endif
