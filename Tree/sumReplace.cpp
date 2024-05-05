#include <iostream>
#include <stack>
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

void printPreOrder(struct node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void sumReplace(struct node *root)
{
    if (root == nullptr)
    {
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);
    if (root->left != nullptr)
    {
        root->data += root->left->data;
    }
    if (root->right != nullptr)
    {
        root->data += root->right->data;
    }
}

int main()
{
    struct node *root = new node(1); // root node with value  1

    /* create the tree shown in below diagram. */
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    // The tree will look like:
    //      1
    //     /  \
    //    2    3
    //   / \     / \
    // 4   5   6  7
    // Printing the tree using Preorder, Inorder and Postorder Traversal
    cout << "Preorder traversal of the constructed tree is : ";
    printPreOrder(root); // Output: 1 2 4 5 3 6 7
    sumReplace(root);
    // After Sum Replace the tree will look like:
    //     28
    //     /  \
    //   11    16
    //   / \     / \
    // 4   5   6  7
    cout << "\nPreorder traversal of the tree replaced with sum of all subtree's nodes is : ";
    printPreOrder(root); // Output: 28 11 4 5 16 6 7
    cout<<endl;
    return 0;
}