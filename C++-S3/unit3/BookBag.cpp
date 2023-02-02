#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string authors;
    int price;
    int edition;
};

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
    T getItem(int index);
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
T Bag<T>::getItem(int index) {
    if (index < 0 || index >= count) {
        cout << "Index out of range." << endl;
        return items[0];
    }
    return items[index];
}

template <typename T>
int Bag<T>::size() {
    return count;
}

int main() {
    Book book1, book2, book3;
    book1.title = "The Great Gatsby";
    book1.authors = "F. Scott Fitzgerald";
    book1.price = 10;
    book1.edition = 1;

    book2.title = "Pride and Prejudice";
    book2.authors = "Jane Austen";
    book2.price = 15;
    book2.edition = 2;

    book3.title = "To Kill a Mockingbird";
    book3.authors = "Harper Lee";
    book3.price = 20;
    book3.edition = 3;

    Bag<Book> bag;
    bag.insert(book1);
    bag.insert(book2);
    bag.insert(book3);

    cout << "Book at index 0: " << endl;
    cout << "Title: " << bag.getItem(0).title << endl;
    cout << "Authors: " << bag.getItem(0).authors << endl;
    cout << "Price: " << bag.getItem(0).price << endl;
    cout << "Edition: " << bag.getItem(0).edition << endl;

    cout << endl;
    
 return 0;
}