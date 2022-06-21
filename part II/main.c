#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include "AVL.h"
#include "hashing.h"
#include "main_functions.h"
#include "menu.h"

int main()
{
    Node *root = NULL;
    DataItem *array[buckets];

    clean();
    menu(root, array);

    exit(0);
}