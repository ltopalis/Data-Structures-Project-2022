.PHONY: compile clean

all: compile clean

compile:
# compile the necessary codes
	@echo "Compiling..."
	@gcc -c -Wall -Wextra -O3 fundamentals.c
	@gcc -c -Wall -Wextra -O3 file_manager.c
	@gcc -c -Wall -Wextra -O3 sort_functions.c
	@gcc -c -Wall -Wextra -O3 searching.c -lm

# compile BIS code
	@gcc -c -Wall -Wextra -O3 exercise04.c -lm
	@gcc -Wall -Wextra -O3 fundamentals.o file_manager.o sort_functions.o searching.o exercise04.o -o BIS.out -lm
	@rm exercise04.o

# compile counting sort code
	@gcc -c -Wall -Wextra -O3 main2.c
	@gcc -Wall -Wextra -O3 fundamentals.o file_manager.o sort_functions.o main2.o -o countingSort.out
	@rm main2.o

# compile Heap sort code
	@gcc -c -Wall -Wextra -O3 main1.c
		@gcc -Wall -Wextra -O3 fundamentals.o file_manager.o sort_functions.o main1.o -o countingSort.out
	@rm main1.o

	@echo "Executable file has been created"
	
clean:
	@echo "Removing object files..."
	@rm *.o
