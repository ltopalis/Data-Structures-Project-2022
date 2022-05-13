.PHONY: compile clean

all: compile clean

compile:
# compile the necessary codes
	@echo "Compiling..."
	@gcc -c -Wall -Wextra -O3 fundamentals.c
	@gcc -c -Wall -Wextra -O3 file_manager.c
	@gcc -c -Wall -Wextra -O3 sort_functions.c
	@gcc -c -Wall -Wextra -O3 searching.c -lm

# compile insertion sort code
	@gcc -c -Wall -Wextra -O3 exercise01_insertion_sort.c
	@gcc -Wall -Wextra -O3 fundamentals.o file_manager.o sort_functions.o exercise01_insertion_sort.o -o insertionSort.out
	@rm exercise01_insertion_sort.o

# compile quick sort code
	@gcc -c -Wall -Wextra -O3 exercise01_quicksort.c
	@gcc -Wall -Wextra -O3 fundamentals.o file_manager.o sort_functions.o exercise01_quicksort.o -o quickSort.out
	@rm exercise01_quicksort.o

# compile bubble and interpolation sort code
	@gcc -c -Wall -Wextra -O3 exercise03.c
	@gcc -Wall -Wextra -O3 fundamentals.o file_manager.o sort_functions.o searching.o exercise03.o -o interpolation.out -lm
	@rm exercise03.o

# compile counting sort code
	@gcc -c -Wall -Wextra -O3 exercise02_countingSort.c
	@gcc -Wall -Wextra -O3 fundamentals.o file_manager.o sort_functions.o exercise02_countingSort.o -o countingSort.out
	@rm exercise02_countingSort.o

# compile Heap sort code
	@gcc -c -Wall -Wextra -O3 exercise02_heapSort.c
	@gcc -Wall -Wextra -O3 fundamentals.o file_manager.o sort_functions.o exercise02_heapSort.o -o heapSort.out
	@rm exercise02_heapSort.o

# compile BIS code
	@gcc -c -Wall -Wextra -O3 exercise04.c -lm
	@gcc -Wall -Wextra -O3 fundamentals.o file_manager.o sort_functions.o searching.o exercise04.o -o BIS.out -lm
	@rm exercise04.o

	@echo "Executable file has been created"
	
clean:
	@echo "Removing object files..."
	@rm *.o
