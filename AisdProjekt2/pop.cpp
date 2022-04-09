#include <iostream>
#include "pop.h"

void popFront(Node** head)
{
    if (*head != NULL) {
        if ((*head)->next == NULL) {
            *head = NULL;
        }
        else {
            Node* tmp;
            tmp = (*head)->next;
            free(*head);
            *head = tmp;
            (*head)->previous = NULL;
        }
    }
}

void popBack(Node** head)
{
    if ((*head)->next == NULL)
    {
        *head = NULL;
    }///
    else
    {
        Node* current = *head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

void popWithIndex(Node** head, int position)
{////
    if (position == 0) popFront(head);
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
        current->next = tmp->next;
        current->next->previous = current;
        free(tmp);
    }
}

void popByNode(Node** node) {

    Node* tempTyl = (*node)->previous;
    Node* tempPrzod = (*node)->next;

    tempTyl->next = tempPrzod;
    tempPrzod->previous = tempTyl;
}