#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "modules/dataStructures.h"

int hash(int index, int htsize){
    return index % htsize;
}

int dhash(int index, int htsize){
    return ((index % 30011) - 30011);
}

int main(){
    srand(time(NULL));
    HTable *htable = createHTable(200003, hash, dhash);
    int peos=100000*(10+rand()%60)+1000*(rand()%100)+rand()%1000;
    printf("%i", peos);
    HTData data;
    addHTable(htable, peos, data);
    return 0;
}