#ifndef MENU_H

#define MENU_H

void clean();
void menu(Node *root, Node_T *root_T, DataItem **array);
void AVL(Node *root, Node_T *root_T);
void avl_by_date(Node *root);
void avl_by_temp(Node_T *root);
void hashing(DataItem **array);

#endif