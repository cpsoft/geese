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
	szAttr = xmlGetProp(node, BAD_CAST"width");
	printf("%s:width = %s\n", node->name, szAttr);
	szAttr = xmlGetProp(node, BAD_CAST"height");
	printf("%s:height = %s\n", node->name, szAttr);
	return 0;
}

Element* CreateSvg(xmlNodePtr node){
	Svg* svg;
	svg = new Svg();
	svg->init(node);
	return (Element*) svg;
}
