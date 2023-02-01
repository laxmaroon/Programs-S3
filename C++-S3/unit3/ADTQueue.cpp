#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    T *data;
    int front;
    int rear;
    int capacity;

    void resize()
    {
        capacity *= 2;
        T *temp = new T[capacity];
        int j = 0;
        for (int i = front; i <= rear; i++)
        {
            temp[j++] = data[i];
        }
        delete[] data;
        data = temp;
        front = 0;
        rear = j - 1;
    }

public:
    Queue(int capacity = 10) : front(0), rear(-1), capacity(capacity)
    {
        data = new T[capacity];
    }

    ~Queue()
    {
        delete[] data;
    }

    bool isEmpty() const
    {
        return front > rear;
    }

    void enqueue(T element)
    {
        if (rear == capacity - 1)
        {
            resize();
        }
        data[++rear] = element;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }
        return data[front++];
    }

    T frontElement() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }
        return data[front];
    }
};

int main()
{
    Queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}
