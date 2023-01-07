#include <GL/glut.h>

float theta;
float ud, lr;//上下、左右
float s = 1.0;

void init(void) {
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    //glMatrixMode(GL_PROJECTION);//投影矩阵
    //gluOrtho2D(-2.0, 2.0, -2.0, 2.0);

    //glMatrixMode(GL_MODELVIEW);//模型视图矩阵
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    //视口1
    glLoadIdentity();//重置为单位矩阵
    glViewport(200, 200, 200, 200);
    glScalef(s, s, s);
    glTranslatef(lr, ud, 0.0);
    glRotatef(theta, 0.0, 0.0, 1.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    //视口2
    glLoadIdentity();
    glViewport(0, 0, 200, 200);
    glScalef(s,s,s);
    glTranslatef(lr, ud, 0.0);
    glRotatef(theta, 0.0, 0.0, 1.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    glFlush();
}

void myKeyboard(unsigned char key, int x, int y) {
    switch (key)
    {
//平移
    case 'W':
        ud += 0.1;
        break;
    case 'S':
        ud -= 0.1;
        break;
    case 'A':
        lr -= 0.1;
        break;
    case 'D':
        lr += 0.1;
        break;
//旋转
    case 'Q':
        theta += 5.0;
        break;
    case 'E':
        theta -= 5.0;
        break;
//缩放
    case '=':
        s += 0.05;
        break;
    case '-':
        s -= 0.05;
        break;
    }
    glutPostRedisplay(); //重新调用绘制函数
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Experiment 3");

    init();
    glutKeyboardFunc(myKeyboard);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}