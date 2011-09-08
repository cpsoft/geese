#include <stdio.h>
#include "rect.h"

Rect::Rect(){
	printf("Rect\n");
}

Rect::~Rect(){
	printf("~Rect\n");
	
}

bool Rect::init(xmlNodePtr node){
	xmlChar* szAttr;
	if (NULL == node){
		return false;
	}
	_width.newValue(xmlGetProp(node, BAD_CAST"width"));
	_height.newValue(xmlGetProp(node, BAD_CAST"height"));
	printf("%s:width = %f\n", node->name, _width.value());
	printf("%s:height = %f\n", node->name, _height.value());
	return 0;
}

Element* CreateRect(xmlNodePtr node){
	Rect* rect;
	rect = new Rect();
	rect->init(node);
	return (Element*) rect;
}
