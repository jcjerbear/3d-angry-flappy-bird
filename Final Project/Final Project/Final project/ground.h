#pragma once
#define FREEGLUT_STATIC
#include "GL/freeglut.h"
#include <GL/gl.h>
#include "inverbal.h"
class ground
{
    const int witdth = 50000;
    int length = 50000;
    int loc = 0;
    const int backlength = 10000;
public:
    ground();
    ~ground();
    void render();
    void setloc(int loc)
    {
        this->loc = loc;
    }
};

