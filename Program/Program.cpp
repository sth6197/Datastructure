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
    SingleLinkedList()
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
            Node* newNode = new Node;

            newNode->data = data;
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

            head = deleteNode->next;

            delete deleteNode;

            size--;
        }
    }

    void PushBack(T data)
    {
        if (head == nullptr)
        {
            head = new Node;

            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node* currentNode = head;

            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            Node* newNode = new Node;

            currentNode->next = newNode;

            newNode->data = data;
            newNode->next = nullptr;
        }

        size++;
    }

    void PopBack()
    {
        if (head == nullptr)        // head가 nullptr이라면
        {
            cout << "Linked List is Empty" << endl;     // 출력
        }
        else
        {
            Node* deleteNode = head;        // deleteNode가 head를 가리킴
            Node* previousNode = nullptr;   // previousNode의 기본값 nullptr

            if (size == 1)
            {
                head = deleteNode->next;    // head를 deleteNode.next 로 넘김

                delete deleteNode;          // deleteNode 삭제
            }
            else
            {
                while (deleteNode->next != nullptr) // deleteNode의 next가 nullptr이 아니라면 반복
                {
                    previousNode = deleteNode;      // 이전 노드를 기억하고 
                    deleteNode = deleteNode->next;  // deleteNode의 위치를 next로
                }

                previousNode->next = deleteNode->next;  // 위치 기억

                delete deleteNode;                      // deleteNode 삭제
            }
            size--;                                     // 값 다운
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


};

int main()
{
    SingleLinkedList<int> singleLinkedList;

    singleLinkedList.PushBack(10);
    singleLinkedList.PushBack(20);
    singleLinkedList.PushBack(30);

    singleLinkedList.PopBack();

    //singleLinkedList.PopFront();

    singleLinkedList.Show();

    return 0;
}