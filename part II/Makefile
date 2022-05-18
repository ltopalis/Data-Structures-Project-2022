.PHONY: compile clean

all: compile clean

compile:
# compile the necessary codes
	@echo "Compiling..."
	@gcc -c -Wall -Wextra -O3 AVL.c
	@gcc -c -Wall -Wextra -O3 main_functions.c
	@gcc -c -Wall -Wextra -O3 menu.c
	@gcc -c -Wall -Wextra -O3 main.c
	@gcc -Wall -Wextra -O3 AVL.o main_functions.o menu.o main.o -o part2.out
	@echo "Executable file has been created"
	
clean:
	@echo "Removing object files..."
	@rm *.o
