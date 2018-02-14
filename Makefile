CFLAGS=-I/usr/local/include
LFLAGS=-L/usr/local/lib -lSDL2 -lSDL2_image

SRC= \
  src/main.cpp \
  src/util.cpp

BIN=openday

all:
	c++ $(CFLAGS) -o$(BIN) $(SRC) $(LFLAGS)

clean:
	rm -f $(BIN)
