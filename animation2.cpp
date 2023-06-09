#include <GL/glut.h>
#include <iostream>

int windowWidth = 800;
int windowHeight = 800;

int objectX = 0; 


void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}


void drawObject() {
    glColor3f(1.0, 0.0, 0.0);
    glRecti(objectX, windowHeight / 2 - 50, objectX + 100, windowHeight / 2 + 50);
    glFlush();
}

void updateObjectPosition() {
    objectX += 5; 

    
    if (objectX > windowWidth) {
        objectX = 0; 
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawObject();
    glFlush();
}

void updateFrame(int value) {
    updateObjectPosition();
    glutPostRedisplay();
    glutTimerFunc(16, updateFrame, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Object Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, updateFrame, 0); 
    glutMainLoop();
    return 0;
}
