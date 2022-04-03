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
    STRING
};

typedef enum DATA_TYPE DATA_TYPE;

int swap(void *a, void *b, DATA_TYPE t);

#endif