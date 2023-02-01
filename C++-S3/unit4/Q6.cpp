/*
This program uses a technique called "pointer reversal" to reverse the linked list by updating the next pointers of each node to point in the opposite direction. 
The prev pointer keeps track of the previously processed node, and the curr pointer keeps track of the current node being processed. 
The next pointer is used to temporarily store the value of curr->next before it is updated.

In each iteration of the loop, the algorithm reverses the next pointer of the current node, moves the prev pointer to the current node, 
and moves the curr pointer to the next node. This process continues until curr becomes null, 
at which point the prev pointer points to the head of the reversed list.

*/


#include <iostream>

struct Node {
  int data;
  Node *next;
};

void insertBack(Node *&head, int data) {
  Node *newNode = new Node {data, nullptr};
  if (!head) {
    head = newNode;
  } else {
    Node *curr = head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

Node *reverseList(Node *head) {
  Node *prev = nullptr, *curr = head, *next = nullptr;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
