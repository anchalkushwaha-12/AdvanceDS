#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int countLeafNodes(Node* root)
{
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    int leftLeafCount = countLeafNodes(root->left);
    int rightLeafCount = countLeafNodes(root->right);

    return leftLeafCount + rightLeafCount;
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Number of leaf nodes in the binary tree: " << countLeafNodes(root) << endl;

    return 0;
}