#include <check.h>
#include "../Common/Keyvalue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

START_TEST(test_keyval_value_doubletype_field) {
  double val1 = 12.213;
  char* key1 = "kkk";
  struct keyvalue *kv1 = keyvalue_constructor(key1, &val1, sizeof(val1));
  ck_assert_uint_eq(*((double*)(kv1->value)), val1);
} END_TEST

START_TEST(test_keyval_value_inttype_field) {
  int val1 = 15;
  char* key1 = "kkk";
  struct keyvalue *kv1 = keyvalue_constructor(key1, &val1, sizeof(val1));
  ck_assert_uint_eq(*((int*)(kv1->value)), val1);
} END_TEST

START_TEST(test_keyval_value_chartype_field) {
  char val1 = 'n';
  char* key1 = "kkk";
  struct keyvalue *kv1 = keyvalue_constructor(key1, &val1, sizeof(val1));
  ck_assert_uint_eq(*((char*)(kv1->value)), val1);
} END_TEST

START_TEST(test_keyval_value_pointertype_field) {
  double val1 = 12.213;
  double *pointer1 = &val1;
  char* key1 = "kkk";
  struct keyvalue *kv1 = keyvalue_constructor(key1, pointer1, sizeof(pointer1));
  ck_assert_uint_eq(*((double*)(kv1->value)), *pointer1);
} END_TEST

START_TEST(test_keyval_key_field) {
  double val1 = 12.231;
  char* key1 = "kkk";
  struct keyvalue *kv1 = keyvalue_constructor(key1, &val1, sizeof(val1));
  ck_assert_uint_eq(strcmp((char *)(kv1->key), (char *)(key1)), 0);
} END_TEST

START_TEST(test_keyval_key_empty_field) {
  double val1 = 12.231;
  char* key1 = "";
  struct keyvalue *kv1 = keyvalue_constructor(key1, &val1, sizeof(val1));
  ck_assert_uint_eq(strcmp((char *)(kv1->key), (char *)(key1)), 0);
} END_TEST

// any tests for destructor?

Suite *compare_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("KeyvalueTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_keyval_value_doubletype_field);
  tcase_add_test(tc_core, test_keyval_value_inttype_field);
  tcase_add_test(tc_core, test_keyval_value_chartype_field);
  tcase_add_test(tc_core, test_keyval_value_pointertype_field);
  tcase_add_test(tc_core, test_keyval_key_field);
  tcase_add_test(tc_core, test_keyval_key_empty_field);
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
