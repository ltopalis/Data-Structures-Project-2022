#ifndef SORT_FUNCTIONS_H

#define SORT_FUNCTIONS_H

void bubble_sort(table_data *pinakas, int n, FIELD t);
void countingsort(table_data array[], int size);
void Heapify(table_data array[], int node, int heap_size);
void HeapSort(table_data array[], int heap_size);

#endif