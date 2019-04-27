#pragma once
#include "Queue.h"

class Iterator {
	int index;
	Queue *queue;
public:
	friend class Queue;
	Iterator(Queue* &que);
	void start();
	void next();
	bool finish();
	int getValue();
};
