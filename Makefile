CC = gcc
CFLAGS = -std=c11 -Wall -Werror -g
TARGET = main

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

test: $(TARGET)
	./$(TARGET) < input.txt

clean:
	rm -f $(TARGET)

.PHONY: all test clean