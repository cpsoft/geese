#include "element_factory.h"

ElementFactory::ElementFactory(){
}

ElementFactory::~ElementFactory(){
}

Element* ElementFactory::create(xmlNodePtr node){
	if (NULL == node || NULL == node->name){
		return NULL;
	}
	printf("%s\n", node->name);
	
	return NULL;
}
