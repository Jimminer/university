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
    data.valid = 0;

    if (!isEmptyStack(stack)){
        data = stack->items[stack->current];
        data.valid = 1;
        stack->current--;
    }
    return data;
}

StackData peekStack(Stack *stack){
    StackData data;
    data.valid = 0;

    if (!isEmptyStack(stack)){
        data = stack->items[stack->current];
        data.valid = 1;
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
    data.valid = 0;

    if (!isEmptyQueue(queue)){
        queue->front = (queue->front + 1) % queue->size;
        queue->entries--;
        data = queue->items[queue->front];
        data.valid = 1;
    }
    return data;
}

QueueData peekQueue(Queue *queue){
    QueueData data;
    data.valid = 0;

    if (!isEmptyQueue(queue)){
        data = queue->items[(queue->front + 1) % queue-> size];
        data.valid = 1;
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
            temp = pqitem->nextItem;
            free(pqitem);
            pqitem = temp;
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
    data.valid = 0;

    if (!isEmptyPQueue(pqueue)){
        PQItem *pqitem = pqueue->front;
        data = pqitem->data;
        data.valid = 1;
        pqueue->front = pqitem->nextItem;
        pqueue->entries--;
        free(pqitem);
    }
    return data;
}

PQData peekPQueue(PQueue *pqueue){
    PQData data;
    data.valid = 0;

    if (!isEmptyPQueue(pqueue)){
        PQItem *pqitem = pqueue->front;
        data = pqitem->data;
        data.valid = 1;
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
            temp = llitem->nextItem;
            free(llitem);
            llitem = temp;
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
    data.valid = 0;
    
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
        data.valid = 1;
        llist->entries--;
        free(llitem);
    }
    return data;
}

LLData peekLList(LList *llist, int position){
    LLData data;
    data.valid = 0;

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
        data.valid = 1;
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

void internal_deleteBTItem(BTItem *btitem){
    if (btitem!=NULL){
        internal_deleteBTItem(btitem->LChild);
        internal_deleteBTItem(btitem->RChild);
        free(btitem);
    }
}

void emptyBinTree(BinTree *bintree){
    if (!isEmptyBinTree(bintree)){
        internal_deleteBTItem(bintree->root);
        bintree->entries = 0;
    }
}

void deleteBinTree(BinTree *bintree){
    emptyBinTree(bintree);
    free(bintree);
}

void addBinTree(BinTree *bintree, int key, BTData data){
    BTItem *btitem = (BTItem*)malloc(sizeof(BTItem));
    btitem->key = key;
    btitem->data = data;
    btitem->LChild = NULL;
    btitem->RChild = NULL;

    if (isEmptyBinTree(bintree)){
        bintree->root = btitem;
    }
    else{
        BTItem *temp = bintree->root;
        int i, m = bintree->entries;

        for (i=0; i<m; i++){
            if (key >= temp->key){
                if (temp->RChild == NULL){
                    temp->RChild = btitem;
                    break;
                }
                else{
                    temp = temp->RChild;
                }
            }
            else{
                if (temp->LChild == NULL){
                    temp->LChild = btitem;
                    break;
                }
                else{
                    temp = temp->LChild;
                }
            }
        }
    }
    bintree->entries++;
}

// void internal_findSuccessorBinTree(BTItem *btitem, int *current, int searchKey){
//     if (btitem != NULL){
//         if (btitem->key > searchKey && btitem->key < *current){
//             *current = btitem->key;
//             printf("FOUND: %i", btitem->key);
//         }
//     }
// }

// BTData removeBinTree(BinTree *bintree, int key){
//     BTData data;
//     if (!isEmptyBinTree(bintree)){
//         BTItem *temp = bintree->root;
//         int i, m = bintree->entries, current = 0, *c;
//         c = &current;

//         for (i=0; i<m; i++){
//             if (key == temp->key){
//                 break;
//             }
//             else if (key > temp->key){
//                 temp = temp->RChild;
//             }
//             else{
//                 temp = temp->LChild;
//             }
//         }

//         internal_findSuccessorBinTree(temp, c, key);
//     }
//     return data;
// }

BTItem *internal_findBinTree(BinTree *bintree, int key){
    BTItem *temp = bintree->root;
    int i, m = bintree->entries;

    for (i=0; i<m; i++){
        if (key == temp->key){
            break;
        }
        else if (key > temp->key && (temp->RChild != NULL)){
            temp = temp->RChild;
        }
        else if (key < temp->key && (temp->LChild != NULL)){
            temp = temp->LChild;
        }
    }

    return temp;
}

BTData findBinTree(BinTree *bintree, int key){
    BTData data;
    data.valid = 0;

    if (!isEmptyBinTree(bintree)){
        BTItem *btitem = internal_findBinTree(bintree, key);
        data = btitem->data;
        data.valid = 1;
    }
    return data;
}

void internal_preOrderBinTree(BTItem *btitem, int *table, int *counter){
    if (btitem!=NULL){
        table[*counter] = btitem->key;
        (*counter)++;
        internal_preOrderBinTree(btitem->LChild, table, counter);
        internal_preOrderBinTree(btitem->RChild, table, counter);
    }
}

void internal_inOrderBinTree(BTItem *btitem, int *table, int *counter){
    if (btitem!=NULL){
        internal_inOrderBinTree(btitem->LChild, table, counter);
        table[*counter] = btitem->key;
        (*counter)++;
        internal_inOrderBinTree(btitem->RChild, table, counter);
    }
}

void internal_postOrderBinTree(BTItem *btitem, int *table, int *counter){
    if (btitem!=NULL){
        internal_postOrderBinTree(btitem->LChild, table, counter);
        internal_postOrderBinTree(btitem->RChild, table, counter);
        table[*counter] = btitem->key;
        (*counter)++;
    }
}

int *preOrderBinTree(BinTree *bintree){
    int *table = (int*)malloc(sizeof(int)*bintree->entries);
    if (!isEmptyBinTree(bintree)){
        int counter = 0, *c;
        c = &counter;

        internal_preOrderBinTree(bintree->root, table, c);
    }
    return table;
}

    // EXAMPLE:
    // int *table;
    // table = preOrderBinTree(bintree);
    // printf("\nPreorder: ");
    // for (int i=0; i<20; i++){
    //     if (!table[i]) break;
    //     printf("%i,", table[i]);
    // }

int *inOrderBinTree(BinTree *bintree){
    int *table = (int*)malloc(sizeof(int)*bintree->entries);
    if (!isEmptyBinTree(bintree)){
        int counter = 0, *c;
        c = &counter;

        internal_inOrderBinTree(bintree->root, table, c);
    }
    return table;
}

    // EXAMPLE:
    // int *table;
    // table = inOrderBinTree(bintree);
    // printf("\nInorder: ");
    // for (int i=0; i<20; i++){
    //     if (!table[i]) break;
    //     printf("%i,", table[i]);
    // }

int *postOrderBinTree(BinTree *bintree){
    int *table = (int*)malloc(sizeof(int)*bintree->entries);
    if (!isEmptyBinTree(bintree)){
        int counter = 0, *c;
        c = &counter;

        internal_postOrderBinTree(bintree->root, table, c);
    }
    return table;
}



/* GRAPH (GRAFOS) */


Graph *createGraph(){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->firstVert = NULL;
    graph->entries = 0;
    return graph;
}

int getSizeGraph(Graph *graph){
    return graph->entries;
}

int isEmptyGraph(Graph *graph){
    return (graph->entries == 0);
}

void emptyGraph(Graph *graph){
    if (isEmptyGraph(graph)) return;

    GRVert *tempV, *grvert = graph->firstVert;
    GREdge *tempE, *gredge;

    while (grvert != NULL){
        gredge = grvert->nextEdge;

        while (gredge != NULL){
            tempE = gredge->nextEdge;
            free(gredge);
            gredge = tempE;
        }
        tempV = grvert->nextVert;
        free(grvert);
        grvert = tempV;
    }

    graph->entries = 0;
}

void deleteGraph(Graph *graph){
    emptyGraph(graph);
    free(graph);
}

void addGraphVert(Graph *graph, GRData data){
    GRVert *grvert = (GRVert*)malloc(sizeof(GRVert));
    grvert->index = 0;
    grvert->visited = 0;
    grvert->data = data;
    grvert->nextVert = NULL;
    grvert->nextEdge = NULL;

    if (isEmptyGraph(graph)){
        graph->firstVert = grvert;
    }
    else{
        GRVert *temp = graph->firstVert;
        grvert->index++;
        while (temp->nextVert != NULL){
            grvert->index++;
            temp = temp->nextVert;
        }
        temp->nextVert = grvert;
    }
    graph->entries++;
}

int internal_hasEdgeGraph(GRVert *grvert, int index){
    GREdge *temp = grvert->nextEdge;

    if (temp == NULL) return 0;

    while (temp->index != index){
        if (temp->nextEdge == NULL) return 0;
        temp = temp->nextEdge;
    }

    return 1;
}

void addGraphEdge(Graph *graph, int index1, int index2, int direction, float grav){
    if (isEmptyGraph(graph)) return;

    GRVert *temp1 = graph->firstVert;
    GRVert *temp2 = graph->firstVert;

    while (temp1->index != index1){
        if (temp1->nextVert == NULL) return;
        temp1 = temp1->nextVert;
    }

    while (temp2->index != index2){
        if (temp2->nextVert == NULL) return;
        temp2 = temp2->nextVert;
    }

    if (internal_hasEdgeGraph(temp1, index2)) return;

    GREdge *gredge = (GREdge*)malloc(sizeof(GREdge));
    gredge->index = index2;
    gredge->grav = grav;
    gredge->connectedVert = temp2;
    gredge->nextEdge = NULL;

    if (temp1->nextEdge == NULL){
        temp1->nextEdge = gredge;
    }
    else{
        GREdge *temp = temp1->nextEdge;
        while (temp->nextEdge != NULL){
            temp = temp->nextEdge;
        }
        temp->nextEdge = gredge;
    }

    if (direction == 0) addGraphEdge(graph, index2, index1, 1, grav);
}

GRData findGraphVert(Graph *graph, int index){
    GRData data;
    data.valid = 0;
    
    if (isEmptyGraph(graph)) return data;

    GRVert *temp = graph->firstVert;

    while (temp->index != index){
        if (temp->nextVert == NULL) return data;
        temp = temp->nextVert;
    }

    data = temp->data;
    data.valid = 1;
    return data;
}

int findGraphEdge(Graph *graph, int index1, int index2){
    if (isEmptyGraph(graph)) return 0;

    GRVert *temp = graph->firstVert;

    while (temp->index != index1){
        if (temp->nextVert == NULL) return 0;
        temp = temp->nextVert;
    }

    return internal_hasEdgeGraph(temp, index2);
}


int internal_isVisitedInPathGraph(LList *llist, int from, int to){
    if (isEmptyLList(llist)) return 0;

    int i;
    LLData data;

    for (i=0; i<getSizeLList(llist); i++){
        data = peekLList(llist, i);
        if ((data.from == from && data.to == to) || (data.from == to && data.to == from)) return 1;
    }
    return 0;
}


void printPathsGraph(Graph *graph, int index1, int index2){
    LList *queue = createLList();
    LList *final = createLList();
    LList *last = createLList();

    GRVert *start = graph->firstVert;
    GRVert *tempv;

    GREdge *edge = start->nextEdge;
    GREdge *tempe;

    LLData data, tempd;

    start->visited = 1;
    while (start->index != index1){
        if (start->nextVert == NULL) return;
        start = start->nextVert;
    }

    while (edge != NULL){
        data.from = start->index;
        data.to = edge->index;
        data.weight = 1;
        addLList(queue, -1, data);
        edge = edge->nextEdge;
    }

    while (!isEmptyLList(queue)){
        data = removeLList(queue, 0);
        addLList(final, -1, data);

        tempv = graph->firstVert;

        while (tempv->index != data.to){
            if (tempv->nextVert == NULL) return;
            tempv = tempv->nextVert;
        }
        if (tempv->visited) continue;

        tempe = tempv->nextEdge;

        if (tempe != NULL) data.weight = data.weight + 1;;

        while (tempe != NULL){
            if (internal_isVisitedInPathGraph(final, tempv->index, tempe->index)){
                tempe = tempe->nextEdge;
                continue;
            }
            data.from = tempv->index;
            data.to = tempe->index;
            addLList(queue, -1, data);
            tempe = tempe->nextEdge;
        }
    }


    int i, min = graph->entries;

    for (i=0; i<getSizeLList(final); i++){
        data = peekLList(final, i);
        if (data.to == index2){
            if (data.weight < min) min = data.weight;
        }
    }
    for (i=0; i<getSizeLList(final); i++){
        data = peekLList(final, i);
        if (data.to == index2 && data.weight == min){
            addLList(last, -1, data);
        }
    }
    while (!isEmptyLList(last)){
        int searchFrom, searchTo, searchWeight, tableSize;
        tempd = peekLList(last, 0);
        searchFrom = tempd.from;
        searchTo = tempd.to;
        searchWeight = tableSize = tempd.weight;
        int *table = (int*)malloc(sizeof(int)*tableSize);
        table[0] = index1;

        while (searchWeight != 0){
            for (i=0; i<getSizeLList(final); i++){
                data = peekLList(final, i);
                if (data.to == searchTo && data.weight == searchWeight){
                    if (data.from == searchFrom || searchFrom == -1){
                        searchTo = data.from;
                        searchFrom = -1;
                        searchWeight = data.weight -1;
                        table[data.weight] = data.to;
                        if (data.weight == 1) break;
                    }
                }
            }
        }
        for (i=0; i<tableSize; i++){
            printf("%i -> ", table[i]);
        }
        printf("%i\n", table[tableSize]);
        removeLList(last, 0);
    }

    deleteLList(queue);
    deleteLList(final);
    deleteLList(last);
}

void printGraphList(Graph *graph){
    GRVert *grvert = graph->firstVert;
    GREdge *gredge;

    while (grvert != NULL){
        printf("%i ->", grvert->index);
        gredge = grvert->nextEdge;

        while (gredge != NULL){
            printf(" %i ", gredge->index);
            gredge = gredge->nextEdge;
        }
        printf("\n");
        grvert = grvert->nextVert;
    }
}

void printGraphMatrix(Graph *graph){
    GRVert *grvert = graph->firstVert;
    int index, i;

    printf("   ");
    while (grvert != NULL){
        printf(" %i", grvert->index);
        grvert = grvert->nextVert;
    }

    grvert = graph->firstVert;

    printf("\n  ┏");
    for (i = 0; i<graph->entries; i++){
        printf("━━");
    }
    printf("━┓");

    while (grvert != NULL){
        printf("\n%i ┃", grvert->index);
        for (index = 0; index < graph->entries; index++){
            printf(" %i", internal_hasEdgeGraph(grvert, index));
        }
        printf(" ┃");
        grvert = grvert->nextVert;
    }

    printf("\n  ┗");
    for (i = 0; i<graph->entries; i++){
        printf("━━");
    }
    printf("━┛");
}


/* HASHING TABLE (KATAKERMATISMOS) */


HTable *createHTable(int size, HTFunc hashfunc, HTFunc dbhashfunc){
    HTable *htable = (HTable*)malloc(sizeof(HTable));
    htable->size = size;
    htable->entries = 0;
    htable->nextEntry = (HTEntry*)malloc(sizeof(HTEntry));
    htable->hashfunc = hashfunc;
    htable->dbhashfunc = dbhashfunc;

    int i;
    HTEntry *temp;
    HTEntry **htentry = &htable->nextEntry;

    for (i=0; i<size; i++){
        temp = (HTEntry*)malloc(sizeof(HTEntry));
        *htentry = temp;
        (*htentry)->key = i;
        printf("%i\n", (*htentry)->key);
        *htentry = (*htentry)->nextEntry;
        
    }
    return htable;
}

int getSizeHTable(HTable *htable){
    return (htable->entries);
}

int isEmptyHTable(HTable *htable){
    return (htable->entries==0);
}



void addHTable(HTable *htable, int index, HTData data){
    HTEntry *htentry = (HTEntry*)malloc(sizeof(HTEntry));
    int key = htable->hashfunc(index, htable->size);
    htentry->key = key;
    htentry->data = data;

    int i, collision = 0, size = getSizeHTable(htable);
    HTEntry *temp = htable->nextEntry;

    while (temp->key != key){
        printf("im at: 1056 (%i)\n", temp->key);
        if (htable->nextEntry == NULL) return;
        if (htable->nextEntry->key == key) break;
        temp = temp->nextEntry;
    }

    if (htable->nextEntry != NULL){
        htable->nextEntry = htentry;
        printf("added node at pos: %i\n", key);
    }
    else{
        collision = 1;
        int key2;
        while (collision){
            key2 = htable->dbhashfunc(key, htable->size) % htable->size;
            key += key2;
            temp = htable->nextEntry;

            while (temp->key != key){
                if (htable->nextEntry == NULL) return;
                if (htable->nextEntry->key == key) break;
                temp = htable->nextEntry;
            }

            if (htable->nextEntry != NULL){
                htable->nextEntry = htentry;
                printf("added node at pos: %i\n", key);
            }
        }
    }
}