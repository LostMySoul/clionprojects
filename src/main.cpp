#include "Queue.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

int main() {
    Queue *ringB = new Queue(5);
    ringB->addElement(1);
    ringB->addElement(2);
    ringB->addElement(3);

    Queue *ringA = new Queue(*ringB);
    Queue *ringC = new Queue(2);
    ringA->addElement(0);
    if (!ringA->isEmpty()) {
        cout << "queue isn't empty" << endl;
    }
    if (ringC->isEmpty()) {
        cout << "queue is empty!" << endl;
    }
    Iterator iteratorA = Iterator(ringA);
    Iterator iteratorB = Iterator(ringB);
    while (!iteratorB.finish()) {
        iteratorB.next();
        cout << iteratorB.getValue() << endl;

    }

    cout << "______________________________________" << endl;

    while (!iteratorA.finish()) {
        iteratorA.next();
        cout << iteratorA.getValue() << endl;

    }

    cout << "______________________________________" << endl;
    cout << "size ringA :" << ringA->getSize() << endl;
    ringA->empty();
    if (ringA->isEmpty()) {
        cout << "ringA is empty" << endl;
    }
    iteratorA.start();
    while (!iteratorA.finish()) {
        iteratorA.next();
        cout << iteratorA.getValue() << endl;

    }

    cout << "______________________________________" << endl;
    cout << "ringB elem: " << ringB->getElem() << endl;
    iteratorB.start();
    cout << "ringB after getting first elem" << endl;
    while (!iteratorB.finish()) {
        iteratorB.next();
        cout << iteratorB.getValue() << endl;
    }

    delete ringA;
    delete ringB;
    delete ringC;

    return 0;
}