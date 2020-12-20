#pragma once
#include "mini.h"
#include "ObjParser.h"

string current_Mode;
string ObjName[5] = { "Body", "magazine", "hammer", "bullet", "trigger" }; //0~4
int objID = 0;
GLuint	R_texture;
bool first = false;
//충돌체크
bool visit[512][512][512];
bool prev[512][512][512];
double		R_Positionx,R_Positiony,R_Positionz,R_anglex=0,R_angley=0,R_anglez=0;
//draw obj handle variable
int dobj = 0;
double dobjx[9], dobjy[9], dobjz[9];
GLfloat dobjc[9][3];
int objidset[9];
GLfloat objcolor[9];
float rx , ry ;
double hangle, tangle;
//SDL2
Mix_Music* gMusic; //BGM
Mix_Chunk* shooting;
Mix_Chunk* reload;
Mix_Chunk* boom;

//Mode variable
bool assemblyMode = true;
bool GameMode = false;
bool shsignal = false;
bool shsignal2 = false; //shooting
bool shsignal3 = false; //reload
double loadangle;
float bu_dist;

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
GLfloat		cr = 1.f, cg = 1.f, cb = 1.f; //조립모드 오브젝트의 색깔.
GLfloat c1[7] = { 1.f,1.f,1.f,1.f,0.0f,0.0f,0.0f };
GLfloat c2[7] = { 1.f,1.f,0.0f,0.0f,1.f,1.f,0.f };
GLfloat c3[7] = { 1.f,0.f,1.f,0.f,1.f,0.f,1.f };
int colorindex = 0;
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
	glutMotionFunc(&motion);
	

	glutCreateMenu(main_menu_function);
	glutAddMenuEntry("Quit", 999);
	glutAddMenuEntry("reload", 10);
	glutAddMenuEntry("shooting", 20);
	glutAddMenuEntry("Game Mode", 24);
	glutAddMenuEntry("Assembly Mode", 26);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutIdleFunc(idle);
	glutDisplayFunc(draw);

	glutMainLoop();

	return (0);
}