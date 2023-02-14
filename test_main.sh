gcc src/Common/Compare.h src/Common/Compare.c src/Common/Keyvalue.h src/Common/Keyvalue.c src/BST/BinarySearchTree.h src/BST/BinarySearchTree.c src/Dict/Dictionary.h src/Dict/Dictionary.c src/main.c -lcheck -lm -lrt -lpthread -fdiagnostics-color=always -o main
chmod +x main
echo "Command execution content: "
./main
rm -f main