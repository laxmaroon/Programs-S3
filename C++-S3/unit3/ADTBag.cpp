#include <iostream>
using namespace std;

template <typename T>
class Bag {
private:
    T *items;
    int count;
    int capacity;

public:
    Bag();
    void insert(T item);
    void remove(T item);
    int size();
};

template <typename T>
Bag<T>::Bag() {
    items = new T[100];
    count = 0;
    capacity = 100;
}

template <typename T>
void Bag<T>::insert(T item) {
    if (count == capacity) {
        T *temp = new T[capacity * 2];
        for (int i = 0; i < count; i++) {
            temp[i] = items[i];
        }
        delete[] items;
        items = temp;
        capacity *= 2;
    }
    items[count++] = item;
}

template <typename T>
void Bag<T>::remove(T item) {
    for (int i = 0; i < count; i++) {
        if (items[i] == item) {
            for (int j = i; j < count - 1; j++) {
                items[j] = items[j + 1];
            }
            count--;
            return;
        }
    }
}

template <typename T>
int Bag<T>::size() {
    return count;
}

int main() {
    Bag<int> b;
    b.insert(1);
    b.insert(2);
    b.insert(3);
    b.insert(4);
    b.remove(2);
    cout << "Bag size: " << b.size() << endl;
    return 0;
}
