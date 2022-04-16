#include <iostream>
#include "print.h"

void printAll(Node* head)
{
    if (head == NULL) return;
    Node* tmp = head;
    do {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    } while (tmp != NULL);
    std::cout << std::endl;
}