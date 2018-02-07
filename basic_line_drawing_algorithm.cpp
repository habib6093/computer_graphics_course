#include <GL/gl.h>
#include <stdio.h>
#include <GL/glut.h>
#include <cmath>
using namespace std;

void draw_line(int x1,int y1,int x2,int y2)
{

    int num_of_coordinate=50;


    double diff_a=abs(x1-x2);
    double diff_b=abs(y1-y2);

    if(x2<x1)
     diff_a*=-1;

    if(y2<y1)
     diff_b*=-1;

    int big=20;
    glColor3ub (0,0,0);

    for(double x=x1,y=y1,z=0; z<=num_of_coordinate; x+=(diff_a/num_of_coordinate),y+=(diff_b/num_of_coordinate),z++)
    {
    	    //cout<<x<<" "<<y<<endl;
    	    printf("%lf  %lf\n",x,y);
            int a=x,b=y;

    	    glBegin(GL_POLYGON);
        	glVertex2i(a,b);
        	glVertex2i(a+big,b);
        	glVertex2i(a+big,b+big);
        	glVertex2i(a,b+big);

        	glEnd();


    }


}



void temp(void)
{

	glClear (GL_COLOR_BUFFER_BIT);

	glPointSize(5.0);
	glColor3ub (0,0,0);


    int x1,y1,x2,y2,num_of_coordinate=0;
    x1=600,y1=300,x2=20,y2=400;
    draw_line(x1,y1,x2,y2);

    x1=20,y1=300,x2=600,y2=400;
    draw_line(x1,y1,x2,y2);


	glFlush();

}










void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);





	glFlush ();
}




void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0.0, 700.0, 0.0, 500.0);

}

main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (700, 500);
	glutInitWindowPosition (200, 150);
	glutCreateWindow ("Ship");
	//glutDisplayFunc(myDisplay);
	glutDisplayFunc(temp);
	myInit ();
	glutMainLoop();
}




