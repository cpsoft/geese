#include <stdio.h>
#include "svg.h"

Svg::Svg(){
	printf("Svg\n");
}

Svg::~Svg(){
	printf("~Svg\n");
}

bool Svg::init(xmlNodePtr node){
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

Element* CreateSvg(xmlNodePtr node){
	Svg* svg;
	svg = new Svg();
	svg->init(node);
	return (Element*) svg;
}
