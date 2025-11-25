#include <iostream>
#include "BSTree/BSTree.h"
int main(int argc, char const *argv[])
{
    std::cout << "Start" << std::endl;
    BSTree *tree = new BSTree();
    tree->insert(1);
    tree->insert(1);
    std::cout << "Before remove" << std::endl;
    tree->printTree();
    tree->remove(1);
    std::cout << "After remove" << std::endl;
    tree->printTree();

    std::cout << "End" << std::endl;
    return 0;
}
