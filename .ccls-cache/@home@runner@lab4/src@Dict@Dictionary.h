#ifndef Dictionary_header
#define Dictionary_header

#include "../BST/BinarySearchTree.h"

struct dictionary{
  struct node *root;
  int (*compare)(void *data_one, void *data_two);
  void (*insert)(struct dictionary *dictionary, char *key, void *value, unsigned long value_size);
  struct keyvalue * (*search)(struct dictionary *dictionary, char *key);
  void (*remove)(struct dictionary *dictionary, char *key);
  void (*print)(void* data);
};

struct dictionary dictionary_constructor(int (*compare)(void *entry_one, void *entry_two), void (*print)(void* data));
void dictionary_destructor(struct dictionary *dictionary);
void dictionary_print(struct dictionary *dictionary);
void print_keyvalues(void* data);

#endif
