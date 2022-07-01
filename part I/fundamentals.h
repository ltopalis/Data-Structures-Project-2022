#ifndef FUNDAMENTALS_H

#include <time.h>

#define FUNDAMENTALS_H
#define TRUE 1
#define FALSE 0

enum DATA_TYPE
{
    INT,
    DOUBLE,
    FLOAT,
    CHAR,
    SHORT_INT,
    LONG_INT,
    LONG_LONG_INT,
    LONG_DOUBLE,
    UNSIGNED_CHAR,
    UNSIGNED_SHORT_INT,
    UNSIGNED_INT,
    UNSIGNED_LONG_LONG_INT,
    STRING,
    TABLE_DATA
};

enum FIELD
{
    TIME,
    TEMPERATURE,
    PHOSPHATE
};

struct table_data
{
    struct tm date;
    double T_degC;
    double PO4uM;
    double SiO3uM;
    double NO2uM;
    double NO3uM;
    double Salnty;
    double O2ml_L;
};

typedef enum DATA_TYPE DATA_TYPE;
typedef enum FIELD FIELD;
typedef struct table_data table_data;

/* 
   swap(): enalagi metaksi dyo metavlitwn. Oi 
   metavlites mporei na einai typou DATA_TYPE
*/
int swap(void *a, void *b, DATA_TYPE t);
/* 
   check_allocation(): Elegxei an egine swsta i
   desmeysi mnimis kai epistrefei TRUE, alliws FALSE 
*/
int check_allocation(void *p);
/* 
   print_array(): Ektypwnei ola ta periexomena tou pinaka 
*/
void print_array(table_data *array, int n);
/* 
   printArray(): Ektypwnei ta periexomena tou pinaka
   mono tis metavlites imerominia kai fwsforo
*/
void printArray(table_data array[], int n);

#endif