#include <stdlib.h>
#include "length.h"

Length::Length(){
}

Length::~Length(){
	if (NULL != valueAsString){
		xmlFree(valueAsString);
		valueAsString = NULL;
	}
}


void Length::newValue(xmlChar* value){
	int len;
	xmlChar *start, *end;
	if (NULL == value){
		return;
	}

	_value = atof((char*)value);
}

float Length::value(){
	return _value;
}
