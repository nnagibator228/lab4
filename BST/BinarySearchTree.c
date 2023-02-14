#include "BinarySearchTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// function to find the minimum value in a node
struct node *find_minimum(struct node *root) {
  if (root == NULL)
    return NULL;
  else if (root->left_child != NULL) // node with minimum value will have no left child
    return find_minimum(root->left_child); // left most element will be minimum
  return root;
}

struct node *new_node(void* data, unsigned long data_size) {
  struct node *p;
  p = malloc(sizeof(struct node));
  p->data = malloc(data_size);
  memcpy(p->data, data, data_size);
  p->left_child = NULL;
  p->right_child = NULL;

  return p;
}

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
    memcpy(root->data, data, data_size);
  }
  return root;
}

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
      memcpy(root->data, temp->data, sizeof(temp->data));
      root->right_child = removing(root->right_child, temp->data, compare);
    }
  }
  return root;
}

void inorder(struct node *root, void (*print)(void *data)) {
  if (root != NULL) // checking if the root is not null
  {
    inorder(root->left_child, print);  // visiting left child
    print(root->data); // printing data at root
    inorder(root->right_child, print); // visiting right child
  }
}
