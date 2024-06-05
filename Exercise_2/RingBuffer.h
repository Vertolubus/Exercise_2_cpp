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
	~RingBuffer();

	bool isEmpty() const; // true, ���� ������� �����
	bool full() const; // true, ���� ������� �����

	void push(const int& a); // �������� � ����� �������
	int& pop(); // ����� ������ ������� �������
	int front() const; // ���������� ������ �������
	void makeEmpty(); //�������� �������

	int arrSize() const;
};
