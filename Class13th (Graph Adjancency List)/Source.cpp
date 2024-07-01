﻿#include <iostream>

#define SIZE 10

using namespace std;

template <typename T>
class AdjancencyList
{
private:
    struct Node
    {
        T data;
        Node* next;

        Node(T data, Node* link = nullptr)
        {
            this->data = data;
            next = link;
        }

    };

    int size;           // 정점의 개수
    T vertex[SIZE];     // 정점의 집합
    Node* list[SIZE];   // 인접 리스트

public:
    AdjancencyList()
    {
        size = 0;

        for (int i = 0; i < SIZE; i++)
        {
            list[i] = NULL;
            vertex[i] = NULL;
        }
    }

    void Insert(T data)
    {
        if (size >= SIZE)
        {
            cout << "Adjancency List Overflow" << endl;
        }
        else
        {
            vertex[size++] = data;
        }
    }

    void Connect(int u, int v)
    {
        if (size <= 0)
        {
            cout << "Adjancency List is Empty" << endl;
        }
        else if (u >= size || v >= size)
        {
            cout << "Index Out of Range" << endl;
        }
        else
        {
            list[u] = new Node(vertex[v], list[u]);
            list[v] = new Node(vertex[u], list[v]);
        }
    }

    void Show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << vertex[i] << " : ";

            Node* currentnode = list[i];

            while (currentnode != nullptr)
            {
                cout << currentnode->data << " ";

                currentnode = currentnode->next;
            }

            cout << endl;
        }
    }

    ~AdjancencyList()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (list[i] != nullptr)
            {
                delete[] list[i];
            }
        }
    }
};

int main()
{
#pragma region 인접 리스트
    // 그래프의 각 정점에 인접한 정점들을 연결 리스트로
    // 표현하는 방법입니다.

    // 장점
    // 그래프의 모든 간선의 수를 0(V + E)로 표현할 수 있습니다.

    // 단점
    // 두 정점을 연결하는 간선을 조회하거나 정점의 차수를 알기 위해서
    // 정점의 인접 리스트를 모두 탐색해야 하므로, 정점의 차수만큼의 시간이
    // 필요합니다.

    AdjancencyList<char> list;

    list.Insert('A');
    list.Insert('B');
    list.Insert('C');
    list.Insert('D');

    list.Connect(0, 1);
    list.Connect(0, 2);
    list.Connect(2, 3);

    list.Show();
#pragma endregion

    return 0;
}