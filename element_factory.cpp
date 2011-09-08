#include "element_factory.h"
#include "svg.h"
#include "rect.h"

static TAG tags[]={
	{BAD_CAST"rect", CreateRect},
	{BAD_CAST"svg", CreateSvg}
};

ElementFactory::ElementFactory(){
	_tags = tags;
}

ElementFactory::~ElementFactory(){
}

Element* ElementFactory::create(xmlNodePtr node){
	xmlChar* content = NULL;
	Element* element = NULL;
	int i;
	if (NULL == node || NULL == node->name){
		return NULL;
	}

	for (i = 0; i < sizeof(tags)/sizeof(TAG); i++){
		if(!xmlStrcmp(node->name, _tags[i].name)){
			element = _tags[i].create(node);
			return element;
		}
	}
#if 0
	if (NULL == element){
		if (!xmlStrcmp(node->name, BAD_CAST"text")){
			content = xmlNodeGetContent(node);
			printf("<%s>\n", content);
			xmlFree(content);
		}else if (!xmlStrcmp(node->name, BAD_CAST"comment")){
			content = xmlNodeGetContent(node);
			printf("/*%s*/\n", content);
			xmlFree(content);
		}else{
			printf("**%s\n", node->name);
		}
	}
#endif
	
	return element;
}
