#include <GL/glut.h>
using namespace std;

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

	glPointSize(10);//点的大小
	glBegin(GL_POINTS);//点
	glVertex2f(-0.5, 0.9);
	glVertex2f(0.0, 0.9);
	glVertex2f(0.5, 0.9);
	glEnd();


	glLineWidth(2.0);//线的宽度
	glBegin(GL_LINES);//线
	glVertex2f(-0.5, 0.7);
	glVertex2f(0.5, 0.7);
	glEnd();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);//dashed
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.65);
	glVertex2f(0.5, 0.65);//绘制线，指定起点与终点
	glEnd();

	glLineStipple(1, 0x0101);//dotted
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.6);
	glVertex2f(0.5, 0.6);//绘制线，指定起点与终点
	glEnd();


	glBegin(GL_TRIANGLES);//三角形
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.5, 0.0);
	glEnd();

	glBegin(GL_QUADS);//四边形,注意4个点的创建顺序，要么顺时针，要么逆时针
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