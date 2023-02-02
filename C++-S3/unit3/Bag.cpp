class Bag {
private:
    int *items;
    int count;
    int capacity;

public:
    Bag();
    void insert(int item);
    void remove(int item);
    int size();
};
Bag::Bag() {
    items = new int[100];
    count = 0;
    capacity = 100;
}

void Bag::insert(int item) {
    if (count == capacity) {
        int *temp = new int[capacity * 2];
        for (int i = 0; i < count; i++) {
            temp[i] = items[i];
        }
        delete[] items;
        items = temp;
        capacity *= 2;
    }
    items[count++] = item;
}

void Bag::remove(int item) {
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

int Bag::size() {
    return count;
}

/*
A bag is a collection of items where items can be inserted or removed, but the order of the items does not matter. 
The number of items in a bag can change dynamically.

In the implementation of the Bag class, we can use an array to store the items and keep track of the number of items 
in the bag using a variable count.

Insertion into a bag can be done by adding the item to the end of the array and incrementing the count. 
Deletion from a bag can be done by removing an item from the array and decrementing the count.*/