#ifndef MAIN_FUNCTIONS_H

#define MAIN_FUNCTIONS_H

#define NUM_LEN 10

/*
   user_insert(): synartisi eisagwgis 
   komvou sto menu apo riza enos AVL root
*/
Node *user_insert(Node *root);
/*
   change_temp(): synartisi allagis 
   thermokrasias sto menu enos 
   komvou apo riza enos AVL root
*/
int change_temp(Node *root);
/* 
   print_equal(): Typonontai "=" plithous 
   number
*/
void print_equal(int number);
/*
   user_search(): synartisi anazitishs 
   sto menu enos komvou apo riza
   enos AVL root
*/
void user_search(Node *root);
/*
   delete(): synartisi diagrafis 
   sto menu enos komvou apo riza
   enos AVL root
*/
void delete (Node *root);

#endif