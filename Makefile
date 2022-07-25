
CC = gcc
CFLAGS = -Wall -Wextra

all:
	$(CC) $(CFLAGS) -o ttt main.c

clean:
	rm -f $(BIN)
