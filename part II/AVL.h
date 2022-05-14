#ifndef AVL_H
#define AVL_H

#define TRUE 1
#define FALSE 0

struct table_data
{
    struct tm date;
    double T_degC;
};

struct node
{
    struct table_data key;
    struct node *left;
    struct node *right;
    int height;
};

typedef struct table_data table_data;   // synonymo ths domis pou periexei ta stoixeia tou pinaka
typedef struct node tree_node;          // synonymo tou komvou dendrou
typedef struct node *node_ptr;          // synonymo toy deikti komvou dendrou

// arxikopoiei ton deikti root na deixnei sthn riza tou dendrou /
void init_avl(node_ptr *root); 

// elegxei an to AVL dendro einai adeio                 
int check_empty(node_ptr root);    

// thetei to stoixeio x ws riza tou dendrou             
int root_insert(node_ptr *root, table_data x);

// topothetei to stoixeio x ws aristero paidi tou kombou "komvos"  
int insert_left(node_ptr komvos, table_data x); 

// topothetei to stoixeio x ws deksi paidi tou kombou "komvos"
int insert_right(node_ptr komvos, table_data x);

// epistrefei thn timh thw megalyteris metavlitis
int max(int x, int y);            

// epistrefei to ipsos tou komvou
int height(node_ptr node);

// ektelei mia deksia peristrofi
node_ptr RR_rotation(node_ptr node);

// ektelei mia aristeri peristrofi
node_ptr LL_rotation(node_ptr node);

// ektelei mia deksia kai epita mia aristeri peristrofi
node_ptr RL_rotation(node_ptr node);

// ektelei mia aristeri kai epita mia deksia peristrofi
node_ptr LR_rotation(node_ptr node);

// Eisagei to stoixeio x sto AVL
node_ptr insert(node_ptr *root, table_data x);


#endif