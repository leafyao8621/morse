CC = gcc
SRC = $(wildcard src/*.c) $(wildcard src/*/*.c) $(wildcard src/*/*/*.c)
OBJ = $(SRC:.c=.o)
BIN = morse

%.o: %.c
	$(CC) -g -c $< -o $@

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

.PHONY: clean
clean:
	@rm $(OBJ)
	@rm $(BIN)
