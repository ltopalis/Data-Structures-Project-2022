#include <stdio.h>
#include "file_manager.h"
#include "fundamentals.h"

void quicksort(table_data *data_array, int min, int max)
{
	if(min<max)
	{
		int i;
		int j = min-1;

		for(i=min; i<max; i++)
		{
			if(data_array[i].T_degC>=data_array[max].T_degC)
				continue;
			else
			{
				j++;
				swap(&data_array[i], &data_array[j], TABLE_DATA);
			}
		}
		swap(&data_array[max], &data_array[j+1], TABLE_DATA);

		quicksort(data_array, min, j);
		quicksort(data_array, j+2, max);
	}
}
