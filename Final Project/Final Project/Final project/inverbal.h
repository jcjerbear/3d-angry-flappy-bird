#pragma once
#define FREEGLUT_STATIC
#include <vector>
#include <string>
#include "GL/freeglut.h"
#include <GL/gl.h>
#include <iostream>
using namespace std;

const double bird_r = 0.5;
const double tube_r = 1.5;
const double tube_bottom = -20.0;
const double tube_top = 20.0;
const double vspeed = 0.015;
const double g = 0.00018;
const double cam2bird = 8.0;
const double SPEE = 0.02;
const double DTIME = 0.016;
const double ROTATE_SPEED = 0.1;
const double TUBEBLANK = 10.0;
const int MAXHEIGHT = 5;
/**/const int TREEMAXHEIGHT = 30;
/**/const double TREEBOTTOM = -20;

/**/enum rotater
{
    X2B,
    Y2B,
    INL,
    INR,
};

class obj3dmodel {
protected:
	struct vertex {
		double x, y, z;
	};
	struct texel {
		double x, y;
	};
	struct face {
		unsigned int v1, v2, v3;
	};
	vector <vertex> vertices;
	vector <texel> texcoords;
	vector <vertex> normalVertices;
	vector <face> faces;
	vector <face> texfaces;
	vector <face> normalFaces;
public:
	obj3dmodel();
	~obj3dmodel();
	void read(const char* path);
	void render();
};

void skyrender();