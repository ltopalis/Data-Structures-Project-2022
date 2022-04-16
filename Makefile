.PHONY: compile clean

all: compile clean

compile:
	@echo "Compiling..."
	@gcc -c -Wall -Wextra -O3 -g fundamentals.c
	@gcc -c -Wall -Wextra -O3 -g file_manager.c
	@gcc -c -Wall -Wextra -O3 -g sort_functions.c
	@gcc -c -Wall -Wextra -O3 -g exercise04.c
	@gcc -Wall -Wextra -O3 *.o -o a.out
	@echo "Executable file has been created"
	
clean:
	@echo "Removing object files..."
	@rm *.o
