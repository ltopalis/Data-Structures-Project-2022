#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct.h"
#include "AVL.h"
#include "hashing.h"
#include "main_functions.h"
#include "avl_by_temp.h"
#include "menu.h"

void clean()
{
    int check;

#ifdef _WIN32
    check = system("cls");
#elif __unix__
    check = system("clear");
#elif __APPLE__
    check = system("clear");
#endif

    if (check == -1)
        fprintf(stderr, "error cleaning console!\n");
}

void menu(Node *root, Node_T *root_T, DataItem **array)
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
            check = scanf("%d", &choice);
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
            AVL(root, root_T);
            break;
        case 2:
            hashing(array);
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

void AVL(Node *root, Node_T *root_T)
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
            check = scanf("%d", &choice);
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
            root = insert_from_file("ocean.csv", root);
            avl_by_date(root);
            root = delete_AVL(root);

            break;
        case 2:
            avl_by_temp(root_T);
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
            check = scanf("%d", &choice);
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
            delete (root);
            break;
        case 5:
            return;
        default:
            break;
        }

        print_equal(44);
        printf("\nPress enter to continue...\n");
        fflush(stdin);
        getc(stdin);
        getc(stdin);
        clean();
    }
}

void hashing(DataItem **array)
{
    int choice, check;

    init_hashing(array);
    insert_from_file_hashing("ocean.csv", array);

    while (TRUE)
    {
        do
        {
            print_equal(20);
            printf("1. searching given a date\n");
            printf("2. change temperature\n");
            printf("3. delete given a date\n");
            printf("4. back\n");
            printf("choice? ");
            check = scanf("%d", &choice);
            check = (choice > 0 && choice < 5);
            if (!check)
            {
                clean();
                fprintf(stderr, "Should be between 1 and 4\n");
                print_equal(25);
            }
        } while (!check);
        clean();

        switch (choice)
        {
        case 1:
            user_search_hashing(array);
            break;
        case 2:
            temp_change_hashing(array);
            break;
        case 3:
            delete_node_hashing(array);
            break;
        case 4:
            return;
        default:
            break;
        }

        print_equal(44);
        printf("\nPress enter to continue...\n");
        fflush(stdin);
        getc(stdin);
        getc(stdin);
        clean();
    }
}

void avl_by_temp(Node_T *root)
{
    int choice, check;
    while (TRUE)
    {
        do
        {
            print_equal(20);
            printf("1. print AVL\n");
            printf("2. print the coldest dates\n");
            printf("3. print the hottest dates\n");
            printf("4. back\n");
            printf("choice? ");
            check = scanf("%d", &choice);
            check = (choice > 0 && choice < 5);
            if (!check)
            {
                clean();
                fprintf(stderr, "Should be between 1 and 4\n");
                print_equal(25);
            }
        } while (!check);
        clean();

        switch (choice)
        {
        case 1:
            printAVLD(root);
            break;
        case 2:
            printMin(root);
            break;
        case 3:
            printMax(root);
            break;
        case 4:
            return;
        default:
            break;
        }

        print_equal(44);
        printf("\nPress enter to continue...\n");
        fflush(stdin);
        getc(stdin);
        getc(stdin);
        clean();
    }
}