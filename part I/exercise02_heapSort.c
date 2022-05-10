#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "sort_functions.h"


int main()
{
    table_data values[1405];
    char *contents = (char *)malloc(sizeof(char) * LINE_SIZE);
    clock_t c3, c4;
    open_file("ocean.csv", values, contents);
    int k = sizeof(values) / sizeof(values[0]);
    c3 = clock();
    HeapSort(values, k);
    c4 = clock();
    printArray(values, k);
    printf("====================\n");
    printf("Heapsort %f sec\n", (float)(c4 - c3) / CLOCKS_PER_SEC);

    free(contents);

    return 0;
}
