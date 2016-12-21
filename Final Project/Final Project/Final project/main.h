#pragma once
#define FREEGLUT_STATIC
#include "GL/freeglut.h"
#include <GL/gl.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include <mmsystem.h>
#include "bird.h"
#include "shot.h"
#include "tube.h"
#include "ground.h"
#include "buff.h"
#include "tree.h"
#include "textrender.h"
#define WindowWidth  500
#define WindowHeight 500
#define BMP_Header_Length 54

const int HEIGHT = 640;
const int WIDTH = 480;
const int tubeAmount = 10;
const int SLICE = 20;

GLuint texture_ID;
GLuint birdtexture;
GLuint pipetexture;
GLuint treetexture;
GLuint tree02texture;
GLuint housetexture;
GLuint groundtexture;
GLuint magic;

GLfloat ambient[] = { 0.2f, 0.2f, 0.2f };
GLfloat diffuse[] = { 0.8f, 0.8f, 0.8f };
GLfloat specular[] = { 0.0f, 0.0f, 0.0f };
GLfloat position[] = { -1.5f, 1.0f, -4.0f, 1.0f };

enum gamestat
{
    START,
    RUNNING,
    OVER,
};
void scoredetect(tube ttt[10], tube ddd[10], double x, double y, double z);
void tubeControl(tube ttt[10], double x, double y, double z, bool up);
void tubeControl(tree ttt[10], double x, double y, double z, bool up);
static int AddKeyModifier(int key);
static int ConvertSpecialKey(int special);
static void ChangeSize(int w, int h);
static void RenderScene(void);
static void SpecialKeys(int key, int x, int y);
static void SpecialKeysUp(int key, int x, int y);
static void KeyboardFunc(unsigned char cAscii, int x, int y);
static void KeyboardFuncUp(unsigned char cAscii, int x, int y);
static void MouseClickMessage(int button, int state, int x, int y);
static void MouseMoveMessage(int x, int y);
static void MouseWheelMessage(int wheel, int dir, int x, int y);
static void MousePassiveMoveMessage(int x, int y);
static void MyIdle(void);
void grab();
int power_of_two(int n);
GLuint load_texture(const char* file_name);
void output(double x, double y, double z, char* string);
