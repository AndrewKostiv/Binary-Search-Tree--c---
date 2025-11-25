#pragma once
#include <iostream>
struct BSNode
{
    int data;
    BSNode *left = nullptr;
    BSNode *right = nullptr;
    BSNode() {};
    BSNode(int data)
    {
        this->data = data;
    };
};

class BSTree
{
private:
    BSNode *root = nullptr;

    bool insertNode(BSNode *current, BSNode *newNode);
    bool removeNode(BSNode *parent, BSNode *node);
    void printRecursive(const BSNode *thisNode) const;
    BSNode *searchRecursive(BSNode *node, int key) const;
    BSNode *getParentRecursive(BSNode *subtreeRoot, const BSNode *node) const;

public:
    BSTree(/* args */);
    ~BSTree();
    bool insert(int data);
    bool remove(int data);
    bool deleteNode(BSNode &thisNode);
    void printTree() const;
    BSNode *search(int key) const;
    BSNode *getRoot() const;
    BSNode *getParent(BSNode *node) const;
};
