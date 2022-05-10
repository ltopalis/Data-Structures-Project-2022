#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "countingsort.h"
#include <time.h>



void countingsort(table_data array[], int size)
{
  table_data output[size];

  // Find the largest
  int max = array[0].PO4uM * 100;
  for (int i = 0; i < size; i++)
  {
    if (array[i].PO4uM * 100 > max)
      max = array[i].PO4uM * 100;
  }

  int new_array[max + 1];
  // Initialize count array with all zeros.
  for (int i = 0; i < max + 1; i++)
  {
    new_array[i] = 0;
  }
  // Store the count of each element
  for (int i = 0; i < size; i++)
  {
    new_array[(int)(array[i].PO4uM * 100)]++;
  }
  // Store the cummulative count of each array
  for (int i = 1; i < max + 1; i++)
  {
    new_array[i] += new_array[i - 1];
  }


  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  //for(int i=0;i<size;i++)
  for (int i = size - 1; i >= 0; i--)
  {
    output[new_array[(int)(array[i].PO4uM * 100)] -1].date.tm_mon = array[i].date.tm_mon;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].date.tm_mday = array[i].date.tm_mday;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].date.tm_year = array[i].date.tm_year;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].date.tm_hour = array[i].date.tm_hour;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].date.tm_min = array[i].date.tm_min;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].date.tm_sec = array[i].date.tm_sec;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].T_degC = array[i].T_degC;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].PO4uM = array[i].PO4uM;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].NO2uM = array[i].NO2uM;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].NO3uM = array[i].NO3uM;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].O2ml_L = array[i].O2ml_L;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].Salnty = array[i].Salnty;
    output[new_array[(int)(array[i].PO4uM * 100)] -1].SiO3uM = array[i].SiO3uM;
    new_array[(int)(array[i].PO4uM * 100)]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++)
  {
    array[i].date.tm_mon = output[i].date.tm_mon;
    array[i].date.tm_mday = output[i].date.tm_mday;
    array[i].date.tm_year = output[i].date.tm_year;
    array[i].date.tm_hour = output[i].date.tm_hour;
    array[i].date.tm_min = output[i].date.tm_min;
    array[i].date.tm_sec = output[i].date.tm_sec;
    array[i].T_degC = output[i].T_degC;
    array[i].PO4uM = output[i].PO4uM;
    array[i].NO2uM = output[i].NO2uM;
    array[i].NO3uM = output[i].NO3uM;
    array[i].O2ml_L = output[i].O2ml_L;
    array[i].Salnty = output[i].Salnty;
    array[i].SiO3uM = output[i].SiO3uM;
  }
}

