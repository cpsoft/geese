#ifndef __ELEMENT_FACTORY_H__
#define __ELEMENT_FACTORY_H__
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "element.h"


class ElementFactory{
public:
	ElementFactory();
	~ElementFactory();

	Element* create(xmlNodePtr node);
};

#endif
