#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "heapify.h"
#define N 1405


void Heapify(table_data array[],int node,int heap_size){
    int bigger=node;//root
    int left = 2 *node + 1; // node is an index in array[]
    int right = 2 *node + 2;
    // If left child is bigger than root
    if (left < heap_size&& array[left].PO4uM > array[bigger].PO4uM) bigger= left;

    // If right child is bigger than (int) bigger
    if (right < heap_size && array[right].PO4uM > array[bigger].PO4uM)
       bigger= right;

    // If bigger is not root
    if (bigger != node) {

        swap(&array[node],&array[bigger],TABLE_DATA);
    //  heapify the sub-tree
        Heapify(array, bigger, heap_size);
    }
}
