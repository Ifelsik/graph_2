#include "../include/graph.h"
#include "../include/file.h"


AdjacencyMatrix* initGraph(int size, int **matrix) {
    AdjacencyMatrix *graph_p = (AdjacencyMatrix *) malloc(sizeof(AdjacencyMatrix));
    if (graph_p == NULL) {
        fputs("ERROR in function 'initGraph': Can't allocate memory", stderr);
        exit(EXIT_FAILURE);
    }
    graph_p->size = size;
    graph_p->vertices = matrix;
    return graph_p;
}

void showGraph(AdjacencyMatrix *graph_p, char *img_path) {
    FILE *file_p = NULL;
    char *template = NULL;
    char *cmd = NULL;
    char *path = "./graph.txt";
    int cmd_len = 128;

    template = readFile("./files/dot_template.txt");

    file_p = fopen(path, "w");
    if (file_p == NULL) {
        fprintf(stderr, "ERROR in function 'showGraph': file doesn't exist at this path %s\n", path);
        exit(EXIT_FAILURE);
    }
    
    fputs(template, file_p);

    for (int i = 0; i < graph_p->size; i++) {
        for (int j = 0; j < graph_p->size; j++) {
            if (graph_p->vertices[i][j] != 0)
                fprintf(file_p, "%d -> %d[label=\"%.2f\"]\n", i, j,
                        (float) graph_p->vertices[i][j]);
        }
    }
    putc('}', file_p);

    fclose(file_p);

    cmd = (char*) malloc(sizeof(char) * cmd_len);
    if (cmd == NULL) {
        fprintf(stderr, "ERROR in function 'showGraph': memory allocation error for cmd\n");
        exit(EXIT_FAILURE);
    }
    sprintf(cmd, "dot -Tpng > %s < graph.txt", img_path);

    system(cmd);

    free(cmd);
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

 AdjacencyMatrix* rm_edgeGraph(AdjacencyMatrix* graph_p,
                               int vert_from,
                               int vert_to) {
    if (vert_from >= graph_p->size || vert_to >= graph_p->size) {
        fputs("These vertices even doesn't exist\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (!graph_p->vertices[vert_from][vert_to]) {
        puts("Such edge doesn't exist");
        return graph_p;
    }

    graph_p->vertices[vert_from][vert_to] = 0;
    puts("This edge succesfully deleted!");
    return graph_p;
 }
