#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"

void init_avl(node_ptr *root)
{
    *root = NULL;
}

int check_empty(node_ptr root)
{
    return root == NULL;
}

int root_insert(node_ptr *root, table_data x)
{

    node_ptr newNode;

    if (*root != NULL)
        return FALSE;

    newNode = (node_ptr)malloc(sizeof(node_ptr));
    if (!newNode)
    {
        fprintf(stderr, "Error allocation Memory!\n");
        return FALSE;
    }

    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;

    *root = newNode;
    return TRUE;
}

int insert_left(node_ptr komvos, table_data x)
{
    node_ptr newNode;

    if (komvos->left != NULL)
        return FALSE;

    newNode = (node_ptr)malloc(sizeof(node_ptr));
    if (!newNode)
    {
        fprintf(stderr, "Error allocating memory!\n");
        return FALSE;
    }

    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;

    komvos->left = newNode;
    return TRUE;
}

int insert_right(node_ptr komvos, table_data x)
{
    node_ptr newNode;

    if (komvos->right != NULL)
        return FALSE;
    fprintf(stderr, "%ld\n", sizeof(node_ptr));

    newNode = (node_ptr)malloc(sizeof(node_ptr));
    if (!newNode)
    {
        fprintf(stderr, "Error allocating memory!\n");
        return FALSE;
    }

    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;

    komvos->right = newNode;
    return TRUE;
}

int max(int x, int y)
{
    if (x < y)
        return y;
    else
        return x;
}

int height(node_ptr node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}

node_ptr RR_rotation(node_ptr C)
{
    node_ptr L = NULL;

    L = C->right;
    C->left = L->right;
    L->right = C;
    C->height = max(height(C->left), height(C->right)) + 1;
    L->height = max(height(L->left), height(L->right)) + 1;

    return L;
}

node_ptr LL_rotation(node_ptr C)
{
    node_ptr R = NULL;

    R = C->left;
    C->right = R->left;
    R->left = C;
    C->height = max(height(C->left), height(C->right)) + 1;
    R->height = max(height(R->left), height(R->right)) + 1;

    return R;
}

node_ptr LR_rotation(node_ptr C)
{
    C->right = LL_rotation(C->left);

    return RR_rotation(C);
}

node_ptr RL_rotation(node_ptr C)
{
    C->right = RR_rotation(C->left);

    return LL_rotation(C);
}

node_ptr insert(node_ptr *root, table_data x)
{
    double diff = 0.0;

    if (*root == NULL)
    {
        root_insert(root, x);
        (*root)->height = 1;
        return (*root);
    }

    diff = difftime(mktime(&x.date), mktime(&((*root)->key.date)));

    if (diff < 0.0)
    {

        (*root)->left = insert(&((*root)->left), x);
        if (height((*root)->left) - height((*root)->right) == 2)
        {
            if (difftime(mktime(&x.date), mktime(&((*root)->left->key.date))) < 0.0)
                (*root) = RR_rotation(*root);
            else
                (*root) = LR_rotation(*root);
        }
    }
    else if (diff > 0.0)
    {

        (*root)->right = insert(&((*root)->right), x);
        if (height((*root)->left) - height((*root)->right) == -2)
        {
            if (difftime(mktime(&x.date), mktime(&((*root)->right->key.date))) < 0.0)
                (*root) = RR_rotation(*root);
            else
                (*root) = LR_rotation(*root);
        }
    }

    (*root)->height = max(height((*root)->left), height((*root)->right)) + 1;

    return (*root);
}