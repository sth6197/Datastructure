#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Vector
{
private:
    int size;
    int capacity;

    T* container;

public:
    Vector()
    {
        size = 0;
        capacity = 0;
        container = nullptr;
    }

    void Resize(int newSize)
    {
        // 1. capacity에 새로운 size값을 저장한다.
        capacity = newSize;

        // 2. 새로운 포인터 변수를 생성해서 새롭게 만들어진 메모리 공간을 가리키도록 한다.
        T* arr = new T[capacity];

        // 3. 새로운 메모리 공간의 값을 초기화한다.
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = NULL;
        }
        
        // 4. 기존 배열에 있는 값을 복사해서 새로운 배열에 넣는다.
        for (int i = 0; i < size; i++)
        {
            arr[i] = container[i];
        }
        
        // 5. 기존 배열의 메모리를 해제한다.
        if (container != nullptr)
        {
            delete[] container;
        }

        // 6. 기존에 배열을 가리키던 포인터 변수의 값을 새로운 배열에 시작 주소로 가리키도록 한다.
        container = arr;
    }
    
    void PushBack(T data)
    {
        if (capacity <= 0)
        {
            Resize(1);
        }
        else if (size >= capacity)
        {
            Resize(capacity * 2);
        }
        
        container[size++] = data;
    }

    void PopBack()
    {

    }
    
    void Reserve(int newSize)
    {

    }

    T& operator[](const int index)
    {
        return container[index];
    }
    
    int& Size()
    {
        return size;
    }

    ~Vector()
    {
        if (container != nullptr)
        {
            delete[] container;
        }
    }
};

int main()
{
    Vector<int> vector;
    
    vector.PushBack(10);
    vector.PushBack(20);
    vector.PushBack(30);

    for (int i = 0; i < vector.Size(); i++)
    {
        cout << vector[i] << endl;
    }


    return 0;
}