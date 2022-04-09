#include <iostream>
#include "push.h"

void pushWithIndex(Node** head, unsigned long long data, int position, int sizeOfList, Node** tail)
{
    if (position == 0) pushFront(head, data, tail);
    else if (position == sizeOfList) pushBack(head, data, tail);
    else
    {
        Node* current = *head;
        Node* tmp;

        int i = 0;
        while (current->next != NULL && i < position - 1) {
            current = current->next;
            i++;
        }

        tmp = current->next;
        current->next = new Node;
        current->next->data = data;
        current->next->previous = current;
        tmp->previous = current->next;
        current->next->next = tmp;
    }
}

void pushAfter(Node** node, unsigned long long data, Node** tail) {

    Node* newNode = new Node;

    Node* t = (*node)->next;
    newNode->next = (*node)->next;
    newNode->data = data;
    newNode->previous = *node;

    newNode->next->previous = newNode;
    newNode->previous->next = newNode;
}

void pushBefore(Node** node, unsigned long long data, Node** tail) {

    Node* newNode = new Node;

    newNode->next = *node;
    newNode->data = data;
    newNode->previous = (*node)->previous;


    (*node)->previous = newNode;
    newNode->previous->next = newNode;
}

void pushFront(Node** head, unsigned long long data, Node** tail)
{
    if (*head == NULL) { //LISTA PUSTA
        *head = new Node;
        *tail = new Node;
        (*head)->data = data;
        (*head)->previous = NULL;
        (*head)->next = NULL;

        (*tail)->data = data;
        (*tail)->previous = NULL;
        (*tail)->next = NULL;
    }
    else {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->previous = NULL;
        newNode->next = *head;
        (*head)->previous = newNode;
        *head = newNode;
    }
}

void pushBack(Node** head, unsigned long long data, Node** tail)
{
    if (*head == NULL)
    {
        *head = new Node;
        *tail = new Node;
        (*head)->data = data;
        (*head)->previous = NULL;
        (*head)->next = NULL;
        (*tail)->data = data;
        (*tail)->previous = NULL;
        (*tail)->next = NULL;
    }
    else
    {
        Node* current = *head;
        Node* new_element;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Node;
        current->next->data = data;
        current->next->previous = current;
        current->next->next = NULL;

        (*tail)->data = data;
        (*tail)->previous = current;
        (*tail)->next = NULL;
    }


}