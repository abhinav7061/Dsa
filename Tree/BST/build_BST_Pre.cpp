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

int main()
{
    int preorder[] = {7, 5, 4, 6, 8, 9};
    int n = sizeof(preorder) / sizeof(preorder[0]);
    TreeNode *bst = buildBST(preorder, n);
    printInOrder(bst);
    return 0;
}
