/*In this implementation, the head1 and head2 parameters are pointers to the heads of the two chains that need to be merged. 
The function returns a pointer to the head of the merged chain.*/


#include <iostream>

struct Node {
  int data;
  Node *next;
};

Node *mergeChains(Node *head1, Node *head2) {
  if (!head1) return head2;
  if (!head2) return head1;
  
  Node *head = nullptr, *curr = nullptr;
  
  while (head1 && head2) {
    if (head1->data < head2->data) {
      if (!curr) head = curr = head1;
      else curr = curr->next = head1;
      head1 = head1->next;
    } else {
      if (!curr) head = curr = head2;
      else curr = curr->next = head2;
      head2 = head2->next;
    }
  }
  
  curr->next = head1 ? head1 : head2;
  
  return head;
}
