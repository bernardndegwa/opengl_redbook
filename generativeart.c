#include <stdlib.h>

#ifdef __UBUNTU__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

// Question 1: In a GLUT program, how is control passed
// back to the programmer?  How is this set up during
// initialization?

int win_width = 512;
int win_height = 512;


void display( void )
{
  glClear( GL_COLOR_BUFFER_BIT );
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
  glutSwapBuffers();
}

void reshape( int w, int h )
{
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();

  // Question 3: What do the calls to glOrtho()
  // and glViewport() accomplish?
  glOrtho( 0., 1., 0., 1., -1., 1. );
  glViewport( 0, 0, w, h );

  win_width = w;
  win_height = h;

  glutPostRedisplay();
}

void keyboard( unsigned char key, int x, int y ) {
  switch(key) {
  case 27: // Escape key
    exit(0);
    break;
  }
}
int initGlutDisplay(int argc, char* argv[]){
  glutInit( &argc, argv );
  // Question 2: What does the parameter to glutInitDisplayMode()
  // specify?
  glutInitDisplayMode( GLUT_RGBA | GLUT_SINGLE);
  glutInitWindowSize( win_width, win_height );
  glutInitWindowPosition(100, 200);
  glutCreateWindow( "Intro Graphics Assignment 1" );

  glutDisplayFunc( display );
  glutReshapeFunc( reshape );
  glutKeyboardFunc( keyboard );

  glutMainLoop();
  return 0;
}
int main (int argc, char *argv[]) {
  int win_width = 512;
  int win_height = 512;
  initGlutDisplay(argc, argv);

}

