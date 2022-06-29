#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "struct.h"
#include "avl_by_temp.h"

Node_T *insert_temp(Node_T *node, table_data_T key)
{
    DL *temp = NULL;
    int balance;

    if (node == NULL)
        return (newNode_T(key));

    if (key.T_degC < node->key.T_degC)
        node->left = insert_temp(node->left, key);
    else if (key.T_degC > node->key.T_degC)
        node->right = insert_temp(node->right, key);
    else /* temp of current node is equal to our temp */
    {

        temp = node->key.date;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = (DL *)malloc(sizeof(DL));
        temp = temp->next;
        temp->date.tm_mday = key.d.tm_mday;
        temp->date.tm_mon = key.d.tm_mon;
        temp->date.tm_year = key.d.tm_year;
        temp->date.tm_hour = 0;
        temp->date.tm_min = 0;
        temp->date.tm_sec = 0;
        temp->date.tm_isdst = 0;
        temp->next = NULL;
    }

    node->height = height_T(node);

    balance = getBalance_T(node);

    if (balance > 1 && key.T_degC < node->left->key.T_degC)
        return rightRotate_T(node);

    if (balance < -1 && key.T_degC > node->right->key.T_degC)
        return leftRotate_T(node);

    if (balance > 1 && key.T_degC > node->left->key.T_degC)
    {
        node->left = leftRotate_T(node->left);
        return rightRotate_T(node);
    }

    if (balance < -1 && key.T_degC < node->right->key.T_degC)
    {
        node->right = rightRotate_T(node->right);
        return leftRotate_T(node);
    }

    return node;
}

Node_T *newNode_T(table_data_T key)
{
    Node_T *node = (Node_T *)malloc(sizeof(Node_T));
    node->key.T_degC = key.T_degC;
    node->key.date = (DL *)malloc(sizeof(DL));
    node->key.date->date = key.d;
    node->key.date->next = NULL;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return (node);
}

int height_T(Node_T *N)
{
    if (N == NULL)
        return 0;
    return 1 + max(height_T(N->left), height_T(N->right));
}

int getBalance_T(Node_T *N)
{
    if (N == NULL)
        return 0;
    return height_T(N->left) - height_T(N->right);
}

Node_T *rightRotate_T(Node_T *y)
{
    Node_T *x = y->left;
    Node_T *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = height_T(y);
    x->height = height_T(x);

    return x;
}

Node_T *leftRotate_T(Node_T *x)
{
    Node_T *y = x->right;
    Node_T *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = height_T(x);
    y->height = height_T(y);

    return y;
}

Node_T *LR_Rotate_T(Node_T *x)
{
    x->left = leftRotate_T(x->left);

    return rightRotate_T(x);
}

Node_T *RL_Rotate_T(Node_T *x)
{
    x->right = rightRotate_T(x->right);

    return leftRotate_T(x);
}

Node_T *insert_from_file_by_temp(char *filename, Node_T *root)
{
    FILE *fp = NULL;
    table_data_T temp;
    char *pinakas = (char *)malloc(sizeof(char) * LINE_SIZE);
    char *date_str = (char *)malloc(sizeof(char) * (10 + 1));
    if (check_allocation((char *)pinakas) == FALSE)
        return FALSE;
    if (check_allocation((char *)date_str) == FALSE)
        return FALSE;

    fp = fopen(filename, "r");
    if (!fp)
    {
        fprintf(stderr, "Error opening file!\n");
        return NULL;
    }

    pinakas = fgets(pinakas, LINE_SIZE - 1, fp);      // Διαβάζουμε την πρώτη γραμμή του
                                                      // αρχείου με τις επικεφαλίδες κάθε τιμής
    while (fgets(pinakas, LINE_SIZE - 1, fp) != NULL) // Η while εκτελέιται εώς ότου
                                                      // φτάσουμε στο τέλος του αρχείου
    {
        strcpy(date_str, strtok(pinakas, ","));
        temp.T_degC = atof(strtok(NULL, ","));
        temp.d.tm_mon = atoi(strtok(date_str, "/")) - 1; /* month, range 0 to 11             */
        temp.d.tm_mday = atoi(strtok(NULL, "/"));        /* day of the month, range 1 to 31  */
        temp.d.tm_year = atoi(strtok(NULL, "/")) - 1900; /* The number of years since 1900   */
        temp.d.tm_sec = 0;                               /* seconds,  range 0 to 59          */
        temp.d.tm_min = 0;                               /* minutes, range 0 to 59           */
        temp.d.tm_hour = 0;                              /* hours, range 0 to 23             */
        temp.d.tm_wday = 0;                              /* day of the week, range 0 to 6    */
        temp.d.tm_yday = 0;                              /* day in the year, range 0 to 365  */
        temp.d.tm_isdst = 0;                             /* daylight saving time             */
        root = insert_temp(root, temp);
    }

    fclose(fp);
    free(pinakas);
    free(date_str);

    return root;
}

void printAVLD(Node_T *root)
{
    char *time_str = (char *)malloc(sizeof(char) * 11);
    DL *temp;

    if (root == NULL)
        return;

    printAVLD(root->left);
    temp = root->key.date;
    while (temp)
    {
        strftime(time_str, 11, "%m/%d/%Y", &temp->date);
        printf("%s %05.2lf\n", time_str, root->key.T_degC);
        temp = temp->next;
    }

    printAVLD(root->right);
    free(time_str);
}

void printMin(Node_T *root)
{
    char *time_str = (char *)malloc(sizeof(char) * 11);
    DL *temp;

    while (root->left)
    {
        root = root->left;
    }

    temp = root->key.date;
    while (temp)
    {
        strftime(time_str, 11, "%m/%d/%Y", &temp->date);
        printf("%s\t%05.2lf\n", time_str, root->key.T_degC);
        temp = temp->next;
    }

    free(time_str);
}

void printMax(Node_T *root)
{
    char *time_str = (char *)malloc(sizeof(char) * 11);
    DL *temp;

    while (root->right)
    {
        root = root->right;
    }

    temp = root->key.date;
    while (temp)
    {
        strftime(time_str, 11, "%m/%d/%Y", &temp->date);
        printf("%s\t%05.2lf\n", time_str, root->key.T_degC);
        temp = temp->next;
    }

    free(time_str);
}