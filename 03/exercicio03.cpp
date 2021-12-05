#include <GL/glut.h>

GLfloat limite;
GLfloat deslocax = 0;
GLfloat angulo = 0;
GLfloat angulo2 = 0;

void desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glViewport(0, 0, 400, 400);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-10.0, 0.0);
        glVertex2f(10.0, 0.0);
    glEnd();

    glTranslatef(deslocax, 0, 0);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-2.0, 0.0);
        glVertex2f(-3.0, 0.0);
        glVertex2f(-3.0, 4.0);
        glVertex2f(3.0, 4.0);
        glVertex2f(3.0, 0.0);
        glVertex2f(2.0, 0.0);
        glVertex2f(2.0, 1.0);
        glVertex2f(-2.0, 1.0);
    glEnd();

    glTranslatef(0, 2, 0);
    glRotatef(angulo, 0, 0, 1);

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.5, 0.0);
        glVertex2f(-0.5, 3.0);
        glVertex2f(0.5, 3.0);
        glVertex2f(0.5, 0.0);
    glEnd();

    glTranslatef(0, 3, 0);
    glRotatef(angulo2, 0, 0, 1);

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 2.5);
        glVertex2f(0.5, 2.5);
        glVertex2f(0.5, -0.5);
    glEnd();

    glFlush();
}

void teclasEspeciais(int key, int x, int y)
{
    if (key == GLUT_KEY_PAGE_UP)
    {
        angulo -= 15;
    }
    if (key == GLUT_KEY_PAGE_DOWN)
    {
        angulo += 15;
    }
    if (key == GLUT_KEY_LEFT)
    {
        if (deslocax > -7)
            deslocax -= 1.0f;
    }
    if (key == GLUT_KEY_RIGHT)
    {
        if (deslocax < 7)
            deslocax += 1.0f;
        
    }
    if (key == GLUT_KEY_HOME)
    {
        angulo2 -= 15;
    }
    if (key == GLUT_KEY_END)
    {
        angulo2 += 15;
    }

    glutPostRedisplay();
}


void inicializa(void)
{
    limite = 10.0;
    deslocax = 0.0;
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-limite, limite, -limite, limite);
}

int main(void)
{
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Meu desenho");
    inicializa();
    glutDisplayFunc(desenha);
    glutSpecialFunc(teclasEspeciais);
    glutMainLoop();
}
