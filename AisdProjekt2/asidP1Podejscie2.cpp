#include <iostream>
#include "push.h"
#include "pop.h"
#include "print.h"

using namespace std;

int main()
{
    char command[10];
    int sizeOfBlock, numerIteratora, LICZBA_ITERATOROW = 10;
    unsigned long long data;
    char iterator[5];
    Node *head = NULL, *tail = NULL;

    Node* iterators[10]{ NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL , NULL };

    while (cin >> command) {
        if (!strcmp(command, "I")) {
            cin >> sizeOfBlock;
        }
        else if (!strcmp(command, "i")) {
            cin >> numerIteratora >> iterator;

            if (!strcmp(iterator, "BEG")) {
                iterators[numerIteratora] = head;
            }
            else if (!strcmp(iterator, "END"))
            {
                iterators[numerIteratora] = tail;
            }
            else {
                iterators[numerIteratora] = iterators[atoi(iterator)];
            }

        }
        else if (!strcmp(command, "+")) {
            cin >> numerIteratora;
            if (iterators[numerIteratora] != NULL && iterators[numerIteratora]->next != NULL)
                iterators[numerIteratora] = iterators[numerIteratora]->next;

        }
        else if (!strcmp(command, "-")) {
            cin >> numerIteratora;
            if (iterators[numerIteratora] != NULL && iterators[numerIteratora]->previous != NULL)
                iterators[numerIteratora] = iterators[numerIteratora]->previous;

        }
        else if (!strcmp(command, "A.")) {

            cin >> iterator >> data;

            if (!strcmp(iterator, "BEG")) {
                pushAfter(&head, &head, &tail, data);
            }
            else if (!strcmp(iterator, "END")) {
                pushBack(&head, &tail, data);
            }
            else pushAfter(&iterators[atoi(iterator)], &head, &tail, data);

        }
        if (!strcmp(command, ".A")) {

            cin >> iterator >> data;

            if (!strcmp(iterator, "BEG")) {
                pushFront(&head, &tail, data);
            }
            else if (!strcmp(iterator, "END")) {
                pushBefore(&tail, &head, &tail, data);
            }
            else pushBefore(&iterators[atoi(iterator)], &head, &tail, data);

        }
        else if (!strcmp(command, "P")) {
            cin >> command;
            if (!strcmp(command, "ALL")) {
                printAll(head);
            }
            else if(iterators[atoi(command)] != NULL) cout << iterators[atoi(command)]->data << endl;

        }
        else if (!strcmp(command, "R")) {
            cin >> iterator;

            if (!strcmp(iterator, "BEG")) {
                popFront(&head, &tail);
            }
            else if (!strcmp(iterator, "END")) {
                popBack(&head, &tail);
            }
            else if (iterators[atoi(iterator)] != NULL) {

                Node* temp = iterators[atoi(iterator)];
               
                int flag = -1;
                bool first = true;
                int number = -1;

                for (int i = 0; i < LICZBA_ITERATOROW; i++) {
                    if (iterators[i] == temp && first) {
                        if (iterators[i] != tail) {
                            iterators[i] = iterators[i]->next;
                            flag = 0;
                        }
                        else if (head != tail) {
                            iterators[i] = iterators[i]->previous;
                            flag = 1;
                        }
                        else { flag = 2; }

                        first = false;
                        number = i;
                    }
                    else if (iterators[i] == temp) iterators[i] = iterators[number];
                }
                if (flag == 0) popByNode(&iterators[atoi(iterator)]->previous, &head, &tail);
                else if (flag == 1) popByNode(&iterators[atoi(iterator)]->next, &head, &tail);
                else if (flag == 2) popByNode(&iterators[atoi(iterator)], &head, &tail);
            }

        }
    }
}
