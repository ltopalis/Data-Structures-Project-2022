#include <stdio.h>
#include "file_manager.h"
#include "fundamentals.h"

void insertion_sort(table_data *data_array, int max)
{
	int i;
	int k;

	for(i=1; i<max; i++)
  	{
    	if(data_array[i].T_degC<=data_array[i+1].T_degC)
      		continue;
    	else if(data_array[i].T_degC>data_array[i+1].T_degC)
      		swap(&data_array[i], &data_array[i+1], TABLE_DATA);
      
      	if(i==1)
        	continue;
      	else
      	{
        	for(k=i; k>0; k--)
        	{
          	if(data_array[k].T_degC>=data_array[k-1].T_degC)
            	break;
          	else if(data_array[k].T_degC<data_array[k-1].T_degC)
            	swap(&data_array[k], &data_array[k-1], TABLE_DATA);
        	}
      	}  
    }
}
