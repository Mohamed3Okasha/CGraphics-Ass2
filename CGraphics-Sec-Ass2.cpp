#include "pch.h"
#include <iostream>
#include <stdlib.h> //Needed for "exit" function
#define _USE_MATH_DEFINES
#include <cmath>
//Include OpenGL header files, so that we can use OpenGL
#ifdef APPLE
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;
float X1 = 48;
float X2 = 23;
float X3 = 23;
float step = 1;
bool f1 = false;
bool f2 = false;
bool f3 = false;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 920.0, 0.0, 1200.0);
}
float cx = 50.0f;
float cy = 50.0f;
int num_segments = 20;
float r = 15.0f;
void renderbitmap(float x, float y, void *font, char *string) {
	char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void drawSending() {
	glColor3f(0.0, 1.0, 0.0);
	char buf4[100] = { 0 };
	sprintf_s(buf4, "SENDING");
	renderbitmap(38, 32, GLUT_BITMAP_HELVETICA_18, buf4);
}
void drawReceiving() {
	glColor3f(0.0, 1.0, 0.0);
	char buf5[100] = { 0 };
	sprintf_s(buf5, "RECEIVING");
	renderbitmap(32, 20, GLUT_BITMAP_HELVETICA_18, buf5);
}
void drawReceiving2() {
	glColor3f(0.0, 1.0, 0.0);
	char buf5[100] = { 0 };
	sprintf_s(buf5, "RECEIVING");
	renderbitmap(13, 32, GLUT_BITMAP_HELVETICA_18, buf5);
}
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT);
	//draw the left circle
	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_POINTS);
	for (int i = 0; i < 360; ++i)
	{
		glVertex2f((cos(3.14159*i / 180.0))*7.0 + 30, (sin(3.14159*i / 180.0))*7.0 + 30);
	}

	glEnd();
	glBegin(GL_LINES);
	glVertex2f(23, 30);
	glVertex2f(12, 30);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(12, 33);
	glVertex2f(6, 33);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(6, 33);
	glVertex2f(6, 27);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(6, 27);
	glVertex2f(12, 27);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(12, 27);
	glVertex2f(12, 33);
	glEnd();
	char buf[100] = { 0 };
	sprintf_s(buf, "PC");
	renderbitmap(8, 29, GLUT_BITMAP_HELVETICA_18, buf);
	glBegin(GL_LINES);
	glVertex2f(37, 30);
	glVertex2f(48, 30);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(54, 33);
	glVertex2f(48, 33);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(48, 33);
	glVertex2f(48, 27);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(48, 27);
	glVertex2f(54, 27);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(54, 27);
	glVertex2f(54, 33);
	glEnd();
	char buf2[100] = { 0 };
	sprintf_s(buf2, "SERVER");
	renderbitmap(49, 30, GLUT_BITMAP_HELVETICA_12, buf2);
	char bufr[100] = { 0 };
	sprintf_s(bufr, "RING");
	renderbitmap(27, 31, GLUT_BITMAP_TIMES_ROMAN_24, bufr);
	char bufn[100] = { 0 };
	sprintf_s(bufn, "NETWORK");
	renderbitmap(24, 27, GLUT_BITMAP_TIMES_ROMAN_24, bufn);
	glBegin(GL_LINES);
	glVertex2f(30, 23);
	glVertex2f(30, 18);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(33, 18);
	glVertex2f(27, 18);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(27, 18);
	glVertex2f(27, 12);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(27, 12);
	glVertex2f(33, 12);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(33, 12);
	glVertex2f(33, 18);
	glEnd();

	char buf3[100] = { 0 };
	sprintf_s(buf3, "MAC");
	renderbitmap(28, 14, GLUT_BITMAP_HELVETICA_18, buf3);

	glColor3f(0.0, 1.0, 1.0);
	glPushAttrib(GL_ENABLE_BIT);
	// glPushAttrib is done to return everything to normal after drawing

	glLineStipple(1, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	//Server Line
	glBegin(GL_LINES);
	glVertex2f(48, 31);
	glVertex2f(X1, 31);
	glEnd();
	//MAC Line
	glBegin(GL_LINES);
	glVertex2f(31, 23);
	glVertex2f(31, X2);
	glEnd();
	//PC Line
	glBegin(GL_LINES);
	glVertex2f(23, 31);
	glVertex2f(X3, 31);
	glEnd();
	if (f1 == true) {
		drawSending();
	}
	if (f2 == true) {
		drawReceiving();
	}
	if (f3 == true) {
		drawReceiving2();
	}

	glPopAttrib();
	glFlush();
}
void processSpecialKeys(int key, int mx, int my) {
	switch (key) {
	case GLUT_KEY_LEFT: //move left
		//while (X1 <= 48)
		f1 = true;
		if (X1 >= 39) {
			X1 -= step;

		}
		if (X1 <= 39 && X2 >= 19) {
			X2 -= step;
			f2 = true;
		}
		if (X2 <= 19 && X3 >= 13) {
			X3 -= step;
			f3 = true;
		}

		glutPostRedisplay(); // use to display changes on screen
		break;
	default:
		break;
	}
}
int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600); //Set the window size
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Ring Network");//Create the window
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 60.0, 0.0, 60.0);
	glutDisplayFunc(drawScene);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}