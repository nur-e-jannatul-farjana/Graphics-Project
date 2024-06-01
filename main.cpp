#include<iostream>
#include <stdlib.h>
#include<Windows.h>
#include <GL/glut.h>
#include<MMSystem.h>
#include<GL/gl.h>
#include<math.h>

using namespace std;
float cx=0;
float cy=0;
float angle=0;
float time1=0;
float time2=0;
float time3=0;
char option1[]="press W to know WHAT IS GREENHOUSE EFFECT";
char option2[]="press C to know THE CAUSES OF GREENHOUSE EFFECT";
char option3[]="press A to know HOW TO AVOID GREENHOUSE EFFECT";
bool start=true;
bool what=false;
bool cause=false;
bool effect= false;
char ozen[]="Ozen layer";
float c = 0;

void initRendering()
{
    glEnable(GL_DEPTH_TEST);

}

void handleResize(int w,int h)  // resizing by adjusting the viewport and projection matrix settings
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);  //projection matrix is used to transform 3D points into 2D space for rendering.
    glLoadIdentity();
    gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
}

void NormalKey (GLubyte key,GLint x, GLint y)
{
    switch(key)
    {
    case 'w':
        start= false;
        cause= false;
        effect = false;
        what=true;
        glutPostRedisplay();
        break;

    case 'c':
        start= false;
        cause= true;
        effect = false;
        what=false;
        glutPostRedisplay();
        break;

    case 'a':
        start= false;
        cause= false;
        effect = true;
        what=false;
        glutPostRedisplay();
        break;


    }
}
void print(float x,float y, char *st)
{
    int l,i;

    l=strlen(st);  //see how many characters are in text string

    glColor3f(0.2,1.0,0.7);

    glRasterPos2f(x,y);
    for(int i =0; i<l; i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }

}

void drawCross(float x, float y)
{
    glPushMatrix();
    glTranslatef(x,y,0);
    glColor3f(1,0,0);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex3f(-0.975,-0.975,0);
    glVertex3f(-0.85,-0.75,0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-0.975,-0.975,0);
    glVertex3f(-0.85,-0.75,0);
    glEnd();
    glLineWidth(1);
    glPopMatrix();
}

void drawTimber(float x,float y)
{

    glPushMatrix();
    glScalef(5,5,0);
    glTranslatef(x,y,0.0);
    glColor3f(0.8235294110, 0.4117647059,0.1176470588);
    glBegin(GL_POLYGON);

    glVertex3f(0.0125,.01,0.0);
    glVertex3f(0.01,.00575,0.0);
    glVertex3f(0.005,0.0,0.0);
    glVertex3f(0.01,.0025,0.0);
    glVertex3f(0.013,.00375,0.0);
    glVertex3f(0.0175,.0025,0.0);
    glVertex3f(0.0225,0.0,0.0);
    glVertex3f(0.02,.0025,0.0);
    glVertex3f(0.01825,.007,0.0);
    glVertex3f(0.0225,.0075,0.0);
    glVertex3f(0.0275,.005,0.0);
    glVertex3f(0.03,.00425,0.0);
    glVertex3f(0.0325,.005,0.0);
    glVertex3f(0.03,.0065,0.0);
    glVertex3f(0.0275,.01,0.0);
    glVertex3f(0.0275,.0225,0.0);
    glVertex3f(0.0125,.0225,0.0);
    glEnd();
    glPopMatrix();

}
/* GLUT callback Handlers */

void drawSmoke(float x,float y)
{
    glPushMatrix();
    glTranslatef(0.02+x,0.6+y,0.0);
    glColor3f(0.247,0.196,0.199);
    glBegin(GL_POLYGON);

    for(int i =0; i<600; i++)
        {
            float pi = 3.1416;
            float A = (i*2*pi)/100;
            float r = 0.05;
            float x= r * cos(A);
            float y = r* sin(A);
            glVertex2f(x,y);
         }

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.07+x,0.6+y,0.0);
    glColor3f(0.247,0.196,0.199);
    glBegin(GL_POLYGON);

    for(int i =0; i<600; i++)
    {
         float pi=3.1416;

         float A = (i*2*pi)/100;
         float r = 0.05;
         float x= r * cos(A);
         float y = r* sin(A);
            glVertex2f(x,y);
    }

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0+x,0.65+y,0.0);
    glColor3f(0.247,0.196,0.199);
    glBegin(GL_POLYGON);


      for(int i =0; i<600; i++)
    {
         float pi=3.1416;

         float A = (i*2*pi)/100;
         float r = 0.05;
         float x= r * cos(A);
         float y = r* sin(A);
            glVertex2f(x,y);
    }

    glEnd();
    glPopMatrix();
}

void drawCar(float _angle,float d,float e)
{

    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(-2.98+d,0.55+e,0.0);
    glRotatef(_angle,0.0,0.0,-1.0);
    glColor3f(0.10,.10,.10);
    glutSolidSphere(.10,40,25);
    glPopMatrix();


    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(-2.3+d,0.55+e,0.0);
    glRotatef(_angle,0.0,0.0,-1.0);
    glColor3f(0.10,.10,.10);
    glutSolidSphere(.10,40,5);
    glPopMatrix();



    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(-.40+d,0.35+e,0.0);
    glColor3f(0.40,0.40,0.40);
    glBegin(GL_POLYGON);
    glVertex3f(-1.77+d,0.46,0.0);
    glVertex3f(-1.87+d,0.63,0.0);
    glVertex3f(-2.04+d,0.63,0.0);
    glVertex3f(-2.04+d,0.46,0.0);
    glEnd();
    glPopMatrix();

    //Body 1.53 min

    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(-0.40,0.350+e,0.0);
    glColor3f(0.70,0.70,0.70);
    glBegin(GL_POLYGON);
    glVertex3f(-2.05+d,0.15,0.0);
    glVertex3f(-1.65+d,0.15,0.0);
    glVertex3f(-1.6+d,0.20,0.0);
    glVertex3f(-1.60+d,0.28,0.0);
    glVertex3f(-1.62+d,0.28,0.0);
    glVertex3f(-1.64+d,0.40,0.0);
    glVertex3f(-1.64+d,0.40,0.0);
    glVertex3f(-1.76+d,0.48,0.0);
    glVertex3f(-1.86+d,0.64,0.0);
    glVertex3f(-2.05+d,0.64,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(-0.40,0.350+e,0.0);
    glColor3f(0.20,0.20,0.20);
    glBegin(GL_POLYGON);
    glVertex3f(-2.05+d,0.74,0.0);
    glVertex3f(-2.75+d,0.74,0.0);
    glVertex3f(-2.75+d,0.14,0.0);
    glVertex3f(-2.05+d,0.14,0.0);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(-0.40,0.35+e,0.0);
    glColor3f(0.140,0.140,0.140);
    glBegin(GL_POLYGON);
    glVertex3f(-2.77+d,0.19,0.0);
    glVertex3f(-2.75+d,0.19,0.0);
    glVertex3f(-2.75+d,0.18,0.0);
    glVertex3f(-2.77+d,0.18,0.0);
    glEnd();
    glPopMatrix();



}


void drawArrowIncoming(float x,float y,float a,float b, float c)
{
    glColor3f(a,b,c);
    glPushMatrix();
    glTranslatef(x,y,0.0);

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex3f(-0.033,0.2,0.0);
    glVertex3f(0.12,0.1,0.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.085,0.1,0.0);
    glVertex3f(0.085,0.1,0.0);
    glVertex3f(0.12,0.1,0.0);
    glEnd();

    glBegin(GL_LINES);
    glBegin(GL_LINES);
    glVertex3f(0.13,0.12,0.0);
    glVertex3f(0.12,0.1,0.0);
    glEnd();
    glPopMatrix();



}

void drawArrowOutgoing(float x,float y,float a,float b, float c)
{
    glColor3f(a,b,c);
    glPushMatrix();
    glLineWidth(2.0);
    glTranslatef(x,y,0.0);

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex3f(0.07,0.1,0.0);
    glVertex3f(0.22,0.2,0.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.15,0.18,0.0);
    glVertex3f(0.22,0.2,0.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.22,0.18,0.0);
    glVertex3f(0.22,0.18,0.0);
    glVertex3f(0.22,0.2,0.0);
    glEnd();
    glLineWidth(1.0);
    glPopMatrix();


}

void drawArrowStraight(float x,float y,float a,float b, float c)
{
    glColor3f(a,b,c);
    glPushMatrix();
    glLineWidth(2.0);
    glTranslatef(x,y,0.0);

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.15,0.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.02,0.14,0.0);
    glVertex3f(0.0,0.15,0.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.02,0.14,0.0);
    glVertex3f(0.0,0.15,0.0);

    glEnd();
    glLineWidth(1.0);
    glPopMatrix();

}

void drawArrowDown(float x,float y,float a,float b, float c)
{
    glColor3f(a,b,c);
    glPushMatrix();
    glLineWidth(2.0);
    glTranslatef(x,y,0.0);

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.15,0.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.02,0.01,0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.02,0.01,0.0);
    glVertex3f(0.0,0.0,0.0);

    glEnd();
    glLineWidth(1.0);
    glPopMatrix();

}

void drawCfc(float x,float y)
{
    glPushMatrix(); //copy matrix
    glScalef(7,7,0);
    glTranslatef(x,y,0.0);
    glColor3f(0.432941176,0.0,.0667);
    glBegin(GL_POLYGON);
    glVertex3f(0.0005,0.02125,0.0);
    glVertex3f(0.0005,0.00125,0.0);
    glVertex3f(0.0025,0.00075,0.0);
    glVertex3f(0.005,0.0005,0.0);
    glVertex3f(0.0075,0.00125,0.0);
    glVertex3f(0.0075,0.02125,0.0);
    glEnd();
    glPopMatrix();  //restore

    glPushMatrix();
    glScalef(7,7,0);
    glTranslatef(x,y,0.0);
    glColor3f(0.2509803922,0.0,0);
    glBegin(GL_POLYGON);
    glVertex3f(0.00125,0.0225,0.0);
    glVertex3f(0.0005,0.02125,0.0);
    glVertex3f(0.0025,0.0205,0.0);
    glVertex3f(0.005,0.02,0.0);
    glVertex3f(0.0075,0.02025,0.0);
    glVertex3f(0.0075,0.0225,0.0);
    glVertex3f(0.005,0.022,0.0);
    glVertex3f(0.0025,0.022,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScalef(7,7,0);
    glTranslatef(x,y,0.0);
    glColor3f(0.5019607843,0.2509803922,0.2809803922);
    glBegin(GL_POLYGON);
    glVertex3f(0.003,0.025,0.0);
    glVertex3f(0.00125,0.0225,0.0);
    glVertex3f(0.0025,0.022,0.0);
    glVertex3f(0.005,0.022,0.0);
    glVertex3f(0.0075,0.0225,0.0);
    glVertex3f(0.00725,0.024,0.0);
    glVertex3f(0.00625,0.025,0.0);
    glVertex3f(0.005,0.02375,0.0);
    glVertex3f(0.00375,0.024,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScalef(7,7,0);
    glTranslatef(x,y,0.0);
    glColor3f(0.5019607843,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.00375,0.02725,0.0);
    glVertex3f(0.003,0.025,0.0);
    glVertex3f(0.0375,0.024,0.0);
    glVertex3f(0.005,0.02375,0.0);
    glVertex3f(0.00625,0.025,0.0);
    glVertex3f(0.006,0.0275,0.0);
    glVertex3f(0.00625,0.025,0.0);
    glVertex3f(0.006,0.0275,0.0);
    glVertex3f(0.00675,0.03,0.0);
    glVertex3f(0.00475,0.0295,0.0);
    glEnd();
    glPopMatrix();



}


void drawBrickFieldLeft(float x,float y)
{
    //2.06 min
    glColor3f(0.6f,0.2f,0.0f);
    glPushMatrix();
    glTranslatef(x,y,0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.475,-0.375,0);
    glVertex3f(-0.5,0.-0.5,0);
    glVertex3f(-0.375,-0.5,0);
    glVertex3f(-0.4,-0.375,0);
    glVertex3f(-0.375,-0.25,0);
    glVertex3f(-0.5,-0.25,0);

    glEnd();
    glPopMatrix();

}
void drawBrickFieldRight(float x,float y)
{

    glColor3f(0.6f,0.2f,0.0f);
    glPushMatrix();
    glScalef(1,2,0);
    glTranslatef(x,y,0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.325,-.25,0);
    glVertex3f(0.55,-0.25,0);
    glVertex3f(0.5,0,0);
    glVertex3f(0.375,0,0);


    glEnd();
    glPopMatrix();

}

void drawTree(float x, float y)
{
   glPushMatrix();
   glScalef(15,20,0);
   glTranslatef(x,y,0.0);
   glColor3f(0.5333333,0,0.08235294118);
   glBegin(GL_POLYGON);

   glVertex3f(0.0,0.01425,0.0);
   glVertex3f(-.00225,0.015,0.0);
   glVertex3f(-.005,0.0175,0.0);
   glVertex3f(-.00675,0.01675,0.0);
   glVertex3f(-.0025,0.01325,0.0);
   glVertex3f(-.00025,0.01,0.0);
   glVertex3f(0,0,0.0);
   glVertex3f(.0025,0,0.0);
   glVertex3f(.00475,0.0125,0.0);
   glVertex3f(.005,0.015,0.0);
   glVertex3f(.009,0.0225,0.0);
   glVertex3f(.007,0.02325,0.0);
   glVertex3f(.00525,0.01875,0.0);
   glVertex3f(.00525,0.01875,0.0);
   glVertex3f(.0025,0.015,0.0);

    glEnd();
    glPopMatrix();

    //2.09 min
    glPushMatrix();
    glScalef(20,20,0);
    glTranslatef(x,y,0.0);
    glColor3f(0.305,0.541,0.192);
    glBegin(GL_POLYGON);
    glVertex3f(-0.0105,0.02225,0.0);
    glVertex3f(-0.0025,0.027,0.0);
    glVertex3f(-0.014,0.02,0.0);
    glVertex3f(-0.0025,0.027,0.0);
    glVertex3f(-0.01425,0.0175,0.0);
    glVertex3f(-0.001225,0.015,0.0);
    glVertex3f(-0.00875,0.0155,0.0);
    glVertex3f(-0.00475,0.01875,0.0);
    glVertex3f(-0.00325,0.023,0.0);
    glVertex3f(-0.0005,0.0195,0.0);
    glVertex3f(0.00325,0.02,0.0);
    glVertex3f(0.00525,0.0225,0.0);
    glVertex3f(0.0065,0.024,0.0);
    glVertex3f(0.0065,0.024,0.0);
    glVertex3f(0.01,0.023,0.0);
    glVertex3f(0.0105,0.01925,0.0);
    glVertex3f(0.01375,0.01875,0.0);
    glVertex3f(0.0175,0.0225,0.0);
    glVertex3f(0.01725,0.025,0.0);
    glVertex3f(0.015,0.027,0.0);
    glVertex3f(0.0125,0.0275,0.0);
    glVertex3f(0.0105,0.0265,0.0);
    glVertex3f(0.01,0.03,0.0);
    glVertex3f(0.0075,0.0325,0.0);
    glVertex3f(0.0025,0.03225,0.0);
    glVertex3f(-0.00175,0.029,0.0);
    glVertex3f(-0.0025,0.027,0.0);
    glVertex3f(-0.0075,0.0275,0.0);
    glVertex3f(-0.01,0.0265,0.0);
    glVertex3f(-0.01125,0.025,0.0);
    glEnd();
    glPopMatrix();


}

void drawCloud(float x,float y)
{
    glPushMatrix();
    glTranslatef(0.0+x, 0.6+y, 0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);



    for(int i=0;i<600;i++)

    {
    float pi=3.1416;
    float A=(i*2*pi)/100;
    float r=0.05;
    float x= r * cos(A);
    float y= r * sin(A);
    glVertex2f(x,y);


    }
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.08+x, 0.6+y, 0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);



     for(int i=0;i<600;i++)

    {
    float pi=3.1416;
    float A=(i*2*pi)/100;
    float r=0.05;
    float x= r * cos(A);
    float y= r * sin(A);
    glVertex2f(x,y);


    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.15+x, 0.6+y, 0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);


     for(int i=0;i<600;i++)

    {

    float pi=3.1416;

    float A=(i*2*pi)/100;
    float r=0.05;
    float x= r * cos(A);
    float y= r * sin(A);
    glVertex2f(x,y);


    }

    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0+x, 0.65+y, 0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);


     for(int i=0;i<600;i++)

    {

    float pi=3.1416;
    float A=(i*2*pi)/100;
    float r=0.05;
    float x= r * cos(A);
    float y= r * sin(A);
    glVertex2f(x,y);

    }

    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.08+x, 0.65+y, 0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);


     for(int i=0;i<600;i++)

    {

    float pi=3.1416;
    float A=(i*2*pi)/100;
    float r=0.05;
    float x= r * cos(A);
    float y= r * sin(A);
    glVertex2f(x,y);

    }

    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.15+x, 0.65+y, 0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);


     for(int i=0;i<600;i++)

    {

    float pi=3.1416;
    float A=(i*2*pi)/100;
    float r=0.05;
    float x= r * cos(A);
    float y= r * sin(A);
    glVertex2f(x,y);

    }

    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.06+x, 0.62+y, 0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);

     for(int i=0;i<600;i++)

    {

    float pi=3.1416;
    float A=(i*2*pi)/100;
    float r=0.05;
    float x= r * cos(A);
    float y= r * sin(A);
    glVertex2f(x,y);


    }

    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.19+x, 0.62+y, 0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);


    for(int i=0;i<600;i++)

    {

    float pi=3.1416;
    float A=(i*2*pi)/100;
    float r=0.05;
    float x= r * cos(A);
    float y= r * sin(A);
    glVertex2f(x,y);


    }

    glEnd();
    glPopMatrix();

}


void drawScene()
{
    glClearColor(0.45,0.45,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    float _angle=0;
    float d = 2.5;
    float e = -1.8;

    if(start)
    {
        glClearColor(0.0,0.45,0.66,0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        print(-0.9,.9,option1);
        print(-0.9,.8,option2);
        print(-0.9,.7,option3);
    }
    else if(what)
    {
        mciSendString("play paral.way", NULL,0,NULL);

        print(0.6,0.6,ozen);


        ////// sun /////
        glPushMatrix();
        glTranslatef(-0.9,0.9,0.0);
        glColor3f(1.0,.0,0.0);
        glBegin(GL_POLYGON);


        for(int i=0; i<600; i++)
        {
            float pi=3.1416;
            float A= (i*2*pi)/100;
            float r = 0.2;
            float x = r*cos(A);
            float y = r*sin(A);
            glVertex2f(x,y);
        }

        glEnd();
        glPopMatrix();



        ///// clouds /////

        drawCloud(0,0);
        drawCloud(-0.80,-.04);


        if (time1 < 400 )
        {
            drawArrowIncoming(-0.9+cx,0.8+cy,1,0,0);
            drawArrowIncoming(-0.9+cx/2,0.8+cy,1,0,0);
            drawArrowIncoming(-0.9+cx/5,0.8+cy,1,0,0);
        }

        else if (time1> 400 && time1 < 600)
        {
               drawArrowIncoming(-0.9+cx,0.8+cy,0.603,.27,.603);

        }

         else if (time1> 600 && time1 < 700)
        {
               drawArrowOutgoing(-0.6+cx,0.45+cy,0.603,.27,.603);

        }
         else if (time1> 700 && time1 < 800)
        {
               drawArrowIncoming(-0.9+cx,0.8+cy,1,0,0);

        }

         else if (time1> 8000 && time1 < 10000)
        {
               drawArrowStraight(cx,cy,1,0,0);

        }

         else if (time1> 1000 && time1 < 1200)
        {
               drawArrowIncoming(-0.9+cx,0.8+cy,1,0,0);

        }

           else if (time1> 1200 && time1 < 1500)
        {
               drawArrowStraight(cx,cy,1,0,0);
               drawArrowStraight(-0.05+cx,cy,1,0,0);
               drawArrowStraight(0.05+cx,cy,1,0,0);

        }

           else if (time1> 1500 && time1 < 2200)
        {
               drawArrowDown(cx,.4+cy,1,0,0);
               drawArrowDown(-0.05+cx,.4+cy,1,0,0);
               drawArrowDown(0.05+cx,0.4+cy,1,0,0);

        }

        if (time1 > 2400)
        {
            mciSendString("stop paral.way",NULL,0,NULL);
            start=false;
            cause=false;
            effect=false;
            what=false;
            glutPostRedisplay();
        }

        //// atmosphere ////
        for(float r=2.0; r<=2.2; r+=.01)
        {
            glPushMatrix();
            glPointSize(2.0);
            glTranslatef(.0,-1.5,0.0);
            glTranslatef(.0,-1.5,0.0);
            glColor3f(0.752,0.752,0.752);
            glBegin(GL_LINE_STRIP);

             for(int i=0; i<600; i++)
             for(int i=0; i<600; i++)
    {
            float pi=3.1416;
            float A= (i*2*pi)/100;
           // float r = 1.7;
            float x = r*cos(A);
            float y = r*sin(A);
            glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();



    }


    ///// earth ////

    glPushMatrix();
    glTranslatef(0.0,-1.5,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);


    for(int i=0; i<600; i++)
    {
            float pi=3.1416;
            float A= (i*2*pi)/100;
            float r = 1.7;
            float x = r*cos(A);
            float y = r*sin(A);
            glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
    }

    else if (cause)
    {
        mciSendString("stop paral.way",NULL,0,NULL);
        mciSendString("stop para3.way",NULL,0,NULL);

        print(0.6,0.6,ozen);


        //// sun ////

           ////// sun /////
        glPushMatrix();
        glTranslatef(-0.9,0.9,0.0);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);


        for(int i=0; i<600; i++)
        {
            float pi=3.1416;
            float A= (i*2*pi)/100;
            float r = 0.2;
            float x = r*cos(A);
            float y = r*sin(A);
            glVertex2f(x,y);
        }

        glEnd();
        glPopMatrix();


        ///// clouds ////


        drawCloud(0,0);
        drawCloud(-0.80,-.04);

        if (time2>0)
        {
            if(time2>0)
            {
                mciSendString("play para2.way",NULL,0,NULL);
                drawTimber(-0.130,-0.02);
            }


            if(time2>300)
            {
                drawTimber(-0.150,-.01);
            }

            if(time2>600)
            {
                drawTimber(-0.170,-.02);
            }
            if(time2>900)
            {
                drawTimber(-0.150,-.04);
            }
            if(time2>1200)
            {
                drawTimber(-0.115,-.04);
            }
            if(time2>1500)
            {
                drawTimber(-0.185,-.04);
            }
            if(time2>3000)
            {
               drawCfc(.01,0);
               drawCfc(.02,0);
            }
            if(time2>6000)
               drawCar(_angle,d,e);

            }

            if(time2>6500 && time2 <10000)
            {
                drawSmoke(-0.45,-1.2+c);
            }

            if(time2>8000)
            {
                drawBrickFieldLeft(1,.2);
            }
             if(time2>8000)
            {
                drawBrickFieldRight(0.35,.2);
                drawSmoke(0.5,-0.3);
                drawSmoke(0.5,-0.3);
                drawSmoke(0.6,-0.2);
                drawSmoke(0.7,-0.3);
                drawSmoke(0.75,-0.25);
            }

            if(time2>10000)
            {
                mciSendString("play para1.way",NULL,0,NULL);
                mciSendString("play para2.way",NULL,0,NULL);
                mciSendString("play para3.way",NULL,0,NULL);

                start=false;
                cause=false;
                what=false;
                glutPostRedisplay();
                drawTimber(-0.130,-0.02);
            }


            ////atmosphere ////
            for(float r = 2.0; r<=2.2; r+=0.01)
            {
            glPushMatrix();
            glPointSize(2.0);
            glTranslatef(.0,-1.5,0.0);

            glColor3f(0.752,0.752,0.752);
            glBegin(GL_LINE_STRIP);

            for(int i =0;i<600;i++)
            {
            float pi=3.1416;
            float A= (i*2*pi)/100;

            float x = r*cos(A);
            float y = r*sin(A);
            glVertex2f(x,y);
        }

        glEnd();
        glPopMatrix();

        }

        //// earth ///

         glPushMatrix();
    glTranslatef(0.0,-1.5,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);


    for(int i=0; i<600; i++)
    {
            float pi=3.1416;
            float A= (i*2*pi)/100;
            float r = 1.7;
            float x = r*cos(A);
            float y = r*sin(A);
            glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
    }

     else if(effect)
     {
         mciSendString("stop paral.way",NULL,0,NULL);
        mciSendString("stop para2.way",NULL,0,NULL);

        /// sun ///


        glPushMatrix();
        glTranslatef(-0.9,0.9,0.0);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);


        for(int i=0; i<600; i++)
        {
            float pi=3.1416;
            float A= (i*2*pi)/100;
            float r = 0.2;
            float x = r*cos(A);
            float y = r*sin(A);
            glVertex2f(x,y);
        }

        glEnd();
        glPopMatrix();


        //// clouds ///

        drawCloud(0,0);
        drawCloud(-0.80,-.04);
 mciSendString("play para2.way",NULL,0,NULL);
 print(.6,.6,ozen);

       if(time3>500)
            {

                drawTimber(-0.130,-0.02);
                drawTimber(-0.150,-0.01);
                drawTimber(-0.170,-0.02);
                drawTimber(-0.150,-0.04);
                drawTimber(-0.115,-0.04);
                drawTimber(-0.185,-0.04);
                drawCar(_angle,d,e);
            }


            if(time3>500)
            {
                drawTree(-0.025,-.01);
            }

            if(time3>600)
            {
                drawTimber(-0.035,-.005);
            }
            if(time3>3500)

            {
                if((int)time3%500<200)
                {
                    drawCross(1.05,1);
                }
                drawCfc(.01,0);
                drawCfc(.02,0);
            }
            if(time3>5000)
            {
                 if((int)time3%500<200)
                {
                    drawCross(1.5,0.7);
                    drawCross(1.6,0.8);
                    drawCross(1.7,0.9);
                }
              drawBrickFieldLeft(1,.2);
              drawBrickFieldRight(.35,.1);
              drawSmoke(0.5,-.3);
              drawSmoke(0.6,-.2);
              drawSmoke(0.7,-.3);
              drawSmoke(0.75,-.25);

            }
            if(time3>6000)
            {
                mciSendString("stop para3.way",NULL,0,NULL);
            }


            /// atmosphere ///
            for(float r=2.0;r<=2.2; r+=.01)
            {
            glPushMatrix();
            glPointSize(2.0);
            glTranslatef(.0,-1.5,0.0);

            glColor3f(0.752,0.752,0.752);
            glBegin(GL_LINE_STRIP);


            for (int i =0; i<600; i++)
            {
            float pi=3.1416;
            float A= (i*2*pi)/100;

            float x = r*cos(A);
            float y = r*sin(A);
            glVertex2f(x,y);

            }

            glEnd();
            glPopMatrix();
            }


            ///// earth /////


             glPushMatrix();
    glTranslatef(0.0,-1.5,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);


    for(int i=0; i<600; i++)
    {
            float pi=3.1416;
            float A= (i*2*pi)/100;
            float r = 1.7;
            float x = r*cos(A);
            float y = r*sin(A);
            glVertex2f(x,y);
    }

      glEnd();
      glPopMatrix();

     }

     glutSwapBuffers();


}


void update(int value)
{
    if(what)
    {
        time1 += 25;

        if(time1 <4000)
        {
            cx +=.01;
            cy -=.01;
            angle = 300;

            if(cy< -0.7)
            {
                cx = 0;
                cy = 0;
            }

            if(time1 > 3800)
            {
                cx = 0;
                cy = 0;
            }
        }


        else if (time1> 4000 && time1 <6000)
        {
            cx +=.01;
            cy -= .01;

            if(cy < -0.3)
            {
                cx =0;
                cy = 0;
            }

            if(time1 > 5900)
            {
                cx =0;
                cy = 0;
            }

        }

          else if (time1> 6000 && time1 <7000)
        {
            cx +=.01;
            cy -= .01;

            if(cy > 0.2)
            {
                cx =0;
                cy = 0;
            }

            if(time1 > 6900)
            {
                cx =0;
                cy = 0;
            }

        }
        else if (time1> 7000 && time1 <8000)
        {
            cx +=.01;
            cy -= .01;
            angle = 300;
            if(cy < -0.7)
            {
                cx =0;
                cy = 0;
            }

            if(time1 > 7900)
            {
                cx =0;
                cy = 0;
            }

        }
        else if (time1> 8000 && time1 <10000)
        {
          //  cx +=.01;
            cy -= .01;

            if(cy < 0.3)
            {
                cx =0;
                cy = 0;
            }

            if(time1 > 9900)
            {
                cx =0;
                cy = 0;
            }

        }
        else if (time1> 10000 && time1 <12000)
        {
            cx +=.01;
            cy -= .01;
            angle=300;

            if(cy < -0.7 )
            {
                cx =0;
                cy = 0;
            }
            if(time1 > 11900)
            {
                cx =0;
                cy = 0;
            }



        }
         else if (time1> 12000 && time1 <15000)
        {
          //  cx +=.01;
            cy -= .01;

               if(cy > 0.3 )
            {
                cx =0;
                cy = 0;
            }

            if(time1 > 14900)
            {
                cx =0;
                cy = 0;
            }



        }
         else if (time1> 15000 && time1 <24000)
        {
          //  cx +=.01;
            cy -= .01;

               if(cy <- 0.3 )
            {
                cx =0;
                cy = 0;
            }

            if(time1 > 23900)
            {
                cx =0;
                cy = 0;
            }



        }



    }

    if(cause)
    {
        time2 +=25;

        if(time2>6000)
        {
            c +=.001;
        }
    }

    if(effect)
    {
        time3 +=25;

    }

    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}

int main(int argc, char** argv)
{
    //initialize glut
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  //sets the initial display mode for the rendering context
    glutInitWindowSize(800,800);


    //Create the window

    glutCreateWindow("Green House Effect");
    initRendering();

    //set handler function
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);

    glutKeyboardFunc(NormalKey);

    glutTimerFunc(5, update,0);

    glutMainLoop();
    return 0;


}
