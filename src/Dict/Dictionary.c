/*!
\file Dictionary.c
\brief Основной файл функций compare

Содерижит реализацию функций, предназначенных для взаимодействия с этой структурой
*/

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

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Конструктор dictionary
///
/// Конструктор для структуры dictionary, назначающий полям-указателям на функции соответствующие приватно определенные и передаваемые по указателю функции
///
/// \param compare указатель на функцию для сравнения хранимых данных
/// \param print указатель на функцию для вывода хранимых данных
/// \return dict созданный экземпляр
//////////////////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Деструктор dictionary
///
/// Деструктор для структуры dictionary, рекурсивно очищает ДБП внутри структуры
///
/// \param dictionary указатель на удаляемый экземпляр
//////////////////////////////////////////////////////////////////////////////////////////////////////
void dictionary_destructor(struct dictionary *dictionary){
  recursive_dictionary_destroy(dictionary->root);
  dictionary->root = NULL;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief рекурсивное удаление элементов ДБП
///
/// Рекурсивно удаляет элементы дерева бинарного поиска, вызывая деструктор keyvalue
///
/// \param root указатель на корень дерева
//////////////////////////////////////////////////////////////////////////////////////////////////////
void recursive_dictionary_destroy(struct node *root){
  if(root!=NULL){
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
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Добавление элемента в словарь
///
/// Распологает передаваемое значение по соответствующему передаваемому ключу в словаре
///
/// \param dictionary указатель на словарь
/// \param key строка-ключ
/// \param value указатель на записываемое значение
/// \param value размер записываемого значения
//////////////////////////////////////////////////////////////////////////////////////////////////////
void insert_dict(struct dictionary *dictionary, char *key, void *value, unsigned long value_size){
  struct keyvalue *keyval = keyvalue_constructor(key, value, value_size);
  dictionary->root = insert(dictionary->root, keyval, sizeof(struct keyvalue), dictionary->compare);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Поиск элемента в словаре
///
/// Ищет элемент по ключу в словаре
///
/// \param dictionary указатель на словарь
/// \param key строка-ключ
/// \return res_keyval указатель на найденный экземпляр keyvalue или NULL если элемент не найден
//////////////////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Удаление элемента в словаре
///
/// Удаляет элемент по ключу в словаре
///
/// \param dictionary указатель на словарь
/// \param key строка-ключ
//////////////////////////////////////////////////////////////////////////////////////////////////////
void remove_dict(struct dictionary *dictionary, char *key){
  int dummy_val = 0;
  struct keyvalue *deleted = keyvalue_constructor(key, &dummy_val, sizeof(dummy_val));
  dictionary->root = removing(dictionary->root, deleted, dictionary->compare);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Вывод содержимого словаря
///
/// Обходит все включенное в словарь ДБП и выводит его значения в соответствии с объявленной как поле структуры функции вывода
///
/// \param dictionary указатель на словарь
//////////////////////////////////////////////////////////////////////////////////////////////////////
void dictionary_print(struct dictionary *dictionary){
  inorder(dictionary->root, dictionary->print);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Вариант реализации функции вывода элементов словаря
///
/// Функцию можно применить для словарей, хранящих значения типа double*
///
/// \param data указатель, подразумевающий, что указывает на элемент keyvalue
//////////////////////////////////////////////////////////////////////////////////////////////////////
void print_keyvalues(void* data){
  struct keyvalue *kv = (struct keyvalue *)data;
  size_t len = strlen(kv->key);
  for(int i=0; i<len; ++i){
    printf("%c", kv->key[i]);
  }
  printf(" - ");
  printf("%lf / %lld\n", *(double*)(kv->value), *(long long*)(kv->value));

}
