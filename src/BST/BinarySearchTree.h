/*!
\file BinarySearchTree.h
\brief Header-файл реализации структуры Дерева Бинарного Поиска

Содерижит объявления функций, предназначенных для работы с реализованной структурой
*/

#ifndef BinarySearchTree_header
#define BinarySearchTree_header

/*! \struct node
    \brief Основной элемент бинарного дерева

    На базе нод строится реализация бинарного дерева, чтобы взаимодействовать со всем деревом целиком, нужно знать его коренную ноду
*/
struct node {
  /** Хранимое в ноде значение по указателю свободного типа */
  void *data;
  /** Указатель на правого потомка (того же типа, что и сама нода) */
  struct node *right_child; 
  /** Указатель на левого потомка (того же типа, что и сама нода) */
  struct node *left_child;  
};

struct node *search(struct node *root, void* data, int (*compare)(void *data_one, void *data_two));
struct node *find_minimum(struct node *root);
struct node *new_node(void* data, unsigned long data_size);
struct node *insert(struct node *root, void* data, unsigned long data_size, int (*compare)(void *data_one, void *data_two));
struct node *removing(struct node *root, void *data, int (*compare)(void *data_one, void *data_two));
void inorder(struct node *root, void (*print)(void *data));

#endif