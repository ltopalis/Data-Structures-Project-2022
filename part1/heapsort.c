#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "heapsort.h"
#define N 1405

void HeapSort(table_data array[], int heap_size){
    // Build heap
 for (int i = heap_size / 2 - 1; i >= 0; i--) Heapify(array, i, heap_size);
 // One by one extract an element from heap
    for (int i = heap_size - 1; i > 0; i--) {

        swap(&array[0], &array[i],TABLE_DATA);
        // call max heapify on the reduced heap
        Heapify(array, 0, i);
    }
}










