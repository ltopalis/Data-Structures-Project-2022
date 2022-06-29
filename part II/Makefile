compiler := gcc
flags := -Wall -Wextra -O3
files := struct.c AVL.c avl_by_temp.c main_functions.c hashing.c menu.c main.c

.PHONY: compile clean delete

all: compile

compile:
	@echo "Compiling..."
	@${compiler} ${flags} ${files} -o part2 -lm
	@echo "Executable file has been created"

delete:
	@rm part2