#include <iostream>
#include <stdexcept>
#include "vector/Vector.h"

int main() {
    Vector v;
    std::cout << v << std::endl;
    Vector v2(3);
    std::cout << v2 << std::endl;
    Vector v3(4, 4);
    std::cout << v3 << std::endl;
    v3.~Vector();
    std::cout << v3 << std::endl;

    Vector vcopy(v2);
    vcopy.resize(4);
    std::cout << v2 << std::endl;
    vcopy[2] = 1;
    std::cout << vcopy << std::endl;
    vcopy.resize(2);
    std::cout << vcopy << std::endl << std::endl << std::endl;
    std::cout << std::endl << "----------------------";
    Vector toMove;
    toMove = Vector(3, 3);
    std::cout << std::endl << "vector to move:" << std::endl << toMove << std::endl;
    Vector moved(std::move(toMove));
    std::cout << std::endl << "moved:" << std::endl << moved << std::endl;
    std::cout << std::endl << "vector after move:" << std::endl << toMove;
    std::cout << std::endl << "----------------------" << std::endl;
    v = v2;
    std::cout << v << std::endl;

    std::cout << (v == v2) << "-eq v and v2" << std::endl;
    v2[1] = 4;
    std::cout << (v != v2) << "-not eq v and v2 (after change in v2)" << std::endl;
    std::cout << v + v2 << std::endl;

    std::cout << (v < v2) << std::endl;
    std::cout << (v <= v2) << std::endl;
    std::cout << (v2 <= v2) << std::endl;
    std::cout << (v > v2) << std::endl;
    std::cout << (v >= v2) << std::endl;

    return 0;
}