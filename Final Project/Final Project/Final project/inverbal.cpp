#include "inverbal.h"

obj3dmodel::obj3dmodel() {};

obj3dmodel::~obj3dmodel() {};

void obj3dmodel::read(const char* path) {
	FILE *file = fopen(path, "r");
	char lineHeader[128];
	char mtlpath[128];
	char mtlname[128];
	while (1) {
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF) break;
		if (strcmp(lineHeader, "v") == 0) {
			vertex v;
			fscanf(file, "%lf %lf %lf", &v.x, &v.y, &v.z);
			vertices.push_back(v);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			texel t;
			fscanf(file, "%lf %lf", &t.x, &t.y);
			texcoords.push_back(t);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			vertex n;
			fscanf(file, "%lf %lf %lf", &n.x, &n.y, &n.z);
			normalVertices.push_back(n);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			face f;
			face n;
			face t;
			fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d", &f.v1, &t.v1, &n.v1, &f.v2, &t.v2, &n.v2, &f.v3, &t.v3, &n.v3);
			f.v1--; f.v2--; f.v3--;
			t.v1--; t.v2--; t.v3--;
			n.v1--; n.v2--; n.v3--;
			faces.push_back(f);
			texfaces.push_back(t);
			normalFaces.push_back(n);
		}
	}
	fclose(file);
}

void obj3dmodel::render() {
	vertex v1, v2, v3, v4;
	vertex n1, n2, n3, n4;
	texel t1, t2, t3, t4;
	glBegin(GL_TRIANGLES);
	for (unsigned int i = 0; i < faces.size(); i++) {
		v1 = vertices[faces.at(i).v1];
		v2 = vertices[faces.at(i).v2];
		v3 = vertices[faces.at(i).v3];
		t1 = texcoords[texfaces.at(i).v1];
		t2 = texcoords[texfaces.at(i).v2];
		t3 = texcoords[texfaces.at(i).v3];
		n1 = normalVertices[normalFaces.at(i).v1];
		n2 = normalVertices[normalFaces.at(i).v2];
		n3 = normalVertices[normalFaces.at(i).v3];
		glNormal3f(n1.x, n1.y, n1.z);
		glTexCoord2f(t1.x, t1.y);
		glVertex3f(v1.x, v1.y, v1.z);
		glNormal3f(n2.x, n2.y, n2.z);
		glTexCoord2f(t2.x, t2.y);
		glVertex3f(v2.x, v2.y, v2.z);
		glNormal3f(n3.x, n3.y, n3.z);
		glTexCoord2f(t3.x, t3.y);
		glVertex3f(v3.x, v3.y, v3.z);
	}
	glEnd();
}

void skyrender() {

}