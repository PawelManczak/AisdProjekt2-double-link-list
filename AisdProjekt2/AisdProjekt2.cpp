// LinkList.cpp : Ten plik zawiera funkcjÄ âmainâŁ. W nim rozpoczyna siÄ i koÅczy wykonywanie programu.
//

#include <iostream>
#include "push.h"
#include "pop.h"

using namespace std;

void printAll(Node* head)
{
    if (head == NULL) return;
    Node* tmp = head;
    do {
        cout << tmp->data << " ";
        tmp = tmp->next;
    } while (tmp != NULL);
    cout << endl;
}

void printNaodwrot(Node* tail) {
    Node* tmp = tail;
    do {
        cout << tmp->data << " ";
        tmp = tmp->previous;
    } while (tmp != NULL);
    cout << endl;
}

Node* getTail(Node* head) {
    Node* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}


Node* getElemenntyByIndex(int index, Node* head) {
    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    char command[100];
    unsigned long long dane, index;

    unsigned long long x, y;
    int numerIteratora;
    int sizeOfBlock;

    Node* iterators[10]; // isnerAtfet(iteratos[2]
    int size = 0;

    while (cin >> command)
    {
        if (command == "I") { //ROZMIAR BLOKU
            cin >> sizeOfBlock;
        }
        else if (!strcmp(command, "i")) {
            char yy[5];
            cin >> x >> yy;

            if (!strcmp(yy, "BEG")) {
                iterators[x] = head;
            }
            else if (!strcmp(yy, "END"))
            {
                iterators[x] = tail;
            }
            else {
                iterators[x] = tail;//atoll(yy); !!!!!!!TODO
            }
        }
        else if (!strcmp(command, "+")) {
            cin >> numerIteratora;
            iterators[numerIteratora] = iterators[numerIteratora]->next;
        }
        else if (!strcmp(command, "-")) {
            cin >> numerIteratora;
            if (iterators[numerIteratora]->previous != NULL) iterators[numerIteratora] = iterators[numerIteratora]->previous;
        }
        else if (command == "+") {
            cin >> numerIteratora;
        }
        else if (!strcmp(command, ".A")) {
            unsigned long long x, y;
            char yy[5];
            cin >> yy >> x;
            size++;
            if (!strcmp(yy, "BEG")) {
                pushFront(&head, x, &tail);
            }
            else if (!strcmp(yy, "END")) {
                Node* tmp = getTail(head);
                pushBefore(&tmp, x, &tail);
                //pushBack(&head, x, &tail);
            }
            else {
                pushBefore(&iterators[atoll(yy)], x, &tail);
            }
        }
        else if (!strcmp(command, "A.")) {
            unsigned long long x, y;
            char yy[5];
            cin >> yy >> x;
            size++;
            if (!strcmp(yy, "BEG")) {
                pushFront(&head, x, &tail);
            }
            else if (!strcmp(yy, "END")) {
                //pushAfter(&iterators[atoll(yy)], x, &tail, &head);
                pushBack(&head, x, &tail);
            }
            else {
                pushAfter(&iterators[atoll(yy)], x, &tail, &head);
            }
        }
        else if (!strcmp(command, "R")) {
            char xx[5];
            cin >> xx;

            if (!strcmp(xx, "BEG")) {
                popFront(&head);
            }
            else if (!strcmp(xx, "END")) {
                popBack(&head);
            }
            else {
                if (tail == NULL || size == 1) {
                    popBack(&head);
                }
                else if (iterators[atoi(xx)]->next == tail->next) {
                    // cout <<"-----"<< size;
                    if (size != 1) {
                        tail = tail->previous;
                        popBack(&head);
                    }


                    for (int i = 0; i < 10; i++) {
                        if (iterators[i] == iterators[atoi(xx)])
                            iterators[i] = tail;
                    }
                }
                else {
                    // cout << "--"<<getTail(head)->data << endl;
                    popByNode(&iterators[atoi(xx)], &head);
                    //cout << tail->data;
                    //cout << iterators[atoi(xx)]->data;
                    for (int i = 0; i < 10; i++) {
                        if (iterators[i] == iterators[atoi(xx)])
                            iterators[i] = iterators[i]->next;
                    }
                }


                // cout <<"----------"<< iterators[atoi(xx)]->data << endl;
                size--;



            }
        }
        else if (!strcmp(command, "P")) {
            cin >> command;
            if (!strcmp(command, "ALL")) {
                printAll(head);
            }
            else {
                cout << iterators[atoll(command)]->data << endl;
            }
        }
    }
}