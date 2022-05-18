#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "AVL.h"
#include "main_functions.h"
#include "menu.h"

void clean()
{

#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#elif __APPLE__
    system("clear");
#endif
}

void menu(Node *root)
{
    int choice, check;
    while (TRUE)
    {
        do
        {

            printf("1. AVL\n");
            printf("2. Hashing\n");
            printf("3. Exit\n");
            printf("choice? ");
            scanf("%d", &choice);
            check = (choice > 0 && choice < 4);
            if (!check)
            {
                clean();
                fprintf(stderr, "Should be between 1 and 3\n");
                print_equal(25);
            }
        } while (!check);
        clean();

        switch (choice)
        {
        case 1:
            AVL(root);
            break;
        case 2:
            printf("Under construction\n");
            break;
        case 3:
            printf("Bye bye\n");
            exit(0);
        default:
            fprintf(stderr, "Error\n");
            exit(0);
        }
    }
}

void AVL(Node *root)
{
    int choice, check;
    while (TRUE)
    {
        do
        {

            printf("1. by date\n");
            printf("2. by temperature\n");
            printf("3. back\n");
            printf("choice? ");
            scanf("%d", &choice);
            check = (choice > 0 && choice < 4);
            if (!check)
            {
                clean();
                fprintf(stderr, "Should be between 1 and 6\n");
                print_equal(25);
            }
        } while (!check);
        clean();

        switch (choice)
        {
        case 1:
            avl_by_date(root);
            break;
        case 2:
            printf("Under Construction\n");
            break;
        case 3:
            return;
        default:
            fprintf(stderr, "Error\n");
        }
    }
}

void avl_by_date(Node *root)
{
    int choice, check;
    while (TRUE)
    {
        do
        {
            print_equal(20);
            printf("1. print AVL\n");
            printf("2. searching given a date\n");
            printf("3. change temperature\n");
            printf("4. delete given a date\n");
            printf("5. back\n");
            printf("choice? ");
            scanf("%d", &choice);
            check = (choice > 0 && choice < 6);
            if (!check)
            {
                clean();
                fprintf(stderr, "Should be between 1 and 6\n");
                print_equal(25);
            }
        } while (!check);
        clean();

        switch (choice)
        {
        case 1:
            printAVL(root);
            break;
        case 2:
            user_search(root);
            break;
        case 3:
            if (change_temp(root))
                printf("Temperature has been successfully changed!\n");
            break;
        case 4:
            printf("Under construction\n");
            break;
        case 5:
            return;
        default:
            break;
        }

        print_equal(20);
        printf("\nPress enter to continue...\n");
        fflush(stdin);
        getc(stdin);
        getc(stdin);
        clean();
    }
}