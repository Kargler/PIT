#ifndef LISTENELEMENT_H
#define LISTENELEMENT_H

#include "SchaltwerkElement.h"

class ListenElement
{
private:
	SchaltwerkElement* schaltwerkElement;
	ListenElement* next;

public:
	ListenElement(void);
	~ListenElement(void);

	SchaltwerkElement* getSchaltwerkPointer() { return schaltwerkElement; }
};

#endif