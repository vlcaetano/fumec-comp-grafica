#include<GL/glut.h>

GLfloat angulo = 2;
GLdouble eyeX = 0;
GLdouble eyeZ = 100;
GLdouble olhaX = 0;
GLdouble olhaZ = 0;

GLboolean ida = true;
GLfloat desloca = -20;

GLboolean pararMovimento = false;

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, 20, eyeZ, olhaX, 0, olhaZ, 0, 1, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(desloca, 0, -20);
        glColor3f(1, 0, 0);
        glutWireCube(10);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(20, 0, -20);
        glColor3f(1, 1, 0);
        glRotatef(angulo, 0, 1, 0);
        glutWireCube(10);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(desloca, 0, 20);
        glColor3f(0, 0, 1);
        glutWireCube(10);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(20, 0, 20);
        glColor3f(0, 1, 0);
        glRotatef(angulo, 0, 1, 0);
        glutWireCube(10);
    glPopMatrix();

    glFlush();
}

void anima(int)
{
    if (pararMovimento == false)
    {
        if (ida) {
            desloca += 0.5;
            if (desloca == 0) {
                ida = false;
            }
        }
        else {
            desloca -= 0.5;
            if (desloca == -20) {
                ida = true;
            }
        }

        angulo += 1;
    }
    glutPostRedisplay();
    glutTimerFunc(16, anima, 1);
}

void especificaParametrosVisualizacao(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 10, 1000);

    glEnable(GL_DEPTH_TEST);

}

void teclado(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        if (eyeZ >= 50) {
            eyeZ -= 5;
            olhaZ -= 5;
        }
    }

    if (key == GLUT_KEY_DOWN)
    {
        if (eyeZ <= 350) {
            eyeZ += 5;
            olhaZ += 5;
        }
    }

    if (key == GLUT_KEY_LEFT)
    {
        if (eyeX >= -40) {
            eyeX -= 5;
            olhaX -= 5;
        }
    }

    if (key == GLUT_KEY_RIGHT)
    {
        if (eyeX <= 40) {
            eyeX += 5;
            olhaX += 5;
        }
    }

    if (key == GLUT_KEY_END)
    {
        pararMovimento = true;
    }

    if (key == GLUT_KEY_HOME)
    {
        pararMovimento = false;
        angulo = 2;
        eyeX = 0;
        eyeZ = 100;
        ida = true;
        desloca = -20;

        olhaX = 0;
        olhaZ = 0;
    }

    glutPostRedisplay();
}

void Inicializa(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Teste_3D");
    especificaParametrosVisualizacao();
    glutDisplayFunc(Desenha);
    glutSpecialFunc(teclado);
    Inicializa();
    anima(1);
    glutMainLoop();
}