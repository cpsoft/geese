#include <stdio.h>
#include <stdlib.h>
#include "element.h"

Element::Element(){
	_parent = _child = NULL;
	_prev = _next = this;
	
}

Element::~Element(){

}

Element* Element::next(){
	if (_next == this){
		return NULL;
	}
	return _next;
}

Element* Element::prev(){
	if (_prev == this){
		return NULL;
	}
	return _prev;
}

Element* Element::child(){
	return _child;
}

bool Element::setParent(Element* parent){
	_parent = parent;
}

bool Element::addChild(Element* child){
	_child = child;
	if (NULL != child){
		child->setParent(this);
	}
	return true;
}

bool Element::addNeighbor(Element* neighbor){
	if (NULL == neighbor){
		return false;
	}
	neighbor->_prev = this;
	neighbor->_next = _next;
	_next->_prev = neighbor;
	_next = neighbor;
	neighbor->setParent(_parent);
}
