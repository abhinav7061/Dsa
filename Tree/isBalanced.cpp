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

int getHeight(node *root)
{
    if (root == nullptr)
        return 0;
    else
        return max(getHeight(root->left), getHeight(root->right)) + 1;
}

bool isBalanced(node *root, int height)
{
    if (root == nullptr)
        return true;
    // Get the height of left and right subtree
    int lheight = getHeight(root->left);
    int rheight = getHeight(root->right);

    /* If difference between heights is more than 1, then tree is not balanced.
       Return false */
    if (abs(lheight - rheight) > 1)
        return false;

    /* Recur for each subtree. The condition is to ensure that heights of both
       subtrees are within allowed limit. */
    return isBalanced(root->left, height - 1) && isBalanced(root->right, height + 1);
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
    int height = 0;
    if (isBalanced(root, height))
    {
        cout << "The given tree is balanced\n";
    }
    else
    {
        cout << "The given tree is not balanced\n";
    }

    return 0;
}