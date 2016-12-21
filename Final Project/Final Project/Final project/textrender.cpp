#include"textrender.h"
void textrender::calOffset(const unsigned char word[3])
{
    offset = (94 * (unsigned int)(word[0] - 0xa0 - 1) + (word[1] - 0xa0 - 1)) * 32;
    getBuffer();
}
void textrender::calOffset(unsigned char a)
{
    offset= ((3 - 1) * 94 + a - 32 - 1) * 32;
    getBuffer();
}
void  textrender::getBuffer()
{
    buffer = (short int*)malloc(sizeof(short int) * 16);
    fseek(hzk, offset, SEEK_SET);
    fread(buffer, 1, 32, hzk);
}
textrender::~textrender()
{
    free(buffer);
    fclose(hzk);
}
textrender::textrender()
{
        if (NULL == (hzk = fopen("Hzk16", "rb")))
        {
            textrender::~textrender();
        }
}

void textrender::drawText(int x, int y, int size, float r, float g, float b, int inverse, int fade, int kong, int ilas)
{
    if (kong)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    if (!fade)
    {
        glColor3f(r, g, b);
    }
    for (int m = 0; m < 16; m++)
    {
        for (int n = 0; n < 16; n++)
        {
            int i = n, j = m;
            if (fade)
            {
                if (i + j <= 15)
                    glColor3f(1.0 - (i + j) / 30.0, (i + j) / 15.0, (i + j) / 30.0);
                else
                    glColor3f(1.0 - (i + j) / 30.0, 1 - (i + j - 15) / 15.0, (i + j) / 30.0);
            }
            short int mask = (0x0080 >> i);
            if (!mask)
            {
                mask = (0x8000 >> (i - 8));
            }
            if (ilas)
            {
                i = n + (15 - j) / 2;
            }
            if (buffer[j] & mask)
            {
                if (inverse)
                {
                    j = 15 - m;
                }
                glBegin(GL_POLYGON);
                glVertex2i(x + i*size, y + j*size);
                glVertex2i(x + i*size + size, y + j*size);
                glVertex2i(x + i*size + size, y + j*size + size);
                glVertex2i(x + i*size, y + j*size + size);
                glEnd();
            }
        }
    }
}

void textrender::drawText3(double x, double y, double z, double size, float r, float g , float b , int inverse, int fade , int kong , int ilas )
{
    if (kong)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    if (!fade)
    {
        GLfloat color[] = { r,g,b };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
    }
    for (int m = 0; m < 16; m++)
    {
        for (int n = 0; n < 16; n++)
        {
            int i = n, j = m;
            if (fade)
            {
                if (i + j <= 15)
                {
                    GLfloat color[] = { 1.0 - (i + j) / 30.0, (i + j) / 15.0, (i + j) / 30.0 };
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
                }
                else
                {
                    GLfloat color[] = { 1.0 - (i + j) / 30.0, 1 - (i + j - 15) / 15.0, (i + j) / 30.0 };
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
                }
            }
            short int mask = (0x0080 >> i);
            if (!mask)
            {
                mask = (0x8000 >> (i - 8));
            }
            if (ilas)
            {
                i = n + (15 - j) / 2;
            }
            if (buffer[j] & mask)
            {
                if (inverse)
                {
                    j = 15 - m;
                }
                glBegin(GL_POLYGON);
                glVertex3f(x + i*size, y + j*size,z);
                glVertex3f(x + i*size + size, y + j*size,z);
                glVertex3f(x + i*size + size, y + j*size + size,z);
                glVertex3f(x + i*size, y + j*size + size,z);
                glEnd();
            }
        }
    }
}
