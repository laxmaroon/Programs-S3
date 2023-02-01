#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node* next;
};

class CircularLinkedList {
public:
  Node* head;

  CircularLinkedList() {
    head = NULL;
  }
  
   // Adding nodes to the right:
  void addNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;

    if (head == NULL) {
      head = newNode;
      newNode->next = head;
    } else {
      Node* temp = head;
      while (temp->next != head) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  void concatenate(CircularLinkedList& other) {
    Node* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = other.head;
    other.head->next = head;
  }

  int countNodes() {
    int count = 0;
    Node* temp = head;
    if (head == NULL) {
      return count;
    } else {
      do {
        count++;
        temp = temp->next;
      } while (temp != head);
    }
    return count;
  }

  int searchNode(int value) {
    int index = 0;
    Node* temp = head;
    do {
      if (temp->data == value) {
        return index;
      }
      index++;
      temp = temp->next;
    } while (temp != head);
    return -1;
  }

  void displayList() {
    Node* temp = head;
    if (head == NULL) {
      cout << "List is empty" << std::endl;
    } else {
      do {
       cout << temp->data << " ";
        temp = temp->next;
      } while (temp != head);
    }
  }
};

int main() {
  CircularLinkedList list;
  list.addNode(5);
  list.addNode(10);
  list.addNode(15);
  list.displayList();
  cout << endl;

  CircularLinkedList list2;
  list2.addNode(20);
  list2.addNode(25);
  list2.displayList();
  cout << endl;

  list.concatenate(list2);
  list.displayList();
  cout <<endl;

  int count = list.countNodes();
  cout << "Number of nodes: " << count << endl;

  int index = list.searchNode(25);
  if (index == -1) {
    cout << "Node not found" << endl;
  } else {
    cout << "Node found at index: " << index <<endl;
  }

  return 0;
}
