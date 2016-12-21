#pragma once
#define FREEGLUT_STATIC
#include "GL/freeglut.h"
#include <GL/gl.h>
#include<stdio.h>
#include<stdlib.h>

class textrender {
    FILE *hzk = NULL;
    int offset = 0;
    short int* buffer = NULL; 
    void getBuffer();
    
public:
    textrender();
    ~textrender();
    void drawText(int x, int y, int size, float r, float g, float b, int inverse, int fade, int kong, int ilas);
    void textrender::drawText3(double x, double y, double z, double size, float r = 1.0, float g = 1.0, float b = 1.0, int inverse = 0, int fade = 0, int kong = 0, int ilas = 0);
    void calOffset(const unsigned char word[3]);
    void calOffset(unsigned char a);
};