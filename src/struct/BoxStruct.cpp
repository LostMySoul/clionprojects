//
// Created by User on 015 15.02.19.
//
#include "BoxStruct.h"

bool operator==(const Box &b1, const Box &b2) {
    return (b1.length == b2.length && b1.width == b2.width && b1.height == b2.height && b1.value == b2.value &&
            b1.weight == b2.weight);
}

std::ostream &operator<<(std::ostream &out, const Box &box) {
    out << "Box(" << box.length << ", " << box.width << ", " << box.height << ", " << box.weight << ", " << box.value
        << ")" << std::endl;
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

int boxValueSum(Box *box, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += box[i].value;
    }
    return sum;
}

bool smallerThan(Box *box, int size, int value) {
    int tempSum = 0;
    for (int i = 0; i < size; i++) {
        tempSum += box[i].length + box[i].width + box[i].height;
    }
    if (tempSum > value) {
        return false;
    }
    return true;
}

bool canPack(Box *boxArr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size; j++) {
            if (!(boxArr[i] < boxArr[j + 1] || boxArr[i] > boxArr[j + 1])) {
                return false;
            }
        }
    }
    return true;
}

double maxBoxOutOfV(Box *box, int size, int value) {
//	if (value < 0) {
//		throw new Exception
//	}
    int tempV;
    double maxWeight = 0;
    for (int i = 0; i < size; i++) {
        tempV = box[i].length * box[i].width * box[i].height;
        if (tempV <= value) {
                maxWeight += box[i].weight;
        }
    }
    return maxWeight;
}