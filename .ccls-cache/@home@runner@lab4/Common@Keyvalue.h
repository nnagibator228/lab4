#ifndef Keyvalue_header
#define Keyvalue_header

struct keyvalue {
  char *key;
  void *value;
};

struct keyvalue *keyvalue_constructor(char* key, void *value, unsigned long size);
struct keyvalue keyvalue_destructor(struct keyvalue *keyval);

#endif