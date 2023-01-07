#include <GL/glut.h>
#include <windows.h>

#define MAX_CHAR       128

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void drawString(const char* str) {
	static int isFirstCall = 1;
	static GLuint lists;
	if (isFirstCall) { // 如果是第一次调用，执行初始化
		isFirstCall = 0;		// 为每一个ASCII字符产生一个显示列表
		lists = glGenLists(MAX_CHAR);		// 申请MAX_CHAR个连续的显示列表编号
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);		// 把每个字符的绘制命令都装到对应的显示列表中
	}
	for (; *str != '\0'; ++str)	// 调用每个字符对应的显示列表，绘制每个字符
		glCallList(lists + *str);
}

void selectFont(int size, int charset, const char* face) {
	HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
		charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);

	HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
	DeleteObject(hOldFont);
}

void display(void) {
	selectFont(48, ANSI_CHARSET, "Times New Roman");
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(-0.5f, 0.0f);
	drawString("Hello World");
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Experiment 5");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
