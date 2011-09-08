#ifndef __ELEMENT_FACTORY_H__
#define __ELEMENT_FACTORY_H__
#include <string>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "element.h"


typedef Element* (*Create)(xmlNodePtr);
typedef struct Tag{
	xmlChar* name;
	Create create;
}TAG;

class ElementFactory{
private:
	Tag* _tags;

public:
	ElementFactory();
	~ElementFactory();

	Element* create(xmlNodePtr node);
};

#endif
