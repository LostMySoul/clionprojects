//
// Created by User on 015 15.02.19.
//

#ifndef EXC0_BOX_H
#define EXC0_BOX_H


#include <iostream>

struct Box {

    int length, width, height;
    double weight;
    int value;

    Box(int length, int width, int height, double weight, int value) : length(length), width(width), height(height), weight(weight), value(value) {
    }

    Box() : length(0), width(0), height(0), weight(0), value(0) {
    }

    friend bool operator< (const Box &b1, const Box &b2) {
        return (b1.length < b2.length && b1.width < b2.width && b1.height < b2.height);
    }

    friend bool operator> (const Box &b1, const Box &b2) {
        return (b1.length > b2.length && b1.width > b2.width && b1.height > b2.height);
    }
};

bool operator== (const Box &b1, const Box &b2);

std::ostream& operator<< (std::ostream &out, const Box &box);

std::istream& operator>> (std::istream &in, Box &box);

int boxValueSum(Box *box, int size);

bool smallerThan(Box *box, int size, int value);

bool canPack(Box *boxArr, int size);

double maxBoxOutOfV(Box *box, int size, int value);

#endif //EXC0_BOX_H
