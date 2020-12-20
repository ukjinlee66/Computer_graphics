#include "mini.h"

// 키보드는 텍스처를 바꾸는 키와 자동조립 상태로바꾸는 키 그리고 각도회전 줌아웃 포함.
void keyboard(unsigned char key, int x, int y)
{
	if (key == 32)
	{
		if (assemblyMode)
		{
			if (!drawsignal)
			{
				printf("objID : %d\n", objID);
				drawsignal = true;
			}
			else
			{
				dobj++;
				printf("draw obj objID : %d\n",objID);
				cx = cy = cz = 0;
				colorindex = 0;
				objidset[dobj] = objID; // 현재 오브젝트 아이디를 저장.
				drawsignal = false;
			}
		}
		else if (GameMode)
		{
			printf("shooting\n");
			Mix_PlayChannel(-1, shooting, 0);
			//idle함수 이용 총알을 발사.
			if (!shsignal) shsignal = true;
		}
	}
	if (assemblyMode)
	{ 
		if (key == 'q') // +x
			cx+=0.1;	
		if (key == 'a') // -x
			cx -= 0.1;
		if (key == 'w') // +y
			cy+=0.1;
		if (key == 's') // -y
			cy-=0.1;
		if (key == 'e') // +z
			cz+=0.1;
		if (key == 'd') // -z
			cz-=0.1;
		if (key == 'c')
		{
			colorindex++;
			if (colorindex == 7) colorindex = 0;
			cr = c1[colorindex]; cg = c2[colorindex]; cb = c3[colorindex];
		}
		if (key == 'l') // shooting motion
		{
			shsignal2 = true;
		}
		if (key == 'z') // reload motion
		{
			shsignal3 = true;
		}
	}
	if (key == 's')
		spin_state = (spin_state == true ? false : true);
	else if (key == '0')
	{
		light_mode = 0;
	}
	else if (key == '1') {
		light_mode = 1;
	}
	else if (key == '2') {
		light_mode = 2;
	}
	else if (key == '3') {
		light_mode = 3;
	}
	else if (key == '4')
	{
		light_mode = 4;
	}
	else if (key == '5')
	{
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
			//default option
			theta = 15;
			phi = 25;
			radius = 5;
		}
		else
		{
			GameMode = false;
			assemblyMode = true;
			//default option
			theta = 45;
			phi = 45;
			radius = 10;
		}
	}

}

void glut_special_input(int key, int x, int y)
{
	if (assemblyMode) //조립모드에서방향키
	{
		if (key == GLUT_KEY_UP) {
			phi -= 5;
			if (phi < 0) phi = 355;
		}
		else if (key == GLUT_KEY_DOWN) {
			phi += 5;
			if (phi >= 360) phi = 0;
		}
		else if (key == GLUT_KEY_RIGHT) {
			theta += 5;
			if (theta >= 360) theta = 0;
		}
		else if (key == GLUT_KEY_LEFT) {
			theta -= 5;
			if (theta < 0) theta = 355;
		}
	}
	if (GameMode) //게임모드 각도조절
	{
		if (key == GLUT_KEY_UP) {
			phi -= 5;
			if (phi < 0) phi = 355;
			R_angley += 0.1;
			rx -=1;
		}
		else if (key == GLUT_KEY_DOWN) {
			phi += 5;
			if (phi >= 360) phi = 0;
			R_angley -= 0.1;
			rx += 1;
		}
		else if (key == GLUT_KEY_LEFT) {
			theta += 5;
			if (theta >= 360) theta = 0;
			R_anglex += 0.1;
			ry += 1;
		}
		else if (key == GLUT_KEY_RIGHT) {
			theta -= 5;
			if (theta < 0) theta = 355;
			R_anglex -= 0.1;
			ry -= 1;
		}
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	/*y = g_nGLHeight - y;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		Picking(x, y);
		g_nX = x;
		g_nY = y;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		g_nSelect = 0;
	glutPostRedisplay();*/
}

void mouseWheel(int button, int dir, int x, int y)
{
	if (dir > 0) {
		if (radius > 1) radius -= 0.3;
	}
	else {
		if (radius < 100) radius += 0.3;
	}
	glutPostRedisplay();
}