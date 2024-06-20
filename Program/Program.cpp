#pragma warnings(disable : 4996)
#include <iostream>

using namespace std;

class String
{
private:
    char* container;
    int size;

public:
    String()
    {
        size = 0;
        container = nullptr;
    }

    void operator=(const char* content)
    {
        int arraySize = strlen(content) + 1;
        size = strlen(content);

        if (container == nullptr)
        {
            container = new char[arraySize];

            for (int i = 0; i < arraySize; i++)
            {
                container[i] = content[i];
            }
        }
        else
        {
            char* newContainer = new char[arraySize];

            for (int i = 0; i < arraySize; i++)
            {
                newContainer[i] = content[i];
            }

            delete container;

            container = newContainer;
        }
    }
    
    int Compare(const char* content)
    {
        for (int i = 0; i != size; i++)
        {
            if (content[i] > content[i])
            {
                return 1;
            }
            else if (content[i] < content[i])
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

    }

    char& operator[] (int index)
    {
        return container[index];
    }

    int& Size()
    {
        return size;
    }
};

int main()
{
    String string;

    string = "Janna";

    cout << "string의 크기 : " << string.Size() << endl;

    string = "Allistar";

    for (int i = 0; i < string.Size(); i++)
    {
        cout << string[i];
    }

    return 0;
}