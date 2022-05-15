SOURCE_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

CC = gcc

CFLAGS = -Wall -Wextra `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0` -rdynamic -lm



all: init EpiLearn


init:
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)

EpiLearn: src/EpiLearn.c src/gui/gui.c src/property/mathematics/complex_number/complex_number.c src/property/computer_architecture/integer_representation/integer_representation.c src/calculator/calculator.c src/calculator/parser.c src/calculator/node.c src/graph/graph.c src/graph/parser.c src/graph/node.c src/mcqGenerator/computer_architecture/computer_architecture.c src/mcqGenerator/mathematics/mathematics.c src/property/algorithm/list/list.c src/gui/list.c src/property/algorithm/fifo/fifo.c src/property/algorithm/lifo/lifo.c src/gui/fifo_lifo.c src/gui/paint2D.c src/property/algorithm/binary_tree/binary_tree.c src/gui/binary_tree.c src/mcqGenerator/algorithm/algorithm.c src/calculator/integral.c src/mini_game/tetris_game/checker.c src/mini_game/tetris_game/shape.c src/mini_game/tetris_game/tetris.c src/mini_game/tetris_game/tetwin.c src/mini_game/number_game/number.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)


calculator: src/calculator/calculator.c  src/calculator/integral.c src/calculator/node.c  src/calculator/parser.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)

graph: src/graph/graph.c  src/graph/node.c  src/graph/parser.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)

sort: src/sortingAlgorithm/question_sort.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)

grid: $(OBJ_DIR)/mini_game/grid_game/window.o #$(OBJ_DIR)/mini_game/grid_game/script.o
	$(CC) -o $(BUILD_DIR)/$@ $(addprefix $(OBJ_DIR)/, $(^F)) $(LDFLAGS)

number: $(OBJ_DIR)/mini_game/number_game/window.o $(OBJ_DIR)/mini_game/number_game/script.o
	$(CC) -o $(BUILD_DIR)/$@ $(addprefix $(OBJ_DIR)/, $(^F)) $(LDFLAGS)

chimp: $(OBJ_DIR)/mini_game/chimp_game/window.o #$(OBJ_DIR)/mini_game/grid_game/script.o
	$(CC) -o $(BUILD_DIR)/$@ $(addprefix $(OBJ_DIR)/, $(^F)) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $(OBJ_DIR)/$(@F) $<



.PHONY: clean

clean:
	rm -f -r $(OBJ_DIR)
	rm $(BUILD_DIR)/*
