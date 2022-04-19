#include <stdio.h>
#include <time.h>
#include <math.h>
#include "fundamentals.h"
#include "searching.h"

int Linear_Search(table_data *array, time_t date, int start, int finish)
{
    int i;

    for (i = start; i <= finish; i++)
        if (difftime(date, mktime(&array[i].date)) == 0.0)
            return i;

    return -1;
}