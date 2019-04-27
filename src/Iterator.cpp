#include "Iterator.h"

Iterator::Iterator(Queue* &que) {
	this->index = que->firstPointer-1;
	this->queue = que;
}

void Iterator::start() {
	index = queue->firstPointer - 1;
}

void Iterator::next() {
	index++;
	index = index%queue->size;
}

bool Iterator::finish() {
	if (queue->lastPointer != index && !queue->isEmpty()) {
		return false;
	}
	return true;
}

int Iterator::getValue() {
	return queue->arr[index];
}
