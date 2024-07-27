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

TreeNode *sortedArrayToBST(int sortedArray[], int start, int end)
{
    if (start > end)
        return nullptr;
    const int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(sortedArray[mid]);

    root->left = sortedArrayToBST(sortedArray, start, mid - 1);
    root->right = sortedArrayToBST(sortedArray, mid + 1, end);

    return root;
}

void printPreOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    int sortedArray[] = {4, 5, 6, 7, 8, 9};
    int n = sizeof(sortedArray) / sizeof(sortedArray[0]);
    TreeNode *bst = sortedArrayToBST(sortedArray, 0, n - 1);
    printPreOrder(bst);
    return 0;
}
