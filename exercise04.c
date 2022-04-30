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
    clock_t c1, c2;

    if (!open_file("ocean.csv", ocean, contents))
    {
        fprintf(stderr, "Error reading file!");
        exit(0);
    }

    bubble_sort(ocean, DATA, TIME);
    //print_array(ocean, DATA);

    do
    {
        printf("Give month: ");
        k = scanf("%d", &t.tm_mon);
    } while (!(t.tm_mon > 0 && t.tm_mon < 13));
    do
    {
        printf("Give day: ");
        k = scanf("%d", &t.tm_mday);
    } while (!(t.tm_mday > 0 && t.tm_mday < 32));
    do
    {
        printf("Give year: ");
        k = scanf("%d", &t.tm_year);
    } while (!(t.tm_year > 0));

    t.tm_mon  -= 1;
    t.tm_year -= 1900;
    t.tm_sec   = 0;  /* seconds,  range 0 to 59          */
    t.tm_min   = 0;  /* minutes, range 0 to 59           */
    t.tm_hour  = 0; /* hours, range 0 to 23             */
    t.tm_wday  = 0; /* day of the week, range 0 to 6    */
    t.tm_yday  = 0; /* day in the year, range 0 to 365  */
    t.tm_isdst = -1;

    c1 = clock();
    k = optimized_binary_interpolation_search(ocean, mktime(&t), DATA);
    c2 = clock();

    if (k != -1)
        printf("%d/%d/%d\n", ocean[k].date.tm_mon + 1, ocean[k].date.tm_mday, ocean[k].date.tm_year + 1900);
    else
        printf("Record hasn't been found!\n");

    printf("Arxi: %ld, Telos: %ld, Xronos: %f\n", c1, c2, (float)(c2 - c1)/CLOCKS_PER_SEC);

    free(ocean);
    free(contents);
    return 0;
}
