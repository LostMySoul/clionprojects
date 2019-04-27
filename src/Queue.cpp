#include "Queue.h"

Queue::Queue(int size) {
	flag = true;
	arr = new double[size];
	this->size = size;
	firstPointer = 0;
	lastPointer = 0;
}

Queue::Queue(const Queue &copy) {
	flag = copy.flag;
	this->size = copy.size;
	firstPointer = copy.firstPointer;
    lastPointer = copy.lastPointer;
	arr = new double[copy.size];
	for (int i = 0; i < size; i++) {
		arr[i] = copy.arr[i];
	}
}

void Queue::addElement(double element) {
	if ((lastPointer + 1) % size == firstPointer) {
		throw SizeException();
	}
	if (flag) {
		arr[lastPointer] = element;
		flag = false;
	}
	else {
		lastPointer++;
		lastPointer = lastPointer%size;
		arr[lastPointer] = element;
	}
}

double Queue::getElem() {
	if (flag) {
		throw EmptyException();
	}
	if (firstPointer == lastPointer) {
		flag = true;
		return arr[firstPointer];
	}
	if (firstPointer != lastPointer) {
		firstPointer++;
		return arr[firstPointer - 1];
	}
}

double Queue::peek() {
	if (flag) {
		throw EmptyException();
	}
	return arr[firstPointer];
}
int Queue::getSize() {
	return size;
}
void Queue::empty() {
	firstPointer = lastPointer;
	flag = true;
}

bool Queue::isEmpty() {
	return flag;
}
