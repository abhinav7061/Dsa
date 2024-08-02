#include <iostream>
using namespace std;

#define defaultNodeDetails {INT32_MAX, INT32_MIN, 0, 0, true}

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : data(val), left(left), right(right) {}
};

struct nodeDetails
{
    int min;
    int max;
    int size;
    int ans;
    bool isBST;
};

nodeDetails largestBSTinBTDetails(TreeNode *root)
{
    if (root == nullptr)
        return defaultNodeDetails;
    if (root->left == nullptr && root->right == nullptr)
        return {root->data, root->data, 1, 1, true};

    nodeDetails leftDetails = largestBSTinBTDetails(root->left);
    nodeDetails rightDetails = largestBSTinBTDetails(root->right);

    nodeDetails curr;
    curr.size = leftDetails.size + rightDetails.size + 1;
    if (leftDetails.isBST && rightDetails.isBST && (root->data > leftDetails.max) && (root->data < rightDetails.min))
    {
        curr.min = min(root->data, min(leftDetails.min, rightDetails.min));
        curr.max = max(root->data, max(leftDetails.max, rightDetails.max));
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(leftDetails.ans, rightDetails.ans);
    curr.isBST = false;
    return curr;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(10);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(11);
    // The tree will look like
    //        5
    //      /    \
    //    3       8
    //   /  \     /  \
    //  1   4  7   10
    //              /  \
    //             9  11
    nodeDetails details = largestBSTinBTDetails(root);
    cout << "The largest BST has nodes " << details.ans << endl;
    return 0;
}