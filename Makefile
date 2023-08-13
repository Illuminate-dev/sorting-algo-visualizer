CC=clang++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = src
OBJ = app.cpp
INCLUDE = src/visualizer.cpp src/SortItem.cpp


sav: $(SRC_DIR)/$(OBJ)
	$(CC) -o $@.out $(INCLUDE) $^ $(CFLAGS)
