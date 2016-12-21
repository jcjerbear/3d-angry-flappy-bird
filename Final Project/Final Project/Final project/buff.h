#pragma once
#include "inverbal.h"
#include <Windows.h>
#include <mmsystem.h>
enum bufftype {
    NOMAGIC,
    POWM,
};

class buff {
    double x, y, z;
    const double radius = 0.5;
    bufftype bftp;
    const double timelength = 2000.0;
    double timevar = 0.0;
    bool activited = false;//if activited display the buff
    bool function = false;
public:
    buff()
    {
        bftp = POWM;
    }
    void setloc(double x,double y,double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        activited = true;
        function = false;
        timevar = 0.0;
    }
    void render();
    bool magic(double x, double y, double z);
    bool getact() {
        return activited;
    }
};