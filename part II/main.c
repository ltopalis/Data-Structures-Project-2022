#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"
#include "main_functions.h"
#include "menu.h"

int main()
{
    Node *root = NULL;

    root = insert_from_file("ocean.csv", root);

    menu(root);

    exit(0);
}