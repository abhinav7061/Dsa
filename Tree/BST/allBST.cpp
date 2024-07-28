#include <iostream>
#include <vector>
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

vector<TreeNode *> constructTrees(int start, int end)
{
    vector<TreeNode *> trees;
    if (start > end)
    {
        trees.push_back(nullptr);
        return trees;
    }

    for (size_t i = start; i <= end; i++)
    {
        vector<TreeNode *> leftSubtrees = constructTrees(start, i - 1);
        vector<TreeNode *> rightSubtrees = constructTrees(i + 1, end);

        for (TreeNode *left : leftSubtrees)
        {
            for (TreeNode *right : rightSubtrees)
            {
                TreeNode *root = new TreeNode(i);
                root->left = left;
                root->right = right;
                trees.emplace_back(root);
            }
        }
    }

    return trees;
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
    vector<TreeNode *> allTrees = constructTrees(1, 5);
    for (size_t i = 0; i < allTrees.size(); i++)
    {
        cout << (i + 1) << ": ";
        printPreOrder(allTrees[i]);
        cout << endl;
    }

    return 0;
}
