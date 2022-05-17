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