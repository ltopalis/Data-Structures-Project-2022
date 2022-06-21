#ifndef AVL_H

#define AVL_H
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
Node *LR_Rotate(Node *x);
Node *RL_Rotate(Node *x);
Node *insert(Node *node, table_data key);
Node *insert_from_file(char *filename, Node *root);
/* delete_root(): diagrafi tis rizas efoson den exei paidia */
int delete_root(Node *parent, table_data *elem);
/* delete_right(): diagrafi tou deksiou paidiou efoson den exei paidia to teleftaio */
int delete_right(Node *parent, table_data *elem);
/* delete_left(): diagrafi tou aristerou paidiou efoson den exei paidia to teleftaio */
int delete_left(Node *parent, table_data *elem);
void printAVL(Node *root);
int getBalance(Node *N);
int max(int a, int b);
int check_allocation(void *p);
Node *search(Node *root, time_t date);
Node *node_delete(Node *root, time_t date);
/* Delete the leaves of a tree, but it doesn't set root to NULL */
void delete_AVL_recursive(Node *root);
/* Delete the whole AVL tree */
Node *delete_AVL(Node *root);

#endif