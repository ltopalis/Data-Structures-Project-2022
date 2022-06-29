#ifndef AVL_BY_TEMP_H

#define AVL_BY_TEMP_H

struct dateList
{
    struct tm date;
    struct dateList *next;
};

struct table_data_T
{
    struct tm d;
    double T_degC;
};

struct table_data_by_temp
{
    struct dateList *date;
    double T_degC;
};

struct Node_T
{
    struct table_data_by_temp key; // table_data key
    struct Node_T *left;           //
    struct Node_T *right;
    int height;
};

typedef struct Node_T Node_T;
typedef struct table_data_by_temp TD;
typedef struct dateList DL;
typedef struct table_data_T table_data_T;

Node_T *insert_temp(Node_T *node, table_data_T key);
Node_T *newNode_T(table_data_T key);
int height_T(Node_T *N);
int getBalance_T(Node_T *N);
Node_T *rightRotate_T(Node_T *y);
Node_T *leftRotate_T(Node_T *x);
Node_T *LR_Rotate_T(Node_T *x);
Node_T *RL_Rotate_T(Node_T *x);
Node_T *insert_from_file_by_temp(char *filename, Node_T *root);
void printAVLD(Node_T *root);
void printMin(Node_T *root);
void printMax(Node_T *root);

#endif