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

/* 
   print_equal(): Typonontai "=" plithous 
   number
*/
void print_equal(int number);
/* 
   check_allocation(): Elegxei an egine swsta i
   desmeysi mnimis kai epistrefei TRUE, alliws FALSE 
*/
int check_allocation(void *p);
/*
   max(): epistrefetai i timi toy 
   megalyterou arithmou apo tous a
   kai b
*/
int max(int a, int b);

#endif