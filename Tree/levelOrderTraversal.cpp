#include <iostream>
#include <queue>
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

void printLevelOrder(struct node *root)
{
    if (root == nullptr)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *curr_node = q.front();
        cout << curr_node->data << " ";
        q.pop();
        if (curr_node->left != nullptr)
            q.push(curr_node->left);
        if (curr_node->right != nullptr)
            q.push(curr_node->right);
    }
}

void printNodeAtLevel(struct node *root, int level)
{
    if (root == nullptr)
        return;

    queue<pair<node *, int>> q;
    q.push({root, 1}); // Start with root at level 1

    while (!q.empty())
    {
        pair<node *, int> currPair = q.front();
        q.pop();

        node *currNode = currPair.first;
        int currLevel = currPair.second;

        if (currLevel == level)
        {
            cout << currNode->data << " ";
        }

        if (currNode->left != nullptr)
            q.push({currNode->left, currLevel + 1});

        if (currNode->right != nullptr)
            q.push({currNode->right, currLevel + 1});
    }
}

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
    // The tree will look like:
    //      1
    //     /  \
    //    2    3
    //   / \     / \
    // 4   5   6  7
    // Printing the tree using level order Traversal
    cout << "level traversal of the constructed tree is : ";
    printLevelOrder(root);
    cout << endl;
    cout << "traversal at level 2 of the constructed tree is : ";
    printNodeAtLevel(root, 2);
    cout << endl;
    return 0;
}