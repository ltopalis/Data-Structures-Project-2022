compiler := gcc
flags := -Wall -Wextra -O3
objectFiles := fundamentals.o file_manager.o sort_functions.o
neccessary := fundamentals file_manager sort_functions searching exercise01_insertion_sort exercise01_quicksort exercise02_countingSort exercise02_heapSort exercise03 exercise04

.PHONY: compile delete

all: compile clean

compile: ${neccessary}
	@echo "Compiling..."
	@${compiler} ${flags} ${objectFiles}             exercise01_insertion_sort.o -o insertionSort
	@${compiler} ${flags} ${objectFiles}             exercise01_quicksort.o      -o quickSort
	@${compiler} ${flags} ${objectFiles} searching.o exercise03.o                -o interpolation -lm
	@${compiler} ${flags} ${objectFiles}             exercise02_countingSort.o   -o countingSort
	@${compiler} ${flags} ${objectFiles}             exercise02_heapSort.o       -o heapSort
	@${compiler} ${flags} ${objectFiles} searching.o exercise04.o                -o BIS -lm
	@echo "Executable files have been created!"

${neccessary}:
	@${compiler} ${flags} -c $@.c

clean: 
	@echo "Removing object files..."
	@rm *.o

delete:
	@rm insertionSort quickSort interpolation countingSort heapSort BIS
