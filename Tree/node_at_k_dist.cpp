// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node. You can return the answer in any order.

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void printInSubTree(node *root, int k)
{
    if (root == NULL || k < 0)
        return;

    // Print the node
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    // Recur for left and right
    printInSubTree(root->left, k - 1);
    printInSubTree(root->right, k - 1);
}

int printNodesAtK(node *root, node *target, int k)
{
    if (root == nullptr)
        return -1;

    if (root == target)
    {
        printInSubTree(root, k);
        return 0;
    }
    int dl = printNodesAtK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printInSubTree(root->right, k - dl - 2);
        }
        return dl + 1;
    }
    int dr = printNodesAtK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printInSubTree(root->left, k - dr - 2);
        }
        return dr + 1;
    }

    return -1;
}

int main()
{
    struct node *root = new node(1); // root node with value  1

    /* create the tree shown in below diagram. */
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->right = new node(8);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->left = new node(9);
    // root->right->right->left = new node(8);
    /*
        The tree will look like:
              1
             /  \
            2    3
           / \    / \
         4  5  6   7
          \         /
           8      9
    */

    printNodesAtK(root, root->left->left, 5);

    return 0;
}