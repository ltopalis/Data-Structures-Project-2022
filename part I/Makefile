.PHONY: compile clean

all: compile clean

compile:
	@echo "Compiling..."
	@gcc -c -Wall -Wextra -O3 fundamentals.c
	@gcc -c -Wall -Wextra -O3 file_manager.c
	@gcc -c -Wall -Wextra -O3 sort_functions.c
	@gcc -c -Wall -Wextra -O3 searching.c -lm
	@gcc -c -Wall -Wextra -O3 exercise04.c -lm
	@gcc -Wall -Wextra -O3 *.o -o BIS.out -lm
	@echo "Executable file has been created"
	
clean:
	@echo "Removing object files..."
	@rm *.o
