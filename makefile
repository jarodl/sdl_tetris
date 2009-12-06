CC=g++
CFLAGS=-c -Wall
SDLFLAGS=`sdl-config --cflags --libs` -framework Cocoa
SOURCES=main.cpp Game.cpp IO.cpp Board.cpp Pieces.cpp Piece.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tetris

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(SDLFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
