#include "ground.h"



ground::ground()
{
}


ground::~ground()
{
}

void ground::render()
{
    GLfloat color[] = {0/255.0,238/255.0,62.0/255.5};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5*witdth,-1.0*backlength,tube_bottom);
    glVertex3f(-0.5*witdth,length -1.0 * backlength, tube_bottom);
    glVertex3f(0.5*witdth, length- 1.0 * backlength, tube_bottom);
    glVertex3f(0.5*witdth, -1.0 * backlength, tube_bottom);
    glEnd();
}
