#include <stdio.h>
#include <stdlib.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "sort_functions.h"

int main()
{
    table_data values[1405];
    char *contents = (char *)malloc(sizeof(char) * LINE_SIZE);
    
    open_file("ocean.csv", values, contents);
    int k = sizeof(values) / sizeof(values[0]);
    countingsort(values, k);
    printArray(values, k);
    
    free(contents);
    exit(0);
}
