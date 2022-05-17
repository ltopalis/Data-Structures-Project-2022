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

    while (TRUE)
    {
        do
        {

            printf("1. AVL\n");
            printf("2. Hashing\n");
            printf("3. exit\n");
            printf("choice? ");
            scanf("%d", &choice);
            check = (choice > 0 && choice < 4);
            if (!check)
            {
                system("clear");
                fprintf(stderr, "Should be between 1 and 3\n");
                print_equal(25);
            }
        } while (!check);
        system("clear");

        switch (choice)
        {
        case 1: // AVL
            break;
        case 2: // Hashing
            break;
        case 3: // exit
            printf("Bye Bye\n");
            exit(0);
        default:
            fprintf(stderr, "Error\n");
            break;
        }
    }
}