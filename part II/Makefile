compiler := gcc
flags := -Wall -Wextra -O3
objectFiles := struct.o AVL.o main_functions.o hashing.o menu.o main.o
neccessary := struct AVL main_functions hashing menu main

.PHONY: compile clean delete

all: compile clean

compile: ${neccessary}
	@echo "Compiling..."
	@${compiler} ${flags} ${objectFiles} -o part2 -lm
	@echo "Executable file has been created"

${neccessary}:
	@${compiler} ${flags} -c $@.c
	
clean:
	@echo "Removing object files..."
	@rm *.o

delete:
	@rm part2