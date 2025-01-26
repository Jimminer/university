#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

typedef struct {
    int V, E;
    Edge* edge;
} Graph;

Graph createGraph(int V, int E) {
    Graph graph;
    graph.V = V;
    graph.E = E;
    graph.edge = (Edge*) malloc(graph.E * sizeof(Edge));
    return graph;
}

void BellmanFord(Graph graph, int source) {
    int V = graph.V;
    int E = graph.E;
    int distance[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph.edge[j].source;
            int v = graph.edge[j].destination;
            int weight = graph.edge[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = graph.edge[j].source;
        int v = graph.edge[j].destination;
        int weight = graph.edge[j].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("The graph contains a negative weight cycle\n");
            return;
        }
    }

    printf("Node\tdistanceance from Source\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t\t%d\t\t\t", i, distance[i]);
        if (distance[i] != INT_MAX) {
            int current = i;
            while (current != -1) {
                printf("%d ", current);
                current = parent[current];
            }
        } else {
            printf("No path available");
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    int E = 8;

    Graph graph = createGraph(V, E);

    graph.edge[0].source = 0;
    graph.edge[0].destination = 1;
    graph.edge[0].weight = 4;

    graph.edge[1].source = 0;
    graph.edge[1].destination = 2;
    graph.edge[1].weight = 3;

    graph.edge[2].source = 1;
    graph.edge[2].destination = 2;
    graph.edge[2].weight = -1;

    graph.edge[3].source = 1;
    graph.edge[3].destination = 3;
    graph.edge[3].weight = 2;

    graph.edge[4].source = 2;
    graph.edge[4].destination = 3;
    graph.edge[4].weight = 5;

    graph.edge[5].source = 2;
    graph.edge[5].destination = 4;
    graph.edge[5].weight = 2;

    graph.edge[6].source = 3;
    graph.edge[6].destination = 4;
    graph.edge[6].weight = -3;

    graph.edge[7].source = 4;
    graph.edge[7].destination = 1;
    graph.edge[7].weight = 1;

    BellmanFord(graph, 0);

    graph.edge[6].weight = -13;

    printf("Changing the weight of the edge E->D to -13\n");

    BellmanFord(graph, 0);

    return 0;
}