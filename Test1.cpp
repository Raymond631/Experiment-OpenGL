#include <GL/glut.h>
using namespace std;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);//����
	glVertex2f(-1, -1);
	glVertex2f(-1, 1);
	glVertex2f(1, 1);
	glVertex2f(1, -1);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);//ͼԪ��ɫ

	glPointSize(10);//��Ĵ�С
	glBegin(GL_POINTS);//��
	glVertex2f(-0.5, 0.9);
	glVertex2f(0.0, 0.9);
	glVertex2f(0.5, 0.9);
	glEnd();


	glLineWidth(2.0);//�ߵĿ��
	glBegin(GL_LINES);//��
	glVertex2f(-0.5, 0.7);
	glVertex2f(0.5, 0.7);
	glEnd();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);//dashed
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.65);
	glVertex2f(0.5, 0.65);//�����ߣ�ָ��������յ�
	glEnd();

	glLineStipple(1, 0x0101);//dotted
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.6);
	glVertex2f(0.5, 0.6);//�����ߣ�ָ��������յ�
	glEnd();


	glBegin(GL_TRIANGLES);//������
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.5, 0.0);
	glEnd();

	glBegin(GL_QUADS);//�ı���,ע��4����Ĵ���˳��Ҫô˳ʱ�룬Ҫô��ʱ��
	glVertex2f(-0.5, -0.2);
	glVertex2f(0.5, -0.2);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();


	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Experiment 1");

	glutDisplayFunc(display);
	glutMainLoop();
}