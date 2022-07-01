#ifndef SORT_FUNCTIONS_H

#define SORT_FUNCTIONS_H

/*
   bubble_sort(): taksinomisi toy pinaka me xrisi tou
   bubble sort, to pedio pou taksinomeitai kathorizetai apo
   to pedio t
*/
void bubble_sort(table_data *pinakas, int n, FIELD t);
/*
   countingsort(): taksinomisi toy array me megethos pou
   kathorizetai apo thn size me xrisi counting sort
*/
void countingsort(table_data array[], int size);
/*
   Heapify(): ftiaxnei ton soro tou array me riza to node.
   To megethos tou sorou dinetai apo to heap_size
*/
void Heapify(table_data array[], int node, int heap_size);
/*
   HeapSOrt(): taksinomisi toy array me xrisi heap sort
   aksiopiontas ton Heapify(). To megethos tou heap dinetai
   apo to heap_size
*/
void HeapSort(table_data array[], int heap_size);
/* 
   insertion_sort(): taksinomisi toy data_array me xrisi
   insertion sort. Taksinomei mexri to max - 1 
*/
void insertion_sort(table_data *data_array, int max);
/* 
   quick_sort(): taksinomisi toy data_array me xrisi
   quick sort. Taksinomei apo to min mexri to max - 1 
*/
void quicksort(table_data *data_array, int min, int max);

#endif