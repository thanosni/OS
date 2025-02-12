CC = gcc

CFLAGS = -Wall 

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

TARGETS = $(SRC:.c=)

.PHONY: all clean

all: $(TARGETS)

$(TARGETS): %: %.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGETS)
