// Flatten the given tree into the form of linked list in-place. After flattening, left of each node should point to NULL and right should contain next node in preorder sequence.
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

void flatten(node *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    if (root->left != NULL)
    {
        flatten(root->left);
        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node *t = root->right;
        while (t->right != nullptr)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
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
    // root->right->right->left = new node(8);
    /*
        The tree will look like:
              1
             /  \
            2    3
           / \   / \
         4   5 6  7
    */

    flatten(root);

    return 0;
}