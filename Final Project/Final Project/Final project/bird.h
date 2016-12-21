#pragma once
#include "inverbal.h"
#include <vector>
using namespace std;
class bird: public obj3dmodel
{
public:
    bird(const char* objpath);
    ~bird();
    double getx() {
        return x;
    }
    double gety()
    {
        return y;
    }
    double getz() {
        return z;
    }
    double getvx() {
        return vx;
    }
    double getvy() {
        return vy;
    }
    double getvz() {
        return vz;
    }
    /**/double getly() {
        return ly;
    }
    /**/double getlz() {
        return lz;
    }
    void moveUp();
    void idle(bool rotate);
	void render(GLuint birdtexture);
private:
    double x = 0;
    double y = 0;
    double z = 0;
    const double lx = 0;
    double ly = 1;
    double lz = 0;
    double timevar = 0.0;
    const double vx = 0.0;
    const double vy = vspeed;
    double vz = 0.0;
};

