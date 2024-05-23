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

class BST
{
private:
    TreeNode *root;

    TreeNode *insert(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        if (root->data > val)
        {
            root->left = insert(root->left, val);
        }
        else
        {
            root->right = insert(root->right, val);
        }
        return root;
    }

    // Helper function to find the minimum value node in the BST
    TreeNode *findMin(TreeNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node in the BST
    TreeNode *deleteNode(TreeNode *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (value < node->data)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            // Node with only one child or no child
            if (node->left == nullptr)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode *temp = findMin(node->right);

            // Copy the inorder successor's content to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inOrderTraversal(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }

public:
    BST()
    {
        root = nullptr;
    }
    void insert(int val)
    {
        root = insert(root, val);
    }
    void inOrderTraversal()
    {
        inOrderTraversal(root);
        cout << endl;
    }
    bool search(int val)
    {
        TreeNode *temp = root;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return true;
            }
            else if (temp->data > val)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return false;
    }
    void deleteNode(int value)
    {
        root = deleteNode(root, value);
    }
};

int main()
{
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(3);
    bst.insert(7);
    bst.insert(15);
    bst.insert(30);
    bst.inOrderTraversal();
    cout << "Search for 15: " << (bst.search(15) ? "Found" : "Not Found") << endl; // Expected output: Found
    bst.deleteNode(15);
    bst.inOrderTraversal();
    cout << "Search for 15: " << (bst.search(15) ? "Found" : "Not Found") << endl; // Expected output: Found
    return 0;
}