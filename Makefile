SOURCE_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

CC = gcc

CFLAGS = -Wall -Wextra `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0` -rdynamic -lm



all: init EpiLearn


init:
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)
	@echo "Initialization..."

EpiLearn: src/EpiLearn.c src/gui/gui.c src/property/mathematics/complex_number/complex_number.c src/property/computer_architecture/integer_representation/integer_representation.c src/calculator/calculator.c src/calculator/parser.c src/calculator/node.c src/graph/graph.c src/graph/parser.c src/graph/node.c src/mcqGenerator/computer_architecture/computer_architecture.c src/mcqGenerator/mathematics/mathematics.c src/property/algorithm/list/list.c src/gui/list.c src/property/algorithm/fifo/fifo.c src/property/algorithm/lifo/lifo.c src/gui/fifo_lifo.c src/gui/paint2D.c src/property/algorithm/binary_tree/binary_tree.c src/gui/binary_tree.c src/mcqGenerator/algorithm/algorithm.c src/calculator/integral.c src/mini_game/tetris_game/checker.c src/mini_game/tetris_game/shape.c src/mini_game/tetris_game/tetris.c src/mini_game/tetris_game/tetwin.c src/mini_game/number_game/number.c src/mini_game/grid_game/grid.c src/mini_game/type_game/type.c src/mcqGenerator/electronic/electronic.c
	@echo "Building The Project:"
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)
	@echo "src/EpiLearn.c \nsrc/gui/gui.c \nsrc/property/mathematics/complex_number/complex_number.c \nsrc/property/computer_architecture/integer_representation/integer_representation.c \nsrc/calculator/calculator.c \nsrc/calculator/parser.c \nsrc/calculator/node.c \nsrc/graph/graph.c \nsrc/graph/parser.c \nsrc/graph/node.c \nsrc/mcqGenerator/computer_architecture/computer_architecture.c \nsrc/mcqGenerator/mathematics/mathematics.c \nsrc/property/algorithm/list/list.c \nsrc/gui/list.c \nsrc/property/algorithm/fifo/fifo.c \nsrc/property/algorithm/lifo/lifo.c \nsrc/gui/fifo_lifo.c \nsrc/gui/paint2D.c \nsrc/property/algorithm/binary_tree/binary_tree.c \nsrc/gui/binary_tree.c \nsrc/mcqGenerator/algorithm/algorithm.c \nsrc/calculator/integral.c \nsrc/mini_game/tetris_game/checker.c \nsrc/mini_game/tetris_game/shape.c \nsrc/mini_game/tetris_game/tetris.c \nsrc/mini_game/tetris_game/tetwin.c \nsrc/mini_game/number_game/number.c \nsrc/mini_game/grid_game/grid.c \nsrc/mini_game/type_game/type.c \nsrc/mcqGenerator/electronic/electronic.c"
	@echo "Build Finished..."

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
	@rm -f -r $(OBJ_DIR)
	@rm $(BUILD_DIR)/*
	@echo "Cleaning of all build files..."
