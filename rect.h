#ifndef __RECT_H__
#define __RECT_H__
#include <libxml/tree.h>
#include "element.h"
#include "length.h"

class Rect:public Element{
private:
	unsigned int _x;
	unsigned int _y;
	Length _width;
	Length _height;
	Length _rx;
	Length _ry;

public:
	Rect();
	~Rect();

	bool init(xmlNodePtr node);
};

Element* CreateRect(xmlNodePtr node);

#endif
