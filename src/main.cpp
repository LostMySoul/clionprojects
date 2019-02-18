#include <iostream>
#include <stdexcept>
#include "container/Container.h"
#include "exception/ContainerException.cpp"

using namespace ContainerSpace;

int main() {
    Box box1(4, 4, 4, 10, 100);
    Box box2(1, 1, 1, 11, 200);
    Box box3(2, 2, 2, 1, 300);
    Box box4(3, 3, 3, 1, 300);
    Box *boxArr;
    boxArr = new Box[4];
    boxArr[0] = box1;
    boxArr[1] = box2;
    boxArr[2] = box3;
    boxArr[3] = box4;
    std::cout << "box1 and box2 equal? " << (box1 == box2) << std::endl;
    std::cout << "BoxArr sum value: " << Box::boxValueSum(boxArr, 3) << std::endl;
    std::cout << "All boxess len,wid,hei sum in array smaller: " << Box::smallerThan(boxArr, 3, 100) << std::endl;
    std::cout << "Maximum Boxes weight, which volume smaller than inserted value: " << Box::maxBoxOutOfV(boxArr, 3, 1)
              << std::endl << std::endl;
    std::cout << "Current array can be packed: " << Box::canPack(boxArr, 4) << std::endl;
    std::cout << box1 << std::endl;
    Box test;
    std::cout << "insert box  length, width, height, weight, value:" << std::endl;
    std::cin >> test;
    std::cout << "inserted box:" << std::endl << test << std::endl;
    Container container(100, 100, 100, 100);
    container.push(box1);
    container.push(box2);
    container.push(box4);
    container.push(box3);
    std::cout << container << std::endl;
    std::cout << "container box (id=1):" << container[1];
    std::cout << "number of boxes in container:" << container.size() << std::endl;
    std::cout << "sum weight of container" << container.fullWeight() << std::endl;
    std::cout << "sum value of container" << container.fullValue() << std::endl;
    Box box10(3, 3, 3, 102, 300);
    try {
        std::cout << "trying to push overweighted box" << std::endl;
        container.push(box10);
    } catch (const ContainerException &ex) {
        std::cout << ex.getMessage();
    }

    std::cout << container << std::endl;
    Container testCont;
    std::cout << "enter container length, width, height, maxWeight:" << std::endl;
    std::cin >> testCont;
    std::cout << "entered container:" << std::endl << testCont;
    testCont.push(box1);
    std::cout << std::endl << testCont;


    return 0;
}

