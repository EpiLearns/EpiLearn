SOURCE_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

CC = gcc

CFLAGS = -Wall -Wextra --cflags gtk+-3.0`
LDFLAGS = --libs gtk+-3.0`

SRC = $(shell find $(SOURCE_DIR) -name "*.c" ! -name "*main.c")
OBJ = $(pathsubst $(SOURCE_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: init EpiLearn


init:
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)

EpiLearn: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

calculator: $(OBJ_DIR)/calculator.o
	$(CC) -o $(BUILD_DIR)/$(@F) $^ $(LDFLAGS)

ide: $(OBJ_DIR)/ide.o
	$(CC) -o $(BUILD_DIR)/$(@F) $^ $(LDFLAGS)

#
# mini_games
#

grid: $(OBJ_DIR)/window.o $(OBJ_DIR)/script.o
	$(CC) -o $(BUILD_DIR)/$(@F) $^ $(LDFLAGS)
number: $(OBJ_DIR)/window.o $(OBJ_DIR)/script.o
	$(CC) -o $(BUILD_DIR)/$(@F) $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: init %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f -r $(OBJ_DIR)
