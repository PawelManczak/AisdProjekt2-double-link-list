#ifndef push_h
#define push_h
struct Node {
    long long int data;
    int iloscDanych;
    struct Node* next;
    struct Node* previous;
};
void pushWithIndex(Node** head, unsigned long long data, int position, int sizeOfList, Node** tail);
void pushFront(Node** head, unsigned long long data, Node** tail);
void pushBack(Node** head, unsigned long long data, Node** tail);
void pushAfter(Node** node, unsigned long long longdata, Node** tail, Node** head);
void pushBefore(Node** node, unsigned long long data, Node** tail);
#endif // !push_h