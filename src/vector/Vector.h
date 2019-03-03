//
// Created by User on 022 22.02.19.
//

#ifndef EXC0_VECTOR_H
#define EXC0_VECTOR_H

#include <iostream>

class Vector {
private:
    int sz;
    int *elem;
    void swap(Vector &other) noexcept;

public:

    explicit Vector(unsigned int size, int n);

    explicit Vector(unsigned int size);

    Vector(Vector &&v) noexcept;

    Vector(const Vector &a);

    Vector();

    ~Vector();

    int &operator[](int) const;

    int size() const;

    Vector &operator=(Vector v);

    bool operator==(const Vector &v);

    const Vector &operator+(const Vector &);

    bool operator!=(const Vector &v);

    Vector &operator=(Vector &&other) noexcept;

    void resize(int newSize);

    bool operator<(const Vector &v);
    bool operator<=(const Vector &v);
    bool operator>(const Vector &v);
    bool operator>=(const Vector &v);

    friend std::ostream &operator<<(std::ostream &out, const Vector &v);

    friend std::istream &operator>>(std::istream &in, Vector &v);


};


#endif //EXC0_VECTOR_H
