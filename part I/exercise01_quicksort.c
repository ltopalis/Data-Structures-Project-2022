#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file_manager.h"
#include "fundamentals.h"
#include "quicksort.h"

int main()
{
	int i;
	double time_spent;
	table_data values[DATA];
	char first_lines_content[LINE_SIZE];

	open_file("ocean.csv", values, first_lines_content);

	clock_t begin = clock();

	quicksort(values, 0, DATA-1);

	clock_t end = clock();
	
	for(i=0; i<DATA; i++)
  	{
    	printf("%d) %2.d/%2.d/%d\t%.3f", i, values[i].date.tm_mday, values[i].date.tm_mon+1, values[i].date.tm_year+1900, values[i].T_degC);
    	printf("\n");
  	}

  	time_spent = (double)(end-begin)/CLOCKS_PER_SEC;

  	printf("\nThe execution time of quicksort is: %f\n", time_spent);

  	exit(0);
}
