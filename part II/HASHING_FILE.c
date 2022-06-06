#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define size 1405
#define LINE_SIZE 1405
#define FALSE 0
#define buckets 11

struct table_data
{
    struct tm date;
    double T_degC;
};

struct DataItem
{
    struct table_data data;
    struct DataItem *next;
};

typedef struct table_data table_data;
typedef struct DataItem DataItem;

int hash_function(char *date);
void insert(table_data data, int key, DataItem *array[]);
void init(DataItem **array);

int main()
{
    DataItem *array[10];
    table_data t;

    init(array);

    printf("%d\n", hash_function("10/05/2014"));
    insert(t, hash_function("10/05/2014"), array);

    exit(0);
}

int hash_function(char *date)
{
    int i, sum;

    sum = 0;
    for (i = 0; i < (int)strlen(date); i++)
        sum += (int)date[i];

    return (sum % buckets);
}

void insert(table_data data, int key, DataItem *array[])
{
    DataItem *newNode = (DataItem *)malloc(sizeof(DataItem));
    DataItem *current = (DataItem *)malloc(sizeof(DataItem));
    if (!newNode)
    {
        fprintf(stderr, "Error allocating memory!\n");
        return;
    }
    if (!current)
    {
        fprintf(stderr, "Error allocating memory!\n");
        return;
    }

    if (array[key] == NULL)
    {
        array[key] = (DataItem *)malloc(sizeof(DataItem));
        if (!array[key])
        {
            fprintf(stderr, "Error allocating memory!\n");
            return;
        }
        array[key]->data.date.tm_mon = data.date.tm_mon;
        array[key]->data.date.tm_mday = data.date.tm_mday;
        array[key]->data.date.tm_year = data.date.tm_year;
        array[key]->data.date.tm_hour = data.date.tm_hour;
        array[key]->data.date.tm_min = data.date.tm_min;
        array[key]->data.date.tm_sec = data.date.tm_sec;
        array[key]->data.date.tm_isdst = data.date.tm_isdst;
        array[key]->data.T_degC = data.T_degC;
        array[key]->next = NULL;
    }
    else
    {
        current = array[key];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = (DataItem *)malloc(sizeof(DataItem));
        if (!current->next)
        {
            fprintf(stderr, "Error allocating memory!\n");
            return;
        }
        current->next->data.date.tm_mon = data.date.tm_mon;
        current->next->data.date.tm_mday = data.date.tm_mday;
        current->next->data.date.tm_year = data.date.tm_year;
        current->next->data.date.tm_hour = data.date.tm_hour;
        current->next->data.date.tm_min = data.date.tm_min;
        current->next->data.date.tm_sec = data.date.tm_sec;
        current->next->data.date.tm_isdst = data.date.tm_isdst;
        current->next->data.T_degC = data.T_degC;
        current->next->next = NULL;
    }
}

void init(DataItem **array){
    int i;

    for(i=0; i<buckets - 1; i++)
        array[i] = NULL;
}