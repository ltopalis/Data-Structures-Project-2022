#ifndef HASHING_H

#define HASHING_H

#define size 1405
#define FALSE 0
#define buckets 11

struct DataItem
{
    struct table_data data;
    struct DataItem *next;
    struct DataItem *prev;
};

typedef struct table_data table_data;
typedef struct DataItem DataItem;

int hash_function_hashing(char *date);
void insert_hashing(table_data data, int key, DataItem *array[]);
void init_hashing(DataItem **array);
void insert_from_file_hashing(char *filename, DataItem *array[]);
DataItem *search_hashing(DataItem **array, struct tm date);
/* searching function used in menu file */
void user_search_hashing(DataItem **array);
void print_hashing(DataItem **t);
void temp_change_hashing(DataItem **array);
void delete_node_hashing(DataItem **array);

#endif