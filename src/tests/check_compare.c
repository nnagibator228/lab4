#include <check.h>
#include "../Common/Keyvalue.h"
#include "../Common/Compare.h"
#include <stdlib.h>
#include <stdio.h>

START_TEST(test_with_equal_vals_compare) {
  int a = 12;
  int b = 12;
  ck_assert_uint_eq(compare(&a,&b), 0);
} END_TEST

START_TEST(test_with_smaller_val_first_compare) {
  int a = 7;
  int b = 12;
  ck_assert_uint_eq(compare(&a,&b), -1);
} END_TEST

START_TEST(test_with_larger_val_first_compare) {
  int a = 15;
  int b = 12;
  ck_assert_uint_eq(compare(&a,&b), 1);
} END_TEST

START_TEST(test_with_negative_val_compare) {
  int a = -173;
  int b = 16;
  ck_assert_uint_eq(compare(&a,&b), -1);
} END_TEST

START_TEST(test_with_negative_vals_compare) {
  int a = -12;
  int b = -123;
  ck_assert_uint_eq(compare(&a,&b), 1);
} END_TEST

START_TEST(test_with_nill_val_compare) {
  int a = 0;
  int b = 12;
  ck_assert_uint_eq(compare(&a,&b), -1);
} END_TEST


START_TEST(test_with_equal_strings_keyval_by_str_compare) {
  double val1 = 12.213;
  char* key1 = "test";
  double val2 = 36.546;
  struct keyvalue *kv1 = keyvalue_constructor(key1, &val1, sizeof(val1));
  struct keyvalue *kv2 = keyvalue_constructor(key1, &val2, sizeof(val2));
  ck_assert_uint_eq(compare_string_keys(kv1, kv2), 0);
} END_TEST

START_TEST(test_with_greater_string_first_keyval_by_str_compare) {
  double val1 = 12.213;
  char* key1 = "test";
  double val2 = 36.546;
  char* key2 = "kek";
  struct keyvalue *kv1 = keyvalue_constructor(key1, &val1, sizeof(val1));
  struct keyvalue *kv2 = keyvalue_constructor(key2, &val2, sizeof(val2));
  ck_assert_uint_eq(compare_string_keys(kv1, kv2), 1);
} END_TEST

START_TEST(test_with_smaller_string_first_keyval_by_str_compare) {
  double val1 = 12.213;
  char* key1 = "test";
  double val2 = 36.546;
  char* key2 = "kek";
  struct keyvalue *kv1 = keyvalue_constructor(key2, &val1, sizeof(val1));
  struct keyvalue *kv2 = keyvalue_constructor(key1, &val2, sizeof(val2));
  ck_assert_uint_eq(compare_string_keys(kv1, kv2), -1);
} END_TEST

START_TEST(test_with_empty_string_first_keyval_by_str_compare) {
  double val1 = 12.213;
  char* key1 = "kkk";
  double val2 = 36.546;
  char* key2 = "";
  struct keyvalue *kv1 = keyvalue_constructor(key1, &val1, sizeof(val1));
  struct keyvalue *kv2 = keyvalue_constructor(key2, &val2, sizeof(val2));
  ck_assert_uint_eq(compare_string_keys(kv1, kv2), 1);
} END_TEST



Suite *compare_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("CompareTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_with_equal_vals_compare);
  tcase_add_test(tc_core, test_with_smaller_val_first_compare);
  tcase_add_test(tc_core, test_with_larger_val_first_compare);
  tcase_add_test(tc_core, test_with_negative_val_compare);
  tcase_add_test(tc_core, test_with_negative_vals_compare);
  tcase_add_test(tc_core, test_with_nill_val_compare);
  tcase_add_test(tc_core, test_with_equal_strings_keyval_by_str_compare);
  tcase_add_test(tc_core, test_with_greater_string_first_keyval_by_str_compare);
  tcase_add_test(tc_core, test_with_smaller_string_first_keyval_by_str_compare);
  tcase_add_test(tc_core, test_with_empty_string_first_keyval_by_str_compare);

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
