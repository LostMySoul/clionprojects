//
// Created by User on 016 16.02.19.
//

#include "Box.h"

using namespace ContainerSpace;

int Box::getLength() {
    return length;
}

int Box::getWidth() {
    return width;
}

int Box::getHeight() {
    return height;
}

double Box::getWeight() {
    return weight;
}

int Box::getValue() {
    return value;
}

void Box::setLength(int length) {
    this->length = length;
}

void Box::setWidth(int width) {
    this->width = width;
}

void Box::setHeight(int height) {
    this->height = height;
}

void Box::setWeight(double weight) {
    this->weight = weight;
}

void Box::setValue(int value) {
    this->value = value;
}

int Box::boxValueSum(Box *box, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += box[i].value;
    }
    return sum;
}

bool Box::smallerThan(Box *box, int size, int value) {
    int tempSum = 0;
    for (int i = 0; i < size; i++) {
        tempSum += box[i].length + box[i].width + box[i].height;
    }
    if (tempSum > value) {
        return false;
    }
    return true;
}

bool Box::canPack(Box *boxArr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size; j++) {
            if (!(boxArr[i] < boxArr[j + 1] || boxArr[i] > boxArr[j + 1])) {
                return false;
            }
        }
    }
    return true;
}

double Box::maxBoxOutOfV(Box *box, int size, int value) {
    int tempV;
    int maxWeight = 0;
    for (int i = 0; i < size; i++) {
        tempV = box[i].length * box[i].width * box[i].height;
        if (tempV <= value) {
            maxWeight += box[i].weight;
        }
    }
    return maxWeight;
}

bool Box::operator==(const Box &b) {
    return (this->length == b.length && this->width == b.width && this->height == b.height && this->value == b.value &&
            this->weight == b.weight);
}

namespace ContainerSpace {

    bool operator<(const Box &b1, const Box &b2) {
        return (b1.length < b2.length && b1.width < b2.width && b1.height < b2.height);
    }

    bool operator>(const Box &b1, const Box &b2) {
        return (b1.length > b2.length && b1.width > b2.width && b1.height > b2.height);
    }

    std::ostream &operator<<(std::ostream &out, const Box &box) {
        out << "Box(" << box.length << ", " << box.width << ", " << box.height << ", " << box.weight << ", "
            << box.value << ")" << std::endl;
        return out;
    }

    std::istream &operator>>(std::istream &in, Box &box) {
        in >> box.length;
        in >> box.width;
        in >> box.height;
        in >> box.weight;
        in >> box.value;
        return in;
    }

}
