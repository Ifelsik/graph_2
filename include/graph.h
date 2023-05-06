#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct {
    int size;
    int **vertices;
} AdjacencyMatrix;

void showGraph(AdjacencyMatrix *graph_p);

bool isConnectedGraph(AdjacencyMatrix *graph_p);

void delGraph(AdjacencyMatrix** graph_pp);

#endif