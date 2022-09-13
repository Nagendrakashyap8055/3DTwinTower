#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define TEXTID 5

int disp = 0;
static float angle = 0.0;
static float x = 0.0f, y = 1.75f, z = 5.0f;
static float lx = 0.10f, ly = 0.10f, lz = -1.0f;
int xxxx = 0, yyyy = 0, open = 1;
static GLfloat theta[]={0.0,0.0,0.0};
static GLint axis=1;
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
	glColor3f(1.0, 0.0, 0.0);
	glLoadName(TEXTID);
	DrawTextXY(-1.8, 3.8, 0.2, 0.002, "ATME COLLEGE OF ENGINEERING");

	glColor3f(1.0, 0.8, 0.0);
	glLoadName(TEXTID);
	DrawTextXY(-1, 3.2, 0.0, 0.002, "  The Pentagon");

	glColor3f(0.0, 0.0, 1.0);
	glLoadName(TEXTID);
	DrawTextXY(-1, 3.5, 0.2, 0.002, "MINI PROJECT ON");

	glColor3f(1.0, 0.8, 0.0);
	glLoadName(TEXTID);
	DrawTextXY(-2, 2, 1.0, 0.001, " SUBMITTED BY: Nagendra B (4AD19CS048)");

	glColor3f(1.0, 0.8, 0.0);
	glLoadName(TEXTID);
	DrawTextXY(-2, 1.8, 1.0, 0.001, "            Mithilesh A(4AD19CS041)");

	glColor3f(1.0, 0.8, 0.0);
	glLoadName(TEXTID);
	DrawTextXY(-1.9, 1.5, 1.0, 0.001, " GUIDE: POORNASREE KULKARNI");
	DrawTextXY(-1.9, 1.3, 1.0, 0.001, "      ASSISTANT PROFESSOR, ");

	glColor3f(1.0, 0.8, 0.0);
	glLoadName(TEXTID);
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
		glClearColor(0.56, 0.40, 0.9, 0.0);
		glColor3f(0.1f, 1.0f, 0.2f); // Draw ground
		glBegin(GL_QUADS);
		glVertex3f(-150.0f, 0.0f, -150.0f);
		glVertex3f(-150.0f, 0.0f, 150.0f);
		glVertex3f(150.0f, 0.0f, 150.0f);
		glVertex3f(150.0f, 0.0f, -150.0f);
		glEnd();

		// glClearColor(.7, 0.85, 1.0, 1.0);
		glColor3f(0.97, 0.60, 22); // top1
		glBegin(GL_QUADS);
		glVertex3f(-10.0f, 130.0f, -10.0f);
		glVertex3f(-10.0f, 130.0f, 10.0f);
		glVertex3f(10.0f, 130.0f, 10.0f);
		glVertex3f(10.0f, 130.0f, -10.0f);
		glEnd();

		glColor3f(1.0f, 1.0f, 1.0f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-10.0f, 130.0f, -10.0f);
		glVertex3f(-10.0f, 130.0f, 10.0f);
		glVertex3f(-10.0f, 0.0f, 10.0f);
		glVertex3f(-10.0f, 0.0f, -10.0f);
		glEnd();

		glColor3f(0.1f, 0.1f, 0.0f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS); // black1
		glVertex3f(-10.0f, 130.0f, -10.0f);
		glVertex3f(10.0f, 130.0f, -10.0f);
		glVertex3f(10.0f, 0.0f, -10.0f);
		glVertex3f(-10.0f, 0.0f, -10.0f);
		glEnd();

		glColor3f(.96f, 0.51f, 0.0f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS);
		glVertex3f(10.0f, 130.0f, 10.0f);
		glVertex3f(-10.0f, 130.0f, 10.0f); // orange1
		glVertex3f(-10.0f, 0.0f, 10.0f);
		glVertex3f(10.0f, 0.0f, 10.0f);
		glEnd();

		/// glColor3f(1.0f, 0.0f, 0.0f);
		// glColor3f(0.97, 0.60, 0.22);
		glColor3f(0.51, 0.33, 0.18);
		glBegin(GL_QUADS); // red1
		glVertex3f(10.0f, 130.0f, -10.0f);
		glVertex3f(10.0f, 130.0f, 10.0f);
		glVertex3f(10.0f, 0.0f, 10.0f);
		glVertex3f(10.0f, 0.0f, -10.0f);
		glEnd();
		// glClearColor(.7, 0.85, 1.0, 1.0);

		glColor3f(1.0f, 1.0f, 0.2f);
		// glColor3f(0.97, 0.60, 0.22); // top2
		glBegin(GL_QUADS);

		glVertex3f(20.0f, 150.0f, 20.0f);

		glVertex3f(40.0f, 150.0f, 20.0f);

		glVertex3f(40.0f, 150.0f, 40.0f);
		glVertex3f(20.0f, 150.0f, 40.0f);
		glEnd();

		glColor3f(1.0f, 1.0f, 1.0f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS); // blue2
		glVertex3f(20.0f, 150.0f, 20.0f);
		glVertex3f(20.0f, 150.0f, 40.0f);
		glVertex3f(20.0f, 0.0f, 40.0f);
		glVertex3f(20.0f, 0.0f, 20.0f);
		glEnd();

		glColor3f(0.1f, 0.1f, 0.0f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS); // black2
		glVertex3f(20.0f, 150.0f, 20.0f);
		glVertex3f(40.0f, 150.0f, 20.0f);
		glVertex3f(40.0f, 0.0f, 20.0f);
		glVertex3f(20.0f, 0.0f, 20.0f);
		glEnd();

		glColor3f(.96f, 0.51f, 0.0f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS);
		glVertex3f(40.0f, 150.00f, 40.0f);
		glVertex3f(20.0f, 150.0f, 40.0f); // orange2
		glVertex3f(20.0f, 0.0f, 40.0f);
		glVertex3f(40.0f, 0.0f, 40.0f);
		glEnd();

		glColor3f(1.0f, 0.0f, 0.0f);
		// glColor3f(0.97, 0.60, 0.22);
		glColor3f(0.51, 0.33, 0.18);
		glBegin(GL_QUADS); // red2
		glVertex3f(40.0f, 150.0f, 20.0f);

		glVertex3f(40.0f, 150.0f, 40.0f);
		glVertex3f(40.0f, 0.0f, 40.0f);
		glVertex3f(40.0f, 0.0f, 20.0f);

		glEnd();

		/*************************************************/
		// glColor3f(97.0f, 79.0f, 30);
		glColor3f(0.51, 0.33, 0.18);
		glBegin(GL_QUADS); // 3 b
		glVertex3f(50.0f, 50.00f, 10.0f);
		glVertex3f(50.0f, 30.0f, 10.0f);

		glVertex3f(-20.0f, 30.0f, 10.0f);
		glVertex3f(-20.0f, 50.0f, 10.0f);
		glEnd();

		// glColor3f(1.0f, 0.0f, 1.0f);
		glColor3f(0.51, 0.33, 0.18);
		glBegin(GL_QUADS); // 3 f
		glVertex3f(50.0f, 50.00f, 20.0f);
		glVertex3f(50.0f, 30.0f, 20.0f);

		glVertex3f(-20.0f, 30.0f, 20.0f);
		glVertex3f(-20.0f, 50.0f, 20.0f);
		glEnd();
		glColor3f(0.0f, 0.0f, 0.0f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS); // 3 top
		glVertex3f(50.0f, 50.00f, 20.0f);
		glVertex3f(50.0f, 50.00f, 10.0f);
		glVertex3f(-20.0f, 50.0f, 10.0f);
		glVertex3f(-20.0f, 50.0f, 20.0f);

		glEnd();
		glColor3f(0.0f, 0.0f, 0.0f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS); // 3 bottom
		glVertex3f(50.0f, 30.00f, 20.0f);
		glVertex3f(50.0f, 30.00f, 10.0f);
		glVertex3f(-20.0f, 30.0f, 10.0f);
		glVertex3f(-20.0f, 30.0f, 20.0f);

		glEnd();

		glColor3f(1.0f, 0.2f, 0.2f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS); // 3 top
		glVertex3f(50.0f, 50.00f, 20.0f);
		glVertex3f(50.0f, 50.00f, 10.0f);
		glVertex3f(-20.0f, 50.0f, 10.0f);
		glVertex3f(-20.0f, 50.0f, 20.0f);

		glEnd();
		glColor3f(1.0f, 0.2f, 0.2f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS); // 3 bottom
		glVertex3f(50.0f, 30.00f, 20.0f);
		glVertex3f(50.0f, 30.00f, 10.0f);
		glVertex3f(-20.0f, 30.0f, 10.0f);
		glVertex3f(-20.0f, 30.0f, 20.0f);

		glEnd();

		glColor3f(1.0f, 0.5f, 0.5f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS); // 3 left
		glVertex3f(-20.0f, 50.0f, 10.0f);
		glVertex3f(-20.0f, 50.0f, 20.0f);
		glVertex3f(-20.0f, 30.0f, 20.0f);
		glVertex3f(-20.0f, 30.0f, 10.0f);

		glEnd();
		glColor3f(1.0f, 0.5f, 0.5f);
		// glColor3f(0.97, 0.60, 0.22);
		glBegin(GL_QUADS); // 3 right
		glVertex3f(50.0f, 50.0f, 10.0f);
		glVertex3f(50.0f, 50.0f, 20.0f);
		glVertex3f(50.0f, 30.0f, 20.0f);
		glVertex3f(50.0f, 30.0f, 10.0f);

		glEnd();

		/*******************/

		// glColor3f(1.0f, 0.0f, 1.0f);
		glColor3f(0.51, 0.33, 0.18);
		glBegin(GL_QUADS); // 4b
		glVertex3f(10.0f, 60.0f, -20.00f);
		glVertex3f(10.0f, 80.0f, -20.0f);

		glVertex3f(10.0f, 80.0f, 60.0f);
		glVertex3f(10.0f, 60.0f, 60.0f);
		glEnd();

		// glColor3f(1.0f, 0.0f, 1.0f);
		glColor3f(0.51, 0.33, 0.18);
		glBegin(GL_QUADS); // 4 f
		glVertex3f(20.0f, 60.0f, -20.00f);
		glVertex3f(20.0f, 80.0f, -20.0f);

		glVertex3f(20.0f, 80.0f, 60.0f);
		glVertex3f(20.0f, 60.0f, 60.0f);
		glEnd();
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS); // 4 top
		glVertex3f(10.0f, 80.0f, -20.0f);
		glVertex3f(10.0f, 80.0f, 60.0f);
		glVertex3f(20.0f, 80.0f, 60.0f);
		glVertex3f(20.0f, 80.0f, -20.0f);

		glEnd();
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS); // 4  bottom
		glVertex3f(10.0f, 60.0f, -20.0f);
		glVertex3f(10.0f, 60.0f, 60.0f);
		glVertex3f(20.0f, 60.0f, 60.0f);
		glVertex3f(20.0f, 60.0f, -20.0f);

		glEnd();
		glColor3f(1.0f, 0.5f, 0.5f);
		glBegin(GL_QUADS); // 4  left
		glVertex3f(10.0f, 60.0f, -20.0f);
		glVertex3f(20.0f, 80.0f, -20.0f);
		glVertex3f(20.0f, 80.0f, -20.0f);
		glVertex3f(10.0f, 60.0f, -20.0f);

		glEnd();
		glColor3f(1.0f, 0.5f, 0.5f);
		glBegin(GL_QUADS); // 4 right
		glVertex3f(50.0f, 50.0f, 80.0f);
		glVertex3f(50.0f, 50.0f, 80.0f);
		glVertex3f(50.0f, 30.0f, 80.0f);
		glVertex3f(50.0f, 30.0f, 80.0f);
		glEnd();

		glColor3f(1.0f, 0.2f, 0.2f);
		glBegin(GL_QUADS); // 4  bottom
		glVertex3f(10.0f, 60.0f, -20.0f);
		glVertex3f(10.0f, 60.0f, 60.0f);
		glVertex3f(20.0f, 60.0f, 60.0f);
		glVertex3f(20.0f, 60.0f, -20.0f);
		glEnd();

		glColor3f(1.0f, 0.5f, 0.5f);
		glBegin(GL_QUADS); // 4  left
		glVertex3f(10.0f, 80.0f, -20.0f);
		glVertex3f(20.0f, 80.0f, -20.0f);
		glVertex3f(20.0f, 60.0f, -20.0f);
		glVertex3f(10.0f, 60.0f, -20.0f);

		glEnd();
		glColor3f(1.0f, 0.5f, 0.5f);
		glBegin(GL_QUADS); // 4 right
		glVertex3f(10.0f, 80.0f, 60.0f);
		glVertex3f(20.0f, 80.0f, 60.0f);
		glVertex3f(20.0f, 60.0f, 60.0f);
		glVertex3f(10.0f, 60.0f, 60.0f);

		glEnd();
		/*********************************/
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 129.0f, -10.2f);
		glVertex3f(-9.0f, 125.0f, -10.2f);
		glVertex3f(-5.25f, 125.0f, -10.2f);
		glVertex3f(-5.25f, 129.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 129.0f, -10.2f);
		glVertex3f(-4.25f, 125.0f, -10.2f);
		glVertex3f(-0.5f, 125.0f, -10.2f);
		glVertex3f(-0.5f, 129.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 129.0f, -10.2f);
		glVertex3f(0.5f, 125.0f, -10.2f);
		glVertex3f(4.25f, 125.0f, -10.2f);
		glVertex3f(4.25f, 129.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 129.0f, -10.2f);
		glVertex3f(5.25f, 125.0f, -10.2f);
		glVertex3f(9.0f, 125.0f, -10.2f);
		glVertex3f(9.0f, 129.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 124.0f, -10.2f);
		glVertex3f(-9.0f, 120.0f, -10.2f);
		glVertex3f(-5.25f, 120.0f, -10.2f);
		glVertex3f(-5.25f, 124.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 124.0f, -10.2f);
		glVertex3f(-4.25f, 120.0f, -10.2f);
		glVertex3f(-0.5f, 120.0f, -10.2f);
		glVertex3f(-0.5f, 124.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 124.0f, -10.2f);
		glVertex3f(0.5f, 120.0f, -10.2f);
		glVertex3f(4.25f, 120.0f, -10.2f);
		glVertex3f(4.25f, 124.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 124.0f, -10.2f);
		glVertex3f(5.25f, 120.0f, -10.2f);
		glVertex3f(9.0f, 120.0f, -10.2f);
		glVertex3f(9.0f, 124.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 119.0f, -10.2f);
		glVertex3f(-9.0f, 115.0f, -10.2f);
		glVertex3f(-5.25f, 115.0f, -10.2f);
		glVertex3f(-5.25f, 119.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 119.0f, -10.2f);
		glVertex3f(-4.25f, 115.0f, -10.2f);
		glVertex3f(-0.5f, 115.0f, -10.2f);
		glVertex3f(-0.5f, 119.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 119.0f, -10.2f);
		glVertex3f(0.5f, 115.0f, -10.2f);
		glVertex3f(4.25f, 115.0f, -10.2f);
		glVertex3f(4.25f, 119.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 119.0f, -10.2f);
		glVertex3f(5.25f, 115.0f, -10.2f);
		glVertex3f(9.0f, 115.0f, -10.2f);
		glVertex3f(9.0f, 119.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 114.0f, -10.2f);
		glVertex3f(-9.0f, 110.0f, -10.2f);
		glVertex3f(-5.25f, 110.0f, -10.2f);
		glVertex3f(-5.25f, 114.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 114.0f, -10.2f);
		glVertex3f(-4.25f, 110.0f, -10.2f);
		glVertex3f(-0.5f, 110.0f, -10.2f);
		glVertex3f(-0.5f, 114.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 114.0f, -10.2f);
		glVertex3f(0.5f, 110.0f, -10.2f);
		glVertex3f(4.25f, 110.0f, -10.2f);
		glVertex3f(4.25f, 114.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 114.0f, -10.2f);
		glVertex3f(5.25f, 110.0f, -10.2f);
		glVertex3f(9.0f, 110.0f, -10.2f);
		glVertex3f(9.0f, 114.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 109.0f, -10.2f);
		glVertex3f(-9.0f, 105.0f, -10.2f);
		glVertex3f(-5.25f, 105.0f, -10.2f);
		glVertex3f(-5.25f, 109.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 109.0f, -10.2f);
		glVertex3f(-4.25f, 105.0f, -10.2f);
		glVertex3f(-0.5f, 105.0f, -10.2f);
		glVertex3f(-0.5f, 109.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 109.0f, -10.2f);
		glVertex3f(0.5f, 105.0f, -10.2f);
		glVertex3f(4.25f, 105.0f, -10.2f);
		glVertex3f(4.25f, 109.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 109.0f, -10.2f);
		glVertex3f(5.25f, 105.0f, -10.2f);
		glVertex3f(9.0f, 105.0f, -10.2f);
		glVertex3f(9.0f, 109.0f, -10.2f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 104.0f, -10.2f);
		glVertex3f(-9.0f, 100.0f, -10.2f);
		glVertex3f(-5.25f, 100.0f, -10.2f);
		glVertex3f(-5.25f, 104.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 104.0f, -10.2f);
		glVertex3f(-4.25f, 100.0f, -10.2f);
		glVertex3f(-0.5f, 100.0f, -10.2f);
		glVertex3f(-0.5f, 104.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 104.0f, -10.2f);
		glVertex3f(0.5f, 100.0f, -10.2f);
		glVertex3f(4.25f, 100.0f, -10.2f);
		glVertex3f(4.25f, 104.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 104.0f, -10.2f);
		glVertex3f(5.25f, 100.0f, -10.2f);
		glVertex3f(9.0f, 100.0f, -10.2f);
		glVertex3f(9.0f, 104.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 99.0f, -10.2f);
		glVertex3f(-9.0f, 95.0f, -10.2f);
		glVertex3f(-5.25f, 95.0f, -10.2f);
		glVertex3f(-5.25f, 99.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 99.0f, -10.2f);
		glVertex3f(-4.25f, 95.0f, -10.2f);
		glVertex3f(-0.5f, 95.0f, -10.2f);
		glVertex3f(-0.5f, 99.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 99.0f, -10.2f);
		glVertex3f(0.5f, 95.0f, -10.2f);
		glVertex3f(4.25f, 95.0f, -10.2f);
		glVertex3f(4.25f, 99.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 99.0f, -10.2f);
		glVertex3f(5.25f, 95.0f, -10.2f);
		glVertex3f(9.0f, 95.0f, -10.2f);
		glVertex3f(9.0f, 99.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 94.0f, -10.2f);
		glVertex3f(-9.0f, 90.0f, -10.2f);
		glVertex3f(-5.25f, 90.0f, -10.2f);
		glVertex3f(-5.25f, 94.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 94.0f, -10.2f);
		glVertex3f(-4.25f, 90.0f, -10.2f);
		glVertex3f(-0.5f, 90.0f, -10.2f);
		glVertex3f(-0.5f, 94.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 94.0f, -10.2f);
		glVertex3f(0.5f, 90.0f, -10.2f);
		glVertex3f(4.25f, 90.0f, -10.2f);
		glVertex3f(4.25f, 94.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 94.0f, -10.2f);
		glVertex3f(5.25f, 90.0f, -10.2f);
		glVertex3f(9.0f, 90.0f, -10.2f);
		glVertex3f(9.0f, 94.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 89.0f, -10.2f);
		glVertex3f(-9.0f, 85.0f, -10.2f);
		glVertex3f(-5.25f, 85.0f, -10.2f);
		glVertex3f(-5.25f, 89.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 89.0f, -10.2f);
		glVertex3f(-4.25f, 85.0f, -10.2f);
		glVertex3f(-0.5f, 85.0f, -10.2f);
		glVertex3f(-0.5f, 89.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 89.0f, -10.2f);
		glVertex3f(0.5f, 85.0f, -10.2f);
		glVertex3f(4.25f, 85.0f, -10.2f);
		glVertex3f(4.25f, 89.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 89.0f, -10.2f);
		glVertex3f(5.25f, 85.0f, -10.2f);
		glVertex3f(9.0f, 85.0f, -10.2f);
		glVertex3f(9.0f, 89.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 84.0f, -10.2f);
		glVertex3f(-9.0f, 80.0f, -10.2f);
		glVertex3f(-5.25f, 80.0f, -10.2f);
		glVertex3f(-5.25f, 84.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 84.0f, -10.2f);
		glVertex3f(-4.25f, 80.0f, -10.2f);
		glVertex3f(-0.5f, 80.0f, -10.2f);
		glVertex3f(-0.5f, 84.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 84.0f, -10.2f);
		glVertex3f(0.5f, 80.0f, -10.2f);
		glVertex3f(4.25f, 80.0f, -10.2f);
		glVertex3f(4.25f, 84.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 84.0f, -10.2f);
		glVertex3f(5.25f, 80.0f, -10.2f);
		glVertex3f(9.0f, 80.0f, -10.2f);
		glVertex3f(9.0f, 84.0f, -10.2f);

		glEnd();

		/*********************************/
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 79.0f, -10.2f);
		glVertex3f(-9.0f, 75.0f, -10.2f);
		glVertex3f(-5.25f, 75.0f, -10.2f);
		glVertex3f(-5.25f, 79.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 79.0f, -10.2f);
		glVertex3f(-4.25f, 75.0f, -10.2f);
		glVertex3f(-0.5f, 75.0f, -10.2f);
		glVertex3f(-0.5f, 79.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 79.0f, -10.2f);
		glVertex3f(0.5f, 75.0f, -10.2f);
		glVertex3f(4.25f, 75.0f, -10.2f);
		glVertex3f(4.25f, 79.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 79.0f, -10.2f);
		glVertex3f(5.25f, 75.0f, -10.2f);
		glVertex3f(9.0f, 75.0f, -10.2f);
		glVertex3f(9.0f, 79.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 74.0f, -10.2f);
		glVertex3f(-9.0f, 70.0f, -10.2f);
		glVertex3f(-5.25f, 70.0f, -10.2f);
		glVertex3f(-5.25f, 74.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 74.0f, -10.2f);
		glVertex3f(-4.25f, 70.0f, -10.2f);
		glVertex3f(-0.5f, 70.0f, -10.2f);
		glVertex3f(-0.5f, 74.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 74.0f, -10.2f);
		glVertex3f(0.5f, 70.0f, -10.2f);
		glVertex3f(4.25f, 70.0f, -10.2f);
		glVertex3f(4.25f, 74.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 74.0f, -10.2f);
		glVertex3f(5.25f, 70.0f, -10.2f);
		glVertex3f(9.0f, 70.0f, -10.2f);
		glVertex3f(9.0f, 74.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 69.0f, -10.2f);
		glVertex3f(-9.0f, 65.0f, -10.2f);
		glVertex3f(-5.25f, 65.0f, -10.2f);
		glVertex3f(-5.25f, 69.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 69.0f, -10.2f);
		glVertex3f(-4.25f, 65.0f, -10.2f);
		glVertex3f(-0.5f, 65.0f, -10.2f);
		glVertex3f(-0.5f, 69.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 69.0f, -10.2f);
		glVertex3f(0.5f, 65.0f, -10.2f);
		glVertex3f(4.25f, 65.0f, -10.2f);
		glVertex3f(4.25f, 69.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 69.0f, -10.2f);
		glVertex3f(5.25f, 65.0f, -10.2f);
		glVertex3f(9.0f, 65.0f, -10.2f);
		glVertex3f(9.0f, 69.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 64.0f, -10.2f);
		glVertex3f(-9.0f, 60.0f, -10.2f);
		glVertex3f(-5.25f, 60.0f, -10.2f);
		glVertex3f(-5.25f, 64.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 64.0f, -10.2f);
		glVertex3f(-4.25f, 60.0f, -10.2f);
		glVertex3f(-0.5f, 60.0f, -10.2f);
		glVertex3f(-0.5f, 64.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 64.0f, -10.2f);
		glVertex3f(0.5f, 60.0f, -10.2f);
		glVertex3f(4.25f, 60.0f, -10.2f);
		glVertex3f(4.25f, 64.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 64.0f, -10.2f);
		glVertex3f(5.25f, 60.0f, -10.2f);
		glVertex3f(9.0f, 60.0f, -10.2f);
		glVertex3f(9.0f, 64.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 59.0f, -10.2f);
		glVertex3f(-9.0f, 55.0f, -10.2f);
		glVertex3f(-5.25f, 55.0f, -10.2f);
		glVertex3f(-5.25f, 59.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 59.0f, -10.2f);
		glVertex3f(-4.25f, 55.0f, -10.2f);
		glVertex3f(-0.5f, 55.0f, -10.2f);
		glVertex3f(-0.5f, 59.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 59.0f, -10.2f);
		glVertex3f(0.5f, 55.0f, -10.2f);
		glVertex3f(4.25f, 55.0f, -10.2f);
		glVertex3f(4.25f, 59.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 59.0f, -10.2f);
		glVertex3f(5.25f, 55.0f, -10.2f);
		glVertex3f(9.0f, 55.0f, -10.2f);
		glVertex3f(9.0f, 59.0f, -10.2f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 54.0f, -10.2f);
		glVertex3f(-9.0f, 50.0f, -10.2f);
		glVertex3f(-5.25f, 50.0f, -10.2f);
		glVertex3f(-5.25f, 54.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 54.0f, -10.2f);
		glVertex3f(-4.25f, 50.0f, -10.2f);
		glVertex3f(-0.5f, 50.0f, -10.2f);
		glVertex3f(-0.5f, 54.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 54.0f, -10.2f);
		glVertex3f(0.5f, 50.0f, -10.2f);
		glVertex3f(4.25f, 50.0f, -10.2f);
		glVertex3f(4.25f, 54.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 54.0f, -10.2f);
		glVertex3f(5.25f, 50.0f, -10.2f);
		glVertex3f(9.0f, 50.0f, -10.2f);
		glVertex3f(9.0f, 54.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 49.0f, -10.2f);
		glVertex3f(-9.0f, 45.0f, -10.2f);
		glVertex3f(-5.25f, 45.0f, -10.2f);
		glVertex3f(-5.25f, 49.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 49.0f, -10.2f);
		glVertex3f(-4.25f, 45.0f, -10.2f);
		glVertex3f(-0.5f, 45.0f, -10.2f);
		glVertex3f(-0.5f, 49.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 49.0f, -10.2f);
		glVertex3f(0.5f, 45.0f, -10.2f);
		glVertex3f(4.25f, 45.0f, -10.2f);
		glVertex3f(4.25f, 49.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 49.0f, -10.2f);
		glVertex3f(5.25f, 45.0f, -10.2f);
		glVertex3f(9.0f, 45.0f, -10.2f);
		glVertex3f(9.0f, 49.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 44.0f, -10.2f);
		glVertex3f(-9.0f, 40.0f, -10.2f);
		glVertex3f(-5.25f, 40.0f, -10.2f);
		glVertex3f(-5.25f, 44.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 44.0f, -10.2f);
		glVertex3f(-4.25f, 40.0f, -10.2f);
		glVertex3f(-0.5f, 40.0f, -10.2f);
		glVertex3f(-0.5f, 44.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 44.0f, -10.2f);
		glVertex3f(0.5f, 40.0f, -10.2f);
		glVertex3f(4.25f, 40.0f, -10.2f);
		glVertex3f(4.25f, 44.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 44.0f, -10.2f);
		glVertex3f(5.25f, 40.0f, -10.2f);
		glVertex3f(9.0f, 40.0f, -10.2f);
		glVertex3f(9.0f, 44.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 39.0f, -10.2f);
		glVertex3f(-9.0f, 35.0f, -10.2f);
		glVertex3f(-5.25f, 35.0f, -10.2f);
		glVertex3f(-5.25f, 39.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 39.0f, -10.2f);
		glVertex3f(-4.25f, 35.0f, -10.2f);
		glVertex3f(-0.5f, 35.0f, -10.2f);
		glVertex3f(-0.5f, 39.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 39.0f, -10.2f);
		glVertex3f(0.5f, 35.0f, -10.2f);
		glVertex3f(4.25f, 35.0f, -10.2f);
		glVertex3f(4.25f, 39.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 39.0f, -10.2f);
		glVertex3f(5.25f, 35.0f, -10.2f);
		glVertex3f(9.0f, 35.0f, -10.2f);
		glVertex3f(9.0f, 39.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 34.0f, -10.2f);
		glVertex3f(-9.0f, 30.0f, -10.2f);
		glVertex3f(-5.25f, 30.0f, -10.2f);
		glVertex3f(-5.25f, 34.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 34.0f, -10.2f);
		glVertex3f(-4.25f, 30.0f, -10.2f);
		glVertex3f(-0.5f, 30.0f, -10.2f);
		glVertex3f(-0.5f, 34.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 34.0f, -10.2f);
		glVertex3f(0.5f, 30.0f, -10.2f);
		glVertex3f(4.25f, 30.0f, -10.2f);
		glVertex3f(4.25f, 34.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 34.0f, -10.2f);
		glVertex3f(5.25f, 30.0f, -10.2f);
		glVertex3f(9.0f, 30.0f, -10.2f);
		glVertex3f(9.0f, 34.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 29.0f, -10.2f);
		glVertex3f(-9.0f, 25.0f, -10.2f);
		glVertex3f(-5.25f, 25.0f, -10.2f);
		glVertex3f(-5.25f, 29.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 29.0f, -10.2f);
		glVertex3f(-4.25f, 25.0f, -10.2f);
		glVertex3f(-0.5f, 25.0f, -10.2f);
		glVertex3f(-0.5f, 29.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 29.0f, -10.2f);
		glVertex3f(0.5f, 25.0f, -10.2f);
		glVertex3f(4.25f, 25.0f, -10.2f);
		glVertex3f(4.25f, 29.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 29.0f, -10.2f);
		glVertex3f(5.25f, 25.0f, -10.2f);
		glVertex3f(9.0f, 25.0f, -10.2f);
		glVertex3f(9.0f, 29.0f, -10.2f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 24.0f, -10.2f);
		glVertex3f(-9.0f, 20.0f, -10.2f);
		glVertex3f(-5.25f, 20.0f, -10.2f);
		glVertex3f(-5.25f, 24.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 24.0f, -10.2f);
		glVertex3f(-4.25f, 20.0f, -10.2f);
		glVertex3f(-0.5f, 20.0f, -10.2f);
		glVertex3f(-0.5f, 24.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 24.0f, -10.2f);
		glVertex3f(0.5f, 20.0f, -10.2f);
		glVertex3f(4.25f, 20.0f, -10.2f);
		glVertex3f(4.25f, 24.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 24.0f, -10.2f);
		glVertex3f(5.25f, 20.0f, -10.2f);
		glVertex3f(9.0f, 20.0f, -10.2f);
		glVertex3f(9.0f, 24.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 19.0f, -10.2f);
		glVertex3f(-9.0f, 15.0f, -10.2f);
		glVertex3f(-5.25f, 15.0f, -10.2f);
		glVertex3f(-5.25f, 19.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 19.0f, -10.2f);
		glVertex3f(-4.25f, 15.0f, -10.2f);
		glVertex3f(-0.5f, 15.0f, -10.2f);
		glVertex3f(-0.5f, 19.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 19.0f, -10.2f);
		glVertex3f(0.5f, 15.0f, -10.2f);
		glVertex3f(4.25f, 15.0f, -10.2f);
		glVertex3f(4.25f, 19.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 19.0f, -10.2f);
		glVertex3f(5.25f, 15.0f, -10.2f);
		glVertex3f(9.0f, 15.0f, -10.2f);
		glVertex3f(9.0f, 19.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 14.0f, -10.2f);
		glVertex3f(-9.0f, 10.0f, -10.2f);
		glVertex3f(-5.25f, 10.0f, -10.2f);
		glVertex3f(-5.25f, 14.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 14.0f, -10.2f);
		glVertex3f(-4.25f, 10.0f, -10.2f);
		glVertex3f(-0.5f, 10.0f, -10.2f);
		glVertex3f(-0.5f, 14.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 14.0f, -10.2f);
		glVertex3f(0.5f, 10.0f, -10.2f);
		glVertex3f(4.25f, 10.0f, -10.2f);
		glVertex3f(4.25f, 14.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 14.0f, -10.2f);
		glVertex3f(5.25f, 10.0f, -10.2f);
		glVertex3f(9.0f, 10.0f, -10.2f);
		glVertex3f(9.0f, 14.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 9.0f, -10.2f);
		glVertex3f(-9.0f, 5.0f, -10.2f);
		glVertex3f(-5.25f, 5.0f, -10.2f);
		glVertex3f(-5.25f, 9.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 9.0f, -10.2f);
		glVertex3f(-4.25f, 5.0f, -10.2f);
		glVertex3f(-0.5f, 5.0f, -10.2f);
		glVertex3f(-0.5f, 9.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 9.0f, -10.2f);
		glVertex3f(0.5f, 5.0f, -10.2f);
		glVertex3f(4.25f, 5.0f, -10.2f);
		glVertex3f(4.25f, 9.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 9.0f, -10.2f);
		glVertex3f(5.25f, 5.0f, -10.2f);
		glVertex3f(9.0f, 5.0f, -10.2f);
		glVertex3f(9.0f, 9.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 4.0f, -10.2f);
		glVertex3f(-9.0f, 1.0f, -10.2f);
		glVertex3f(-5.25f, 1.0f, -10.2f);
		glVertex3f(-5.25f, 4.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 4.0f, -10.2f);
		glVertex3f(-4.25f, 1.0f, -10.2f);
		glVertex3f(-0.5f, 1.0f, -10.2f);
		glVertex3f(-0.5f, 4.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 4.0f, -10.2f);
		glVertex3f(0.5f, 1.0f, -10.2f);
		glVertex3f(4.25f, 1.0f, -10.2f);
		glVertex3f(4.25f, 4.0f, -10.2f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 4.0f, -10.2f);
		glVertex3f(5.25f, 1.0f, -10.2f);
		glVertex3f(9.0f, 1.0f, -10.2f);
		glVertex3f(9.0f, 4.0f, -10.2f);

		glEnd();
		/***********************************************************/
		/*********************************/
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 149.0f, 19.9f);
		glVertex3f(21.0f, 145.0f, 19.9f);
		glVertex3f(24.25f, 145.0f, 19.9f);
		glVertex3f(24.25f, 149.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 149.0f, 19.9f);
		glVertex3f(25.25f, 145.0f, 19.9f);
		glVertex3f(29.5f, 145.0f, 19.9f);
		glVertex3f(29.5f, 149.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 149.0f, 19.9f);
		glVertex3f(30.5f, 145.0f, 19.9f);
		glVertex3f(34.25f, 145.0f, 19.9f);
		glVertex3f(34.25f, 149.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 149.0f, 19.9f);
		glVertex3f(35.25f, 145.0f, 19.9f);
		glVertex3f(39.0f, 145.0f, 19.9f);
		glVertex3f(39.0f, 149.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 144.0f, 19.9f);
		glVertex3f(21.0f, 140.0f, 19.9f);
		glVertex3f(24.25f, 140.0f, 19.9f);
		glVertex3f(24.25f, 144.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 144.0f, 19.9f);
		glVertex3f(25.25f, 140.0f, 19.9f);
		glVertex3f(29.5f, 140.0f, 19.9f);
		glVertex3f(29.5f, 144.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 144.0f, 19.9f);
		glVertex3f(30.5f, 140.0f, 19.9f);
		glVertex3f(34.25f, 140.0f, 19.9f);
		glVertex3f(34.25f, 144.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 144.0f, 19.9f);
		glVertex3f(35.25f, 140.0f, 19.9f);
		glVertex3f(39.0f, 140.0f, 19.9f);
		glVertex3f(39.0f, 144.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 139.0f, 19.9f);
		glVertex3f(21.0f, 135.0f, 19.9f);
		glVertex3f(24.25f, 135.0f, 19.9f);
		glVertex3f(24.25f, 139.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 139.0f, 19.9f);
		glVertex3f(25.25f, 135.0f, 19.9f);
		glVertex3f(29.5f, 135.0f, 19.9f);
		glVertex3f(29.5f, 139.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 139.0f, 19.9f);
		glVertex3f(30.5f, 135.0f, 19.9f);
		glVertex3f(34.25f, 135.0f, 19.9f);
		glVertex3f(34.25f, 139.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 139.0f, 19.9f);
		glVertex3f(35.25f, 135.0f, 19.9f);
		glVertex3f(39.0f, 135.0f, 19.9f);
		glVertex3f(39.0f, 139.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 134.0f, 19.9f);
		glVertex3f(21.0f, 130.0f, 19.9f);
		glVertex3f(24.25f, 130.0f, 19.9f);
		glVertex3f(24.25f, 134.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 134.0f, 19.9f);
		glVertex3f(25.25f, 130.0f, 19.9f);
		glVertex3f(29.5f, 130.0f, 19.9f);
		glVertex3f(29.5f, 134.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 134.0f, 19.9f);
		glVertex3f(30.5f, 130.0f, 19.9f);
		glVertex3f(34.25f, 130.0f, 19.9f);
		glVertex3f(34.25f, 134.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 134.0f, 19.9f);
		glVertex3f(35.25f, 130.0f, 19.9f);
		glVertex3f(39.0f, 130.0f, 19.9f);
		glVertex3f(39.0f, 134.0f, 19.9f);

		glEnd();

		/*****************************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 129.0f, 19.9f);
		glVertex3f(21.0f, 125.0f, 19.9f);
		glVertex3f(24.25f, 125.0f, 19.9f);
		glVertex3f(24.25f, 129.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 129.0f, 19.9f);
		glVertex3f(25.25f, 125.0f, 19.9f);
		glVertex3f(29.5f, 125.0f, 19.9f);
		glVertex3f(29.5f, 129.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 129.0f, 19.9f);
		glVertex3f(30.5f, 125.0f, 19.9f);
		glVertex3f(34.25f, 125.0f, 19.9f);
		glVertex3f(34.25f, 129.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 129.0f, 19.9f);
		glVertex3f(35.25f, 125.0f, 19.9f);
		glVertex3f(39.0f, 125.0f, 19.9f);
		glVertex3f(39.0f, 129.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 124.0f, 19.9f);
		glVertex3f(21.0f, 120.0f, 19.9f);
		glVertex3f(24.25f, 120.0f, 19.9f);
		glVertex3f(24.25f, 124.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 124.0f, 19.9f);
		glVertex3f(25.25f, 120.0f, 19.9f);
		glVertex3f(29.5f, 120.0f, 19.9f);
		glVertex3f(29.5f, 124.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 124.0f, 19.9f);
		glVertex3f(30.5f, 120.0f, 19.9f);
		glVertex3f(34.25f, 120.0f, 19.9f);
		glVertex3f(34.25f, 124.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 124.0f, 19.9f);
		glVertex3f(35.25f, 120.0f, 19.9f);
		glVertex3f(39.0f, 120.0f, 19.9f);
		glVertex3f(39.0f, 124.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 119.0f, 19.9f);
		glVertex3f(21.0f, 115.0f, 19.9f);
		glVertex3f(24.25f, 115.0f, 19.9f);
		glVertex3f(24.25f, 119.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 119.0f, 19.9f);
		glVertex3f(25.25f, 115.0f, 19.9f);
		glVertex3f(29.5f, 115.0f, 19.9f);
		glVertex3f(29.5f, 119.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 119.0f, 19.9f);
		glVertex3f(30.5f, 115.0f, 19.9f);
		glVertex3f(34.25f, 115.0f, 19.9f);
		glVertex3f(34.25f, 119.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 119.0f, 19.9f);
		glVertex3f(35.25f, 115.0f, 19.9f);
		glVertex3f(39.0f, 115.0f, 19.9f);
		glVertex3f(39.0f, 119.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 114.0f, 19.9f);
		glVertex3f(21.0f, 110.0f, 19.9f);
		glVertex3f(24.25f, 110.0f, 19.9f);
		glVertex3f(24.25f, 114.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 114.0f, 19.9f);
		glVertex3f(25.25f, 110.0f, 19.9f);
		glVertex3f(29.5f, 110.0f, 19.9f);
		glVertex3f(29.5f, 114.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 114.0f, 19.9f);
		glVertex3f(30.5f, 110.0f, 19.9f);
		glVertex3f(34.25f, 110.0f, 19.9f);
		glVertex3f(34.25f, 114.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 114.0f, 19.9f);
		glVertex3f(35.25f, 110.0f, 19.9f);
		glVertex3f(39.0f, 110.0f, 19.9f);
		glVertex3f(39.0f, 114.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 109.0f, 19.9f);
		glVertex3f(21.0f, 105.0f, 19.9f);
		glVertex3f(24.25f, 105.0f, 19.9f);
		glVertex3f(24.25f, 109.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 109.0f, 19.9f);
		glVertex3f(25.25f, 105.0f, 19.9f);
		glVertex3f(29.5f, 105.0f, 19.9f);
		glVertex3f(29.5f, 109.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 109.0f, 19.9f);
		glVertex3f(30.5f, 105.0f, 19.9f);
		glVertex3f(34.25f, 105.0f, 19.9f);
		glVertex3f(34.25f, 109.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 109.0f, 19.9f);
		glVertex3f(35.25f, 105.0f, 19.9f);
		glVertex3f(39.0f, 105.0f, 19.9f);
		glVertex3f(39.0f, 109.0f, 19.9f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 104.0f, 19.9f);
		glVertex3f(21.0f, 100.0f, 19.9f);
		glVertex3f(24.25f, 100.0f, 19.9f);
		glVertex3f(24.25f, 104.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 104.0f, 19.9f);
		glVertex3f(25.25f, 100.0f, 19.9f);
		glVertex3f(29.5f, 100.0f, 19.9f);
		glVertex3f(29.5f, 104.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 104.0f, 19.9f);
		glVertex3f(30.5f, 100.0f, 19.9f);
		glVertex3f(34.25f, 100.0f, 19.9f);
		glVertex3f(34.25f, 104.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 104.0f, 19.9f);
		glVertex3f(35.25f, 100.0f, 19.9f);
		glVertex3f(39.0f, 100.0f, 19.9f);
		glVertex3f(39.0f, 104.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 99.0f, 19.9f);
		glVertex3f(21.0f, 95.0f, 19.9f);
		glVertex3f(24.25f, 95.0f, 19.9f);
		glVertex3f(24.25f, 99.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 99.0f, 19.9f);
		glVertex3f(25.25f, 95.0f, 19.9f);
		glVertex3f(29.5f, 95.0f, 19.9f);
		glVertex3f(29.5f, 99.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 99.0f, 19.9f);
		glVertex3f(30.5f, 95.0f, 19.9f);
		glVertex3f(34.25f, 95.0f, 19.9f);
		glVertex3f(34.25f, 99.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 99.0f, 19.9f);
		glVertex3f(35.25f, 95.0f, 19.9f);
		glVertex3f(39.0f, 95.0f, 19.9f);
		glVertex3f(39.0f, 99.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 94.0f, 19.9f);
		glVertex3f(21.0f, 90.0f, 19.9f);
		glVertex3f(24.25f, 90.0f, 19.9f);
		glVertex3f(24.25f, 94.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 94.0f, 19.9f);
		glVertex3f(25.25f, 90.0f, 19.9f);
		glVertex3f(29.5f, 90.0f, 19.9f);
		glVertex3f(29.5f, 94.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 94.0f, 19.9f);
		glVertex3f(30.5f, 90.0f, 19.9f);
		glVertex3f(34.25f, 90.0f, 19.9f);
		glVertex3f(34.25f, 94.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 94.0f, 19.9f);
		glVertex3f(35.25f, 90.0f, 19.9f);
		glVertex3f(39.0f, 90.0f, 19.9f);
		glVertex3f(39.0f, 94.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 89.0f, 19.9f);
		glVertex3f(21.0f, 85.0f, 19.9f);
		glVertex3f(24.25f, 85.0f, 19.9f);
		glVertex3f(24.25f, 89.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 89.0f, 19.9f);
		glVertex3f(25.25f, 85.0f, 19.9f);
		glVertex3f(29.5f, 85.0f, 19.9f);
		glVertex3f(29.5f, 89.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 89.0f, 19.9f);
		glVertex3f(30.5f, 85.0f, 19.9f);
		glVertex3f(34.25f, 85.0f, 19.9f);
		glVertex3f(34.25f, 89.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 89.0f, 19.9f);
		glVertex3f(35.25f, 85.0f, 19.9f);
		glVertex3f(39.0f, 85.0f, 19.9f);
		glVertex3f(39.0f, 89.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 84.0f, 19.9f);
		glVertex3f(21.0f, 80.0f, 19.9f);
		glVertex3f(24.25f, 80.0f, 19.9f);
		glVertex3f(24.25f, 84.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 84.0f, 19.9f);
		glVertex3f(25.25f, 80.0f, 19.9f);
		glVertex3f(29.5f, 80.0f, 19.9f);
		glVertex3f(29.5f, 84.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 84.0f, 19.9f);
		glVertex3f(30.5f, 80.0f, 19.9f);
		glVertex3f(34.25f, 80.0f, 19.9f);
		glVertex3f(34.25f, 84.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 84.0f, 19.9f);
		glVertex3f(35.25f, 80.0f, 19.9f);
		glVertex3f(39.0f, 80.0f, 19.9f);
		glVertex3f(39.0f, 84.0f, 19.9f);

		glEnd();

		/*********************************/
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 79.0f, 19.9f);
		glVertex3f(21.0f, 75.0f, 19.9f);
		glVertex3f(24.25f, 75.0f, 19.9f);
		glVertex3f(24.25f, 79.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 79.0f, 19.9f);
		glVertex3f(25.25f, 75.0f, 19.9f);
		glVertex3f(29.5f, 75.0f, 19.9f);
		glVertex3f(29.5f, 79.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 79.0f, 19.9f);
		glVertex3f(30.5f, 75.0f, 19.9f);
		glVertex3f(34.25f, 75.0f, 19.9f);
		glVertex3f(34.25f, 79.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 79.0f, 19.9f);
		glVertex3f(35.25f, 75.0f, 19.9f);
		glVertex3f(39.0f, 75.0f, 19.9f);
		glVertex3f(39.0f, 79.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 74.0f, 19.9f);
		glVertex3f(21.0f, 70.0f, 19.9f);
		glVertex3f(24.25f, 70.0f, 19.9f);
		glVertex3f(24.25f, 74.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 74.0f, 19.9f);
		glVertex3f(25.25f, 70.0f, 19.9f);
		glVertex3f(29.5f, 70.0f, 19.9f);
		glVertex3f(29.5f, 74.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 74.0f, 19.9f);
		glVertex3f(30.5f, 70.0f, 19.9f);
		glVertex3f(34.25f, 70.0f, 19.9f);
		glVertex3f(34.25f, 74.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 74.0f, 19.9f);
		glVertex3f(35.25f, 70.0f, 19.9f);
		glVertex3f(39.0f, 70.0f, 19.9f);
		glVertex3f(39.0f, 74.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 69.0f, 19.9f);
		glVertex3f(21.0f, 65.0f, 19.9f);
		glVertex3f(24.25f, 65.0f, 19.9f);
		glVertex3f(24.25f, 69.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 69.0f, 19.9f);
		glVertex3f(25.25f, 65.0f, 19.9f);
		glVertex3f(29.5f, 65.0f, 19.9f);
		glVertex3f(29.5f, 69.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 69.0f, 19.9f);
		glVertex3f(30.5f, 65.0f, 19.9f);
		glVertex3f(34.25f, 65.0f, 19.9f);
		glVertex3f(34.25f, 69.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 69.0f, 19.9f);
		glVertex3f(35.25f, 65.0f, 19.9f);
		glVertex3f(39.0f, 65.0f, 19.9f);
		glVertex3f(39.0f, 69.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 64.0f, 19.9f);
		glVertex3f(21.0f, 60.0f, 19.9f);
		glVertex3f(24.25f, 60.0f, 19.9f);
		glVertex3f(24.25f, 64.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 64.0f, 19.9f);
		glVertex3f(25.25f, 60.0f, 19.9f);
		glVertex3f(29.5f, 60.0f, 19.9f);
		glVertex3f(29.5f, 64.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 64.0f, 19.9f);
		glVertex3f(30.5f, 60.0f, 19.9f);
		glVertex3f(34.25f, 60.0f, 19.9f);
		glVertex3f(34.25f, 64.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 64.0f, 19.9f);
		glVertex3f(35.25f, 60.0f, 19.9f);
		glVertex3f(39.0f, 60.0f, 19.9f);
		glVertex3f(39.0f, 64.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 59.0f, 19.9f);
		glVertex3f(21.0f, 55.0f, 19.9f);
		glVertex3f(24.25f, 55.0f, 19.9f);
		glVertex3f(24.25f, 59.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 59.0f, 19.9f);
		glVertex3f(25.25f, 55.0f, 19.9f);
		glVertex3f(29.5f, 55.0f, 19.9f);
		glVertex3f(29.5f, 59.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 59.0f, 19.9f);
		glVertex3f(30.5f, 55.0f, 19.9f);
		glVertex3f(34.25f, 55.0f, 19.9f);
		glVertex3f(34.25f, 59.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 59.0f, 19.9f);
		glVertex3f(35.25f, 55.0f, 19.9f);
		glVertex3f(39.0f, 55.0f, 19.9f);
		glVertex3f(39.0f, 59.0f, 19.9f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 54.0f, 19.9f);
		glVertex3f(21.0f, 50.0f, 19.9f);
		glVertex3f(24.25f, 50.0f, 19.9f);
		glVertex3f(24.25f, 54.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 54.0f, 19.9f);
		glVertex3f(25.25f, 50.0f, 19.9f);
		glVertex3f(29.5f, 50.0f, 19.9f);
		glVertex3f(29.5f, 54.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 54.0f, 19.9f);
		glVertex3f(30.5f, 50.0f, 19.9f);
		glVertex3f(34.25f, 50.0f, 19.9f);
		glVertex3f(34.25f, 54.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 54.0f, 19.9f);
		glVertex3f(35.25f, 50.0f, 19.9f);
		glVertex3f(39.0f, 50.0f, 19.9f);
		glVertex3f(39.0f, 54.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 49.0f, 9.9f);
		glVertex3f(21.0f, 45.0f, 9.9f);
		glVertex3f(24.25f, 45.0f, 9.9f);
		glVertex3f(24.25f, 49.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 49.0f, 9.9f);
		glVertex3f(25.25f, 45.0f, 9.9f);
		glVertex3f(29.5f, 45.0f, 9.9f);
		glVertex3f(29.5f, 49.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 49.0f, 9.9f);
		glVertex3f(30.5f, 45.0f, 9.9f);
		glVertex3f(34.25f, 45.0f, 9.9f);
		glVertex3f(34.25f, 49.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 49.0f, 9.9f);
		glVertex3f(35.25f, 45.0f, 9.9f);
		glVertex3f(39.0f, 45.0f, 9.9f);
		glVertex3f(39.0f, 49.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 44.0f, 9.9f);
		glVertex3f(21.0f, 40.0f, 9.9f);
		glVertex3f(24.25f, 40.0f, 9.9f);
		glVertex3f(24.25f, 44.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 44.0f, 9.9f);
		glVertex3f(25.25f, 40.0f, 9.9f);
		glVertex3f(29.5f, 40.0f, 9.9f);
		glVertex3f(29.5f, 44.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 44.0f, 9.9f);
		glVertex3f(30.5f, 40.0f, 9.9f);
		glVertex3f(34.25f, 40.0f, 9.9f);
		glVertex3f(34.25f, 44.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 44.0f, 9.9f);
		glVertex3f(35.25f, 40.0f, 9.9f);
		glVertex3f(39.0f, 40.0f, 9.9f);
		glVertex3f(39.0f, 44.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 39.0f, 9.9f);
		glVertex3f(21.0f, 35.0f, 9.9f);
		glVertex3f(24.25f, 35.0f, 9.9f);
		glVertex3f(24.25f, 39.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 39.0f, 9.9f);
		glVertex3f(25.25f, 35.0f, 9.9f);
		glVertex3f(29.5f, 35.0f, 9.9f);
		glVertex3f(29.5f, 39.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 39.0f, 9.9f);
		glVertex3f(30.5f, 35.0f, 9.9f);
		glVertex3f(34.25f, 35.0f, 9.9f);
		glVertex3f(34.25f, 39.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 39.0f, 9.9f);
		glVertex3f(35.25f, 35.0f, 9.9f);
		glVertex3f(39.0f, 35.0f, 9.9f);
		glVertex3f(39.0f, 39.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 34.0f, 9.9f);
		glVertex3f(21.0f, 30.0f, 9.9f);
		glVertex3f(24.25f, 30.0f, 9.9f);
		glVertex3f(24.25f, 34.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 34.0f, 9.9f);
		glVertex3f(25.25f, 30.0f, 9.9f);
		glVertex3f(29.5f, 30.0f, 9.9f);
		glVertex3f(29.5f, 34.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 34.0f, 9.9f);
		glVertex3f(30.5f, 30.0f, 9.9f);
		glVertex3f(34.25f, 30.0f, 9.9f);
		glVertex3f(34.25f, 34.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 34.0f, 9.9f);
		glVertex3f(35.25f, 30.0f, 9.9f);
		glVertex3f(39.0f, 30.0f, 9.9f);
		glVertex3f(39.0f, 34.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 29.0f, 19.9f);
		glVertex3f(21.0f, 25.0f, 19.9f);
		glVertex3f(24.25f, 25.0f, 19.9f);
		glVertex3f(24.25f, 29.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 29.0f, 19.9f);
		glVertex3f(25.25f, 25.0f, 19.9f);
		glVertex3f(29.5f, 25.0f, 19.9f);
		glVertex3f(29.5f, 29.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 29.0f, 19.9f);
		glVertex3f(30.5f, 25.0f, 19.9f);
		glVertex3f(34.25f, 25.0f, 19.9f);
		glVertex3f(34.25f, 29.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 29.0f, 19.9f);
		glVertex3f(35.25f, 25.0f, 19.9f);
		glVertex3f(39.0f, 25.0f, 19.9f);
		glVertex3f(39.0f, 29.0f, 19.9f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 24.0f, 19.9f);
		glVertex3f(21.0f, 20.0f, 19.9f);
		glVertex3f(24.25f, 20.0f, 19.9f);
		glVertex3f(24.25f, 24.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 24.0f, 19.9f);
		glVertex3f(25.25f, 20.0f, 19.9f);
		glVertex3f(29.5f, 20.0f, 19.9f);
		glVertex3f(29.5f, 24.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 24.0f, 19.9f);
		glVertex3f(30.5f, 20.0f, 19.9f);
		glVertex3f(34.25f, 20.0f, 19.9f);
		glVertex3f(34.25f, 24.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 24.0f, 19.9f);
		glVertex3f(35.25f, 20.0f, 19.9f);
		glVertex3f(39.0f, 20.0f, 19.9f);
		glVertex3f(39.0f, 24.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 19.0f, 19.9f);
		glVertex3f(21.0f, 15.0f, 19.9f);
		glVertex3f(24.25f, 15.0f, 19.9f);
		glVertex3f(24.25f, 19.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 19.0f, 19.9f);
		glVertex3f(25.25f, 15.0f, 19.9f);
		glVertex3f(29.5f, 15.0f, 19.9f);
		glVertex3f(29.5f, 19.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 19.0f, 19.9f);
		glVertex3f(30.5f, 15.0f, 19.9f);
		glVertex3f(34.25f, 15.0f, 19.9f);
		glVertex3f(34.25f, 19.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 19.0f, 19.9f);
		glVertex3f(35.25f, 15.0f, 19.9f);
		glVertex3f(39.0f, 15.0f, 19.9f);
		glVertex3f(39.0f, 19.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 14.0f, 19.9f);
		glVertex3f(21.0f, 10.0f, 19.9f);
		glVertex3f(24.25f, 10.0f, 19.9f);
		glVertex3f(24.25f, 14.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 14.0f, 19.9f);
		glVertex3f(25.25f, 10.0f, 19.9f);
		glVertex3f(29.5f, 10.0f, 19.9f);
		glVertex3f(29.5f, 14.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 14.0f, 19.9f);
		glVertex3f(30.5f, 10.0f, 19.9f);
		glVertex3f(34.25f, 10.0f, 19.9f);
		glVertex3f(34.25f, 14.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 14.0f, 19.9f);
		glVertex3f(35.25f, 10.0f, 19.9f);
		glVertex3f(39.0f, 10.0f, 19.9f);
		glVertex3f(39.0f, 14.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 9.0f, 19.9f);
		glVertex3f(21.0f, 5.0f, 19.9f);
		glVertex3f(24.25f, 5.0f, 19.9f);
		glVertex3f(24.25f, 9.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 9.0f, 19.9f);
		glVertex3f(25.25f, 5.0f, 19.9f);
		glVertex3f(29.5f, 5.0f, 19.9f);
		glVertex3f(29.5f, 9.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 9.0f, 19.9f);
		glVertex3f(30.5f, 5.0f, 19.9f);
		glVertex3f(34.25f, 5.0f, 19.9f);
		glVertex3f(34.25f, 9.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 9.0f, 19.9f);
		glVertex3f(35.25f, 5.0f, 19.9f);
		glVertex3f(39.0f, 5.0f, 19.9f);
		glVertex3f(39.0f, 9.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 4.0f, 19.9f);
		glVertex3f(21.0f, 1.0f, 19.9f);
		glVertex3f(24.25f, 1.0f, 19.9f);
		glVertex3f(24.25f, 4.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 4.0f, 19.9f);
		glVertex3f(25.25f, 1.0f, 19.9f);
		glVertex3f(29.5f, 1.0f, 19.9f);
		glVertex3f(29.5f, 4.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 4.0f, 19.9f);
		glVertex3f(30.5f, 1.0f, 19.9f);
		glVertex3f(34.25f, 1.0f, 19.9f);
		glVertex3f(34.25f, 4.0f, 19.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 4.0f, 19.9f);
		glVertex3f(35.25f, 1.0f, 19.9f);
		glVertex3f(39.0f, 1.0f, 19.9f);
		glVertex3f(39.0f, 4.0f, 19.9f);

		glEnd();

		/**************************
		 * *********************
		 * **********************
		 * *********************
		 * ***********************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 129.0f, 10.1f);
		glVertex3f(-9.0f, 125.0f, 10.1f);
		glVertex3f(-5.25f, 125.0f, 10.1f);
		glVertex3f(-5.25f, 129.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 129.0f, 10.1f);
		glVertex3f(-4.25f, 125.0f, 10.1f);
		glVertex3f(-0.5f, 125.0f, 10.1f);
		glVertex3f(-0.5f, 129.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 129.0f, 10.1f);
		glVertex3f(0.5f, 125.0f, 10.1f);
		glVertex3f(4.25f, 125.0f, 10.1f);
		glVertex3f(4.25f, 129.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 129.0f, 10.1f);
		glVertex3f(5.25f, 125.0f, 10.1f);
		glVertex3f(9.0f, 125.0f, 10.1f);
		glVertex3f(9.0f, 129.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 124.0f, 10.1f);
		glVertex3f(-9.0f, 120.0f, 10.1f);
		glVertex3f(-5.25f, 120.0f, 10.1f);
		glVertex3f(-5.25f, 124.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 124.0f, 10.1f);
		glVertex3f(-4.25f, 120.0f, 10.1f);
		glVertex3f(-0.5f, 120.0f, 10.1f);
		glVertex3f(-0.5f, 124.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 124.0f, 10.1f);
		glVertex3f(0.5f, 120.0f, 10.1f);
		glVertex3f(4.25f, 120.0f, 10.1f);
		glVertex3f(4.25f, 124.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 124.0f, 10.1f);
		glVertex3f(5.25f, 120.0f, 10.1f);
		glVertex3f(9.0f, 120.0f, 10.1f);
		glVertex3f(9.0f, 124.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 119.0f, 10.1f);
		glVertex3f(-9.0f, 115.0f, 10.1f);
		glVertex3f(-5.25f, 115.0f, 10.1f);
		glVertex3f(-5.25f, 119.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 119.0f, 10.1f);
		glVertex3f(-4.25f, 115.0f, 10.1f);
		glVertex3f(-0.5f, 115.0f, 10.1f);
		glVertex3f(-0.5f, 119.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 119.0f, 10.1f);
		glVertex3f(0.5f, 115.0f, 10.1f);
		glVertex3f(4.25f, 115.0f, 10.1f);
		glVertex3f(4.25f, 119.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 119.0f, 10.1f);
		glVertex3f(5.25f, 115.0f, 10.1f);
		glVertex3f(9.0f, 115.0f, 10.1f);
		glVertex3f(9.0f, 119.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 114.0f, 10.1f);
		glVertex3f(-9.0f, 110.0f, 10.1f);
		glVertex3f(-5.25f, 110.0f, 10.1f);
		glVertex3f(-5.25f, 114.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 114.0f, 10.1f);
		glVertex3f(-4.25f, 110.0f, 10.1f);
		glVertex3f(-0.5f, 110.0f, 10.1f);
		glVertex3f(-0.5f, 114.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 114.0f, 10.1f);
		glVertex3f(0.5f, 110.0f, 10.1f);
		glVertex3f(4.25f, 110.0f, 10.1f);
		glVertex3f(4.25f, 114.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 114.0f, 10.1f);
		glVertex3f(5.25f, 110.0f, 10.1f);
		glVertex3f(9.0f, 110.0f, 10.1f);
		glVertex3f(9.0f, 114.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 109.0f, 10.1f);
		glVertex3f(-9.0f, 105.0f, 10.1f);
		glVertex3f(-5.25f, 105.0f, 10.1f);
		glVertex3f(-5.25f, 109.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 109.0f, 10.1f);
		glVertex3f(-4.25f, 105.0f, 10.1f);
		glVertex3f(-0.5f, 105.0f, 10.1f);
		glVertex3f(-0.5f, 109.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 109.0f, 10.1f);
		glVertex3f(0.5f, 105.0f, 10.1f);
		glVertex3f(4.25f, 105.0f, 10.1f);
		glVertex3f(4.25f, 109.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 109.0f, 10.1f);
		glVertex3f(5.25f, 105.0f, 10.1f);
		glVertex3f(9.0f, 105.0f, 10.1f);
		glVertex3f(9.0f, 109.0f, 10.1f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 104.0f, 10.1f);
		glVertex3f(-9.0f, 100.0f, 10.1f);
		glVertex3f(-5.25f, 100.0f, 10.1f);
		glVertex3f(-5.25f, 104.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 104.0f, 10.1f);
		glVertex3f(-4.25f, 100.0f, 10.1f);
		glVertex3f(-0.5f, 100.0f, 10.1f);
		glVertex3f(-0.5f, 104.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 104.0f, 10.1f);
		glVertex3f(0.5f, 100.0f, 10.1f);
		glVertex3f(4.25f, 100.0f, 10.1f);
		glVertex3f(4.25f, 104.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 104.0f, 10.1f);
		glVertex3f(5.25f, 100.0f, 10.1f);
		glVertex3f(9.0f, 100.0f, 10.1f);
		glVertex3f(9.0f, 104.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 99.0f, 10.1f);
		glVertex3f(-9.0f, 95.0f, 10.1f);
		glVertex3f(-5.25f, 95.0f, 10.1f);
		glVertex3f(-5.25f, 99.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 99.0f, 10.1f);
		glVertex3f(-4.25f, 95.0f, 10.1f);
		glVertex3f(-0.5f, 95.0f, 10.1f);
		glVertex3f(-0.5f, 99.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 99.0f, 10.1f);
		glVertex3f(0.5f, 95.0f, 10.1f);
		glVertex3f(4.25f, 95.0f, 10.1f);
		glVertex3f(4.25f, 99.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 99.0f, 10.1f);
		glVertex3f(5.25f, 95.0f, 10.1f);
		glVertex3f(9.0f, 95.0f, 10.1f);
		glVertex3f(9.0f, 99.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 94.0f, 10.1f);
		glVertex3f(-9.0f, 90.0f, 10.1f);
		glVertex3f(-5.25f, 90.0f, 10.1f);
		glVertex3f(-5.25f, 94.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 94.0f, 10.1f);
		glVertex3f(-4.25f, 90.0f, 10.1f);
		glVertex3f(-0.5f, 90.0f, 10.1f);
		glVertex3f(-0.5f, 94.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 94.0f, 10.1f);
		glVertex3f(0.5f, 90.0f, 10.1f);
		glVertex3f(4.25f, 90.0f, 10.1f);
		glVertex3f(4.25f, 94.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 94.0f, 10.1f);
		glVertex3f(5.25f, 90.0f, 10.1f);
		glVertex3f(9.0f, 90.0f, 10.1f);
		glVertex3f(9.0f, 94.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 89.0f, 10.1f);
		glVertex3f(-9.0f, 85.0f, 10.1f);
		glVertex3f(-5.25f, 85.0f, 10.1f);
		glVertex3f(-5.25f, 89.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 89.0f, 10.1f);
		glVertex3f(-4.25f, 85.0f, 10.1f);
		glVertex3f(-0.5f, 85.0f, 10.1f);
		glVertex3f(-0.5f, 89.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 89.0f, 10.1f);
		glVertex3f(0.5f, 85.0f, 10.1f);
		glVertex3f(4.25f, 85.0f, 10.1f);
		glVertex3f(4.25f, 89.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 89.0f, 10.1f);
		glVertex3f(5.25f, 85.0f, 10.1f);
		glVertex3f(9.0f, 85.0f, 10.1f);
		glVertex3f(9.0f, 89.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 84.0f, 10.1f);
		glVertex3f(-9.0f, 80.0f, 10.1f);
		glVertex3f(-5.25f, 80.0f, 10.1f);
		glVertex3f(-5.25f, 84.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 84.0f, 10.1f);
		glVertex3f(-4.25f, 80.0f, 10.1f);
		glVertex3f(-0.5f, 80.0f, 10.1f);
		glVertex3f(-0.5f, 84.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 84.0f, 10.1f);
		glVertex3f(0.5f, 80.0f, 10.1f);
		glVertex3f(4.25f, 80.0f, 10.1f);
		glVertex3f(4.25f, 84.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 84.0f, 10.1f);
		glVertex3f(5.25f, 80.0f, 10.1f);
		glVertex3f(9.0f, 80.0f, 10.1f);
		glVertex3f(9.0f, 84.0f, 10.1f);

		glEnd();

		/*********************************/
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 79.0f, 10.1f);
		glVertex3f(-9.0f, 75.0f, 10.1f);
		glVertex3f(-5.25f, 75.0f, 10.1f);
		glVertex3f(-5.25f, 79.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 79.0f, 10.1f);
		glVertex3f(-4.25f, 75.0f, 10.1f);
		glVertex3f(-0.5f, 75.0f, 10.1f);
		glVertex3f(-0.5f, 79.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 79.0f, 10.1f);
		glVertex3f(0.5f, 75.0f, 10.1f);
		glVertex3f(4.25f, 75.0f, 10.1f);
		glVertex3f(4.25f, 79.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 79.0f, 10.1f);
		glVertex3f(5.25f, 75.0f, 10.1f);
		glVertex3f(9.0f, 75.0f, 10.1f);
		glVertex3f(9.0f, 79.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 74.0f, 10.1f);
		glVertex3f(-9.0f, 70.0f, 10.1f);
		glVertex3f(-5.25f, 70.0f, 10.1f);
		glVertex3f(-5.25f, 74.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 74.0f, 10.1f);
		glVertex3f(-4.25f, 70.0f, 10.1f);
		glVertex3f(-0.5f, 70.0f, 10.1f);
		glVertex3f(-0.5f, 74.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 74.0f, 10.1f);
		glVertex3f(0.5f, 70.0f, 10.1f);
		glVertex3f(4.25f, 70.0f, 10.1f);
		glVertex3f(4.25f, 74.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 74.0f, 10.1f);
		glVertex3f(5.25f, 70.0f, 10.1f);
		glVertex3f(9.0f, 70.0f, 10.1f);
		glVertex3f(9.0f, 74.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 69.0f, 10.1f);
		glVertex3f(-9.0f, 65.0f, 10.1f);
		glVertex3f(-5.25f, 65.0f, 10.1f);
		glVertex3f(-5.25f, 69.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 69.0f, 10.1f);
		glVertex3f(-4.25f, 65.0f, 10.1f);
		glVertex3f(-0.5f, 65.0f, 10.1f);
		glVertex3f(-0.5f, 69.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 69.0f, 10.1f);
		glVertex3f(0.5f, 65.0f, 10.1f);
		glVertex3f(4.25f, 65.0f, 10.1f);
		glVertex3f(4.25f, 69.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 69.0f, 10.1f);
		glVertex3f(5.25f, 65.0f, 10.1f);
		glVertex3f(9.0f, 65.0f, 10.1f);
		glVertex3f(9.0f, 69.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 64.0f, 10.1f);
		glVertex3f(-9.0f, 60.0f, 10.1f);
		glVertex3f(-5.25f, 60.0f, 10.1f);
		glVertex3f(-5.25f, 64.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 64.0f, 10.1f);
		glVertex3f(-4.25f, 60.0f, 10.1f);
		glVertex3f(-0.5f, 60.0f, 10.1f);
		glVertex3f(-0.5f, 64.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 64.0f, 10.1f);
		glVertex3f(0.5f, 60.0f, 10.1f);
		glVertex3f(4.25f, 60.0f, 10.1f);
		glVertex3f(4.25f, 64.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 64.0f, 10.1f);
		glVertex3f(5.25f, 60.0f, 10.1f);
		glVertex3f(9.0f, 60.0f, 10.1f);
		glVertex3f(9.0f, 64.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 59.0f, 10.1f);
		glVertex3f(-9.0f, 55.0f, 10.1f);
		glVertex3f(-5.25f, 55.0f, 10.1f);
		glVertex3f(-5.25f, 59.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 59.0f, 10.1f);
		glVertex3f(-4.25f, 55.0f, 10.1f);
		glVertex3f(-0.5f, 55.0f, 10.1f);
		glVertex3f(-0.5f, 59.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 59.0f, 10.1f);
		glVertex3f(0.5f, 55.0f, 10.1f);
		glVertex3f(4.25f, 55.0f, 10.1f);
		glVertex3f(4.25f, 59.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 59.0f, 10.1f);
		glVertex3f(5.25f, 55.0f, 10.1f);
		glVertex3f(9.0f, 55.0f, 10.1f);
		glVertex3f(9.0f, 59.0f, 10.1f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 54.0f, 10.1f);
		glVertex3f(-9.0f, 50.0f, 10.1f);
		glVertex3f(-5.25f, 50.0f, 10.1f);
		glVertex3f(-5.25f, 54.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 54.0f, 10.1f);
		glVertex3f(-4.25f, 50.0f, 10.1f);
		glVertex3f(-0.5f, 50.0f, 10.1f);
		glVertex3f(-0.5f, 54.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 54.0f, 10.1f);
		glVertex3f(0.5f, 50.0f, 10.1f);
		glVertex3f(4.25f, 50.0f, 10.1f);
		glVertex3f(4.25f, 54.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 54.0f, 10.1f);
		glVertex3f(5.25f, 50.0f, 10.1f);
		glVertex3f(9.0f, 50.0f, 10.1f);
		glVertex3f(9.0f, 54.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 49.0f, 20.1f);
		glVertex3f(-9.0f, 45.0f, 20.1f);
		glVertex3f(-5.25f, 45.0f, 20.1f);
		glVertex3f(-5.25f, 49.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 49.0f, 20.1f);
		glVertex3f(-4.25f, 45.0f, 20.1f);
		glVertex3f(-0.5f, 45.0f, 20.1f);
		glVertex3f(-0.5f, 49.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 49.0f, 20.1f);
		glVertex3f(0.5f, 45.0f, 20.1f);
		glVertex3f(4.25f, 45.0f, 20.1f);
		glVertex3f(4.25f, 49.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 49.0f, 20.1f);
		glVertex3f(5.25f, 45.0f, 20.1f);
		glVertex3f(9.0f, 45.0f, 20.1f);
		glVertex3f(9.0f, 49.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 44.0f, 20.1f);
		glVertex3f(-9.0f, 40.0f, 20.1f);
		glVertex3f(-5.25f, 40.0f, 20.1f);
		glVertex3f(-5.25f, 44.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 44.0f, 20.1f);
		glVertex3f(-4.25f, 40.0f, 20.1f);
		glVertex3f(-0.5f, 40.0f, 20.1f);
		glVertex3f(-0.5f, 44.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 44.0f, 20.1f);
		glVertex3f(0.5f, 40.0f, 20.1f);
		glVertex3f(4.25f, 40.0f, 20.1f);
		glVertex3f(4.25f, 44.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 44.0f, 20.1f);
		glVertex3f(5.25f, 40.0f, 20.1f);
		glVertex3f(9.0f, 40.0f, 20.1f);
		glVertex3f(9.0f, 44.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 39.0f, 20.1f);
		glVertex3f(-9.0f, 35.0f, 20.1f);
		glVertex3f(-5.25f, 35.0f, 20.1f);
		glVertex3f(-5.25f, 39.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 39.0f, 20.1f);
		glVertex3f(-4.25f, 35.0f, 20.1f);
		glVertex3f(-0.5f, 35.0f, 20.1f);
		glVertex3f(-0.5f, 39.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 39.0f, 20.1f);
		glVertex3f(0.5f, 35.0f, 20.1f);
		glVertex3f(4.25f, 35.0f, 20.1f);
		glVertex3f(4.25f, 39.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 39.0f, 20.1f);
		glVertex3f(5.25f, 35.0f, 20.1f);
		glVertex3f(9.0f, 35.0f, 20.1f);
		glVertex3f(9.0f, 39.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 34.0f, 20.1f);
		glVertex3f(-9.0f, 30.0f, 20.1f);
		glVertex3f(-5.25f, 30.0f, 20.1f);
		glVertex3f(-5.25f, 34.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 34.0f, 20.1f);
		glVertex3f(-4.25f, 30.0f, 20.1f);
		glVertex3f(-0.5f, 30.0f, 20.1f);
		glVertex3f(-0.5f, 34.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 34.0f, 20.1f);
		glVertex3f(0.5f, 30.0f, 20.1f);
		glVertex3f(4.25f, 30.0f, 20.1f);
		glVertex3f(4.25f, 34.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 34.0f, 20.1f);
		glVertex3f(5.25f, 30.0f, 20.1f);
		glVertex3f(9.0f, 30.0f, 20.1f);
		glVertex3f(9.0f, 34.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 29.0f, 10.1f);
		glVertex3f(-9.0f, 25.0f, 10.1f);
		glVertex3f(-5.25f, 25.0f, 10.1f);
		glVertex3f(-5.25f, 29.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 29.0f, 10.1f);
		glVertex3f(-4.25f, 25.0f, 10.1f);
		glVertex3f(-0.5f, 25.0f, 10.1f);
		glVertex3f(-0.5f, 29.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 29.0f, 10.1f);
		glVertex3f(0.5f, 25.0f, 10.1f);
		glVertex3f(4.25f, 25.0f, 10.1f);
		glVertex3f(4.25f, 29.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 29.0f, 10.1f);
		glVertex3f(5.25f, 25.0f, 10.1f);
		glVertex3f(9.0f, 25.0f, 10.1f);
		glVertex3f(9.0f, 29.0f, 10.1f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 24.0f, 10.1f);
		glVertex3f(-9.0f, 20.0f, 10.1f);
		glVertex3f(-5.25f, 20.0f, 10.1f);
		glVertex3f(-5.25f, 24.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 24.0f, 10.1f);
		glVertex3f(-4.25f, 20.0f, 10.1f);
		glVertex3f(-0.5f, 20.0f, 10.1f);
		glVertex3f(-0.5f, 24.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 24.0f, 10.1f);
		glVertex3f(0.5f, 20.0f, 10.1f);
		glVertex3f(4.25f, 20.0f, 10.1f);
		glVertex3f(4.25f, 24.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 24.0f, 10.1f);
		glVertex3f(5.25f, 20.0f, 10.1f);
		glVertex3f(9.0f, 20.0f, 10.1f);
		glVertex3f(9.0f, 24.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 19.0f, 10.1f);
		glVertex3f(-9.0f, 15.0f, 10.1f);
		glVertex3f(-5.25f, 15.0f, 10.1f);
		glVertex3f(-5.25f, 19.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 19.0f, 10.1f);
		glVertex3f(-4.25f, 15.0f, 10.1f);
		glVertex3f(-0.5f, 15.0f, 10.1f);
		glVertex3f(-0.5f, 19.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 19.0f, 10.1f);
		glVertex3f(0.5f, 15.0f, 10.1f);
		glVertex3f(4.25f, 15.0f, 10.1f);
		glVertex3f(4.25f, 19.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 19.0f, 10.1f);
		glVertex3f(5.25f, 15.0f, 10.1f);
		glVertex3f(9.0f, 15.0f, 10.1f);
		glVertex3f(9.0f, 19.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 14.0f, 10.1f);
		glVertex3f(-9.0f, 10.0f, 10.1f);
		glVertex3f(-5.25f, 10.0f, 10.1f);
		glVertex3f(-5.25f, 14.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 14.0f, 10.1f);
		glVertex3f(-4.25f, 10.0f, 10.1f);
		glVertex3f(-0.5f, 10.0f, 10.1f);
		glVertex3f(-0.5f, 14.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 14.0f, 10.1f);
		glVertex3f(0.5f, 10.0f, 10.1f);
		glVertex3f(4.25f, 10.0f, 10.1f);
		glVertex3f(4.25f, 14.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 14.0f, 10.1f);
		glVertex3f(5.25f, 10.0f, 10.1f);
		glVertex3f(9.0f, 10.0f, 10.1f);
		glVertex3f(9.0f, 14.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 9.0f, 10.1f);
		glVertex3f(-9.0f, 5.0f, 10.1f);
		glVertex3f(-5.25f, 5.0f, 10.1f);
		glVertex3f(-5.25f, 9.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 9.0f, 10.1f);
		glVertex3f(-4.25f, 5.0f, 10.1f);
		glVertex3f(-0.5f, 5.0f, 10.1f);
		glVertex3f(-0.5f, 9.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 9.0f, 10.1f);
		glVertex3f(0.5f, 5.0f, 10.1f);
		glVertex3f(4.25f, 5.0f, 10.1f);
		glVertex3f(4.25f, 9.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 9.0f, 10.1f);
		glVertex3f(5.25f, 5.0f, 10.1f);
		glVertex3f(9.0f, 5.0f, 10.1f);
		glVertex3f(9.0f, 9.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-9.0f, 4.0f, 10.1f);
		glVertex3f(-9.0f, 1.0f, 10.1f);
		glVertex3f(-5.25f, 1.0f, 10.1f);
		glVertex3f(-5.25f, 4.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-4.25f, 4.0f, 10.1f);
		glVertex3f(-4.25f, 1.0f, 10.1f);
		glVertex3f(-0.5f, 1.0f, 10.1f);
		glVertex3f(-0.5f, 4.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(0.5f, 4.0f, 10.1f);
		glVertex3f(0.5f, 1.0f, 10.1f);
		glVertex3f(4.25f, 1.0f, 10.1f);
		glVertex3f(4.25f, 4.0f, 10.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(5.25f, 4.0f, 10.1f);
		glVertex3f(5.25f, 1.0f, 10.1f);
		glVertex3f(9.0f, 1.0f, 10.1f);
		glVertex3f(9.0f, 4.0f, 10.1f);

		glEnd();

		/********************
		 * ***********************************
		 * ***********************************
		 * ************************************
		 * **************************************************
		 * ***************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 149.0f, 40.1f);
		glVertex3f(21.0f, 145.0f, 40.1f);
		glVertex3f(24.25f, 145.0f, 40.1f);
		glVertex3f(24.25f, 149.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 149.0f, 40.1f);
		glVertex3f(25.25f, 145.0f, 40.1f);
		glVertex3f(29.5f, 145.0f, 40.1f);
		glVertex3f(29.5f, 149.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 149.0f, 40.1f);
		glVertex3f(30.5f, 145.0f, 40.1f);
		glVertex3f(34.25f, 145.0f, 40.1f);
		glVertex3f(34.25f, 149.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 149.0f, 40.1f);
		glVertex3f(35.25f, 145.0f, 40.1f);
		glVertex3f(39.0f, 145.0f, 40.1f);
		glVertex3f(39.0f, 149.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 144.0f, 40.1f);
		glVertex3f(21.0f, 140.0f, 40.1f);
		glVertex3f(24.25f, 140.0f, 40.1f);
		glVertex3f(24.25f, 144.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 144.0f, 40.1f);
		glVertex3f(25.25f, 140.0f, 40.1f);
		glVertex3f(29.5f, 140.0f, 40.1f);
		glVertex3f(29.5f, 144.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 144.0f, 40.1f);
		glVertex3f(30.5f, 140.0f, 40.1f);
		glVertex3f(34.25f, 140.0f, 40.1f);
		glVertex3f(34.25f, 144.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 144.0f, 40.1f);
		glVertex3f(35.25f, 140.0f, 40.1f);
		glVertex3f(39.0f, 140.0f, 40.1f);
		glVertex3f(39.0f, 144.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 139.0f, 40.1f);
		glVertex3f(21.0f, 135.0f, 40.1f);
		glVertex3f(24.25f, 135.0f, 40.1f);
		glVertex3f(24.25f, 139.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 139.0f, 40.1f);
		glVertex3f(25.25f, 135.0f, 40.1f);
		glVertex3f(29.5f, 135.0f, 40.1f);
		glVertex3f(29.5f, 139.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 139.0f, 40.1f);
		glVertex3f(30.5f, 135.0f, 40.1f);
		glVertex3f(34.25f, 135.0f, 40.1f);
		glVertex3f(34.25f, 139.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 139.0f, 40.1f);
		glVertex3f(35.25f, 135.0f, 40.1f);
		glVertex3f(39.0f, 135.0f, 40.1f);
		glVertex3f(39.0f, 139.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 134.0f, 40.1f);
		glVertex3f(21.0f, 130.0f, 40.1f);
		glVertex3f(24.25f, 130.0f, 40.1f);
		glVertex3f(24.25f, 134.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 134.0f, 40.1f);
		glVertex3f(25.25f, 130.0f, 40.1f);
		glVertex3f(29.5f, 130.0f, 40.1f);
		glVertex3f(29.5f, 134.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 134.0f, 40.1f);
		glVertex3f(30.5f, 130.0f, 40.1f);
		glVertex3f(34.25f, 130.0f, 40.1f);
		glVertex3f(34.25f, 134.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 134.0f, 40.1f);
		glVertex3f(35.25f, 130.0f, 40.1f);
		glVertex3f(39.0f, 130.0f, 40.1f);
		glVertex3f(39.0f, 134.0f, 40.1f);

		glEnd();

		/*****************************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 129.0f, 40.1f);
		glVertex3f(21.0f, 125.0f, 40.1f);
		glVertex3f(24.25f, 125.0f, 40.1f);
		glVertex3f(24.25f, 129.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 129.0f, 40.1f);
		glVertex3f(25.25f, 125.0f, 40.1f);
		glVertex3f(29.5f, 125.0f, 40.1f);
		glVertex3f(29.5f, 129.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 129.0f, 40.1f);
		glVertex3f(30.5f, 125.0f, 40.1f);
		glVertex3f(34.25f, 125.0f, 40.1f);
		glVertex3f(34.25f, 129.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 129.0f, 40.1f);
		glVertex3f(35.25f, 125.0f, 40.1f);
		glVertex3f(39.0f, 125.0f, 40.1f);
		glVertex3f(39.0f, 129.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 124.0f, 40.1f);
		glVertex3f(21.0f, 120.0f, 40.1f);
		glVertex3f(24.25f, 120.0f, 40.1f);
		glVertex3f(24.25f, 124.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 124.0f, 40.1f);
		glVertex3f(25.25f, 120.0f, 40.1f);
		glVertex3f(29.5f, 120.0f, 40.1f);
		glVertex3f(29.5f, 124.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 124.0f, 40.1f);
		glVertex3f(30.5f, 120.0f, 40.1f);
		glVertex3f(34.25f, 120.0f, 40.1f);
		glVertex3f(34.25f, 124.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 124.0f, 40.1f);
		glVertex3f(35.25f, 120.0f, 40.1f);
		glVertex3f(39.0f, 120.0f, 40.1f);
		glVertex3f(39.0f, 124.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 119.0f, 40.1f);
		glVertex3f(21.0f, 115.0f, 40.1f);
		glVertex3f(24.25f, 115.0f, 40.1f);
		glVertex3f(24.25f, 119.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 119.0f, 40.1f);
		glVertex3f(25.25f, 115.0f, 40.1f);
		glVertex3f(29.5f, 115.0f, 40.1f);
		glVertex3f(29.5f, 119.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 119.0f, 40.1f);
		glVertex3f(30.5f, 115.0f, 40.1f);
		glVertex3f(34.25f, 115.0f, 40.1f);
		glVertex3f(34.25f, 119.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 119.0f, 40.1f);
		glVertex3f(35.25f, 115.0f, 40.1f);
		glVertex3f(39.0f, 115.0f, 40.1f);
		glVertex3f(39.0f, 119.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 114.0f, 40.1f);
		glVertex3f(21.0f, 110.0f, 40.1f);
		glVertex3f(24.25f, 110.0f, 40.1f);
		glVertex3f(24.25f, 114.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 114.0f, 40.1f);
		glVertex3f(25.25f, 110.0f, 40.1f);
		glVertex3f(29.5f, 110.0f, 40.1f);
		glVertex3f(29.5f, 114.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 114.0f, 40.1f);
		glVertex3f(30.5f, 110.0f, 40.1f);
		glVertex3f(34.25f, 110.0f, 40.1f);
		glVertex3f(34.25f, 114.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 114.0f, 40.1f);
		glVertex3f(35.25f, 110.0f, 40.1f);
		glVertex3f(39.0f, 110.0f, 40.1f);
		glVertex3f(39.0f, 114.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 109.0f, 40.1f);
		glVertex3f(21.0f, 105.0f, 40.1f);
		glVertex3f(24.25f, 105.0f, 40.1f);
		glVertex3f(24.25f, 109.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 109.0f, 40.1f);
		glVertex3f(25.25f, 105.0f, 40.1f);
		glVertex3f(29.5f, 105.0f, 40.1f);
		glVertex3f(29.5f, 109.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 109.0f, 40.1f);
		glVertex3f(30.5f, 105.0f, 40.1f);
		glVertex3f(34.25f, 105.0f, 40.1f);
		glVertex3f(34.25f, 109.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 109.0f, 40.1f);
		glVertex3f(35.25f, 105.0f, 40.1f);
		glVertex3f(39.0f, 105.0f, 40.1f);
		glVertex3f(39.0f, 109.0f, 40.1f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 104.0f, 40.1f);
		glVertex3f(21.0f, 100.0f, 40.1f);
		glVertex3f(24.25f, 100.0f, 40.1f);
		glVertex3f(24.25f, 104.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 104.0f, 40.1f);
		glVertex3f(25.25f, 100.0f, 40.1f);
		glVertex3f(29.5f, 100.0f, 40.1f);
		glVertex3f(29.5f, 104.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 104.0f, 40.1f);
		glVertex3f(30.5f, 100.0f, 40.1f);
		glVertex3f(34.25f, 100.0f, 40.1f);
		glVertex3f(34.25f, 104.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 104.0f, 40.1f);
		glVertex3f(35.25f, 100.0f, 40.1f);
		glVertex3f(39.0f, 100.0f, 40.1f);
		glVertex3f(39.0f, 104.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 99.0f, 40.1f);
		glVertex3f(21.0f, 95.0f, 40.1f);
		glVertex3f(24.25f, 95.0f, 40.1f);
		glVertex3f(24.25f, 99.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 99.0f, 40.1f);
		glVertex3f(25.25f, 95.0f, 40.1f);
		glVertex3f(29.5f, 95.0f, 40.1f);
		glVertex3f(29.5f, 99.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 99.0f, 40.1f);
		glVertex3f(30.5f, 95.0f, 40.1f);
		glVertex3f(34.25f, 95.0f, 40.1f);
		glVertex3f(34.25f, 99.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 99.0f, 40.1f);
		glVertex3f(35.25f, 95.0f, 40.1f);
		glVertex3f(39.0f, 95.0f, 40.1f);
		glVertex3f(39.0f, 99.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 94.0f, 40.1f);
		glVertex3f(21.0f, 90.0f, 40.1f);
		glVertex3f(24.25f, 90.0f, 40.1f);
		glVertex3f(24.25f, 94.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 94.0f, 40.1f);
		glVertex3f(25.25f, 90.0f, 40.1f);
		glVertex3f(29.5f, 90.0f, 40.1f);
		glVertex3f(29.5f, 94.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 94.0f, 40.1f);
		glVertex3f(30.5f, 90.0f, 40.1f);
		glVertex3f(34.25f, 90.0f, 40.1f);
		glVertex3f(34.25f, 94.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 94.0f, 40.1f);
		glVertex3f(35.25f, 90.0f, 40.1f);
		glVertex3f(39.0f, 90.0f, 40.1f);
		glVertex3f(39.0f, 94.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 89.0f, 40.1f);
		glVertex3f(21.0f, 85.0f, 40.1f);
		glVertex3f(24.25f, 85.0f, 40.1f);
		glVertex3f(24.25f, 89.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 89.0f, 40.1f);
		glVertex3f(25.25f, 85.0f, 40.1f);
		glVertex3f(29.5f, 85.0f, 40.1f);
		glVertex3f(29.5f, 89.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 89.0f, 40.1f);
		glVertex3f(30.5f, 85.0f, 40.1f);
		glVertex3f(34.25f, 85.0f, 40.1f);
		glVertex3f(34.25f, 89.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 89.0f, 40.1f);
		glVertex3f(35.25f, 85.0f, 40.1f);
		glVertex3f(39.0f, 85.0f, 40.1f);
		glVertex3f(39.0f, 89.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 84.0f, 40.1f);
		glVertex3f(21.0f, 80.0f, 40.1f);
		glVertex3f(24.25f, 80.0f, 40.1f);
		glVertex3f(24.25f, 84.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 84.0f, 40.1f);
		glVertex3f(25.25f, 80.0f, 40.1f);
		glVertex3f(29.5f, 80.0f, 40.1f);
		glVertex3f(29.5f, 84.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 84.0f, 40.1f);
		glVertex3f(30.5f, 80.0f, 40.1f);
		glVertex3f(34.25f, 80.0f, 40.1f);
		glVertex3f(34.25f, 84.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 84.0f, 40.1f);
		glVertex3f(35.25f, 80.0f, 40.1f);
		glVertex3f(39.0f, 80.0f, 40.1f);
		glVertex3f(39.0f, 84.0f, 40.1f);

		glEnd();

		/*********************************/
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 79.0f, 40.1f);
		glVertex3f(21.0f, 75.0f, 40.1f);
		glVertex3f(24.25f, 75.0f, 40.1f);
		glVertex3f(24.25f, 79.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 79.0f, 40.1f);
		glVertex3f(25.25f, 75.0f, 40.1f);
		glVertex3f(29.5f, 75.0f, 40.1f);
		glVertex3f(29.5f, 79.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 79.0f, 40.1f);
		glVertex3f(30.5f, 75.0f, 40.1f);
		glVertex3f(34.25f, 75.0f, 40.1f);
		glVertex3f(34.25f, 79.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 79.0f, 40.1f);
		glVertex3f(35.25f, 75.0f, 40.1f);
		glVertex3f(39.0f, 75.0f, 40.1f);
		glVertex3f(39.0f, 79.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 74.0f, 40.1f);
		glVertex3f(21.0f, 70.0f, 40.1f);
		glVertex3f(24.25f, 70.0f, 40.1f);
		glVertex3f(24.25f, 74.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 74.0f, 40.1f);
		glVertex3f(25.25f, 70.0f, 40.1f);
		glVertex3f(29.5f, 70.0f, 40.1f);
		glVertex3f(29.5f, 74.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 74.0f, 40.1f);
		glVertex3f(30.5f, 70.0f, 40.1f);
		glVertex3f(34.25f, 70.0f, 40.1f);
		glVertex3f(34.25f, 74.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 74.0f, 40.1f);
		glVertex3f(35.25f, 70.0f, 40.1f);
		glVertex3f(39.0f, 70.0f, 40.1f);
		glVertex3f(39.0f, 74.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 69.0f, 40.1f);
		glVertex3f(21.0f, 65.0f, 40.1f);
		glVertex3f(24.25f, 65.0f, 40.1f);
		glVertex3f(24.25f, 69.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 69.0f, 40.1f);
		glVertex3f(25.25f, 65.0f, 40.1f);
		glVertex3f(29.5f, 65.0f, 40.1f);
		glVertex3f(29.5f, 69.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 69.0f, 40.1f);
		glVertex3f(30.5f, 65.0f, 40.1f);
		glVertex3f(34.25f, 65.0f, 40.1f);
		glVertex3f(34.25f, 69.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 69.0f, 40.1f);
		glVertex3f(35.25f, 65.0f, 40.1f);
		glVertex3f(39.0f, 65.0f, 40.1f);
		glVertex3f(39.0f, 69.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 64.0f, 40.1f);
		glVertex3f(21.0f, 60.0f, 40.1f);
		glVertex3f(24.25f, 60.0f, 40.1f);
		glVertex3f(24.25f, 64.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 64.0f, 40.1f);
		glVertex3f(25.25f, 60.0f, 40.1f);
		glVertex3f(29.5f, 60.0f, 40.1f);
		glVertex3f(29.5f, 64.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 64.0f, 40.1f);
		glVertex3f(30.5f, 60.0f, 40.1f);
		glVertex3f(34.25f, 60.0f, 40.1f);
		glVertex3f(34.25f, 64.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 64.0f, 40.1f);
		glVertex3f(35.25f, 60.0f, 40.1f);
		glVertex3f(39.0f, 60.0f, 40.1f);
		glVertex3f(39.0f, 64.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 59.0f, 40.1f);
		glVertex3f(21.0f, 55.0f, 40.1f);
		glVertex3f(24.25f, 55.0f, 40.1f);
		glVertex3f(24.25f, 59.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 59.0f, 40.1f);
		glVertex3f(25.25f, 55.0f, 40.1f);
		glVertex3f(29.5f, 55.0f, 40.1f);
		glVertex3f(29.5f, 59.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 59.0f, 40.1f);
		glVertex3f(30.5f, 55.0f, 40.1f);
		glVertex3f(34.25f, 55.0f, 40.1f);
		glVertex3f(34.25f, 59.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 59.0f, 40.1f);
		glVertex3f(35.25f, 55.0f, 40.1f);
		glVertex3f(39.0f, 55.0f, 40.1f);
		glVertex3f(39.0f, 59.0f, 40.1f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 54.0f, 40.1f);
		glVertex3f(21.0f, 50.0f, 40.1f);
		glVertex3f(24.25f, 50.0f, 40.1f);
		glVertex3f(24.25f, 54.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 54.0f, 40.1f);
		glVertex3f(25.25f, 50.0f, 40.1f);
		glVertex3f(29.5f, 50.0f, 40.1f);
		glVertex3f(29.5f, 54.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 54.0f, 40.1f);
		glVertex3f(30.5f, 50.0f, 40.1f);
		glVertex3f(34.25f, 50.0f, 40.1f);
		glVertex3f(34.25f, 54.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 54.0f, 40.1f);
		glVertex3f(35.25f, 50.0f, 40.1f);
		glVertex3f(39.0f, 50.0f, 40.1f);
		glVertex3f(39.0f, 54.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 49.0f, 40.1f);
		glVertex3f(21.0f, 45.0f, 40.1f);
		glVertex3f(24.25f, 45.0f, 40.1f);
		glVertex3f(24.25f, 49.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 49.0f, 40.1f);
		glVertex3f(25.25f, 45.0f, 40.1f);
		glVertex3f(29.5f, 45.0f, 40.1f);
		glVertex3f(29.5f, 49.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 49.0f, 40.1f);
		glVertex3f(30.5f, 45.0f, 40.1f);
		glVertex3f(34.25f, 45.0f, 40.1f);
		glVertex3f(34.25f, 49.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 49.0f, 40.1f);
		glVertex3f(35.25f, 45.0f, 40.1f);
		glVertex3f(39.0f, 45.0f, 40.1f);
		glVertex3f(39.0f, 49.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 44.0f, 40.1f);
		glVertex3f(21.0f, 40.0f, 40.1f);
		glVertex3f(24.25f, 40.0f, 40.1f);
		glVertex3f(24.25f, 44.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 44.0f, 40.1f);
		glVertex3f(25.25f, 40.0f, 40.1f);
		glVertex3f(29.5f, 40.0f, 40.1f);
		glVertex3f(29.5f, 44.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 44.0f, 40.1f);
		glVertex3f(30.5f, 40.0f, 40.1f);
		glVertex3f(34.25f, 40.0f, 40.1f);
		glVertex3f(34.25f, 44.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 44.0f, 40.1f);
		glVertex3f(35.25f, 40.0f, 40.1f);
		glVertex3f(39.0f, 40.0f, 40.1f);
		glVertex3f(39.0f, 44.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 39.0f, 40.1f);
		glVertex3f(21.0f, 35.0f, 40.1f);
		glVertex3f(24.25f, 35.0f, 40.1f);
		glVertex3f(24.25f, 39.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 39.0f, 40.1f);
		glVertex3f(25.25f, 35.0f, 40.1f);
		glVertex3f(29.5f, 35.0f, 40.1f);
		glVertex3f(29.5f, 39.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 39.0f, 40.1f);
		glVertex3f(30.5f, 35.0f, 40.1f);
		glVertex3f(34.25f, 35.0f, 40.1f);
		glVertex3f(34.25f, 39.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 39.0f, 40.1f);
		glVertex3f(35.25f, 35.0f, 40.1f);
		glVertex3f(39.0f, 35.0f, 40.1f);
		glVertex3f(39.0f, 39.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 34.0f, 40.1f);
		glVertex3f(21.0f, 30.0f, 40.1f);
		glVertex3f(24.25f, 30.0f, 40.1f);
		glVertex3f(24.25f, 34.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 34.0f, 40.1f);
		glVertex3f(25.25f, 30.0f, 40.1f);
		glVertex3f(29.5f, 30.0f, 40.1f);
		glVertex3f(29.5f, 34.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 34.0f, 40.1f);
		glVertex3f(30.5f, 30.0f, 40.1f);
		glVertex3f(34.25f, 30.0f, 40.1f);
		glVertex3f(34.25f, 34.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 34.0f, 40.1f);
		glVertex3f(35.25f, 30.0f, 40.1f);
		glVertex3f(39.0f, 30.0f, 40.1f);
		glVertex3f(39.0f, 34.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 29.0f, 40.1f);
		glVertex3f(21.0f, 25.0f, 40.1f);
		glVertex3f(24.25f, 25.0f, 40.1f);
		glVertex3f(24.25f, 29.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 29.0f, 40.1f);
		glVertex3f(25.25f, 25.0f, 40.1f);
		glVertex3f(29.5f, 25.0f, 40.1f);
		glVertex3f(29.5f, 29.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 29.0f, 40.1f);
		glVertex3f(30.5f, 25.0f, 40.1f);
		glVertex3f(34.25f, 25.0f, 40.1f);
		glVertex3f(34.25f, 29.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 29.0f, 40.1f);
		glVertex3f(35.25f, 25.0f, 40.1f);
		glVertex3f(39.0f, 25.0f, 40.1f);
		glVertex3f(39.0f, 29.0f, 40.1f);

		glEnd();

		/****************************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 24.0f, 40.1f);
		glVertex3f(21.0f, 20.0f, 40.1f);
		glVertex3f(24.25f, 20.0f, 40.1f);
		glVertex3f(24.25f, 24.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 24.0f, 40.1f);
		glVertex3f(25.25f, 20.0f, 40.1f);
		glVertex3f(29.5f, 20.0f, 40.1f);
		glVertex3f(29.5f, 24.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 24.0f, 40.1f);
		glVertex3f(30.5f, 20.0f, 40.1f);
		glVertex3f(34.25f, 20.0f, 40.1f);
		glVertex3f(34.25f, 24.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 24.0f, 40.1f);
		glVertex3f(35.25f, 20.0f, 40.1f);
		glVertex3f(39.0f, 20.0f, 40.1f);
		glVertex3f(39.0f, 24.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 19.0f, 40.1f);
		glVertex3f(21.0f, 15.0f, 40.1f);
		glVertex3f(24.25f, 15.0f, 40.1f);
		glVertex3f(24.25f, 19.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 19.0f, 40.1f);
		glVertex3f(25.25f, 15.0f, 40.1f);
		glVertex3f(29.5f, 15.0f, 40.1f);
		glVertex3f(29.5f, 19.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 19.0f, 40.1f);
		glVertex3f(30.5f, 15.0f, 40.1f);
		glVertex3f(34.25f, 15.0f, 40.1f);
		glVertex3f(34.25f, 19.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 19.0f, 40.1f);
		glVertex3f(35.25f, 15.0f, 40.1f);
		glVertex3f(39.0f, 15.0f, 40.1f);
		glVertex3f(39.0f, 19.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 14.0f, 40.1f);
		glVertex3f(21.0f, 10.0f, 40.1f);
		glVertex3f(24.25f, 10.0f, 40.1f);
		glVertex3f(24.25f, 14.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 14.0f, 40.1f);
		glVertex3f(25.25f, 10.0f, 40.1f);
		glVertex3f(29.5f, 10.0f, 40.1f);
		glVertex3f(29.5f, 14.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 14.0f, 40.1f);
		glVertex3f(30.5f, 10.0f, 40.1f);
		glVertex3f(34.25f, 10.0f, 40.1f);
		glVertex3f(34.25f, 14.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 14.0f, 40.1f);
		glVertex3f(35.25f, 10.0f, 40.1f);
		glVertex3f(39.0f, 10.0f, 40.1f);
		glVertex3f(39.0f, 14.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 9.0f, 40.1f);
		glVertex3f(21.0f, 5.0f, 40.1f);
		glVertex3f(24.25f, 5.0f, 40.1f);
		glVertex3f(24.25f, 9.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 9.0f, 40.1f);
		glVertex3f(25.25f, 5.0f, 40.1f);
		glVertex3f(29.5f, 5.0f, 40.1f);
		glVertex3f(29.5f, 9.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 9.0f, 40.1f);
		glVertex3f(30.5f, 5.0f, 40.1f);
		glVertex3f(34.25f, 5.0f, 40.1f);
		glVertex3f(34.25f, 9.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 9.0f, 40.1f);
		glVertex3f(35.25f, 5.0f, 40.1f);
		glVertex3f(39.0f, 5.0f, 40.1f);
		glVertex3f(39.0f, 9.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(21.0f, 4.0f, 40.1f);
		glVertex3f(21.0f, 1.0f, 40.1f);
		glVertex3f(24.25f, 1.0f, 40.1f);
		glVertex3f(24.25f, 4.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(25.25f, 4.0f, 40.1f);
		glVertex3f(25.25f, 1.0f, 40.1f);
		glVertex3f(29.5f, 1.0f, 40.1f);
		glVertex3f(29.5f, 4.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(30.5f, 4.0f, 40.1f);
		glVertex3f(30.5f, 1.0f, 40.1f);
		glVertex3f(34.25f, 1.0f, 40.1f);
		glVertex3f(34.25f, 4.0f, 40.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(35.25f, 4.0f, 40.1f);
		glVertex3f(35.25f, 1.0f, 40.1f);
		glVertex3f(39.0f, 1.0f, 40.1f);
		glVertex3f(39.0f, 4.0f, 40.1f);

		glEnd();

		/***************************************
		 * **************************************
		 * **************************************
		 * ****************Onred**********************
		 * **************************************
		 * **************************************
		 * ***************************************/

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 129.0f, -9.0f);
		glVertex3f(10.1f, 125.0f, -9.0f);
		glVertex3f(10.1f, 125.0f, -5.25f);
		glVertex3f(10.1f, 129.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 129.0f, -4.25f);
		glVertex3f(10.1f, 125.0f, -4.25f);
		glVertex3f(10.1f, 125.0f, -0.5f);
		glVertex3f(10.1f, 129.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 129.0f, 0.5f);
		glVertex3f(10.1f, 125.0f, 0.5f);
		glVertex3f(10.1f, 125.0f, 4.25f);
		glVertex3f(10.1f, 129.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 129.0f, 5.250f);
		glVertex3f(10.1f, 125.0f, 5.25f);
		glVertex3f(10.1f, 125.0f, 9.0f);
		glVertex3f(10.1f, 129.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 129.0f, 9.0f);
		glVertex3f(10.1f, 125.0f, 9.0f);
		glVertex3f(10.1f, 125.0f, 5.25f);
		glVertex3f(10.1f, 129.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 124.0f, -9.0f);
		glVertex3f(10.1f, 120.0f, -9.0f);
		glVertex3f(10.1f, 120.0f, -5.25f);
		glVertex3f(10.1f, 124.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 124.0f, -4.25f);
		glVertex3f(10.1f, 120.0f, -4.25f);
		glVertex3f(10.1f, 120.0f, -0.5f);
		glVertex3f(10.1f, 124.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 124.0f, 0.5f);
		glVertex3f(10.1f, 120.0f, 0.5f);
		glVertex3f(10.1f, 120.0f, 4.25f);
		glVertex3f(10.1f, 124.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 124.0f, 5.250f);
		glVertex3f(10.1f, 120.0f, 5.25f);
		glVertex3f(10.1f, 120.0f, 9.0f);
		glVertex3f(10.1f, 124.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 124.0f, 9.0f);
		glVertex3f(10.1f, 120.0f, 9.0f);
		glVertex3f(10.1f, 120.0f, 5.25f);
		glVertex3f(10.1f, 124.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 119.0f, -9.0f);
		glVertex3f(10.1f, 115.0f, -9.0f);
		glVertex3f(10.1f, 115.0f, -5.25f);
		glVertex3f(10.1f, 119.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 119.0f, -4.25f);
		glVertex3f(10.1f, 115.0f, -4.25f);
		glVertex3f(10.1f, 115.0f, -0.5f);
		glVertex3f(10.1f, 119.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 119.0f, 0.5f);
		glVertex3f(10.1f, 115.0f, 0.5f);
		glVertex3f(10.1f, 115.0f, 4.25f);
		glVertex3f(10.1f, 119.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 119.0f, 5.250f);
		glVertex3f(10.1f, 115.0f, 5.25f);
		glVertex3f(10.1f, 115.0f, 9.0f);
		glVertex3f(10.1f, 119.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 119.0f, 9.0f);
		glVertex3f(10.1f, 115.0f, 9.0f);
		glVertex3f(10.1f, 115.0f, 5.25f);
		glVertex3f(10.1f, 119.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 114.0f, -9.0f);
		glVertex3f(10.1f, 110.0f, -9.0f);
		glVertex3f(10.1f, 110.0f, -5.25f);
		glVertex3f(10.1f, 114.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 114.0f, -4.25f);
		glVertex3f(10.1f, 110.0f, -4.25f);
		glVertex3f(10.1f, 110.0f, -0.5f);
		glVertex3f(10.1f, 114.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 114.0f, 0.5f);
		glVertex3f(10.1f, 110.0f, 0.5f);
		glVertex3f(10.1f, 110.0f, 4.25f);
		glVertex3f(10.1f, 114.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 114.0f, 5.250f);
		glVertex3f(10.1f, 110.0f, 5.25f);
		glVertex3f(10.1f, 110.0f, 9.0f);
		glVertex3f(10.1f, 114.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 114.0f, 9.0f);
		glVertex3f(10.1f, 110.0f, 9.0f);
		glVertex3f(10.1f, 110.0f, 5.25f);
		glVertex3f(10.1f, 114.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 109.0f, -9.0f);
		glVertex3f(10.1f, 105.0f, -9.0f);
		glVertex3f(10.1f, 105.0f, -5.25f);
		glVertex3f(10.1f, 109.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 109.0f, -4.25f);
		glVertex3f(10.1f, 105.0f, -4.25f);
		glVertex3f(10.1f, 105.0f, -0.5f);
		glVertex3f(10.1f, 109.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 109.0f, 0.5f);
		glVertex3f(10.1f, 105.0f, 0.5f);
		glVertex3f(10.1f, 105.0f, 4.25f);
		glVertex3f(10.1f, 109.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 109.0f, 5.250f);
		glVertex3f(10.1f, 105.0f, 5.25f);
		glVertex3f(10.1f, 105.0f, 9.0f);
		glVertex3f(10.1f, 109.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 109.0f, 9.0f);
		glVertex3f(10.1f, 105.0f, 9.0f);
		glVertex3f(10.1f, 105.0f, 5.25f);
		glVertex3f(10.1f, 109.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 104.0f, -9.0f);
		glVertex3f(10.1f, 100.0f, -9.0f);
		glVertex3f(10.1f, 100.0f, -5.25f);
		glVertex3f(10.1f, 104.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 104.0f, -4.25f);
		glVertex3f(10.1f, 100.0f, -4.25f);
		glVertex3f(10.1f, 100.0f, -0.5f);
		glVertex3f(10.1f, 104.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 104.0f, 0.5f);
		glVertex3f(10.1f, 100.0f, 0.5f);
		glVertex3f(10.1f, 100.0f, 4.25f);
		glVertex3f(10.1f, 104.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 104.0f, 5.250f);
		glVertex3f(10.1f, 100.0f, 5.25f);
		glVertex3f(10.1f, 100.0f, 9.0f);
		glVertex3f(10.1f, 104.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 104.0f, 9.0f);
		glVertex3f(10.1f, 100.0f, 9.0f);
		glVertex3f(10.1f, 100.0f, 5.25f);
		glVertex3f(10.1f, 104.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 99.0f, -9.0f);
		glVertex3f(10.1f, 95.0f, -9.0f);
		glVertex3f(10.1f, 95.0f, -5.25f);
		glVertex3f(10.1f, 99.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 99.0f, -4.25f);
		glVertex3f(10.1f, 95.0f, -4.25f);
		glVertex3f(10.1f, 95.0f, -0.5f);
		glVertex3f(10.1f, 99.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 99.0f, 0.5f);
		glVertex3f(10.1f, 95.0f, 0.5f);
		glVertex3f(10.1f, 95.0f, 4.25f);
		glVertex3f(10.1f, 99.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 99.0f, 5.250f);
		glVertex3f(10.1f, 95.0f, 5.25f);
		glVertex3f(10.1f, 95.0f, 9.0f);
		glVertex3f(10.1f, 99.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 99.0f, 9.0f);
		glVertex3f(10.1f, 95.0f, 9.0f);
		glVertex3f(10.1f, 95.0f, 5.25f);
		glVertex3f(10.1f, 99.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 94.0f, -9.0f);
		glVertex3f(10.1f, 90.0f, -9.0f);
		glVertex3f(10.1f, 90.0f, -5.25f);
		glVertex3f(10.1f, 94.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 94.0f, -4.25f);
		glVertex3f(10.1f, 90.0f, -4.25f);
		glVertex3f(10.1f, 90.0f, -0.5f);
		glVertex3f(10.1f, 94.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 94.0f, 0.5f);
		glVertex3f(10.1f, 90.0f, 0.5f);
		glVertex3f(10.1f, 90.0f, 4.25f);
		glVertex3f(10.1f, 94.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 94.0f, 5.250f);
		glVertex3f(10.1f, 90.0f, 5.25f);
		glVertex3f(10.1f, 90.0f, 9.0f);
		glVertex3f(10.1f, 94.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 94.0f, 9.0f);
		glVertex3f(10.1f, 90.0f, 9.0f);
		glVertex3f(10.1f, 90.0f, 5.25f);
		glVertex3f(10.1f, 94.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 89.0f, -9.0f);
		glVertex3f(10.1f, 85.0f, -9.0f);
		glVertex3f(10.1f, 85.0f, -5.25f);
		glVertex3f(10.1f, 89.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 89.0f, -4.25f);
		glVertex3f(10.1f, 85.0f, -4.25f);
		glVertex3f(10.1f, 85.0f, -0.5f);
		glVertex3f(10.1f, 89.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 89.0f, 0.5f);
		glVertex3f(10.1f, 85.0f, 0.5f);
		glVertex3f(10.1f, 85.0f, 4.25f);
		glVertex3f(10.1f, 89.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 89.0f, 5.250f);
		glVertex3f(10.1f, 85.0f, 5.25f);
		glVertex3f(10.1f, 85.0f, 9.0f);
		glVertex3f(10.1f, 89.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 89.0f, 9.0f);
		glVertex3f(10.1f, 85.0f, 9.0f);
		glVertex3f(10.1f, 85.0f, 5.25f);
		glVertex3f(10.1f, 89.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 84.0f, -9.0f);
		glVertex3f(10.1f, 80.0f, -9.0f);
		glVertex3f(10.1f, 80.0f, -5.25f);
		glVertex3f(10.1f, 84.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 84.0f, -4.25f);
		glVertex3f(10.1f, 80.0f, -4.25f);
		glVertex3f(10.1f, 80.0f, -0.5f);
		glVertex3f(10.1f, 84.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 84.0f, 0.5f);
		glVertex3f(10.1f, 80.0f, 0.5f);
		glVertex3f(10.1f, 80.0f, 4.25f);
		glVertex3f(10.1f, 84.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 84.0f, 5.250f);
		glVertex3f(10.1f, 80.0f, 5.25f);
		glVertex3f(10.1f, 80.0f, 9.0f);
		glVertex3f(10.1f, 84.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 84.0f, 9.0f);
		glVertex3f(10.1f, 80.0f, 9.0f);
		glVertex3f(10.1f, 80.0f, 5.25f);
		glVertex3f(10.1f, 84.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 79.0f, -9.0f);
		glVertex3f(20.1f, 75.0f, -9.0f);
		glVertex3f(20.1f, 75.0f, -5.25f);
		glVertex3f(20.1f, 79.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 79.0f, -4.25f);
		glVertex3f(20.1f, 75.0f, -4.25f);
		glVertex3f(20.1f, 75.0f, -0.5f);
		glVertex3f(20.1f, 79.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 79.0f, 0.5f);
		glVertex3f(20.1f, 75.0f, 0.5f);
		glVertex3f(20.1f, 75.0f, 4.25f);
		glVertex3f(20.1f, 79.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 79.0f, 5.250f);
		glVertex3f(20.1f, 75.0f, 5.25f);
		glVertex3f(20.1f, 75.0f, 9.0f);
		glVertex3f(20.1f, 79.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 79.0f, 9.0f);
		glVertex3f(20.1f, 75.0f, 9.0f);
		glVertex3f(20.1f, 75.0f, 5.25f);
		glVertex3f(20.1f, 79.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 74.0f, -9.0f);
		glVertex3f(20.1f, 70.0f, -9.0f);
		glVertex3f(20.1f, 70.0f, -5.25f);
		glVertex3f(20.1f, 74.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 74.0f, -4.25f);
		glVertex3f(20.1f, 70.0f, -4.25f);
		glVertex3f(20.1f, 70.0f, -0.5f);
		glVertex3f(20.1f, 74.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 74.0f, 0.5f);
		glVertex3f(20.1f, 70.0f, 0.5f);
		glVertex3f(20.1f, 70.0f, 4.25f);
		glVertex3f(20.1f, 74.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 74.0f, 5.250f);
		glVertex3f(20.1f, 70.0f, 5.25f);
		glVertex3f(20.1f, 70.0f, 9.0f);
		glVertex3f(20.1f, 74.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 74.0f, 9.0f);
		glVertex3f(20.1f, 70.0f, 9.0f);
		glVertex3f(20.1f, 70.0f, 5.25f);
		glVertex3f(20.1f, 74.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 69.0f, -9.0f);
		glVertex3f(20.1f, 65.0f, -9.0f);
		glVertex3f(20.1f, 65.0f, -5.25f);
		glVertex3f(20.1f, 69.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 69.0f, -4.25f);
		glVertex3f(20.1f, 65.0f, -4.25f);
		glVertex3f(20.1f, 65.0f, -0.5f);
		glVertex3f(20.1f, 69.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 69.0f, 0.5f);
		glVertex3f(20.1f, 65.0f, 0.5f);
		glVertex3f(20.1f, 65.0f, 4.25f);
		glVertex3f(20.1f, 69.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 69.0f, 5.250f);
		glVertex3f(20.1f, 65.0f, 5.25f);
		glVertex3f(20.1f, 65.0f, 9.0f);
		glVertex3f(20.1f, 69.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 69.0f, 9.0f);
		glVertex3f(20.1f, 65.0f, 9.0f);
		glVertex3f(20.1f, 65.0f, 5.25f);
		glVertex3f(20.1f, 69.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 64.0f, -9.0f);
		glVertex3f(20.1f, 60.0f, -9.0f);
		glVertex3f(20.1f, 60.0f, -5.25f);
		glVertex3f(20.1f, 64.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 64.0f, -4.25f);
		glVertex3f(20.1f, 60.0f, -4.25f);
		glVertex3f(20.1f, 60.0f, -0.5f);
		glVertex3f(20.1f, 64.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 64.0f, 0.5f);
		glVertex3f(20.1f, 60.0f, 0.5f);
		glVertex3f(20.1f, 60.0f, 4.25f);
		glVertex3f(20.1f, 64.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 64.0f, 5.250f);
		glVertex3f(20.1f, 60.0f, 5.25f);
		glVertex3f(20.1f, 60.0f, 9.0f);
		glVertex3f(20.1f, 64.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(20.1f, 64.0f, 9.0f);
		glVertex3f(20.1f, 60.0f, 9.0f);
		glVertex3f(20.1f, 60.0f, 5.25f);
		glVertex3f(20.1f, 64.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 59.0f, -9.0f);
		glVertex3f(10.1f, 55.0f, -9.0f);
		glVertex3f(10.1f, 55.0f, -5.25f);
		glVertex3f(10.1f, 59.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 59.0f, -4.25f);
		glVertex3f(10.1f, 55.0f, -4.25f);
		glVertex3f(10.1f, 55.0f, -0.5f);
		glVertex3f(10.1f, 59.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 59.0f, 0.5f);
		glVertex3f(10.1f, 55.0f, 0.5f);
		glVertex3f(10.1f, 55.0f, 4.25f);
		glVertex3f(10.1f, 59.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 59.0f, 5.250f);
		glVertex3f(10.1f, 55.0f, 5.25f);
		glVertex3f(10.1f, 55.0f, 9.0f);
		glVertex3f(10.1f, 59.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 59.0f, 9.0f);
		glVertex3f(10.1f, 55.0f, 9.0f);
		glVertex3f(10.1f, 55.0f, 5.25f);
		glVertex3f(10.1f, 59.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 54.0f, -9.0f);
		glVertex3f(10.1f, 50.0f, -9.0f);
		glVertex3f(10.1f, 50.0f, -5.25f);
		glVertex3f(10.1f, 54.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 54.0f, -4.25f);
		glVertex3f(10.1f, 50.0f, -4.25f);
		glVertex3f(10.1f, 50.0f, -0.5f);
		glVertex3f(10.1f, 54.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 54.0f, 0.5f);
		glVertex3f(10.1f, 50.0f, 0.5f);
		glVertex3f(10.1f, 50.0f, 4.25f);
		glVertex3f(10.1f, 54.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 54.0f, 5.250f);
		glVertex3f(10.1f, 50.0f, 5.25f);
		glVertex3f(10.1f, 50.0f, 9.0f);
		glVertex3f(10.1f, 54.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 54.0f, 9.0f);
		glVertex3f(10.1f, 50.0f, 9.0f);
		glVertex3f(10.1f, 50.0f, 5.25f);
		glVertex3f(10.1f, 54.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 49.0f, -9.0f);
		glVertex3f(10.1f, 45.0f, -9.0f);
		glVertex3f(10.1f, 45.0f, -5.25f);
		glVertex3f(10.1f, 49.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 49.0f, -4.25f);
		glVertex3f(10.1f, 45.0f, -4.25f);
		glVertex3f(10.1f, 45.0f, -0.5f);
		glVertex3f(10.1f, 49.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 49.0f, 0.5f);
		glVertex3f(10.1f, 45.0f, 0.5f);
		glVertex3f(10.1f, 45.0f, 4.25f);
		glVertex3f(10.1f, 49.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 49.0f, 5.250f);
		glVertex3f(10.1f, 45.0f, 5.25f);
		glVertex3f(10.1f, 45.0f, 9.0f);
		glVertex3f(10.1f, 49.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 49.0f, 9.0f);
		glVertex3f(10.1f, 45.0f, 9.0f);
		glVertex3f(10.1f, 45.0f, 5.25f);
		glVertex3f(10.1f, 49.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 44.0f, -9.0f);
		glVertex3f(10.1f, 40.0f, -9.0f);
		glVertex3f(10.1f, 40.0f, -5.25f);
		glVertex3f(10.1f, 44.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 44.0f, -4.25f);
		glVertex3f(10.1f, 40.0f, -4.25f);
		glVertex3f(10.1f, 40.0f, -0.5f);
		glVertex3f(10.1f, 44.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 44.0f, 0.5f);
		glVertex3f(10.1f, 40.0f, 0.5f);
		glVertex3f(10.1f, 40.0f, 4.25f);
		glVertex3f(10.1f, 44.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 44.0f, 5.250f);
		glVertex3f(10.1f, 40.0f, 5.25f);
		glVertex3f(10.1f, 40.0f, 9.0f);
		glVertex3f(10.1f, 44.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 44.0f, 9.0f);
		glVertex3f(10.1f, 40.0f, 9.0f);
		glVertex3f(10.1f, 40.0f, 5.25f);
		glVertex3f(10.1f, 44.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 39.0f, -9.0f);
		glVertex3f(10.1f, 35.0f, -9.0f);
		glVertex3f(10.1f, 35.0f, -5.25f);
		glVertex3f(10.1f, 39.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 39.0f, -4.25f);
		glVertex3f(10.1f, 35.0f, -4.25f);
		glVertex3f(10.1f, 35.0f, -0.5f);
		glVertex3f(10.1f, 39.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 39.0f, 0.5f);
		glVertex3f(10.1f, 35.0f, 0.5f);
		glVertex3f(10.1f, 35.0f, 4.25f);
		glVertex3f(10.1f, 39.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 39.0f, 5.250f);
		glVertex3f(10.1f, 35.0f, 5.25f);
		glVertex3f(10.1f, 35.0f, 9.0f);
		glVertex3f(10.1f, 39.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 39.0f, 9.0f);
		glVertex3f(10.1f, 35.0f, 9.0f);
		glVertex3f(10.1f, 35.0f, 5.25f);
		glVertex3f(10.1f, 39.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 34.0f, -9.0f);
		glVertex3f(10.1f, 30.0f, -9.0f);
		glVertex3f(10.1f, 30.0f, -5.25f);
		glVertex3f(10.1f, 34.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 34.0f, -4.25f);
		glVertex3f(10.1f, 30.0f, -4.25f);
		glVertex3f(10.1f, 30.0f, -0.5f);
		glVertex3f(10.1f, 34.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 34.0f, 0.5f);
		glVertex3f(10.1f, 30.0f, 0.5f);
		glVertex3f(10.1f, 30.0f, 4.25f);
		glVertex3f(10.1f, 34.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 34.0f, 5.250f);
		glVertex3f(10.1f, 30.0f, 5.25f);
		glVertex3f(10.1f, 30.0f, 9.0f);
		glVertex3f(10.1f, 34.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 34.0f, 9.0f);
		glVertex3f(10.1f, 30.0f, 9.0f);
		glVertex3f(10.1f, 30.0f, 5.25f);
		glVertex3f(10.1f, 34.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 29.0f, -9.0f);
		glVertex3f(10.1f, 25.0f, -9.0f);
		glVertex3f(10.1f, 25.0f, -5.25f);
		glVertex3f(10.1f, 29.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 29.0f, -4.25f);
		glVertex3f(10.1f, 25.0f, -4.25f);
		glVertex3f(10.1f, 25.0f, -0.5f);
		glVertex3f(10.1f, 29.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 29.0f, 0.5f);
		glVertex3f(10.1f, 25.0f, 0.5f);
		glVertex3f(10.1f, 25.0f, 4.25f);
		glVertex3f(10.1f, 29.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 29.0f, 5.250f);
		glVertex3f(10.1f, 25.0f, 5.25f);
		glVertex3f(10.1f, 25.0f, 9.0f);
		glVertex3f(10.1f, 29.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 29.0f, 9.0f);
		glVertex3f(10.1f, 25.0f, 9.0f);
		glVertex3f(10.1f, 25.0f, 5.25f);
		glVertex3f(10.1f, 29.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 24.0f, -9.0f);
		glVertex3f(10.1f, 20.0f, -9.0f);
		glVertex3f(10.1f, 20.0f, -5.25f);
		glVertex3f(10.1f, 24.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 24.0f, -4.25f);
		glVertex3f(10.1f, 20.0f, -4.25f);
		glVertex3f(10.1f, 20.0f, -0.5f);
		glVertex3f(10.1f, 24.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 24.0f, 0.5f);
		glVertex3f(10.1f, 20.0f, 0.5f);
		glVertex3f(10.1f, 20.0f, 4.25f);
		glVertex3f(10.1f, 24.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 24.0f, 5.250f);
		glVertex3f(10.1f, 20.0f, 5.25f);
		glVertex3f(10.1f, 20.0f, 9.0f);
		glVertex3f(10.1f, 24.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 24.0f, 9.0f);
		glVertex3f(10.1f, 20.0f, 9.0f);
		glVertex3f(10.1f, 20.0f, 5.25f);
		glVertex3f(10.1f, 24.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 19.0f, -9.0f);
		glVertex3f(10.1f, 15.0f, -9.0f);
		glVertex3f(10.1f, 15.0f, -5.25f);
		glVertex3f(10.1f, 19.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 19.0f, -4.25f);
		glVertex3f(10.1f, 15.0f, -4.25f);
		glVertex3f(10.1f, 15.0f, -0.5f);
		glVertex3f(10.1f, 19.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 19.0f, 0.5f);
		glVertex3f(10.1f, 15.0f, 0.5f);
		glVertex3f(10.1f, 15.0f, 4.25f);
		glVertex3f(10.1f, 19.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 19.0f, 5.250f);
		glVertex3f(10.1f, 15.0f, 5.25f);
		glVertex3f(10.1f, 15.0f, 9.0f);
		glVertex3f(10.1f, 19.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 19.0f, 9.0f);
		glVertex3f(10.1f, 15.0f, 9.0f);
		glVertex3f(10.1f, 15.0f, 5.25f);
		glVertex3f(10.1f, 19.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 14.0f, -9.0f);
		glVertex3f(10.1f, 10.0f, -9.0f);
		glVertex3f(10.1f, 10.0f, -5.25f);
		glVertex3f(10.1f, 14.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 14.0f, -4.25f);
		glVertex3f(10.1f, 10.0f, -4.25f);
		glVertex3f(10.1f, 10.0f, -0.5f);
		glVertex3f(10.1f, 14.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 14.0f, 0.5f);
		glVertex3f(10.1f, 10.0f, 0.5f);
		glVertex3f(10.1f, 10.0f, 4.25f);
		glVertex3f(10.1f, 14.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 14.0f, 5.250f);
		glVertex3f(10.1f, 10.0f, 5.25f);
		glVertex3f(10.1f, 10.0f, 9.0f);
		glVertex3f(10.1f, 14.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 14.0f, 9.0f);
		glVertex3f(10.1f, 10.0f, 9.0f);
		glVertex3f(10.1f, 10.0f, 5.25f);
		glVertex3f(10.1f, 14.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 9.0f, -9.0f);
		glVertex3f(10.1f, 5.0f, -9.0f);
		glVertex3f(10.1f, 5.0f, -5.25f);
		glVertex3f(10.1f, 9.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 9.0f, -4.25f);
		glVertex3f(10.1f, 5.0f, -4.25f);
		glVertex3f(10.1f, 5.0f, -0.5f);
		glVertex3f(10.1f, 9.0f, -0.5f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 9.0f, 0.5f);
		glVertex3f(10.1f, 5.0f, 0.5f);
		glVertex3f(10.1f, 5.0f, 4.25f);
		glVertex3f(10.1f, 9.0f, 4.25f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 9.0f, 5.250f);
		glVertex3f(10.1f, 5.0f, 5.25f);
		glVertex3f(10.1f, 5.0f, 9.0f);
		glVertex3f(10.1f, 9.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 9.0f, 9.0f);
		glVertex3f(10.1f, 5.0f, 9.0f);
		glVertex3f(10.1f, 5.0f, 5.25f);
		glVertex3f(10.1f, 9.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 4.0f, -9.0f);
		glVertex3f(10.1f, 1.0f, -9.0f);
		glVertex3f(10.1f, 1.0f, -5.25f);
		glVertex3f(10.1f, 4.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 4.0f, -4.25f);
		glVertex3f(10.1f, 1.0f, -4.25f);
		glVertex3f(10.1f, 1.0f, -0.5f);
		glVertex3f(10.1f, 4.0f, -0.5f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 4.0f, 0.5f);
		glVertex3f(10.1f, 1.0f, 0.5f);
		glVertex3f(10.1f, 1.0f, 4.25f);
		glVertex3f(10.1f, 4.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 4.0f, 5.250f);
		glVertex3f(10.1f, 1.0f, 5.25f);
		glVertex3f(10.1f, 1.0f, 9.0f);
		glVertex3f(10.1f, 4.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(10.1f, 4.0f, 9.0f);
		glVertex3f(10.1f, 1.0f, 9.0f);
		glVertex3f(10.1f, 1.0f, 5.25f);
		glVertex3f(10.1f, 4.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 129.0f, -9.0f);
		glVertex3f(-10.1f, 125.0f, -9.0f);
		glVertex3f(-10.1f, 125.0f, -5.25f);
		glVertex3f(-10.1f, 129.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 129.0f, -4.25f);
		glVertex3f(-10.1f, 125.0f, -4.25f);
		glVertex3f(-10.1f, 125.0f, -0.5f);
		glVertex3f(-10.1f, 129.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 129.0f, 0.5f);
		glVertex3f(-10.1f, 125.0f, 0.5f);
		glVertex3f(-10.1f, 125.0f, 4.25f);
		glVertex3f(-10.1f, 129.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 129.0f, 5.250f);
		glVertex3f(-10.1f, 125.0f, 5.25f);
		glVertex3f(-10.1f, 125.0f, 9.0f);
		glVertex3f(-10.1f, 129.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 129.0f, 9.0f);
		glVertex3f(-10.1f, 125.0f, 9.0f);
		glVertex3f(-10.1f, 125.0f, 5.25f);
		glVertex3f(-10.1f, 129.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 124.0f, -9.0f);
		glVertex3f(-10.1f, 120.0f, -9.0f);
		glVertex3f(-10.1f, 120.0f, -5.25f);
		glVertex3f(-10.1f, 124.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 124.0f, -4.25f);
		glVertex3f(-10.1f, 120.0f, -4.25f);
		glVertex3f(-10.1f, 120.0f, -0.5f);
		glVertex3f(-10.1f, 124.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 124.0f, 0.5f);
		glVertex3f(-10.1f, 120.0f, 0.5f);
		glVertex3f(-10.1f, 120.0f, 4.25f);
		glVertex3f(-10.1f, 124.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 124.0f, 5.250f);
		glVertex3f(-10.1f, 120.0f, 5.25f);
		glVertex3f(-10.1f, 120.0f, 9.0f);
		glVertex3f(-10.1f, 124.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 124.0f, 9.0f);
		glVertex3f(-10.1f, 120.0f, 9.0f);
		glVertex3f(-10.1f, 120.0f, 5.25f);
		glVertex3f(-10.1f, 124.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 119.0f, -9.0f);
		glVertex3f(-10.1f, 115.0f, -9.0f);
		glVertex3f(-10.1f, 115.0f, -5.25f);
		glVertex3f(-10.1f, 119.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 119.0f, -4.25f);
		glVertex3f(-10.1f, 115.0f, -4.25f);
		glVertex3f(-10.1f, 115.0f, -0.5f);
		glVertex3f(-10.1f, 119.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 119.0f, 0.5f);
		glVertex3f(-10.1f, 115.0f, 0.5f);
		glVertex3f(-10.1f, 115.0f, 4.25f);
		glVertex3f(-10.1f, 119.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 119.0f, 5.250f);
		glVertex3f(-10.1f, 115.0f, 5.25f);
		glVertex3f(-10.1f, 115.0f, 9.0f);
		glVertex3f(-10.1f, 119.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 119.0f, 9.0f);
		glVertex3f(-10.1f, 115.0f, 9.0f);
		glVertex3f(-10.1f, 115.0f, 5.25f);
		glVertex3f(-10.1f, 119.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 114.0f, -9.0f);
		glVertex3f(-10.1f, 110.0f, -9.0f);
		glVertex3f(-10.1f, 110.0f, -5.25f);
		glVertex3f(-10.1f, 114.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 114.0f, -4.25f);
		glVertex3f(-10.1f, 110.0f, -4.25f);
		glVertex3f(-10.1f, 110.0f, -0.5f);
		glVertex3f(-10.1f, 114.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 114.0f, 0.5f);
		glVertex3f(-10.1f, 110.0f, 0.5f);
		glVertex3f(-10.1f, 110.0f, 4.25f);
		glVertex3f(-10.1f, 114.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 114.0f, 5.250f);
		glVertex3f(-10.1f, 110.0f, 5.25f);
		glVertex3f(-10.1f, 110.0f, 9.0f);
		glVertex3f(-10.1f, 114.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 114.0f, 9.0f);
		glVertex3f(-10.1f, 110.0f, 9.0f);
		glVertex3f(-10.1f, 110.0f, 5.25f);
		glVertex3f(-10.1f, 114.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 109.0f, -9.0f);
		glVertex3f(-10.1f, 105.0f, -9.0f);
		glVertex3f(-10.1f, 105.0f, -5.25f);
		glVertex3f(-10.1f, 109.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 109.0f, -4.25f);
		glVertex3f(-10.1f, 105.0f, -4.25f);
		glVertex3f(-10.1f, 105.0f, -0.5f);
		glVertex3f(-10.1f, 109.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 109.0f, 0.5f);
		glVertex3f(-10.1f, 105.0f, 0.5f);
		glVertex3f(-10.1f, 105.0f, 4.25f);
		glVertex3f(-10.1f, 109.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 109.0f, 5.250f);
		glVertex3f(-10.1f, 105.0f, 5.25f);
		glVertex3f(-10.1f, 105.0f, 9.0f);
		glVertex3f(-10.1f, 109.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 109.0f, 9.0f);
		glVertex3f(-10.1f, 105.0f, 9.0f);
		glVertex3f(-10.1f, 105.0f, 5.25f);
		glVertex3f(-10.1f, 109.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 104.0f, -9.0f);
		glVertex3f(-10.1f, 100.0f, -9.0f);
		glVertex3f(-10.1f, 100.0f, -5.25f);
		glVertex3f(-10.1f, 104.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 104.0f, -4.25f);
		glVertex3f(-10.1f, 100.0f, -4.25f);
		glVertex3f(-10.1f, 100.0f, -0.5f);
		glVertex3f(-10.1f, 104.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 104.0f, 0.5f);
		glVertex3f(-10.1f, 100.0f, 0.5f);
		glVertex3f(-10.1f, 100.0f, 4.25f);
		glVertex3f(-10.1f, 104.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 104.0f, 5.250f);
		glVertex3f(-10.1f, 100.0f, 5.25f);
		glVertex3f(-10.1f, 100.0f, 9.0f);
		glVertex3f(-10.1f, 104.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 104.0f, 9.0f);
		glVertex3f(-10.1f, 100.0f, 9.0f);
		glVertex3f(-10.1f, 100.0f, 5.25f);
		glVertex3f(-10.1f, 104.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 99.0f, -9.0f);
		glVertex3f(-10.1f, 95.0f, -9.0f);
		glVertex3f(-10.1f, 95.0f, -5.25f);
		glVertex3f(-10.1f, 99.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 99.0f, -4.25f);
		glVertex3f(-10.1f, 95.0f, -4.25f);
		glVertex3f(-10.1f, 95.0f, -0.5f);
		glVertex3f(-10.1f, 99.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 99.0f, 0.5f);
		glVertex3f(-10.1f, 95.0f, 0.5f);
		glVertex3f(-10.1f, 95.0f, 4.25f);
		glVertex3f(-10.1f, 99.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 99.0f, 5.250f);
		glVertex3f(-10.1f, 95.0f, 5.25f);
		glVertex3f(-10.1f, 95.0f, 9.0f);
		glVertex3f(-10.1f, 99.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 99.0f, 9.0f);
		glVertex3f(-10.1f, 95.0f, 9.0f);
		glVertex3f(-10.1f, 95.0f, 5.25f);
		glVertex3f(-10.1f, 99.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 94.0f, -9.0f);
		glVertex3f(-10.1f, 90.0f, -9.0f);
		glVertex3f(-10.1f, 90.0f, -5.25f);
		glVertex3f(-10.1f, 94.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 94.0f, -4.25f);
		glVertex3f(-10.1f, 90.0f, -4.25f);
		glVertex3f(-10.1f, 90.0f, -0.5f);
		glVertex3f(-10.1f, 94.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 94.0f, 0.5f);
		glVertex3f(-10.1f, 90.0f, 0.5f);
		glVertex3f(-10.1f, 90.0f, 4.25f);
		glVertex3f(-10.1f, 94.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 94.0f, 5.250f);
		glVertex3f(-10.1f, 90.0f, 5.25f);
		glVertex3f(-10.1f, 90.0f, 9.0f);
		glVertex3f(-10.1f, 94.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 94.0f, 9.0f);
		glVertex3f(-10.1f, 90.0f, 9.0f);
		glVertex3f(-10.1f, 90.0f, 5.25f);
		glVertex3f(-10.1f, 94.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 89.0f, -9.0f);
		glVertex3f(-10.1f, 85.0f, -9.0f);
		glVertex3f(-10.1f, 85.0f, -5.25f);
		glVertex3f(-10.1f, 89.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 89.0f, -4.25f);
		glVertex3f(-10.1f, 85.0f, -4.25f);
		glVertex3f(-10.1f, 85.0f, -0.5f);
		glVertex3f(-10.1f, 89.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 89.0f, 0.5f);
		glVertex3f(-10.1f, 85.0f, 0.5f);
		glVertex3f(-10.1f, 85.0f, 4.25f);
		glVertex3f(-10.1f, 89.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 89.0f, 5.250f);
		glVertex3f(-10.1f, 85.0f, 5.25f);
		glVertex3f(-10.1f, 85.0f, 9.0f);
		glVertex3f(-10.1f, 89.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 89.0f, 9.0f);
		glVertex3f(-10.1f, 85.0f, 9.0f);
		glVertex3f(-10.1f, 85.0f, 5.25f);
		glVertex3f(-10.1f, 89.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 84.0f, -9.0f);
		glVertex3f(-10.1f, 80.0f, -9.0f);
		glVertex3f(-10.1f, 80.0f, -5.25f);
		glVertex3f(-10.1f, 84.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 84.0f, -4.25f);
		glVertex3f(-10.1f, 80.0f, -4.25f);
		glVertex3f(-10.1f, 80.0f, -0.5f);
		glVertex3f(-10.1f, 84.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 84.0f, 0.5f);
		glVertex3f(-10.1f, 80.0f, 0.5f);
		glVertex3f(-10.1f, 80.0f, 4.25f);
		glVertex3f(-10.1f, 84.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 84.0f, 5.250f);
		glVertex3f(-10.1f, 80.0f, 5.25f);
		glVertex3f(-10.1f, 80.0f, 9.0f);
		glVertex3f(-10.1f, 84.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 84.0f, 9.0f);
		glVertex3f(-10.1f, 80.0f, 9.0f);
		glVertex3f(-10.1f, 80.0f, 5.25f);
		glVertex3f(-10.1f, 84.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 79.0f, -9.0f);
		glVertex3f(-10.1f, 75.0f, -9.0f);
		glVertex3f(-10.1f, 75.0f, -5.25f);
		glVertex3f(-10.1f, 79.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 79.0f, -4.25f);
		glVertex3f(-10.1f, 75.0f, -4.25f);
		glVertex3f(-10.1f, 75.0f, -0.5f);
		glVertex3f(-10.1f, 79.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 79.0f, 0.5f);
		glVertex3f(-10.1f, 75.0f, 0.5f);
		glVertex3f(-10.1f, 75.0f, 4.25f);
		glVertex3f(-10.1f, 79.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 79.0f, 5.250f);
		glVertex3f(-10.1f, 75.0f, 5.25f);
		glVertex3f(-10.1f, 75.0f, 9.0f);
		glVertex3f(-10.1f, 79.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 79.0f, 9.0f);
		glVertex3f(-10.1f, 75.0f, 9.0f);
		glVertex3f(-10.1f, 75.0f, 5.25f);
		glVertex3f(-10.1f, 79.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 74.0f, -9.0f);
		glVertex3f(-10.1f, 70.0f, -9.0f);
		glVertex3f(-10.1f, 70.0f, -5.25f);
		glVertex3f(-10.1f, 74.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 74.0f, -4.25f);
		glVertex3f(-10.1f, 70.0f, -4.25f);
		glVertex3f(-10.1f, 70.0f, -0.5f);
		glVertex3f(-10.1f, 74.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 74.0f, 0.5f);
		glVertex3f(-10.1f, 70.0f, 0.5f);
		glVertex3f(-10.1f, 70.0f, 4.25f);
		glVertex3f(-10.1f, 74.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 74.0f, 5.250f);
		glVertex3f(-10.1f, 70.0f, 5.25f);
		glVertex3f(-10.1f, 70.0f, 9.0f);
		glVertex3f(-10.1f, 74.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 74.0f, 9.0f);
		glVertex3f(-10.1f, 70.0f, 9.0f);
		glVertex3f(-10.1f, 70.0f, 5.25f);
		glVertex3f(-10.1f, 74.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 69.0f, -9.0f);
		glVertex3f(-10.1f, 65.0f, -9.0f);
		glVertex3f(-10.1f, 65.0f, -5.25f);
		glVertex3f(-10.1f, 69.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 69.0f, -4.25f);
		glVertex3f(-10.1f, 65.0f, -4.25f);
		glVertex3f(-10.1f, 65.0f, -0.5f);
		glVertex3f(-10.1f, 69.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 69.0f, 0.5f);
		glVertex3f(-10.1f, 65.0f, 0.5f);
		glVertex3f(-10.1f, 65.0f, 4.25f);
		glVertex3f(-10.1f, 69.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 69.0f, 5.250f);
		glVertex3f(-10.1f, 65.0f, 5.25f);
		glVertex3f(-10.1f, 65.0f, 9.0f);
		glVertex3f(-10.1f, 69.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 69.0f, 9.0f);
		glVertex3f(-10.1f, 65.0f, 9.0f);
		glVertex3f(-10.1f, 65.0f, 5.25f);
		glVertex3f(-10.1f, 69.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 64.0f, -9.0f);
		glVertex3f(-10.1f, 60.0f, -9.0f);
		glVertex3f(-10.1f, 60.0f, -5.25f);
		glVertex3f(-10.1f, 64.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 64.0f, -4.25f);
		glVertex3f(-10.1f, 60.0f, -4.25f);
		glVertex3f(-10.1f, 60.0f, -0.5f);
		glVertex3f(-10.1f, 64.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 64.0f, 0.5f);
		glVertex3f(-10.1f, 60.0f, 0.5f);
		glVertex3f(-10.1f, 60.0f, 4.25f);
		glVertex3f(-10.1f, 64.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 64.0f, 5.250f);
		glVertex3f(-10.1f, 60.0f, 5.25f);
		glVertex3f(-10.1f, 60.0f, 9.0f);
		glVertex3f(-10.1f, 64.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 64.0f, 9.0f);
		glVertex3f(-10.1f, 60.0f, 9.0f);
		glVertex3f(-10.1f, 60.0f, 5.25f);
		glVertex3f(-10.1f, 64.0f, 5.25f);
		glEnd();

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 59.0f, -9.0f);
		glVertex3f(-10.1f, 55.0f, -9.0f);
		glVertex3f(-10.1f, 55.0f, -5.25f);
		glVertex3f(-10.1f, 59.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 59.0f, -4.25f);
		glVertex3f(-10.1f, 55.0f, -4.25f);
		glVertex3f(-10.1f, 55.0f, -0.5f);
		glVertex3f(-10.1f, 59.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 59.0f, 0.5f);
		glVertex3f(-10.1f, 55.0f, 0.5f);
		glVertex3f(-10.1f, 55.0f, 4.25f);
		glVertex3f(-10.1f, 59.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 59.0f, 5.250f);
		glVertex3f(-10.1f, 55.0f, 5.25f);
		glVertex3f(-10.1f, 55.0f, 9.0f);
		glVertex3f(-10.1f, 59.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 59.0f, 9.0f);
		glVertex3f(-10.1f, 55.0f, 9.0f);
		glVertex3f(-10.1f, 55.0f, 5.25f);
		glVertex3f(-10.1f, 59.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 54.0f, -9.0f);
		glVertex3f(-10.1f, 50.0f, -9.0f);
		glVertex3f(-10.1f, 50.0f, -5.25f);
		glVertex3f(-10.1f, 54.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 54.0f, -4.25f);
		glVertex3f(-10.1f, 50.0f, -4.25f);
		glVertex3f(-10.1f, 50.0f, -0.5f);
		glVertex3f(-10.1f, 54.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 54.0f, 0.5f);
		glVertex3f(-10.1f, 50.0f, 0.5f);
		glVertex3f(-10.1f, 50.0f, 4.25f);
		glVertex3f(-10.1f, 54.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 54.0f, 5.250f);
		glVertex3f(-10.1f, 50.0f, 5.25f);
		glVertex3f(-10.1f, 50.0f, 9.0f);
		glVertex3f(-10.1f, 54.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 54.0f, 9.0f);
		glVertex3f(-10.1f, 50.0f, 9.0f);
		glVertex3f(-10.1f, 50.0f, 5.25f);
		glVertex3f(-10.1f, 54.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 49.0f, -9.0f);
		glVertex3f(-10.1f, 45.0f, -9.0f);
		glVertex3f(-10.1f, 45.0f, -5.25f);
		glVertex3f(-10.1f, 49.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 49.0f, -4.25f);
		glVertex3f(-10.1f, 45.0f, -4.25f);
		glVertex3f(-10.1f, 45.0f, -0.5f);
		glVertex3f(-10.1f, 49.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 49.0f, 0.5f);
		glVertex3f(-10.1f, 45.0f, 0.5f);
		glVertex3f(-10.1f, 45.0f, 4.25f);
		glVertex3f(-10.1f, 49.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 49.0f, 5.250f);
		glVertex3f(-10.1f, 45.0f, 5.25f);
		glVertex3f(-10.1f, 45.0f, 9.0f);
		glVertex3f(-10.1f, 49.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 49.0f, 9.0f);
		glVertex3f(-10.1f, 45.0f, 9.0f);
		glVertex3f(-10.1f, 45.0f, 5.25f);
		glVertex3f(-10.1f, 49.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 44.0f, -9.0f);
		glVertex3f(-10.1f, 40.0f, -9.0f);
		glVertex3f(-10.1f, 40.0f, -5.25f);
		glVertex3f(-10.1f, 44.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 44.0f, -4.25f);
		glVertex3f(-10.1f, 40.0f, -4.25f);
		glVertex3f(-10.1f, 40.0f, -0.5f);
		glVertex3f(-10.1f, 44.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 44.0f, 0.5f);
		glVertex3f(-10.1f, 40.0f, 0.5f);
		glVertex3f(-10.1f, 40.0f, 4.25f);
		glVertex3f(-10.1f, 44.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 44.0f, 5.250f);
		glVertex3f(-10.1f, 40.0f, 5.25f);
		glVertex3f(-10.1f, 40.0f, 9.0f);
		glVertex3f(-10.1f, 44.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 44.0f, 9.0f);
		glVertex3f(-10.1f, 40.0f, 9.0f);
		glVertex3f(-10.1f, 40.0f, 5.25f);
		glVertex3f(-10.1f, 44.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 39.0f, -9.0f);
		glVertex3f(-10.1f, 35.0f, -9.0f);
		glVertex3f(-10.1f, 35.0f, -5.25f);
		glVertex3f(-10.1f, 39.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 39.0f, -4.25f);
		glVertex3f(-10.1f, 35.0f, -4.25f);
		glVertex3f(-10.1f, 35.0f, -0.5f);
		glVertex3f(-10.1f, 39.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 39.0f, 0.5f);
		glVertex3f(-10.1f, 35.0f, 0.5f);
		glVertex3f(-10.1f, 35.0f, 4.25f);
		glVertex3f(-10.1f, 39.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 39.0f, 5.250f);
		glVertex3f(-10.1f, 35.0f, 5.25f);
		glVertex3f(-10.1f, 35.0f, 9.0f);
		glVertex3f(-10.1f, 39.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 39.0f, 9.0f);
		glVertex3f(-10.1f, 35.0f, 9.0f);
		glVertex3f(-10.1f, 35.0f, 5.25f);
		glVertex3f(-10.1f, 39.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 34.0f, -9.0f);
		glVertex3f(-10.1f, 30.0f, -9.0f);
		glVertex3f(-10.1f, 30.0f, -5.25f);
		glVertex3f(-10.1f, 34.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 34.0f, -4.25f);
		glVertex3f(-10.1f, 30.0f, -4.25f);
		glVertex3f(-10.1f, 30.0f, -0.5f);
		glVertex3f(-10.1f, 34.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 34.0f, 0.5f);
		glVertex3f(-10.1f, 30.0f, 0.5f);
		glVertex3f(-10.1f, 30.0f, 4.25f);
		glVertex3f(-10.1f, 34.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 34.0f, 5.250f);
		glVertex3f(-10.1f, 30.0f, 5.25f);
		glVertex3f(-10.1f, 30.0f, 9.0f);
		glVertex3f(-10.1f, 34.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 34.0f, 9.0f);
		glVertex3f(-10.1f, 30.0f, 9.0f);
		glVertex3f(-10.1f, 30.0f, 5.25f);
		glVertex3f(-10.1f, 34.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 29.0f, -9.0f);
		glVertex3f(-10.1f, 25.0f, -9.0f);
		glVertex3f(-10.1f, 25.0f, -5.25f);
		glVertex3f(-10.1f, 29.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 29.0f, -4.25f);
		glVertex3f(-10.1f, 25.0f, -4.25f);
		glVertex3f(-10.1f, 25.0f, -0.5f);
		glVertex3f(-10.1f, 29.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 29.0f, 0.5f);
		glVertex3f(-10.1f, 25.0f, 0.5f);
		glVertex3f(-10.1f, 25.0f, 4.25f);
		glVertex3f(-10.1f, 29.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 29.0f, 5.250f);
		glVertex3f(-10.1f, 25.0f, 5.25f);
		glVertex3f(-10.1f, 25.0f, 9.0f);
		glVertex3f(-10.1f, 29.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 29.0f, 9.0f);
		glVertex3f(-10.1f, 25.0f, 9.0f);
		glVertex3f(-10.1f, 25.0f, 5.25f);
		glVertex3f(-10.1f, 29.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 24.0f, -9.0f);
		glVertex3f(-10.1f, 20.0f, -9.0f);
		glVertex3f(-10.1f, 20.0f, -5.25f);
		glVertex3f(-10.1f, 24.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 24.0f, -4.25f);
		glVertex3f(-10.1f, 20.0f, -4.25f);
		glVertex3f(-10.1f, 20.0f, -0.5f);
		glVertex3f(-10.1f, 24.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 24.0f, 0.5f);
		glVertex3f(-10.1f, 20.0f, 0.5f);
		glVertex3f(-10.1f, 20.0f, 4.25f);
		glVertex3f(-10.1f, 24.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 24.0f, 5.250f);
		glVertex3f(-10.1f, 20.0f, 5.25f);
		glVertex3f(-10.1f, 20.0f, 9.0f);
		glVertex3f(-10.1f, 24.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 24.0f, 9.0f);
		glVertex3f(-10.1f, 20.0f, 9.0f);
		glVertex3f(-10.1f, 20.0f, 5.25f);
		glVertex3f(-10.1f, 24.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 19.0f, -9.0f);
		glVertex3f(-10.1f, 15.0f, -9.0f);
		glVertex3f(-10.1f, 15.0f, -5.25f);
		glVertex3f(-10.1f, 19.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 19.0f, -4.25f);
		glVertex3f(-10.1f, 15.0f, -4.25f);
		glVertex3f(-10.1f, 15.0f, -0.5f);
		glVertex3f(-10.1f, 19.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 19.0f, 0.5f);
		glVertex3f(-10.1f, 15.0f, 0.5f);
		glVertex3f(-10.1f, 15.0f, 4.25f);
		glVertex3f(-10.1f, 19.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 19.0f, 5.250f);
		glVertex3f(-10.1f, 15.0f, 5.25f);
		glVertex3f(-10.1f, 15.0f, 9.0f);
		glVertex3f(-10.1f, 19.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 19.0f, 9.0f);
		glVertex3f(-10.1f, 15.0f, 9.0f);
		glVertex3f(-10.1f, 15.0f, 5.25f);
		glVertex3f(-10.1f, 19.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 14.0f, -9.0f);
		glVertex3f(-10.1f, 10.0f, -9.0f);
		glVertex3f(-10.1f, 10.0f, -5.25f);
		glVertex3f(-10.1f, 14.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 14.0f, -4.25f);
		glVertex3f(-10.1f, 10.0f, -4.25f);
		glVertex3f(-10.1f, 10.0f, -0.5f);
		glVertex3f(-10.1f, 14.0f, -0.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 14.0f, 0.5f);
		glVertex3f(-10.1f, 10.0f, 0.5f);
		glVertex3f(-10.1f, 10.0f, 4.25f);
		glVertex3f(-10.1f, 14.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 14.0f, 5.250f);
		glVertex3f(-10.1f, 10.0f, 5.25f);
		glVertex3f(-10.1f, 10.0f, 9.0f);
		glVertex3f(-10.1f, 14.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 14.0f, 9.0f);
		glVertex3f(-10.1f, 10.0f, 9.0f);
		glVertex3f(-10.1f, 10.0f, 5.25f);
		glVertex3f(-10.1f, 14.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 9.0f, -9.0f);
		glVertex3f(-10.1f, 5.0f, -9.0f);
		glVertex3f(-10.1f, 5.0f, -5.25f);
		glVertex3f(-10.1f, 9.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 9.0f, -4.25f);
		glVertex3f(-10.1f, 5.0f, -4.25f);
		glVertex3f(-10.1f, 5.0f, -0.5f);
		glVertex3f(-10.1f, 9.0f, -0.5f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 9.0f, 0.5f);
		glVertex3f(-10.1f, 5.0f, 0.5f);
		glVertex3f(-10.1f, 5.0f, 4.25f);
		glVertex3f(-10.1f, 9.0f, 4.25f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 9.0f, 5.250f);
		glVertex3f(-10.1f, 5.0f, 5.25f);
		glVertex3f(-10.1f, 5.0f, 9.0f);
		glVertex3f(-10.1f, 9.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 9.0f, 9.0f);
		glVertex3f(-10.1f, 5.0f, 9.0f);
		glVertex3f(-10.1f, 5.0f, 5.25f);
		glVertex3f(-10.1f, 9.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 4.0f, -9.0f);
		glVertex3f(-10.1f, 1.0f, -9.0f);
		glVertex3f(-10.1f, 1.0f, -5.25f);
		glVertex3f(-10.1f, 4.0f, -5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 4.0f, -4.25f);
		glVertex3f(-10.1f, 1.0f, -4.25f);
		glVertex3f(-10.1f, 1.0f, -0.5f);
		glVertex3f(-10.1f, 4.0f, -0.5f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 4.0f, 0.5f);
		glVertex3f(-10.1f, 1.0f, 0.5f);
		glVertex3f(-10.1f, 1.0f, 4.25f);
		glVertex3f(-10.1f, 4.0f, 4.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 4.0f, 5.250f);
		glVertex3f(-10.1f, 1.0f, 5.25f);
		glVertex3f(-10.1f, 1.0f, 9.0f);
		glVertex3f(-10.1f, 4.0f, 9.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.5f);
		glBegin(GL_QUADS);
		glVertex3f(-10.1f, 4.0f, 9.0f);
		glVertex3f(-10.1f, 1.0f, 9.0f);
		glVertex3f(-10.1f, 1.0f, 5.25f);
		glVertex3f(-10.1f, 4.0f, 5.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 149.0f, 21.0f);
		glVertex3f(19.9f, 145.0f, 21.0f);
		glVertex3f(19.9f, 145.0f, 24.25f);
		glVertex3f(19.9f, 149.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 149.0f, 25.25f);
		glVertex3f(19.9f, 145.0f, 25.25f);
		glVertex3f(19.9f, 145.0f, 29.5f);
		glVertex3f(19.9f, 149.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 149.0f, 30.5f);
		glVertex3f(19.9f, 145.0f, 30.5f);
		glVertex3f(19.9f, 145.0f, 34.25f);
		glVertex3f(19.9f, 149.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 149.0f, 35.25f);
		glVertex3f(19.9f, 145.0f, 35.25f);
		glVertex3f(19.9f, 145.0f, 39.0f);
		glVertex3f(19.9f, 149.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 149.0f, 39.0f);
		glVertex3f(19.9f, 145.0f, 39.0f);
		glVertex3f(19.9f, 145.0f, 35.25f);
		glVertex3f(19.9f, 149.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 144.0f, 21.0f);
		glVertex3f(19.9f, 140.0f, 21.0f);
		glVertex3f(19.9f, 140.0f, 24.25f);
		glVertex3f(19.9f, 144.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 144.0f, 25.25f);
		glVertex3f(19.9f, 140.0f, 25.25f);
		glVertex3f(19.9f, 140.0f, 29.5f);
		glVertex3f(19.9f, 144.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 144.0f, 30.5f);
		glVertex3f(19.9f, 140.0f, 30.5f);
		glVertex3f(19.9f, 140.0f, 34.25f);
		glVertex3f(19.9f, 144.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 144.0f, 35.25f);
		glVertex3f(19.9f, 140.0f, 35.25f);
		glVertex3f(19.9f, 140.0f, 39.0f);
		glVertex3f(19.9f, 144.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 144.0f, 39.0f);
		glVertex3f(19.9f, 140.0f, 39.0f);
		glVertex3f(19.9f, 140.0f, 35.25f);
		glVertex3f(19.9f, 144.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 149.0f, 21.0f);
		glVertex3f(19.9f, 145.0f, 21.0f);
		glVertex3f(19.9f, 145.0f, 24.25f);
		glVertex3f(19.9f, 149.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 139.0f, 21.0f);
		glVertex3f(19.9f, 135.0f, 21.0f);
		glVertex3f(19.9f, 135.0f, 24.25f);
		glVertex3f(19.9f, 139.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 139.0f, 25.25f);
		glVertex3f(19.9f, 135.0f, 25.25f);
		glVertex3f(19.9f, 135.0f, 29.5f);
		glVertex3f(19.9f, 139.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 139.0f, 30.5f);
		glVertex3f(19.9f, 135.0f, 30.5f);
		glVertex3f(19.9f, 135.0f, 34.25f);
		glVertex3f(19.9f, 139.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 139.0f, 35.25f);
		glVertex3f(19.9f, 135.0f, 35.25f);
		glVertex3f(19.9f, 135.0f, 39.0f);
		glVertex3f(19.9f, 139.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 134.0f, 21.0f);
		glVertex3f(19.9f, 130.0f, 21.0f);
		glVertex3f(19.9f, 130.0f, 24.25f);
		glVertex3f(19.9f, 134.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 134.0f, 25.25f);
		glVertex3f(19.9f, 130.0f, 25.25f);
		glVertex3f(19.9f, 130.0f, 29.5f);
		glVertex3f(19.9f, 134.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 134.0f, 30.5f);
		glVertex3f(19.9f, 130.0f, 30.5f);
		glVertex3f(19.9f, 130.0f, 34.25f);
		glVertex3f(19.9f, 134.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 134.0f, 35.25f);
		glVertex3f(19.9f, 130.0f, 35.25f);
		glVertex3f(19.9f, 130.0f, 39.0f);
		glVertex3f(19.9f, 134.0f, 39.0f);
		glEnd();

		/**/
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 129.0f, 21.0f);
		glVertex3f(19.9f, 125.0f, 21.0f);
		glVertex3f(19.9f, 125.0f, 24.25f);
		glVertex3f(19.9f, 129.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 129.0f, 25.25f);
		glVertex3f(19.9f, 125.0f, 25.25f);
		glVertex3f(19.9f, 125.0f, 29.5f);
		glVertex3f(19.9f, 129.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 129.0f, 30.5f);
		glVertex3f(19.9f, 125.0f, 30.5f);
		glVertex3f(19.9f, 125.0f, 34.25f);
		glVertex3f(19.9f, 129.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 129.0f, 35.25f);
		glVertex3f(19.9f, 125.0f, 35.25f);
		glVertex3f(19.9f, 125.0f, 39.0f);
		glVertex3f(19.9f, 129.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 129.0f, 39.0f);
		glVertex3f(19.9f, 125.0f, 39.0f);
		glVertex3f(19.9f, 125.0f, 35.25f);
		glVertex3f(19.9f, 129.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 124.0f, 21.0f);
		glVertex3f(19.9f, 120.0f, 21.0f);
		glVertex3f(19.9f, 120.0f, 24.25f);
		glVertex3f(19.9f, 124.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 124.0f, 25.25f);
		glVertex3f(19.9f, 120.0f, 25.25f);
		glVertex3f(19.9f, 120.0f, 29.5f);
		glVertex3f(19.9f, 124.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 124.0f, 30.5f);
		glVertex3f(19.9f, 120.0f, 30.5f);
		glVertex3f(19.9f, 120.0f, 34.25f);
		glVertex3f(19.9f, 124.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 124.0f, 35.25f);
		glVertex3f(19.9f, 120.0f, 35.25f);
		glVertex3f(19.9f, 120.0f, 39.0f);
		glVertex3f(19.9f, 124.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 124.0f, 39.0f);
		glVertex3f(19.9f, 120.0f, 39.0f);
		glVertex3f(19.9f, 120.0f, 35.25f);
		glVertex3f(19.9f, 124.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 119.0f, 21.0f);
		glVertex3f(19.9f, 115.0f, 21.0f);
		glVertex3f(19.9f, 115.0f, 24.25f);
		glVertex3f(19.9f, 119.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 119.0f, 25.25f);
		glVertex3f(19.9f, 115.0f, 25.25f);
		glVertex3f(19.9f, 115.0f, 29.5f);
		glVertex3f(19.9f, 119.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 119.0f, 30.5f);
		glVertex3f(19.9f, 115.0f, 30.5f);
		glVertex3f(19.9f, 115.0f, 34.25f);
		glVertex3f(19.9f, 119.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 119.0f, 35.25f);
		glVertex3f(19.9f, 115.0f, 35.25f);
		glVertex3f(19.9f, 115.0f, 39.0f);
		glVertex3f(19.9f, 119.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 119.0f, 39.0f);
		glVertex3f(19.9f, 115.0f, 39.0f);
		glVertex3f(19.9f, 115.0f, 35.25f);
		glVertex3f(19.9f, 119.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 114.0f, 21.0f);
		glVertex3f(19.9f, 110.0f, 21.0f);
		glVertex3f(19.9f, 110.0f, 24.25f);
		glVertex3f(19.9f, 114.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 114.0f, 25.25f);
		glVertex3f(19.9f, 110.0f, 25.25f);
		glVertex3f(19.9f, 110.0f, 29.5f);
		glVertex3f(19.9f, 114.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 114.0f, 30.5f);
		glVertex3f(19.9f, 110.0f, 30.5f);
		glVertex3f(19.9f, 110.0f, 34.25f);
		glVertex3f(19.9f, 114.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 114.0f, 35.25f);
		glVertex3f(19.9f, 110.0f, 35.25f);
		glVertex3f(19.9f, 110.0f, 39.0f);
		glVertex3f(19.9f, 114.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 114.0f, 39.0f);
		glVertex3f(19.9f, 110.0f, 39.0f);
		glVertex3f(19.9f, 110.0f, 35.25f);
		glVertex3f(19.9f, 114.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 109.0f, 21.0f);
		glVertex3f(19.9f, 105.0f, 21.0f);
		glVertex3f(19.9f, 105.0f, 24.25f);
		glVertex3f(19.9f, 109.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 109.0f, 25.25f);
		glVertex3f(19.9f, 105.0f, 25.25f);
		glVertex3f(19.9f, 105.0f, 29.5f);
		glVertex3f(19.9f, 109.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 109.0f, 30.5f);
		glVertex3f(19.9f, 105.0f, 30.5f);
		glVertex3f(19.9f, 105.0f, 34.25f);
		glVertex3f(19.9f, 109.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 109.0f, 35.25f);
		glVertex3f(19.9f, 105.0f, 35.25f);
		glVertex3f(19.9f, 105.0f, 39.0f);
		glVertex3f(19.9f, 109.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 109.0f, 39.0f);
		glVertex3f(19.9f, 105.0f, 39.0f);
		glVertex3f(19.9f, 105.0f, 35.25f);
		glVertex3f(19.9f, 109.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 104.0f, 21.0f);
		glVertex3f(19.9f, 100.0f, 21.0f);
		glVertex3f(19.9f, 100.0f, 24.25f);
		glVertex3f(19.9f, 104.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 104.0f, 25.25f);
		glVertex3f(19.9f, 100.0f, 25.25f);
		glVertex3f(19.9f, 100.0f, 29.5f);
		glVertex3f(19.9f, 104.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 104.0f, 30.5f);
		glVertex3f(19.9f, 100.0f, 30.5f);
		glVertex3f(19.9f, 100.0f, 34.25f);
		glVertex3f(19.9f, 104.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 104.0f, 35.25f);
		glVertex3f(19.9f, 100.0f, 35.25f);
		glVertex3f(19.9f, 100.0f, 39.0f);
		glVertex3f(19.9f, 104.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 104.0f, 39.0f);
		glVertex3f(19.9f, 100.0f, 39.0f);
		glVertex3f(19.9f, 100.0f, 35.25f);
		glVertex3f(19.9f, 104.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 99.0f, 21.0f);
		glVertex3f(19.9f, 95.0f, 21.0f);
		glVertex3f(19.9f, 95.0f, 24.25f);
		glVertex3f(19.9f, 99.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 99.0f, 25.25f);
		glVertex3f(19.9f, 95.0f, 25.25f);
		glVertex3f(19.9f, 95.0f, 29.5f);
		glVertex3f(19.9f, 99.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 99.0f, 30.5f);
		glVertex3f(19.9f, 95.0f, 30.5f);
		glVertex3f(19.9f, 95.0f, 34.25f);
		glVertex3f(19.9f, 99.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 99.0f, 35.25f);
		glVertex3f(19.9f, 95.0f, 35.25f);
		glVertex3f(19.9f, 95.0f, 39.0f);
		glVertex3f(19.9f, 99.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 99.0f, 39.0f);
		glVertex3f(19.9f, 95.0f, 39.0f);
		glVertex3f(19.9f, 95.0f, 35.25f);
		glVertex3f(19.9f, 99.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 94.0f, 21.0f);
		glVertex3f(19.9f, 90.0f, 21.0f);
		glVertex3f(19.9f, 90.0f, 24.25f);
		glVertex3f(19.9f, 94.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 94.0f, 25.25f);
		glVertex3f(19.9f, 90.0f, 25.25f);
		glVertex3f(19.9f, 90.0f, 29.5f);
		glVertex3f(19.9f, 94.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 94.0f, 30.5f);
		glVertex3f(19.9f, 90.0f, 30.5f);
		glVertex3f(19.9f, 90.0f, 34.25f);
		glVertex3f(19.9f, 94.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 94.0f, 35.25f);
		glVertex3f(19.9f, 90.0f, 35.25f);
		glVertex3f(19.9f, 90.0f, 39.0f);
		glVertex3f(19.9f, 94.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 94.0f, 39.0f);
		glVertex3f(19.9f, 90.0f, 39.0f);
		glVertex3f(19.9f, 90.0f, 35.25f);
		glVertex3f(19.9f, 94.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 89.0f, 21.0f);
		glVertex3f(19.9f, 85.0f, 21.0f);
		glVertex3f(19.9f, 85.0f, 24.25f);
		glVertex3f(19.9f, 89.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 89.0f, 25.25f);
		glVertex3f(19.9f, 85.0f, 25.25f);
		glVertex3f(19.9f, 85.0f, 29.5f);
		glVertex3f(19.9f, 89.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 89.0f, 30.5f);
		glVertex3f(19.9f, 85.0f, 30.5f);
		glVertex3f(19.9f, 85.0f, 34.25f);
		glVertex3f(19.9f, 89.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 89.0f, 35.25f);
		glVertex3f(19.9f, 85.0f, 35.25f);
		glVertex3f(19.9f, 85.0f, 39.0f);
		glVertex3f(19.9f, 89.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 89.0f, 39.0f);
		glVertex3f(19.9f, 85.0f, 39.0f);
		glVertex3f(19.9f, 85.0f, 35.25f);
		glVertex3f(19.9f, 89.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 84.0f, 21.0f);
		glVertex3f(19.9f, 80.0f, 21.0f);
		glVertex3f(19.9f, 80.0f, 24.25f);
		glVertex3f(19.9f, 84.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 84.0f, 25.25f);
		glVertex3f(19.9f, 80.0f, 25.25f);
		glVertex3f(19.9f, 80.0f, 29.5f);
		glVertex3f(19.9f, 84.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 84.0f, 30.5f);
		glVertex3f(19.9f, 80.0f, 30.5f);
		glVertex3f(19.9f, 80.0f, 34.25f);
		glVertex3f(19.9f, 84.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 84.0f, 35.25f);
		glVertex3f(19.9f, 80.0f, 35.25f);
		glVertex3f(19.9f, 80.0f, 39.0f);
		glVertex3f(19.9f, 84.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 84.0f, 39.0f);
		glVertex3f(19.9f, 80.0f, 39.0f);
		glVertex3f(19.9f, 80.0f, 35.25f);
		glVertex3f(19.9f, 84.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 79.0f, 21.0f);
		glVertex3f(9.9f, 75.0f, 21.0f);
		glVertex3f(9.9f, 75.0f, 24.25f);
		glVertex3f(9.9f, 79.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 79.0f, 25.25f);
		glVertex3f(9.9f, 75.0f, 25.25f);
		glVertex3f(9.9f, 75.0f, 29.5f);
		glVertex3f(9.9f, 79.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 79.0f, 30.5f);
		glVertex3f(9.9f, 75.0f, 30.5f);
		glVertex3f(9.9f, 75.0f, 34.25f);
		glVertex3f(9.9f, 79.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 79.0f, 35.25f);
		glVertex3f(9.9f, 75.0f, 35.25f);
		glVertex3f(9.9f, 75.0f, 39.0f);
		glVertex3f(9.9f, 79.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 79.0f, 39.0f);
		glVertex3f(9.9f, 75.0f, 39.0f);
		glVertex3f(9.9f, 75.0f, 35.25f);
		glVertex3f(9.9f, 79.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 74.0f, 21.0f);
		glVertex3f(9.9f, 70.0f, 21.0f);
		glVertex3f(9.9f, 70.0f, 24.25f);
		glVertex3f(9.9f, 74.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 74.0f, 25.25f);
		glVertex3f(9.9f, 70.0f, 25.25f);
		glVertex3f(9.9f, 70.0f, 29.5f);
		glVertex3f(9.9f, 74.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 74.0f, 30.5f);
		glVertex3f(9.9f, 70.0f, 30.5f);
		glVertex3f(9.9f, 70.0f, 34.25f);
		glVertex3f(9.9f, 74.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 74.0f, 35.25f);
		glVertex3f(9.9f, 70.0f, 35.25f);
		glVertex3f(9.9f, 70.0f, 39.0f);
		glVertex3f(9.9f, 74.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 74.0f, 39.0f);
		glVertex3f(9.9f, 70.0f, 39.0f);
		glVertex3f(9.9f, 70.0f, 35.25f);
		glVertex3f(9.9f, 74.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 69.0f, 21.0f);
		glVertex3f(9.9f, 65.0f, 21.0f);
		glVertex3f(9.9f, 65.0f, 24.25f);
		glVertex3f(9.9f, 69.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 69.0f, 25.25f);
		glVertex3f(9.9f, 65.0f, 25.25f);
		glVertex3f(9.9f, 65.0f, 29.5f);
		glVertex3f(9.9f, 69.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 69.0f, 30.5f);
		glVertex3f(9.9f, 65.0f, 30.5f);
		glVertex3f(9.9f, 65.0f, 34.25f);
		glVertex3f(9.9f, 69.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 69.0f, 35.25f);
		glVertex3f(9.9f, 65.0f, 35.25f);
		glVertex3f(9.9f, 65.0f, 39.0f);
		glVertex3f(9.9f, 69.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 69.0f, 39.0f);
		glVertex3f(9.9f, 65.0f, 39.0f);
		glVertex3f(9.9f, 65.0f, 35.25f);
		glVertex3f(9.9f, 69.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 64.0f, 21.0f);
		glVertex3f(9.9f, 60.0f, 21.0f);
		glVertex3f(9.9f, 60.0f, 24.25f);
		glVertex3f(9.9f, 64.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 64.0f, 25.25f);
		glVertex3f(9.9f, 60.0f, 25.25f);
		glVertex3f(9.9f, 60.0f, 29.5f);
		glVertex3f(9.9f, 64.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 64.0f, 30.5f);
		glVertex3f(9.9f, 60.0f, 30.5f);
		glVertex3f(9.9f, 60.0f, 34.25f);
		glVertex3f(9.9f, 64.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 64.0f, 35.25f);
		glVertex3f(9.9f, 60.0f, 35.25f);
		glVertex3f(9.9f, 60.0f, 39.0f);
		glVertex3f(9.9f, 64.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(9.9f, 64.0f, 39.0f);
		glVertex3f(9.9f, 60.0f, 39.0f);
		glVertex3f(9.9f, 60.0f, 35.25f);
		glVertex3f(9.9f, 64.0f, 35.25f);
		glEnd();

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 59.0f, 21.0f);
		glVertex3f(19.9f, 55.0f, 21.0f);
		glVertex3f(19.9f, 55.0f, 24.25f);
		glVertex3f(19.9f, 59.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 59.0f, 25.25f);
		glVertex3f(19.9f, 55.0f, 25.25f);
		glVertex3f(19.9f, 55.0f, 29.5f);
		glVertex3f(19.9f, 59.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 59.0f, 30.5f);
		glVertex3f(19.9f, 55.0f, 30.5f);
		glVertex3f(19.9f, 55.0f, 34.25f);
		glVertex3f(19.9f, 59.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 59.0f, 35.25f);
		glVertex3f(19.9f, 55.0f, 35.25f);
		glVertex3f(19.9f, 55.0f, 39.0f);
		glVertex3f(19.9f, 59.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 59.0f, 39.0f);
		glVertex3f(19.9f, 55.0f, 39.0f);
		glVertex3f(19.9f, 55.0f, 35.25f);
		glVertex3f(19.9f, 59.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 54.0f, 21.0f);
		glVertex3f(19.9f, 50.0f, 21.0f);
		glVertex3f(19.9f, 50.0f, 24.25f);
		glVertex3f(19.9f, 54.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 54.0f, 25.25f);
		glVertex3f(19.9f, 50.0f, 25.25f);
		glVertex3f(19.9f, 50.0f, 29.5f);
		glVertex3f(19.9f, 54.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 54.0f, 30.5f);
		glVertex3f(19.9f, 50.0f, 30.5f);
		glVertex3f(19.9f, 50.0f, 34.25f);
		glVertex3f(19.9f, 54.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 54.0f, 35.25f);
		glVertex3f(19.9f, 50.0f, 35.25f);
		glVertex3f(19.9f, 50.0f, 39.0f);
		glVertex3f(19.9f, 54.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 54.0f, 39.0f);
		glVertex3f(19.9f, 50.0f, 39.0f);
		glVertex3f(19.9f, 50.0f, 35.25f);
		glVertex3f(19.9f, 54.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 49.0f, 21.0f);
		glVertex3f(19.9f, 45.0f, 21.0f);
		glVertex3f(19.9f, 45.0f, 24.25f);
		glVertex3f(19.9f, 49.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 49.0f, 25.25f);
		glVertex3f(19.9f, 45.0f, 25.25f);
		glVertex3f(19.9f, 45.0f, 29.5f);
		glVertex3f(19.9f, 49.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 49.0f, 30.5f);
		glVertex3f(19.9f, 45.0f, 30.5f);
		glVertex3f(19.9f, 45.0f, 34.25f);
		glVertex3f(19.9f, 49.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 49.0f, 35.25f);
		glVertex3f(19.9f, 45.0f, 35.25f);
		glVertex3f(19.9f, 45.0f, 39.0f);
		glVertex3f(19.9f, 49.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 49.0f, 39.0f);
		glVertex3f(19.9f, 45.0f, 39.0f);
		glVertex3f(19.9f, 45.0f, 35.25f);
		glVertex3f(19.9f, 49.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 44.0f, 21.0f);
		glVertex3f(19.9f, 40.0f, 21.0f);
		glVertex3f(19.9f, 40.0f, 24.25f);
		glVertex3f(19.9f, 44.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 44.0f, 25.25f);
		glVertex3f(19.9f, 40.0f, 25.25f);
		glVertex3f(19.9f, 40.0f, 29.5f);
		glVertex3f(19.9f, 44.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 44.0f, 30.5f);
		glVertex3f(19.9f, 40.0f, 30.5f);
		glVertex3f(19.9f, 40.0f, 34.25f);
		glVertex3f(19.9f, 44.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 44.0f, 35.25f);
		glVertex3f(19.9f, 40.0f, 35.25f);
		glVertex3f(19.9f, 40.0f, 39.0f);
		glVertex3f(19.9f, 44.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 44.0f, 39.0f);
		glVertex3f(19.9f, 40.0f, 39.0f);
		glVertex3f(19.9f, 40.0f, 35.25f);
		glVertex3f(19.9f, 44.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 39.0f, 21.0f);
		glVertex3f(19.9f, 35.0f, 21.0f);
		glVertex3f(19.9f, 35.0f, 24.25f);
		glVertex3f(19.9f, 39.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 39.0f, 25.25f);
		glVertex3f(19.9f, 35.0f, 25.25f);
		glVertex3f(19.9f, 35.0f, 29.5f);
		glVertex3f(19.9f, 39.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 39.0f, 30.5f);
		glVertex3f(19.9f, 35.0f, 30.5f);
		glVertex3f(19.9f, 35.0f, 34.25f);
		glVertex3f(19.9f, 39.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 39.0f, 35.25f);
		glVertex3f(19.9f, 35.0f, 35.25f);
		glVertex3f(19.9f, 35.0f, 39.0f);
		glVertex3f(19.9f, 39.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 39.0f, 39.0f);
		glVertex3f(19.9f, 35.0f, 39.0f);
		glVertex3f(19.9f, 35.0f, 35.25f);
		glVertex3f(19.9f, 39.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 34.0f, 21.0f);
		glVertex3f(19.9f, 30.0f, 21.0f);
		glVertex3f(19.9f, 30.0f, 24.25f);
		glVertex3f(19.9f, 34.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 34.0f, 25.25f);
		glVertex3f(19.9f, 30.0f, 25.25f);
		glVertex3f(19.9f, 30.0f, 29.5f);
		glVertex3f(19.9f, 34.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 34.0f, 30.5f);
		glVertex3f(19.9f, 30.0f, 30.5f);
		glVertex3f(19.9f, 30.0f, 34.25f);
		glVertex3f(19.9f, 34.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 34.0f, 35.25f);
		glVertex3f(19.9f, 30.0f, 35.25f);
		glVertex3f(19.9f, 30.0f, 39.0f);
		glVertex3f(19.9f, 34.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 34.0f, 39.0f);
		glVertex3f(19.9f, 30.0f, 39.0f);
		glVertex3f(19.9f, 30.0f, 35.25f);
		glVertex3f(19.9f, 34.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 29.0f, 21.0f);
		glVertex3f(19.9f, 25.0f, 21.0f);
		glVertex3f(19.9f, 25.0f, 24.25f);
		glVertex3f(19.9f, 29.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 29.0f, 25.25f);
		glVertex3f(19.9f, 25.0f, 25.25f);
		glVertex3f(19.9f, 25.0f, 29.5f);
		glVertex3f(19.9f, 29.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 29.0f, 30.5f);
		glVertex3f(19.9f, 25.0f, 30.5f);
		glVertex3f(19.9f, 25.0f, 34.25f);
		glVertex3f(19.9f, 29.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 29.0f, 35.25f);
		glVertex3f(19.9f, 25.0f, 35.25f);
		glVertex3f(19.9f, 25.0f, 39.0f);
		glVertex3f(19.9f, 29.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 29.0f, 39.0f);
		glVertex3f(19.9f, 25.0f, 39.0f);
		glVertex3f(19.9f, 25.0f, 35.25f);
		glVertex3f(19.9f, 29.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 24.0f, 21.0f);
		glVertex3f(19.9f, 20.0f, 21.0f);
		glVertex3f(19.9f, 20.0f, 24.25f);
		glVertex3f(19.9f, 24.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 24.0f, 25.25f);
		glVertex3f(19.9f, 20.0f, 25.25f);
		glVertex3f(19.9f, 20.0f, 29.5f);
		glVertex3f(19.9f, 24.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 24.0f, 30.5f);
		glVertex3f(19.9f, 20.0f, 30.5f);
		glVertex3f(19.9f, 20.0f, 34.25f);
		glVertex3f(19.9f, 24.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 24.0f, 35.25f);
		glVertex3f(19.9f, 20.0f, 35.25f);
		glVertex3f(19.9f, 20.0f, 39.0f);
		glVertex3f(19.9f, 24.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 24.0f, 39.0f);
		glVertex3f(19.9f, 20.0f, 39.0f);
		glVertex3f(19.9f, 20.0f, 35.25f);
		glVertex3f(19.9f, 24.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 19.0f, 21.0f);
		glVertex3f(19.9f, 15.0f, 21.0f);
		glVertex3f(19.9f, 15.0f, 24.25f);
		glVertex3f(19.9f, 19.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 19.0f, 25.25f);
		glVertex3f(19.9f, 15.0f, 25.25f);
		glVertex3f(19.9f, 15.0f, 29.5f);
		glVertex3f(19.9f, 19.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 19.0f, 30.5f);
		glVertex3f(19.9f, 15.0f, 30.5f);
		glVertex3f(19.9f, 15.0f, 34.25f);
		glVertex3f(19.9f, 19.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 19.0f, 35.25f);
		glVertex3f(19.9f, 15.0f, 35.25f);
		glVertex3f(19.9f, 15.0f, 39.0f);
		glVertex3f(19.9f, 19.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 19.0f, 39.0f);
		glVertex3f(19.9f, 15.0f, 39.0f);
		glVertex3f(19.9f, 15.0f, 35.25f);
		glVertex3f(19.9f, 19.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 14.0f, 21.0f);
		glVertex3f(19.9f, 10.0f, 21.0f);
		glVertex3f(19.9f, 10.0f, 24.25f);
		glVertex3f(19.9f, 14.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 14.0f, 25.25f);
		glVertex3f(19.9f, 10.0f, 25.25f);
		glVertex3f(19.9f, 10.0f, 29.5f);
		glVertex3f(19.9f, 14.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 14.0f, 30.5f);
		glVertex3f(19.9f, 10.0f, 30.5f);
		glVertex3f(19.9f, 10.0f, 34.25f);
		glVertex3f(19.9f, 14.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 14.0f, 35.25f);
		glVertex3f(19.9f, 10.0f, 35.25f);
		glVertex3f(19.9f, 10.0f, 39.0f);
		glVertex3f(19.9f, 14.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 14.0f, 39.0f);
		glVertex3f(19.9f, 10.0f, 39.0f);
		glVertex3f(19.9f, 10.0f, 35.25f);
		glVertex3f(19.9f, 14.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 9.0f, 21.0f);
		glVertex3f(19.9f, 5.0f, 21.0f);
		glVertex3f(19.9f, 5.0f, 24.25f);
		glVertex3f(19.9f, 9.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 9.0f, 25.25f);
		glVertex3f(19.9f, 5.0f, 25.25f);
		glVertex3f(19.9f, 5.0f, 29.5f);
		glVertex3f(19.9f, 9.0f, 29.5f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 9.0f, 30.5f);
		glVertex3f(19.9f, 5.0f, 30.5f);
		glVertex3f(19.9f, 5.0f, 34.25f);
		glVertex3f(19.9f, 9.0f, 34.25f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 9.0f, 35.25f);
		glVertex3f(19.9f, 5.0f, 35.25f);
		glVertex3f(19.9f, 5.0f, 39.0f);
		glVertex3f(19.9f, 9.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 9.0f, 39.0f);
		glVertex3f(19.9f, 5.0f, 39.0f);
		glVertex3f(19.9f, 5.0f, 35.25f);
		glVertex3f(19.9f, 9.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 4.0f, 21.0f);
		glVertex3f(19.9f, 1.0f, 21.0f);
		glVertex3f(19.9f, 1.0f, 24.25f);
		glVertex3f(19.9f, 4.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 4.0f, 25.25f);
		glVertex3f(19.9f, 1.0f, 25.25f);
		glVertex3f(19.9f, 1.0f, 29.5f);
		glVertex3f(19.9f, 4.0f, 29.5f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 4.0f, 30.5f);
		glVertex3f(19.9f, 1.0f, 30.5f);
		glVertex3f(19.9f, 1.0f, 34.25f);
		glVertex3f(19.9f, 4.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 4.0f, 35.25f);
		glVertex3f(19.9f, 1.0f, 35.25f);
		glVertex3f(19.9f, 1.0f, 39.0f);
		glVertex3f(19.9f, 4.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(19.9f, 4.0f, 39.0f);
		glVertex3f(19.9f, 1.0f, 39.0f);
		glVertex3f(19.9f, 1.0f, 35.25f);
		glVertex3f(19.9f, 4.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 149.0f, 21.0f);
		glVertex3f(40.1f, 145.0f, 21.0f);
		glVertex3f(40.1f, 145.0f, 24.25f);
		glVertex3f(40.1f, 149.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 149.0f, 25.25f);
		glVertex3f(40.1f, 145.0f, 25.25f);
		glVertex3f(40.1f, 145.0f, 29.5f);
		glVertex3f(40.1f, 149.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 149.0f, 30.5f);
		glVertex3f(40.1f, 145.0f, 30.5f);
		glVertex3f(40.1f, 145.0f, 34.25f);
		glVertex3f(40.1f, 149.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 149.0f, 35.25f);
		glVertex3f(40.1f, 145.0f, 35.25f);
		glVertex3f(40.1f, 145.0f, 39.0f);
		glVertex3f(40.1f, 149.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 149.0f, 39.0f);
		glVertex3f(40.1f, 145.0f, 39.0f);
		glVertex3f(40.1f, 145.0f, 35.25f);
		glVertex3f(40.1f, 149.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 144.0f, 21.0f);
		glVertex3f(40.1f, 140.0f, 21.0f);
		glVertex3f(40.1f, 140.0f, 24.25f);
		glVertex3f(40.1f, 144.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 144.0f, 25.25f);
		glVertex3f(40.1f, 140.0f, 25.25f);
		glVertex3f(40.1f, 140.0f, 29.5f);
		glVertex3f(40.1f, 144.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 144.0f, 30.5f);
		glVertex3f(40.1f, 140.0f, 30.5f);
		glVertex3f(40.1f, 140.0f, 34.25f);
		glVertex3f(40.1f, 144.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 144.0f, 35.25f);
		glVertex3f(40.1f, 140.0f, 35.25f);
		glVertex3f(40.1f, 140.0f, 39.0f);
		glVertex3f(40.1f, 144.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 144.0f, 39.0f);
		glVertex3f(40.1f, 140.0f, 39.0f);
		glVertex3f(40.1f, 140.0f, 35.25f);
		glVertex3f(40.1f, 144.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 149.0f, 21.0f);
		glVertex3f(40.1f, 145.0f, 21.0f);
		glVertex3f(40.1f, 145.0f, 24.25f);
		glVertex3f(40.1f, 149.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 139.0f, 21.0f);
		glVertex3f(40.1f, 135.0f, 21.0f);
		glVertex3f(40.1f, 135.0f, 24.25f);
		glVertex3f(40.1f, 139.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 139.0f, 25.25f);
		glVertex3f(40.1f, 135.0f, 25.25f);
		glVertex3f(40.1f, 135.0f, 29.5f);
		glVertex3f(40.1f, 139.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 139.0f, 30.5f);
		glVertex3f(40.1f, 135.0f, 30.5f);
		glVertex3f(40.1f, 135.0f, 34.25f);
		glVertex3f(40.1f, 139.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 139.0f, 35.25f);
		glVertex3f(40.1f, 135.0f, 35.25f);
		glVertex3f(40.1f, 135.0f, 39.0f);
		glVertex3f(40.1f, 139.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 134.0f, 21.0f);
		glVertex3f(40.1f, 130.0f, 21.0f);
		glVertex3f(40.1f, 130.0f, 24.25f);
		glVertex3f(40.1f, 134.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 134.0f, 25.25f);
		glVertex3f(40.1f, 130.0f, 25.25f);
		glVertex3f(40.1f, 130.0f, 29.5f);
		glVertex3f(40.1f, 134.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 134.0f, 30.5f);
		glVertex3f(40.1f, 130.0f, 30.5f);
		glVertex3f(40.1f, 130.0f, 34.25f);
		glVertex3f(40.1f, 134.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 134.0f, 35.25f);
		glVertex3f(40.1f, 130.0f, 35.25f);
		glVertex3f(40.1f, 130.0f, 39.0f);
		glVertex3f(40.1f, 134.0f, 39.0f);
		glEnd();

		/**/
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 129.0f, 21.0f);
		glVertex3f(40.1f, 125.0f, 21.0f);
		glVertex3f(40.1f, 125.0f, 24.25f);
		glVertex3f(40.1f, 129.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 129.0f, 25.25f);
		glVertex3f(40.1f, 125.0f, 25.25f);
		glVertex3f(40.1f, 125.0f, 29.5f);
		glVertex3f(40.1f, 129.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 129.0f, 30.5f);
		glVertex3f(40.1f, 125.0f, 30.5f);
		glVertex3f(40.1f, 125.0f, 34.25f);
		glVertex3f(40.1f, 129.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 129.0f, 35.25f);
		glVertex3f(40.1f, 125.0f, 35.25f);
		glVertex3f(40.1f, 125.0f, 39.0f);
		glVertex3f(40.1f, 129.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 129.0f, 39.0f);
		glVertex3f(40.1f, 125.0f, 39.0f);
		glVertex3f(40.1f, 125.0f, 35.25f);
		glVertex3f(40.1f, 129.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 124.0f, 21.0f);
		glVertex3f(40.1f, 120.0f, 21.0f);
		glVertex3f(40.1f, 120.0f, 24.25f);
		glVertex3f(40.1f, 124.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 124.0f, 25.25f);
		glVertex3f(40.1f, 120.0f, 25.25f);
		glVertex3f(40.1f, 120.0f, 29.5f);
		glVertex3f(40.1f, 124.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 124.0f, 30.5f);
		glVertex3f(40.1f, 120.0f, 30.5f);
		glVertex3f(40.1f, 120.0f, 34.25f);
		glVertex3f(40.1f, 124.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 124.0f, 35.25f);
		glVertex3f(40.1f, 120.0f, 35.25f);
		glVertex3f(40.1f, 120.0f, 39.0f);
		glVertex3f(40.1f, 124.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 124.0f, 39.0f);
		glVertex3f(40.1f, 120.0f, 39.0f);
		glVertex3f(40.1f, 120.0f, 35.25f);
		glVertex3f(40.1f, 124.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 119.0f, 21.0f);
		glVertex3f(40.1f, 115.0f, 21.0f);
		glVertex3f(40.1f, 115.0f, 24.25f);
		glVertex3f(40.1f, 119.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 119.0f, 25.25f);
		glVertex3f(40.1f, 115.0f, 25.25f);
		glVertex3f(40.1f, 115.0f, 29.5f);
		glVertex3f(40.1f, 119.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 119.0f, 30.5f);
		glVertex3f(40.1f, 115.0f, 30.5f);
		glVertex3f(40.1f, 115.0f, 34.25f);
		glVertex3f(40.1f, 119.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 119.0f, 35.25f);
		glVertex3f(40.1f, 115.0f, 35.25f);
		glVertex3f(40.1f, 115.0f, 39.0f);
		glVertex3f(40.1f, 119.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 119.0f, 39.0f);
		glVertex3f(40.1f, 115.0f, 39.0f);
		glVertex3f(40.1f, 115.0f, 35.25f);
		glVertex3f(40.1f, 119.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 114.0f, 21.0f);
		glVertex3f(40.1f, 110.0f, 21.0f);
		glVertex3f(40.1f, 110.0f, 24.25f);
		glVertex3f(40.1f, 114.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 114.0f, 25.25f);
		glVertex3f(40.1f, 110.0f, 25.25f);
		glVertex3f(40.1f, 110.0f, 29.5f);
		glVertex3f(40.1f, 114.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 114.0f, 30.5f);
		glVertex3f(40.1f, 110.0f, 30.5f);
		glVertex3f(40.1f, 110.0f, 34.25f);
		glVertex3f(40.1f, 114.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 114.0f, 35.25f);
		glVertex3f(40.1f, 110.0f, 35.25f);
		glVertex3f(40.1f, 110.0f, 39.0f);
		glVertex3f(40.1f, 114.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 114.0f, 39.0f);
		glVertex3f(40.1f, 110.0f, 39.0f);
		glVertex3f(40.1f, 110.0f, 35.25f);
		glVertex3f(40.1f, 114.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 109.0f, 21.0f);
		glVertex3f(40.1f, 105.0f, 21.0f);
		glVertex3f(40.1f, 105.0f, 24.25f);
		glVertex3f(40.1f, 109.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 109.0f, 25.25f);
		glVertex3f(40.1f, 105.0f, 25.25f);
		glVertex3f(40.1f, 105.0f, 29.5f);
		glVertex3f(40.1f, 109.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 109.0f, 30.5f);
		glVertex3f(40.1f, 105.0f, 30.5f);
		glVertex3f(40.1f, 105.0f, 34.25f);
		glVertex3f(40.1f, 109.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 109.0f, 35.25f);
		glVertex3f(40.1f, 105.0f, 35.25f);
		glVertex3f(40.1f, 105.0f, 39.0f);
		glVertex3f(40.1f, 109.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 109.0f, 39.0f);
		glVertex3f(40.1f, 105.0f, 39.0f);
		glVertex3f(40.1f, 105.0f, 35.25f);
		glVertex3f(40.1f, 109.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 104.0f, 21.0f);
		glVertex3f(40.1f, 100.0f, 21.0f);
		glVertex3f(40.1f, 100.0f, 24.25f);
		glVertex3f(40.1f, 104.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 104.0f, 25.25f);
		glVertex3f(40.1f, 100.0f, 25.25f);
		glVertex3f(40.1f, 100.0f, 29.5f);
		glVertex3f(40.1f, 104.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 104.0f, 30.5f);
		glVertex3f(40.1f, 100.0f, 30.5f);
		glVertex3f(40.1f, 100.0f, 34.25f);
		glVertex3f(40.1f, 104.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 104.0f, 35.25f);
		glVertex3f(40.1f, 100.0f, 35.25f);
		glVertex3f(40.1f, 100.0f, 39.0f);
		glVertex3f(40.1f, 104.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 104.0f, 39.0f);
		glVertex3f(40.1f, 100.0f, 39.0f);
		glVertex3f(40.1f, 100.0f, 35.25f);
		glVertex3f(40.1f, 104.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 99.0f, 21.0f);
		glVertex3f(40.1f, 95.0f, 21.0f);
		glVertex3f(40.1f, 95.0f, 24.25f);
		glVertex3f(40.1f, 99.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 99.0f, 25.25f);
		glVertex3f(40.1f, 95.0f, 25.25f);
		glVertex3f(40.1f, 95.0f, 29.5f);
		glVertex3f(40.1f, 99.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 99.0f, 30.5f);
		glVertex3f(40.1f, 95.0f, 30.5f);
		glVertex3f(40.1f, 95.0f, 34.25f);
		glVertex3f(40.1f, 99.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 99.0f, 35.25f);
		glVertex3f(40.1f, 95.0f, 35.25f);
		glVertex3f(40.1f, 95.0f, 39.0f);
		glVertex3f(40.1f, 99.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 99.0f, 39.0f);
		glVertex3f(40.1f, 95.0f, 39.0f);
		glVertex3f(40.1f, 95.0f, 35.25f);
		glVertex3f(40.1f, 99.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 94.0f, 21.0f);
		glVertex3f(40.1f, 90.0f, 21.0f);
		glVertex3f(40.1f, 90.0f, 24.25f);
		glVertex3f(40.1f, 94.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 94.0f, 25.25f);
		glVertex3f(40.1f, 90.0f, 25.25f);
		glVertex3f(40.1f, 90.0f, 29.5f);
		glVertex3f(40.1f, 94.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 94.0f, 30.5f);
		glVertex3f(40.1f, 90.0f, 30.5f);
		glVertex3f(40.1f, 90.0f, 34.25f);
		glVertex3f(40.1f, 94.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 94.0f, 35.25f);
		glVertex3f(40.1f, 90.0f, 35.25f);
		glVertex3f(40.1f, 90.0f, 39.0f);
		glVertex3f(40.1f, 94.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 94.0f, 39.0f);
		glVertex3f(40.1f, 90.0f, 39.0f);
		glVertex3f(40.1f, 90.0f, 35.25f);
		glVertex3f(40.1f, 94.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 89.0f, 21.0f);
		glVertex3f(40.1f, 85.0f, 21.0f);
		glVertex3f(40.1f, 85.0f, 24.25f);
		glVertex3f(40.1f, 89.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 89.0f, 25.25f);
		glVertex3f(40.1f, 85.0f, 25.25f);
		glVertex3f(40.1f, 85.0f, 29.5f);
		glVertex3f(40.1f, 89.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 89.0f, 30.5f);
		glVertex3f(40.1f, 85.0f, 30.5f);
		glVertex3f(40.1f, 85.0f, 34.25f);
		glVertex3f(40.1f, 89.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 89.0f, 35.25f);
		glVertex3f(40.1f, 85.0f, 35.25f);
		glVertex3f(40.1f, 85.0f, 39.0f);
		glVertex3f(40.1f, 89.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 89.0f, 39.0f);
		glVertex3f(40.1f, 85.0f, 39.0f);
		glVertex3f(40.1f, 85.0f, 35.25f);
		glVertex3f(40.1f, 89.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 84.0f, 21.0f);
		glVertex3f(40.1f, 80.0f, 21.0f);
		glVertex3f(40.1f, 80.0f, 24.25f);
		glVertex3f(40.1f, 84.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 84.0f, 25.25f);
		glVertex3f(40.1f, 80.0f, 25.25f);
		glVertex3f(40.1f, 80.0f, 29.5f);
		glVertex3f(40.1f, 84.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 84.0f, 30.5f);
		glVertex3f(40.1f, 80.0f, 30.5f);
		glVertex3f(40.1f, 80.0f, 34.25f);
		glVertex3f(40.1f, 84.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 84.0f, 35.25f);
		glVertex3f(40.1f, 80.0f, 35.25f);
		glVertex3f(40.1f, 80.0f, 39.0f);
		glVertex3f(40.1f, 84.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 84.0f, 39.0f);
		glVertex3f(40.1f, 80.0f, 39.0f);
		glVertex3f(40.1f, 80.0f, 35.25f);
		glVertex3f(40.1f, 84.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 79.0f, 21.0f);
		glVertex3f(40.1f, 75.0f, 21.0f);
		glVertex3f(40.1f, 75.0f, 24.25f);
		glVertex3f(40.1f, 79.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 79.0f, 25.25f);
		glVertex3f(40.1f, 75.0f, 25.25f);
		glVertex3f(40.1f, 75.0f, 29.5f);
		glVertex3f(40.1f, 79.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 79.0f, 30.5f);
		glVertex3f(40.1f, 75.0f, 30.5f);
		glVertex3f(40.1f, 75.0f, 34.25f);
		glVertex3f(40.1f, 79.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 79.0f, 35.25f);
		glVertex3f(40.1f, 75.0f, 35.25f);
		glVertex3f(40.1f, 75.0f, 39.0f);
		glVertex3f(40.1f, 79.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 79.0f, 39.0f);
		glVertex3f(40.1f, 75.0f, 39.0f);
		glVertex3f(40.1f, 75.0f, 35.25f);
		glVertex3f(40.1f, 79.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 74.0f, 21.0f);
		glVertex3f(40.1f, 70.0f, 21.0f);
		glVertex3f(40.1f, 70.0f, 24.25f);
		glVertex3f(40.1f, 74.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 74.0f, 25.25f);
		glVertex3f(40.1f, 70.0f, 25.25f);
		glVertex3f(40.1f, 70.0f, 29.5f);
		glVertex3f(40.1f, 74.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 74.0f, 30.5f);
		glVertex3f(40.1f, 70.0f, 30.5f);
		glVertex3f(40.1f, 70.0f, 34.25f);
		glVertex3f(40.1f, 74.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 74.0f, 35.25f);
		glVertex3f(40.1f, 70.0f, 35.25f);
		glVertex3f(40.1f, 70.0f, 39.0f);
		glVertex3f(40.1f, 74.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 74.0f, 39.0f);
		glVertex3f(40.1f, 70.0f, 39.0f);
		glVertex3f(40.1f, 70.0f, 35.25f);
		glVertex3f(40.1f, 74.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 69.0f, 21.0f);
		glVertex3f(40.1f, 65.0f, 21.0f);
		glVertex3f(40.1f, 65.0f, 24.25f);
		glVertex3f(40.1f, 69.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 69.0f, 25.25f);
		glVertex3f(40.1f, 65.0f, 25.25f);
		glVertex3f(40.1f, 65.0f, 29.5f);
		glVertex3f(40.1f, 69.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 69.0f, 30.5f);
		glVertex3f(40.1f, 65.0f, 30.5f);
		glVertex3f(40.1f, 65.0f, 34.25f);
		glVertex3f(40.1f, 69.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 69.0f, 35.25f);
		glVertex3f(40.1f, 65.0f, 35.25f);
		glVertex3f(40.1f, 65.0f, 39.0f);
		glVertex3f(40.1f, 69.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 69.0f, 39.0f);
		glVertex3f(40.1f, 65.0f, 39.0f);
		glVertex3f(40.1f, 65.0f, 35.25f);
		glVertex3f(40.1f, 69.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 64.0f, 21.0f);
		glVertex3f(40.1f, 60.0f, 21.0f);
		glVertex3f(40.1f, 60.0f, 24.25f);
		glVertex3f(40.1f, 64.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 64.0f, 25.25f);
		glVertex3f(40.1f, 60.0f, 25.25f);
		glVertex3f(40.1f, 60.0f, 29.5f);
		glVertex3f(40.1f, 64.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 64.0f, 30.5f);
		glVertex3f(40.1f, 60.0f, 30.5f);
		glVertex3f(40.1f, 60.0f, 34.25f);
		glVertex3f(40.1f, 64.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 64.0f, 35.25f);
		glVertex3f(40.1f, 60.0f, 35.25f);
		glVertex3f(40.1f, 60.0f, 39.0f);
		glVertex3f(40.1f, 64.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 64.0f, 39.0f);
		glVertex3f(40.1f, 60.0f, 39.0f);
		glVertex3f(40.1f, 60.0f, 35.25f);
		glVertex3f(40.1f, 64.0f, 35.25f);
		glEnd();

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 59.0f, 21.0f);
		glVertex3f(40.1f, 55.0f, 21.0f);
		glVertex3f(40.1f, 55.0f, 24.25f);
		glVertex3f(40.1f, 59.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 59.0f, 25.25f);
		glVertex3f(40.1f, 55.0f, 25.25f);
		glVertex3f(40.1f, 55.0f, 29.5f);
		glVertex3f(40.1f, 59.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 59.0f, 30.5f);
		glVertex3f(40.1f, 55.0f, 30.5f);
		glVertex3f(40.1f, 55.0f, 34.25f);
		glVertex3f(40.1f, 59.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 59.0f, 35.25f);
		glVertex3f(40.1f, 55.0f, 35.25f);
		glVertex3f(40.1f, 55.0f, 39.0f);
		glVertex3f(40.1f, 59.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 59.0f, 39.0f);
		glVertex3f(40.1f, 55.0f, 39.0f);
		glVertex3f(40.1f, 55.0f, 35.25f);
		glVertex3f(40.1f, 59.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 54.0f, 21.0f);
		glVertex3f(40.1f, 50.0f, 21.0f);
		glVertex3f(40.1f, 50.0f, 24.25f);
		glVertex3f(40.1f, 54.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 54.0f, 25.25f);
		glVertex3f(40.1f, 50.0f, 25.25f);
		glVertex3f(40.1f, 50.0f, 29.5f);
		glVertex3f(40.1f, 54.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 54.0f, 30.5f);
		glVertex3f(40.1f, 50.0f, 30.5f);
		glVertex3f(40.1f, 50.0f, 34.25f);
		glVertex3f(40.1f, 54.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 54.0f, 35.25f);
		glVertex3f(40.1f, 50.0f, 35.25f);
		glVertex3f(40.1f, 50.0f, 39.0f);
		glVertex3f(40.1f, 54.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 54.0f, 39.0f);
		glVertex3f(40.1f, 50.0f, 39.0f);
		glVertex3f(40.1f, 50.0f, 35.25f);
		glVertex3f(40.1f, 54.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 49.0f, 21.0f);
		glVertex3f(40.1f, 45.0f, 21.0f);
		glVertex3f(40.1f, 45.0f, 24.25f);
		glVertex3f(40.1f, 49.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 49.0f, 25.25f);
		glVertex3f(40.1f, 45.0f, 25.25f);
		glVertex3f(40.1f, 45.0f, 29.5f);
		glVertex3f(40.1f, 49.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 49.0f, 30.5f);
		glVertex3f(40.1f, 45.0f, 30.5f);
		glVertex3f(40.1f, 45.0f, 34.25f);
		glVertex3f(40.1f, 49.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 49.0f, 35.25f);
		glVertex3f(40.1f, 45.0f, 35.25f);
		glVertex3f(40.1f, 45.0f, 39.0f);
		glVertex3f(40.1f, 49.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 49.0f, 39.0f);
		glVertex3f(40.1f, 45.0f, 39.0f);
		glVertex3f(40.1f, 45.0f, 35.25f);
		glVertex3f(40.1f, 49.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 44.0f, 21.0f);
		glVertex3f(40.1f, 40.0f, 21.0f);
		glVertex3f(40.1f, 40.0f, 24.25f);
		glVertex3f(40.1f, 44.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 44.0f, 25.25f);
		glVertex3f(40.1f, 40.0f, 25.25f);
		glVertex3f(40.1f, 40.0f, 29.5f);
		glVertex3f(40.1f, 44.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 44.0f, 30.5f);
		glVertex3f(40.1f, 40.0f, 30.5f);
		glVertex3f(40.1f, 40.0f, 34.25f);
		glVertex3f(40.1f, 44.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 44.0f, 35.25f);
		glVertex3f(40.1f, 40.0f, 35.25f);
		glVertex3f(40.1f, 40.0f, 39.0f);
		glVertex3f(40.1f, 44.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 44.0f, 39.0f);
		glVertex3f(40.1f, 40.0f, 39.0f);
		glVertex3f(40.1f, 40.0f, 35.25f);
		glVertex3f(40.1f, 44.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 39.0f, 21.0f);
		glVertex3f(40.1f, 35.0f, 21.0f);
		glVertex3f(40.1f, 35.0f, 24.25f);
		glVertex3f(40.1f, 39.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 39.0f, 25.25f);
		glVertex3f(40.1f, 35.0f, 25.25f);
		glVertex3f(40.1f, 35.0f, 29.5f);
		glVertex3f(40.1f, 39.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 39.0f, 30.5f);
		glVertex3f(40.1f, 35.0f, 30.5f);
		glVertex3f(40.1f, 35.0f, 34.25f);
		glVertex3f(40.1f, 39.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 39.0f, 35.25f);
		glVertex3f(40.1f, 35.0f, 35.25f);
		glVertex3f(40.1f, 35.0f, 39.0f);
		glVertex3f(40.1f, 39.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 39.0f, 39.0f);
		glVertex3f(40.1f, 35.0f, 39.0f);
		glVertex3f(40.1f, 35.0f, 35.25f);
		glVertex3f(40.1f, 39.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 34.0f, 21.0f);
		glVertex3f(40.1f, 30.0f, 21.0f);
		glVertex3f(40.1f, 30.0f, 24.25f);
		glVertex3f(40.1f, 34.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 34.0f, 25.25f);
		glVertex3f(40.1f, 30.0f, 25.25f);
		glVertex3f(40.1f, 30.0f, 29.5f);
		glVertex3f(40.1f, 34.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 34.0f, 30.5f);
		glVertex3f(40.1f, 30.0f, 30.5f);
		glVertex3f(40.1f, 30.0f, 34.25f);
		glVertex3f(40.1f, 34.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 34.0f, 35.25f);
		glVertex3f(40.1f, 30.0f, 35.25f);
		glVertex3f(40.1f, 30.0f, 39.0f);
		glVertex3f(40.1f, 34.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 34.0f, 39.0f);
		glVertex3f(40.1f, 30.0f, 39.0f);
		glVertex3f(40.1f, 30.0f, 35.25f);
		glVertex3f(40.1f, 34.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 29.0f, 21.0f);
		glVertex3f(40.1f, 25.0f, 21.0f);
		glVertex3f(40.1f, 25.0f, 24.25f);
		glVertex3f(40.1f, 29.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 29.0f, 25.25f);
		glVertex3f(40.1f, 25.0f, 25.25f);
		glVertex3f(40.1f, 25.0f, 29.5f);
		glVertex3f(40.1f, 29.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 29.0f, 30.5f);
		glVertex3f(40.1f, 25.0f, 30.5f);
		glVertex3f(40.1f, 25.0f, 34.25f);
		glVertex3f(40.1f, 29.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 29.0f, 35.25f);
		glVertex3f(40.1f, 25.0f, 35.25f);
		glVertex3f(40.1f, 25.0f, 39.0f);
		glVertex3f(40.1f, 29.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 29.0f, 39.0f);
		glVertex3f(40.1f, 25.0f, 39.0f);
		glVertex3f(40.1f, 25.0f, 35.25f);
		glVertex3f(40.1f, 29.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 24.0f, 21.0f);
		glVertex3f(40.1f, 20.0f, 21.0f);
		glVertex3f(40.1f, 20.0f, 24.25f);
		glVertex3f(40.1f, 24.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 24.0f, 25.25f);
		glVertex3f(40.1f, 20.0f, 25.25f);
		glVertex3f(40.1f, 20.0f, 29.5f);
		glVertex3f(40.1f, 24.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 24.0f, 30.5f);
		glVertex3f(40.1f, 20.0f, 30.5f);
		glVertex3f(40.1f, 20.0f, 34.25f);
		glVertex3f(40.1f, 24.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 24.0f, 35.25f);
		glVertex3f(40.1f, 20.0f, 35.25f);
		glVertex3f(40.1f, 20.0f, 39.0f);
		glVertex3f(40.1f, 24.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 24.0f, 39.0f);
		glVertex3f(40.1f, 20.0f, 39.0f);
		glVertex3f(40.1f, 20.0f, 35.25f);
		glVertex3f(40.1f, 24.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 19.0f, 21.0f);
		glVertex3f(40.1f, 15.0f, 21.0f);
		glVertex3f(40.1f, 15.0f, 24.25f);
		glVertex3f(40.1f, 19.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 19.0f, 25.25f);
		glVertex3f(40.1f, 15.0f, 25.25f);
		glVertex3f(40.1f, 15.0f, 29.5f);
		glVertex3f(40.1f, 19.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 19.0f, 30.5f);
		glVertex3f(40.1f, 15.0f, 30.5f);
		glVertex3f(40.1f, 15.0f, 34.25f);
		glVertex3f(40.1f, 19.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 19.0f, 35.25f);
		glVertex3f(40.1f, 15.0f, 35.25f);
		glVertex3f(40.1f, 15.0f, 39.0f);
		glVertex3f(40.1f, 19.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 19.0f, 39.0f);
		glVertex3f(40.1f, 15.0f, 39.0f);
		glVertex3f(40.1f, 15.0f, 35.25f);
		glVertex3f(40.1f, 19.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 14.0f, 21.0f);
		glVertex3f(40.1f, 10.0f, 21.0f);
		glVertex3f(40.1f, 10.0f, 24.25f);
		glVertex3f(40.1f, 14.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 14.0f, 25.25f);
		glVertex3f(40.1f, 10.0f, 25.25f);
		glVertex3f(40.1f, 10.0f, 29.5f);
		glVertex3f(40.1f, 14.0f, 29.5f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 14.0f, 30.5f);
		glVertex3f(40.1f, 10.0f, 30.5f);
		glVertex3f(40.1f, 10.0f, 34.25f);
		glVertex3f(40.1f, 14.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 14.0f, 35.25f);
		glVertex3f(40.1f, 10.0f, 35.25f);
		glVertex3f(40.1f, 10.0f, 39.0f);
		glVertex3f(40.1f, 14.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 14.0f, 39.0f);
		glVertex3f(40.1f, 10.0f, 39.0f);
		glVertex3f(40.1f, 10.0f, 35.25f);
		glVertex3f(40.1f, 14.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 9.0f, 21.0f);
		glVertex3f(40.1f, 5.0f, 21.0f);
		glVertex3f(40.1f, 5.0f, 24.25f);
		glVertex3f(40.1f, 9.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 9.0f, 25.25f);
		glVertex3f(40.1f, 5.0f, 25.25f);
		glVertex3f(40.1f, 5.0f, 29.5f);
		glVertex3f(40.1f, 9.0f, 29.5f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 9.0f, 30.5f);
		glVertex3f(40.1f, 5.0f, 30.5f);
		glVertex3f(40.1f, 5.0f, 34.25f);
		glVertex3f(40.1f, 9.0f, 34.25f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 9.0f, 35.25f);
		glVertex3f(40.1f, 5.0f, 35.25f);
		glVertex3f(40.1f, 5.0f, 39.0f);
		glVertex3f(40.1f, 9.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 9.0f, 39.0f);
		glVertex3f(40.1f, 5.0f, 39.0f);
		glVertex3f(40.1f, 5.0f, 35.25f);
		glVertex3f(40.1f, 9.0f, 35.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 4.0f, 21.0f);
		glVertex3f(40.1f, 1.0f, 21.0f);
		glVertex3f(40.1f, 1.0f, 24.25f);
		glVertex3f(40.1f, 4.0f, 24.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 4.0f, 25.25f);
		glVertex3f(40.1f, 1.0f, 25.25f);
		glVertex3f(40.1f, 1.0f, 29.5f);
		glVertex3f(40.1f, 4.0f, 29.5f);
		glEnd();
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 4.0f, 30.5f);
		glVertex3f(40.1f, 1.0f, 30.5f);
		glVertex3f(40.1f, 1.0f, 34.25f);
		glVertex3f(40.1f, 4.0f, 34.25f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 4.0f, 35.25f);
		glVertex3f(40.1f, 1.0f, 35.25f);
		glVertex3f(40.1f, 1.0f, 39.0f);
		glVertex3f(40.1f, 4.0f, 39.0f);
		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS);
		glVertex3f(40.1f, 4.0f, 39.0f);
		glVertex3f(40.1f, 1.0f, 39.0f);
		glVertex3f(40.1f, 1.0f, 35.25f);
		glVertex3f(40.1f, 4.0f, 35.25f);
		glEnd();
		/*sidewindows*/
		
		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(11.0f, 49.0f, 9.9f);
		glVertex3f(11.0f, 45.0f, 9.9f);
		glVertex3f(14.25f, 45.0f, 9.9f);
		glVertex3f(14.25f, 49.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(15.25f, 49.0f, 9.9f);
		glVertex3f(15.25f, 45.0f, 9.9f);
		glVertex3f(19.5f, 45.0f, 9.9f);
		glVertex3f(19.5f, 49.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(40.5f, 49.0f, 9.9f);
		glVertex3f(40.5f, 45.0f, 9.9f);
		glVertex3f(44.25f, 45.0f, 9.9f);
		glVertex3f(44.25f, 49.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(45.25f, 49.0f, 9.9f);
		glVertex3f(45.25f, 45.0f, 9.9f);
		glVertex3f(49.0f, 45.0f, 9.9f);
		glVertex3f(49.0f, 49.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(11.0f, 44.0f, 9.9f);
		glVertex3f(11.0f, 40.0f, 9.9f);
		glVertex3f(14.25f, 40.0f, 9.9f);
		glVertex3f(14.25f, 44.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(15.25f, 44.0f, 9.9f);
		glVertex3f(15.25f, 40.0f, 9.9f);
		glVertex3f(19.5f, 40.0f, 9.9f);
		glVertex3f(19.5f, 44.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(40.5f, 44.0f, 9.9f);
		glVertex3f(40.5f, 40.0f, 9.9f);
		glVertex3f(44.25f, 40.0f, 9.9f);
		glVertex3f(44.25f, 44.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(45.25f, 44.0f, 9.9f);
		glVertex3f(45.25f, 40.0f, 9.9f);
		glVertex3f(49.0f, 40.0f, 9.9f);
		glVertex3f(49.0f, 44.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(11.0f, 39.0f, 9.9f);
		glVertex3f(11.0f, 35.0f, 9.9f);
		glVertex3f(14.25f, 35.0f, 9.9f);
		glVertex3f(14.25f, 39.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(15.25f, 39.0f, 9.9f);
		glVertex3f(15.25f, 35.0f, 9.9f);
		glVertex3f(19.5f, 35.0f, 9.9f);
		glVertex3f(19.5f, 39.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(40.5f, 39.0f, 9.9f);
		glVertex3f(40.5f, 35.0f, 9.9f);
		glVertex3f(44.25f, 35.0f, 9.9f);
		glVertex3f(44.25f, 39.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(45.25f, 39.0f, 9.9f);
		glVertex3f(45.25f, 35.0f, 9.9f);
		glVertex3f(49.0f, 35.0f, 9.9f);
		glVertex3f(49.0f, 39.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(11.0f, 34.0f, 9.9f);
		glVertex3f(11.0f, 30.0f, 9.9f);
		glVertex3f(14.25f, 30.0f, 9.9f);
		glVertex3f(14.25f, 34.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(15.25f, 34.0f, 9.9f);
		glVertex3f(15.25f, 30.0f, 9.9f);
		glVertex3f(19.5f, 30.0f, 9.9f);
		glVertex3f(19.5f, 34.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(40.5f, 34.0f, 9.9f);
		glVertex3f(40.5f, 30.0f, 9.9f);
		glVertex3f(44.25f, 30.0f, 9.9f);
		glVertex3f(44.25f, 34.0f, 9.9f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(45.25f, 34.0f, 9.9f);
		glVertex3f(45.25f, 30.0f, 9.9f);
		glVertex3f(49.0f, 30.0f, 9.9f);
		glVertex3f(49.0f, 34.0f, 9.9f);

		glEnd();
		
glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-19.0f, 49.0f, 20.1f);
		glVertex3f(-19.0f, 45.0f, 20.1f);
		glVertex3f(-15.25f, 45.0f, 20.1f);
		glVertex3f(-15.25f, 49.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-14.25f, 49.0f, 20.1f);
		glVertex3f(-14.25f, 45.0f, 20.1f);
		glVertex3f(-10.5f, 45.0f, 20.1f);
		glVertex3f(-10.5f, 49.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(10.5f, 49.0f, 20.1f);
		glVertex3f(10.5f, 45.0f, 20.1f);
		glVertex3f(14.25f, 45.0f, 20.1f);
		glVertex3f(14.25f, 49.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(15.25f, 49.0f, 20.1f);
		glVertex3f(15.25f, 45.0f, 20.1f);
		glVertex3f(19.0f, 45.0f, 20.1f);
		glVertex3f(19.0f, 49.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-19.0f, 44.0f, 20.1f);
		glVertex3f(-19.0f, 40.0f, 20.1f);
		glVertex3f(-15.25f, 40.0f, 20.1f);
		glVertex3f(-15.25f, 44.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-14.25f, 44.0f, 20.1f);
		glVertex3f(-14.25f, 40.0f, 20.1f);
		glVertex3f(-10.5f, 40.0f, 20.1f);
		glVertex3f(-10.5f, 44.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(10.5f, 44.0f, 20.1f);
		glVertex3f(10.5f, 40.0f, 20.1f);
		glVertex3f(14.25f, 40.0f, 20.1f);
		glVertex3f(14.25f, 44.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(15.25f, 44.0f, 20.1f);
		glVertex3f(15.25f, 40.0f, 20.1f);
		glVertex3f(19.0f, 40.0f, 20.1f);
		glVertex3f(19.0f, 44.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-19.0f, 39.0f, 20.1f);
		glVertex3f(-19.0f, 35.0f, 20.1f);
		glVertex3f(-15.25f, 35.0f, 20.1f);
		glVertex3f(-15.25f, 39.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-14.25f, 39.0f, 20.1f);
		glVertex3f(-14.25f, 35.0f, 20.1f);
		glVertex3f(-10.5f, 35.0f, 20.1f);
		glVertex3f(-10.5f, 39.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(10.5f, 39.0f, 20.1f);
		glVertex3f(10.5f, 35.0f, 20.1f);
		glVertex3f(14.25f, 35.0f, 20.1f);
		glVertex3f(14.25f, 39.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(15.25f, 39.0f, 20.1f);
		glVertex3f(15.25f, 35.0f, 20.1f);
		glVertex3f(19.0f, 35.0f, 20.1f);
		glVertex3f(19.0f, 39.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-19.0f, 34.0f, 20.1f);
		glVertex3f(-19.0f, 30.0f, 20.1f);
		glVertex3f(-15.25f, 30.0f, 20.1f);
		glVertex3f(-15.25f, 34.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(-14.25f, 34.0f, 20.1f);
		glVertex3f(-14.25f, 30.0f, 20.1f);
		glVertex3f(-10.5f, 30.0f, 20.1f);
		glVertex3f(-10.5f, 34.0f, 20.1f);

		glEnd();

		glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(10.5f, 34.0f, 20.1f);
		glVertex3f(10.5f, 30.0f, 20.1f);
		glVertex3f(14.25f, 30.0f, 20.1f);
		glVertex3f(14.25f, 34.0f, 20.1f);

		glEnd();
glColor3f(1.0f, 0.8f, 0.6f);
		glBegin(GL_QUADS); // blue1
		glVertex3f(15.25f, 34.0f, 20.1f);
		glVertex3f(15.25f, 30.0f, 20.1f);
		glVertex3f(19.0f, 30.0f, 20.1f);
		glVertex3f(19.0f, 34.0f, 20.1f);

		glEnd();


		/*something*/
		void tableleg(double thick, double len)
		{
			glPushMatrix();
			glTranslated(0, len / 2.0, 0);
			glScaled(thick, len, thick);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		void table(double topwid, double topthick, double legthick, double leglen)
		{
			glPushMatrix();
			glTranslated(0, leglen, 0);
			glScaled(topwid, topthick, topwid);

			glutSolidCube(1.0);
			glPopMatrix();
			double dist = 0.95 * topwid / 2 - legthick / 2;
			glPushMatrix();
			glColor3f(.96f, 0.51f, 0.0f);
			glTranslated(dist, 0, dist);
			glColor3f(.96f, 0.51f, 0.0f);
			tableleg(legthick, leglen);
			glTranslated(0, 0, -2 * dist);
			glColor3f(.96f, 0.51f, 0.0f);
			tableleg(legthick, leglen);
			glTranslated(-2 * dist, 0, 2 * dist);
			glColor3f(.96f, 0.51f, 0.0f);
			tableleg(legthick, leglen);
			glTranslated(0, 0, -2 * dist);
			glColor3f(.96f, 0.51f, 0.0f);
			tableleg(legthick, leglen);
			glPopMatrix();
		}
		/******************************************/
		double winht = 1.0;
		// GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
		// GLfloat mat_diffuse[] = {0.5f, 0.5f, 0.5f, 1.0f};
		// GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
		// GLfloat mat_shininess[] = {50.0f};
		// glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		// glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		// glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		// glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		// GLfloat Lightintensity[] = {1.0f, 1.0f, 1.0f, 1.0f};
		// GLfloat Lightposition[] = {2.0f, 6.0f, 3.0f, 0.0f};
		// glLightfv(GL_LIGHT0, GL_POSITION, Lightposition);
		// glLightfv(GL_LIGHT0, GL_DIFFUSE, Lightintensity);
		glPushMatrix();
		glTranslated(0.4, 0, 0.4);
		table(1.6, 0.06, 0.06, 0.9);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.9, 0.98, 0.5);
		glRotated(60, 0, 1, 0);
		glColor3f(0.192f, 0.192f, 0.192f);
		glutSolidTeapot(0.08);
		glPopMatrix();
		glFlush();

		glPushMatrix();
		glTranslated(30, 0, 30);
		glColor3f(1.0f, 0.8f, 0.6f);
		table(1.6, 0.06, 0.06, 0.9);
		glPopMatrix();

		glPushMatrix();
		glTranslated(30.0, 0.98, 30.0);
		glRotated(60, 0, 1, 0);
		glColor3f(0.192f, 0.192f, 0.192f);
		glutSolidTeapot(0.08);
		glPopMatrix();
		glFlush();

		glPushMatrix();
		glScalef(2.0, 2.0, 2.0);
		glTranslatef(0.0, .85, -20.0);

		glPopMatrix();


	}

	glutSwapBuffers();
}



void Orient(float ang)
{
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
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
	// if (key == 'o')
	// {
	// 	open = 1;
	// 	gluLookAt(1, 1, 25, 0, 0, -10, 0.0, 0.1, 0.0);
	// }
	// if (key == 'c')
	// {
	// 	open = 0;
	// 	gluLookAt(1, 1, 25, 0, 0, -10, 0.0, 0.1, 0.0);
	// }
	

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
	// glutAddMenuEntry("10)  o:Open door.", 1);
	// glutAddMenuEntry("11)  c:Close door.", 1);
	glutAddMenuEntry("10) q:Quit.", 1);
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
	glutCreateWindow("PENTAGON");
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(Keys);
	glutSpecialFunc(arrowKeys);
	menu();
	glutFullScreen(); // to see o/p in full screen on monitor
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(Reshape);

// glEnable(GL_DEPTH_TEST);
// glEnable(GL_LIGHTING);
// glEnable(GL_LIGHT0); 
// glEnable(GL_NORMALIZE);
	glutMainLoop();
	return (0);
}
