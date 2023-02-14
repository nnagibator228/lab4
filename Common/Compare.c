#include "Compare.h"
#include "Keyvalue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(void *s1, void *s2) {
  int *a = (int *)s1;
  int *b = (int *)s2;
  if ((*a) > (*b))
    return 1;
  else if ((*a) < (*b))
    return -1;
  else
    return 0;
}

int compare_string_keys(void *entry_one, void *entry_two){
    if (strcmp((char *)(((struct keyvalue *)entry_one)->key), (char *)(((struct keyvalue *)entry_two)->key)) > 0){
        return 1;
    }
    else if (strcmp((char *)(((struct keyvalue *)entry_one)->key), (char *)(((struct keyvalue *)entry_two)->key)) < 0){
        return -1;
    }
    else{
        return 0;
    }
}