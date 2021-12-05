#include<GL/glut.h>

GLfloat angulo = 2;

void Desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glRotatef(angulo, 0, 1, 0);

    glColor3f(1.0, 0.0, 0.0);
    glutWireCube(40.0);

    glPushMatrix();
    glTranslatef(40, 0, 0);
    glutWireCube(40.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40, 0, 0);
    glutWireCube(40.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 40, 0);
    glutWireCube(40.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -40, 0);
    glutWireCube(40.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 40);
    glutWireCube(40.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -40);
    glutWireCube(40.0);
    glPopMatrix();

    glFlush();
}

void anima(int)
{
    glutPostRedisplay();
    glutTimerFunc(16, anima, 1);
}

void especificaParametrosVisualizacao(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 60, 380);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(100, 100, 100, 0, 0, 0, 0, 1, 0);
  
    glEnable(GL_DEPTH_TEST);

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
    glutDisplayFunc(Desenha);
    especificaParametrosVisualizacao();
    Inicializa();
    anima(1);
    glutMainLoop();
}