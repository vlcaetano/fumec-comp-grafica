#include<GL/glut.h>

GLfloat angulo = 2;
GLdouble zoom = 200;

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(zoom, zoom, zoom, 0, 0, 0, 0, 1, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glRotatef(angulo, 0, 1, 0);
    glColor3f(1.0, 1.0, 0.0);
    glutWireSphere(40, 10, 10);
        
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(100, 0, 0);
    glRotatef(angulo, 0, 1, 0);
    glutWireSphere(10, 10, 10);

    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(20, 0, 0);
    glRotatef(angulo, 0, 1, 0);
    glutWireSphere(2, 10, 10);

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
        if (zoom >= 50){
            zoom -= 10;
        }
    }

    if (key == GLUT_KEY_DOWN)
    {
        if (zoom <= 350) {
            zoom += 10;
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