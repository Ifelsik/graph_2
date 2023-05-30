#include "main.h"

int main() {
    char *path = "./files/input.txt";
    char **matrix = NULL;
    AdjacencyMatrix *graph = NULL;

    matrix = readLinesFromFile(path);
    
    graph = initGraph(getMatrixSize(matrix), parseSquareMatrix(matrix));

    if (isConnectedGraph(graph))
        puts("Graph is connected");
    else
        puts("Graph is disconected");

    showGraph(graph, "graph_before.png");
    graph = rm_edgeGraph(graph, 0, 1);
    showGraph(graph, "graph_after.png");

    delGraph(&graph);
    return 0;
}