.PHONY: compile clean

all: compile clean

compile:
	@echo "Compiling..."
	@gcc -c -Wall -Wextra -O3 *.c
	@gcc -Wall -Wextra -O3 *.o -o a.out
	@echo "Executable file has been created"
	
clean:
	@echo "Removing object files..."
	@rm *.o
