#ifndef STRUCT_H

#define STRUCT_H

#define LINE_SIZE 100

struct table_data
{
    struct tm date;
    double T_degC;
};

void print_equal(int number);

#endif