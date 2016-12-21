#pragma once
#include "inverbal.h"
#include <cmath>

class shot
{
public:
    shot(double x, double y, double z)
    {
        px = x + DST;
        py = y;
        pz = z;
        lx = x;
        ly = y;
        lz = z;
    }
    ~shot();
    void idle(double x, double y);
    void switchLeft();
    void switchRight();
    bool inRotation();
    double px;
    double py;
    double pz;
    double lx;
    double ly;
    double lz;
    const double cx = 0;
    const double cy = 0;
    const double cz = 1;
    const double DST = cam2bird;
    rotater getStats() {
        return stats;
    }
private:
	
    double timevar = 0.0;
    rotater stats = X2B;
};

