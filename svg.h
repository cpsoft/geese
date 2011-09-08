#ifndef __SVG_H__
#define __SVG_H__
#include <libxml/tree.h>
#include "element.h"

class Svg:public Element{
private:
	unsigned int _width;
	unsigned int _height;
public:
	Svg();
	~Svg();

	bool init(xmlNodePtr node);
};

Element* CreateSvg(xmlNodePtr node);

#endif
