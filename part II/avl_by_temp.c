#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LINE_SIZE 100
#define TRUE 1
#define FALSE 0

struct dateList
{
    struct tm date;
    struct dateList *next;
};

struct table_data
{
    struct tm d;
    double T_degC;
};

struct table_data_by_temp
{
    struct dateList *date;
    double T_degC;
};

struct Node
{
    struct table_data_by_temp key; // table_data key
    struct Node *left;             //
    struct Node *right;
    int height;
};

typedef struct Node Node;
typedef struct table_data_by_temp TD;
typedef struct dateList DL;
typedef struct table_data table_data;

Node *insert_temp(Node *node, table_data key);
Node *newNode(table_data key);
int height(Node *N);
int max(int a, int b);
int getBalance(Node *N);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
Node *LR_Rotate(Node *x);
Node *RL_Rotate(Node *x);
Node *insert_from_file_by_date(char *filename, Node *root);
int check_allocation(void *p);
void printAVLD(Node *root);
void printMin(Node *root);
void printMax(Node *root);

int main()
{
    Node *root = NULL;

    root = insert_from_file_by_date("ocean.csv", root);

    printMin(root);
    printf("\n\n\n");
    printMax(root);

    exit(0);
}

Node *insert_temp(Node *node, table_data key)
{
    DL *temp = NULL;
    int balance;

    if (node == NULL)
        return (newNode(key));

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

    node->height = height(node);

    balance = getBalance(node);

    if (balance > 1 && key.T_degC < node->left->key.T_degC)
        return rightRotate(node);

    if (balance < -1 && key.T_degC > node->right->key.T_degC)
        return leftRotate(node);

    if (balance > 1 && key.T_degC > node->left->key.T_degC)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key.T_degC < node->right->key.T_degC)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *newNode(table_data key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key.T_degC = key.T_degC;
    node->key.date = (DL *)malloc(sizeof(DL));
    node->key.date->date = key.d;
    node->key.date->next = NULL;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return (node);
}

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

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

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
    x->right = rightRotate(x->right);

    return leftRotate(x);
}

Node *insert_from_file_by_date(char *filename, Node *root)
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

int check_allocation(void *p)
{
    if (!p)
    {
        fprintf(stderr, "Error allocating memory!");
        return FALSE;
    }

    return TRUE;
}

void printAVLD(Node *root)
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

void printMin(Node *root)
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
        printf("%s %05.2lf\n", time_str, root->key.T_degC);
        temp = temp->next;
    }

    free(time_str);
}

void printMax(Node *root){
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
        printf("%s %05.2lf\n", time_str, root->key.T_degC);
        temp = temp->next;
    }

    free(time_str);
}