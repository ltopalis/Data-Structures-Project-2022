#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "searching.h"
#include "sort_functions.h"

int main()
{
    table_data values[DATA];
    char contents[LINE_SIZE];
    struct tm timeinfo;

    open_file("ocean.csv", values, contents);

    bubble_sort(values, DATA, TIME);

    for (int i = 0; i < __INT_MAX__; i++)
    {
        srand(time(NULL));
        timeinfo.tm_year = rand() % 2022 - 1900;
        timeinfo.tm_mon = (1 + rand() % 20) - 1;
        timeinfo.tm_mday = 1 + rand() % 35;
        timeinfo.tm_hour = 0;
        timeinfo.tm_min = 0;
        timeinfo.tm_sec = 0;

        int n = binarySearch(values, 0, DATA - 1, mktime(&timeinfo));
        int m = interpolationSearch(values, 0, DATA - 1, mktime(&timeinfo));
        int k = binary_interpolation_search(values, mktime(&timeinfo), DATA);
        int l = optimized_binary_interpolation_search(values, mktime(&timeinfo), DATA);

        if (n != m && k!=l)
        {
            printf("DATE: %d/%d/%d\n", timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_year + 1900);
            printf("====================================");
            printf("binary search       : %d\n", n);
            printf("interpolation search: %d\n", m);
            printf("BIS                 : %d\n", k);
            printf("optimized BIS       : %d\n", l);
            break;
        }
    }

    printf("PASS\n");

    return 0;
}
