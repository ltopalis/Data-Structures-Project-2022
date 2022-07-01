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

/*
   hash_function_hashing(): dosmenou
   mias symvoloseiras date vriskei kai
   epistrefei tin thesei pou tha apothikeytei
   i eggrafi se pinaka hashing
*/
int hash_function_hashing(char *date);
/*
   insert_hashing(): Eisagwgi tis eggrafhs data ston 
   pinaka array sthn thesi key
*/
void insert_hashing(table_data data, int key, DataItem *array[]);
/*
   init_hashing(): Arxikopoiei ola ta kelia
   tou pinaka array se NULL
*/
void init_hashing(DataItem **array);
/*
   insert_from_file_hashing(): Eisagwgi stoixeiwn me
   thn methodo tou hashing ston pinaka array apo to arxeio
   me onoma filename
*/
void insert_from_file_hashing(char *filename, DataItem *array[]);
/*
   search_hashing(): anazitisi tis eggrafis me 
   imerominia date ston pinaka array
*/
DataItem *search_hashing(DataItem **array, struct tm date);
/* 
   searching function used in menu file 
*/
void user_search_hashing(DataItem **array);
/*
   print_hashing(): typwnetai o pinakas t
*/
void print_hashing(DataItem **t);
/*
   temp_change_hashing(): anazitatai kai allazei 
   i timi ths thermokrasias enos komvou tou
   array
*/
void temp_change_hashing(DataItem **array);
/*
   delete_node_hashing(): diagrafi enos
   stoixeiou tou pinaka array me vasi thn
   imerominia
*/
void delete_node_hashing(DataItem **array);

#endif