#ifndef __SVG_H__
#define __SVG_H__
#include <libxml/tree.h>
#include "element.h"
#include "length.h"

class Svg:public Element{
private:
	Length _width;
	Length _height;
public:
	Svg();
	~Svg();

	bool init(xmlNodePtr node);
};

Element* CreateSvg(xmlNodePtr node);

#endif
