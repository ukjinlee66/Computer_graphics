#include "mini.h"

extern int g_nGLWidth, g_nGLHeight;
extern double partial_angle;
extern int objID;
extern string ObjName[5];
extern ObjParser* revolver_body;
extern ObjParser* revolver_trigger;
extern ObjParser* revolver_hammer;
extern ObjParser* bullet;
extern ObjParser* revolver_magazine;

void draw_ModeName(string ModeName)
{
	glViewport(0, (GLsizei)g_nGLHeight -50,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, ModeName.c_str(), -5, -7, 1.0f, 1.0f, 0.0f);
	glFlush();
}

void draw_partial_obj(void) // 인자로 들어오는 object id에따라서 부품을 그린다. 그상태에서 키입력을통한 조립뷰포트에 추가.
{
	glViewport((GLsizei)g_nGLWidth* 3 / 4, -50,
		(GLsizei)g_nGLWidth - 550, 300);

	/*glDisable(GL_LIGHTING);
	draw_axis();
	glEnable(GL_LIGHTING);*/
	glRotatef(partial_angle, 0, 1, 0);
	//switch() objID
	glColor3f(1, 1, 1);
	switch (objID)
	{
	case 0:
		draw_obj(revolver_body);
		break;
	case 1:
		draw_obj(revolver_magazine);
		break;
	case 2:
		draw_obj(revolver_hammer);
		break;
	case 3:
		draw_obj(bullet);
		break;
	case 4:
		draw_obj(revolver_trigger);
		break;
	default :
		printf("Not correct objID\n");
		exit(1);
	}
	//glutSolidTeapot(2.0f);
	glLoadIdentity();
	/*glTranslatef(0, 400, 0);*/
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, ObjName[objID].c_str(), -10, 5, 1.0f, 1.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	glFlush();
}