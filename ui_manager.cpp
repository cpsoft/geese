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
	if (NULL == node){
		return NULL;
	}

	_factory->create(node);
	layout(node->xmlChildrenNode);
	layout(node->next);
	return NULL;
}

void UIManager::layout(){
	xmlNodePtr root, node;
	root = _parser->root();
	if (NULL == root){
		return;
	}

	_root = layout(root);
}
