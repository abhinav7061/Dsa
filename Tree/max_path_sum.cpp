/*
    A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

    The path sum of a path is the sum of the node's values in the path.

    Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/

// A program to find the distance between two node. Distance is equal to minimum number of edges to reach from one node to anohter one

#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int maxSumPathUtil(TreeNode *root, int &ans)
{
    if (root == nullptr)
    {
        return 0;
    }
    int maxLeft = max(0, maxSumPathUtil(root->left, ans));
    int maxRight = max(0, maxSumPathUtil(root->right, ans));
    ans = max(ans, maxLeft + maxRight + root->data);

    return root->data + max(maxLeft, maxRight);
}

int maxSumPath(TreeNode *root)
{
    int ans = INT8_MIN;
    maxSumPathUtil(root, ans);
    return ans;
}

int main()
{
    struct TreeNode *root = new TreeNode(1); // root node with value  1

    /* create the tree shown in below diagram. */
    root->left = new TreeNode(-2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(7);
    /*
        The tree will look like:
              1
             /  \
           -2    3
          / \     / \
         4  5  -6  7
    */
    cout << maxSumPath(root) << endl;

    return 0;
}