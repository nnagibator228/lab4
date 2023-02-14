#!/bin/bash

gcc Common/Compare.h Common/Compare.c Common/Keyvalue.h Common/Keyvalue.c BST/BinarySearchTree.h BST/BinarySearchTree.c Dict/Dictionary.h Dict/Dictionary.c tests/check_compare.c -lcheck -lm -lrt -lpthread -o check_compare_unit_tests
gcc Common/Compare.h Common/Compare.c Common/Keyvalue.h Common/Keyvalue.c BST/BinarySearchTree.h BST/BinarySearchTree.c Dict/Dictionary.h Dict/Dictionary.c tests/check_keyvalue.c -lcheck -lm -lrt -lpthread -o check_keyvalue_unit_tests
gcc Common/Compare.h Common/Compare.c Common/Keyvalue.h Common/Keyvalue.c BST/BinarySearchTree.h BST/BinarySearchTree.c Dict/Dictionary.h Dict/Dictionary.c tests/check_binarysearchtree.c -lcheck -lm -lrt -lpthread -o check_binarysearchtree_unit_tests
gcc Common/Compare.h Common/Compare.c Common/Keyvalue.h Common/Keyvalue.c BST/BinarySearchTree.h BST/BinarySearchTree.c Dict/Dictionary.h Dict/Dictionary.c tests/check_dictionary.c -lcheck -lm -lrt -lpthread -o check_dictionary_unit_tests
chmod +x check_compare_unit_tests check_keyvalue_unit_tests check_binarysearchtree_unit_tests check_dictionary_unit_tests
./check_compare_unit_tests && ./check_keyvalue_unit_tests && ./check_binarysearchtree_unit_tests && ./check_dictionary_unit_tests
rm -f check_compare_unit_tests check_keyvalue_unit_tests check_binarysearchtree_unit_tests check_dictionary_unit_tests
