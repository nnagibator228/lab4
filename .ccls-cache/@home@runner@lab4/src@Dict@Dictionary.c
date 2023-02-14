#include "Dictionary.h"
#include "../Common/Keyvalue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_dict(struct dictionary *dictionary, char *key, void *value, unsigned long value_size);
struct keyvalue * search_dict(struct dictionary *dictionary, char *key);
void remove_dict(struct dictionary *dictionary, char *key);
void recursive_dictionary_destroy(struct node *root);
void print_dict(struct dictionary *dictionary, void (*type_print)(void* data));

struct dictionary dictionary_constructor(int (*compare)(void *entry_one, void *entry_two), void (*print)(void* data)){
  struct dictionary dict;
  dict.compare = compare;
  dict.insert = insert_dict;
  dict.search = search_dict;
  dict.remove = remove_dict;
  dict.print = print;
  dict.root = NULL;
  return dict;
}

void dictionary_destructor(struct dictionary *dictionary){
  recursive_dictionary_destroy(dictionary->root);
  dictionary->root = NULL;
}

void recursive_dictionary_destroy(struct node *root){
    if (root->left_child)
    {
        recursive_dictionary_destroy(root->left_child);
    }
    if (root->right_child)
    {
        recursive_dictionary_destroy(root->right_child);
    }
    keyvalue_destructor((struct keyvalue *)root->data);
    free(root->data);
    free(root);
}

void insert_dict(struct dictionary *dictionary, char *key, void *value, unsigned long value_size){
  struct keyvalue *keyval = keyvalue_constructor(key, value, value_size);
  dictionary->root = insert(dictionary->root, keyval, sizeof(struct keyvalue), dictionary->compare);
}

struct keyvalue *search_dict(struct dictionary *dictionary, char *key){
  int dummy_val = 0;
  struct keyvalue *searched = keyvalue_constructor(key, &dummy_val, sizeof(dummy_val));
  struct node *result = search(dictionary->root, searched, dictionary->compare);
  if (result){
    struct keyvalue *res_keyval = result->data;
    return res_keyval;
  }
  else{
    return NULL;
  }
}

void remove_dict(struct dictionary *dictionary, char *key){
  int dummy_val = 0;
  struct keyvalue *deleted = keyvalue_constructor(key, &dummy_val, sizeof(dummy_val));
  dictionary->root = removing(dictionary->root, deleted, dictionary->compare);
}

void dictionary_print(struct dictionary *dictionary){
  inorder(dictionary->root, dictionary->print);
}

void print_keyvalues(void* data){
  struct keyvalue *kv = (struct keyvalue *)data;
  size_t len = strlen(kv->key);
  for(int i=0; i<len; ++i){
    printf("%c", kv->key[i]);
  }
  printf(" - ");
  printf("%lf\n", *(double*)(kv->value));

}
