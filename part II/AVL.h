#ifndef AVL_H
#define AVL_H

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
int insert_from_file();

#endif