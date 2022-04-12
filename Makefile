SOURCE_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

CC = gcc

CFLAGS = -Wall -Wextra `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0` -rdynamic -lm



all: init EpiLearn


init:
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)

EpiLearn: src/EpiLearn.c src/gui/gui.c src/property/mathamatics/complex_number/complex_number.c src/property/computer_architecture/integer_representation/integer_representation.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)


calculator: src/calculator/calculator.c  src/calculator/node.c  src/calculator/parser.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)

graph: src/graph/graph.c  src/graph/node.c  src/graph/parser.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)

sort: src/sortingAlgorithm/question_sort.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)

grid: $(OBJ_DIR)/mini_game/grid_game/window.o #$(OBJ_DIR)/mini_game/grid_game/script.o
	$(CC) -o $(BUILD_DIR)/$@ $(addprefix $(OBJ_DIR)/, $(^F)) $(LDFLAGS)

number: $(OBJ_DIR)/mini_game/number_game/window.o $(OBJ_DIR)/mini_game/number_game/script.o
	$(CC) -o $(BUILD_DIR)/$@ $(addprefix $(OBJ_DIR)/, $(^F)) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $(OBJ_DIR)/$(@F) $<



.PHONY: clean

clean:
	rm -f -r $(OBJ_DIR)
	rm $(BUILD_DIR)/*
