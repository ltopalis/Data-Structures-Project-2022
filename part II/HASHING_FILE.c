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
void insert_from_file(char *filename, DataItem *array[]);
DataItem *search(DataItem **array, struct tm date);
void print(DataItem **t);
void temp_change(DataItem **array);

int main()
{
    DataItem *array[buckets];
    struct tm mday;

    init(array);

    insert_from_file("ocean.csv", array);
    temp_change(array);

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

    if (key >= buckets)
        printf("An error occured!");

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

void init(DataItem **array)
{
    int i;

    for (i = 0; i < buckets; i++)
        array[i] = NULL;
}

void insert_from_file(char *filename, DataItem *array[])
{
    FILE *fp = NULL;
    char *pinakas = NULL;
    char date_str[11];
    table_data data;

    pinakas = (char *)malloc(sizeof(char) * LINE_SIZE);
    if (!pinakas)
    {
        fprintf(stderr, "Error allocating memory!");
        return;
    }

    fp = fopen(filename, "r");
    if (!fp)
    {
        fprintf(stderr, "Error opening file!");
        return;
    }

    strncpy(date_str, fgets(pinakas, LINE_SIZE - 1, fp), 10); // reading the contents
    while (fgets(pinakas, LINE_SIZE - 1, fp) != NULL)
    {
        strcpy(date_str, strtok(pinakas, ","));
        data.T_degC = atof(strtok(NULL, ","));
        data.date.tm_mon = atoi(strtok(date_str, "/")) - 1;
        data.date.tm_mday = atoi(strtok(NULL, "/"));
        data.date.tm_year = atoi(strtok(NULL, "/")) - 1900;
        data.date.tm_hour = 0;
        data.date.tm_min = 0;
        data.date.tm_sec = 0;
        data.date.tm_isdst = 0;
        insert(data, hash_function(date_str), array);
    }

    fclose(fp);
    free(pinakas);
}

DataItem *search(DataItem **array, struct tm date)
{
    char strdate[11] = {'0'};
    DataItem *node = (DataItem *)malloc(sizeof(DataItem));
    if (!node)
    {
        fprintf(stderr, "Error Allocating Memory!");
        return NULL;
    }

    strftime(strdate, 11, "%m/%d/%Y", &date);
    node = array[hash_function(strdate)];

    while (node != NULL)
    {
        if (difftime(mktime(&(node->data.date)), mktime(&date) == 0.0))
        {
            free(node);
            return node;
        }

        node = node->next;
    }

    free(node);
    return NULL;
}

void print(DataItem **t)
{
    int i;
    char d[11];
    DataItem *k = (DataItem *)malloc(sizeof(DataItem));

    for (i = 0; i < 11; i++)
    {
        printf("\n\n%02d:\n", i);
        k = t[i];

        while (k != NULL)
        {
            strftime(d, 11, "%m/%d/%Y", &k->data.date);
            printf("\t%s %02.2lf\n", d, k->data.T_degC);
            k = k->next;
        }
    }
    printf("\n");

    free(k);
}

void temp_change(DataItem **array)
{
    int d, m, y, choice;
    struct tm Date = {0};
    char date[11];
    double temp;
    DataItem *node;

    printf("Give the date, whose temperature you want to change\n");
    do
    {
        printf("Month: ");
        choice = scanf("%d", &m);
    } while (!(m > 0 && m < 13));
    do
    {
        printf("Day: ");
        choice = scanf("%d", &d);
    } while (!(d > 0 && d < 32));
    do
    {
        printf("Year: ");
        choice = scanf("%d", &y);
    } while (!(y > 0));

    Date.tm_mday = d;
    Date.tm_mon = m - 1;
    Date.tm_year = y - 1900;

    strftime(date, 11, "%m/%d/%Y", &Date);
    node = search(array, Date);

    if (node == NULL)
    {
        printf("There's no such date\n");
        return;
    }

    printf("Give the new temperature: ");
    choice = scanf("%lf", &temp);

    printf("Are you sure change the temperature from %lf to %lf?(1 = yes or 2 = no) ", node->data.T_degC, temp);
    do
    {
        d = scanf("%d", &choice);
    } while (!(choice == 1 || choice == 2));

    if(choice == 1)
    {
        node->data.T_degC = temp;
        printf("The temperature has been successfully updated!\n");
    }

    return;
}