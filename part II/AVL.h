#ifndef AVL_H

#define AVL_H
#define DATA 1405
#define TABLE_SIZE 1405

struct Node
{
    struct table_data key; // table_data key
    struct Node *left;
    struct Node *right;
    int height;
};

typedef struct table_data table_data;
typedef struct Node Node;

/*
   height(): epistrefetai to ipsos tou
   komvou N
*/
int height(Node *N);
/*
   newNode(): dimioyrgitai enas neos komvos dendrou
   me stoixeia key
*/
Node *newNode(table_data key);
/*
   rightRotate(): Ekteleitai deksia peristrofi
   ston komvo x kai epistrefetai i riza
   tou dentrou
*/
Node *rightRotate(Node *y);
/*
   leftRotate(): Ekteleitai aristeri peristrofi
   ston komvo x kai epistrefetai i riza
   tou dentrou
*/
Node *leftRotate(Node *x);
/*
   LR_Rotate_T(): Ekteleitai LR peristrofi
   ston komvo x kai epistrefetai i riza
   tou dentrou
*/
Node *LR_Rotate(Node *x);
/*
   RL_Rotate_T(): Ekteleitai RL peristrofi
   ston komvo x kai epistrefetai i riza
   tou dentrou
*/
Node *RL_Rotate(Node *x);
/* 
   insert(): Eisagei enan neo komvo me stoixeia key
   stin riza tou dentrou node. EPistrefetai i riza tou dentrou
*/
Node *insert(Node *node, table_data key);
/*
   insert_from_file(): Eisagei se dentro
   AVL me riza root ta stoixeia tou arxeiou 
   filename me vasei thn imerominia kai epistrefetai
   h riza tou dentrou
*/
Node *insert_from_file(char *filename, Node *root);
/* 
   delete_root(): diagrafi tis rizas efoson den exei paidia
*/
int delete_root(Node *parent, table_data *elem);
/* 
   delete_right(): diagrafi tou deksiou paidiou efoson
   den exei paidia to teleftaio 
*/
int delete_right(Node *parent, table_data *elem);
/* 
   delete_left(): diagrafi tou aristerou paidiou efoson
   den exei paidia to teleftaio 
*/
int delete_left(Node *parent, table_data *elem);
/* 
   printAVL(): Typwnei to dentro me riza root
*/
void printAVL(Node *root);
/*
   getBalance(): epistrefetai i ypsozygisi
   tou komvou N
*/
int getBalance(Node *N);
/*
   search(): anazeititai o komvos tou dedrou
   me riza root pou exei imerominia date.
   An den yparxei epistrefetai NULL
*/
Node *search(Node *root, time_t date);
/*
   node_delete(): diagrafetai o komvos me 
   imerominia date apo dentro me riza root.
   An den yparxei epistrefetai NULL alliws 
   i riza tou dentrou
*/
Node *node_delete(Node *root, time_t date);
/* 
   Delete the leaves of a tree, but 
   it doesn't set root to NULL 
*/
void delete_AVL_recursive(Node *root);
/* 
   Delete the whole AVL tree
*/
Node *delete_AVL(Node *root);

#endif