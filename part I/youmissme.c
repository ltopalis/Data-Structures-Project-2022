#include <stdio.h>
#include <stdlib.h>
#include "fundamentals.h"
#include <time.h>
#include "file_manager.h"

// haha
struct Node
{
    table_data key;  //table_data key
    struct Node *left; //
    struct Node *right;
    int height;
};


int max(int a, int b);


int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return 1 + max(height(N->left), height(N->right));
}


int max(int a, int b)
{
    if(a>b)
    return a;
    else return b;
}


struct Node *newNode(table_data key)
{
    struct Node *node = (struct Node *)
        malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 0; 
    return (node);
}

//right rotate subtree 
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

  
    x->right = y;
    y->left = T2;

 
    y->height = height(y);
    x->height = height(x);


    return x;
}

//left rotate subtree 
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

 
    y->left = x;
    x->right = T2;

   
    x->height = height(x);
    y->height = height(y);


    return y;
}


int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

//  insert 
struct Node *insert(struct Node *node, table_data key)
{
   
    if (node == NULL)
        return (newNode(key));

    if (difftime(mktime(&key.date), mktime(&node->key.date))<0)
        node->left = insert(node->left, key);
    else if (difftime(mktime(&key.date), mktime(&node->key.date))>0)
        node->right = insert(node->right, key);
    else // dgaf
        return node;

   
    node->height = height(node);

  
    int balance = getBalance(node);

   

    // Left Left
    if (balance > 1 && difftime(mktime(&key.date), mktime(&node->left->key.date))<0)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && difftime(mktime(&key.date), mktime(&node->right->key.date))>0)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && difftime(mktime(&key.date), mktime(&node->left->key.date))>0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && difftime(mktime(&key.date), mktime(&node->right->key.date))<0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }


    return node;
}


void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d %d %d \n", root->key.date.tm_mday, root->key.date.tm_mon+1, root->key.date.tm_year+1900);
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main()
{  
    table_data values[DATA];
  char contents[LINE_SIZE];
  open_file("ocean.csv", values, contents);
    struct Node *root = NULL;

 

    for(int i=0; i<10; i++)
    {
        root = insert(root, values[i]);
    }
    


    printf("tree");
    preOrder(root);

    return 0;
}
