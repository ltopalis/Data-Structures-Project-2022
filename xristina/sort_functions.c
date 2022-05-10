#include <time.h>
#include <stdlib.h>
#include "fundamentals.h"
#include "sort_functions.h"

void bubble_sort(table_data *pinakas, int n, FIELD t)
{
	int i, j;

	switch (t)
	{
	case TIME:
		for (i = 0; i < n; i++)
			for (j = n - 1; j >= i + 1; j--)
				if (difftime(mktime(&pinakas[j].date), mktime(&pinakas[j - 1].date)) < 0.0)
					swap(&pinakas[j], &pinakas[j - 1], TABLE_DATA);
		break;
	case TEMPERATURE:
		for (i = 0; i < n; i++)
			for (j = n - 1; j >= i + 1; j--)
				if (pinakas[j].T_degC < pinakas[j - 1].T_degC)
					swap(&pinakas[j], &pinakas[j - 1], TABLE_DATA);
		break;
	case PHOSPHATE:
		for (i = 0; i < n; i++)
			for (j = n - 1; j >= i + 1; j--)
				if (pinakas[j].PO4uM < pinakas[j - 1].PO4uM)
					swap(&pinakas[j], &pinakas[j - 1], TABLE_DATA);
		break;
	default:
		break;
	}
}

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
	// for(int i=0;i<size;i++)
	for (int i = size - 1; i >= 0; i--)
	{
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].date.tm_mon = array[i].date.tm_mon;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].date.tm_mday = array[i].date.tm_mday;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].date.tm_year = array[i].date.tm_year;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].date.tm_hour = array[i].date.tm_hour;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].date.tm_min = array[i].date.tm_min;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].date.tm_sec = array[i].date.tm_sec;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].T_degC = array[i].T_degC;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].PO4uM = array[i].PO4uM;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].NO2uM = array[i].NO2uM;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].NO3uM = array[i].NO3uM;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].O2ml_L = array[i].O2ml_L;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].Salnty = array[i].Salnty;
		output[new_array[(int)(array[i].PO4uM * 100)] - 1].SiO3uM = array[i].SiO3uM;
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

void Heapify(table_data array[], int node, int heap_size)
{
	int bigger = node;		 // root
	int left = 2 * node + 1; // node is an index in array[]
	int right = 2 * node + 2;
	// If left child is bigger than root
	if (left < heap_size && array[left].PO4uM > array[bigger].PO4uM)
		bigger = left;

	// If right child is bigger than (int) bigger
	if (right < heap_size && array[right].PO4uM > array[bigger].PO4uM)
		bigger = right;

	// If bigger is not root
	if (bigger != node)
	{

		swap(&array[node], &array[bigger], TABLE_DATA);
		//  heapify the sub-tree
		Heapify(array, bigger, heap_size);
	}
}

void HeapSort(table_data array[], int heap_size)
{
	// Build heap
	for (int i = heap_size / 2 - 1; i >= 0; i--)
		Heapify(array, i, heap_size);
	// One by one extract an element from heap
	for (int i = heap_size - 1; i > 0; i--)
	{

		swap(&array[0], &array[i], TABLE_DATA);
		// call max heapify on the reduced heap
		Heapify(array, 0, i);
	}
}
