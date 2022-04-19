#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "sort_functions.h"
#include "searching.h"

int main()
{
    int k;
    table_data *ocean = (table_data *)malloc(sizeof(table_data) * DATA);
    char *contents = (char *)malloc(sizeof(char) * LINE_SIZE);
    struct tm t;

    if (!open_file("ocean.csv", ocean, contents))
    {
        fprintf(stderr, "Error reading file!");
        exit(0);
    }

    bubble_sort(ocean, DATA, TIME);
    print_array(ocean, DATA);

    t.tm_mon = 1 - 1;
    t.tm_mday = 7;
    t.tm_year = 2005 - 1900;
    t.tm_sec = 0;  /* seconds,  range 0 to 59          */
    t.tm_min = 0;  /* minutes, range 0 to 59           */
    t.tm_hour = 0; /* hours, range 0 to 23             */
    t.tm_wday = 0; /* day of the week, range 0 to 6    */
    t.tm_yday = 0; /* day in the year, range 0 to 365  */
    t.tm_isdst = -1;

    k = Linear_Search(ocean, mktime(&t), 0, DATA - 1);
    printf("%d ", k);
    if (k != -1)
        printf("%d/%d/%d\n", ocean[k].date.tm_mon + 1, ocean[k].date.tm_mday, ocean[k].date.tm_year + 1900);
    else
        printf("Record hasn't been found!\n");

    free(ocean);
    free(contents);
    return 0;
}

