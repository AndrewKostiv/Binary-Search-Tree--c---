#include "BSTree.h"

// =============================

// Constructor & Destructor

// =============================

BSTree::BSTree()
{
    BSNode *root = nullptr;
}

BSTree::~BSTree() {}

// =============================

// insert

// =============================
bool BSTree::insert(int data)
{
    BSNode *node = new BSNode(data);
    if (!root)
    {
        root = node;
        return true;
    }
    else
    {
        return insertNode(root, node);
    }
    return false;
}

bool BSTree::insertNode(BSNode *parent, BSNode *nodeToInsert)
{
    if (nodeToInsert->data < parent->data)
    {
        if (!parent->left)
        {
            parent->left = nodeToInsert;
            return true;
        }
        else
            return insertNode(parent->left, nodeToInsert);
    }
    else
    {
        if (!parent->right)
        {
            parent->right = nodeToInsert;
            return true;
        }
        else
            return insertNode(parent->right, nodeToInsert);
    }
    return false;
}

// =============================

// print

// =============================

void BSTree::printTree() const
{
    if (!root)
    {
        std::cout << "no root" << std::endl;
    }

    printRecursive(this->root);
}

void BSTree::printRecursive(const BSNode *currentNode) const
{
    if (currentNode == nullptr)
    {
        return;
    }
    std::cout << currentNode->data << std::endl;
    printRecursive(currentNode->left);
    printRecursive(currentNode->right);
}

// =============================

// Remove

// =============================
bool BSTree::remove(int key)
{
    BSNode *node = search(key);
    BSNode *parent = getParent(node);
    return removeNode(parent, node);
}

bool BSTree::removeNode(BSNode *parent, BSNode *node)

{
    if (node == nullptr)
    {
        return false;
    }

    // Case 1: Internal node with 2 children
    if (node->left && node->right)
    {
        // Find successor and successor's parent
        BSNode *successorNode = node->right;
        BSNode *successorParent = node;
        while (successorNode->left)
        {
            successorParent = successorNode;
            successorNode = successorNode->left;
        }

        // Copy the key from the successor node
        node->data = successorNode->data;

        // Recursively remove successor node
        removeNode(successorParent, successorNode);
    }

    // Case 2: Root node (with 1 or 0 children)
    else if (node == root)
    {
        if (node->left)
        {
            root = node->left;
        }
        else
        {
            root = node->right;
        }
    }

    // Case 3: Internal with left child only
    else if (node->left)
    {
        // Replace node with node's left child
        if (parent->left == node)
        {
            parent->left = node->left;
        }
        else
        {
            parent->right = node->left;
        }
    }

    // Case 4: Internal with right child only OR leaf
    else
    {
        // Replace node with node's right child
        if (parent->left == node)
        {
            parent->left = node->right;
        }
        else
        {
            parent->right = node->right;
        }
    }

    return true;
}

// =============================

// Getters & Setters

// =============================
BSNode *BSTree::getRoot() const
{
    return this->root;
}

// =============================

// Search

// =============================

BSNode *BSTree::search(int key) const
{
    return searchRecursive(root, key);
}

BSNode *BSTree::searchRecursive(BSNode *node, int key) const
{
    if (node)
    {
        if (key == node->data)
        {
            return node;
        }
        else if (key < node->data)
        {
            return searchRecursive(node->left, key);
        }
        else
        {
            return searchRecursive(node->right, key);
        }
    }
    return nullptr;
}
// =============================

// getParent

// =============================
BSNode *BSTree::getParent(BSNode *node) const
{
    return getParentRecursive(root, node);
}

BSNode *BSTree::getParentRecursive(BSNode *subtreeRoot, const BSNode *node) const
{
    if (subtreeRoot == nullptr)
        return nullptr;

    if (subtreeRoot->left == node ||
        subtreeRoot->right == node)
    {
        return subtreeRoot;
    }

    if (node->data < subtreeRoot->data)
    {
        return getParentRecursive(subtreeRoot->left, node);
    }
    return getParentRecursive(subtreeRoot->right, node);
}
