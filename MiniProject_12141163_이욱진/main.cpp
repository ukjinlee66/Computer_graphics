#pragma once
#include "mini.h"
#include "ObjParser.h"
//#include "SDL2_mixer-2.0.4/SDL_mixer.h" //효과음 외부 라이브러리


string current_Mode;
string ObjName[5] = { "Body", "magazine", "hammer", "bullet", "trigger" }; //0~4
int objID = 0;
GLuint	R_texture;
bool first = false;
//충돌체크
bool visit[512][512][512];
//각 object 위치.
int  rBodyPosition[512][512][512];
int  rmaPosition[512][512][512];
int  bulletPosition[512][512][512];
int  rhaPosition[512][512][512];
int  rtrPosition[512][512][512];

//Mode variable
bool assemblyMode = true;
bool GameMode = false;

//object variable
GLuint		g_nCubeTex;
ObjParser* revolver_body;
ObjParser* revolver_trigger;
ObjParser* revolver_hammer;
ObjParser* bullet;
ObjParser* revolver_magazine;
ObjParser* target;
GLuint		target_texture;
GLuint		revolver_body_texture;
GLuint		revolver_trigger_texture;
GLuint		revolver_hammer_texture;
GLuint		revolver_bullet_texture;
GLuint		revolver_magazine_texture;
GLfloat		cx=0, cy=0, cz=0; //조립모드 움직임변수.
//mouse variable
int g_nSelect = 0;
int g_nGLWidth = 800, g_nGLHeight = 600;
int g_nX, g_nY;
float g_pPosition[6] = { 0.0f, 144.0f, -100.0f, -100.0f, 100.0f, -100.0f };
//camera variable
double eyeX, eyeY, eyeZ;
double target_angle = 45;
//light variable
GLdouble eq[4] = { 1.0, 0.0, 0.0, 0.0 };
int light_mode = 0;
GLfloat light_position[] = { 0.0,0.0,0.0,1.0 };
bool drawsignal = false;
//angle variable
double theta = 45.0f, phi = 45.0f;
double radius = 10.0;
bool spin_state = false;
double partial_angle = 0;
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("MiniProject_12141163_이욱진");

	init();

	glutReshapeFunc(resize);
	glutMouseFunc(&mouse);
	glutMouseWheelFunc(&mouseWheel);
	glutKeyboardFunc(&keyboard);
	glutSpecialFunc(&glut_special_input);
	//glutIdleFunc(idle);
	glutMotionFunc(&motion);
	

	glutCreateMenu(main_menu_function);
	glutAddMenuEntry("Quit", 999);
	glutAddMenuEntry("reload", 10);
	glutAddMenuEntry("shooting", 20);
	glutAddMenuEntry("next texture", 24);
	glutAddMenuEntry("init texture", 26);
	glutAddMenuEntry("init", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutSpecialFunc(glut_special_input);
	glutReshapeFunc(resize);
	glutIdleFunc(idle);
	glutDisplayFunc(draw);

	glutMainLoop();

	return (0);
}