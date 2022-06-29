#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include "AVL.h"
#include "avl_by_temp.h"
#include "hashing.h"
#include "main_functions.h"
#include "menu.h"

int main()
{
    Node *root = NULL;
    Node_T *root_T = NULL;
    DataItem *array[buckets];

    root_T = insert_from_file_by_temp("ocean.csv", root_T);

    clean();
    menu(root, root_T, array);

    exit(0);
}