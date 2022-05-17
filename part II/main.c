#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"
#include "main_functions.h"

int main()
{
    Node *root = NULL;
    Node *temp = NULL;
    table_data user_key;
    int choice, check;

    root = insert_from_file("ocean.csv", root);

    
}