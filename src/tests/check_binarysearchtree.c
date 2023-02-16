#include <check.h>
#include "../BST/BinarySearchTree.h"
#include "../Common/Compare.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

START_TEST(test_bst_search_existing_data) {
  int val1 = 20;
  int val2 = 5;
  int val3 = 1;
  int val4 = 15;
  int val5 = 9;
  struct node *root;
  root = new_node(&val1, sizeof(val1));
  insert(root,&val2,sizeof(val2),compare);
  insert(root,&val3,sizeof(val3),compare);
  insert(root,&val4,sizeof(val4),compare);
  insert(root,&val5,sizeof(val5),compare);
  ck_assert_uint_eq(*(int *)search(root,&val1,compare)->data, val1);
} END_TEST

START_TEST(test_bst_search_nonexisting_data) {
  int val1 = 20;
  int val2 = 5;
  int val3 = 1;
  int val4 = 15;
  int val5 = 9;
  int val6 = 42;
  struct node *root;
  root = new_node(&val1, sizeof(val1));
  insert(root,&val2,sizeof(val2),compare);
  insert(root,&val3,sizeof(val3),compare);
  insert(root,&val4,sizeof(val4),compare);
  insert(root,&val5,sizeof(val5),compare);
  ck_assert_ptr_eq(search(root,&val6,compare), NULL);
} END_TEST

START_TEST(test_bst_insert_on_left) {
  int val1 = 20;
  int val2 = 5;
  struct node *root;
  root = new_node(&val1, sizeof(val1));
  insert(root,&val2,sizeof(val2),compare);
  ck_assert_uint_eq(*(int *)root->left_child->data, val2);
} END_TEST

START_TEST(test_bst_insert_on_right) {
  int val1 = 20;
  int val2 = 27;
  struct node *root;
  root = new_node(&val1, sizeof(val1));
  insert(root,&val2,sizeof(val2),compare);
  ck_assert_uint_eq(*(int *)root->right_child->data, val2);
} END_TEST

START_TEST(test_bst_insert_similar) {
  int val1 = 20;
  struct node *root;
  root = new_node(&val1, sizeof(val1));
  insert(root,&val1,sizeof(val1), compare);
  ck_assert_ptr_eq(root->right_child, NULL);
  ck_assert_ptr_eq(root->left_child, NULL);
} END_TEST

START_TEST(test_bst_remove_leaf) {
  int val1 = 20;
  int val2 = 5;
  int val3 = 1;
  int val4 = 15;
  int val5 = 9;
  int val6 = 42;
  struct node *root;
  root = new_node(&val1, sizeof(val1));
  insert(root,&val2,sizeof(val2),compare);
  insert(root,&val3,sizeof(val3),compare);
  insert(root,&val4,sizeof(val4),compare);
  insert(root,&val5,sizeof(val5),compare);
  ck_assert_uint_eq(*(int *)(search(root, &val2, compare)->left_child->data), val3);
  removing(root, &val3, compare);
  ck_assert_ptr_eq(search(root, &val2, compare)->left_child, NULL);
} END_TEST

START_TEST(test_bst_remove_single_child_node) {
  int val1 = 20;
  int val2 = 5;
  int val3 = 1;
  int val4 = 15;
  int val5 = 9;
  int val6 = 42;
  struct node *root;
  root = new_node(&val1, sizeof(val1));
  insert(root,&val2,sizeof(val2),compare);
  insert(root,&val3,sizeof(val3),compare);
  insert(root,&val4,sizeof(val4),compare);
  insert(root,&val5,sizeof(val5),compare);
  ck_assert_uint_eq(*(int *)(search(root, &val2, compare)->right_child->data), val4);
  removing(root, &val4, compare);
  ck_assert_uint_eq(*(int *)(search(root, &val2, compare)->right_child->data), val5);
} END_TEST

START_TEST(test_bst_remove_full_child_node) {
  int val1 = 20;
  int val2 = 5;
  int val3 = 1;
  int val4 = 15;
  int val5 = 9;
  int val6 = 42;
  struct node *root;
  root = new_node(&val1, sizeof(val1));
  insert(root,&val2,sizeof(val2),compare);
  insert(root,&val3,sizeof(val3),compare);
  insert(root,&val4,sizeof(val4),compare);
  insert(root,&val5,sizeof(val5),compare);
  ck_assert_uint_eq(*(int *)(search(root, &val1, compare)->left_child->data), val2);
  removing(root, &val2, compare);
  ck_assert_uint_eq(*(int *)(search(root, &val1, compare)->left_child->data), val5);
} END_TEST

START_TEST(test_bst_remove_nonexisting_node) {
  int val1 = 20;
  int val2 = 5;
  int val3 = 1;
  int val4 = 15;
  int val5 = 9;
  int val6 = 42;
  struct node *root;
  root = new_node(&val1, sizeof(val1));
  insert(root,&val2,sizeof(val2),compare);
  insert(root,&val3,sizeof(val3),compare);
  insert(root,&val4,sizeof(val4),compare);
  insert(root,&val5,sizeof(val5),compare);
  ck_assert_uint_eq(*(int *)(search(root, &val1, compare)->left_child->data), val2);
  removing(root, &val6, compare);
  ck_assert_uint_eq(*(int *)(search(root, &val1, compare)->left_child->data), val2);
} END_TEST

Suite *compare_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("BinarySearchTreeTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_bst_search_existing_data);
  tcase_add_test(tc_core, test_bst_search_nonexisting_data);
  tcase_add_test(tc_core, test_bst_insert_on_left);
  tcase_add_test(tc_core, test_bst_insert_on_right);
  tcase_add_test(tc_core, test_bst_insert_similar);
  tcase_add_test(tc_core, test_bst_remove_leaf);
  tcase_add_test(tc_core, test_bst_remove_single_child_node);
  tcase_add_test(tc_core, test_bst_remove_full_child_node);
  tcase_add_test(tc_core, test_bst_remove_nonexisting_node);
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
