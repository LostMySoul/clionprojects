//
// Created by User on 016 16.02.19.
//

#ifndef EXC0_BOX_H
#define EXC0_BOX_H


#include <iostream>

namespace ContainerSpace {

    class Box {
    private:
        int length, width, height;
        double weight;
        int value;
    public:

        Box(int length, int width, int height, double weight, int value) :
                length(length), width(width), height(height), weight(weight), value(value) {

        }

        Box() : length(0), width(0), height(0), weight(0), value(0) {

        }

        ~Box() = default;

        int getLength();

        int getWidth();

        int getHeight();

        double getWeight();

        int getValue();

        void setLength(int length);

        void setWidth(int width);

        void setHeight(int height);

        void setWeight(double weight);

        void setValue(int value);

        friend bool operator<(const Box &b1, const Box &b2);

        friend bool operator>(const Box &b1, const Box &b2);

        bool operator==(const Box &b);

        friend std::ostream &operator<<(std::ostream &out, const Box &box);

        friend std::istream &operator>>(std::istream &in, Box &box);

        static int boxValueSum(Box *box, int size);

        static bool smallerThan(Box *box, int size, int value);

        static bool canPack(Box *boxArr, int size);

        static double maxBoxOutOfV(Box *box, int size, int value);
    };
}

#endif //EXC0_BOX_H
