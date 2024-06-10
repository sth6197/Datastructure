#include <iostream>

using namespace std;

template <typename T>
class SingleLinkedList
{
private:
    int size;

    struct Node
    {
        T data;
        Node* next;
    };

    Node* head;

public:
    void SingleLingkedList()
    {
        size = 0;
        head = nullptr;
    }

    void PushFront(T data)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node* newnode = new Node;
            newnode->next = head;
            newnode->data = data;
            head = newnode;
        }
        size++;
    }

    void Show()
    {
        Node* crntnode = head;

        while(crntnode != nullptr)
        {
            cout << crntnode->data << endl;
            crntnode = crntnode->next;
        }
    }

};

int main()
{
    SingleLinkedList<int> single;




}