CC=clang++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC_DIR = src
OBJ = app.cpp
INCLUDE = src/visualizer.cpp src/SortItem.cpp src/Sorting.cpp src/algos/bubble_sort.cpp src/algos/insertion_sort.cpp src/algos/merge_sort.cpp src/algos/selection_sort.cpp src/algos/counting_sort.cpp src/algos/quicksort.cpp


sav: $(SRC_DIR)/$(OBJ)
	$(CC) -o $@.out $(INCLUDE) $^ $(CFLAGS)
