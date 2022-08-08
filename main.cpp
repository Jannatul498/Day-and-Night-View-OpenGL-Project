#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416


GLfloat cy=0, cy1=0, s=0;


int i;
float x=0;
bool transition= false;

void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;
    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
void cloud() //cloud
{
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(4,5.5,0);
    circle(4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8,5.5,0);
    circle(3.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.5,9,0);
    circle(3.5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1,9,0);
    circle(3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5,5.5,0);
    circle(4);
    glPopMatrix();
}

void cloud1()
{
    glPushMatrix();
    glTranslated(-40,25,0);
    glScalef(.55,.9,0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-20,35,0);
    glScalef(.55,.9,0);
    cloud();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-8,25,0);
    glScalef(.77,1.1,0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslated(10,10,0);
    glScalef(.44,.8,0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslated(42,25,0);
    glScalef(.88,1.2,0);
    cloud();
    glPopMatrix();
}

void move_cloud()
{
    if(x>=100)
        x=-100;
    glPushMatrix();
    glTranslatef(x,0,0);
    cloud1();
    glPopMatrix();
    x+=.006;
    glutSwapBuffers( );
}

void grass()
{

    glBegin(GL_POLYGON);
    glVertex3f (-0.4, -0.69, 0.0);
    glVertex3f (-0.32, -0.69, 0.0);
    glVertex3f (-0.277, -0.64, 0.0);
    glVertex3f (-0.3, -0.58, 0.0);
    glVertex3f (-0.26, -0.52, 0.0);
    glVertex3f (-0.28, -0.485, 0.0);
    glVertex3f (-0.26, -0.45, 0.0);
    glVertex3f (-0.28, -0.43, 0.0);
    glVertex3f (-0.4, -0.43, 0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (0.0, -0.69, 0.0);

    glVertex3f (0.0, -0.43, 0.0);

    glVertex3f (-0.17, -0.43, 0.0);

    glVertex3f (-0.14, -0.48, 0.0);
    glVertex3f (-0.18, -0.52, 0.0);
    glVertex3f (-0.13, -0.55, 0.0);
    glVertex3f (-0.19, -0.61, 0.0);
    glVertex3f (-0.15, -0.65, 0.0);
    glVertex3f (-0.2, -0.69, 0.0);

    glEnd();
}

void grass_mod()
{
    glPushMatrix();
    glTranslatef(50,30,0);
    glScalef(250,100,0);
    grass();
    glPopMatrix();
}
void river()
{

    glBegin(GL_QUADS);
    glVertex3f (0.0, -0.8, 0.0);
    glVertex3f (0.0, -0.43, 0.0);
    glVertex3f (-0.4, -0.43, 0.0);
    glVertex3f (-0.4, -0.8, 0.0);

    glEnd();
}
void river_mod()
{
    glPushMatrix();
    glTranslatef(50,30,0);
    glScalef(250,100,0);
    river();
    glPopMatrix();
}
void boat()
{

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f (-0.3, 0.2, 0.0);
    glVertex3f (-0.3, 0.4, 0.0);

    glVertex3f (-0.6, 0.4, 0.0);
    glVertex3f (-0.6, 0.2, 0.0);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex3f (-0.3, 0.2, 0.0);
    glVertex3f (-0.1, 0.5, 0.0);
    glVertex3f (-0.3, 0.4, 0.0);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex3f (-0.6, 0.4, 0.0);
    glVertex3f (-0.8, 0.52, 0.0);
    glVertex3f (-0.6, 0.2, 0.0);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex3f (-0.3, 0.4, 0.0);
    glVertex3f (-0.35, 0.6, 0.0);
    glVertex3f (-0.4, 0.4, 0.0);
    glEnd();
    glColor3ub(139,69,19);
    glBegin(GL_QUADS);
    glVertex3f (-0.4, 0.4, 0.0);
    glVertex3f (-0.35, 0.6, 0.0);

    glVertex3f (-0.55, 0.6, 0.0);
    glVertex3f (-0.6, 0.4, 0.0);
    glEnd();
}

void boat_mod()
{
    glPushMatrix();
    glTranslatef(4,-50,0);
    glScalef(15,15,0);
    boat();
    glPopMatrix();
}




void tree()
{

    glColor3ub(101,67,33);
    glBegin(GL_QUADS);
    glVertex2f(-16,0);
    glVertex2f(-13,0);
    glVertex2f(-13,-29);
    glVertex2f(-16,-29);
    glEnd();

    glColor3ub(0,100,0);
    glPushMatrix();
    glTranslatef(-18,-8,0);
    glScalef(.77,1.1,0);
    circle(6.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-12,-8,0);
    glScalef(.77,1.1,0);
    circle(6.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15,10,0);
    glScalef(.77,1.1,0);
    circle(6.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-19,1,0);
    glScalef(.77,1.3,0);
    circle(6.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-11,1,0);
    glScalef(.77,1.3,0);
    circle(6.5);
    glPopMatrix();


}
void tree_mod()
{
    glPushMatrix();
    glTranslatef(-31,-10,0);
    glScalef(.5,.5,0);
    tree();
    glPopMatrix();
}

void tree_mod2()
{
    glPushMatrix();
    glTranslatef(40.0,-12,0);
    glScalef(.5,.5,0);
    tree();
    glPopMatrix();
}

void tree2(void)
{

    glColor3ub(101,67,33);
    glBegin(GL_QUADS);
    glVertex2f(-1,-3);
    glVertex2f(1,-3);
    glVertex2f(1.0,-20.0);
    glVertex2f(-1.0,-20);
    glEnd();

    glColor3ub(101,67,33);
    glBegin(GL_QUADS);
    glVertex2f(-1,-3);
    glVertex2f(1,-3);
    glVertex2f(1.0,-20.0);
    glVertex2f(-1.0,-20);
    glEnd();

    glColor3ub(0,100,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0,3.0);
    glVertex2f(3.0,-5.0);
    glVertex2f(-3.0,-5.0);
    glEnd();

    glColor3ub(0,100,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0,1.0);
    glVertex2f(4.0,-9.0);
    glVertex2f(-4.0,-9.0);
    glEnd();

    glColor3ub(0,100,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0,.5);
    glVertex2f(5.0,-15.0);
    glVertex2f(-5.0,-15.0);
    glEnd();
}
void tree2_mod()
{
    glPushMatrix();
    glTranslatef(0.58,-3.5,0);
    glScalef(.42,.4,0);
    tree2();
    glPopMatrix();
}
void tree2_mod2()
{
    glPushMatrix();
    glTranslatef(-25.5,-0.2,0);
    glScalef(.5,.5,0);
    tree2();
    glPopMatrix();
}
void tree2_mod3()
{
    glPushMatrix();
    glTranslatef(16.7,-6.0,0);
    glScalef(.28,.3,0);
    tree2();
    glPopMatrix();
}
void tree2_mod4()
{
    glPushMatrix();
    glTranslatef(44.0,-4.0,0);
    glScalef(.3,.3,0);
    tree2();
    glPopMatrix();
}

void parachute()
{
    glColor3ub(165,42,42);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(2.0,-2.0);//top
    glVertex2f(1.0,-10.0);//bottom
    glVertex2f(-2,-2.0);//top
    glVertex2f(-1,-10);//bottom
    glEnd();

    glColor3ub(219,112,147);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(.6,1,0);
    circle(6);
    glPopMatrix();

    glColor3ub(123,104,238);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(.25,1,0);
    circle(6);
    glPopMatrix();



    glColor3ub(70,130,180);
    glBegin(GL_QUADS);
    glVertex2f(-1.5,-9);
    glVertex2f(1.5,-9);
    glVertex2f(1.5,-13);
    glVertex2f(-1.5,-13);
    glEnd();

}

void parachute_mod()
{
    glPushMatrix();
    glTranslatef(20,-20,0);
    glScalef(.5,.5,0);
    parachute();
    glPopMatrix();


}
void parachute_mod2()
{
    glPushMatrix();
    glTranslatef(-20,-20,0);
    glScalef(.8,.8,0);
    parachute();
    glPopMatrix();
}



void house()
{

    glColor3ub(218,165,32);

    glBegin(GL_POLYGON);
    glVertex3f (0.1, 0.1, 0.0);
    glVertex3f (0.4, 0.1, 0.0);
    glVertex3f (0.4, 0.5, 0.0);
    glVertex3f (0.1, 0.5, 0.0);
    glEnd();
    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.2, 0.3, 0.0);
    glVertex3f (0.3, 0.3, 0.0);
    glVertex3f (0.3, 0.1, 0.0);
    glEnd();
    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    glVertex3f (0.10, 0.5, 0.0);
    glVertex3f (0.4, 0.5, 0.0);
    glVertex3f (0.25, 0.75, 0.0);
    glEnd();
    glColor3ub(255,255,0);

    glBegin(GL_POLYGON);
    glVertex3f (0.4, 0.1, 0.0);
    glVertex3f (0.8, 0.4, 0.0);
    glVertex3f (0.8, 0.75, 0.0);
    glVertex3f (0.4, 0.5, 0.0);
    glEnd();
    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    glVertex3f (0.58, 0.231, 0.0);
    glVertex3f (0.65, 0.287, 0.0);
    glVertex3f (0.65, 0.45, 0.0);
    glVertex3f (0.58, 0.4, 0.0);
    glEnd();

    glColor3ub(210,105,30);

    glBegin(GL_POLYGON);
    glVertex3f (0.4, 0.5, 0.0);
    glVertex3f (0.8, 0.75, 0.0);
    glVertex3f (0.62, 0.93, 0.0);
    glVertex3f (0.25, 0.75, 0.0);
    glEnd();
}
void house_mod()
{
    glPushMatrix();
    glTranslatef(-40,-30,0);
    glScalef(20,20,0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,-35,0);
    glScalef(20,18,0);
    house();
    glPopMatrix();



}

void sun()
{

    glBegin(GL_POLYGON);

    float angle;
    for(int i=0; i<360; i++)
    {
        angle = i * 3.1416/180;
        glVertex2f(cos(angle)*0.1, sin(angle)*0.15);
    }

    glEnd();
    glFlush();

}
void sun_mod()
{
    glPushMatrix();
    glTranslatef(30,30,0);
    glScalef(40,45,0);
    sun();
    glPopMatrix();
}
void hill()
{
    glColor3ub(107,142,35);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.05, -0.3, 0.0);
    glVertex3f (0.2, -0.1, 0.0);
    glVertex3f (-0.1, -0.3, 0.0);
    glEnd();

    glColor3ub(85,107,47);

    glBegin(GL_TRIANGLES);
    glVertex3f (0.4, -0.3, 0.0);
    glVertex3f (0.2, -0.1, 0.0);
    glVertex3f (0.05, -0.3, 0.0);
    glEnd();

}

void hill_mod()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(50,50,0);
    hill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50,7,0);
    glScalef(70,70,0);
    hill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,7,0);
    glScalef(70,70,0);
    hill();



    glPopMatrix();
    glPushMatrix();
    glTranslatef(20,7,0);
    glScalef(70,70,0);
    hill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40,0,0);
    glScalef(50,50,0);
    hill();
    glPopMatrix();
}

void sky()
{

    glBegin(GL_POLYGON); //sky
    glVertex3f (50, -20, 0);
    glVertex3f (50, 50, 0);
    glVertex3f (-50, 50, 0);
    glVertex3f (-50, -20, 0);
    glEnd();
}

void star()
{

    glBegin(GL_POINTS);

    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(5.0,2.0);
    glVertex2f(-2.0,-7.0);
    glVertex2f(-3.0,6.0);
    glVertex2f(2.0,-5.0);

    glVertex2f(10,10);
    glVertex2f(30,30);
    glVertex2f(20,10);
    glVertex2f(9,9);

    glVertex2f(40,40);
    glVertex2f(30,20);
    glVertex2f(15,30);
    glVertex2f(10,40);

    glVertex2f(-10,10);
    glVertex2f(-30,30);
    glVertex2f(-20,10);
    glVertex2f(9,9);

    glVertex2f(-40,40);
    glVertex2f(-30,20);
    glVertex2f(-15,30);
    glVertex2f(-10,40);

    glVertex2f(-50,50);
    glVertex2f(-30,40);
    glVertex2f(-15,20);
    glVertex2f(-10,40);

    glVertex2f(0,50);
    glVertex2f(-5,40);
    glVertex2f(5,20);
    glVertex2f(0,10);
    glEnd( );
    glFlush( );
}


void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();
    if (transition)

        glColor3ub(0,0,0);

    else

        glColor3ub(135,206,235);


    sky();

    glPopMatrix();

    glPushMatrix();
    move_cloud();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.0,cy,0.0);
    parachute_mod();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,cy1,0.0);
    parachute_mod2();
    glPopMatrix();
    tree2_mod();
    tree2_mod2();
    tree2_mod3();
    tree2_mod4();
    hill_mod();

    glPushMatrix();
    if (transition)

        glColor3ub(25,25,112);

    else

        glColor3ub(65,105,225);

    river_mod();

    glPopMatrix();

    if (transition)

        glColor3ub(34,139,34);

    else

        glColor3ub(50,205,50);

    grass_mod();

    glPopMatrix();



    tree_mod();
    house_mod();
    tree_mod2();

    glPushMatrix();
    glPushMatrix();
    glTranslatef(x,0.0,0.0);
    boat_mod();
    glPopMatrix();



    glPushMatrix();
    if (transition)

        glColor3f(1.0, 1.0, 1.0);

    else

        glColor3f(1, 1, 0.0);
    sun_mod();
    glPopMatrix();

    glPushMatrix();

    if (transition)

        glColor3ub(225,225,225);



    else

        glColor3ub(135,206,235);


    star();

    glPopMatrix();

    glFlush();
}


void init(void)
{
    glClearColor (0, 0.749, 1, 0);
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

void spinDisplay()
{
    cy = cy + .005;
    if(cy>100)
        cy = -100;

    cy1 = cy1 + .007;
    if(cy1>100)
        cy1 = -100;

    glutPostRedisplay();
}




void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(spinDisplay);
        }

        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }

        break;
    default:
        break;
    }
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'n':

        transition = !transition;

    default:
        break;
    }
}

int main()
{
    printf("Press left mouse button to see parachute \n");
    printf("press 'n' to see the transition \n");
    printf("press right mouse button to pause the animation");

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1350, 690);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Village scenery");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
