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

/* 
   insert_temp(): Eisagei enan neo komvo me stoixeia key
   stin riza tou dentrou node. EPistrefetai i riza tou dentrou
*/
Node_T *insert_temp(Node_T *node, table_data_T key);
/*
   newNode_T(): dimioyrgitai enas neos komvos dendrou
   me stoixeia key
*/
Node_T *newNode_T(table_data_T key);
/*
   height_T(): epistrefetai to ipsos tou
   komvou N
*/
int height_T(Node_T *N);
/*
   getBalance_T(): epistrefetai i ypsozygisi
   tou komvou N
*/
int getBalance_T(Node_T *N);
/*
   rightRotate_T(): Ekteleitai deksia peristrofi
   ston komvo x kai epistrefetai i riza
   tou dentrou
*/
Node_T *rightRotate_T(Node_T *y);
/*
   leftRotate_T(): Ekteleitai aristeri peristrofi
   ston komvo x kai epistrefetai i riza
   tou dentrou
*/
Node_T *leftRotate_T(Node_T *x);
/*
   LR_Rotate_T(): Ekteleitai LR peristrofi
   ston komvo x kai epistrefetai i riza
   tou dentrou
*/
Node_T *LR_Rotate_T(Node_T *x);
/*
   RL_Rotate_T(): Ekteleitai RL peristrofi
   ston komvo x kai epistrefetai i riza
   tou dentrou
*/
Node_T *RL_Rotate_T(Node_T *x);
/*
   insert_from_file_by_temp(): Eisagei se dentro
   AVL me riza root ta stoixeia tou arxeiou 
   filename me vasei thn thermokrasia kai epistrefetai
   h riza tou dentrou
*/
Node_T *insert_from_file_by_temp(char *filename, Node_T *root);
/* 
   printAVLD(): Typwnei to dentro me riza root
*/
void printAVLD(Node_T *root);
/* 
   printMin(): Typwnei tis imerominies me thn
   xamiloteri thermokrasia dinontas thn riza 
   tou dendrou root 
*/
void printMin(Node_T *root);
/* 
   printMax(): Typwnei tis imerominies me thn
   ipsiloteri thermokrasia dinontas thn riza 
   tou dendrou root 
*/
void printMax(Node_T *root);

#endif