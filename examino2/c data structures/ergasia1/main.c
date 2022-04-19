#include <stdio.h>
#include "dataStructures.h"
#include "dataStructuresVars.h"

int main(){
    PQData data;
    PQueue *pqueue = createPQueue(0);
    data.size = 5; data.money = 35.2;
    addPQueue(pqueue, 5, data);
    data.size = 15; data.money = 28;
    addPQueue(pqueue, 15, data);
    data.size = 8; data.money = 139.15;
    addPQueue(pqueue, 8, data);
    data.size = 1; data.money = 1982.52;
    addPQueue(pqueue, 1, data);
    data.size = 25; data.money = 2.3;
    addPQueue(pqueue, 25, data);
    data = removePQueue(pqueue);
    printf("\n\ndata.size = %i\ndata.money = %f", data.size, data.money);
    data = removePQueue(pqueue);
    printf("\n\ndata.size = %i\ndata.money = %f", data.size, data.money);
    data = removePQueue(pqueue);
    printf("\n\ndata.size = %i\ndata.money = %f", data.size, data.money);
    data = removePQueue(pqueue);
    printf("\n\ndata.size = %i\ndata.money = %f", data.size, data.money);
    data = peekPQueue(pqueue);
    printf("\n\ndata.size = %i\ndata.money = %f", data.size, data.money);
    data = peekPQueue(pqueue);
    printf("\n\ndata.size = %i\ndata.money = %f", data.size, data.money);
    return 0;
}