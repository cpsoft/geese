#include "ui_manager.h"

UIManager::UIManager(){
	_parser = new Parser();
	_factory = new ElementFactory();
}

UIManager::~UIManager(){
	_parser->close();
	delete _factory;
	delete _parser;
}

void UIManager::open(char* filename){
	_parser->open(filename);
}

Element* UIManager::layout(xmlNodePtr node){
	Element* element= NULL;
	if (NULL == node){
		return NULL;
	}

	element = _factory->create(node);
	if (NULL == element){
		return NULL;
	}
	element->addChild(layout(node->xmlChildrenNode));
	element->addNeighbor(layout(node->next));
	return element;
}

void UIManager::layout(){
	xmlNodePtr root, node;
	root = _parser->root();
	if (NULL == root){
		return;
	}

	_root = layout(root);
}

void UIManager::freeLayout(Element* element){
	if (NULL == element){
		return;
	}

	freeLayout(element->child());
	freeLayout(element->next());
	delete element;
}

void UIManager::cleanLayout(){
	if (NULL == _root){
		return;
	}

	freeLayout(_root);
}
