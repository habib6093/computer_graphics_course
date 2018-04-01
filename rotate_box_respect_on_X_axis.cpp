// house.cc

#include <GL/gl.h>
#include <GL/glut.h>
float camPosX = 5;
float camPosy = 5.0f;
float camPosZ = 5;
float upVx = .1;
float upVy = .1;
float upVz = .1;
float angle=20;

/*GLfloat ctrlpoints[3][3] = {
	{ 0.0, 0.0, 0.0}, { .50, .50, 0.0},
	{1.0, 1.0, 0.0}};*/
void display () {

    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);

    /* draw scene */
    glPushMatrix();
    //glScalef(0.33,0.33,0.33);
    // house
    glPushMatrix();
    angle+=20;
    glRotatef(angle, 1.0, 0.0,0.0);
    //glColor3f(1.0,0.0,0.0);
    //glTranslatef(0,0,0);
    //glutWireCube(1);                 // building
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        //X-Axis
        glColor3ub(255,0,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        //Y-Axis
        glColor3ub(0,255,0);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        //X-Axis
        glColor3ub(0,0,255);
        glVertex3f(0,0,0);
        glVertex3f(0,0,1);
    glEnd();









    glBegin(GL_QUADS);
        //X-Axis
        glColor3ub(255,0,0);
        glVertex3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
         glVertex3f(1,1,0);

    glEnd();


    glBegin(GL_QUADS);
        //X-Axis
        glColor3ub(0,255,0);
        glVertex3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,1);
         glVertex3f(1,0,1);

    glEnd();


     glBegin(GL_QUADS);
        //X-Axis
        glColor3ub(0,0,255);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,1);
         glVertex3f(0,0,1);

    glEnd();



    glBegin(GL_QUADS);
        //X-Axis
        glColor3ub(80,80,255);
        glVertex3f(1,1,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,1);
         glVertex3f(1,1,1);

    glEnd();



    glBegin(GL_QUADS);
        //X-Axis
        glColor3ub(80,200,255);
        glVertex3f(1,1,1);
        glVertex3f(0,1,1);
        glVertex3f(0,0,1);
         glVertex3f(1,0,1);

    glEnd();


    glBegin(GL_QUADS);
        //X-Axis
        glColor3ub(200,200,255);
        glVertex3f(1,1,0);
        glVertex3f(1,1,1);
        glVertex3f(1,0,1);
         glVertex3f(1,0,0);

    glEnd();




    /////////////niche/////////////




     glBegin(GL_QUADS);
        //X-Axis
        glColor3ub(80,255,255);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(-1,1,0);
         glVertex3f(-1,0,0);

    glEnd();




     glBegin(GL_QUADS);
        //X-Axis
        glColor3ub(80,0,255);
        glVertex3f(0,0,0);
        glVertex3f(-1,0,0);
        glVertex3f(-1,0,1);
         glVertex3f(0,0,1);

    glEnd();



    glBegin(GL_QUADS);
        //X-Axis
        glColor3ub(100,1000,255);
        glVertex3f(-1,0,0);
        glVertex3f(-1,1,0);

        glVertex3f(-1,1,1);
         glVertex3f(-1,0,1);

    glEnd();





    glBegin(GL_QUADS);
        //X-Axis
        glColor3ub(200,30,55);
        glVertex3f(-1,1,0);

        glVertex3f(-1,1,1);
        glVertex3f(0,1,1);
         glVertex3f(0,1,0);

    glEnd();



    glBegin(GL_QUADS);
        //X-Axis
        glColor3ub(255,130,55);
        glVertex3f(0,1,1);

        glVertex3f(-1,1,1);
        glVertex3f(-1,0,1);
         glVertex3f(0,0,1);

    glEnd();





















    glPopMatrix();

    /* flush drawing routines to the window */
    //glFlush();
    glutSwapBuffers();
}

void reshape ( int width, int height ) {

    /* define the viewport transformation */
    glViewport(0,0,width,height);
}

void myInit()
{
    /* set up depth-buffering */
    glEnable(GL_DEPTH_TEST);

    /* turn on default lighting */
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);

    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40,1,4,20);

    /* define the viewing transformation */

}

void update(int value)
{
    //gluLookAt(5.0,camPosy,5.0,0.0,0.0,0.0,0.0,1.0,0.0glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camPosX,camPosy,camPosZ,0.0,0.0,0.0,1.0,0.0,0.0);
    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}
void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          camPosy+=0.5f;
          update(0);
          break;
      case GLUT_KEY_DOWN:
          camPosy-=0.5f;
          update(0);
          break;
      case GLUT_KEY_RIGHT:
          camPosX+=0.5f;
          update(0);
          break;
      case GLUT_KEY_LEFT:
          camPosX-=0.5f;
          update(0);
          break;

}
}
int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(800,700);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    /* create and set up a window */
    glutCreateWindow("hello, teapot!");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(reshape);

    myInit();
    glutTimerFunc(25,update,0);
    /* tell GLUT to wait for events */
    glutMainLoop();
}
