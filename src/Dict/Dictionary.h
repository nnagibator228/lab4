/*!
\file Dictionary.h
\brief Header-файл реализации структуры Словаря на базе Дерева Бинарного Поиска

Содерижит объявления функций, предназначенных для работы с реализованной структурой
*/

#ifndef Dictionary_header
#define Dictionary_header

#include "../BST/BinarySearchTree.h"

/*! \struct dictionary
    \brief Абстрактная структура словаря

    Использует структуры keyvalue и node для реализации словаря на базе бинарного дерева
*/
struct dictionary{
  /** Указатель на корневую ноду БДП */
  struct node *root;
  /** Указатель на функцию сравнения элементов keyvalue */
  int (*compare)(void *data_one, void *data_two);
  /** Указатель на функцию вставки нового элемента словаря в ДБП (назначается на основе приватнореализованной функции) */
  void (*insert)(struct dictionary *dictionary, char *key, void *value, unsigned long value_size);
  /** Указатель на функцию поиска элемента словаря в ДБП (назначается на основе приватнореализованной функции) */
  struct keyvalue * (*search)(struct dictionary *dictionary, char *key);
  /** Указатель на функцию удаления элемента словаря в ДБП (назначается на основе приватнореализованной функции) */
  void (*remove)(struct dictionary *dictionary, char *key);
  /** Указатель на функцию вывода элементов словаря */
  void (*print)(void* data);
};

struct dictionary dictionary_constructor(int (*compare)(void *entry_one, void *entry_two), void (*print)(void* data));
void dictionary_destructor(struct dictionary *dictionary);
void dictionary_print(struct dictionary *dictionary);
void print_keyvalues(void* data);

#endif
