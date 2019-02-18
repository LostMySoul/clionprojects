//
// Created by User on 015 15.02.19.
//

#ifndef EXC0_CONTAINER_H
#define EXC0_CONTAINER_H

#include <vector>
#include "../box/Box.h"

namespace ContainerSpace {

    class Container {
    private:
        std::vector<Box> container;
        int length;
        int width;
        int height;
        double weight = 0;
        int maxWeight;
        int lastindex = -1;
    public:
        Container(int length, int width, int height, int maxWeight) {
            container = {};
            this->length = length;
            this->width = width;
            this->height = height;
            this->maxWeight = maxWeight;
        }

        Container() : length(0), width(0), height(0), maxWeight(0) {
            container = {};
        }

        ~Container() = default;

        int push(Box box);

        void erase(int index);

        unsigned long size();

        double fullWeight();

        int fullValue();

        Box getByIndex(int index);

        friend std::ostream &operator<<(std::ostream &out, const Container &container);

        friend std::istream &operator>>(std::istream &in, Container &container);

        Box operator[](int index) const;

    };
}

#endif //EXC0_CONTAINER_H
