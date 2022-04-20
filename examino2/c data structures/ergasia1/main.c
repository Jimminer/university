#include <stdio.h>
#include "dataStructures.h"
#include "dataStructuresVars.h"

int main(){
    LLData data;
    LList *llist = createLList();
    data.key = 1;
    addLList(llist, -1, data);
    data.key = 5;
    addLList(llist, -1, data);
    data.key = 2;
    addLList(llist, 39, data);
    data.key = 9;
    addLList(llist, 0, data);
    peekeverything(llist);
    data = peekLList(llist, 2);
    printf("\nPEEK: %i", data.key);
    data = peekLList(llist, 60);
    printf("\nPEEK: %i", data.key);
    data = peekLList(llist, 1);
    printf("\nPEEK: %i", data.key);
    peekeverything(llist);
    return 0;
}