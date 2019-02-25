//
// Created by User on 022 22.02.19.
//

#include "Vector.h"

Vector::Vector() {
    sz = 0;
    elem = nullptr;
}

Vector::Vector(int size) {
    sz = size;
    elem = new int[size]();
}

Vector::Vector(int size, int n) {
    sz = size;
    elem = new int[size];
    for (int i = 0; i < size; i++) {
        elem[i] = n;
    }
}

Vector::Vector(const Vector &a) : sz(a.sz), elem(new int[sz]) {
    for (int i = 0; i < sz; i++)
        elem[i] = a.elem[i];
}

Vector::~Vector() {
    delete[] elem;
}

Vector::Vector(Vector &&v) noexcept : elem(nullptr), sz(0) {
    sz = v.sz;
    elem = v.elem;
    v.elem = nullptr;
    v.sz = 0;
}

int Vector::size() const {
    return sz;
}

int &Vector::operator[](int i) const {
    if (i < 0 || i >= size()) throw std::out_of_range{"Vector::operator[]"};
    return elem[i];
}

void Vector::resize(int newSize) {
    if (newSize < 0) throw std::runtime_error{"resize error"};
    int *tmp = new int[newSize]();
    if (sz > newSize) {
        for (int i = 0; i < newSize; i++) {
            tmp[i] = elem[i];
        }
    } else {
        for (int i = 0; i < sz; i++) {
            tmp[i] = elem[i];
        }
    }
    delete[] elem;
    elem = tmp;
    sz = newSize;
}

void Vector::swap(Vector &other) noexcept {
    std::swap(elem, other.elem);
    std::swap(sz, other.sz);
}

const Vector &Vector::operator+(const Vector &other) {
    Vector newValue(sz + other.sz);

    std::copy(this->elem, this->elem + this->sz, newValue.elem);
    std::copy(other.elem, other.elem + other.sz, newValue.elem + this->sz);

    newValue.swap(*this);
    return *this;
}

Vector &Vector::operator=(Vector v) {
    v.swap(*this);
    return *this;
}

bool Vector::operator==(const Vector &v) {
    if (size() != v.size())
        throw std::out_of_range("Cant check equality of vectors");
    else {
        for (int i = 0; i < size(); i++) {
            if (elem[i] != v[i])
                return false;
        }
    }
    return true;
}

Vector &Vector::operator=(Vector &&other) noexcept {
    if (this != &other) {
        delete[] elem;

        sz = other.sz;
        elem = new int[sz];
        std::copy(other.elem, other.elem + sz, elem);
    }
    return *this;
}

bool Vector::operator!=(const Vector &v) {
    if (size() != v.size())
        throw std::out_of_range("Cant check equality of vectors");
    else {
        for (int i = 0; i < size(); i++) {
            if (elem[i] != v[i])
                return true;
        }
    }
    return false;
}

std::ostream &operator<<(std::ostream &out, const Vector &v) {
    out << "Vector:\n" << "size " << v.sz << std::endl << "Elements:\n";
    for (int i = 0; i < v.sz; i++) {
        out << v[i] << ' ';
    }
    return out;
}

std::istream &operator>>(std::istream &in, Vector &v) {
    in >> v.sz;
    if (v.sz < 0) {
        throw std::out_of_range("wrong size");
    }
    for (int i = 0; i < v.sz; i++) {
        in >> v[i];
    }
    return in;
}


bool Vector::operator<(const Vector &v) {
//todo: end
}

bool Vector::operator<=(const Vector &v) {

}

bool Vector::operator>(const Vector &v) {

}

bool Vector::operator>=(const Vector &v) {

}