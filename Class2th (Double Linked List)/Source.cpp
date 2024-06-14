#include <iostream>

using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
    int size;

    struct Node;    // 프로토타입 선언(선언만 하고 구현은 아직 안함)

    Node* head;
    Node* tail;

public:
    struct Node
    {
        T data;
        Node* next;
        Node* previous;
    };


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
            cout << "Linked List is Empty" << endl;
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

    void PopFront()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head;

            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                deleteNode->next->previous = nullptr;
                head = head->next;
            }
            delete deleteNode;

            size--;
        }
    }

    int& Size()
    {
        return size;
    }

    Node* Begin()
    {
        return head;
    }

    void Insert(Node* position, T data)
    {
        if (head == nullptr)
        {
            PushBack(data);
        }
        else
        {
            Node* previousNode = position;
            Node* nextNode = position->next;

            if (nextNode == nullptr)
            {
                PushBack(data);
            }
            else if (previousNode->previous == nullptr)
            {
                PushFront(data);
            }
            else
            {
                Node* newNode = new Node;
                newNode->data = data;

                previousNode->next = newNode;
                nextNode->previous = newNode;

                newNode->next = nextNode;
                newNode->previous = previousNode;

                size++;
            }
        }
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

    ~DoubleLinkedList()
    {
        while (head != nullptr)
        {
            PopFront();
        }
    }
};

int main()
{
    DoubleLinkedList<int> Double;

    Double.PushFront(10);
    Double.PushFront(20);
    Double.PushFront(30);

    Double.Insert(Double.Begin()->next, 99);

    cout << "Double Linked List의 Size : " << Double.Begin()->next << endl;

    cout << "Double Linked List의 Size : " << Double.Size() << endl;

    Double.~DoubleLinkedList();

    Double.Show();





    return 0;
}