CC=gcc
CFLAGS=-Wall -g
SRC_DIR=./src


graph: main.o file.o matrix_parser.o graph.o
	$(CC) $(CFLAGS) main.o file.o matrix_parser.o graph.o -o graph

main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c

file.o: $(SRC_DIR)/file.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/file.c

matrix_parser.o: $(SRC_DIR)/matrix_parser.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/matrix_parser.c

graph.o: $(SRC_DIR)/graph.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/graph.c

clean:
	rm -rf *.o graph_visualization.png graph.txt graph