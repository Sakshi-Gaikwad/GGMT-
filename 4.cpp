#include <GL/glut.h>
#include <cmath>

float angle = 0.0f;
float scale = 1.0f;
float xTranslate = 0.0f;
float yTranslate = 0.0f;
float zTranslate = -5.0f;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(xTranslate, yTranslate, zTranslate);
    glRotatef(angle, 1.0, 1.0, 0.0);
    glScalef(scale, scale, scale);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();

    glFlush();
}

void update(int value) {
    angle += 2.0f;
    if (angle > 360) {
        angle -= 360;
    }

    scale += 0.01f;
    if (scale > 2.0f) {
        scale = 1.0f;
    }

    xTranslate = 1.0f * sin(angle * 3.14159265 / 180.0);
    yTranslate = 1.0f * cos(angle * 3.14159265 / 180.0);

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL 3D Transformations");

    init();

    glutDisplayFunc(display);

    glEnable(GL_DEPTH_TEST);

    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}


