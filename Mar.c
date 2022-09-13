#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define TEXTID 5

int disp = 0;
static float angle = 0.0;
 float x = 0.0f, y = 1.75f, z = 5.0f;
static float lx = 0.10f, ly = 0.10f, lz = -1.0f;
int xxxx = 0, yyyy = 0, open = 1;
int i=0,box=0,light=0;
void Orient(float ang)
{
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void DrawTextXY(double x, double y, double z, double scale, char *s)
{
	int i;
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(scale, scale, scale);
	for (i = 0; i < strlen(s); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, s[i]);
	glPopMatrix();
}


void front()
{
	glColor3f(1.0,0.0,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-1.8,3.8,0.2,0.002,"ATME COLLEGE OF ENGINEERING");

	glColor3f(1.0,0.8,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-1,3.2,0.0,0.002,"  Graveyard");

        glColor3f(0.0,0.0,1.0);
	glLoadName(TEXTID);
	DrawTextXY(-1,3.5,0.2,0.002,"MINI PROJECT ON");

	glColor3f(1.0,0.8,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-2,2,1.0,0.001," SUBMITTED BY: Moulya E (4AD19CS047)");

	glColor3f(1.0,0.8,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-2,1.8,1.0,0.001,"            Rakshitha R (4AD19CS048)");

	glColor3f(1.0,0.8,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-1.9,1.5,1.0,0.001," GUIDE: MS Poornashree Narayani S Kulkarni ");
	DrawTextXY(-1.9,1.3,1.0,0.001,"      ASSISTANT PROFESSOR, ");
	
  	// glColor3f(1.0,0.8,0.0);
	// glLoadName(TEXTID);
	// DrawTextXY(-1.8,1,1.0,0.001,"CO-ORDINATOR: MRS SUNITHA PATEL M S");
	// DrawTextXY(-1.8,0.8,1.0,0.001,"           ASSISTANT PROFESSOR,");
	
}


void Reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h); // Set the viewport to be the entire window
	gluPerspective(45, 1.0f * w / h, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	if (disp == 0)
	{
		front();
	}

	if (disp == 1)
	{
		glColor3f(0.1f, 1.0f, 0.2f); // Draw ground
		glBegin(GL_QUADS);
		glVertex3f(-300.0f, 0.0f, -300.0f);
		glVertex3f(-300.0f, 0.0f, 300.0f);
		glVertex3f(300.0f, 0.0f, 300.0f);
		glVertex3f(300.0f, 0.0f, -300.0f);
		glEnd();

		glPushMatrix();
		glScalef(2.0, 2.0, 2.0);
		glTranslatef(0.0, .85, -20.0);

		glPopMatrix();
	

void tree()
{
glColor3ub(139,69,19);
glBegin(GL_POLYGON);
glVertex3f(3.25,-0.84,2.6);//a
glVertex3f(3.45,-0.84,2.6);//b
glVertex3f(3.45,0.4,2.6);//c
glVertex3f(3.25,0.4,2.6);//d
glEnd();

glColor3ub(0,139,0);
glBegin(GL_POLYGON);
glVertex3f(3.2,0.09,2.6);//1
glVertex3f(2.8,0.09,2.6);//2
glVertex3f(3.35,2.0,2.6);//3
glVertex3f(3.9,0.09,2.6);//4
glVertex3f(3.5,0.09,2.6);//5
glEnd();


}
tree();

glPushMatrix();
glTranslatef(0.7,0.0,0.2);
glScalef(100,0,100);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(1.2,0.0,0.3);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(1.8,0.0,0.0);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(2.4,0.0,0.2);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-7.4,0.0,0.2);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-7.9,0.0,0.4);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-8.4,0.0,0.1);
tree();
glPopMatrix();

tree();

glPushMatrix();
glTranslatef(0.7,0.0,10.2);
glScalef(100,0,100);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(1.2,0.0,10.3);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(1.8,0.0,10.0);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(2.4,0.0,10.2);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-7.4,0.0,10.2);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-7.9,0.0,10.4);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-8.4,0.0,10.1);
tree();
glPopMatrix();
tree();

glPushMatrix();
glTranslatef(0.7,0.0,20.2);
glScalef(200,0,200);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(1.2,0.0,20.3);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(1.8,0.0,20.0);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(2.4,0.0,20.2);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-7.4,0.0,20.2);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-7.9,0.0,20.4);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-8.4,0.0,20.1);
tree();
glPopMatrix();

tree();

glPushMatrix();
glTranslatef(0.7,0.0,30.2);
glScalef(300,0,300);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(1.2,0.0,30.3);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(1.8,0.0,30.0);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(2.4,0.0,30.2);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-7.4,0.0,30.2);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-7.9,0.0,30.4);
tree();
glPopMatrix();

glPushMatrix();
glTranslatef(-8.4,0.0,30.1);
tree();
glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f); // Draw ground
	glBegin(GL_QUADS);
	glVertex3f(-300.0f, 0.0f, 300.0f);
	glVertex3f(300.0f, 0.0f, 300.0f);
	glVertex3f(300.0f, 30.0f, 300.0f);
	glVertex3f(-300.0f, 30.0f, 300.0f);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f); // Draw ground
	glBegin(GL_QUADS);
	glVertex3f(-300.0f, 0.0f, -300.0f);
	glVertex3f(-50.0f, 0.0f, -300.0f);
	glVertex3f(-50.0f, 30.0f, -300.0f);
	glVertex3f(-300.0f, 30.0f, -300.0f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f); // Draw ground
	glBegin(GL_QUADS);
	glVertex3f(300.0f, 0.0f, -300.0f);
	glVertex3f(50.0f, 0.0f, -300.0f);
	glVertex3f(50.0f, 30.0f, -300.0f);
	glVertex3f(300.0f, 30.0f, -300.0f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f); // Draw ground
	glBegin(GL_QUADS);
	glVertex3f(300.0f, 0.0f, 300.0f);
	glVertex3f(300.0f, 0.0f, -300.0f);
	glVertex3f(300.0f, 30.0f, -300.0f);
	glVertex3f(300.0f, 30.0f, 300.0f);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f); // Draw ground
	glBegin(GL_QUADS);
	glVertex3f(-300.0f, 0.0f, 300.0f);
	glVertex3f(-300.0f, 0.0f, -300.0f);
	glVertex3f(-300.0f, 30.0f, -300.0f);
	glVertex3f(-300.0f, 30.0f, 300.0f);
	glEnd();






	glColor3f(0.51, 0.33, 0.18); 
	glBegin(GL_QUADS);
	glVertex3f(90.0f, 10.0f, 25.0f);
	glVertex3f(60.0f, 10.0f, 15.0f);
	glVertex3f(60.0f, 0.0f, 15.0f);

	glVertex3f(90.0f, 0.0f, 25.0f);

	glEnd();
	glColor3f(0.51, 0.33, 0.18); 
	glBegin(GL_QUADS);
	glVertex3f(90.0f, 10.0f, 35.0f);
	glVertex3f(60.0f, 10.0f, 45.0f);
	glVertex3f(60.0f, 0.0f, 45.0f);

	glVertex3f(90.0f, 0.0f, 35.0f);

	glEnd();

	glColor3f(0.51, 0.33, 0.18); 
	glBegin(GL_QUADS);
	glVertex3f(10.0f, 10.0f, 40.0f);

	glVertex3f(60.0f, 10.0f, 45.0f);
	glVertex3f(60.0f, 0.0f, 45.0f);

	glVertex3f(10.0f, 0.0f, 40.0f);


	glEnd();

	glColor3f(0.51, 0.33, 0.18); // Draw ground
	glBegin(GL_QUADS);
	glVertex3f(10.0f, 10.0f, 20.0f);
	glVertex3f(60.0f, 10.0f, 15.0f);
	glVertex3f(60.0f, 0.0f, 15.0f);
	glVertex3f(10.0f, 0.0f, 20.0f);

	glEnd();





	glColor3f(0.51, 0.33, 0.18); // Draw ground
	glBegin(GL_QUADS);

	glVertex3f(90.0f, 0.01f, 35.0f);
	glVertex3f(90.0f, 0.01f, 25.0f);
	glVertex3f(90.0f, 10.0f, 25.0f);
	glVertex3f(90.0f, 10.0f, 35.0f);

	glEnd();

	glColor3f(0.51, 0.33, 0.18); // Draw ground
	glBegin(GL_QUADS);
	glVertex3f(10.0f, 10.0f, 40.0f);
	glVertex3f(10.0f, 10.0f, 20.0f);
	glVertex3f(10.0f, 0.0f, 20.0f);
	glVertex3f(10.0f, 0.0f, 40.0f);
	glEnd();

	glColor3f(0.51, 0.44, 0.18);
	glBegin(GL_POLYGON);
	glVertex3f(10.0f, 0.01f, 40.0f);

	glVertex3f(60.0f, 0.01f, 45.0f);
	glVertex3f(90.0f, 0.01f, 35.0f);

	glVertex3f(90.0f, 0.01f, 25.0f);
	glVertex3f(60.0f, 0.01f, 15.0f);
	glVertex3f(10.0f, 0.01f, 20.0f);
	glEnd();



if(i==0)
{
	glColor3f(0.51, 0.44, 0.18);
	glBegin(GL_POLYGON);
	glVertex3f(10.0f, 10.01f, 40.0f);

	glVertex3f(60.0f, 10.01f, 45.0f);
	glVertex3f(90.0f, 10.01f, 35.0f);

	glVertex3f(90.0f, 10.01f, 25.0f);
	glVertex3f(60.0f, 10.01f, 15.0f);
	glVertex3f(10.0f, 10.01f, 20.0f);
	glEnd();
	
	
	
	glColor3f(1.51, 1.33, 1.18); // Draw ground
	
	glBegin(GL_QUADS);
	glVertex3f(75.0f, 10.02f, 28.01f);
	glVertex3f(75.0f, 10.02f, 32.01f);
	glVertex3f(45.0f, 10.02f, 32.01f);
	glVertex3f(45.0f, 10.02f, 28.01f);

	glEnd();
	glColor3f(1.51, 1.33, 1.18); // Draw ground
	
	glBegin(GL_QUADS);
	glVertex3f(69.0f, 10.02f, 25.01f);
	glVertex3f(69.0f, 10.02f, 35.01f);
	glVertex3f(65.0f, 10.02f, 35.01f);
	glVertex3f(65.0f, 10.02f, 25.01f);
	glEnd();
	
	glEnd();

}











































if(i==1)
{


	glColor3f(0.51, 0.33, 0.18);
	glBegin(GL_POLYGON);
	glVertex3f(10.0f, 25.0f, 45.0f);
	glVertex3f(60.0f, 30.0f, 45.0f);
	glVertex3f(90.0f, 25.0f, 45.0f);
	glVertex3f(90.0f, 15.0f, 45.0f);
	glVertex3f(60.0f, 10.0f, 45.0f);
	glVertex3f(10.0f, 15.0f, 45.0f);
	glEnd();
	
	glColor3f(1.51, 1.33, 1.18); // Draw ground
	
	glBegin(GL_QUADS);
	glVertex3f(75.0f, 18.0f, 45.01f);
	glVertex3f(75.0f, 22.0f, 45.01f);
	glVertex3f(45.0f, 22.0f, 45.01f);
	glVertex3f(45.0f, 18.0f, 45.01f);
	glEnd();
	glColor3f(1.51, 1.33, 1.18); // Draw ground
	
	glBegin(GL_QUADS);
	glVertex3f(69.0f, 15.0f, 45.01f);
	glVertex3f(69.0f, 25.0f, 45.01f);
	glVertex3f(65.0f, 25.0f, 45.01f);
	glVertex3f(65.0f, 15.0f, 45.01f);
	glEnd();
	
	glColor3f(1.51, 1.33, 1.18); // Draw ground
	glBegin(GL_QUADS);
	glVertex3f(75.0f, 18.0f, 44.901f);
	glVertex3f(75.0f, 22.0f, 44.901f);
	glVertex3f(45.0f, 22.0f, 44.901f);
	glVertex3f(45.0f, 18.0f, 44.901f);
	glEnd();
	
	glColor3f(1.51, 1.33, 1.18); // Draw ground
	glBegin(GL_QUADS);
	glVertex3f(69.0f, 15.0f, 44.901f);
	glVertex3f(69.0f, 25.0f, 44.901f);
	glVertex3f(65.0f, 25.0f, 44.901f);
	glVertex3f(65.0f, 15.0f, 44.901f);
	glEnd();


}



//sholder
	glColor3f(.01f, .045f, .95f);
	glPushMatrix();
	glTranslated(73, 3,24.5);
	glScaled(3, 2, 4);

	glutSolidSphere(1.05,5,5);
	glPopMatrix();


	glColor3f(.01f, .045f, .95f);
	glPushMatrix();
	glTranslated(73, 3,34.5);
	glScaled(3, 2, 4);

	glutSolidSphere(1.05,5,5);
	glPopMatrix();




//hair

	glColor3f(.01f, .05f, .05f);
	glPushMatrix();
	glTranslated(83, 3,30);
	glScaled(4, 4, 4);

	glutSolidSphere(1.05,50,50);
	glPopMatrix();


//nose

	glColor3f(.09f, .05f, .075f);
	glPushMatrix();
	glTranslated(80, 4,30);
	glScaled(5, 5, 5);

	glutSolidTetrahedron();
	glPopMatrix();



//head

	glColor3f(.91f, .745f, .675f);
	glPushMatrix();
	glTranslated(80, 3,30);
	glScaled(5, 5, 5);

	glutSolidSphere(1.05,50,50);
	glPopMatrix();

//eye

glColor3f(.0f, .0f, .0f);
	glPushMatrix();
	glTranslated(80.5, 8,31);
	glScaled(10, 5, 5);

	glutSolidSphere(.1,50,50);
	glPopMatrix();
//mouth

glColor3f(.0f, .0f, .0f);
	glPushMatrix();
	glTranslated(76.5, 7.5,30.25);
	glScaled(5, 5, 10);

	glutSolidSphere(.1,50,50);
	glPopMatrix();

//eye
	glColor3f(.0f, .0f, .0f);
	glPushMatrix();
	glTranslated(80.5, 8,29);
	glScaled(10, 5, 5);

	glutSolidSphere(.1,50,50);
	glPopMatrix();




		glColor3f(0.0f, 0.0f, 0.82f);
	glPushMatrix();
	glTranslated(62, 1,30);
	glScaled(25, 8, 10);

	glutSolidCube(1.0);
	glPopMatrix();
			//Leg
	glColor3f(.8f,.75f,.0f);
	glPushMatrix();
	glTranslated(40, 1,25);
	glScaled(23, 5, 3);

	glutSolidCube(1.0);
	glPopMatrix();
	
	glColor3f(.91f, .745f, .675f);
	glPushMatrix();
	glTranslated(35, 1,25);
	glScaled(23, 4.9, 2.9);

	glutSolidCube(1.0);
	glPopMatrix();
//legg



	glColor3f(.8f,.75f,.0f);
	glPushMatrix();
	glTranslated(40, 1,35);
	glScaled(23, 5, 3);

	glutSolidCube(1.0);
	glPopMatrix();


	glColor3f(.91f, .745f, .675f);
	glPushMatrix();
	glTranslated(35, 1,35);
	glScaled(23, 4.9, 2.9);

	glutSolidCube(1.0);
	glPopMatrix();

//
glColor3f(.8f,.75f,.0f);
	glPushMatrix();
	glTranslated(37, 3,25);
	glScaled(3, 2, 2.3);

	glutSolidSphere(1.05,5,5);
	glPopMatrix();

glColor3f(.8f,.75f,.0f);
	glPushMatrix();
	glTranslated(37, 3,35);
	glScaled(3, 2, 2.3);

	glutSolidSphere(1.05,5,5);
	glPopMatrix();
//arm
	glColor3f(1.0f, 0.88f, 0.82f);
	glPushMatrix();
	glTranslated(55, 1,23);
	glScaled(10, 5, 3);

	glutSolidCube(1.0);
	glPopMatrix();


	glColor3f(.0f, 0.0f, 0.82f);
	glPushMatrix();
	glTranslated(65, 1,23);
	glScaled(20, 4.9,2.9);
	glutSolidCube(1.0);
	glPopMatrix();
////arm





	glColor3f(1.0f, 0.88f, 0.82f);
	glPushMatrix();
	glTranslated(55, 1,37);
	glScaled(10, 5, 3);

	glutSolidCube(1.0);
	glPopMatrix();


	glColor3f(.0f, 0.0f, 0.82f);
	glPushMatrix();
	glTranslated(65, 1,37);
	glScaled(20, 4.9,2.9);
	glutSolidCube(1.0);
	glPopMatrix();






















































	
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-20, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-40, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-60, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-80, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-100, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-120, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-140, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-160, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-180, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-200, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-220, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-240, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(20, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(40, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(60, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(80, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(120, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(140, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(160, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(180, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(200, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(220, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(240, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-20, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-40, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-60, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-80, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-100, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-120, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-140, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-160, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-180, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-200, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-220, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-240, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(20, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(40, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(60, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(80, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(120, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(140, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(160, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(180, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(200, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(220, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(240, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-20, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-40, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-60, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-80, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-100, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-120, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-140, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-160, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-180, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-200, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-220, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-240, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(20, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(40, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(60, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(80, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(120, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(140, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(160, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(180, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(200, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(220, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(240, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-20, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-40, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-60, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-80, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-100, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-120, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-140, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-160, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-180, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-200, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-220, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-240, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(20, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(40, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(60, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(80, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(120, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(140, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(160, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(180, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(200, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(220, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(240, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-20, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-40, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-60, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-80, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-100, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-120, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-140, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-160, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-180, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-200, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-220, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-240, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, 240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(20, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(40, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(60, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(80, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(120, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(140, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(160, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(180, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(200, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(220, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(240, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-20, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-40, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-60, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-80, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-100, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-120, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-140, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-160, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-180, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-200, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-220, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-240, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -0);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(20, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(40, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(60, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(80, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(120, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(140, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(160, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(180, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(200, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(220, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(240, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-20, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-40, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-60, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-80, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-100, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-120, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-140, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-160, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-180, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-200, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-220, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-240, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -60);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(20, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(40, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(60, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(80, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(120, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(140, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(160, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(180, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(200, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(220, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(240, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-20, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-40, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-60, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-80, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-100, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-120, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-140, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-160, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-180, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-200, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-220, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-240, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -120);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(20, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(40, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(60, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(80, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(120, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(140, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(160, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(180, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(200, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(220, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(240, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-20, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-40, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-60, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-80, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-100, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-120, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-140, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-160, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-180, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-200, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-220, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-240, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -180);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(20, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(40, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(60, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(80, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(100, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(120, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(140, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(160, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(180, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(200, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(220, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(240, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-20, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-40, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-60, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-80, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-100, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-120, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-140, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-160, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-180, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-200, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-220, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(-240, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();
	glColor3f(1.0f, 0.99f, 0.82f);
	glPushMatrix();
	glTranslated(0, 5, -240);
	glScaled(1, 10, 7);

	glutSolidCube(1.0);
	glPopMatrix();

	glutSolidCube(1.0);
	glPopMatrix();
	}
	glutSwapBuffers();
	
}

void Move(int i)
{
	if (xxxx == 1)
		y = y + i * (lz)*0.1;

	if (yyyy == 1)
	{
		x = x + i * (lz)*.1;
	}

	else
	{
		z = z + i * (lz)*0.5;
		x = x + i * (lx)*0.5;
	}

	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void Keys(unsigned char key, int x, int y)
{
	glLoadIdentity();
	if (key == 'q')
		exit(0);
	if (key == 't')
		gluLookAt(1, 190, 50, 0, 0, -10, 0.0, 0.1, 0.0);
	if (key == 'l')
		Move(4);
	xxxx = 1, yyyy = 0;
	if (key == 'f')
		Move(-4);
	xxxx = 1, yyyy = 0;
	if (key == 'n')
		Move(4);
	yyyy = 1;
	xxxx = 0;
	if (key == 'r')
		Move(-4);
	yyyy = 1;
	xxxx = 0;
	if (key == 'o')
	{
		i = 1;
		
	}
	if (key == 'c')
	{
		i = 0;
		
	}
	if (key == 'd')
	{
		box = 1;
		
	}
	if (key == 'b')
	{
		glClearColor(.7, 0.85, 1.0, 1.0);
	}
	if (key == 'k')
	{
		glClearColor(.0, 0.05, 0.0, 0.0);
	}
if (key == 'S')
	{
	 glEnable(GL_LIGHTING);
	 glEnable(GL_LIGHT0);
	}
	if (key == 's')
	{
			 glEnable(GL_LIGHTING);
	 glEnable(GL_LIGHT0);
		light=1;
		GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
		GLfloat mat_diffuse[] = {0.5f, 0.5f, 0.5f, 1.0f};
		GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
		GLfloat mat_shininess[] = {50.0f};
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		GLfloat Lightintensity[] = {1.0f, 1.0f, 1.0f, 1.0f};
		GLfloat Lightposition[] = {2.0f, 6.0f, 3.0f, 0.0f};
		glLightfv(GL_LIGHT0, GL_POSITION, Lightposition);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, Lightintensity);
	}
}

void arrowKeys(int key, int x, int y)
{

	switch (key)
	{
	case GLUT_KEY_LEFT:
		angle -= 0.05f;
		Orient(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.05f;
		Orient(angle);
		break;
	case GLUT_KEY_UP:
		Move(2);
		xxxx = 0, yyyy = 0;
		break;
	case GLUT_KEY_DOWN:
		Move(-2);
		xxxx = 0, yyyy = 0;
		break;
	}
}

void ProcessMenu(int value) // Reset flags as appropriate in response to menu selections
{
	glutPostRedisplay();
}

void ProcessMenu1(int value)
{
	switch (value)
	{
	case 1:
		if (value == 1)
			disp = 1;
	}
}

void menu()
{
	int control;
	int control1;
	control = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("**CONTROLS**", 1);
	glutAddMenuEntry("1)  UP KEY:to move in Forward Direction.", 1);
	glutAddMenuEntry("2)  DOWN KEY:to move  in Backward Direction.", 1);
	glutAddMenuEntry("3)  LEFT KEY:to Turn Left .", 1);
	glutAddMenuEntry("4)  RIGHT KEY:to Turn Right .", 1);
	glutAddMenuEntry("5)  r:moves Towards Right. ", 1);
	glutAddMenuEntry("6)  l:moves Towards Left.", 1);
	glutAddMenuEntry("7)  f:moves Far.", 1);
	glutAddMenuEntry("8)  n:moves Near.", 1);
	glutAddMenuEntry("9)  t:Top view.", 1);
	glutAddMenuEntry("10)  o:Open Box.", 1);
	glutAddMenuEntry("11)  c:Close Box.", 1);
	glutAddMenuEntry("12)  g:Day view.", 1);
	glutAddMenuEntry("13)  k:Night view.", 1);
	glutAddMenuEntry("14)  s:Lighting.", 1);
	//glutAddMenuEntry("15)  S:Scary view.", 1);
	glutAddMenuEntry("15) q:Quit.", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	control1 = glutCreateMenu(ProcessMenu1);
	glutAddMenuEntry("START", 1);
	glutAttachMenu(GLUT_LEFT_BUTTON);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1010, 710);
	glutCreateWindow("Graveyard");
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(Keys);
	glutSpecialFunc(arrowKeys);
	menu();
	glutFullScreen(); // to see o/p in full screen on monitor
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(Reshape);
		 glEnable(GL_DEPTH_TEST);
		 glEnable(GL_NORMALIZE);
	glutMainLoop();
	return (0);
}
