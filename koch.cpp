#include <GL/glut.h>
#include <math.h>


GLfloat oldx=-0.5,oldy=0.5;

void msdelay(int ms){
    for(int i; i < ms; i++){
        for(int j; j < 1000; j++){
            ;
        }
    }
}

void drawkoch(GLfloat dir, GLfloat len, GLint iter){
    GLdouble dirRad = dir * 0.0174533;
    GLfloat newX=oldx+len * cos(dirRad);
    GLfloat newY= oldy + len * sin(dirRad);
    if(iter==0){
        glVertex2f(oldx, oldy);
        glVertex2f(newX, newY);
        oldx=newX;
        oldy=newY;
    }
    else{
        iter--;
        drawkoch(dir,len,iter);
        msdelay(2000);
        dir+=60.0;
        drawkoch(dir, len, iter);
        msdelay(2000);
        dir -= 120.0;
		drawkoch(dir, len, iter);
        msdelay(2000);
		dir += 60.0;
		drawkoch(dir, len, iter);
        msdelay(2000);
    }
}



void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0.0,1.0,0.0);
    drawkoch(0.0,0.05,3);
    msdelay(2000);
    drawkoch(-120.0, 0.05, 3);
    msdelay(2000);
	drawkoch(120.0,0.05,3);
    msdelay(2000);
	  
	glEnd();
	glFlush(); 
}



int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Koch Snowflake");
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}

