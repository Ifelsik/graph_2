#include "../include/graph.h"
#include "../include/file.h"


AdjacencyMatrix* initGraph(int size, int **matrix) {
    AdjacencyMatrix *graph_p = (AdjacencyMatrix *) malloc(sizeof(AdjacencyMatrix));
    if (graph_p == NULL) {
        fprintf(stderr, "ERROR occured during allocate memory in function 'initGraph'\n");
        exit(EXIT_FAILURE);
    }
    graph_p->size = size;
    graph_p->vertices = matrix;
    return graph_p;
}

void showGraph(AdjacencyMatrix *graph_p) {
    FILE *file_p = NULL;
    char *template = NULL;

    template = readFile("./files/dot_template.txt");

    file_p = fopen("./graph.txt", "w");
    if (file_p == NULL) {
        puts("Error in function showGraph: file doesn't exist");
        exit(EXIT_FAILURE);
    }
    
    fputs(template, file_p);

    for (int i = 0; i < graph_p->size; i++) {
        for (int j = 0; j <= i; j++) {
            if (graph_p->vertices[i][j] != 0)
                fprintf(file_p, "%d -- %d[label=\"%.2f\"]\n", i, j,
                        (float) graph_p->vertices[i][j]); 
        }
    }
    putc('}', file_p);

    fclose(file_p);
    system("dot -Tpng > graph_visualization.png < graph.txt");
}

void dfsGraph(AdjacencyMatrix *graph_p, bool *visited, int start_vertex) {
    visited[start_vertex] = true;
    for (int i = 0; i < graph_p->size; i++) {
        if (!visited[i] && graph_p->vertices[start_vertex][i] != 0)
            dfsGraph(graph_p, visited, i);
    }
}

bool isConnectedGraph(AdjacencyMatrix *graph_p) {
    bool *visited = (bool*) calloc(graph_p->size, sizeof(bool));
    dfsGraph(graph_p, visited, 0);
    for(int i = 0; i < graph_p->size; i++) {
        if (!visited[i])
            return false;
    }
    return true;
}

void delGraph(AdjacencyMatrix  **graph_pp) {
    for(int i = 0; i < (*graph_pp)->size; i++) {
        free((*graph_pp)->vertices[i]);
    }
    free((*graph_pp)->vertices);
    free(*graph_pp);
    *graph_pp = NULL;
}