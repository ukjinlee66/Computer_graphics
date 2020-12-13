#pragma once
#include "mini.h"

extern int g_nGLWidth, g_nGLHeight;

void draw_text(void)
{
	glViewport(0, (GLsizei)g_nGLWidth / 2.0,
		(GLsizei)g_nGLWidth / 2.0, (GLsizei)g_nGLHeight / 2.0);
	draw_axis();
	glLoadIdentity();

	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Graphics are cool!!", -5, -3, 1.0f, 1.0f, 0.0f);
	draw_string(GLUT_BITMAP_HELVETICA_18, "Multi-Viewport Example!!", -7, 2, 0.5f, 1.0f, 0.0f);
	glFlush();
}

void draw_string(void* font, const char* str, float x_position,
	float y_position, float red, float green, float blue)
{
	glPushAttrib(GL_LIGHTING_BIT);
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(red, green, blue);
	glRasterPos3f(x_position, y_position, 0);
	for (unsigned int i = 0; i < strlen(str); i++)
		glutBitmapCharacter(font, str[i]);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
}