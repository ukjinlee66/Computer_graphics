#include "mini.h"
extern int light_mode;
extern double theta , phi;
extern double radius;
extern bool spin_state;
extern int objID;
extern bool assemblyMode;
extern bool GameMode;
extern GLfloat		cx, cy, cz;
extern bool drawsignal;
// 키보드는 텍스처를 바꾸는 키와 자동조립 상태로바꾸는 키 그리고 각도회전 줌아웃 포함.
void keyboard(unsigned char key, int x, int y)
{
	if (key == 32)
	{
		if (!drawsignal)
		{
			printf("objID : %d\n", objID);
			drawsignal = true;
		}
		else
		{
			printf("fin obj\n");
			drawsignal = false;
		}
		
	}
	if (key == 's')
		spin_state = (spin_state == true ? false : true);
	else if (key == '0')
	{
		printf("light position camera\n");

		light_mode = 0;
	}
	else if (key == '1') {
		printf("light position Sun\n");
		light_mode = 1;
	}
	else if (key == '2') {
		printf("light position Mercury\n");
		light_mode = 2;
	}
	else if (key == '3') {
		printf("light position Venus.\n");
		light_mode = 3;
	}
	else if (key == '4')
	{
		printf("light position (3, 5, 7)\n");
		light_mode = 4;
	}
	else if (key == '5')
	{
		printf("light position (20, 0, 0)\n");
		light_mode = 5;
	}
	else if (key == 'i')
	{
		objID++;
		if (objID == 5) objID = 0;
	}
	else if (key == 'n')
	{
		if (assemblyMode)
		{
			assemblyMode = false;
			GameMode = true;
		}
		else
		{
			GameMode = false;
			assemblyMode = true;
		}
	}

}

void glut_special_input(int key, int x, int y)
{
	if (assemblyMode) //조립모드에서방향키
	{
		if (key == GLUT_KEY_UP) {
			cy += 1;
		}
		else if (key == GLUT_KEY_DOWN) {
			cy -= 1;
		}
		else if (key == GLUT_KEY_RIGHT) {
			cx += 1;
		}
		else if (key == GLUT_KEY_LEFT) {
			cx -= 1;
		}
	}
	else if (GameMode) //게임모드 각도조절
	{
		if (key == GLUT_KEY_UP) {
			phi -= 5;
			if (phi < 0) phi = 355;
		}
		else if (key == GLUT_KEY_DOWN) {
			phi += 5;
			if (phi >= 360) phi = 0;
		}
		else if (key == GLUT_KEY_LEFT) {
			theta += 5;
			if (theta >= 360) theta = 0;
		}
		else if (key == GLUT_KEY_RIGHT) {
			theta -= 5;
			if (theta < 0) theta = 355;
		}
	}
	printf("theta : %f phi : %f\n", theta, phi);
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	y = g_nGLHeight - y;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		Picking(x, y);
		g_nX = x;
		g_nY = y;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		g_nSelect = 0;
	glutPostRedisplay();
}

void mouseWheel(int button, int dir, int x, int y)
{
	if (dir > 0) {
		// printf("button(%d), dir(%d), x(%d), y(%d)\n", button, dir, x, y);
		if (radius > 1) radius -= 0.5;
	}
	else {
		// printf("button(%d), dir(%d), x(%d), y(%d)\n", button, dir, x, y);
		if (radius < 100) radius += 0.5;
	}
	glutPostRedisplay();
}