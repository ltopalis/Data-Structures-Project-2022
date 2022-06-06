#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "AVL.h"
#include "main_functions.h"

Node *user_insert(Node *root)
{
    table_data user_key;
    int check;

    do
    {
        printf("Give month: ");
        check = scanf("%d", &user_key.date.tm_mon);
        check = !(user_key.date.tm_mon > 0 && user_key.date.tm_mon < 13);
    } while (check);

    do
    {
        printf("Give day: ");
        check = scanf("%d", &user_key.date.tm_mday);
        check = !(user_key.date.tm_mday > 0 && user_key.date.tm_mday < 32);
    } while (check);

    do
    {
        printf("Give year: ");
        check = scanf("%d", &user_key.date.tm_year);
        check = !(user_key.date.tm_year > 0);
    } while (check);

    user_key.date.tm_year -= 1900;
    user_key.date.tm_mon -= 1;
    user_key.date.tm_hour = 0;
    user_key.date.tm_min = 0;
    user_key.date.tm_sec = 0;

    printf("Give the temperature: ");
    check = scanf("%lf", &user_key.T_degC);

    return insert(root, user_key);
}

void user_search(Node *root)
{
    int check;
    table_data user_key;
    Node *searching_node;
    char time_str[11];

    printf("Date to be searched\n");
    do
    {
        printf("Give month: ");
        check = scanf("%d", &user_key.date.tm_mon);
        check = !(user_key.date.tm_mon > 0 && user_key.date.tm_mon < 13);
    } while (check);

    do
    {
        printf("Give day: ");
        check = scanf("%d", &user_key.date.tm_mday);
        check = !(user_key.date.tm_mday > 0 && user_key.date.tm_mday < 32);
    } while (check);

    do
    {
        printf("Give year: ");
        check = scanf("%d", &user_key.date.tm_year);
        check = !(user_key.date.tm_year > 0);
    } while (check);

    user_key.date.tm_year -= 1900;
    user_key.date.tm_mon -= 1;
    user_key.date.tm_hour = 0;
    user_key.date.tm_min = 0;
    user_key.date.tm_sec = 0;

    searching_node = search(root, mktime(&user_key.date));
    print_equal(44);
    if (searching_node == NULL)
    {
        printf("There's no record!\n");
        return;
    }
    strftime(time_str, 11, "%m/%d/%Y", &searching_node->key.date);
    printf("Date: %s\tTemperature: %.4lf\n", time_str, searching_node->key.T_degC);
}

int change_temp(Node *root)
{
    table_data user_key;
    Node *searching_node;
    int check;
    double new_temp;
    char choice[2];
    char *time_str = (char *)malloc(sizeof(char) * 11);
    if (!check_allocation(time_str))
    {
        fprintf(stderr, "Error\n");
        return FALSE;
    }

    printf("Date to be searched\n");
    do
    {
        printf("Give month: ");
        check = scanf("%d", &user_key.date.tm_mon);
        check = !(user_key.date.tm_mon > 0 && user_key.date.tm_mon < 13);
    } while (check);

    do
    {
        printf("Give day: ");
        check = scanf("%d", &user_key.date.tm_mday);
        check = !(user_key.date.tm_mday > 0 && user_key.date.tm_mday < 32);
    } while (check);

    do
    {
        printf("Give year: ");
        check = scanf("%d", &user_key.date.tm_year);
        check = !(user_key.date.tm_year > 0);
    } while (check);

    user_key.date.tm_year -= 1900;
    user_key.date.tm_mon -= 1;
    user_key.date.tm_hour = 0;
    user_key.date.tm_min = 0;
    user_key.date.tm_sec = 0;

    searching_node = search(root, mktime(&user_key.date));

    if (searching_node == NULL)
    {
        printf("There's no record!\n");
        return FALSE;
    }

    printf("\nGive the new temp: ");
    check = scanf("%lf", &new_temp);
    strftime(time_str, 11, "%m/%d/%Y", &searching_node->key.date);
    fflush(NULL);
    printf("Are you sure you want to change the temperature of date %s to %lf?(y/n) ", time_str, new_temp);
    check = scanf("%s", choice);
    if (strcmp(choice, "y") == 0)
    {
        searching_node->key.T_degC = new_temp;
        return TRUE;
    }

    return FALSE;
}

void print_equal(int number)
{
    int i;

    for (i = 0; i < number; i++)
        printf("=");
    printf("\n");
}

void delete (Node *root)
{
    table_data user_key;
    int check;
    char *time_str = (char *)malloc(sizeof(char) * 11);
    if (!check_allocation(time_str))
    {
        fprintf(stderr, "Error\n");
        return;
    }

    printf("Date to be searched\n");
    do
    {
        printf("Give month: ");
        check = scanf("%d", &user_key.date.tm_mon);
        check = !(user_key.date.tm_mon > 0 && user_key.date.tm_mon < 13);
    } while (check);

    do
    {
        printf("Give day: ");
        check = scanf("%d", &user_key.date.tm_mday);
        check = !(user_key.date.tm_mday > 0 && user_key.date.tm_mday < 32);
    } while (check);

    do
    {
        printf("Give year: ");
        check = scanf("%d", &user_key.date.tm_year);
        check = !(user_key.date.tm_year > 0);
    } while (check);

    user_key.date.tm_year -= 1900;
    user_key.date.tm_mon -= 1;
    user_key.date.tm_hour = 0;
    user_key.date.tm_min = 0;
    user_key.date.tm_sec = 0;

    root = node_delete(root, mktime(&user_key.date));
}