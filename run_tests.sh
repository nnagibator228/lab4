#!/bin/bash

gcc src/Common/Compare.h src/Common/Compare.c src/Common/Keyvalue.h src/Common/Keyvalue.c src/BST/BinarySearchTree.h src/BST/BinarySearchTree.c src/Dict/Dictionary.h src/Dict/Dictionary.c src/tests/check_compare.c -lcheck -lm -lrt -lpthread -lsubunit -o check_compare_unit_tests
gcc src/Common/Compare.h src/Common/Compare.c src/Common/Keyvalue.h src/Common/Keyvalue.c src/BST/BinarySearchTree.h src/BST/BinarySearchTree.c src/Dict/Dictionary.h src/Dict/Dictionary.c src/tests/check_keyvalue.c -lcheck -lm -lrt -lpthread -lsubunit -o check_keyvalue_unit_tests
gcc src/Common/Compare.h src/Common/Compare.c src/Common/Keyvalue.h src/Common/Keyvalue.c src/BST/BinarySearchTree.h src/BST/BinarySearchTree.c src/Dict/Dictionary.h src/Dict/Dictionary.c src/tests/check_binarysearchtree.c -lcheck -lm -lrt -lpthread -lsubunit -o check_binarysearchtree_unit_tests
gcc src/Common/Compare.h src/Common/Compare.c src/Common/Keyvalue.h src/Common/Keyvalue.c src/BST/BinarySearchTree.h src/BST/BinarySearchTree.c src/Dict/Dictionary.h src/Dict/Dictionary.c src/tests/check_dictionary.c -lcheck -lm -lrt -lpthread -lsubunit -o check_dictionary_unit_tests
chmod +x check_compare_unit_tests check_keyvalue_unit_tests check_binarysearchtree_unit_tests check_dictionary_unit_tests
./check_compare_unit_tests && ./check_keyvalue_unit_tests && ./check_binarysearchtree_unit_tests && ./check_dictionary_unit_tests
rm -f check_compare_unit_tests check_keyvalue_unit_tests check_binarysearchtree_unit_tests check_dictionary_unit_tests
