.POSIX:
.SUFFIXES:
CC      = clang
CFLAGS  = -W -O -Isrc
LDFLAGS = -lm -lpthread -lcheck
BUILD   = build/
SRC     = $(wildcard src/*.c)
TEST    = $(wildcard tests/*.c)
OBJ     = $(SRC:.c=.o)
TOBJ    = $(TEST:.c=.o)

all: test main

main: app/main.o $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

test: $(OBJ) $(TOBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm -f **/*.o test main