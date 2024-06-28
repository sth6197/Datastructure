#include <iostream>

#define SIZE 10

using namespace std;

template <typename T>
class AdjacencyMartix
{
private:
    int size;                // 정점의 개수
    T vertex[SIZE];          // 정점의 집합
    int matrix[SIZE][SIZE];  // 인접 행렬

public:
    AdjacencyMartix()
    {
        size = 0;

        for (int i = 0; i < SIZE; i++)
        {
            vertex[i] = NULL;

            for (int j = 0; j < SIZE; j++)
            {
                matrix[i][j] = NULL;
            }
        }
    }

    void Insert(T data)
    {
        if (size >= SIZE)
        {
            cout << "Adjacency Matrix Overflow" << endl;
        }
        else
        {
            vertex[size++] = data;
        }
    }

    void Connect(int i, int j)
    {
        if (size <= 0)
        {
            cout << "Adjacency Matrix is Empty" << endl;
        }
        else if (i >= size || j >= size)
        {
            cout << "Index Out of Range" << endl;
        }
        else
        {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }

    void Show()
    {
        if (size <= 0)
        {
            cout << "Adjacency Matrix Overflow" << endl;
        }
        else
        {
            cout << "    ";

            for (int i = 0; i < size; i++)
            {
                cout << vertex[i] << " ";
            }

            cout << endl;

            for (int i = 0; i < size; i++)
            {
                cout << vertex[i] << " : ";

                for (int j = 0; j < size; j++)
                {
                    cout << matrix[i][j] << " ";
                }

                cout << endl;
            }
        }
    }

};

int main()
{
#pragma region 그래프
    // 요소들이 서로 복잡하게 연결되어 있는 관계를
    // 표현하는 자료구조이며, 정점과 간선들의 집합으로 구성되어 있습니다.


    // 정점(Vertex)
    // 노드(Node) 데이터가 저장되는 그래프의 기본 원소입니다.

    // 간선(Edge)
    // 노드들을 연결하는 선입니다.

    // 인접 정점(Adjacent Vertex)
    // 간선으로 직접 연결된 정점을 의미합니다.

    // 차수(Degree)
    // 정점에 연결된 간선의 수를 의미합니다.

    // 경로(Path)
    // 정점들을 연결하는 간선들의 순서입니다.
#pragma endregion

#pragma region 인접 행렬
    // 정점들 간의 연결관계를 2차원 배열로 표현하는 방식입니다.
    // 정점의 개수가 v일 때, v * v 크기의 2차원 배열을 사용합니다.
#pragma endregion

    AdjacencyMartix<char> graph;

    graph.Insert('A');
    graph.Insert('B');
    graph.Insert('C');
    graph.Insert('D');

    graph.Connect(0, 1);
    graph.Connect(0, 2);
    graph.Connect(2, 3);

    graph.Show();

    return 0;
}