#pragma once
#include <cmath>
#include "inverbal.h"
class tube : public obj3dmodel
{
public:
    tube();
    ~tube();
    /**/bool idle(double x, double y, double z, rotater rotk);
    double geth()
    {
        return h;
    }
    double gety()
    {
        return y;
    }
    /**/double getx()
    {
        return x;
    }
    void setloc(double x, double y, double h,bool up)
    {
        this->x = x;
        this->y = y;
        this->h = h;
        toward = up;
    }
	void render(GLuint pipetexture);
private:
    double x = 0.0;
    double y;
    const double z=-10;
    double h;
    double timevar=0.0;
    const double r = 5.0;
    bool toward;
};

