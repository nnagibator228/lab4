gcc Common/Compare.h Common/Compare.c Common/Keyvalue.h Common/Keyvalue.c BST/BinarySearchTree.h BST/BinarySearchTree.c Dict/Dictionary.h Dict/Dictionary.c main.c -lcheck -lm -lrt -lpthread -fdiagnostics-color=always -o main
chmod +x main
echo "Command execution content: "
./main
rm -f main
