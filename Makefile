CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = simple-copy
SRC = simple-copy.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
