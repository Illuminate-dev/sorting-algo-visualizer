CC=clang++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = src
OBJ = app.cpp
INCLUDE = visualizer.cpp


sav: $(SRC_DIR)/$(OBJ)
	$(CC) -o $@.out $(SRC_DIR)/$(INCLUDE) $^ $(CFLAGS)
