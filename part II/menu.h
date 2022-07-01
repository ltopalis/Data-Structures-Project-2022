#ifndef MENU_H

#define MENU_H

/*
   clean(): Synartisi pou katharizei tin konsola.
   Exei ilopoihthei wste na ekteleitai se Linux,
   Windows kai MacOS
*/
void clean();
/*
   menu(): to kyrios menu tou
   programmatos to opoio odigei
   kai organwnei tis synartiseis
   pou tha ektelestoun symfwna me
   tis epiloges tou xristi
*/
void menu(Node *root, Node_T *root_T, DataItem **array);
/*
   AVL(): Menu pou antapokrinetai 
   stis synartiseis dendrou AVL
*/
void AVL(Node *root, Node_T *root_T);
/*
   avl_by_date(): Menu pou antapokrinetai 
   stis synartiseis dendrou AVL me vasei
   tin imerominia
*/
void avl_by_date(Node *root);
/*
   avl_by_temp(): Menu pou antapokrinetai 
   stis synartiseis dendrou AVL me vasei
   tin thermokrasia
*/
void avl_by_temp(Node_T *root);
/*
   hashing(): Menu pou antapokrinetai 
   stis synartiseis hashing
*/
void hashing(DataItem **array);

#endif