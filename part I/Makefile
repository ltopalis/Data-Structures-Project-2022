.PHONY: compile clean

all: compile clean

compile:
# compile the necessary codes
	@echo "Compiling..."
	@gcc -c -Wall -Wextra -O3 fundamentals.c
	@gcc -c -Wall -Wextra -O3 file_manager.c
	@gcc -c -Wall -Wextra -O3 sort_functions.c
	@gcc -c -Wall -Wextra -O3 searching.c -lm

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
