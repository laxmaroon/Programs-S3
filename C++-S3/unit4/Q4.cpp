#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class  Chain {
    private:
        Node *head;

    public:
        Chain() { head = NULL; }

        int length() {
            int count = 0;
            Node *temp = head;
            while (temp != NULL) {
                count++;
                temp = temp->next;
            }
            return count;
        }

        // Other functions for adding and removing nodes from the chain.
};

int main() {
   Chain chain;

    // Add some nodes to the list.

    cout << "Number of nodes in the Chain: " << chain.length() << endl;
    return 0;
}
