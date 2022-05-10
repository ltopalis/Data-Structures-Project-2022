#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fundamentals.h"

int swap(void *a, void *b, DATA_TYPE t)
{
    void *temp = NULL;

    switch (t)
    {
    case INT:
        temp = malloc(sizeof(int));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(int *)temp = *(int *)a;
        *(int *)a = *(int *)b;
        *(int *)b = *(int *)temp;
        break;
    case DOUBLE:
        temp = malloc(sizeof(double));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(double *)temp = *(double *)a;
        *(double *)a = *(double *)b;
        *(double *)b = *(double *)temp;
        break;
    case FLOAT:
        temp = malloc(sizeof(float));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(float *)temp = *(float *)a;
        *(float *)a = *(float *)b;
        *(float *)b = *(float *)temp;
        break;
    case CHAR:
        temp = malloc(sizeof(char));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(char *)temp = *(char *)a;
        *(char *)a = *(char *)b;
        *(char *)b = *(char *)temp;
        break;
    case SHORT_INT:
        temp = malloc(sizeof(short int));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(short int *)temp = *(short int *)a;
        *(short int *)a = *(short int *)b;
        *(short int *)b = *(short int *)temp;
        break;
    case LONG_INT:
        temp = malloc(sizeof(long int));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(long int *)temp = *(long int *)a;
        *(long int *)a = *(long int *)b;
        *(long int *)b = *(long int *)temp;
        break;
    case LONG_LONG_INT:
        temp = malloc(sizeof(long long int));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(long long int *)temp = *(long long int *)a;
        *(long long int *)a = *(long long int *)b;
        *(long long int *)b = *(long long int *)temp;
        break;
    case LONG_DOUBLE:
        temp = malloc(sizeof(long double));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(long double *)temp = *(long double *)a;
        *(long double *)a = *(long double *)b;
        *(long double *)b = *(long double *)temp;
        break;
    case UNSIGNED_CHAR:
        temp = malloc(sizeof(unsigned char));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(unsigned char *)temp = *(unsigned char *)a;
        *(unsigned char *)a = *(unsigned char *)b;
        *(unsigned char *)b = *(unsigned char *)temp;
        break;
    case UNSIGNED_SHORT_INT:
        temp = malloc(sizeof(unsigned short int));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(unsigned short int *)temp = *(unsigned short int *)a;
        *(unsigned short int *)a = *(unsigned short int *)b;
        *(unsigned short int *)b = *(unsigned short int *)temp;
        break;
    case UNSIGNED_INT:
        temp = malloc(sizeof(unsigned int));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(unsigned int *)temp = *(unsigned int *)a;
        *(unsigned int *)a = *(unsigned int *)b;
        *(unsigned int *)b = *(unsigned int *)temp;
        break;
    case UNSIGNED_LONG_LONG_INT:
        temp = malloc(sizeof(unsigned long long int));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(unsigned long long int *)temp = *(unsigned long long int *)a;
        *(unsigned long long int *)a = *(unsigned long long int *)b;
        *(unsigned long long int *)b = *(unsigned long long int *)temp;
        break;
    case STRING:
        temp = malloc(sizeof(char) * strlen((char *)a));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        strcpy((char *)temp, (char *)a);
        a = realloc((char *)a, sizeof(char) * strlen((char *)b));
        if (!a)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        strcpy((char *)a, (char *)b);
        b = realloc((char *)b, sizeof(char) * strlen((char *)temp));
        if (!a)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        strcpy((char *)b, (char *)temp);
        break;
    case TABLE_DATA:
        temp = malloc(sizeof(table_data));
        if (!temp)
        {
            fprintf(stderr, "Error Allocating memory!");
            return FALSE;
        }
        *(table_data *)temp = *(table_data *)a;
        *(table_data *)a = *(table_data *)b;
        *(table_data *)b = *(table_data *)temp;
        break;
    default:
        fprintf(stderr, "invalid data type");
    }

    free(temp);

    return TRUE;
}

int check_allocation(void *p)
{
    if (!p)
    {
        fprintf(stderr, "Error allocating memory!");
        return FALSE;
    }

    return TRUE;
}

void print_array(table_data *array, int n)
{
    int i;
    char *time_str = (char *)malloc(sizeof(char) * 11);

    for (i = 0; i < n; i++)
    {
        strftime(time_str, 11, "%m/%d/%Y", &array[i].date);
        printf("\n%s  ", time_str);
        printf("%6.3lf  ", array[i].T_degC);
        printf("%6.3lf  ", array[i].PO4uM);
        printf("%6.3lf  ", array[i].SiO3uM);
        printf("%6.3lf  ", array[i].NO2uM);
        printf("%6.3lf  ", array[i].NO3uM);
        printf("%6.3lf  ", array[i].Salnty);
        printf("%6.3lf  ", array[i].O2ml_L);
    }
    printf("\n");
    free(time_str);
}

void printArray(table_data array[], int n)
{
    char *time_str = (char *)malloc(sizeof(char) * 11);

    for (int i = 0; i < n; i++)
    {
        strftime(time_str, 11, "%m/%d/%Y", &array[i].date);
        printf("%d) %s\t%.3f", (i + 1), time_str, array[i].PO4uM);
        printf("\n");
    }

    free(time_str);
}
