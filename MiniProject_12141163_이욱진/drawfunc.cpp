#pragma once
#include "mini.h"

void draw_aim(void)
{
	glLineWidth(2.0f);
	glBegin(GL_LINES);

	glColor4f(1.f, 0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 50.f);

	glEnd();
	glLineWidth(1);
}
void draw_axis2(void)
{
	glLineWidth(1.5f);
	glBegin(GL_LINES);

	glColor4f(1.f, 0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(14.f, 0.f, 0.f);

	glColor4f(0.f, 1.f, 0.f, 1.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 14.f, 0.f);

	glColor4f(0.f, 0.f, 1.f, 1.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 14.f);

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
	/*printf("draw_obj_with_texture function call\n");*/
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
		R_Positionx = objParser->vertices[objParser->vertexIdx[n + 2] - 1].x;
		R_Positiony = objParser->vertices[objParser->vertexIdx[n + 2] - 1].y;
		R_Positionz = objParser->vertices[objParser->vertexIdx[n + 2] - 1].z;
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
	ObjParser* R = new ObjParser("3d_Object/R2.obj");
	target = new ObjParser("3d_Object/target2.obj");
	
	if (assemblyMode)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_POLYGON_SMOOTH);
		glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
		//resize(800, 600);
		//glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		current_Mode = "Assembly Mode";
		eyeX = radius * sin(theta * PI / 180) * cos(phi * PI / 180);
		eyeY = radius * sin(phi * PI / 180);
		eyeZ = radius * cos(theta * PI / 180) * cos(phi * PI / 180);
		gluLookAt(eyeX, eyeY, eyeZ, 0, 0, 0, 0, cos(phi * PI / 180), 0); //키보드입력을통한 object조립. 마우스와 키보드를 통한 카메라전환
		
		glPushMatrix();
		draw_ModeName(current_Mode);
		glPopMatrix();
		glPushMatrix();
		draw_partial_obj();
		glPopMatrix();
		glPushMatrix();
		resize(800, 600);
		//glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		draw_axis2();
		//glEnable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		glPushMatrix();
		if (drawsignal)
		{
			glTranslatef(cx, cy, cz);
			dobjx[dobj] = cx; dobjy[dobj] = cy; dobjz[dobj] = cz; // 위치 저장.
			cr = c1[colorindex]; cg = c2[colorindex]; cb = c2[colorindex];
			glColor3f(cr, cg, cb);
			dobjc[dobj][0] = cr; dobjc[dobj][1] = cg; dobjc[dobj][2] = cb; //컬러 저장.
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
		glPopMatrix();
		glPushMatrix();
			for (int i = 1; i <= dobj; i++)
			{
				glTranslatef(dobjx[i - 1], dobjy[i - 1], dobjz[i - 1]);
				if (shsignal2) // obj ID 방아쇠 해머 각도를 idle함수를 활용하여 45도 rotate 시킨다. shooting motion
				{
					//ID 2, 4 rotate
					if (objidset[i] == 2)
					{
						glRotatef(hangle, 1, 0, 0); //hammer angle
					}
					else if (objidset[i] == 4)
					{
						glRotatef(tangle, 1, 0, 0); //trigger angle
					}
				}
				//ID 1 rotate
				if (objidset[i] == 1)
				{
					glRotatef(loadangle, 0, 0, 1); //magazine angle
				}
				glColor3f(dobjc[i - 1][0], dobjc[i - 1][1], dobjc[i - 1][2]);
				switch (objidset[i])
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
				glPopMatrix();
				glPushMatrix();
			}
		glPopMatrix();
		glutSwapBuffers();
		glFlush();
	}
	else if (GameMode)
	{
		glColor3f(1.f, 1.f, 1.f);
		current_Mode = "Game Mode";
		/*eyeX = radius * sin(theta * PI / 180) * cos(phi * PI / 180);
		eyeY = radius * sin(phi * PI / 180);
		eyeZ = radius * cos(theta * PI / 180) * cos(phi * PI / 180);*/
		gluLookAt(0.5, 4.5,-4.5, R_anglex + 0.1 ,R_angley + 3.0, 0.0, 0.0, /*cos(phi * PI / 180)*/1, 0.0);
		
		glPushMatrix();
		glRotatef(rx, 1.0f, 0, 0);
		glRotatef(ry, 0, 1.0f, 0);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glTranslatef(0, 2.7, 0);
		draw_aim(); //blue side
		glEnable(GL_TEXTURE_2D);
		glPopMatrix();
		glPushMatrix();
		glRotatef(target_angle, 0, 1, 0);
		glTranslatef(25, 2.7, 0);
		draw_obj_with_texture(target,target_texture);
		//draw_target();
		glPopMatrix();
		glPushMatrix();
		glRotatef(rx, 1.0, 0, 0);
		glRotatef(ry, 0, 1.0, 0);
		glColor3f(1.f, 1.f, 1.f);
		draw_obj_with_texture(R, R_texture);
		glPopMatrix();
		if (shsignal)
		{
			glPushMatrix();
			glRotatef(rx, 1.0f, 0, 0);
			glRotatef(ry, 0, 1.0f, 0);
			glTranslatef(0, 2.7, 1.0);
			glTranslatef(0, 0, bu_dist);
			/*glColor3f(1, 0, 0);*/
			draw_obj(bullet);
			glPopMatrix();
		}
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
		glFlush();
	}
}