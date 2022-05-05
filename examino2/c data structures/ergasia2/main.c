#include <stdio.h>
#include <stdlib.h>

#include "modules/dataStructures.h"
#include "modules/dataStructuresVars.h"

int main(){
    BinTree *bintree = createBinTree();
    BTData data;
    data.skata = 5;
    addBinTree(bintree, 50, data);
    data.skata = 26;
    addBinTree(bintree, 6, data);
    data.skata = 55;
    addBinTree(bintree, 2, data);
    data.skata = 80;
    addBinTree(bintree, 15, data);
    data.skata = 3;
    addBinTree(bintree, 20, data);
    data.skata = 3;
    addBinTree(bintree, 60, data);
    data.skata = 3;
    addBinTree(bintree, 75, data);
    data.skata = 3;
    addBinTree(bintree, 35, data);
    data.skata = 3;
    addBinTree(bintree, 55, data);
    data.skata = 3;
    addBinTree(bintree, 90, data);
    data.skata = 3;
    addBinTree(bintree, 13, data);
    data.skata = 3;
    addBinTree(bintree, 44, data);
    data.skata = 3;
    addBinTree(bintree, 24, data);
    data.skata = 3;
    addBinTree(bintree, 70, data);
    data.skata = 3;
    addBinTree(bintree, 67, data);
    data.skata = 3;
    addBinTree(bintree, 82, data);
    return 0;
}