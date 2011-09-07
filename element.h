#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include <vector>

using namespace std;

class Element{
private:
	Element* _next;
	Element* _prev;
	Element* _parent;
	vector<Element*> _children;

public:
	Element();
	~Element();
	Element* next();
	Element* prev();	
};

#endif
