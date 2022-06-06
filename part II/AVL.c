#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
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

Node *LR_Rotate(Node *x)
{
    x->left = leftRotate(x->left);

    return rightRotate(x);
}

Node *RL_Rotate(Node *x)
{
    x->right = leftRotate(x->right);

    return rightRotate(x);
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

int delete_root(Node *root, table_data *elem)
{

    if (root->left != NULL || root->right != NULL) // H riza exei paidia
        return FALSE;

    *elem = root->key;
    free(root);
    root = NULL;
    return TRUE;
}

int delete_right(Node *parent, table_data *elem)
{
    Node *current;

    if (parent->right == NULL) // den yparxei deksi paidi
        return FALSE;

    current = parent->right;
    if (current->left != NULL || current->right != NULL) // to stoixeio exei toulaxiston 1 paidi
        return FALSE;

    *elem = current->key;
    free(current);
    parent->right = NULL;
    return TRUE;
}

int delete_left(Node *parent, table_data *elem)
{
    Node *current;

    if (parent->left == NULL) // den yparxei deksi paidi
        return FALSE;

    current = parent->left;
    if (current->left != NULL || current->right != NULL) // to stoixeio exei toulaxiston 1 paidi
        return FALSE;

    *elem = current->key;
    free(current);
    parent->left = NULL;
    return TRUE;
}

void printAVL(Node *root)
{
    char *time_str = (char *)malloc(sizeof(char) * 11);

    if (root == NULL)
        return;

    printAVL(root->left);
    strftime(time_str, 11, "%m/%d/%Y", &root->key.date);
    printf("%s %05.2lf\n", time_str, root->key.T_degC);

    printAVL(root->right);
    free(time_str);
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

    while (root != NULL)
    {
        root->key.date.tm_hour = 0;
        root->key.date.tm_min = 0;
        root->key.date.tm_sec = 0;
        diff = difftime(date, mktime(&root->key.date));

        if (fabs(diff) >= 0.0 && fabs(diff) <= 3600) // found
            return root;
        else if (diff < 0.0) // metagenesteri
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

Node *node_delete(Node *root, time_t date)
{
    Node *current, *parent, *next_ordered;
    int p; // 1 -> deksi paidi, 2 -> aristero paidi
    int balance;
    double diff;

    // Anazitisi

    parent = NULL;
    current = root;
    while (current != NULL)
    {
        current->key.date.tm_hour = 0;
        current->key.date.tm_min = 0;
        current->key.date.tm_sec = 0;
        diff = difftime(date, mktime(&current->key.date));

        if (fabs(diff) >= 0.0 && fabs(diff) <= 3600)
            break;
        else if (diff < 0.0)
        {
            parent = current;
            p = 1;
            current = current->left;
        }
        else // diff > 0.0
        {
            parent = current;
            p = 2;
            current = current->right;
        }
    }
    if (current == NULL)
    {
        printf("\nThere's no such date\n");
        return NULL;
    }

    // kanena paidi
    if (current->left == NULL && current->right == NULL)
    {
        free(current);

        if (parent == NULL)
            root = NULL;
        else if (p == 1)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    // ena aristero paidi
    else if (current->left != NULL && current->right == NULL)
    {
        if (parent == NULL)
            root = current->left;
        else if (p == 1)
            parent->left = current->left;
        else
            parent->right = current->left;
        free(current);
    }
    // ena deksi paidi
    else if (current->left == NULL && current->right != NULL)
    {
        if (parent == NULL)
            root = current->right;
        else if (p == 1)
            parent->left = current->right;
        else
            parent->right = current->right;
        free(current);
    }
    // dyo paidia
    else
    {
        p = 1;
        next_ordered = current->right;

        while (next_ordered->left != NULL)
        {
            parent = next_ordered;
            next_ordered = next_ordered->left;
            p = 2;
        }

        current->key.date.tm_mon = next_ordered->key.date.tm_mon;
        current->key.date.tm_mday = next_ordered->key.date.tm_mday;
        current->key.date.tm_year = next_ordered->key.date.tm_year;
        current->key.date.tm_hour = next_ordered->key.date.tm_hour;
        current->key.date.tm_min = next_ordered->key.date.tm_min;
        current->key.date.tm_sec = next_ordered->key.date.tm_sec;
        current->key.T_degC = next_ordered->key.T_degC;

        if (p == 1) // epomenos deksi paidi
        {
            current->right = next_ordered->right;
            free(next_ordered);
        }
        else
        {
            parent->left = next_ordered->right;
            free(next_ordered);
        }
    }

    // to dendro exei enan komvo
    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    balance = getBalance(root);

    // LL rotation
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR rotation
    if (balance > 1 && getBalance(root->left) < 0)
        return LR_Rotate(root);

    // RR rotation
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL rotation
    if (balance < -1 && getBalance(root->right) > 0)
        return RL_Rotate(root);

    printf("\nThe record has been successfully deleted!\n");

    return root;
}
