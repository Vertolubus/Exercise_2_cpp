#pragma once
#include <exception>

class ElementIsMissing : public std::exception {
public:
	ElementIsMissing(const char* theMessage) : exception(theMessage) { }
};