#include "tree.h"

tree::tree()
{
	randomvalue();
	obj3dmodel::obj3dmodel();
	if (state == 0)
		obj3dmodel::read("tree01.obj");
	else if (state == 1)
		obj3dmodel::read("tree02.obj");
	else if (state == 2)
		obj3dmodel::read("house.obj");
}

void tree::randomvalue()
{
	x = -20.0;
	z = TREEBOTTOM;
	y = (1 - 2 * (rand() % 10)) * 20;
}

tree::~tree()
{
}

void tree::render(GLuint treetexture)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, treetexture);
	glRotatef(90, 1, 0, 0);
	switch (state) {
	case 0:
		glScalef(0.1f, 0.1f, 0.1f); break;
	case 1:
		glScalef(0.5f, 0.5f, 0.5f); break;
	case 2:
		glScalef(0.5f, 0.5f, 0.5f); break;
	}
	obj3dmodel::render();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void tree::idle()
{

}
