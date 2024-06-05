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

//RingBuffer::RingBuffer(const RingBuffer& rb) : size(rb.size), maxSize(rb.maxSize) {
//	this->arr = new int[maxSize];
//
//	for (int i = 0; i < maxSize; i++) {
//		this->arr[i] = rb.arr[i];
//	}
//}

//RingBuffer::RingBuffer(RingBuffer&& rb) : size(rb.size), maxSize(rb.maxSize) {
//	this->arr = new int[size + maxSize];
//
//	for (int i = 0; i < size; i++) {
//		this->arr[i] = rb.arr[i];
//	}
//
//	for (int i = size; i < size + maxSize; i++) {
//		this->arr[i] = 0;
//	}
//
//	rb.size = 0;
//	rb.maxSize = 0;
//	rb.arr = nullptr;
//}
//
//RingBuffer& RingBuffer::operator=(const RingBuffer& obj) {
//	if (this == &obj) {
//		return *this;
//	}
//	RingBuffer copy(obj);
//	std::swap(size, copy.size);
//	std::swap(maxSize, copy.maxSize);
//	std::swap(arr, copy.arr);
//	return *this;
//}
//
//RingBuffer& RingBuffer::operator=(RingBuffer&& obj) {
//	if (this == &obj) {
//		return *this;
//	}
//	std::swap(size, obj.size);
//	std::swap(maxSize, obj.maxSize);
//	std::swap(arr, obj.arr);
//	obj.arr = nullptr;
//	obj.size = 0;
//	obj.maxSize = 0;
//	return *this;
//}
//
//int& RingBuffer::operator[](int i) {
//	return arr[i];
//}
//
//const int& RingBuffer::operator[](int i) const {
//	return arr[i];
//}

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





