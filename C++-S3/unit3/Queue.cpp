#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 10;

class Queue {
  private:
    int front;
    int rear;
    int arr[MAX_SIZE];

  public:
    Queue() {
      front = -1;
      rear = -1;
    }

    void enqueue(int x) {
      if (rear == MAX_SIZE - 1) {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
      }

      if (front == -1 && rear == -1) {
        front = rear = 0;
      } else {
        rear++;
      }

      arr[rear] = x;
      cout << x << " enqueued." << endl;
    }

    void dequeue() {
      if (front == -1) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
      }

      cout << arr[front] << " dequeued." << endl;

      if (front == rear) {
        front = rear = -1;
      } else {
        front++;
      }
    }

    void display() {
      if (front == -1) {
        cout << "Queue is empty." << endl;
        return;
      }

      for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
};

int main() {
  Queue q;

  int choice;
  int x;
  while (true) {
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter the number to enqueue: ";
        cin >> x;
        q.enqueue(x);
        break;

      case 2:
        q.dequeue();
        break;

      case 3:
        q.display();
        break;

      case 4:
        exit(0);

      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0;
}
