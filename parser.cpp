#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "parser.h"

Parser::~Parser(){
}

void Parser::open(char* filename){
	if (NULL == filename){
		return;
	}

	_doc = xmlReadFile(filename, "UTF-8", XML_PARSE_RECOVER);
	if (_doc == NULL){
		printf ("open %s faild.\n", filename);
		return;
	}

	_root = xmlDocGetRootElement (_doc);
	if (_root == NULL){
		printf("Error: %s is empty(hasn't root node.\n", filename);
		return;
	}

	return;
}

void Parser::close(){
	xmlFreeDoc(_doc);
	xmlCleanupParser();
}

xmlNodePtr Parser::root(){
	if (NULL == _root){
		return NULL;
	}
	return _root;
}

#ifdef DEBUG
void Parser::dump(){
	xmlNodePtr curNode = NULL;
	if (NULL == _root){
		return;
	}

	if (xmlHasProp (_root, BAD_CAST "version")){
		xmlChar* szAttr = xmlGetProp (_root, BAD_CAST "version");
		printf ("version: %s\n root: %s\n", szAttr, _root->name);
	}else{
		printf ("xml hasn't version info\n");
	}

	curNode = _root->xmlChildrenNode;
	char n = 0;
	while (curNode != NULL){
		if (curNode->name != BAD_CAST "text"){
			printf ("child%d: %s\n", n++, curNode->name);
		}
		curNode = curNode->next;
	}
}
#endif
