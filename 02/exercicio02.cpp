#include <GL/glut.h>

GLdouble minX = -1.0;
GLdouble maxX = 1.0;
GLdouble minY = -1.0;
GLdouble maxY = 1.0;

void desenha(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
		glVertex2f(-0.8, 0.8);
		glVertex2f(0.8, 0.8);
		glVertex2f(0.8, -0.8);
		glVertex2f(-0.8, -0.8);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex2f(-0.6, -0.6);
		glVertex2f(0.0, 0.6);
		glVertex2f(0.6, -0.6);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2f(-0.6, -0.4);
		glVertex2f(0.0, -0.3);
		glVertex2f(0.6, -0.4);
		glVertex2f(0.6, -0.6);
		glVertex2f(-0.6, -0.6);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
		glVertex2f(-1.0, 1.0);
		glVertex2f(1.0, -1.0);
	glEnd();
	glFlush();
}


void recarrega() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(minX, maxX, minY, maxY);
	glutPostRedisplay();
}

void teclado(int Key, int x, int y) {
	if (Key == GLUT_KEY_PAGE_UP) {
		minX += 0.1;
		maxX -= 0.1;
		minY += 0.1;
		maxY -= 0.1;
		recarrega();
	}

	if (Key == GLUT_KEY_PAGE_DOWN) {
		minX -= 0.1;
		maxX += 0.1;
		minY -= 0.1;
		maxY += 0.1;
		recarrega();
	}

	if (Key == GLUT_KEY_UP) {
		minY += 0.1;
		maxY += 0.1;
		recarrega();
	}

	if (Key == GLUT_KEY_DOWN) {
		minY -= 0.1;
		maxY -= 0.1;
		recarrega();
	}

	if (Key == GLUT_KEY_LEFT) {
		minX -= 0.1;
		maxX -= 0.1;
		recarrega();
	}

	if (Key == GLUT_KEY_RIGHT) {
		minX += 0.1;
		maxX += 0.1;
		recarrega();
	}
}

void inicializa(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(void) {
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Meu desenho");
	inicializa();
	glutDisplayFunc(desenha);
	glutSpecialFunc(teclado);
	glutMainLoop();
}


