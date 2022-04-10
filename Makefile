SOURCE_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

CC = gcc

CFLAGS = -Wall -Wextra `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0` -rdynamic



all: init EpiLearn


init:
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)

EpiLearn: src/EpiLearn.c src/gui/gui.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)


calculator: $(OBJ_DIR)/calculator/calculator.o
	$(CC) -o $(BUILD_DIR)/$@ $(addprefix $(OBJ_DIR)/, $(^F)) $(LDFLAGS)

sort: $(OBJ_DIR)/sortingAlgorithm/question_sort.o
	$(CC) -o $(BUILD_DIR)/$@ $(addprefix $(OBJ_DIR)/, $(^F)) $(LDFLAGS)

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
