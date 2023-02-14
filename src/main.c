#include "Dict/Dictionary.h"
#include "Common/Compare.h"
#include "Common/Keyvalue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// вывод чего-то там
void int_print(void *data){
  printf("value: %d\n", *(int*)(data));
}

/*!
\file
\brief XdXd JEee43esus... Заголов132очный файл с описанием классов. Тестовая версия #1

Д22анный фай1111л содержит в себе определения основных 
к12лассов, испоqsльзуемых в демонстрационной программе
*/
int main() {
  struct dictionary test = dictionary_constructor(compare_string_keys, print_keyvalues);
  double val1 = 12.213;
  char* key1 = "test";
  double val2 = 36.546;
  char* key2 = "kekw";
  double val3 = 20.312;
  char* key3 = "lol";
  double val4 = 67.874;
  char* key4 = "allah";
  test.insert(&test, key1, &val1, sizeof(val1));
  test.insert(&test, key2, &val2, sizeof(val2));
  test.insert(&test, key3, &val3, sizeof(val3));
  test.insert(&test, key4, &val4, sizeof(val4));
  int_print(test.search(&test, "test")->value);
  printf("--\n");
  dictionary_print(&test);
  printf("--\n");
  test.remove(&test, "kekw");
  dictionary_print(&test);
  printf("--\n");
  double val5 = 1234.12;
  test.insert(&test, "jesus", &val5, sizeof(val5));
  dictionary_print(&test);
  printf("--\n");
  double val6 = 4321.21;
  test.insert(&test, "jesus", &val6, sizeof(val6));
  dictionary_print(&test);
}
