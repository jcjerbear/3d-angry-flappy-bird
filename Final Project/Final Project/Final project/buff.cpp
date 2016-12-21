#include "buff.h"


void buff::render()
{
    if (activited)
    {
        GLfloat color[] = { 192.0 / 255.0,1.0,62.0 / 255.5 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
        glPushMatrix();
        glTranslatef(x, y, z);
        //std::cout << z << std:: endl;
        glutSolidSphere(radius, 50, 50);
        glPopMatrix();
        glFlush();
    }
}

bool buff::magic(double x, double y, double z)
{
    bool ko = false;
    //std::cout << this->y << std::endl ;
    if (activited)
    {
		//PlaySound("speed.wav", NULL, SND_SYNC | SND_FILENAME | SND_LOOP);
        double dxx = (x - this->x)*(x - this->x);
        double dyy = (y - this->y)*(y - this->y);
        double dzz = (z - this->z)*(y - this->z);
        if (dxx + dyy + dzz < (radius + bird_r)*(radius + bird_r))
        {
            activited = false;
            function = true;
			PlaySound("speed.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        }
    }
    else if (function)
    {
        timevar += 0.5;
		if (timevar > timelength)
        {
			PlaySound("bgm.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            function = false;
        }
        else
        {
           
            ko = true;
        }
    }
    return ko;
}
