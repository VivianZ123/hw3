#include "llrec.h"

void insert(Node*& list, Node*& tail, Node* node) {
    if (list == NULL) {
        list = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    node->next = NULL;
}
void llpivotHelper(Node* current, Node*& smaller, Node*& larger, Node*& smallerTail, Node*& largerTail, int pivot) {
    if (current == NULL) return;
    Node* nextNode = current->next; 
    if (current->val <= pivot) {
        insert(smaller, smallerTail, current);
    } else {
        insert(larger, largerTail, current);
    }
    llpivotHelper(nextNode, smaller, larger, smallerTail, largerTail, pivot);
}
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    Node *smallerTail = NULL, *largerTail = NULL;
    smaller = larger = NULL;
    llpivotHelper(head, smaller, larger, smallerTail, largerTail, pivot);
    head = NULL;
}