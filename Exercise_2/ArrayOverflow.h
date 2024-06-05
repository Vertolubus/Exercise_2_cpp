#pragma once
#include <exception>

class ArrayOverflow : public std::exception {
public:
	ArrayOverflow(const char* theMessage) : exception(theMessage) { }
};