#pragma once
#include <stdlib.h>
#include "inverbal.h"
class tree : public obj3dmodel
{
public:
	tree();
	void setvalue(double x, double y, double z, bool inner)
	{
		if (inner) this->x = -x;
		else this->x = x;
		this->y = y;
		this->z = z;
	}
	double gety() {
		return this->y;
	}
	void randomvalue();
	~tree();
	void render(GLuint treetexture);
	void idle();
private:
	int type = 0;//0->tree,1->house
	double x, y, z, h;
public:
	int state = rand() % 2;
};

