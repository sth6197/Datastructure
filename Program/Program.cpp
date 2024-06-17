#include <iostream>

using namespace std;

#define SIZE 10

template <typename T>
class Stack
{
private:
    T container[SIZE];
    int top;
    
public:
    Stack()
    {
        top = -1;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = 0;
        }
    }

    void Push(T data)
    {
        if (top >= SIZE-1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            container[++top] = data;
        }
    }

    bool Empty()
    {
        if (top <= -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void Pop()
    {
        if (Empty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            top--;
        }

    }
    
    int& Size()
    {
        return top;
    }

    T & Top()
    {
        return container[top];
    }
};

bool CheckBracket(std::string content)
{
    Stack<char> stack;

    if (content.length() <= 0)
    {
        return false;
    }

    char arr[SIZE];
   
    for (int i = 0; arr[i] != NULL; i++)
    {
        if (arr[i] == '{' || arr[i] == '[' || arr[i] == '(')
        {
            stack.Push(arr[i]);
            return true;
        }
        if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {
            stack.Push(arr[i]);
            return true;

            if (stack.Empty())
            {
                return false;
            }
            if (arr[i] != stack.Top())
            {
                return false;
            }
            else
            {
                stack.Pop();
            }

        }
    }

    if (stack.Empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}



int main()
{
    CheckBracket("");

    cout << CheckBracket("{[()]}") << endl;

    cout << CheckBracket("{[((}") << endl;

    cout << CheckBracket("{[)]}") << endl;



    return 0;
}