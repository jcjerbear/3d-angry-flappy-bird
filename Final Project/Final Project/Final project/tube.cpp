#include "tube.h"





tube::tube()
{
	obj3dmodel::obj3dmodel();
	obj3dmodel::read("pipeobj.obj");
}

tube::~tube()
{
}

/**/bool tube::idle(double xx, double yy, double zz,  rotater rotk)
{
    bool ok = true;
        if (toward)
        {
            if (X2B == rotk)
            {
                if (zz < tube_bottom + h + bird_r&&yy>y - bird_r - tube_r&&yy < y + tube_r + bird_r || zz < tube_bottom)
                {
                    ok = false;
                }
            }
            else
            {
                if (zz < tube_bottom + h + bird_r&&yy>y - bird_r&&yy < y + tube_r + bird_r &&xx<x + tube_r + bird_r&&xx>x - tube_r - bird_r || zz < tube_bottom)
                {
                    ok = false;
                }
            }
        }
        else
        {
            if (X2B == rotk)
            {
                if (zz > tube_top - h - bird_r&&yy > y - bird_r&&yy < y + tube_r + bird_r || zz > tube_top)
                {
                    ok = false;
                }
            }
            else
            {
                if (zz > tube_top - h - bird_r&&yy > y - bird_r&&yy < y + tube_r + bird_r &&xx<x + tube_r + bird_r&&xx>x - tube_r - bird_r || zz > tube_top)
                {
                    ok = false;
                }
            }
        }
    return ok;
}


void tube::render(GLuint pipetexture) {
	GLfloat pipecolor[] = { 0.0f, 0.5f, 0.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, pipecolor);
	obj3dmodel::render();
}