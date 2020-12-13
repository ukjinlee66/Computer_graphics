#pragma once
#include "mini.h"
//extern GLuint g_nCubeTex;
//extern bool drawsignal;
//extern string ObjName[5];
//extern int objID;
//extern bool visit[512][512][512];
//extern int  rBodyPosition[512][512][512];
//extern int  rmaPosition[512][512][512];
//extern int  bulletPosition[512][512][512];
//extern int  rhaPosition[512][512][512];
//extern int  rtrPosition[512][512][512];
//extern bool assemblyMode;
//extern bool GameMode;
//extern double eyeX, eyeY, eyeZ;
//extern double radius, theta, phi;
//extern ObjParser* revolver_body;
//extern ObjParser* revolver_trigger;
//extern ObjParser* revolver_hammer;
//extern ObjParser* bullet;
//extern ObjParser* revolver_magazine;
//extern GLuint	revolver_body_texture;
//extern GLuint	revolver_trigger_texture;
//extern GLuint	revolver_hammer_texture;
//extern GLuint	revolver_bullet_texture;
//extern GLuint	revolver_magazine_texture;
//extern GLuint	R_texture;
//extern GLfloat		cx, cy , cz ;
//extern bool first;


void draw_aim(void)
{
	glLineWidth(2.0f);
	glBegin(GL_LINES);

	glColor4f(0.f, 0.f, 1.f, 1.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 10.f);

	glEnd();
	glLineWidth(1);
}

void draw_axis(void)
{
	glLineWidth(1.5f);
	glBegin(GL_LINES);

	glColor4f(1.f, 0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(7.f, 0.f, 0.f);

	glColor4f(0.f, 1.f, 0.f, 1.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 7.f, 0.f);

	glColor4f(0.f, 0.f, 1.f, 1.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 7.f);

	glEnd();
	glLineWidth(1);
}

void draw_obj(ObjParser* objParser)
{
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) 
	{
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
}

void draw_obj_with_texture(ObjParser* objParser, GLuint tex)
{
	glDisable(GL_BLEND);
	//glEnable(GL_TEXTURE_2D);	// texture 색 보존을 위한 enable
	glBindTexture(GL_TEXTURE_2D, tex);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	glEnable(GL_BLEND);
}

void draw(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	revolver_body = new ObjParser("3d_object/rbody.obj");
	revolver_trigger = new ObjParser("3d_object/rtr2.obj");
	revolver_hammer = new ObjParser("3d_object/rha2.obj");
	bullet = new ObjParser("3d_object/rbu2.obj");
	revolver_magazine = new ObjParser("3d_object/rma2.obj");
	ObjParser* R = new ObjParser("3d_Object/R.obj");
	target = new ObjParser("3d_Object/target2.obj");
	if (assemblyMode)
	{
		//glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//glEnable(GL_POLYGON_SMOOTH);
		//glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
		//glEnable(GL_LIGHTING);
		//glDisable(GL_TEXTURE_2D);
		//glEnable(GL_COLOR_MATERIAL);
		//resize(800, 600);
		current_Mode = "Assembly Mode";
		gluLookAt(15, 15, 15, 0, 0, 0, 0, 1, 0); //고정시각으로 조립을진행. 키보드입력을통한 object조립.
		glPushMatrix();
		
		draw_ModeName(current_Mode);
		glPopMatrix();
		glPushMatrix();
		draw_partial_obj();
		glPopMatrix();
		glPushMatrix();
		resize(800, 600);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		draw_axis();
		glPopMatrix();
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);

		if (drawsignal)
		{
			glColor3f(1, 1, 1);
			glTranslatef(cx, cy, cz);
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
			default:
				printf("Not correct objID\n");
				exit(1);
			}
		}
	}
	else if (GameMode)
	{
		//glDisable(GL_BLEND);
		//glDisable(GL_POLYGON_SMOOTH);	
		//glEnable(GL_TEXTURE_2D);
		//glEnable(GL_LIGHTING);
		//glDisable(GL_COLOR_MATERIAL);
		//resize(800, 600);
		if (first == false)
		{
			theta = 170;
			phi = 25;
			first = true;
		}
		glColor3f(1.f, 1.f, 1.f);
		current_Mode = "Game Mode";
		eyeX = radius * sin(theta * PI / 180) * cos(phi * PI / 180);
		eyeY = radius * sin(phi * PI / 180);
		eyeZ = radius * cos(theta * PI / 180) * cos(phi * PI / 180);
		gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, cos(phi * PI / 180), 0.0);
		glPushMatrix();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glTranslatef(0, 2.7, 0);
		draw_aim(); //blue side
		glEnable(GL_TEXTURE_2D);
		glPopMatrix();
		glPushMatrix();
		glRotatef(target_angle, 0, 1, 0);
		glTranslatef(25, 2.7, 0);
		draw_obj(target);
		//draw_target();
		glPopMatrix();
		glPushMatrix();
		//glEnable(GL_LIGHTING);
		glColor3f(1.f, 1.f, 1.f);
		//draw_obj_with_texture(revolver_body, revolver_body_texture);
		draw_obj_with_texture(R, R_texture);
		glPopMatrix();
		draw_skybox();
	
		glMatrixMode(GL_TEXTURE);
//		glPushMatrix();
	//	glGetFloatv(GL_MODELVIEW_MATRIX, temp_matrix); //현재 모델뷰의 행렬을 불러온다.
		//temp_matrix[14] = 0.f;
		//GLfloat inv[16];
		//gluInverMatrix(temp_matrix, inv); // 역행렬을 구하는 함수.

		//glMultMatrixf(inv); //현재 변환행렬에서  Temp(구한 역행렬)를 곱해준다.
		//시선행렬 역행렬 적용
		//glMultMatrix(), glRotatef(),...
		glMatrixMode(GL_MODELVIEW);
		
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glEnable(GL_TEXTURE_GEN_R);
		glEnable(GL_TEXTURE_CUBE_MAP);
		glBindTexture(GL_TEXTURE_CUBE_MAP, g_nCubeTex);
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
		glDisable(GL_TEXTURE_GEN_R);
		glDisable(GL_TEXTURE_CUBE_MAP);
		glMatrixMode(GL_TEXTURE);
		glMatrixMode(GL_MODELVIEW);
		glutSwapBuffers();
		//glColor3f(1.f, 1.f, 1.f);
		//draw_obj_with_texture(R, R_texture);
		/*glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
		glDisable(GL_TEXTURE_GEN_R);
		glDisable(GL_TEXTURE_CUBE_MAP);*/
		//draw_obj_with_texture(revolver_body, revolver_body_texture);
		//glMatrixMode(GL_TEXTURE);
		//glPushMatrix();
		//GLfloat temp_matrix[16];
		//glGetFloatv(GL_MODELVIEW_MATRIX, temp_matrix); //현재 모델뷰의 행렬을 불러온다.
		//temp_matrix[14] = 0.f;
		//GLfloat inv[16];
		//gluInverMatrix(temp_matrix, inv); // 역행렬을 구하는 함수.
		//glMultMatrixf(inv); //현재 변환행렬에서  Temp(구한 역행렬)를 곱해준다.
		//glMatrixMode(GL_MODELVIEW);


		//glEnable(GL_TEXTURE_GEN_S);
		//glEnable(GL_TEXTURE_GEN_T);
		//glEnable(GL_TEXTURE_GEN_R);
		//glEnable(GL_TEXTURE_CUBE_MAP);
		//glBindTexture(GL_TEXTURE_CUBE_MAP, g_nCubeTex);
		//// Mesh Draw
		//glutSolidSphere(2.0f, 30, 30);
		//draw_obj(R);
		/*glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
		glDisable(GL_TEXTURE_GEN_R);
		glDisable(GL_TEXTURE_CUBE_MAP);


		glMatrixMode(GL_TEXTURE);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);*/
	}
	
	
	/*glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	draw_axis();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glColor3f(1.f, 1.f, 1.f);
	
	draw_obj_with_texture(revolver_body,revolver_body_texture);
	draw_obj(revolver_trigger);
	draw_obj(revolver_hammer);
	draw_obj(bullet);
	draw_obj(revolver_magazine);*/
	//glutSwapBuffers();
	//glFlush();
}