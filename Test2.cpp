#include <GL/glut.h>
#include <math.h>
using namespace std;

double paowuxian[200][2];//抛物线
double zhengxianquxian[200][2];//正弦曲线

void init()
{
	for (double i = -1.0; i < 1.0; i=i+0.01)//抛物线
	{
		int x = (i + 1) * 100;
		paowuxian[x][0] = i;
		paowuxian[x][1] = i*i;
	}

	for (double i = -1.0; i < 1.0; i = i + 0.01)//抛物线
	{
		int x = (i + 1) * 100;
		zhengxianquxian[x][0] = i;
		zhengxianquxian[x][1] = sin(i * 10) / 2 - 0.5;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);//背景
	glVertex2f(-1, -1);
	glVertex2f(-1, 1);
	glVertex2f(1, 1);
	glVertex2f(1, -1);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);//图元颜色

	glBegin(GL_LINE_STRIP);//抛物线
	for (int i=0;i<200;i++)
	{
		glVertex2f(paowuxian[i][0], paowuxian[i][1]);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);//正弦曲线
	for (int i = 0; i < 200; i++)
	{
		glVertex2f(zhengxianquxian[i][0], zhengxianquxian[i][1]);
	}
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Experiment 2");

	init();
	glutDisplayFunc(display);
	glutMainLoop();
}