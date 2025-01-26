#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "modules/dataStructures.h"
#include "modules/dataStructuresVars.h"


int main(){
    int aem;
    printf("Parakalo vale to AEM sou: ");
    scanf("%i", &aem);
    srand(aem);
    Graph *mygraph = createGraph();
    GRData data;

    int i, m;
    int from = 6;
    int to = 10;
    int size = rand() % (to - from + 1) + from;

    printf("Graph Size: %i\n\n", size);

    for (i=0; i<size; i++){
        addGraphVert(mygraph, data);
    }

    for (i=0; i<size; i++){
        for (m=0; m<size; m++){
            if (i != m){
                int makeEdge = rand() % 3;

                if (makeEdge == 1){
                    addGraphEdge(mygraph, i, m, 0, 0);
                }
            }
        }
    }

    for (i=0; i<size; i++){
        int added = 0;
        for (m=0; m<size; m++){
            if (findGraphEdge(mygraph, i, m)) added = 1;
        }
        if (!added){
            int newEdge = rand() % size;

            while (newEdge == i && size > 1){
                newEdge = rand() % size;
            }

            if (size > 1) addGraphEdge(mygraph, i, newEdge, 0, 0);
        }
    }

    printf("Adjacency Matrix:\n");
    printGraphMatrix(mygraph);
    printf("\nShortest Paths from %i to %i:\n", 0, size-1);
    printPathsGraph(mygraph, 0, size-1);
    deleteGraph(mygraph);
    return 0;
}