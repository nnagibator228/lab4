#include <check.h>
#include "../Dict/Dictionary.h"
#include "../Common/Compare.h"
#include "../Common/Keyvalue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


START_TEST(test_dict_creation) {
  struct dictionary test = dictionary_constructor(compare_string_keys, print_keyvalues);
  int val1 = 12;
  char* key1 = "test";
  int val2 = 36;
  char* key2 = "kekw";
  struct keyvalue *kv1 = keyvalue_constructor(key1, &val1, sizeof(val1));
  struct keyvalue *kv2 = keyvalue_constructor(key2, &val2, sizeof(val2));
  ck_assert_uint_eq(test.compare(kv1, kv2), compare_string_keys(kv1, kv2));
} END_TEST

START_TEST(test_dict_destroy) {
  struct dictionary test = dictionary_constructor(compare_string_keys, print_keyvalues);
  double val6 = 4321.21;
  test.insert(&test, "allah", &val6, sizeof(val6));
  dictionary_destructor(&test);
  ck_assert_ptr_eq(test.search(&test, "allah"), NULL);
} END_TEST

START_TEST(test_dict_nonexisting_value_insertion) {
  struct dictionary test = dictionary_constructor(compare_string_keys, print_keyvalues);
  double val1 = 435.23;
  char* key1 = "test";
  test.insert(&test, key1, &val1, sizeof(val1));
  ck_assert_double_eq(*(double *)(((struct keyvalue *)test.root->data)->value), val1);
} END_TEST

START_TEST(test_dict_existing_value_insertion) {
  struct dictionary test = dictionary_constructor(compare_string_keys, print_keyvalues);
  double val1 = 435.23;
  double val2 = 213.98;
  char* key1 = "test";
  test.insert(&test, key1, &val1, sizeof(val1));
  ck_assert_double_eq(*(double *)(((struct keyvalue *)test.root->data)->value), val1);
  test.insert(&test, key1, &val2, sizeof(val2));
  ck_assert_double_eq(*(double *)(((struct keyvalue *)test.root->data)->value), val2);
} END_TEST

START_TEST(test_dict_existing_value_search) {
  struct dictionary test = dictionary_constructor(compare_string_keys, print_keyvalues);
  double val1 = 435.23;
  char* key1 = "test";
  test.insert(&test, key1, &val1, sizeof(val1));
  ck_assert_ptr_ne(test.search(&test, key1), NULL);
} END_TEST

START_TEST(test_dict_nonexisting_value_search) {
  struct dictionary test = dictionary_constructor(compare_string_keys, print_keyvalues);
  double val1 = 435.23;
  char* key1 = "test";
  test.insert(&test, key1, &val1, sizeof(val1));
  ck_assert_ptr_eq(test.search(&test, "gay"), NULL);
} END_TEST

START_TEST(test_dict_existing_value_deletion) {
  struct dictionary test = dictionary_constructor(compare_string_keys, print_keyvalues);
  double val1 = 435.23;
  double val2 = 213.98;
  char* key1 = "test";
  char* key2 = "jesus";
  test.insert(&test, key1, &val1, sizeof(val1));
  test.insert(&test, key2, &val2, sizeof(val2));
  test.remove(&test, key2);
  ck_assert_ptr_eq(test.search(&test, key2), NULL);
} END_TEST

START_TEST(test_dict_nonexisting_value_deletion) {
  struct dictionary test = dictionary_constructor(compare_string_keys, print_keyvalues);
  double val1 = 435.23;
  double val2 = 213.98;
  char* key1 = "test";
  char* key2 = "jesus";
  test.insert(&test, key1, &val1, sizeof(val1));
  test.insert(&test, key2, &val2, sizeof(val2));
  test.remove(&test, "nigger");
  ck_assert_ptr_ne(test.search(&test, key2), NULL);
  ck_assert_ptr_ne(test.search(&test, key1), NULL);
} END_TEST

START_TEST(test_dict_difftype_value_insertion) {
  struct dictionary test = dictionary_constructor(compare_string_keys, print_keyvalues);
  long long val1 = 4358923;
  int val2 = 213;
  char* key1 = "test";
  char* key2 = "jesus";
  test.insert(&test, key1, &val1, sizeof(val1));
  test.insert(&test, key2, &val2, sizeof(val2));
  ck_assert_uint_eq(*(int *)(test.search(&test, key2)->value), val2);
  ck_assert_double_eq(*(long long *)(test.search(&test, key1)->value), val1);
} END_TEST

Suite *compare_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("DictionaryTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_dict_creation);
  tcase_add_test(tc_core, test_dict_destroy);
  tcase_add_test(tc_core, test_dict_nonexisting_value_insertion);
  tcase_add_test(tc_core, test_dict_existing_value_insertion);
  tcase_add_test(tc_core, test_dict_existing_value_deletion);
  tcase_add_test(tc_core, test_dict_nonexisting_value_deletion);
  tcase_add_test(tc_core, test_dict_existing_value_search);
  tcase_add_test(tc_core, test_dict_nonexisting_value_search);
  tcase_add_test(tc_core, test_dict_difftype_value_insertion);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  Suite *s = compare_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

