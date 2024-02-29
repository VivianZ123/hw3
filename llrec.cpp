#include "llrec.h"

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if (head == NULL) {
    return;
  }
  Node* currentNode = head;
  head = head->next;
  currentNode->next = NULL;

  if (currentNode->val <= pivot) {
    smaller=currentNode;
    llpivot(head, smaller->next, larger, pivot);
  }else{
    larger=currentNode;
    llpivot(head, smaller, larger->next, pivot);
  }
}
