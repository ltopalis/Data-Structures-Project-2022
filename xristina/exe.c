#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "exe3.h" 

int binarySearch(table_data *arr, int low, int high, time_t x)
{

  while (high >= low)
  {
    int mid = low + (high - low) / 2;
    if (difftime(mktime(&arr[mid].date), x)==0)                            
    {
      return mid;
    }
    else if (difftime(mktime(&arr[mid].date), x)>0)
    {
      high = mid - 1;
    }
    else if (difftime(mktime(&arr[mid].date), x)<0)
    {
      low = mid + 1;
    }
  }

  return -1;
}

int interpolationSearch(table_data *arr, int low, int high, time_t x)
{
  int pos;
  pos=low + (high-low)*(x-mktime(&arr[low].date))/(mktime(&arr[high].date)-mktime(&arr[low].date));

    if (difftime(mktime(&arr[pos].date), x)==0) 
    {
      return pos;
    }

    if (difftime(mktime(&arr[pos].date), x)<0) 
    {
      return interpolationSearch(arr, pos + 1, high, x);
    }

    if (difftime(mktime(&arr[pos].date), x)>0) 
    {
      return interpolationSearch(arr, low, pos - 1, x);
    }
  

  return -1;
}