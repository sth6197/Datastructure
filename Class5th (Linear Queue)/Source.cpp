#include <iostream>

#define SIZE 5

using namespace std;

template <typename T>
class LinearQueue
{
private:
    int front;
    int rear;
    int size;

    T container[SIZE];

public:
    LinearQueue()
    {
        front = 0;
        rear = 0;
        size = 0;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

    void Push(T data)
    {
        if (rear >= SIZE)
        {
            cout << "Linear Queue Overflow" << endl;
        }
        else
        {
            container[rear++] = data;
            size++;
        }
    }

    void Pop()
    {
        if (Empty())
        {
            cout << "Linear Queue is Empty" << endl;
        }
        else
        {
            container[front++] = NULL;

            size--;
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
    LinearQueue<int> linearqueue;

    linearqueue.Push(10);
    linearqueue.Push(20);
    linearqueue.Push(30);
    linearqueue.Push(40);
    linearqueue.Push(50);

    while (linearqueue.Empty() == false)
    {
        cout << linearqueue.Front() << endl;

        linearqueue.Pop();
    }

    linearqueue.Push(99);

    return 0;
}