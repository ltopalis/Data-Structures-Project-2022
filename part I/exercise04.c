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
    int k, m, choice, flag;
    table_data *ocean = (table_data *)malloc(sizeof(table_data) * DATA);
    char *contents = (char *)malloc(sizeof(char) * LINE_SIZE);
    struct tm t;
    clock_t c1, c2, c3, c4;

    if (!open_file("ocean.csv", ocean, contents))
    {
        fprintf(stderr, "Error reading file!");
        exit(0);
    }

    bubble_sort(ocean, DATA, TIME);
    // print_array(ocean, DATA);

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

    t.tm_mon -= 1;
    t.tm_year -= 1900;
    t.tm_sec = 0;  /* seconds,  range 0 to 59          */
    t.tm_min = 0;  /* minutes, range 0 to 59           */
    t.tm_hour = 0; /* hours, range 0 to 23             */
    t.tm_wday = 0; /* day of the week, range 0 to 6    */
    t.tm_yday = 0; /* day in the year, range 0 to 365  */
    t.tm_isdst = -1;

    c1 = clock();
    k = binary_interpolation_search(ocean, mktime(&t), DATA);
    c2 = clock();

    c3 = clock();
    m = optimized_binary_interpolation_search(ocean, mktime(&t), DATA);
    c4 = clock();

    printf("====================\n");
    printf("1. Temperature\n");
    printf("2. Phosphate\n");
    printf("3. Both\n");
    do
    {
        printf("Choice? ");
        flag = scanf("%d", &choice);
        flag = choice < 1 || choice > 3;
        if (flag)
            fprintf(stderr, "ERROR! Should be between 1 and 3!\n");

    } while (flag);
    printf("====================\n");

    if (k == m)
    {
        if (k != -1)
        {
            switch (choice)
            {
            case 1:
                printf("%d/%d/%d\tTemperature: %.3f\n", ocean[k].date.tm_mon + 1,
                       ocean[k].date.tm_mday, ocean[k].date.tm_year + 1900, ocean[k].T_degC);
                break;
            case 2:
                printf("%d/%d/%d\tPhospate: %.3f\n", ocean[k].date.tm_mon + 1,
                       ocean[k].date.tm_mday, ocean[k].date.tm_year + 1900, ocean[k].PO4uM);
                break;
            case 3:
                printf("%d/%d/%d\tTemperature:%.3f\tPhospahte: %.3f\n", ocean[k].date.tm_mon + 1,
                       ocean[k].date.tm_mday, ocean[k].date.tm_year + 1900, ocean[k].T_degC, ocean[k].PO4uM);
                break;
            default:
                fprintf(stderr, "An unexpected error occured! Try again, please!\n");
                break;
            }
        }
        else
            printf("There're no records!\n");

        printf("====================\n");
        printf("Binary Interpolation Search           %f sec\n", (float)(c2 - c1) / CLOCKS_PER_SEC);
        printf("Optimized Binary Interpolation Search %f sec\n", (float)(c4 - c3) / CLOCKS_PER_SEC);
    }
    else
        fprintf(stderr, "An unexpected error occured! Try again, please!\n");

    free(ocean);
    free(contents);

    exit(0);
}
