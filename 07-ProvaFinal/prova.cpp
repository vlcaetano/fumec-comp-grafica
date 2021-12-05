#include<GL/glut.h>

GLfloat angulo = 2;
GLdouble eyeZ = 50;
GLfloat deslocaX = 0;
GLfloat deslocaY = 0;

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, eyeZ, 0, 0, 0, 0, 1, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //cubo
    glPushMatrix();
        glTranslatef(deslocaX, deslocaY, 0);
        glColor3f(0, 0, 1);
        glRotatef(angulo, 0, 1, 0);
        glutWireCube(10);
    glPopMatrix();

    //triangulo vermelho
    glPushMatrix();
        glColor3f(1, 0, 0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-5, 5);
        glVertex2f(5, 5);
        glVertex2f(0, 15);
        glEnd();
    glPopMatrix();
    
    //triangulo cinza
    glPushMatrix();
        glRotatef(angulo, 1, 0, 0);
        glColor3f(0.8, 0.8, 0.8);
        glBegin(GL_TRIANGLES);
        glVertex2f(-5, -5);
        glVertex2f(-5, 5);
        glVertex2f(-15, 0);
        glEnd();
    glPopMatrix();

    //triangulo amarelo
    glPushMatrix();
        glRotatef(angulo, 1, 0, 0);
        glColor3f(1, 1, 0);
        glBegin(GL_TRIANGLES);
        glVertex2f(5, 5);
        glVertex2f(5, -5);
        glVertex2f(15, 0);
        glEnd();
    glPopMatrix();

    //triangulo verde
    glPushMatrix();
        glColor3f(0, 1, 0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-5, -5);
        glVertex2f(5, -5);
        glVertex2f(0, -15);
        glEnd();
    glPopMatrix();
    glFlush();
}

void anima(int)
{
    angulo += 1;
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
        if (deslocaY <= 10) {
            deslocaY += 1;
        }
    }

    if (key == GLUT_KEY_DOWN)
    {
        if (deslocaY >= -10) {
            deslocaY -= 1;
        }
    }

    if (key == GLUT_KEY_LEFT)
    {
        if (deslocaX >= -10) {
            deslocaX -= 1;
        }
    }

    if (key == GLUT_KEY_RIGHT)
    {
        if (deslocaX <= 10) {
            deslocaX += 1;
        }
    }

    if (key == GLUT_KEY_PAGE_UP)
    {
        if (eyeZ >= 20) {
            eyeZ -= 5;
        }
    }

    if (key == GLUT_KEY_PAGE_DOWN)
    {
        if (eyeZ <= 90) {
            eyeZ += 5;
        }
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