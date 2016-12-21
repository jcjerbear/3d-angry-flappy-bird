#include "bird.h"



bird::bird(const char* objpath)
{
	obj3dmodel::obj3dmodel();
	obj3dmodel::read(objpath);
}


bird::~bird()
{
}

void bird::moveUp()
{
    vz = SPEE;
}

/**/void bird::idle(bool rotate)
{
    if (!rotate)
    {
        x += vx;
        y += vy;
        z += vz;
        vz -= g;
        lz = vz * 40;
    }
}

void bird::render(GLuint birdtexture) {
	glEnable(GL_TEXTURE_2D);
	GLfloat birdcolor[] = { 0.309804, 0.184314, 0.184314 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, birdcolor);
	glPushMatrix();
	glScalef(0.01, 0.01, 0.01);
	glBindTexture(GL_TEXTURE_2D, birdtexture);
	glRotatef(90, 1.0, 0, 0.0);
	glRotatef(165, 0.0, 1.0, 0.0);
	glTranslatef(x, y, z);
    glRotatef(180*atan2f(lz,ly)/3.14159, -1, 0, 0);
	obj3dmodel::render();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
