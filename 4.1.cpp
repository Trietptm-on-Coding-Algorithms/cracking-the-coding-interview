#include <iostream>
#include "Binarytree.h"
#include "BinaryTreePrettyPrint.h"

using namespace std;

void treeInsert(BinaryTree *&root, int newItem)
{
    if (!root)
        root = new BinaryTree(newItem);
    else if (newItem < root->data)
        treeInsert(root->left, newItem);
    else
        treeInsert(root->right, newItem);
}

void buildTree(BinaryTree *&root)
{
    int values[] = {30, 20, 40, 35, 50, 41, 20, 10, 25, 5, 15, 55, 36, 19};

    for (int i = 0; i < 14; i++)
        treeInsert(root, values[i]);

}

int minDepth(BinaryTree *root)
{
    if (!root)
        return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int maxDepth(BinaryTree *root)
{
    if (!root)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

bool isBalanced(BinaryTree *root)
{
    return (maxDepth(root) - minDepth(root) < 1);
}

void test4_1()
{
    BinaryTree* root = 0;

    buildTree(root);
    printPretty(root, 1, 0, cout);
    cout << "min depth " << minDepth(root) << endl;
    cout << "max depth " << maxDepth(root) << endl;
    cout << "is balanced " << isBalanced(root) << endl;
}