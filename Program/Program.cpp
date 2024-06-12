#include <iostream>

using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
    int size;

    struct Node
    {
        T data;
        Node* next;
        Node* previous;
    };

    Node* head;
    Node* tail;

public:
    DoubleLinkedList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void PushBack(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (tail == nullptr)
        {
            tail = newNode;     
            head = tail;
        } 
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        size++;
    }

    void PopBack()
    {

        if (tail == nullptr)
        {
            cout << "Linked List Empty" << endl;
        }
        else
        {  
            Node* deleteNode = tail;

            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;

                delete deleteNode;
            }
            else
            {
                tail->previous->next = nullptr;
                tail = tail->previous;
                delete deleteNode;
            }
            size--;
        }
    }

    void PushFront(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->previous = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    int &Size()
    {
        return size;
    }

    void Show()
    {
        Node* currentNode = head;

        while (currentNode != nullptr)
        {
            cout << currentNode->data << endl;

            currentNode = currentNode->next;
        }
    }



};

int main()
{
    DoubleLinkedList<int> Double;

    Double.PushFront(10);
    Double.PushFront(20);
    Double.PushFront(30);

    cout << "Double Linked List의 Size : " << Double.Size() << endl;
    //Double.PopBack();

    Double.Show();

    return 0;
}