#include "shot.h"
shot::~shot()
{
}

/**/void shot::idle(double x, double y)
{
    if (X2B == stats)
    {
        px = x + DST;
        py = y;
        pz = 0;
        lx = x;
        ly = y;
        lz = 0;
    }
    else if (Y2B == stats)
    {
        px = x;
        py = y - DST;
        pz = 0;
        lx = x;
        ly = y;
        lz = 0;
    }
    else if (INL == stats)
    {
        timevar += DTIME;
        px = x + DST*cos(timevar);
        py = y - DST*sin(timevar);
        if (px <= x + 0.1&&px >= x - 0.1)
        {
            timevar = 0.0;
            stats = Y2B;
        }
    }
    else
    {
        timevar += DTIME;
        px = x + DST*sin(timevar);
        py = y - DST*cos(timevar);
        if (py <= y + 0.1&&py >= y - 0.1)
        {
            timevar = 0.0;
            stats = X2B;
        }
    }
}


void shot::switchLeft()
{
    if (X2B == stats)
    {
        stats = INL;
    }
}

void shot::switchRight()
{
    if (Y2B == stats)
    {
        stats = INR;
    }
}

bool shot::inRotation()
{
    bool ok = false;
    if (INL == stats || INR == stats)
    {
        ok = true;
    }
    return ok;
}
