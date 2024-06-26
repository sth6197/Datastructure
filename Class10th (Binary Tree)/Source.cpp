#include <iostream>

using namespace std;

struct Node
{
    int data;

    Node* left;
    Node* right;
};

Node* CreateNode(int data, Node* left, Node* right)
{
    Node* newnode = new Node;

    newnode->data = data;
    newnode->left = left;
    newnode->right = right;

    return newnode;
}

void Tree()
{
    Node* Node7 = CreateNode(7, nullptr, nullptr);
    Node* Node6 = CreateNode(6, nullptr, nullptr);
    Node* Node5 = CreateNode(5, nullptr, nullptr);
    Node* Node4 = CreateNode(4, nullptr, nullptr);
    Node* Node3 = CreateNode(3, Node6, Node7);
    Node* Node2 = CreateNode(2, Node4, Node5);
    Node* Node1 = CreateNode(1, Node2, Node3);
}

void Preorder(Node* root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void inorder(Node* root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void Postorder(Node* root)
{
    if (root != nullptr)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node* Node7 = CreateNode(7, nullptr, nullptr);
    Node* Node6 = CreateNode(6, nullptr, nullptr);
    Node* Node5 = CreateNode(5, nullptr, nullptr);
    Node* Node4 = CreateNode(4, nullptr, nullptr);
    Node* Node3 = CreateNode(3, Node6, Node7);
    Node* Node2 = CreateNode(2, Node4, Node5);
    Node* Node1 = CreateNode(1, Node2, Node3);

    // 전위 순회
    // Preorder(Node1);

    // 중위 순회
    // inorder(Node1);

    // 후위 순회
    // Postorder(Node1);

    return 0;
}