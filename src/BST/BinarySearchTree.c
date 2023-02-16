/*!
\file BinarySearchTree.с
\brief Основной файл функций BST

Содерижит реализацию функций, предназначенных для взаимодействия с этой структурой
*/

#include "BinarySearchTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Поиск элемента в дереве
///
/// Функция рекурсивно ищет элемент с заданным значениям, используя передаваемую функцию compare для сравнения элементов
///
/// \param root указатель на корень дерева
/// \param data указатель на значение для поиска
/// \param compare указатель на функцию для сравнения элементов
/// \return root указатель на найденный элемент или NULL если элемент не найден
//////////////////////////////////////////////////////////////////////////////////////////////////////
struct node *search(struct node *root, void* data, int (*compare)(void *data_one, void *data_two)) {
  if(root == NULL || compare(root->data, data) == 0){
    return root;
  }
  else if (compare(root->data, data) == -1){ // x is greater, so we will search the right subtree
    return search(root->right_child, data, compare);
  }
  else{ // x is smaller than the data, so we will search the left subtree
    return search(root->left_child, data, compare);
  } 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Поиск минимального элемента в поддереве
///
/// Функция рекурсивно ищет минимальный элемент в поддереве, следуя направлению влево
///
/// \param root указатель на корень дерева
/// \return root указатель на найденный элемент или NULL если передаваемое поддерево NULL
//////////////////////////////////////////////////////////////////////////////////////////////////////
// function to find the minimum value in a node
struct node *find_minimum(struct node *root) {
  if (root == NULL)
    return NULL;
  else if (root->left_child != NULL) // node with minimum value will have no left child
    return find_minimum(root->left_child); // left most element will be minimum
  return root;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Вставка элемента
///
/// Функция рекурсивно вставляет элемент с заданным значением в БДП
///
/// \param root указатель на корень дерева
/// \param data указатель на значение для вставки
/// \param data_size размер вставляемого значения
/// \param compare указатель на функцию для сравнения элементов
/// \return root указатель на новый корень дерева
//////////////////////////////////////////////////////////////////////////////////////////////////////
struct node *new_node(void* data, unsigned long data_size) {
  struct node *p;
  p = malloc(sizeof(struct node));
  p->data = malloc(data_size);
  memcpy(p->data, data, data_size);
  p->left_child = NULL;
  p->right_child = NULL;

  return p;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Вставка элемента
///
/// Функция рекурсивно удаляем элемент с заданным значением из БДП
///
/// \param root указатель на корень дерева
/// \param data указатель на значение для удаления
/// \param compare указатель на функцию для сравнения элементов
/// \return root указатель на новый корень дерева
//////////////////////////////////////////////////////////////////////////////////////////////////////
struct node *insert(struct node *root, void* data, unsigned long data_size, int (*compare)(void *data_one, void *data_two)) {
  // searching for the place to inseted
  if (root == NULL){
    return new_node(data, data_size);
  }
  else if (compare(root->data, data) == -1){
    // x is greater. Should be inserted to right
    root->right_child = insert(root->right_child, data, data_size, compare);
  } 
  else if (compare(root->data, data) == 1){
    // x is smaller should be inserted to left
    root->left_child = insert(root->left_child, data, data_size, compare);
  } 
  else if (compare(root->data, data) == 0){
    //free(root->data);
    root->data = malloc(data_size);
    memcpy(root->data, data, data_size);
  }
  return root;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Вставка элемента
///
/// Функция рекурсивно удаляем элемент с заданным значением из БДП
///
/// \param root указатель на корень дерева
/// \param data указатель на значение для удаления
/// \param compare указатель на функцию для сравнения элементов
/// \return root указатель на новый корень дерева
//////////////////////////////////////////////////////////////////////////////////////////////////////
// funnction to delete a node
struct node *removing(struct node *root, void* data, int (*compare)(void *data_one, void *data_two)) {
  // searching for the item to be deleted
  if (root == NULL)
    return NULL;
  if (compare(root->data, data) == -1){
    root->right_child = removing(root->right_child, data, compare);
  }
  else if (compare(root->data, data) == 1){
    root->left_child = removing(root->left_child, data, compare);
  }
  else {
    // No Children
    if (root->left_child == NULL && root->right_child == NULL) {
      free(root->data);
      free(root);
      return NULL;
    }

    // One Child
    else if (root->left_child == NULL || root->right_child == NULL) {
      struct node *temp;
      if (root->left_child == NULL)
        temp = root->right_child;
      else
        temp = root->left_child;
      free(root->data);
      free(root);
      return temp;
    }

    // Two Children
    else {
      struct node *temp = find_minimum(root->right_child);
      free(root->data);
      root->data = malloc(sizeof(temp->data));
      memcpy(root->data, temp->data, sizeof(temp->data));
      root->right_child = removing(root->right_child, temp->data, compare);
    }
  }
  return root;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Обход всех элементов дерева с выводом
///
/// Функция рекурсивно обходит все ДБП и вызывает указанную функцию print для вывода
///
/// \param root указатель на корень дерева
/// \param print указатель на функцию вывода
//////////////////////////////////////////////////////////////////////////////////////////////////////
void inorder(struct node *root, void (*print)(void *data)) {
  if (root != NULL) // checking if the root is not null
  {
    inorder(root->left_child, print);  // visiting left child
    print(root->data); // printing data at root
    inorder(root->right_child, print); // visiting right child
  }
}
