#pragma once
#include "mini.h"

void setTextureMapping(int option)
{
	printf("set Texture Mapping function call\n");
	int imgWidth, imgHeight, channels;
	uchar* img;
	int texNum = 1;
	switch (option)
	{
		case 1:
			glGenTextures(texNum, &revolver_body_texture);
			img = readImageData("texture/body_tex2.bmp", &imgWidth, &imgHeight, &channels);
			glBindTexture(GL_TEXTURE_2D, revolver_body_texture);
			break;
		case 2:
			img = readImageData("texture/target_texture2.bmp", &imgWidth, &imgHeight, &channels);
			glGenTextures(texNum, &target_texture);
			glBindTexture(GL_TEXTURE_2D, target_texture);
			break;
		case 3:
			glGenTextures(texNum, &R_texture);
			img = readImageData("texture/R3.bmp", &imgWidth, &imgHeight, &channels);
			glBindTexture(GL_TEXTURE_2D, R_texture);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			printf("Not Found Texture file!\n");
			break;
	}
	/*uchar* img = readImageData("texture/body_tex1.bmp", &imgWidth, &imgHeight, &channels);*/

	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//GL_REPEAT 둘중 하나 선택
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imgWidth, imgHeight, GL_RGB, GL_UNSIGNED_BYTE, img);
}

void init(void) {
	printf("init function call!\n");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(10.0f);
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		printf("SDL_Init Error!\n");
		exit(1);
	}
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	gMusic = Mix_LoadMUS(SOUND_MUSIC);
	shooting = Mix_LoadWAV(SOUND_SHOOTING);
	reload = Mix_LoadWAV(SOUND_RELOAD);
	boom = Mix_LoadWAV(SOUND_BOOM);
	Mix_PlayMusic(gMusic, -1);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
	set_skybox();
	//glEnable(GL_TEXTURE_2D);
	for (int i = 1; i <= 3; i++)
		setTextureMapping(i);
	//glEnable(GL_NORMALIZE);
	//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);
	GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	GLfloat light_position[] = { 1.0, 1.0, 1.0 , 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 64);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
}

void resize(int width, int height)
{/*
	printf("resize function call\n");*/
	glViewport(0, 0, width, height);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(66, (float)width / (float)height, 1, 500);
	glMatrixMode(GL_MODELVIEW);
}