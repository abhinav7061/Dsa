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

int findDist(node *root, int n, int dist)
{
    if (root == NULL)
        return -1;
    if (root->data == n)
    {
        return dist;
    }
    int left = findDist(root->left, n, dist + 1);
    if (left != -1)
    {
        return left;
    }
    return findDist(root->right, n, dist + 1);
}

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

int distance(node *root, int n1, int n2)
{
    node *lca = LCA(root, n1, n2);
    // If we reach here, then there is
    // no common ancestor. So, return
    // -1 from here */
    if (!lca)
        return -1;
    /* Now, calculate the distances of
    two nodes from the LCA and add them
    to get the final result.*/
    int dist1 = findDist(lca, n1, 0), dist2 = findDist(lca, n2, 0);

    return dist1 + dist2;
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

    cout << "The distance between the given node is " << distance(root, 5, 1) << endl;

    return 0;
}