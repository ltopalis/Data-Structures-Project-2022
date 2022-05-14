#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "searching.h"
#include "sort_functions.h"

#define UINT_MAX 0xfffff
#define TRUE 1
#define FALSE 0

int main()
{
    table_data values[DATA];
    char contents[LINE_SIZE];
    struct tm timeinfo;
    int flag = TRUE,
        bin_suc = 0,
        bin_fail = 0,
        inter_suc = 0,
        inter_fail = 0,
        BIS_suc = 0,
        BIS_fail = 0,
        oBIS_suc = 0,
        oBIS_fail = 0, n, k, l, m;
    double t_inter = 0.0,
           t_bin = 0.0,
           t_BIS = 0.0,
           t_oBIS = 0.0;

    open_file("ocean.csv", values, contents);

    bubble_sort(values, DATA, TIME);
    printf("\033[0;35m");
    printf("--------------START--------------\n");
    printf("START      FINISH          STATUS\n");
    printf("\033[0m");

    for (unsigned int i = 0; i <= UINT_MAX; i++)
    {
        if ((i + 1) % 100000 == 0)
        {
            printf("\033[0;35m");
            printf("%-10d %-10d --->   OK\n", i - 99999, i);
            printf("\033[0m");
        }
        srand(time(NULL));
        timeinfo.tm_year = rand() % 2022 - 1900;
        timeinfo.tm_mon = (1 + rand() % 20) - 1;
        timeinfo.tm_mday = 1 + rand() % 35;
        timeinfo.tm_hour = 0;
        timeinfo.tm_min = 0;
        timeinfo.tm_sec = 0;

        clock_t c1 = clock();
        n = binarySearch(values, 0, DATA - 1, mktime(&timeinfo));
        clock_t c2 = clock();
        t_bin += ((float)(c2 - c1)) / CLOCKS_PER_SEC;

        clock_t c3 = clock();
        m = interpolationSearch(values, 0, DATA - 1, mktime(&timeinfo));
        clock_t c4 = clock();
        t_inter += ((float)(c4 - c3)) / CLOCKS_PER_SEC;

        clock_t c5 = clock();
        k = binary_interpolation_search(values, mktime(&timeinfo), DATA);
        clock_t c6 = clock();
        t_BIS += ((float)(c6 - c5)) / CLOCKS_PER_SEC;

        clock_t c7 = clock();
        l = optimized_binary_interpolation_search(values, mktime(&timeinfo), DATA);
        clock_t c8 = clock();
        t_oBIS += ((float)(c8 - c7)) / CLOCKS_PER_SEC;

        printf("%d %d %d\n", timeinfo.tm_mday , timeinfo.tm_mon +1 , timeinfo.tm_year + 1900);
        printf("%d %d %d %d\n", k , l , m ,n);

        if (n != m || k != l || n != k)
        {
            printf("Ok\n");
            if (n == -1 && m != -1 && k != -1 && l != -1)
            {
                if (!(difftime(mktime(&values[m].date), mktime(&values[k].date)) == 0.0 &&
                      difftime(mktime(&values[l].date), mktime(&values[k].date)) == 0.0))
                {
                    printf("\033[1;31m");
                    printf("DATE: %d/%d/%d\n", timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_year + 1900);
                    printf("====================================\n");
                    printf("ALGORITHM            POSITION\n");
                    printf("====================================\n");
                    printf("binary search       : %d\n", n);
                    printf("interpolation search: %d\n", m);
                    printf("BIS                 : %d\n", k);
                    printf("optimized BIS       : %d\n", l);
                    printf("\033[0m");
                    flag = FALSE;
                }
            }
            else if (n != -1 && m == -1 && k != -1 && l != -1)
            {
                if (!(difftime(mktime(&values[n].date), mktime(&values[k].date)) == 0.0 &&
                      difftime(mktime(&values[l].date), mktime(&values[k].date)) == 0.0))
                {
                    printf("\033[1;31m");
                    printf("DATE: %d/%d/%d\n", timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_year + 1900);
                    printf("====================================\n");
                    printf("ALGORITHM            POSITION\n");
                    printf("====================================\n");
                    printf("binary search       : %d\n", n);
                    printf("interpolation search: %d\n", m);
                    printf("BIS                 : %d\n", k);
                    printf("optimized BIS       : %d\n", l);
                    printf("\033[0m");
                    flag = FALSE;
                }
            }
            else if (n != -1 && m != -1 && k == -1 && l != -1)
            {
                if (!(difftime(mktime(&values[m].date), mktime(&values[n].date)) == 0.0 &&
                      difftime(mktime(&values[l].date), mktime(&values[n].date)) == 0.0))
                {
                    printf("\033[1;31m");
                    printf("DATE: %d/%d/%d\n", timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_year + 1900);
                    printf("====================================\n");
                    printf("ALGORITHM            POSITION\n");
                    printf("====================================\n");
                    printf("binary search       : %d\n", n);
                    printf("interpolation search: %d\n", m);
                    printf("BIS                 : %d\n", k);
                    printf("optimized BIS       : %d\n", l);
                    printf("\033[0m");
                    flag = FALSE;
                }
            }
            else if (n != -1 && m != -1 && k != -1 && l == -1)
            {
                if (!(difftime(mktime(&values[m].date), mktime(&values[k].date)) == 0.0 &&
                      difftime(mktime(&values[n].date), mktime(&values[k].date)) == 0.0))
                {
                    printf("\033[1;31m");
                    printf("DATE: %d/%d/%d\n", timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_year + 1900);
                    printf("====================================\n");
                    printf("ALGORITHM            POSITION\n");
                    printf("====================================\n");
                    printf("binary search       : %d\n", n);
                    printf("interpolation search: %d\n", m);
                    printf("BIS                 : %d\n", k);
                    printf("optimized BIS       : %d\n", l);
                    printf("\033[0m");
                    flag = FALSE;
                }
            }
        }

        if (k == -1)
            BIS_fail += 1;
        else
            BIS_suc += 1;

        if (m == -1)
            inter_fail += 1;
        else
            inter_suc += 1;

        if (n == -1)
            bin_fail += 1;
        else
            bin_suc += 1;

        if (l == -1)
            oBIS_fail += 1;
        else
            oBIS_suc += 1;
    }
    printf("\033[0;35m");
    printf("--------------FINISH-------------\n");
    printf("\033[0m");

    printf("\033[1;32m");
    if (flag)
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PASS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("==================================================================\n");
    printf("ALGORITHM                 TIME          SUCCESS         FAIL      \n");
    printf("==================================================================\n");
    printf("binary search       : %.10lf\t%-10d\t%-10d\n", t_bin / (bin_suc + bin_fail), bin_suc, bin_fail);
    printf("interpolation search: %.10lf\t%-10d\t%-10d\n", t_inter / (inter_suc + inter_fail), inter_suc, inter_fail);
    printf("BIS                 : %.10lf\t%-10d\t%-10d\n", t_BIS / (BIS_suc + BIS_fail), BIS_suc, BIS_fail);
    printf("optimized BIS       : %.10lf\t%-10d\t%-10d\n", t_oBIS / (oBIS_suc + oBIS_fail), oBIS_suc, oBIS_fail);
    printf("\033[0m");

    return 0;
}
