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

Node *buildTreeUtil(int preorder[], int preStart, int preEnd, int inorder[], int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    if (preStart == preEnd)
    {
        Node *leaf = new Node(preorder[preStart]);
        return leaf;
    }

    int rootValue = preorder[preStart];
    int rootIndex;
    for (rootIndex = inStart; rootIndex <= inEnd; rootIndex++)
    {
        if (inorder[rootIndex] == rootValue)
            break;
    }

    Node *root = new Node(rootValue);
    int leftSubtreeSize = rootIndex - inStart;

    /* Create a node with this data and recur for left subtree and right subtree */
    root->left = buildTreeUtil(preorder, preStart + 1, preStart + leftSubtreeSize, inorder, inStart, rootIndex - 1);
    root->right = buildTreeUtil(preorder, preStart + leftSubtreeSize + 1, preEnd, inorder, rootIndex + 1, inEnd);

    return root;
}

Node *buildTree(int preorder[], int inorder[], int inStart, int inEnd, int &preIndex)
{
    if (inStart > inEnd)
    {
        return nullptr;
    }

    int rootValue = preorder[preIndex++];
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

    root->left = buildTree(preorder, inorder, inStart, rootIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, rootIndex + 1, inEnd, preIndex);

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
    int preorder[] = {1, 2, 4, 5, 3};
    int nPreorder = sizeof(preorder) / sizeof(preorder[0]);

    int inorder[] = {4, 2, 5, 1, 3};
    int nInorder = sizeof(inorder) / sizeof(inorder[0]);
    int idx = 0;

    Node *root = buildTree(preorder, inorder, 0, nInorder - 1, idx);
    // The constructed Tree is
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5

    printPostOrder(root);
    cout << endl;

    return 0;
}
