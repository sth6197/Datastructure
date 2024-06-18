#include <iostream>

#define SIZE 5

using namespace std;

template <typename T>
class CircleQueue
{
private:
    int front;
    int rear;
    int size;

    T container[SIZE];

public:
    CircleQueue()
    {
        front = SIZE - 1;
        rear = SIZE - 1;
        size = 0;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = 0;
        }
    }

    bool Empty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Push(T data)
    {
        if (front == ((rear + 1) % SIZE))
        {
            cout << "Circle Queue is Overflow" << endl;
        }
        else
        {
            rear = (rear + 1) % SIZE;
            container[rear] = data;

            size++;
        }
    }

    void Pop()
    {
        if (Empty())
        {
            cout << "Circle Queue is Empty" << endl;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }

    T& Front()
    {
        if (Empty())
        {
            exit(1);
        }
        else
        {
            return container[front];
        }
    }

    T& Back()
    {
        if (Empty())
        {
            exit(1);
        }
        else
        {
            return container[rear - 1];
        }
    }

    int& Size()
    {
        return size;
    }

};

int main()
{
    CircleQueue<int> circlequeue;

    circlequeue.Push(10);
    circlequeue.Push(20);
    circlequeue.Push(30);
    circlequeue.Push(40);

    while (circlequeue.Empty() == false) 
    {
        cout << circlequeue.Front() << endl;

        circlequeue.Pop();
    }


    return 0;
}