#ifndef __ELEMENT_H__
#define __ELEMENT_H__

class Element{
private:
	Element* _next;
	Element* _prev;
	Element* _parent;
	Element* _child;

public:
	Element();
	~Element();
	Element* next();
	Element* prev();
	Element* child();
	bool setParent(Element* parent);
	bool addChild(Element* child);
	bool addNeighbor(Element* neighbor);
};

#endif
