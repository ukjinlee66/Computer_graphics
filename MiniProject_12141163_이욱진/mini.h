#pragma once
#ifndef MINI_H
# define MINI_H

#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "ObjParser.h"
#include "bmpfuncs.h"
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <algorithm>
#include <GL/glext.h>
#include <SDL.h>
#include <SDL_mixer.h>
using namespace std;

# define PI 3.14159265359
# define SOUND_MUSIC "music/BGM.wav"
# define SOUND_SHOOTING "music/shooting.wav"
# define SOUND_RELOAD "music/reload.wav"
# define SOUND_BOOM "music/boom.wav"

//music variable
extern Mix_Music* gMusic;
extern Mix_Chunk* shooting;
extern Mix_Chunk* reload;
extern Mix_Chunk* boom;
//draw obj handle variable
extern int dobj;
extern double dobjx[9], dobjy[9], dobjz[9];
extern int objidset[9];
extern bool shsignal;
extern float bu_dist;
extern bool shsignal2;
extern bool shsignal3;
extern double loadangle;
extern GLuint g_nCubeTex;
extern double partial_angle;
extern string current_Mode;
extern string ObjName[5];
extern int objID;
extern bool first;
extern bool drawsignal;
extern float rx, ry;
extern bool prev[512][512][512];
extern double	R_Positionx, R_Positiony, R_Positionz, R_anglex, R_angley, R_anglez;
extern int dobj;
extern double hangle, tangle;
//충돌체크
extern bool visit[512][512][512];
//각 object 위치.
extern int  rBodyPosition[512][512][512];
extern int  rmaPosition[512][512][512];
extern int  bulletPosition[512][512][512];
extern int  rhaPosition[512][512][512];
extern int  rtrPosition[512][512][512];

//Mode variable
extern bool assemblyMode;
extern bool GameMode;

//object variable
extern ObjParser* revolver_body;
extern ObjParser* revolver_trigger;
extern ObjParser* revolver_hammer;
extern ObjParser* bullet;
extern ObjParser* revolver_magazine;

//mouse variable
extern int g_nSelect;
extern int g_nGLWidth , g_nGLHeight;
extern int g_nX, g_nY;
extern float g_pPosition[6];
//camera variable
extern double eyeX ,eyeY, eyeZ;

//light variable
extern GLdouble eq[4];
extern int light_mode;
extern GLfloat light_position[];

//angle variable
extern double theta , phi;
extern double radius;
extern bool spin_state;



//texture variable
extern GLuint		revolver_body_texture;
extern GLuint		revolver_trigger_texture;
extern GLuint		revolver_hammer_texture;
extern GLuint		revolver_bullet_texture;
extern GLuint		revolver_magazine_texture;
extern GLuint	R_texture;
extern GLfloat		cx, cy, cz, cr, cg, cb;
extern GLfloat		c1[7], c2[7], c3[7];
extern int colorindex;
extern GLfloat dobjc[9][3];
extern double target_angle;
extern ObjParser* target;
extern GLuint		target_texture;
//menu function
void sub_menu_function(int option);
void sub_menu_function2(int option);
void sub_menu_function3(int option);
void sub_menu_function4(int option);
void main_menu_function(int option);

//init function
void init(void);
void resize(int width, int height);
void setTextureMapping(int option);
//string function
void draw_string(void* font, const char* str, float x_position,
	float y_position, float red, float green, float blue);
//draw function
void draw(void);
void draw_obj(ObjParser* objParser);
void draw_obj_with_texture(ObjParser* objParser, GLuint tex);
void draw_axis(void);
void draw_text(void);
void draw_aim(void);

//keyboard function
void glut_special_input(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
void mouseWheel(int button, int dir, int x, int y);
void mouse(int button, int state, int x, int y);
//motion function
void Picking(int x, int y);
void motion(int x, int y);
void idle(void);
//multiviewport function
void draw_ModeName(string ModeName);
void draw_partial_obj(void);
//skybox function
void set_skybox(void);
void draw_skybox(void);
bool gluInverMatrix(const GLfloat m[16], GLfloat out[16]);

#endif