// Tree.h - Binary Search Tree for storing route/station metadata
#ifndef TREE_H
#define TREE_H

#include "Models.h"
#include <iostream>
using namespace std;

struct TreeNode
{
    int key;
    string data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int k, string d) : key(k), data(d), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    TreeNode *root;

    TreeNode *insertHelper(TreeNode *node, int key, string data)
    {
        if (node == nullptr)
            return new TreeNode(key, data);

        if (key < node->key)
            node->left = insertHelper(node->left, key, data);
        else if (key > node->key)
            node->right = insertHelper(node->right, key, data);
        else
            node->data = data; // Update existing

        return node;
    }

    TreeNode *searchHelper(TreeNode *node, int key)
    {
        if (node == nullptr || node->key == key)
            return node;

        if (key < node->key)
            return searchHelper(node->left, key);
        return searchHelper(node->right, key);
    }

    void inOrderHelper(TreeNode *node)
    {
        if (node != nullptr)
        {
            inOrderHelper(node->left);
            cout << "[" << node->key << ": " << node->data << "] ";
            inOrderHelper(node->right);
        }
    }

    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    TreeNode *deleteHelper(TreeNode *node, int key)
    {
        if (node == nullptr)
            return node;

        if (key < node->key)
            node->left = deleteHelper(node->left, key);
        else if (key > node->key)
            node->right = deleteHelper(node->right, key);
        else
        {
            if (node->left == nullptr)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }

            TreeNode *temp = minValueNode(node->right);
            node->key = temp->key;
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->key);
        }
        return node;
    }

public:
    BST() : root(nullptr) {}

    void insert(int key, string data)
    {
        root = insertHelper(root, key, data);
        cout << "Inserted [" << key << ": " << data << "] into BST.\n";
    }

    void search(int key)
    {
        TreeNode *result = searchHelper(root, key);
        if (result != nullptr)
            cout << "Found in BST: [" << result->key << ": " << result->data << "]\n";
        else
            cout << "Key " << key << " not found in BST.\n";
    }

    void inOrder()
    {
        cout << "BST In-Order Traversal: ";
        inOrderHelper(root);
        cout << "\n";
    }

    void remove(int key)
    {
        root = deleteHelper(root, key);
        cout << "Removed key " << key << " from BST.\n";
    }
};

#endif // TREE_H
