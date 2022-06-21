#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"
#include "main_functions.h"
#include "menu.h"

int main()
{
    Node *root = NULL;

    clean();
    menu(root);

    exit(0);
}