#include "RingBuffer.h" 
#include "ElementIsMissing.h"
#include "ArrayOverflow.h"

RingBuffer::RingBuffer() : size(1), head(0), tail(0), maxSize(size + 1){
	arr = nullptr;
	this->arr = new int[maxSize];
}


RingBuffer::RingBuffer(const int size) : size(size), head(0), tail(0), maxSize(size + 1) {
	this->arr = new int[maxSize];

	for (int i = 0; i < size + maxSize; i++) {
		arr[i] = 0;
	}
}


RingBuffer::~RingBuffer() {
	delete[] arr;
	arr = nullptr;
}

bool RingBuffer::isEmpty() const{
	return tail == head;
}

bool RingBuffer::full() const{
	return (tail + 1) % maxSize == head;
}

void RingBuffer::push(const int& a) {
	if (full()) {
		throw ArrayOverflow("Массив полный!");
	}
	arr[tail] = a;
	tail = (tail + 1) % maxSize;
}

int& RingBuffer::pop() {
	if (isEmpty()) {
		throw ElementIsMissing("Массив пуст!");
	}
	int temp = arr[head];
	head = (head + 1) % maxSize;
	return temp;
}

int RingBuffer::front() const{
	if (isEmpty()) {
		throw ElementIsMissing("Массив пуст!");
	}
	return arr[head];
}

void RingBuffer::makeEmpty() {
	while (!isEmpty()) {
		pop();
	}
}

int RingBuffer::arrSize() const
{
	return (tail - head + maxSize + 1) % (maxSize + 1);
}





