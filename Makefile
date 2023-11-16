CXX := g++
CXXFLAGS := -Wall -Wextra `sdl2-config --cflags` -std=c++11
LDFLAGS := `sdl2-config --libs`

TARGET := main

all: $(TARGET)

$(TARGET): main.o
	$(CXX) $^ -o $@ $(LDFLAGS)

main.o: main.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
