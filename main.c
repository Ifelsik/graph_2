#include "main.h"

int main() {
    char *path = "./files/test.txt";
    char **matrix = NULL;
    AdjacencyMatrix *graph = NULL;

    matrix = readLinesFromFile(path);
    
    graph = initGraph(getMatrixSize(matrix), parseSquareMatrix(matrix));

    if (isConnectedGraph(graph))
        puts("Graph is connected");
    else
        puts("Graph is disconected");

    showGraph(graph);
    
    delGraph(&graph);
    return 0;
}