#include <iostream>
#include "push.h"

void pushBack(Node** head, Node** tail, unsigned long long int data) {

    if (*head == NULL) pushFront(head, tail, data);
    else {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->previous = *tail;
        newNode->next = NULL;

        (*tail)->next = newNode;

        *tail = newNode;
    }
}

void pushAfter(Node** node, Node** head, Node** tail, unsigned long long int data) {

    if (*node == *tail || *node == nullptr) pushBack(head, tail, data);
    else {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->previous = *node;
        newNode->next = (*node)->next;

        (*node)->next->previous = newNode;
        (*node)->next = newNode;
    }
}

void pushBefore(Node** node, Node** head, Node** tail, unsigned long long int data) {
    if (*node == *head || *node == NULL) pushFront(head, tail, data);
    else {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->previous = (*node)->previous;
        newNode->next = *node;

        (*node)->previous->next = newNode;
        (*node)->previous = newNode;
    }
}

void pushFront(Node** head, Node** tail, unsigned long long int data) {

    Node* newNode = new Node;
    newNode->data = data;
    newNode->previous = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *tail = newNode;
    }
    else {
        newNode->next = *head;
        (*head)->previous = newNode;
    }

    *head = newNode;
}