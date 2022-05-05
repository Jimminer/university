/*
LIBRARY MADE BY DIMITRIOS GKOUMAS (cs04502)
*/

#include <stdlib.h>
#include <stdio.h>

#include "dataStructures.h"
#include "dataStructuresVars.h"


/* STACK (STIVA) */


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
        int i, m = pqueue->entries;
        PQItem *pqitem, *temp;
        pqitem = pqueue->front;
        for(i=0;i<m;i++){
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
                    int i, m = pqueue->entries;
                    PQItem *temp = pqueue->front;
                    for (i=0; i<m-1; i++){
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
                    int i, m = pqueue->entries;
                    PQItem *temp = pqueue->front;
                    for (i=0; i<m-1; i++){
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
        int i, m = llist->entries;
        LLItem *llitem, *temp;
        llitem = llist->front;
        for(i=0;i<m;i++){
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


/* BINARY TREE (DIADIKO DENTRO) */


BinTree *createBinTree(){
    BinTree *bintree = (BinTree*)malloc(sizeof(BinTree));
    bintree->entries = 0;
    bintree->root = NULL;
    return bintree;
}

int getSizeBinTree(BinTree *bintree){
    return bintree->entries;
}

int isEmptyBinTree(BinTree *bintree){
    return (bintree->entries == 0);
}

void emptyBinTree(BinTree *bintree){
    return;
}

void deleteBinTree(BinTree *bintree){
    return;
}

void addBinTree(BinTree *bintree, int key, BTData data){
    BTItem *btitem = (BTItem*)malloc(sizeof(BTItem));
    btitem->key = key;
    btitem->data = data;
    btitem->Parent = NULL;
    btitem->LChild = NULL;
    btitem->RChild = NULL;

    if (isEmptyBinTree(bintree)){
        bintree->root = btitem;
        bintree->root->Parent = bintree->root;
        printf("\n\nADDED %i as root", key);
    }
    else{
        if (getSizeBinTree(bintree) == 1){
            if (key >= bintree->root->key){
                btitem->Parent = bintree->root;
                bintree->root->RChild = btitem;
                printf("\n\nADDED %i as a right child of %i", key, btitem->Parent->key);
            }
            else{
                btitem->Parent = bintree->root;
                bintree->root->LChild = btitem;
                printf("\n\nADDED %i as a left child of %i", key, btitem->Parent->key);
            }
        }
        else{
            BTItem *temp = bintree->root;
            int i, m = bintree->entries;

            for (i=0; i<m; i++){
                if (key >= temp->key){
                    if (temp->RChild == NULL){
                        btitem->Parent = temp;
                        temp->RChild = btitem;
                        printf("\n\nADDED %i as a right child of %i", key, btitem->Parent->key);
                        break;
                    }
                    else{
                        temp = temp->RChild;
                    }
                }
                else{
                   if (temp->LChild == NULL){
                        btitem->Parent = temp;
                        temp->LChild = btitem;
                        printf("\n\nADDED %i as a left child of %i", key, btitem->Parent->key);
                        break;
                    }
                    else{
                        temp = temp->LChild;
                    }
                }
            }
        }
    }
    bintree->entries++;
}

// void peekBinTree(BinTree *bintree){
//     int i, m = bintree->entries;
//     BTItem *temp = bintree->root;
//     for (i=0; i<m; i++){
//         break;
//     }
// }