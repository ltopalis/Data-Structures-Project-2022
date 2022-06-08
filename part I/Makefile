compiler := gcc
flags := -Wall -Wextra -O3
neccessary := fundamentals.o file_manager.o sort_functions.o

all: compile clean

compile: fundamentals file_manager sort_functions searching exercise01_insertion_sort exercise01_quicksort exercise02_countingSort exercise02_heapSort exercise03 exercise04 tester
	@echo "Compiling..."
	@${compiler} ${flags} ${neccessary}             exercise01_insertion_sort.o -o insertionSort
	@${compiler} ${flags} ${neccessary}             exercise01_quicksort.o      -o quickSort
	@${compiler} ${flags} ${neccessary} searching.o exercise03.o                -o interpolation -lm
	@${compiler} ${flags} ${neccessary}             exercise02_countingSort.o   -o countingSort
	@${compiler} ${flags} ${neccessary}             exercise02_heapSort.o       -o heapSort
	@${compiler} ${flags} ${neccessary} searching.o exercise04.o                -o BIS -lm
	@${compiler} ${flags} ${neccessary} searching.o tester.o                    -o tester -lm
	@echo "Executable files have been created!"

fundamentals file_manager sort_functions searching exercise01_insertion_sort exercise01_quicksort exercise02_countingSort exercise02_heapSort exercise03 exercise04:
	@${compiler} ${flags} -c $@.c

tester: fundamentals file_manager sort_functions searching
	@${compiler} ${flags} -c tester.c

clean: 
	@echo "Removing object files..."
	@rm *.o
