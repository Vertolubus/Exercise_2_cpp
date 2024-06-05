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

	bool isEmpty() const; // true, ���� ������� �����
	bool full() const; // true, ���� ������� �����

	void push(const int& a); // �������� � ����� �������
	int& pop(); // ����� ������ ������� �������
	int front() const; // ���������� ������ �������
	void makeEmpty(); //�������� �������

	int arrSize() const;
};
