//
// Created by User on 015 15.02.19.
//
#include "../exception/ContainerException.cpp"
#include "Container.h"

using namespace ContainerSpace;

int Container::push(Box box) {
    this->weight += box.getWeight();
    if (this->weight > maxWeight) {
        throw ContainerException("max weight exceeded");
    } else {
        container.push_back(box);
        lastindex++;
    }
    return lastindex;
}

void Container::erase(int index) {
    container.erase(container.begin() + index);
    lastindex--;
}

unsigned long Container::size() {
    return container.size();
}

double Container::fullWeight() {
    double weightSum = 0;
    for (int i = 0; i < size(); i++) {
        weightSum += container[i].getWeight();
    }
    return weightSum;
}

int Container::fullValue() {
    int valueSum = 0;
    for (int i = 0; i < size(); i++) {
        valueSum += container[i].getValue();
    }
    return valueSum;
}

Box Container::getByIndex(int index) {
    if (index < 0 || index > size()-1) {
        throw ContainerException("Container index out of range");
    } else {
        return container[index];
    }
}

Box Container::operator[](int index) const {
    if (index < 0 || index > this->lastindex) {
        throw ContainerException("Container index out of range");
    } else {
        return container[index];
    }
}

namespace ContainerSpace {

        std::ostream &operator<<(std::ostream &out, const Container &container) {
            out << "Container:" << container.length << ", " << container.width << ", " << container.height << ", "
                << container.maxWeight
                << ";" << std::endl << "Boxes:" << std::endl;
            for (int i = 0; i < container.container.size(); i++) {
                out << container.container[i];
            }
            return out;
        }

        std::istream &operator>>(std::istream &in, Container &container) {
            in >> container.length;
            in >> container.width;
            in >> container.height;
            in >> container.maxWeight;
            return in;
        }
};