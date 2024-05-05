#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void printPostOrder(struct Node *root)
{
    if (root == nullptr)
        return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

void printPreOrder(struct Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

Node *buildTree(int postorder[], int inorder[], int inStart, int inEnd, int &postIndex)
{
    if (inStart > inEnd)
    {
        return nullptr;
    }

    int rootValue = postorder[postIndex--];
    Node *root = new Node(rootValue);

    if (inStart == inEnd)
    {
        return root;
    }

    int rootIndex;
    for (rootIndex = inStart; rootIndex <= inEnd; rootIndex++)
    {
        if (inorder[rootIndex] == rootValue)
            break;
    }

    root->right = buildTree(postorder, inorder, rootIndex + 1, inEnd, postIndex);
    root->left = buildTree(postorder, inorder, inStart, rootIndex - 1, postIndex);

    return root;
}

// Driver code to test above functions
int main()
{
    // Let us create the following tree
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    int postorder[] = {4, 5, 2, 3, 1};
    int nPostorder = sizeof(postorder) / sizeof(postorder[0]);

    int inorder[] = {4, 2, 5, 1, 3};
    int nInorder = sizeof(inorder) / sizeof(inorder[0]);
    int idx = nPostorder - 1;

    Node *root = buildTree(postorder, inorder, 0, nInorder - 1, idx);
    // The constructed Tree is
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5

    // printPostOrder(root);
    printPreOrder(root);
    cout << endl;

    return 0;
}

