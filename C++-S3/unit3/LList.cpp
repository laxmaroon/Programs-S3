#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

class LinkedList {
  private:
    Node* head;
  public:
    LinkedList() {
      head = NULL;
    }

    // Adding nodes to the left:
    void addNode(int data) {
      Node* newNode = new Node; 
      newNode->data = data;
      newNode->next = head; //The next field of the new node is set to the current head of the linked list.
      head = newNode;   //The head of the linked list is then updated to the newly created node, making it the new first node in the list.
    }

    void concatenate(LinkedList& list2) {
      Node* temp = head;  //A temporary node temp is created and initialized to the head of the first linked list.
      while (temp->next != NULL) {
        temp = temp->next;   //The temp node is moved through the linked list until temp->next is NULL, which means it has reached the end of the linked list.
      }
      temp->next = list2.head; //The temp->next is set to the head of the second linked list.
    }

    bool search(int data) {
      Node* temp = head;
      while (temp != NULL) {
        if (temp->data == data) {
          return true;
        }
        temp = temp->next;
      }
      return false;
    }

    int countNodes() {
      int count = 0;
      Node* temp = head;
      while (temp != NULL) {
        count++;
        temp = temp->next;
      }
      return count;
    }

    void printList() {
      Node* temp = head;
      while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
      }
    }
};

int main() {
  LinkedList list1, list2;
  list1.addNode(5);
  list1.addNode(10);
  list1.addNode(15);
  list2.addNode(20);
  list2.addNode(25);
  cout << "List 1: ";
  list1.printList();
  cout << endl;
  cout << "List 2: ";
  list2.printList();
  cout << endl;
  cout << "Concatenated List: ";
  list1.concatenate(list2);
  list1.printList();
  cout << endl;
  int searchData = 20;
  if (list1.search(searchData)) {
    cout << "Data " << searchData << " found in the list." << endl;
  } else {
    cout << "Data " << searchData << " not found in the list." << endl;
  }
  cout << "Number of nodes in the list: " << list1.countNodes() << endl;
  return 0;
}
