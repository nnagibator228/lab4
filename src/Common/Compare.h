/*!
\file Compare.h
\brief Header-файл функций compare

Содерижит объявления функций, предназначенных для сравнения значений, содержащихся в нодах ДБП
*/

#ifndef Compare_header
#define Compare_header

int compare(void *s1, void *s2);
int compare_string_keys(void *entry_one, void *entry_two);

#endif