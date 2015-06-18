#include <iostream>

using namespace std;


#include <GL/freeglut.h>

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT); 
   
   glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 1.0f); // Red
     glVertex3f(0.25, 0.25, 0.0);
glVertex3f(0.75, 0.25, 0.0);
glVertex3f(0.75, 0.75, 0.0);
glVertex3f(0.25, 0.75, 0.0);
glEnd();

 
   glFlush();  // Render now
}

void init(void)
{
/* select clearing (background) color
glClearColor(0.0, 0.0, 0.0, 0.0);
*/
/*
 initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(450, 250);
glutInitWindowPosition(500, 100);
glutCreateWindow("hello");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
 /* ISO C requires main to return int. */

}
