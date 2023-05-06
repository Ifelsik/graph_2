#include "../include/main.h"

int main() {
    char *path = "./files/test.txt";
    char **matrix = NULL;
    AdjacencyMatrix *graph = NULL;

    matrix = readLinesFromFile(path);
    
    graph = (AdjacencyMatrix*) malloc(sizeof(AdjacencyMatrix));
    graph->size = getMatrixSize(matrix);
    graph->vertices = parseSquareMatrix(matrix);

    if (isConnectedGraph(graph))
        puts("Graph is connected");
    else
        puts("Graph is disconected");

    showGraph(graph);
    
    delGraph(&graph);
    return 0;
}