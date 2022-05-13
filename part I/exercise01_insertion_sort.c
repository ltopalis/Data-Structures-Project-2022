#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "sort_functions.h"

int main()
{
	int i;
	double time_spent;
	table_data values[DATA];
	char first_line_content[LINE_SIZE];

	open_file("ocean.csv", values, first_line_content);

	clock_t begin = clock();

	insertion_sort(values, DATA);

	clock_t end = clock();

	for (i = 1; i <= DATA; i++)
	{
		printf("%d) %2.d/%2.d/%d\t%.3f", i, values[i].date.tm_mday, values[i].date.tm_mon + 1, values[i].date.tm_year + 1900, values[i].T_degC);
		printf("\n");
	}

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nThe execution time of insertion sort is: %f\n", time_spent);

	exit(0);
}
