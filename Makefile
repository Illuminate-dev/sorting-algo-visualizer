CC=clang++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
OBJ = app.cpp

sav: $(OBJ)
	$(CC) -o $@.out $^ $(CFLAGS)
