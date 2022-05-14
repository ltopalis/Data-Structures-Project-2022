#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "AVL.h"

int main()
{
    node_ptr root;
    table_data x;

    init_avl(&root);

    x.date.tm_hour = 0;
    x.date.tm_mday = 2;
    x.date.tm_mon = 5-1;
    x.date.tm_year = 2014-1970;
    x.date.tm_min = 0;
    x.date.tm_sec = 0;

    x.T_degC = 17.5;

    root_insert(&root, x);

    x.date.tm_hour = 0;
    x.date.tm_mday = 2;
    x.date.tm_mon = 7-1;
    x.date.tm_year = 2011-1970;
    x.date.tm_min = 0;
    x.date.tm_sec = 0;

    x.T_degC = 16.5;

    insert_left(root, x);

    x.date.tm_hour = 0;
    x.date.tm_mday = 2;
    x.date.tm_mon = 1-1;
    x.date.tm_year = 2001-1970;
    x.date.tm_min = 0;
    x.date.tm_sec = 0;

    x.T_degC = 16.0;

    insert_right(root, x);

    

    

    exit(0);

}