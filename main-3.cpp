// Program to plot x,y,z axis and a plane and it's normal
// also introduces the definition of a viewing volume
// the perspective view is set in the reshape callback */

#include <iostream>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
using namespace std;

static GLdouble viewer[]= {0.0, 0.0, 3.0};   // initial viewer (camera)location
static GLdouble lookAt[]= {0.0, 0.0, 0.0};   // initial viewer (camera)location
static GLdouble upVec[]= {0.0, 1.0, 0.0};   // initial viewer (camera)location

static GLdouble u[]= {2, 3, 4};   // vector 1
static GLdouble v[]= {-2, 5, 1};   // vector 2


void display()
{

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

/* update viewer position (or camera) in model-view matrix */

 glLoadIdentity();
 // set up camera: pos, look at, up vector
 gluLookAt(viewer[0],viewer[1],viewer[2], lookAt[0], lookAt[1], lookAt[2], upVec[0], upVec[1], upVec[2]);

 glBegin(GL_LINES);
   glColor3ub(255,0,0);  // x axis red
   glVertex3f(0,0,0);
   glVertex3f(0.5,0,0);

   glColor3ub(0, 255,0);  // y axis green
   glVertex3f(0,0,0);
   glVertex3f(0,0.5,0);

   glColor3ub(0,0,255);  // z axis blue
   glVertex3f(0,0,0);
   glVertex3f(0,0,0.5);
 glEnd();

  glBegin(GL_LINES);
   glColor3ub(128, 128, 128);  // gray vector
   glVertex3f(0,0,0);
   glVertex3f(u[0], u[1], u[2]);
   glColor3ub(200, 200, 200);
   glVertex3f(0,0,0);
   glVertex3f(v[0], v[1], v[2]);
  glEnd();

  glFlush();

}


void myReshape(int w, int h)
{
 glViewport(0, 0, w, h);


 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();

 // use a perspective view


  glFrustum(-2.0, 2.0, -2.0 * (GLfloat) h/ (GLfloat) w,
       2.0* (GLfloat) h / (GLfloat) w, 1.0, 10.0);


 // or we can use gluPerspective
 // gluPerspective(45.0, w/h, 1.0, 10.0);

 // or use an orthographic view
 //glOrtho(-2.0, 2.0, -2.0, 2.0, 2.0, 20.0);


 glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE);
 glutInitWindowSize(500, 500);
 glutCreateWindow("vectors");
 glutReshapeFunc(myReshape);
 glutDisplayFunc(display);

 glutMainLoop();
 return 0;
}
