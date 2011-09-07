#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include "parser.h"
#include "element.h"
#include "element_factory.h"

class UIManager{
private:
	Parser* _parser;
	ElementFactory* _factory;
	Element* _root;

	Element* layout(xmlNodePtr node);

public:
	UIManager();
	~UIManager();
	void open(char* filename);
	void layout();
};

#endif
