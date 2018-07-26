CC = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE -lGL -lglut -lpng -lz -lm


src = $(wildcard *.c)
obj = $(src:.c=.o)

gauss.so:
	$(CC) -o gauss.so $(src)

.PHONY: clean
clean:
	rm -f $(obj) gauss.so