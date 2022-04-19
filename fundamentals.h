#ifndef FUNDAMENTALS_H

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

enum FIELD{
    TIME,
    TEMPERATURE,
    PHOSPHATE
};

struct table_data
{
    struct tm date;
    double temp;
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

int swap(void *a, void *b, DATA_TYPE t);
int check_allocation(void *p);
void print_array(table_data *array, int n);

#endif