#ifndef BinarySearchTree_header
#define BinarySearchTree_header

struct node {
  void *data;               
  struct node *right_child; 
  struct node *left_child;  
};

struct node *search(struct node *root, void* data, int (*compare)(void *data_one, void *data_two));
struct node *find_minimum(struct node *root);
struct node *new_node(void* data, unsigned long data_size);
struct node *insert(struct node *root, void* data, unsigned long data_size, int (*compare)(void *data_one, void *data_two));
struct node *removing(struct node *root, void *data, int (*compare)(void *data_one, void *data_two));
void inorder(struct node *root, void (*print)(void *data));

#endif