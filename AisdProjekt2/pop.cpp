#include "pop.h"
#include <iostream>

void popFront(Node** head, Node** tail) {
    if (*head == *tail) {
        *head = NULL;
        *tail = NULL;
        delete* tail;
        delete* head;
    }
    else {
        Node* tmp;
        tmp = (*head)->next;
        delete* head;
        *head = tmp;
        (*head)->previous = NULL;
    }
}

void popBack(Node** head, Node** tail) {
    if (*head == *tail) popFront(head, tail);
    else {
        Node* tmp;
        tmp = (*tail)->previous;
        delete *tail;
        *tail = tmp;
        (*tail)->next = NULL;
    }
}
void popByNode(Node** node, Node** head, Node** tail) {
    if (*node == *head) popFront(head, tail);
    else if (*node == *tail) popBack(head, tail);
    else {
        Node* tempTyl = (*node)->previous;
        Node* tempPrzod = (*node)->next;

        delete* node;

        tempTyl->next = tempPrzod;
        tempPrzod->previous = tempTyl;
    }

}