#include <GL/glut.h>
#include <iostream>

int windowWidth = 800;
int windowHeight = 800;

int objectX = 0; // Initial x-coordinate of the object

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

// Function to draw the object
void drawObject() {
    glColor3f(1.0, 1.0, 1.0);
    glRecti(objectX, windowHeight / 2 - 50, objectX + 100, windowHeight / 2 + 50);
    glFlush();
}

// Function to update the position of the object
void updateObjectPosition() {
    objectX += 5; // Update the x-coordinate of the object

    // Check if the object goes beyond the window boundaries
    if (objectX > windowWidth) {
        objectX = 0; // Reset the x-coordinate to the starting position
    }
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawObject();
    glFlush();
}

// Function to update the animation frame
void updateFrame(int value) {
    updateObjectPosition();
    glutPostRedisplay();
    glutTimerFunc(16, updateFrame, 0); // 60 frames per second (1000 ms / 60 = 16.67 ms)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Object Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, updateFrame, 0); // Start the animation
    glutMainLoop();
    return 0;
}
