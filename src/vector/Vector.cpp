//
// Created by User on 022 22.02.19.
//

#include "Vector.h"

Vector::Vector() {
    sz = 1;
    elem = new int[1]();
}

Vector::Vector(unsigned int size) {
    sz = size;
    elem = new int[size]();
}

Vector::Vector(unsigned int size, int n) {
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

Vector::Vector(Vector &&v) noexcept : elem(nullptr), sz(0) {
//    sz = v.sz;
//    elem = v.elem;
//    v.elem = nullptr;
//    v.sz = 0;
    elem = new int[v.sz];
    for(int i = 0; i < v.sz; i++) {
        elem[i] = v[i];
    }
    this->sz = v.sz;
    delete[] &v;
}

Vector::~Vector() {
    if (elem) {
        delete[] elem;
        sz = 0;
    }
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

Vector &Vector::operator=(Vector v) {
    v.swap(*this);
    return *this;
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

bool Vector::operator==(const Vector &v) {
    if (sz != v.sz)
        throw std::out_of_range("Cant check equality of vectors");
    else {
        for (int i = 0; i < size(); i++) {
            if (elem[i] != v[i])
                return false;
        }
    }
    return true;
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

const Vector &Vector::operator+(const Vector &other) {
    Vector newValue(sz + other.sz);

    std::copy(this->elem, this->elem + this->sz, newValue.elem);
    std::copy(other.elem, other.elem + other.sz, newValue.elem + this->sz);

    newValue.swap(*this);
    return *this;
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


int compare(int *arr1, int *arr2, int size1, int size2) {
    int size;
    if (size1 == size2) size = size1;
    else if (size1 < size2) size = size1;
    else size = size2;
    for (int i = 0; i < size; i++) {
        if (arr1[i] > arr2[i]) {
            return 1;
        } else if (arr1[i] < arr2[i]) {
            return -1;
        }
    }
    if (size1 == size2) return 0;
    else if (size1 < size2) return -1;
    else return 1;
}

bool Vector::operator<(const Vector &v) {
    return (compare(elem, v.elem, sz, v.sz) < 0);
}

bool Vector::operator<=(const Vector &v) {
    return (compare(elem, v.elem, sz, v.sz) <= 0);
}

bool Vector::operator>(const Vector &v) {
    return (compare(elem, v.elem, sz, v.sz) > 0);
}

bool Vector::operator>=(const Vector &v) {
    return (compare(elem, v.elem, sz, v.sz) >= 0);
}
