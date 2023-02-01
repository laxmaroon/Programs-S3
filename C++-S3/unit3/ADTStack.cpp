#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *data; // pointer to store the elements in the stack
    int top; // index of the top element
    int capacity; // maximum number of elements that can be stored in the stack
    
    // resize the data array to double its current size
    void resize()
    {
        int newCapacity = 2 * capacity;
        T *newData = new T[newCapacity];
        for (int i = 0; i <= top; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack(int capacity = 10) : capacity(capacity), top(-1)
    {
        data = new T[capacity];
    }

    ~Stack()
    {
        delete[] data;
    }

    // add an element to the top of the stack
    void push(T element)
    {
        if (top == capacity - 1)
        {
            resize();
        }
        data[++top] = element;
    }

    // remove the top element from the stack
    T pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return T();
        }
        return data[top--];
    }

    // return the top element of the stack
    T peek() const
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return T();
        }
        return data[top];
    }

    // check if the stack is empty
    bool empty() const
    {
        return top == -1;
    }

};

int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.peek() << endl; // Output: 3
    stack.pop();
    cout << stack.peek() << endl; // Output: 2
    stack.push(4);
    cout << stack.peek() << endl; // Output: 4
    return 0;
}
