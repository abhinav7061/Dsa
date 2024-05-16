// A program to find the distance between two node. Distance is equal to minimum number of edges to reach from one node to anohter one
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

node *LCA(node *root, int n1, int n2)
{
    if (root == nullptr || root->data == n1 || root->data == n2)
        return root;

    node *left_lca = LCA(root->left, n1, n2);
    node *right_lca = LCA(root->right, n1, n2);

    if (left_lca != nullptr && right_lca != nullptr)
        return root;

    if (left_lca == nullptr && right_lca == nullptr)
        return nullptr;

    if (left_lca != nullptr)
        return LCA(root->left, n1, n2);

    return LCA(root->right, n1, n2);
};

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
    int n1 = 2;
    int n2 = 6;

    cout << "The LCA of " << n1 << " and " << n2 << " is " << LCA(root, n1, n2)->data << endl;

    return 0;
}