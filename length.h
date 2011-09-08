#ifndef __LENGTH_H__
#define __LENGTH_H__
#include <libxml/tree.h>

typedef enum LengthType{
	LENGTHTYPE_UNKNOWN = 0,
	LENGTHTYPE_NUMBER = 1,
	LENGTHTYPE_PERCENTAGE = 2,
	LENGTHTYPE_EMS = 3,
	LENGTHTYPE_EXS = 4,
	LENGTHTYPE_PX = 5,
	LENGTHTYPE_CM = 6,
	LENGTHTYPE_MM = 7,
	LENGTHTYPE_IN = 8,
	LENGTHTYPE_PT = 9,
	LENGTHTYPE_PC = 10,
}LengthType;

class Length{
private:
	float _value;
public:
	LengthType type;
	float	valueInSpecifiedUnits;
	xmlChar* valueAsString;

	Length();
	~Length();
	
	float value();
	void newValue(xmlChar* value);
};

#endif
