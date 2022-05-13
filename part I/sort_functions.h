#ifndef SORT_FUNCTIONS_H

#define SORT_FUNCTIONS_H

void bubble_sort(table_data *pinakas, int n, FIELD t);
void countingsort(table_data array[], int size);
void Heapify(table_data array[], int node, int heap_size);
void HeapSort(table_data array[], int heap_size);
void insertion_sort(table_data *data_array, int max);
void quicksort(table_data *data_array, int min, int max);

#endif