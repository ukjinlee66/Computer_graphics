#include "mini.h"

void draw_ModeName(string ModeName)
{
	string Xkey = "Q,A: +X, -X";
	string Ykey = "W,S: +Y, -Y";
	string Zkey = "E,D: +Z, -Z";
	string Okey = "I  : Next object";
	string Skey = "Space bar : Put Object";
	string Nkey = "N  : Game Mode or assembly Mode";
	string Lkey = "L  : Shoot motion";
	string ZZkey = "Z  : reload motion";
	string G = "GameMode";
	string ar = "arrow key : angle change";
	string sp = "space bar : shoot";


	glViewport(0, (GLsizei)g_nGLHeight -50,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, ModeName.c_str(), -5, -7, 1.0f, 0.0f, 0.0f);
	glFlush();
	//단축키 사용법.

	glViewport(0, (GLsizei)g_nGLHeight - 70,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_HELVETICA_18, Okey.c_str(), -5, -8, 1.0f, 1.0f, 1.0f);
	glFlush();

	glViewport(0, (GLsizei)g_nGLHeight - 100,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_HELVETICA_18, Skey.c_str(), -5, -8, 1.0f, 1.0f, 1.0f);
	glFlush();


	glViewport(0, (GLsizei)g_nGLHeight - 130,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_HELVETICA_18, Xkey.c_str(), -5, -8, 1.0f, 1.0f, 1.0f);
	glFlush();

	glViewport(0, (GLsizei)g_nGLHeight - 160,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_HELVETICA_18, Ykey.c_str(), -5, -8, 1.0f, 1.0f, 1.0f);
	glFlush();

	glViewport(0, (GLsizei)g_nGLHeight - 190,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_HELVETICA_18, Zkey.c_str(), -5, -8, 1.0f, 1.0f, 1.0f);
	glFlush();
	
	glViewport(0, (GLsizei)g_nGLHeight - 220,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_HELVETICA_18, Nkey.c_str(), -5, -8, 1.0f, 1.0f, 1.0f);
	glFlush();

	glViewport(0, (GLsizei)g_nGLHeight - 250,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_HELVETICA_18, Lkey.c_str(), -5, -8, 1.0f, 1.0f, 1.0f);
	glFlush();

	glViewport(0, (GLsizei)g_nGLHeight - 280,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_HELVETICA_18, ZZkey.c_str(), -5, -8, 1.0f, 1.0f, 1.0f);
	glFlush();

	glViewport(0, (GLsizei)g_nGLHeight - 320,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, G.c_str(), -5, -7, 1.0f, 0.0f, 0.0f);
	glFlush();

	glViewport(0, (GLsizei)g_nGLHeight - 350,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_HELVETICA_18, ar.c_str(), -5, -8, 1.0f, 1.0f, 1.0f);
	glFlush();

	glViewport(0, (GLsizei)g_nGLHeight - 380,
		(GLsizei)g_nGLWidth / 8.0, (GLsizei)g_nGLHeight / 6.0);
	glLoadIdentity();
	draw_string(GLUT_BITMAP_HELVETICA_18, sp.c_str(), -5, -8, 1.0f, 1.0f, 1.0f);
	glFlush();
}

void draw_partial_obj(void) // object id에따라서 부품을 그린다. 그상태에서 키입력을통한 조립뷰포트에 추가.
{
	glViewport((GLsizei)g_nGLWidth* 3 / 4, -50,
		(GLsizei)g_nGLWidth - 550, 300);

	glDisable(GL_LIGHTING);
	draw_axis();
	glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHTING);
	glRotatef(partial_angle, 0, 1, 0);
	//switch() objID
	glColor3f(cr, cg, cb);
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
	glLoadIdentity();
	/*glTranslatef(0, 400, 0);*/
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, ObjName[objID].c_str(), -10, 5, 1.0f, 1.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	glFlush();
}