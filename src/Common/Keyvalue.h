/*!
\file Keyvalue.h
\brief Header-файл реализации структуры keyvalue

Содерижит объявления структуры keyvalue и функций, предназначенных для взаимодействия с этой структурой
*/

#ifndef Keyvalue_header
#define Keyvalue_header

/*! \struct keyvalue
    \brief Структура, хранящая ключ строку и свободный указатель на значение

    Применяется в качестве объекта, хранящегося в поле data ДБП по указателю
*/
struct keyvalue {
  /** Ключ с которым ассоциируется хранимое в value значение */
  char *key;
  /** Значение, представленное указателем свободного типа */
  void *value;
};

struct keyvalue *keyvalue_constructor(char* key, void *value, unsigned long size);
struct keyvalue keyvalue_destructor(struct keyvalue *keyval);

#endif