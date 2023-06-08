CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11 -pthread

SRC = main.c num_length.c num_reverse_print.c log_inout.c Num_length_print.c
OBJ = $(SRC:.c=.o)

DEPS = num_length.h num_reverse_print.h Num_length_print.h

.PHONY: clean

all: Num_length_print

Num_length_print: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o Num_length_print
