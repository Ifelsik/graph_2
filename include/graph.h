#ifndef GRAPH_H
#define GRAPH_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int size;
    int **vertices;
} AdjacencyMatrix;

AdjacencyMatrix* initGraph(int size, int **matrix);

void showGraph(AdjacencyMatrix *graph_p, char* img_path);

bool isConnectedGraph(AdjacencyMatrix *graph_p);

AdjacencyMatrix* rm_edgeGraph(AdjacencyMatrix* graph_p,
                              int vert_from,
                              int vert_to);

void delGraph(AdjacencyMatrix** graph_pp);

#endif