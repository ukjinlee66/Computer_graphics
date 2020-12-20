#pragma once
#include "mini.h"
// z축 추가.

void idle(void)
{
	if (assemblyMode)
	{
		partial_angle += 2.8;
		if (partial_angle > 360) partial_angle -= 360;
		if (shsignal2) //shoot motion
		{
			if (tangle <= 40 && !first)
			{
				tangle += 8.0; hangle -= 8.0;
				if (tangle == 40) //방아쇠가 끝까지 당겨질 경우 소리출력.
				{
					Mix_PlayChannel(-1, shooting, 0);
					first = true;
				}
			}
			else if(tangle <= 40 && first)
			{
				tangle -= 8.0; hangle += 8.0;
			}
			if (tangle == 0 && hangle == 0)
			{
				tangle = hangle = 0;
				first = false; shsignal2 = false;
			}
		}
		if (shsignal3 && !first)
		{
			if (!first && loadangle > -55)
			{
				loadangle -= 5;
				if (loadangle == -55)
				{
					first = true;
					shsignal3 = false;
					Mix_PlayChannel(-1, reload, 0);
				}
			}
		}
		if (first && loadangle <= 0 && shsignal3)
		{
			loadangle += 5;
			if (loadangle == 0)
			{
				first = false; shsignal3 = false;
				Mix_PlayChannel(-1, reload, 0);
			}
		}
	}
	else if (GameMode)
	{
		target_angle += 3.0;
		if (partial_angle > 360) partial_angle -= 360;
		if (shsignal)
		{
			if (bu_dist < 70) bu_dist += 5.0;
			else
			{
				bu_dist = 0;
				shsignal = false;
			}
		}
	}
	glutPostRedisplay();
}

void motion(int x, int y)
{
	y = g_nGLHeight - y;
	if (g_nSelect > 0)
	{
		g_pPosition[(g_nSelect - 1) * 2 + 0] += x - g_nX;
		g_pPosition[(g_nSelect - 1) * 2 + 1] += y - g_nY;
		g_nX = x;
		g_nY = y;
		glutPostRedisplay();
		draw();
	}
}

void Picking(int x, int y)
{
	GLuint selectBuf[256];
	glSelectBuffer(256, selectBuf);

	glRenderMode(GL_SELECT);

	glMatrixMode(GL_PROJECTION);

	glInitNames();

	glPushName(-1);

	glPushMatrix();
	glLoadIdentity();

	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	gluPickMatrix(x, y, 0.1, 0.1, viewport);
	glOrtho(-g_nGLWidth / 2.0f, g_nGLWidth / 2.0f,
		-g_nGLHeight / 2.0f, g_nGLHeight / 2.0f,
		-100, 100);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	//DrawOBJ();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();

	GLint hits = glRenderMode(GL_RENDER);
	//GL_SELECT이후 GL_RENDER모드를 이용하여 그린다.
	printf("hits objects : %d\n", hits);

	if (hits <= 0) return;

	int stack = selectBuf[0];
	unsigned int zMin = selectBuf[1];
	unsigned int zMax = selectBuf[2];
	g_nSelect = selectBuf[3];
	printf("g_nSelect : %d\n", g_nSelect);


	int index = 3 + stack;
	for (int i = 1; i < hits; i++)
	{
		stack = selectBuf[index];
		if (zMin < selectBuf[index + 2])
		{
			zMin = selectBuf[index + 2];
			g_nSelect = selectBuf[index + 3];
		}
		index += 3 + stack;
	}
}