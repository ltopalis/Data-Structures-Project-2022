#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "sort_functions.h"

int main()
{
	double time_spent;
	table_data values[DATA];
	char first_line_content[LINE_SIZE];

	open_file("ocean.csv", values, first_line_content);

	clock_t begin = clock();

	insertion_sort(values, DATA);

	clock_t end = clock();

	print_array(values, DATA);

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nThe execution time of insertion sort is: %f\n", time_spent);

	exit(0);
}
