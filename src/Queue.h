#pragma once

struct SizeException {};
struct EmptyException {};
class Queue {
private:
	double *arr;
	int size;
	int firstPointer;
	int lastPointer;
	bool flag;
public:
	friend class Iterator;
	Queue(int size);
	Queue(const Queue &copy);
	void addElement(double element);
	double getElem();
	double peek();
	void empty();
	int getSize();
	bool isEmpty();
};

