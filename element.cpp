#include <stdio.h>
#include <stdlib.h>
#include "element.h"

Element::Element(){
	_parent = NULL;
	_prev = _next = NULL;
	
}

Element::~Element(){

}

Element* Element::next(){
	return NULL;
}

Element* Element::prev(){
	return NULL;
}
