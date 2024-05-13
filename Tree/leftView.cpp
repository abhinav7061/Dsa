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

void leftView(node *root)
{
    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        // Traverse all nodes of current level
        for (int i = 1; i <= n; ++i)
        {
            node *temp = q.front();
            q.pop();
            // Print the leftmost node at each level
            if (i == 1)
                cout << temp->data << " ";
            // Enqueue left and right children of current node
            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }
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
    // root->left->right->right = new node(9);
    root->right->left = new node(6);
    // root->right->left->left = new node(8);
    root->right->right = new node(7);
    /*
        The tree will look like:
              1
             /  \
            2    3
           / \   / \
         4   5 6  7
    */

    leftView(root);

    return 0;
}