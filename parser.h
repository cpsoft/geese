#ifndef __PARSER_H__
#define __PARSER_H__
#include <libxml/parser.h>
#include <libxml/tree.h>

class Parser{
private:
	xmlDocPtr _doc;
	xmlNodePtr _root;

public:
	~Parser();
	void open(char* filename);
	void close();

	xmlNodePtr root();

#ifdef DEBUG
	void dump();
#endif
};

#endif
