#include "main.h"

textrender trender;
int sc=0;
int highscore;
bird bbb("abobj.obj");
shot cam(0, 0, 0);
tube ttt[tubeAmount];
tube ddd[tubeAmount];
buff buf;
tree inner_tree[tubeAmount];
tree outer_tree[tubeAmount];
bool bird_buff = false;
char s[]="    ";
gamestat Game = START;
ground grnd;

void Init() {
	FILE* f = fopen("highscore.txt", "r");
	fscanf(f, "%d", &highscore);
	cout << "High score = " << highscore << endl;
	fclose(f);
}

void Write() {
	FILE* f = fopen("highscore.txt", "w");
	if (sc > highscore) {
		fprintf(f, "%d", sc);
	}
	fclose(f);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
	Init();
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    int handle = glutCreateWindow("Angry Flappy bird");
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
    srand(time(NULL));
    //object define
    
    // Register callback functions
    glutReshapeFunc(ChangeSize);
    //glutSpecialFunc(SpecialKeys);
    //glutSpecialUpFunc(SpecialKeysUp);
    glutKeyboardFunc(KeyboardFunc);
    //glutKeyboardUpFunc(KeyboardFuncUp);
    glutDisplayFunc(RenderScene);
    //glutMouseFunc(MouseClickMessage);
    //glutPassiveMotionFunc(MousePassiveMoveMessage);
    //glutMotionFunc(MouseMoveMessage);
    //glutMouseWheelFunc(MouseWheelMessage);
	birdtexture = load_texture("abtexture.bmp");
	pipetexture = load_texture("pipetexture.bmp");
	treetexture = load_texture("tree01texture.bmp");
	tree02texture = load_texture("tree02texture.bmp");
	housetexture = load_texture("housetexture.bmp");
	magic = load_texture("magic.bmp");
    glutIdleFunc(MyIdle);
    glutMainLoop();
}
static int AddKeyModifier(int key)
{}
static int ConvertSpecialKey(int special)
{}
static void ChangeSize(int w, int h)
{
    glutPostRedisplay();
}
static void RenderScene(void)
{  
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.53, 0.81, 0.98, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0, 1, 0.1, 300000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(10, 0, 0, 0, 0, 0, 0, 0, 1);
   // gluLookAt(cam.px, cam.py, cam.pz, cam.lx, cam.ly, cam.lz, cam.cx, cam.cy, cam.cz);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    if (START == Game)
    {
		output(bbb.getx(), bbb.gety(), bbb.getz(), "ass");
        
        glBegin(GL_POLYGON);
        glColor3f(1.0,1.0, 1.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
        glEnd();
        
    }
    else if (RUNNING == Game)
	{
		/*bird render*/
        gluLookAt(cam.px, cam.py, cam.pz, cam.lx, cam.ly, cam.lz, cam.cx, cam.cy, cam.cz);
        //gluLookAt(5, 0, 0, 0, 0, 0, 0, 0, 1);
        glPushMatrix();
        glTranslatef(bbb.getx()+6 * (cam.lx - cam.px)+10, bbb.gety()+6*(cam.ly- cam.py), bbb.getz());
        glRotatef(90, 1, 0, 0);
        glRotatef(270* (cam.lx - cam.px)/cam2bird, 0, 1, 0);
       // glRotatef(180/3.14159*atan2f(cam.lx-cam.px,cam.ly-cam.py), 0, 1, 0);
        
        _itoa(sc, s, 10);
        if (sc >= 100)
        {
            trender.calOffset(s[2]);
            trender.drawText3(20.0, 0.0, 0.0, 1.0, 1, 0, 1, 1, 1, 0, 0);
        }
        if (sc >= 10)
        {
            trender.calOffset(s[1]);
            trender.drawText3(10.0, 0.0, 0.0, 1.0, 1, 0, 1, 1, 1, 0, 0);
        }
        trender.calOffset(s[0]);
        trender.drawText3(0.0, 0.0, 0.0, 1.0, 1, 0, 1, 1, 1, 0, 0);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(bbb.getx(), bbb.gety(), bbb.getz());
        //printf("%lf %lf %lf %lf %lf %lf\n", cam.px, cam.py, cam.pz, cam.lx, cam.ly, cam.lz);
        glColor3f(1.0, 0.0, 0.0);
       
		if (bird_buff) bbb.render(magic);
		else bbb.render(birdtexture);
        glPopMatrix();
       
        glColor3f(0, 1, 0);
		GLfloat currentx, currenty, currentz;
        GLUquadricObj   *quad[tubeAmount];
        /**/for (int i = 0; i < tubeAmount; i++)
        {
			currentx = ttt[i].getx(); currenty = ttt[i].gety(); currentz = tube_bottom;
			glPushMatrix();
			glTranslatef(currentx, currenty, currentz - 1.7);
			glRotatef(90, 1.0, 0, 0.0);
			ttt[i].render(pipetexture);
			glPopMatrix();

			/*quad[i] = gluNewQuadric();
			gluQuadricNormals(quad[i], GL_SMOOTH);
			gluQuadricTexture(quad[i], FALSE);
			glPushMatrix();
			glTranslatef(ttt[i].getx(), ttt[i].gety(), tube_bottom);
			gluCylinder(quad[i], tube_r, tube_r, ttt[i].geth(), SLICE, SLICE);
			glPopMatrix();*/
        }
        /**/for (int i = 0; i < tubeAmount; i++)
        {
            
			glPushMatrix();
			currentx = ddd[i].getx(); currenty = ddd[i].gety(); currentz = tube_top - ddd[i].geth();
			glTranslatef(currentx, currenty, currentz + 20.8);
			glRotatef(-90, 1.0, 0, 0.0);
			ddd[i].render(pipetexture);
			glPopMatrix();
			
			/*quad[i] = gluNewQuadric();
			gluQuadricNormals(quad[i], GL_SMOOTH);
			gluQuadricTexture(quad[i], FALSE);
			glPushMatrix();
			glTranslatef(ddd[i].getx(), ddd[i].gety(), tube_top - ddd[i].geth());
			gluCylinder(quad[i], tube_r, tube_r, tube_top, SLICE, SLICE);
			glPopMatrix();*/
            
            grnd.render();
            buf.render();
        }
		for (int i = 0; i < tubeAmount; i++) {
			switch (inner_tree[i].state) {
			case 0:
				inner_tree[i].render(treetexture); break;
			case 1:
				inner_tree[i].render(tree02texture); break;
			case 2:
				inner_tree[i].render(housetexture); break;
			}
			switch (outer_tree[i].state) {
			case 0:
				outer_tree[i].render(treetexture); break;
			case 1:
				outer_tree[i].render(tree02texture); break;
			case 2:
				outer_tree[i].render(housetexture); break;
			}
		}
        
        glColor3f(0, 0, 1);
        glFlush();
    }
    else if (OVER == Game)
    {
        glBegin(GL_POLYGON);

        glColor3f(1.0, 0.0, 0.0);

        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 0.0, 0.0);
        glEnd();
       
    }
    glFlush();
    glutSwapBuffers();
}
static void SpecialKeys(int key, int x, int y)
{}
static void SpecialKeysUp(int key, int x, int y)
{}
static void KeyboardFunc(unsigned char cAscii, int x, int y)
{
    if (START == Game)
    {
        switch (cAscii)
        {
            case ' ':
				Game = RUNNING;
				PlaySound("bgm.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				break;
        }
    }
    else if (RUNNING == Game)
    {
        switch (cAscii)
        {
            case ' ':
				bbb.moveUp(); 
				break;
            case 'a':cam.switchLeft(); break;
            case 'd':cam.switchRight(); break;
        }
    }
    else if (OVER == Game)
    {
        switch (cAscii)
        {
			PlaySound(NULL, NULL, SND_FILENAME);
            case ' ':
				Game = RUNNING;
				break;
        }
    }
    glutPostRedisplay();
}
static void KeyboardFuncUp(unsigned char cAscii, int x, int y)
{}
static void MouseClickMessage(int button, int state, int x, int y)
{}
static void MouseMoveMessage(int x, int y)
{}
static void MouseWheelMessage(int wheel, int dir, int x, int y)
{}
static void MousePassiveMoveMessage(int x, int y)
{}
static void MyIdle(void)
{
    if (START == Game)
    {

    }
    else if (RUNNING == Game)
    {
        double x = bbb.getx();
        double y = bbb.gety();
        double z = bbb.getz();
        cam.idle(x, y);
        bbb.idle(cam.inRotation());
        tubeControl(ttt, x, y, z, true);
        tubeControl(ddd, x, y, z, false);
        tubeControl(inner_tree, x, y, z, true);
        tubeControl(outer_tree, x, y, z, false);

        if (!cam.inRotation())
        {
            bird_buff = buf.magic(x, y, z);
            scoredetect(ttt, ddd, x, y, z);
        }
        if (!bird_buff)
        {
            
            /**/for (int i = 0; i < tubeAmount; i++)
            {
                if (!ttt[i].idle(x, y, z, cam.getStats()))
                {
                    Game = OVER;
                } if (!ddd[i].idle(x, y, z, cam.getStats()))
                {
                    Game = OVER;
                }
            }
            if (z < tube_bottom+bird_r)
            {
                Game = OVER;
            }
        }
        else
        {
           /**/
        }
    }
    else if (OVER == Game)
    {
		Write();
    }
    glutPostRedisplay();
}

/**/void tubeControl(tube ttt[10], double x, double y, double z, bool up)
{
    static bool outofsight = true;
    for (int i = 0; i < 10; i++)
    {
        double temp = ttt[i].gety();
        if (temp == 0.0 || temp <= y - 5 * TUBEBLANK)
        {
            double tx, ty, th;
            tx = x + (rand() % 10 - 5)*bird_r * 2;
            //tx = 0;
            ty = y + (i + 1)*TUBEBLANK;
            th = 15 + rand() % MAXHEIGHT;
            ttt[i].setloc(tx, ty, th, up);
            static int des;
            if (i == 2&&!buf.getact()&&!bird_buff)
            {
                if (des % 2 == 0)
                {
                    if (up)
                    {
                        buf.setloc(tx, ty, th+tube_bottom+3.0);
                    }
                    else
                    {
                        buf.setloc(tx, ty, tube_top - th-3.0);
                    }
                    
                }
                des++;
            }
        }
    }

}

/**/void tubeControl(tree ttt[10], double x, double y, double z, bool inner)
{
	static bool outofsight = true;
	for (int i = 0; i < 10; i++)
	{
		double temp = ttt[i].gety();
		if (temp == 0.0 || temp <= y - 5 * TUBEBLANK)
		{
			ttt[i].setvalue(20, y + (i + 1)*TUBEBLANK, TREEBOTTOM, inner);
		}
	}

}
void scoredetect(tube ttt[10], tube ddd[10], double x, double y, double z) {
    double near1;
    for (int i = 0; i < tubeAmount; i++) {
        near1 = y - ttt[i].gety();
        if (near1 < 0) near1 *= -1;
        if (near1 < 0.006) {
            sc++;
        }
    }
}

void output(double x, double y, double z, char* string) {
	int len, i;
	glRasterPos3f(x, y, z);
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}

void grab(void)
{
	FILE*     pDummyFile;
	FILE*     pWritingFile;
	GLubyte* pPixelData;
	GLubyte   BMP_Header[BMP_Header_Length];
	GLint     i, j;
	GLint     PixelDataLength;

	// 计算像素数据的实际长度
	i = WindowWidth * 3;    // 得到每一行的像素数据长度
	while (i % 4 != 0)       // 补充数据，直到i是的倍数
		++i;                // 本来还有更快的算法，
							// 但这里仅追求直观，对速度没有太高要求
	PixelDataLength = i * WindowHeight;

	// 分配内存和打开文件
	pPixelData = (GLubyte*)malloc(PixelDataLength);
	if (pPixelData == 0)
		exit(0);

	pDummyFile = fopen("4__.bmp", "rb");
	if (pDummyFile == 0)
		exit(0);

	pWritingFile = fopen("4__.bmp", "wb");
	if (pWritingFile == 0)
		exit(0);

	// 读取像素
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	glReadPixels(0, 0, WindowWidth, WindowHeight,
		GL_BGR_EXT, GL_UNSIGNED_BYTE, pPixelData);

	// 把dummy.bmp的文件头复制为新文件的文件头
	fread(BMP_Header, sizeof(BMP_Header), 1, pDummyFile);
	fwrite(BMP_Header, sizeof(BMP_Header), 1, pWritingFile);
	fseek(pWritingFile, 0x0012, SEEK_SET);
	i = WindowWidth;
	j = WindowHeight;
	fwrite(&i, sizeof(i), 1, pWritingFile);
	fwrite(&j, sizeof(j), 1, pWritingFile);

	// 写入像素数据
	fseek(pWritingFile, 0, SEEK_END);
	fwrite(pPixelData, PixelDataLength, 1, pWritingFile);

	// 释放内存和关闭文件
	fclose(pDummyFile);
	fclose(pWritingFile);
	free(pPixelData);
}
int power_of_two(int n)
{
	if (n <= 0)
		return 0;
	return (n & (n - 1)) == 0;
}
GLuint load_texture(const char* file_name)
{
	GLint width, height, total_bytes;
	GLubyte* pixels = 0;
	GLint last_texture_ID;
	GLuint texture_ID = 0;

	// 打开文件，如果失败，返回
	FILE* pFile = fopen(file_name, "rb");
	if (pFile == 0)
		return 0;

	// 读取文件中图象的宽度和高度
	fseek(pFile, 0x0012, SEEK_SET);
	fread(&width, 4, 1, pFile);
	fread(&height, 4, 1, pFile);
	fseek(pFile, BMP_Header_Length, SEEK_SET);

	// 计算每行像素所占字节数，并根据此数据计算总像素字节数
	{
		GLint line_bytes = width * 3;
		while (line_bytes % 4 != 0)
			++line_bytes;
		total_bytes = line_bytes * height;
	}

	// 根据总像素字节数分配内存
	pixels = (GLubyte*)malloc(total_bytes);
	if (pixels == 0)
	{
		fclose(pFile);
		return 0;
	}

	// 读取像素数据
	if (fread(pixels, total_bytes, 1, pFile) <= 0)
	{
		free(pixels);
		fclose(pFile);
		return 0;
	}

	// 在旧版本的OpenGL中
	// 如果图象的宽度和高度不是的整数次方，则需要进行缩放
	// 这里并没有检查OpenGL版本，出于对版本兼容性的考虑，按旧版本处理
	// 另外，无论是旧版本还是新版本，
	// 当图象的宽度和高度超过当前OpenGL实现所支持的最大值时，也要进行缩放
	{
		GLint max;
		glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max);
		if (!power_of_two(width)
			|| !power_of_two(height)
			|| width > max
			|| height > max)
		{
			const GLint new_width = 256;
			const GLint new_height = 256; // 规定缩放后新的大小为边长的正方形
			GLint new_line_bytes, new_total_bytes;
			GLubyte* new_pixels = 0;

			// 计算每行需要的字节数和总字节数
			new_line_bytes = new_width * 3;
			while (new_line_bytes % 4 != 0)
				++new_line_bytes;
			new_total_bytes = new_line_bytes * new_height;

			// 分配内存
			new_pixels = (GLubyte*)malloc(new_total_bytes);
			if (new_pixels == 0)
			{
				free(pixels);
				fclose(pFile);
				return 0;
			}

			// 进行像素缩放
			gluScaleImage(GL_RGB,
				width, height, GL_UNSIGNED_BYTE, pixels,
				new_width, new_height, GL_UNSIGNED_BYTE, new_pixels);

			// 释放原来的像素数据，把pixels指向新的像素数据，并重新设置width和height
			free(pixels);
			pixels = new_pixels;
			width = new_width;
			height = new_height;
		}
	}

	// 分配一个新的纹理编号
	glGenTextures(1, &texture_ID);
	if (texture_ID == 0)
	{
		free(pixels);
		fclose(pFile);
		return 0;
	}

	// 绑定新的纹理，载入纹理并设置纹理参数
	// 在绑定前，先获得原来绑定的纹理编号，以便在最后进行恢复
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture_ID);
	glBindTexture(GL_TEXTURE_2D, texture_ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
		GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, last_texture_ID);

	// 之前为pixels分配的内存可在使用glTexImage2D以后释放
	// 因为此时像素数据已经被OpenGL另行保存了一份（可能被保存到专门的图形硬件中）
	free(pixels);
	return texture_ID;
}