#include <iostream>

using namespace std;

template <typename T>
class CircleLinkedList
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
    CircleLinkedList()
    {
        size = 0;
        head = nullptr;
    }

    void PushBack(T data)
    {
        Node* newnode = new Node;
        newnode->data = data;

        if (head == nullptr)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            newnode->next = head->next;
            head->next = newnode;
            head = newnode;
        }
        size++;
    }

    void PushFront(T data)
    {
        Node* newnode = new Node;
        newnode->data = data;

        if (head == nullptr)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            newnode->next = head->next;
            head->next = newnode;
        }
        size++;
    }

    void PopFront()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deletenode = head->next;

            if (head == head->next)
            {
                head = nullptr;

                delete deletenode;
            }
            else
            {
                head->next = deletenode->next;    // head를 deletenode의 next로 넘겨주기
            }
            delete deletenode;

            size--;
        }
    }

    void PopBack()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deletenode = head;
            Node* currentnode = head;

            if (head == head->next)
            {
                head = nullptr;
            }
            else
            {
                for(int i = 0; i < size-1; i++)
                {
                    currentnode = currentnode->next;

                    currentnode->next = head->next;

                    head = currentnode;
                }
                delete deletenode;

                size--;
            }
        }
    }

    void Show()
    {
        if (head != nullptr)
        {
            Node* currentNode = head->next;

            for (int i = 0; i < size; i++)
            {
                cout << currentNode->data << endl;

                currentNode = currentNode->next;
            }
        }
    }

};


int main()
{
    CircleLinkedList<int> circle;

    circle.PushFront(10);
    circle.PushFront(20);
    circle.PushFront(30);
    circle.PushFront(99);

    circle.PopBack();


    circle.Show();

    return 0;
}