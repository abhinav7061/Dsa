#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : data(val), left(left), right(right) {}
};

TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode *buildBST(int preorder[], int n)
{
    if (n == 0)
        return nullptr;
    TreeNode *root = new TreeNode(preorder[0]);
    for (int i = 1; i < n; i++)
    {
        insert(root, preorder[i]);
    }
    return root;
}

void printInOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

bool isIdentical(TreeNode *bst1, TreeNode *bst2)
{
    if (bst1 == nullptr && bst2 == nullptr)
        return true;
    else if (bst1 == nullptr || bst2 == nullptr)
        false;

    return (bst1->data == bst2->data) && isIdentical(bst1->left, bst2->left) && isIdentical(bst1->right, bst2->right);
}

int main()
{
    int preorder[] = {7, 5, 4, 6, 8, 9};
    // int preorder2[] = {7, 5, 4, 6, 9, 8, 10, 11};
    // The BST will look like:
    //      7
    //     /  \
    //    5    8
    //   / \      \
    // 4   6      9
    int n = sizeof(preorder) / sizeof(preorder[0]);
    // int n2 = sizeof(preorder2) / sizeof(preorder2[0]);
    TreeNode *bst1 = buildBST(preorder, n);
    TreeNode *bst2 = buildBST(preorder, n);
    printInOrder(bst1);
    cout << endl;
    printInOrder(bst2);
    cout << endl;
    cout << isIdentical(bst1, bst2) << endl;

    return 0;
}
