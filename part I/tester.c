#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "searching.h"
#include "sort_functions.h"

#define UINT_MAX 0xfffe
#define TRUE 1
#define FALSE 0

void clean();
void copy_array(table_data *dest, table_data *source);

int main()
{
    table_data values[DATA];
    table_data values2[DATA];
    table_data values3[DATA];

    struct tm timeinfo;
    clock_t c1, c2;
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
           t_oBIS = 0.0,
           t_inser = 0.0,
           t_heapi = 0.0,
           t_count = 0.0;

    clean();
    fprintf(stderr, "\033[1;31m");

    printf("\033[0;36m");
    printf("Estimated time: 2-5 minutes\n");
    open_file("ocean.csv", values2, NULL);
    copy_array(values3, values2);
    bubble_sort(values3, TABLE_SIZE, TIME);
    printf("\033[0;35m");
    printf("--------------START--------------\n");
    printf("START      FINISH          STATUS\n");
    printf("\033[0m");

    srand(time(NULL));
    for (unsigned int i = 0; i <= UINT_MAX; i++)
    {
        copy_array(values, values2);
        c1 = clock();
        countingsort(values, TABLE_SIZE);
        c2 = clock();
        t_count += ((float)(c2 - c1)) / CLOCKS_PER_SEC;

        copy_array(values, values2);
        c1 = clock();
        HeapSort(values, TABLE_SIZE);
        c2 = clock();
        t_heapi += ((float)(c2 - c1)) / CLOCKS_PER_SEC;

        copy_array(values, values2);
        insertion_sort(values, TABLE_SIZE);
        c2 = clock();
        t_inser += ((float)(c2 - c1)) / CLOCKS_PER_SEC;

        if ((i + 1) % 1500 == 0)
        {
            printf("\033[0;35m");
            printf("%-10d %-10d --->   OK\n", i - 1500 + 1, i);
            printf("\033[0m");
        }
        timeinfo.tm_year = 1998 + rand() % (2022 - 1998) - 1900;
        timeinfo.tm_mon = (1 + rand() % 20) - 1;
        timeinfo.tm_mday = 1 + rand() % 35;
        timeinfo.tm_hour = 0;
        timeinfo.tm_min = 0;
        timeinfo.tm_sec = 0;
        timeinfo.tm_isdst = 0;

        c1 = clock();
        n = binarySearch(values3, 0, DATA - 1, mktime(&timeinfo));
        c2 = clock();
        t_bin += ((float)(c2 - c1)) / CLOCKS_PER_SEC;

        c1 = clock();
        m = interpolation_Search(values3, 0, DATA - 1, mktime(&timeinfo));
        c2 = clock();
        t_inter += ((float)(c2 - c1)) / CLOCKS_PER_SEC;;

        c1 = clock();
        k = binary_interpolation_search(values3, mktime(&timeinfo), DATA);
        c2 = clock();
        t_BIS += ((float)(c2 - c1)) / CLOCKS_PER_SEC;

        c1 = clock();
        l = optimized_binary_interpolation_search(values3, mktime(&timeinfo), DATA);
        c2 = clock();
        t_oBIS += ((float)(c2 - c1)) / CLOCKS_PER_SEC;

        if (n != m || k != l || n != k)
        {
            if (n == -1 && m != -1 && k != -1 && l != -1)
            {
                if ((difftime(mktime(&values[m].date), mktime(&values[k].date)) == 0.0 &&
                     difftime(mktime(&values[l].date), mktime(&values[k].date)) == 0.0))
                {
                    fprintf(stderr, "DATE: %d/%d/%d\n", timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_year + 1900);
                    fprintf(stderr, "====================================\n");
                    fprintf(stderr, "ALGORITHM            POSITION\n");
                    fprintf(stderr, "====================================\n");
                    fprintf(stderr, "binary search       : %d\n", n);
                    fprintf(stderr, "interpolation search: %d\n", m);
                    fprintf(stderr, "BIS                 : %d\n", k);
                    fprintf(stderr, "optimized BIS       : %d\n", l);
                    fprintf(stderr, "\n\n");

                    flag = FALSE;
                }
            }
            else if (n != -1 && m == -1 && k != -1 && l != -1)
            {
                if ((difftime(mktime(&values[n].date), mktime(&values[k].date)) == 0.0 &&
                     difftime(mktime(&values[l].date), mktime(&values[k].date)) == 0.0))
                {

                    fprintf(stderr, "DATE: %d/%d/%d\n", timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_year + 1900);
                    fprintf(stderr, "====================================\n");
                    fprintf(stderr, "ALGORITHM            POSITION\n");
                    fprintf(stderr, "====================================\n");
                    fprintf(stderr, "binary search       : %d\n", n);
                    fprintf(stderr, "interpolation search: %d\n", m);
                    fprintf(stderr, "BIS                 : %d\n", k);
                    fprintf(stderr, "optimized BIS       : %d\n", l);
                    fprintf(stderr, "\n\n");

                    flag = FALSE;
                }
            }
            else if (n != -1 && m != -1 && k == -1 && l != -1)
            {
                if ((difftime(mktime(&values[m].date), mktime(&values[n].date)) == 0.0 &&
                     difftime(mktime(&values[l].date), mktime(&values[n].date)) == 0.0))
                {

                    fprintf(stderr, "DATE: %d/%d/%d\n", timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_year + 1900);
                    fprintf(stderr, "====================================\n");
                    fprintf(stderr, "ALGORITHM            POSITION\n");
                    fprintf(stderr, "====================================\n");
                    fprintf(stderr, "binary search       : %d\n", n);
                    fprintf(stderr, "interpolation search: %d\n", m);
                    fprintf(stderr, "BIS                 : %d\n", k);
                    fprintf(stderr, "optimized BIS       : %d\n", l);
                    fprintf(stderr, "\n\n");

                    flag = FALSE;
                }
            }
            else if (n != -1 && m != -1 && k != -1 && l == -1)
            {
                if ((difftime(mktime(&values[m].date), mktime(&values[k].date)) == 0.0 &&
                     difftime(mktime(&values[n].date), mktime(&values[k].date)) == 0.0))
                {

                    fprintf(stderr, "DATE: %d/%d/%d\n", timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_year + 1900);
                    fprintf(stderr, "====================================\n");
                    fprintf(stderr, "ALGORITHM            POSITION\n");
                    fprintf(stderr, "====================================\n");
                    fprintf(stderr, "binary search       : %d\n", n);
                    fprintf(stderr, "interpolation search: %d\n", m);
                    fprintf(stderr, "BIS                 : %d\n", k);
                    fprintf(stderr, "optimized BIS       : %d\n\n", l);
                    fprintf(stderr, "\n\n");

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

    if (flag)
    {
        printf("\033[1;32m");
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PASS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("\033[0m");
    }
    else
    {
        printf("\033[1;31m");
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FAIL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("\033[0m");
    }
    printf("\033[1;32m");
    printf("Amount of tests %u\n", (bin_fail + bin_suc));
    printf("==============================================================================\n");
    printf("ALGORITHM                 TIME          FOUND      NOT FOUND      SUCCESS RATE\n");
    printf("==============================================================================\n");
    printf("Insertion Sort      : %.10lf\n", t_inser / (bin_suc + bin_fail));
    printf("HeapSort            : %.10lf\n", t_heapi / (bin_suc + bin_fail));
    printf("Counting Sort       : %.10lf\n", t_count / (bin_suc + bin_fail));
    printf("------------------------------------------------------------------------------\n");
    printf("binary search       : %.10lf\t%-10d\t%-10d  %f\n", t_bin / (bin_suc + bin_fail), bin_suc, bin_fail, bin_suc / (float)(bin_suc + bin_fail));
    printf("interpolation search: %.10lf\t%-10d\t%-10d  %f\n", t_inter / (inter_suc + inter_fail), inter_suc, inter_fail, inter_suc / (float)(inter_suc + inter_fail));
    printf("BIS                 : %.10lf\t%-10d\t%-10d  %f\n", t_BIS / (BIS_suc + BIS_fail), BIS_suc, BIS_fail, BIS_suc / (float)(BIS_suc + BIS_fail));
    printf("optimized BIS       : %.10lf\t%-10d\t%-10d  %f\n", t_oBIS / (oBIS_suc + oBIS_fail), oBIS_suc, oBIS_fail, oBIS_suc / (float)(oBIS_suc + oBIS_fail));
    printf("\033[0m");

    fprintf(stderr, "\033[0m");
    printf("\a");

    exit(0);
}

void clean()
{
    int check;

#ifdef _WIN32
    check = system("cls");
#elif __unix__
    check = system("clear");
#elif __APPLE__
    check = system("clear");
#endif

    if (check == -1)
        fprintf(stderr, "error cleaning console!\n");
}

void copy_array(table_data *dest, table_data *source){
    for(int i=0; i<TABLE_SIZE; i++){
        dest[i].date.tm_hour = source[i].date.tm_hour;
        dest[i].date.tm_min = source[i].date.tm_min;
        dest[i].date.tm_sec = source[i].date.tm_sec;
        dest[i].date.tm_isdst = source[i].date.tm_isdst;
        dest[i].date.tm_mday = source[i].date.tm_mday;
        dest[i].date.tm_mon = source[i].date.tm_mon;
        dest[i].date.tm_year = source[i].date.tm_year;
        dest[i].NO2uM = source[i].NO2uM;
        dest[i].NO3uM = source[i].NO3uM;
        dest[i].O2ml_L = source[i].O2ml_L;
        dest[i].PO4uM = source[i].PO4uM;
        dest[i].Salnty = source[i].Salnty;
        dest[i].SiO3uM = source[i].SiO3uM;
        dest[i].T_degC = source[i].T_degC;
    }
}
