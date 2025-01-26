#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_VERTICES 50
#define BUFFER_SIZE 10000

typedef struct Edge {
    int source;
    int destination;
} Edge;

typedef struct Graph {
    int vertices[MAX_VERTICES];
    Edge edges[MAX_VERTICES * MAX_VERTICES / 2];
    int numVertices;
    int numEdges;
} Graph;

void printGraph(Graph graph) {
    printf("Adjacency lists:\n\n");

    for (int i = 0; i < graph.numVertices; i++) {
        printf("%i: ", graph.vertices[i]);

        for (int j = 0; j < graph.numEdges; j++) {
            if (graph.edges[j].source == graph.vertices[i]) {
                printf("%i ", graph.edges[j].destination);
            }
            else if (graph.edges[j].destination == graph.vertices[i]) {
                printf("%i ", graph.edges[j].source);
            }
        }

        printf("\n");
    }

    printf("\n");
}

void plotGraph(Graph graph) {
    FILE *plotFile = fopen("plot.data", "w");
    
    fprintf(plotFile, "graph {\n");
    fprintf(plotFile, "    layout=circo;\n");
    fprintf(plotFile, "    node [shape=circle];\n");

    for (int i = 0; i < graph.numVertices; i++) {
        fprintf(plotFile, "    %i;\n", graph.vertices[i]);
    }

    for (int i = 0; i < graph.numEdges; i++) {
        fprintf(plotFile, "    %i -- %i;\n", graph.edges[i].source, graph.edges[i].destination);
    }

    fprintf(plotFile, "}\n");

    fclose(plotFile);

    system("dot -Tpng plot.data -o plot.png");

    printf("Graph plotted and saved to plot.png\n");
    printf("\n");
}

Graph readGraph(FILE *file, int readFromFile) {
    Graph graph;

    char buffer[BUFFER_SIZE];
    char *point = buffer;
    int number;

    if (!readFromFile) {
        printf("Enter the vertices list (ex. {1,2,3}):\n");
    }
    fgets(buffer, BUFFER_SIZE, file);

    while (*point) {
        if (isdigit(*point)) {
            graph.vertices[graph.numVertices++] = atoi(point);

            while (isdigit(*point)) {
                point++;
            }
        }
        else {
            point++;
        }
    }

    if (!readFromFile) {
        printf("Enter the edges list (ex. {{1,2},{2,3},{3,1}}):\n");
    }
    fgets(buffer, BUFFER_SIZE, file);
    point = buffer;
    int currentEdge = 0;

    while (*point) {
        if (isdigit(*point)) {
            if (currentEdge % 2 == 0) {
                graph.edges[graph.numEdges].source = atoi(point);
            }
            else {
                graph.edges[graph.numEdges].destination = atoi(point);
                graph.numEdges++;
            }

            currentEdge = (currentEdge + 1) % 2;

            while (isdigit(*point)) {
                point++;
            }
        }
        else {
            point++;
        }
    }

    for (int i = 0; i < graph.numVertices; i++) {
        for (int j = 0; j < graph.numEdges; j++) {
            if (graph.edges[j].source == graph.vertices[i]) {
                break;
            }
            else if (graph.edges[j].destination == graph.vertices[i]) {
                break;
            }
            else if (j == graph.numEdges - 1) {
                printf("Error: Vertex %i is not connected to any other vertex\n", graph.vertices[i]);
                exit(1);
            }
        }
    }

    return graph;
}

int main(int argc, char *argv[]) {
    Graph graph;

    if (argc == 1) {
        graph = readGraph(stdin, 0);
    }
    else {
        FILE *file = fopen(argv[1], "r");

        if (file == NULL) {
            printf("Error: Could not open file\n");
            return 1;
        }

        graph = readGraph(file, 1);

        fclose(file);
    }

    printGraph(graph);
    plotGraph(graph);

    printf("1. Search for a vertex\n");
    printf("2. Add a vertex\n");
    printf("3. Remove a vertex\n");
    printf("4. Print graph\n");
    printf("h. Show this message\n");
    printf("q. Quit\n");

    while (1) {
        printf("\n");
        printf("Enter an option: ");

        char option;
        option = getchar();
        // getchar();
        printf("\n");

        switch (option) {
            case '1': {
                printf("Enter a vertex to search: ");

                int vertex;
                scanf("%i", &vertex);
                printf("\n");

                for (int i = 0; i < graph.numVertices; i++) {
                    if (graph.vertices[i] == vertex) {
                        printf("Vertex %i found\n", vertex);
                        break;
                    }
                    else if (i == graph.numVertices - 1) {
                        printf("Vertex %i not found\n", vertex);
                    }
                }

                break;
            }

            case '2': {
                printf("Enter a vertex to add: ");

                int vertex;
                int found = 0;
                scanf("%i", &vertex);
                printf("\n");

                for (int i = 0; i < graph.numVertices; i++) {
                    if (graph.vertices[i] == vertex) {
                        printf("Error: Vertex %i already exists\n", vertex);
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    break;
                }

                graph.vertices[graph.numVertices++] = vertex;

                while (1) {
                    printf("Enter an edge connection for %i: ", vertex);

                    int destination;
                    scanf("%i", &destination);
                    printf("\n");

                    for (int i = 0; i < graph.numVertices; i++) {
                        if (graph.vertices[i] == destination) {
                            break;
                        }
                        else if (i == graph.numVertices - 1) {
                            printf("Error: Vertex %i not found\n", destination);
                            break;
                        }
                    }
                    
                    graph.edges[graph.numEdges].source = vertex;
                    graph.edges[graph.numEdges].destination = destination;
                    graph.numEdges++;

                    printf("Edge %i -> %i added\n", vertex, destination);

                    printf("Add another edge? (y/n): ");

                    char answer;
                    scanf(" %c", &answer);
                    printf("\n");

                    if (answer == 'n') {
                        break;
                    }
                }

                printGraph(graph);
                plotGraph(graph);

                break;
            }

            case '3': {
                printf("Enter a vertex to remove: ");

                int vertex;
                scanf("%i", &vertex);
                printf("\n");

                for (int i = 0; i < graph.numVertices; i++) {
                    for (int j = 0; j < graph.numEdges; j++) {
                        if (graph.edges[j].source == vertex || graph.edges[j].destination == vertex) {
                            graph.edges[j] = graph.edges[graph.numEdges - 1];
                            graph.numEdges--;
                        }
                    }

                    if (graph.vertices[i] == vertex) {
                        graph.vertices[i] = graph.vertices[graph.numVertices - 1];
                        graph.numVertices--;

                        printf("Vertex %i removed\n", vertex);

                        break;
                    }

                    else if (i == graph.numVertices - 1) {
                        printf("Error: Vertex %i not found\n", vertex);
                    }
                }

                printGraph(graph);
                plotGraph(graph);

                break;
            }

            case '4': {
                printGraph(graph);
                plotGraph(graph);

                break;
            }

            case 'h': {
                printf("Options:\n\n");
                printf("1. Search for a vertex\n");
                printf("2. Add a vertex\n");
                printf("3. Remove a vertex\n");
                printf("4. Print graph\n");
                printf("h. Show this message\n");
                printf("q. Quit\n");
                printf("\n");

                break;
            }

            case 'q': {
                return 0;
            }

            default: {
                printf("Error: Invalid option\n");

                break;
            }
        }
    }

    return 0;
}