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

// using stack
void zigZagTraverse(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> currLevel;
    stack<TreeNode *> nextLevel;
    bool leftToRight = true;
    currLevel.push(root);
    while (!currLevel.empty())
    {
        TreeNode *node = currLevel.top();
        currLevel.pop();
        if (node != nullptr)
        {
            cout << node->data << " ";
            if (leftToRight)
            {
                if (node->left != nullptr)
                    nextLevel.push(node->left);
                if (node->right != nullptr)
                    nextLevel.push(node->right);
            }
            else
            {
                if (node->right != nullptr)
                    nextLevel.push(node->right);
                if (node->left != nullptr)
                    nextLevel.push(node->left);
            }
        }
        if (currLevel.empty())
        {
            cout << endl;
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

// using queue
void zigZagTraverseQueue(TreeNode *root)
{
    if (root == nullptr)
        return;

    vector<vector<int>> ans;
    queue<TreeNode *> q{{root}};
    bool isLeftToRight = true;

    while (!q.empty())
    {
        const int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = q.front();
            q.pop();
            const int index = isLeftToRight ? i : size - i - 1;
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << endl;
        isLeftToRight = !isLeftToRight;
    }
}

int main()
{
    int preorder[] = {7, 5, 4, 6, 8, 9};
    // int preorder[] = {7, 5, 11, 10, 13, 34, 12};
    // The BST will look like:
    //      7
    //     /  \
    //    5    8
    //   / \      \
    // 4   6      9
    int n = sizeof(preorder) / sizeof(preorder[0]);
    TreeNode *bst = buildBST(preorder, n);

    // Printing the bst zig-zag order Traversal
    zigZagTraverse(bst);
    zigZagTraverseQueue(bst);
    return 0;
}
