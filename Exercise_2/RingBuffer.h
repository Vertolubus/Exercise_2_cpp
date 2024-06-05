#pragma once
#include <iostream>

class RingBuffer {
private:
	int *arr;
	int size;
	int maxSize;
	int tail;
	int head;

public:
	RingBuffer();
	RingBuffer(int size);
	//RingBuffer(const RingBuffer& rb);
	//RingBuffer(RingBuffer&& rb);
	//RingBuffer& operator=(const RingBuffer& rb); 
	//RingBuffer& operator=(RingBuffer&& rb); 
	//int& operator[](int i); 
	//const int& operator[](int i) const;
	~RingBuffer();

	bool isEmpty() const; // true, если очередь пуста
	bool full() const; // true, если очередь полна

	void push(const int& a); // добавить в конец очереди
	int& pop(); // взять первый элемент очереди
	int front() const; // посмотреть первый элемент
	void makeEmpty(); //очистить очередь

	int arrSize() const;
};
