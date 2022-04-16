#ifndef  push_h
#define push_h

struct Node {
    Node* previous = nullptr;
    Node* next = nullptr;
    unsigned long long int data;
};

void pushFront(Node** head, Node** tail, unsigned long long int data);

void pushBack(Node** head, Node** tail, unsigned long long int data);

void pushAfter(Node** node, Node** head, Node** tail, unsigned long long int data);

void pushBefore(Node** node, Node** head, Node** tail, unsigned long long int data);

#endif // ! push_hh
