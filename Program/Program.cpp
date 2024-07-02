#include <iostream>

using namespace std;

template <typename T>
class BinarySearchTree
{
private:
    struct Node
    {
        T data;

        Node* left;
        Node* right;
    };

    Node* root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    Node* Root()
    {
        return root;
    }

    Node* CreateNode(T data)
    {
        Node* newnode = new Node();
        newnode->data = data;
        newnode->left = nullptr;
        newnode->right = nullptr;

        return newnode;
    }

    void Insert(T data)
    {
        if (root == nullptr)
        {
            root = CreateNode(data);
        }
        else
        {
            Node* currentNode = root;

            while (currentNode != nullptr)
            {
                if (currentNode->data == data)
                {
                    return;
                }
                else if (currentNode->data > data)
                {
                    if (currentNode->left == nullptr)
                    {
                        currentNode->left = CreateNode(data);
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
                else
                {
                    if (currentNode->right == nullptr)
                    {
                        currentNode->right = CreateNode(data);
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
            }
        }
    }

    bool Find(T data)
    {
        Node* currentNode = root;

        if(currentNode == nullptr)
        {
            return false;
        }
        else
        {
            while (currentNode != nullptr)
            {
                if (currentNode->data == data)
                {
                    return true;
                }
                else
                {
                    if (currentNode->data > data)
                    {
                        currentNode = currentNode->left;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
            }

            return false;
        }
    }

    void Destroy(Node* root)
    {
        if (root != nullptr)
        {
            Destroy(root->left);
            Destroy(root->right);
            delete root;
        }
    }

    void Inorder(Node* root)
    {
        if (root != nullptr)
        {
            Inorder(root->left);
            cout << root->data << " ";
            Inorder(root->right);
        }
    }

    ~BinarySearchTree()
    {
        Destroy(root);
    }
};

int main()
{
    BinarySearchTree<int> binarysearchtree;

    binarysearchtree.Insert(10);
    binarysearchtree.Insert(7);
    binarysearchtree.Insert(15);
    binarysearchtree.Insert(5);

    binarysearchtree.Destroy(binarysearchtree.Root());

    cout << binarysearchtree.Find(10) << endl;
    cout << binarysearchtree.Find(0) << endl;

    binarysearchtree.Inorder(binarysearchtree.Root());

    return 0;
}