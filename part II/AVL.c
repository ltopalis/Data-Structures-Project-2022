#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "AVL.h"

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return 1 + max(height(N->left), height(N->right));
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

Node *newNode(table_data key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return (node);
}

// right rotate subtree
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = height(y);
    x->height = height(x);

    return x;
}

// left rotate subtree
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = height(x);
    y->height = height(y);

    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

//  insert
Node *insert(Node *node, table_data key)
{

    if (node == NULL)
        return (newNode(key));

    if (difftime(mktime(&key.date), mktime(&node->key.date)) < 0)
        node->left = insert(node->left, key);
    else if (difftime(mktime(&key.date), mktime(&node->key.date)) > 0)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = height(node);

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && difftime(mktime(&key.date), mktime(&node->left->key.date)) < 0)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && difftime(mktime(&key.date), mktime(&node->right->key.date)) > 0)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && difftime(mktime(&key.date), mktime(&node->left->key.date)) > 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && difftime(mktime(&key.date), mktime(&node->right->key.date)) < 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *insert_from_file(char *filename, Node *root)
{
    FILE *fp = NULL;
    table_data temp;
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
        temp.date.tm_mon = atoi(strtok(date_str, "/")) - 1; /* month, range 0 to 11             */
        temp.date.tm_mday = atoi(strtok(NULL, "/"));        /* day of the month, range 1 to 31  */
        temp.date.tm_year = atoi(strtok(NULL, "/")) - 1900; /* The number of years since 1900   */
        temp.date.tm_sec = 0;                               /* seconds,  range 0 to 59          */
        temp.date.tm_min = 0;                               /* minutes, range 0 to 59           */
        temp.date.tm_hour = 0;                              /* hours, range 0 to 23             */
        temp.date.tm_wday = 0;                              /* day of the week, range 0 to 6    */
        temp.date.tm_yday = 0;                              /* day in the year, range 0 to 365  */
        temp.date.tm_isdst = -1;                            /* daylight saving time             */
        root = insert(root, temp);
    }

    fclose(fp);
    free(pinakas);
    free(date_str);

    return root;
}

void printAVL(Node *root)
{
    char *time_str = (char *)malloc(sizeof(char) * 11);

    if (root != NULL)
    {
        strftime(time_str, 11, "%m/%d/%Y", &root->key.date);
        printf("%s %05.2lf\n", time_str, root->key.T_degC);
        printAVL(root->left);
        printAVL(root->right);
    }
}

int check_allocation(void *p)
{
    if (!p)
    {
        fprintf(stderr, "Error allocating memory!");
        return FALSE;
    }

    return TRUE;
}

Node *search(Node *root, time_t date)
{
    double diff;

    if (root == NULL)
        return root;

    diff = difftime(date, mktime(&(root->key).date));

    if (diff == 0.0) // found
        return root;
    else if (diff > 0.0) // metagenesterh
        return search(root->right, date);
    else // mikroterh
        return search(root->left, date);
}