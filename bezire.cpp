#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void init()
{
  glClearColor(1, 0, 0, 0);
  glColor3f(0, 0, 1);
  gluOrtho2D(0, 640, 0, 480);
}

void draw()
{
  glClear(GL_COLOR_BUFFER_BIT);
  int x[4] = { 320, 400, 480, 560 }, y[4] = { 240, 100, 380, 240 };
  for (int i = 0; i < 4; i++) {
    glBegin(GL_LINES);
    glVertex2i(320, 0);
    glVertex2i(320, 480);
    glVertex2i(0, 240);
    glVertex2i(640, 240);
    glEnd();
  }
  double t;
  for (t = 0.0; t <= 1.0; t += 0.001) {
    int px = (1 - t) * (1 - t) * (1 - t) * x[0] + 3 * t * (1 - t) * (1 - t) * x[1] + 3 * t * t * (1 - t) * x[2] + t * t * t * x[3];
    int py = (1 - t) * (1 - t) * (1 - t) * y[0] + 3 * t * (1 - t) * (1 - t) * y[1] + 3 * t * t * (1 - t) * y[2] + t * t * t * y[3];
    glBegin(GL_POINTS);
    glVertex2i(px, py);
    glEnd();
  }
  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Bezier Curve");
  init();
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}
