#include "Keyvalue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct keyvalue *keyvalue_constructor(char* key, void *value, unsigned long size){
  struct keyvalue *keyval;
  keyval = malloc(sizeof(struct keyvalue));
  keyval->key = malloc(sizeof(key));
  memcpy(keyval->key, key, sizeof(char*));
  keyval->value = malloc(size);
  memcpy(keyval->value, value, size);
  return keyval;
}

struct keyvalue keyvalue_destructor(struct keyvalue *keyval){
  free(keyval->key);
  free(keyval->value);
}
