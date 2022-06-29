#ifndef STRUCT_H

#define STRUCT_H

#define TRUE 1
#define FALSE 0
#define LINE_SIZE 100

struct table_data
{
    struct tm date;
    double T_degC;
};

void print_equal(int number);
int check_allocation(void *p);
int max(int a, int b);

#endif