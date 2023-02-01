#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    private:
        Node *head;

    public:
        LinkedList() { head = NULL; }

        void createTwoNodeList(int data1, int data2) {
            head = new Node;
            head->data = data1;
            head->next = new Node;
            head->next->data = data2;
            head->next->next = NULL;
        }

        void insertNodeAtNthPosition(int data, int position) {
            if (head == NULL) {
                cout << "The list is empty." << endl;
                return;
            }

            Node *temp = head;
            for (int i = 1; i < position - 1 && temp != NULL; i++) {
                temp = temp->next;
            }

            if (temp == NULL) {
                cout << "The position is out of range." << endl;
                return;
            }

            Node *newNode = new Node;
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void deleteNodeAtNthPosition(int position) {
            if (head == NULL) {
                cout << "The list is empty." << endl;
                return;
            }

            Node *temp = head;
            for (int i = 1; i < position - 1 && temp != NULL; i++) {
                temp = temp->next;
            }

            if (temp == NULL || temp->next == NULL) {
                cout << "The position is out of range." << endl;
                return;
            }

            Node *temp2 = temp->next; // Initialising the node which comes after the temp node
            temp->next = temp2->next; // Initialising the temp node pointer with the pointer of temp2
            delete temp2;
        }

        void printList() {
            Node *temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    LinkedList list;

    list.createTwoNodeList(1, 2);
    cout << "List after creating two node list: ";
    list.printList();

    list.insertNodeAtNthPosition(3, 3);
    cout << "List after inserting node at 3rd position: ";
    list.printList();

    list.deleteNodeAtNthPosition(3);
    cout << "List after deleting node at 3rd position: ";
    list.printList();

    return 0;
}
