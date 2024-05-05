#include <iostream>
#include <stack>
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

void iterativePreorder(node *root)
{
    if (root == nullptr)
        return;

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        node *curr = s.top();
        s.pop();
        cout << curr->data << " ";

        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
}

void printPreOrder(struct node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void iterativeInorder(node *root)
{
    if (root == nullptr)
        return;

    stack<node *> s;
    node *curr = root;

    while (curr != nullptr || !s.empty())
    {
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout << curr->data << " ";

        curr = curr->right;
    }
}

void printInOrder(struct node *root)
{
    if (root == nullptr)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void iterativePostorder(node *root)
{
    if (root == nullptr)
        return;

    stack<node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        node *curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }

    while (!s2.empty())
    {
        node *temp = s2.top();
        s2.pop();
        cout << temp->data << " ";
    }
}

void printPostOrder(struct node *root)
{
    if (root == nullptr)
        return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
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
    // Printing the tree using Preorder, Inorder and Postorder Traversal
    cout << "Preorder traversal of the constructed tree is : ";
    printPreOrder(root); // Output: 1 2 4 5 3 6 7
    cout << "\nInorder traversal of the constructed tree is : ";
    printInOrder(root); // Output: 4 2 5 1 6 3 7
    cout << "\nPostorder traversal of the constructed tree is : ";
    printPostOrder(root); // Output: 4 5 2 6 7 3 1
    return 0;
}