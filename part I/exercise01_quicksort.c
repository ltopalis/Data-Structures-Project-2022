#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "sort_functions.h"

int main()
{
	//hello
	double time_spent;
	table_data values[DATA];
	char first_lines_content[LINE_SIZE];

	open_file("ocean.csv", values, first_lines_content);

	clock_t begin = clock();

	quicksort(values, 0, DATA - 1);

	clock_t end = clock();

	print_array(values, DATA);

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nThe execution time of quicksort is: %f\n", time_spent);

	exit(0);
}
