/*!
\file Keyvalue.c
\brief Основной файл функций keyvalue

Содерижит реализацию функций, предназначенных для взаимодействия с этой структурой
*/

#include "Keyvalue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Конструктор keyvalue
///
/// Конструктор для структуры keyvalue, динамически выделяющий память на соответственные поля
///
/// \param key ключ-строка
/// \param value указатель на значение 
/// \param size размер значения
/// \return keyval указатель на созданный экземпляр
//////////////////////////////////////////////////////////////////////////////////////////////////////
struct keyvalue *keyvalue_constructor(char* key, void *value, unsigned long size){
  struct keyvalue *keyval;
  keyval = malloc(sizeof(struct keyvalue));
  keyval->key = malloc(sizeof(key));
  memcpy(keyval->key, key, sizeof(char*));
  keyval->value = malloc(size);
  memcpy(keyval->value, value, size);
  return keyval;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Деструктор keyvalue
///
/// Деструктор для структуры keyvalue, очищает соответствующие поля 
///
/// \param keyval указатель на удаляемый экземпляр
//////////////////////////////////////////////////////////////////////////////////////////////////////
struct keyvalue keyvalue_destructor(struct keyvalue *keyval){
  free(keyval->key);
  free(keyval->value);
}
