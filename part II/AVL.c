#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define LINE_SIZE 100
#define DATA 1405
#define TABLE_SIZE 1405

struct table_data
{
    struct tm date;
    double T_degC;
};

struct Node
{
    struct table_data key; // table_data key
    struct Node *left;     //
    struct Node *right;
    int height;
};

typedef struct table_data table_data;
typedef struct Node Node;

int height(Node *N);
Node *newNode(table_data key);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
Node *insert(Node *node, table_data key);
void printAVL(Node *root);
int getBalance(Node *N);
int max(int a, int b);
int check_allocation(void *p);
double search(Node *root, time_t date);

int main()
{
    struct tm date;
    FILE *fp = NULL;
    Node *root = NULL;
    table_data temp;
    char *pinakas = (char *)malloc(sizeof(char) * LINE_SIZE);
    char *date_str = (char *)malloc(sizeof(char) * (10 + 1));
    if (check_allocation((char *)pinakas) == FALSE)
        return FALSE;
    if (check_allocation((char *)date_str) == FALSE)
        return FALSE;
    fp = fopen("ocean.csv", "r");
    if (!fp)
    {
        fprintf(stderr, "Error opening file!\n");
        exit(0);
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

    // printAVL(root);

    printf("Give us a date\n");
    scanf("%d", &date.tm_mon);
    scanf("%d", &date.tm_mday);
    scanf("%d", &date.tm_year);
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;
    date.tm_mon -= 1;
    date.tm_year -= 1900;
    printf("%.2lf\n", search(root, mktime(&date)));
    fclose(fp);
    free(pinakas);
    free(date_str);

    return 0;
}

int height(struct Node *N)
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

double search(Node *root, time_t date)
{
    double diff;

    if (root == NULL)
        return -1.0;

    diff = difftime(date, mktime(&(root->key).date));

    if (diff == 0.0) // found
        return root->key.T_degC;
    else if (diff > 0.0) // metagenesterh
        return search(root->right, date);
    else if (diff < 0.0) // mikroterh
        return search(root->left, date);

}