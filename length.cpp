#include <stdlib.h>
#include <string.h>
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
	char *start, *end = NULL;
	if (NULL == value){
		return;
	}
	start = (char*)value;

	_value = strtof(start, &end);
	if(end && strcmp(end, "px") != 0){
		if(!strcmp(end, "%")){
			type = LENGTHTYPE_PERCENTAGE;
		}
	}else{
		type = LENGTHTYPE_PX;
	}
}

float Length::value(){
	return _value;
}
