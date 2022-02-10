#ifndef NODE_H
#define NODE_H


#include "Area.h"

struct areaNode
{
	Area info;
	areaNode *u;
	areaNode *d;
	areaNode *l;
	areaNode *r;
};

#endif