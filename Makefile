CC := gcc
CFLAGS := -Wall -Wextra `sdl2-config --cflags` -std=c99
LDFLAGS := `sdl2-config --libs`

TARGET := main

all: $(TARGET)

$(TARGET): main.o
	$(CC) $^ -o $@ $(LDFLAGS)

main.o: main.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(TARGET) *.o
