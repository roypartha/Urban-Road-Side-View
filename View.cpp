#include <windows.h>
#include <stdio.h>
#include <iostream>
#include<cstdio>
#include<conio.h>
#include<math.h>
#include<mmsystem.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<cstdlib>


using namespace std;

float xpos,ypos,prex,prey,nex,ney,radius=0.04f;;
int steps=200;
float angle=3.1415426*2.f/steps;

float rain = 0.0f;
bool rainday = false;

bool night = false;

GLfloat positionCar3 = 0.0f, positionCar4 = 0.0f, positionCar1=0.0f,positionCar2=0.0f,positionBoat=0.0f;
GLfloat poisitionCloud1=0.0f,poisitionCloud2=0.0f,poisitionCloud3=0.0f,poisitionCloud4=0.0f,positionplane=0.0f;
GLfloat speed =- 0.05f, speedcar4=-0.08f,speedcar1=0.06f,speedcar2=0.06f, speedboat=-0.02f;
GLfloat speedcloud1=-0.002f,speedcloud2=-0.002f,speedcloud3=-0.002f,speedcloud4=-0.002f,speedplane=-0.02f;




void Rain(int value){

if(rainday){

    rain += 0.06f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand();
        int y=rand();
        x%=1300; y%=750;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+0.1,y+0.1);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);


    glFlush();

    }
}
void treecircle(GLfloat xpos, GLfloat ypos, GLfloat radius){

glBegin(GL_TRIANGLE_FAN);

glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
if(night){
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
}
glVertex2d(xpos, ypos); // center of circle
for(int i = 0; i <= steps; i++)
{
glColor3f(0.0f, 1.0f, 0.0f);
glVertex2d(
 xpos+ (radius * cos(i * angle)),
ypos + (radius * sin(i * angle))
);

}
glEnd();
}



void plane(){
    xpos=0.4f;
    ypos=0.85f;
    radius=0.04f;
glBegin(GL_TRIANGLE_FAN);

glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
glVertex2d(xpos, ypos); // center of circle
for(int i = 0; i <= steps; i++)
{
glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
glVertex2d(
 xpos+ (radius * cos(i * angle)),
ypos + (radius * sin(i * angle))
);

}
glEnd();

glBegin(GL_QUADS);///...................
glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
glVertex2f( 0.4f,0.89f);
glVertex2f( 0.4f,0.81f);
glVertex2f( 0.53f,0.81f);
glVertex2f( 0.59f,0.89f);
glEnd();

glBegin(GL_QUADS);///...................
glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
glVertex2f( 0.53f,0.89f);
glVertex2f( 0.59f,0.89f);
glVertex2f( 0.64f,0.93f);
glVertex2f( 0.60f,0.93f);
glEnd();

glBegin(GL_QUADS);///...................
glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
glVertex2f( 0.60f,0.93f);
glVertex2f( 0.64f,0.93f);
glVertex2f( 0.65f,0.95f);
glVertex2f( 0.61f,0.95f);
glEnd();

glBegin(GL_QUADS);///...................
glColor3f(0.0f, 1.0f, 0.0f);
glVertex2f( 0.43f,0.81f);
glVertex2f( 0.46f,0.81f);
glVertex2f( 0.46f,0.83f);
glVertex2f( 0.43f,0.83f);
glEnd();

glBegin(GL_QUADS);///...................
glColor3f(0.0f, 1.0f, 0.0f);
glVertex2f( 0.43f,0.82f);
glVertex2f( 0.47f,0.80f);
glVertex2f( 0.50f,0.83f);
glVertex2f( 0.49f,0.85f);
glEnd();

glBegin(GL_QUADS);///...................
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f( 0.42f,0.84f);
glVertex2f( 0.44f,0.84f);
glVertex2f( 0.44f,0.86f);
glVertex2f( 0.42f,0.86f);
glEnd();

glBegin(GL_QUADS);///...................
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f( 0.46f,0.84f);
glVertex2f( 0.48f,0.84f);
glVertex2f( 0.48f,0.86f);
glVertex2f( 0.46f,0.86f);
glEnd();

glBegin(GL_QUADS);///...................
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f( 0.50f,0.84f);
glVertex2f( 0.52f,0.84f);
glVertex2f( 0.52f,0.86f);
glVertex2f( 0.50f,0.86f);
glEnd();
}


void Sun(GLfloat xpos, GLfloat ypos, GLfloat radius)
{

glBegin(GL_TRIANGLE_FAN);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2d(xpos, ypos); // center of circle
for(int i = 0; i <= steps; i++)
{
    if(night){
         glColor3f(1.0f, 1.0f, 1.0f);
    }
    else{
         glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    }



glVertex2d(
 xpos+ (radius * cos(i * angle)),
ypos + (radius * sin(i * angle))
);
}
glEnd();
}


void drawCircle(GLfloat xpos, GLfloat ypos, GLfloat radius)
{


glBegin(GL_TRIANGLE_FAN);
glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
if(night){
    glColor3ub(192, 192, 192);
}
glVertex2d(xpos, ypos); // center of circle
for(int i = 0; i <= steps; i++)
{
    if(night){
    glColor3ub(192, 192, 192);
    }
    else
        glColor4f(1.0f, 1.0f, 1.0f, 0.0f);

    glVertex2d(
    xpos+ (radius * cos(i * angle)),
     ypos + (radius * sin(i * angle))
);
}
glEnd();
}


void Cloud1(){
    glPushMatrix();
     glTranslatef(poisitionCloud2,0.0f, 0.0f);

    drawCircle(-0.65f,0.85f,0.06f);
    drawCircle(-0.55f,0.85f,0.06f);
    drawCircle(-0.60f,0.88f,0.05f);
   glPopMatrix();

   }


void Cloud2(){

   glPushMatrix();
     glTranslatef(poisitionCloud1,0.0f, 0.0f);

    drawCircle(-0.85f,0.85f,0.04f);
    drawCircle(-0.80f,0.85f,0.04f);
    drawCircle(-0.83f,0.88f,0.04f);
   glPopMatrix();
   }

void Cloud3(){
    glPushMatrix();
     glTranslatef(poisitionCloud3,0.0f, 0.0f);

    drawCircle(-0.15f,0.85f,0.06f);
    drawCircle(-0.05f,0.85f,0.05f);
    drawCircle(-0.10f,0.88f,0.07f);
   glPopMatrix();
   }
void Cloud4(){
   glPushMatrix();
     glTranslatef(poisitionCloud4,0.0f, 0.0f);

    drawCircle(0.35f,0.85f,0.06f);
    drawCircle(0.40f,0.86f,0.05f);
    drawCircle(0.30f,0.88f,0.07f);
    drawCircle(0.37f,0.83f,0.06f);

   glPopMatrix();

   }

void update(int value) {

   if(positionCar3 < -2.0f){
        positionCar3 = 1.80f;
   }
    positionCar3 += speed;

	if(positionCar4 < -2.0f){
    positionCar4 = 1.80f;
    }
    positionCar4 += speedcar4;


    if(positionCar1 >2.00f)
        positionCar1 = -1.80f;

    positionCar1 += speedcar1;

    if(positionCar2 >2.00f)
        positionCar2 = -1.80f;

    positionCar2 += speedcar2;

    if(positionplane < -1.5f){
    positionplane = 1.5f;
    }
    positionplane += speedplane;

    if(positionBoat < -2.0f){
        positionBoat = 2.0f;
    }
    positionBoat += speedboat;


    if(poisitionCloud1 <-1.2f)
        poisitionCloud1 = 1.3f;

    poisitionCloud1 += speedcloud1;



	if(poisitionCloud2 <-1.2f)
        poisitionCloud2 = 1.3f;

    poisitionCloud2 += speedcloud2;

    if(poisitionCloud3 <-1.2f)
        poisitionCloud3 = 1.3f;

    poisitionCloud3 += speedcloud3;

    if(poisitionCloud4 <-1.2f)
        poisitionCloud4 = 1.3f;

    poisitionCloud4 += speedcloud4;





	glutPostRedisplay();

	glutTimerFunc(100, update, 0);
}

star(){
    ///star (start).....................

if(night){
      ///star..1

glBegin(GL_QUADS);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.85f, 0.85f);
      glVertex2f( -0.85f, 0.86f);
      glVertex2f( -0.86f, 0.86f);
      glVertex2f( -0.86f, 0.85f);

      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.85f, 0.85f);
      glVertex2f( -0.85f, 0.86f);
      glVertex2f( -0.83f,  0.86f);
      glEnd();

glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.85f, 0.86f);
      glVertex2f( -0.86f, 0.86f);
      glVertex2f( -0.855f,  0.88f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.85f, 0.85f);
      glVertex2f( -0.85f, 0.86f);
      glVertex2f( -0.88f,  0.858f);
      glEnd();

       glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.85f, 0.85f);
      glVertex2f( -0.86f, 0.85f);
      glVertex2f( -0.855f,  0.83f);
      glEnd();


///star2

glBegin(GL_QUADS);
     glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.65f, 0.85f);
      glVertex2f( -0.65f, 0.86f);
      glVertex2f( -0.66f, 0.86f);
      glVertex2f( -0.66f, 0.85f);

      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.65f, 0.85f);
      glVertex2f( -0.65f, 0.86f);
      glVertex2f( -0.63f,  0.86f);
      glEnd();

glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.65f, 0.86f);
      glVertex2f( -0.66f, 0.86f);
      glVertex2f( -0.655f,  0.88f);
      glEnd();

      glBegin(GL_TRIANGLES);
     glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.65f, 0.85f);
      glVertex2f( -0.65f, 0.86f);
      glVertex2f( -0.68f,  0.858f);
      glEnd();

       glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.65f, 0.85f);
      glVertex2f( -0.66f, 0.85f);
      glVertex2f( -0.655f,  0.83f);
      glEnd();

   ///star 3..........

    glBegin(GL_QUADS);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( 0.65f, 0.85f);
      glVertex2f( 0.65f, 0.86f);
      glVertex2f( 0.66f, 0.86f);
      glVertex2f( 0.66f, 0.85f);

      glEnd();

      glBegin(GL_TRIANGLES);
     glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( 0.65f, 0.85f);
      glVertex2f( 0.65f, 0.86f);
      glVertex2f( 0.63f,  0.86f);
      glEnd();

glBegin(GL_TRIANGLES);
     glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( 0.65f, 0.86f);
      glVertex2f( 0.66f, 0.86f);
      glVertex2f( 0.655f,  0.88f);
      glEnd();

      glBegin(GL_TRIANGLES);
     glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( 0.65f, 0.85f);
      glVertex2f( 0.65f, 0.86f);
      glVertex2f( 0.68f,  0.858f);
      glEnd();

       glBegin(GL_TRIANGLES);
     glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( 0.65f, 0.85f);
      glVertex2f( 0.66f, 0.85f);
      glVertex2f( 0.655f,  0.83f);
      glEnd();

      ///star 3

    glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.45f, 0.75f);
glVertex2f( -0.45f, 0.76f);
glVertex2f( -0.46f, 0.76f);
glVertex2f( -0.46f, 0.75f);



glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.45f, 0.75f);
glVertex2f( -0.45f, 0.76f);
glVertex2f( -0.43f, 0.76f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.45f, 0.76f);
glVertex2f( -0.46f, 0.76f);
glVertex2f( -0.455f, 0.78f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.45f, 0.75f);
glVertex2f( -0.45f, 0.76f);
glVertex2f( -0.48f, 0.758f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.45f, 0.75f);
glVertex2f( -0.46f, 0.75f);
glVertex2f( -0.455f, 0.73f);
glEnd();

///star 4

    glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.55f, 0.65f);
glVertex2f( -0.55f, 0.66f);
glVertex2f( -0.56f, 0.66f);
glVertex2f( -0.56f, 0.65f);



glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.55f, 0.65f);
glVertex2f( -0.55f, 0.66f);
glVertex2f( -0.53f, 0.66f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.55f, 0.66f);
glVertex2f( -0.56f, 0.66f);
glVertex2f( -0.555f, 0.68f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.55f, 0.65f);
glVertex2f( -0.55f, 0.66f);
glVertex2f( -0.58f, 0.658f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.55f, 0.65f);
glVertex2f( -0.56f, 0.65f);
glVertex2f( -0.555f, 0.63f);
glEnd();


///star 5

    glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.25f, 0.95f);
glVertex2f( -0.25f, 0.96f);
glVertex2f( -0.26f, 0.96f);
glVertex2f( -0.26f, 0.95f);



glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.25f, 0.95f);
glVertex2f( -0.25f, 0.96f);
glVertex2f( -0.23f, 0.96f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.25f, 0.96f);
glVertex2f( -0.26f, 0.96f);
glVertex2f( -0.255f, 0.98f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.25f, 0.95f);
glVertex2f( -0.25f, 0.96f);
glVertex2f( -0.28f, 0.958f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.25f, 0.95f);
glVertex2f( -0.26f, 0.95f);
glVertex2f( -0.255f, 0.93f);
glEnd();


///star 6

    glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.35f, 0.55f);
glVertex2f( -0.35f, 0.56f);
glVertex2f( -0.36f, 0.56f);
glVertex2f( -0.36f, 0.55f);



glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.35f, 0.55f);
glVertex2f( -0.35f, 0.56f);
glVertex2f( -0.33f, 0.56f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.35f, 0.56f);
glVertex2f( -0.36f, 0.56f);
glVertex2f( -0.355f, 0.58f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.35f, 0.55f);
glVertex2f( -0.35f, 0.56f);
glVertex2f( -0.38f, 0.558f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.35f, 0.55f);
glVertex2f( -0.36f, 0.55f);
glVertex2f( -0.355f, 0.53f);
glEnd();



///star 7

    glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.05f, 0.85f);
glVertex2f( -0.05f, 0.86f);
glVertex2f( -0.06f, 0.86f);
glVertex2f( -0.06f, 0.85f);



glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.05f, 0.85f);
glVertex2f( -0.05f, 0.86f);
glVertex2f( -0.03f, 0.86f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.05f, 0.86f);
glVertex2f( -0.06f, 0.86f);
glVertex2f( -0.055f, 0.88f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.05f, 0.85f);
glVertex2f( -0.05f, 0.86f);
glVertex2f( -0.08f, 0.858f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( -0.05f, 0.85f);
glVertex2f( -0.06f, 0.85f);
glVertex2f( -0.055f, 0.83f);
glEnd();





    ///star 8

    glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.65f, 0.85f);
glVertex2f( 0.65f, 0.86f);
glVertex2f( 0.66f, 0.86f);
glVertex2f( 0.66f, 0.85f);



glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.65f, 0.85f);
glVertex2f( 0.65f, 0.86f);
glVertex2f( 0.63f, 0.86f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.65f, 0.86f);
glVertex2f( 0.66f, 0.86f);
glVertex2f( 0.655f, 0.88f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.65f, 0.85f);
glVertex2f( 0.65f, 0.86f);
glVertex2f( 0.68f, 0.858f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.65f, 0.85f);
glVertex2f( 0.66f, 0.85f);
glVertex2f( 0.655f, 0.83f);
glEnd();



///star 9
    glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.45f, 0.75f);
glVertex2f( 0.45f, 0.76f);
glVertex2f( 0.46f, 0.76f);
glVertex2f( 0.46f, 0.75f);



glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.45f, 0.75f);
glVertex2f( 0.45f, 0.76f);
glVertex2f( 0.43f, 0.76f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.45f, 0.76f);
glVertex2f( 0.46f, 0.76f);
glVertex2f( 0.455f, 0.78f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.45f, 0.75f);
glVertex2f( 0.45f, 0.76f);
glVertex2f( 0.48f, 0.758f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.45f, 0.75f);
glVertex2f( 0.46f, 0.75f);
glVertex2f( 0.455f, 0.73f);
glEnd();

///star 10

    glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.55f, 0.65f);
glVertex2f( 0.55f, 0.66f);
glVertex2f( 0.56f, 0.66f);
glVertex2f( 0.56f, 0.65f);



glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.55f, 0.65f);
glVertex2f( 0.55f, 0.66f);
glVertex2f( 0.53f, 0.66f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.55f, 0.66f);
glVertex2f( 0.56f, 0.66f);
glVertex2f( 0.555f, 0.68f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.55f, 0.65f);
glVertex2f( 0.55f, 0.66f);
glVertex2f( 0.58f, 0.658f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.55f, 0.65f);
glVertex2f( 0.56f, 0.65f);
glVertex2f( 0.555f, 0.63f);
glEnd();


///star 11

    glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.25f, 0.95f);
glVertex2f( 0.25f, 0.96f);
glVertex2f( 0.26f, 0.96f);
glVertex2f( 0.26f, 0.95f);



glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.25f, 0.95f);
glVertex2f( 0.25f, 0.96f);
glVertex2f( 0.23f, 0.96f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.25f, 0.96f);
glVertex2f( 0.26f, 0.96f);
glVertex2f( 0.255f, 0.98f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.25f, 0.95f);
glVertex2f( 0.25f, 0.96f);
glVertex2f( 0.28f, 0.958f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.25f, 0.95f);
glVertex2f( 0.26f, 0.95f);
glVertex2f( 0.255f, 0.93f);
glEnd();


///star 12

    glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.35f, 0.55f);
glVertex2f( 0.35f, 0.56f);
glVertex2f( 0.36f, 0.56f);
glVertex2f( 0.36f, 0.55f);



glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.35f, 0.55f);
glVertex2f( 0.35f, 0.56f);
glVertex2f( 0.33f, 0.56f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.35f, 0.56f);
glVertex2f( 0.36f, 0.56f);
glVertex2f( 0.355f, 0.58f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.35f, 0.55f);
glVertex2f( 0.35f, 0.56f);
glVertex2f( 0.38f, 0.558f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.35f, 0.55f);
glVertex2f( 0.36f, 0.55f);
glVertex2f( 0.355f, 0.53f);
glEnd();


///star 13

    glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.15f, 0.75f);
glVertex2f( 0.15f, 0.76f);
glVertex2f( 0.16f, 0.76f);
glVertex2f( 0.16f, 0.75f);



glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.15f, 0.75f);
glVertex2f( 0.15f, 0.76f);
glVertex2f( 0.13f, 0.76f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.15f, 0.76f);
glVertex2f( 0.16f, 0.76f);
glVertex2f( 0.155f, 0.78f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.15f, 0.75f);
glVertex2f( 0.15f, 0.76f);
glVertex2f( 0.18f, 0.758f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.15f, 0.75f);
glVertex2f( 0.16f, 0.75f);
glVertex2f( 0.155f, 0.73f);
glEnd();

}
}

building(){
    /// Building 1.............
glBegin(GL_QUADS);
glColor3f(0.0f, 0.5f, 0.5f);
glVertex2f( -1.0f,0.15f);
glVertex2f( -1.0f, 0.7f);
glVertex2f( -0.78f,0.7f);
glVertex2f( -0.78f,0.15f);
glEnd();


//building 1 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 0.0f, 240.0f);
glVertex2f( -0.92f,0.3f);
glVertex2f( -0.92f,0.35f);
glVertex2f( -0.97f,0.35f);
glVertex2f( -0.97f,0.3f);
glEnd();

//building 1 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 0.0f, 240.0f);
glVertex2f( -0.92f,0.45f);
glVertex2f( -0.92f,0.5f);
glVertex2f( -0.97f,0.5f);
glVertex2f( -0.97f,0.45f);
glEnd();

//building 1 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 0.0f, 240.0f);
glVertex2f( -0.92f,0.6f);
glVertex2f( -0.92f,0.65f);
glVertex2f( -0.97f,0.65f);
glVertex2f( -0.97f,0.6f);
glEnd();


//building 1 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 0.0f, 240.0f);
glVertex2f( -0.82f,0.3f);
glVertex2f( -0.82f,0.35f);
glVertex2f( -0.87f,0.35f);
glVertex2f( -0.87f,0.3f);
glEnd();

//building 1 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 0.0f, 240.0f);
glVertex2f( -0.82f,0.45f);
glVertex2f( -0.82f,0.5f);
glVertex2f( -0.87f,0.5f);
glVertex2f( -0.87f,0.45f);
glEnd();

//building 1 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 0.0f, 240.0f);
glVertex2f( -0.82f,0.6f);
glVertex2f( -0.82f,0.65f);
glVertex2f( -0.87f,0.65f);
glVertex2f( -0.87f,0.6f);
glEnd();

// building 2
glBegin(GL_QUADS);///...................
glColor3f(0.5f, 0.5f, 0.5f);
glVertex2f( -0.78f,0.15f);
glVertex2f( -0.78f,0.5f);
glVertex2f( -0.6f,0.5f);
glVertex2f( -0.6f,0.15f);
glEnd();




//building 2 window
glBegin(GL_QUADS);///...................
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
glVertex2f( -0.70f,0.38f);
glVertex2f( -0.70f,0.43f);
glVertex2f( -0.75f,0.43f);
glVertex2f( -0.75f,0.38f);
glEnd();

//building 2 window
glBegin(GL_QUADS);///...................
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
glVertex2f( -0.62f,0.38f);
glVertex2f( -0.62f,0.43f);
glVertex2f( -0.67f,0.43f);
glVertex2f( -0.67f,0.38f);
glEnd();
//building 2 window
glBegin(GL_QUADS);///...................
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
glVertex2f( -0.70f,0.28f);
glVertex2f( -0.70f,0.33f);
glVertex2f( -0.75f,0.33f);
glVertex2f( -0.75f,0.28f);
glEnd();

//building 2 window
glBegin(GL_QUADS);///...................
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
glVertex2f( -0.62f,0.28f);
glVertex2f( -0.62f,0.33f);
glVertex2f( -0.67f,0.33f);
glVertex2f( -0.67f,0.28f);
glEnd();


//building 3
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 0.0f, 0.0f);
glVertex2f( -0.7f,0.15f);
glVertex2f( -0.7f,0.3f);
glVertex2f( -0.5f,0.3);
glVertex2f( -0.5f,0.15f);
glEnd();




//building 3 window
glBegin(GL_QUADS);///...................
glColor3f( 255.0f, 255.0f, 0.0f);
glVertex2f( -0.53f,0.2f);
glVertex2f( -0.53f,0.25f);
glVertex2f( -0.57f,0.25);
glVertex2f( -0.57f,0.2f);
glEnd();


//building 3 window
glBegin(GL_QUADS);///...................
glColor3f( 255.0f, 255.0f, 0.0f);
glVertex2f( -0.63f,0.2f);
glVertex2f( -0.63f,0.25f);
glVertex2f( -0.67f,0.25);
glVertex2f( -0.67f,0.2f);
glEnd();

//building 4
glBegin(GL_QUADS);///...................
glColor3f( 4.0f, 0.0f, 240.0f);
glVertex2f( -0.5f,0.15f);
glVertex2f( -0.5f,0.4f);
glVertex2f( -0.2f,0.4f);
glVertex2f( -0.2f,0.15f);
glEnd();


//building 4 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 0.0f);
glVertex2f( -0.47f,0.30f);
glVertex2f( -0.47f,0.35f);
glVertex2f( -0.42f,0.35f);
glVertex2f( -0.42f,0.30f);
glEnd();

//building 4 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 0.0f);
glVertex2f( -0.47f,0.20f);
glVertex2f( -0.47f,0.25f);
glVertex2f( -0.42f,0.25f);
glVertex2f( -0.42f,0.20f);
glEnd();

/////////////////
//building 4 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 0.0f);
glVertex2f( -0.37f,0.30f);
glVertex2f( -0.37f,0.35f);
glVertex2f( -0.32f,0.35f);
glVertex2f( -0.32f,0.30f);
glEnd();

//building 4 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 0.0f);
glVertex2f( -0.37f,0.20f);
glVertex2f( -0.37f,0.25f);
glVertex2f( -0.32f,0.25f);
glVertex2f( -0.32f,0.20f);
glEnd();

//////////////////
//building 4 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 0.0f);
glVertex2f( -0.27f,0.30f);
glVertex2f( -0.27f,0.35f);
glVertex2f( -0.22f,0.35f);
glVertex2f( -0.22f,0.30f);
glEnd();

//building 4 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 0.0f);
glVertex2f( -0.27f,0.20f);
glVertex2f( -0.27f,0.25f);
glVertex2f( -0.22f,0.25f);
glVertex2f( -0.22f,0.20f);
glEnd();

//building 5
glBegin(GL_QUADS);///...................
glColor3f( 128.0f, 0.0f, 0.0f);
glVertex2f( -0.2f,0.15f);
glVertex2f( -0.2f,0.7f);
glVertex2f( 0.01f,0.7f);
glVertex2f( 0.01f,0.15f);
glEnd();

//building 5 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 240.0f);
glVertex2f( -0.17f,0.3f);
glVertex2f( -0.17f,0.35f);
glVertex2f( -0.12f,0.35f);
glVertex2f( -0.12f,0.3f);
glEnd();

//building 5 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 240.0f);
glVertex2f( -0.17f,0.45f);
glVertex2f( -0.17f,0.5f);
glVertex2f( -0.12f,0.5f);
glVertex2f( -0.12f,0.45f);
glEnd();

//building 5 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 240.0f);
glVertex2f( -0.17f,0.6f);
glVertex2f( -0.17f,0.65f);
glVertex2f( -0.12f,0.65f);
glVertex2f( -0.12f,0.6f);
glEnd();


//building 5 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 240.0f);
glVertex2f( -0.08f,0.3f);
glVertex2f( -0.08f,0.35f);
glVertex2f( -0.03f,0.35f);
glVertex2f( -0.03f,0.3f);
glEnd();

//building 5 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 240.0f);
glVertex2f( -0.08f,0.45f);
glVertex2f( -0.08f,0.5f);
glVertex2f( -0.03f,0.5f);
glVertex2f( -0.03f,0.45f);
glEnd();

//building 5 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 240.0f, 240.0f);
glVertex2f( -0.08f,0.6f);
glVertex2f( -0.08f,0.65f);
glVertex2f( -0.03f,0.65f);
glVertex2f( -0.03f,0.6f);
glEnd();

//building 6
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 0.0f, 204.0f);
glVertex2f( 0.01f,0.15f);
glVertex2f( 0.01f,0.6f);
glVertex2f( 0.3f,0.6f);
glVertex2f( 0.3f,0.15f);
glEnd();

//building 6 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 0.0f, 0.0f);
glVertex2f( 0.13f,0.25f);
glVertex2f( 0.13f,0.3f);
glVertex2f( 0.17f,0.3f);
glVertex2f( 0.17f,0.25f);
glEnd();

//building 6 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 0.0f, 0.0f);
glVertex2f( 0.04f,0.25f);
glVertex2f( 0.04f,0.3f);
glVertex2f( 0.08f,0.3f);
glVertex2f( 0.08f,0.25f);
glEnd();

//building 6 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 0.0f, 0.0f);
glVertex2f( 0.22f,0.25f);
glVertex2f( 0.22f,0.3f);
glVertex2f( 0.26f,0.3f);
glVertex2f( 0.26f,0.25f);
glEnd();

//building 6 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 0.0f, 0.0f);
glVertex2f( 0.13f,0.37f);
glVertex2f( 0.13f,0.42f);
glVertex2f( 0.17f,0.42f);
glVertex2f( 0.17f,0.37f);
glEnd();

//building 6 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 0.0f, 0.0f);
glVertex2f( 0.04f,0.37f);
glVertex2f( 0.04f,0.42f);
glVertex2f( 0.08f,0.42f);
glVertex2f( 0.08f,0.37f);
glEnd();

//building 6 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 0.0f, 0.0f);
glVertex2f( 0.22f,0.37f);
glVertex2f( 0.22f,0.42f);
glVertex2f( 0.26f,0.42f);
glVertex2f( 0.26f,0.37f);
glEnd();

//building 6 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 0.0f, 0.0f);
glVertex2f( 0.13f,0.5f);
glVertex2f( 0.13f,0.55f);
glVertex2f( 0.17f,0.55f);
glVertex2f( 0.17f,0.5f);
glEnd();

//building 6 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 0.0f, 0.0f);
glVertex2f( 0.04f,0.5f);
glVertex2f( 0.04f,0.55f);
glVertex2f( 0.08f,0.55f);
glVertex2f( 0.08f,0.5f);
glEnd();

//building 6 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 0.0f, 0.0f);
glVertex2f( 0.22f,0.5f);
glVertex2f( 0.22f,0.55f);
glVertex2f( 0.26f,0.55f);
glVertex2f( 0.26f,0.5f);
glEnd();



//building 7
glBegin(GL_QUADS);///...................
glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
glVertex2f( 0.3f,0.15f);
glVertex2f( 0.3f,0.4f);
glVertex2f( 0.6f,0.4f);
glVertex2f( 0.6f,0.15f);
glEnd();

//building 7 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 0.0f, 0.0f);
glVertex2f( 0.37f,0.3f);
glVertex2f( 0.37f,0.35f);
glVertex2f( 0.42f,0.35f);
glVertex2f( 0.42f,0.3f);
glEnd();

//building 7 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 0.0f, 0.0f);
glVertex2f( 0.48f,0.3f);
glVertex2f( 0.48f,0.35f);
glVertex2f( 0.53f,0.35f);
glVertex2f( 0.53f,0.3f);
glEnd();

//building 7 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 0.0f, 0.0f);
glVertex2f( 0.37f,0.2f);
glVertex2f( 0.37f,0.25f);
glVertex2f( 0.42f,0.25f);
glVertex2f( 0.42f,0.2f);
glEnd();

//building 7 window
glBegin(GL_QUADS);///...................
glColor3f( 240.0f, 0.0f, 0.0f);
glVertex2f( 0.48f,0.2f);
glVertex2f( 0.48f,0.25f);
glVertex2f( 0.53f,0.25f);
glVertex2f( 0.53f,0.2f);
glEnd();

//building 8
glBegin(GL_QUADS);///...................
glColor3f( 0.1f, 0.5f, 0.5f);
glVertex2f( 0.6f,0.15f);
glVertex2f( 0.6f,0.5f);
glVertex2f( 0.8f,0.5f);
glVertex2f( 0.8f,0.15f);
glEnd();

//building 8 window
glBegin(GL_QUADS);///...................
glColor3f(0.0f, 0.5f, 1.0f);
glVertex2f( 0.63f,0.25f);
glVertex2f( 0.63f,0.30f);
glVertex2f( 0.67f,0.30f);
glVertex2f( 0.67f,0.25f);
glEnd();

//building 8 window
glBegin(GL_QUADS);///...................
glColor3f(0.0f, 0.5f, 1.0f);
glVertex2f( 0.63f,0.40f);
glVertex2f( 0.63f,0.45f);
glVertex2f( 0.67f,0.45f);
glVertex2f( 0.67f,0.40f);
glEnd();

//building 8 window
glBegin(GL_QUADS);///...................
glColor3f(0.0f, 0.5f, 1.0f);
glVertex2f( 0.73f,0.40f);
glVertex2f( 0.73f,0.45f);
glVertex2f( 0.77f,0.45f);
glVertex2f( 0.77f,0.40f);
glEnd();

//building 8 window
glBegin(GL_QUADS);///...................
glColor3f(0.0f, 0.5f, 1.0f);
glVertex2f( 0.73f,0.25f);
glVertex2f( 0.73f,0.30f);
glVertex2f( 0.77f,0.30f);
glVertex2f( 0.77f,0.25f);
glEnd();


//building 9
glBegin(GL_QUADS);///...................
glColor3f( 255.0f, 255.0f, 0.0f);
glVertex2f( 0.8f,0.15f);
glVertex2f( 0.8f,0.7f);
glVertex2f( 1.0f,0.7f);
glVertex2f( 1.0f,0.15f);
glEnd();

//building 9 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 255.0f, 0.0f);
glVertex2f( 0.83f,0.25f);
glVertex2f( 0.83f,0.30f);
glVertex2f( 0.88f,0.30f);
glVertex2f( 0.88f,0.25f);
glEnd();

//building 9 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 255.0f, 0.0f);
glVertex2f( 0.83f,0.40f);
glVertex2f( 0.83f,0.45f);
glVertex2f( 0.88f,0.45f);
glVertex2f( 0.88f,0.40f);
glEnd();

//building 9 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 255.0f, 0.0f);
glVertex2f( 0.83f,0.55f);
glVertex2f( 0.83f,0.60f);
glVertex2f( 0.88f,0.60f);
glVertex2f( 0.88f,0.55f);
glEnd();

//building 9 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 255.0f, 0.0f);
glVertex2f( 0.93f,0.25f);
glVertex2f( 0.93f,0.30f);
glVertex2f( 0.98f,0.30f);
glVertex2f( 0.98f,0.25f);
glEnd();

//building 9 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 255.0f, 0.0f);
glVertex2f( 0.93f,0.40f);
glVertex2f( 0.93f,0.45f);
glVertex2f( 0.98f,0.45f);
glVertex2f( 0.98f,0.40f);
glEnd();

//building 9 window
glBegin(GL_QUADS);///...................
glColor3f( 0.0f, 255.0f, 0.0f);
glVertex2f( 0.93f,0.55f);
glVertex2f( 0.93f,0.60f);
glVertex2f( 0.98f,0.60f);
glVertex2f( 0.98f,0.55f);
glEnd();

///Building (End)..............
}
Road(){
     glBegin(GL_QUADS);                ///Road.....
    if(night){
            glColor3f(0.3f, 0.3f, 0.3f);
    }
    else
     glColor3f(0.1f, 0.1f, 0.1f);


    glVertex2f( -1.0f, -0.58f);
    glVertex2f( -1.0f, -0.1f);
    glVertex2f( 1.0f,  -0.1f);
    glVertex2f( 1.0f,  -0.58f);
    glEnd();


    ///Road line (Start)


glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.9f, -0.36f);
      glVertex2f( -0.91f, -0.38f);
      glVertex2f( -0.8f,  -0.38f);
      glVertex2f(-0.79f,  -0.36f);
    glEnd();


    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.7f, -0.36f);
      glVertex2f( -0.71f, -0.38f);
      glVertex2f( -0.6f,  -0.38f);
      glVertex2f(-0.59f,  -0.36f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.5f, -0.36f);
      glVertex2f( -0.51f, -0.38f);
      glVertex2f( -0.4f,  -0.38f);
      glVertex2f( -0.39f,  -0.36f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.3, -0.36f);
      glVertex2f( -0.31f, -0.38f);
      glVertex2f( -0.2f,  -0.38f);
      glVertex2f( -0.19f,  -0.36f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.1f, -0.36f);
      glVertex2f( -0.11f, -0.38f);
      glVertex2f( 0.0f,  -0.38f);
      glVertex2f( 0.01f,  -0.36f);
    glEnd();


    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.1f, -0.36f);
      glVertex2f( 0.09f, -0.38f);
      glVertex2f( 0.2f,  -0.38f);
      glVertex2f( 0.21f,  -0.36f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.3f, -0.36f);
      glVertex2f( 0.29f, -0.38f);
      glVertex2f( 0.4f,  -0.38f);
      glVertex2f( 0.41f,  -0.36f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.5f, -0.36f);
      glVertex2f( 0.49f, -0.38f);
      glVertex2f( 0.6f,  -0.38f);
      glVertex2f( 0.61f,  -0.36f);
    glEnd();


    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.7f, -0.36f);
      glVertex2f( 0.69f, -0.38f);
      glVertex2f( 0.8f,  -0.38f);
      glVertex2f( 0.81f,  -0.36f);
    glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.9f, -0.36f);
      glVertex2f( 0.89f, -0.38f);
      glVertex2f( 1.0f,  -0.38f);
      glVertex2f( 1.0f,  -0.36f);
    glEnd();

    ///Road line(End)



/*glBegin(GL_QUADS);                ///Road.....
      glColor3f(0.4f, 0.5f, 0.5f);
      glVertex2f( -1.0f, -0.58f);
      glVertex2f( -1.0f, -0.1f);
      glVertex2f( 1.0f,  -0.1f);
      glVertex2f( 1.0f,  -0.58f);
    glEnd();*/

glBegin(GL_QUADS);                ///Road side.....
      glColor3f(0.58f, 0.5f, 0.5f);
      glVertex2f( -1.0f, -0.1f);
      glVertex2f( -1.0f, -0.05f);
      glVertex2f( -0.75f,  -0.05f);
      glVertex2f( -0.75f,  -0.1f);
    glEnd();

 glBegin(GL_QUADS);                ///Road side....
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.90f, -0.1f);
      glVertex2f( -0.90f, -0.05f);
      glVertex2f( -0.75f,  -0.05f);
      glVertex2f( -0.75f,  -0.1f);
    glEnd();

    glBegin(GL_QUADS);                ///Road.....
      glColor3f(0.58f, 0.5f, 0.5f);
      glVertex2f( -0.75f, -0.1f);
      glVertex2f( -0.75f, -0.05f);
      glVertex2f( -0.60f,  -0.05f);
      glVertex2f( -0.60f,  -0.1f);
    glEnd();

    glBegin(GL_QUADS);                ///Road.....
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.60f, -0.1f);
      glVertex2f( -0.60f, -0.05f);
      glVertex2f( -0.450f,  -0.05f);
      glVertex2f( -0.45f,  -0.1f);
    glEnd();

     glBegin(GL_QUADS);                ///Road.....
      glColor3f(0.58f, 0.5f, 0.5f);
      glVertex2f( -0.45f, -0.1f);
      glVertex2f( -0.45f, -0.05f);
      glVertex2f( -0.30f,  -0.05f);
      glVertex2f( -0.30f,  -0.1f);
    glEnd();

     glBegin(GL_QUADS);                ///Road.....
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.30f, -0.1f);
      glVertex2f( -0.30f, -0.05f);
      glVertex2f( -0.150f,  -0.05f);
      glVertex2f( -0.15f,  -0.1f);
    glEnd();

     glBegin(GL_QUADS);                ///Road.....
      glColor3f(0.58f, 0.5f, 0.5f);
      glVertex2f( -0.15f, -0.1f);
      glVertex2f( -0.15f, -0.05f);
      glVertex2f( 0.0f,  -0.05f);
      glVertex2f( 0.0f,  -0.1f);
    glEnd();

    glBegin(GL_QUADS);                ///Road.....
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.0f, -0.1f);
      glVertex2f( -0.0f, -0.05f);
      glVertex2f( 0.15f,  -0.05f);
      glVertex2f( 0.15f,  -0.1f);
    glEnd();

    glBegin(GL_QUADS);                ///Road.....
      glColor3f(0.58f, 0.5f, 0.5f);
      glVertex2f( 0.15f, -0.1f);
      glVertex2f( 0.15f, -0.05f);
      glVertex2f( 0.30f,  -0.05f);
      glVertex2f( 0.30f,  -0.1f);
    glEnd();

    glBegin(GL_QUADS);                ///Road.....
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.30f, -0.1f);
      glVertex2f( 0.30f, -0.05f);
      glVertex2f( 0.45f,  -0.05f);
      glVertex2f( 0.45f,  -0.1f);
    glEnd();

    glBegin(GL_QUADS);                ///Road.....
      glColor3f(0.58f, 0.5f, 0.5f);
      glVertex2f( 0.45f, -0.1f);
      glVertex2f( 0.45f, -0.05f);
      glVertex2f( 0.60f,  -0.05f);
      glVertex2f( 0.60f,  -0.1f);
    glEnd();


    glBegin(GL_QUADS);                ///Road.....
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.60f, -0.1f);
      glVertex2f( 0.60f, -0.05f);
      glVertex2f( 0.75f,  -0.05f);
      glVertex2f( 0.75f,  -0.1f);
    glEnd();

    glBegin(GL_QUADS);                ///Road.....
      glColor3f(0.58f, 0.5f, 0.5f);
      glVertex2f( 0.75f, -0.1f);
      glVertex2f( 0.75f, -0.05f);
      glVertex2f( 0.90f,  -0.05f);
      glVertex2f( 0.90f,  -0.1f);
    glEnd();

     glBegin(GL_QUADS);                ///Road side.....
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.90f, -0.1f);
      glVertex2f( 0.90f, -0.05f);
      glVertex2f( 1.0f,  -0.05f);
      glVertex2f( 1.0f,  -0.1f);
    glEnd();




    glBegin(GL_QUADS);                ///walkway .....
      glColor3f(1.3f, 1.0f, 0.0f);
      glVertex2f( -1.0f, -0.05f);
      glVertex2f( -1.00f, 0.01f);
      glVertex2f( 1.00f,  0.01f);
      glVertex2f( 1.00f,  -0.05f);
    glEnd();


glBegin(GL_QUADS);                ///walkway .......
      glColor3f(1.0f, 0.3f, 0.0f);
      glVertex2f( -0.96f, -0.05f);
      glVertex2f( -0.98f, 0.01f);
      glVertex2f( -0.86f,  0.01f);
      glVertex2f( -0.84f,  -0.05f);
    glEnd();

    glBegin(GL_QUADS);                ///walkway .......
      glColor3f(1.0f, 0.3f, 0.0f);
      glVertex2f( -0.76f, -0.05f);
      glVertex2f( -0.78f, 0.01f);
      glVertex2f( -0.66f,  0.01f);
      glVertex2f( -0.64f,  -0.05f);
    glEnd();

    glBegin(GL_QUADS);                ///walkway .......
      glColor3f(1.0f, 0.3f, 0.0f);
      glVertex2f( -0.56f, -0.05f);
      glVertex2f( -0.58f, 0.01f);
      glVertex2f( -0.46f,  0.01f);
      glVertex2f( -0.44f,  -0.05f);
    glEnd();

    glBegin(GL_QUADS);                ///walkway ........
      glColor3f(1.0f, 0.3f, 0.0f);
      glVertex2f( -0.36f, -0.05f);
      glVertex2f( -0.38f, 0.01f);
      glVertex2f( -0.26f,  0.01f);
      glVertex2f( -0.24f,  -0.05f);
    glEnd();

     glBegin(GL_QUADS);                ///walkway ......
      glColor3f(1.0f, 0.3f, 0.0f);
      glVertex2f( -0.16f, -0.05f);
      glVertex2f( -0.18f, 0.01f);
      glVertex2f( -0.06f,  0.01f);
      glVertex2f( -0.04f,  -0.05f);
    glEnd();

     glBegin(GL_QUADS);                ///walkway .....
      glColor3f(1.0f, 0.3f, 0.0f);
      glVertex2f( 0.04f, -0.05f);
      glVertex2f( 0.02f, 0.01f);
      glVertex2f( 0.14f,  0.01f);
      glVertex2f( 0.16f,  -0.05f);
    glEnd();

    glBegin(GL_QUADS);                ///walkway ....
      glColor3f(1.0f, 0.3f, 0.0f);
      glVertex2f( 0.24f, -0.05f);
      glVertex2f( 0.22f, 0.01f);
      glVertex2f( 0.34f,  0.01f);
      glVertex2f( 0.36f,  -0.05f);
    glEnd();

    glBegin(GL_QUADS);                ///walkway .....
      glColor3f(1.0f, 0.3f, 0.0f);
      glVertex2f( 0.44f, -0.05f);
      glVertex2f( 0.42f, 0.01f);
      glVertex2f( 0.54f,  0.01f);
      glVertex2f( 0.56f,  -0.05f);
    glEnd();

    glBegin(GL_QUADS);                ///walkway ....
      glColor3f(1.0f, 0.3f, 0.0f);
      glVertex2f( 0.64f, -0.05f);
      glVertex2f( 0.62f, 0.01f);
      glVertex2f( 0.74f,  0.01f);
      glVertex2f( 0.76f,  -0.05f);
    glEnd();

    glBegin(GL_QUADS);                ///walkway ....
      glColor3f(1.0f, 0.3f, 0.0f);
      glVertex2f( 0.84f, -0.05f);
      glVertex2f( 0.82f, 0.01f);
      glVertex2f( 0.94f,  0.01f);
      glVertex2f( 0.96f,  -0.05f);
    glEnd();

    glBegin(GL_LINES);                ///Road ....
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f( -1.0f, -0.02f);
      glVertex2f( 1.0f, -0.02f);

    glEnd();

    ///walk way end
}

car1(){
     ///Start car 1

    glPushMatrix();
glTranslatef(positionCar1,0.0f, 0.0f);

glBegin(GL_QUADS);
      glColor3f(0.0f, 0.5f, 0.5f);
      glVertex2f( -0.79f, -0.28f);
      glVertex2f( -0.3f, -0.28f);
      glVertex2f( -0.3f,  -0.23f);
      glVertex2f( -0.79f,  -0.23f);
      glEnd();

      if(night){ /// night mode
      glBegin(GL_QUADS);
      glColor4f(1.0f, 0.9f, 0.0f, 0.0f);
      glVertex2f( -0.3f, -0.28f);
      glVertex2f( -0.3f, -0.26f);
      glVertex2f( -0.19f,  -0.25f);
      glVertex2f( -0.2f,  -0.35f);
      glEnd();
      }

      glBegin(GL_QUADS);
      glColor3f(0.0f, 0.5f, 0.5f);
      glVertex2f( -0.3f,  -0.23f);
      glVertex2f( -0.41f, -0.17f);
      glVertex2f( -0.72f,  -0.17f);
      glVertex2f( -0.72f,  -0.23f);
      glEnd();


      glBegin(GL_QUADS);
      glColor3f(0.0f, 0.5f, 0.5f);
      glVertex2f( -0.72f,  -0.24f);
      glVertex2f( -0.72f,  -0.17f);
      glVertex2f( -0.79f, -0.20f);
      glVertex2f( -0.79f, -0.24f);


      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.0f, 0.5f, 0.5f);
       glVertex2f( -0.41f, -0.17f);
      glVertex2f( -0.47f, -0.09f);
      glVertex2f( -0.68f,  -0.09f);
      glVertex2f( -0.72f,  -0.17f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
       glVertex2f( -0.42f, -0.17f);
      glVertex2f( -0.47f, -0.10f);
      glVertex2f( -0.57f,  -0.10f);
      glVertex2f( -0.57f,  -0.17f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
       glVertex2f( -0.58f, -0.17f);
      glVertex2f( -0.58f, -0.10f);
      glVertex2f( -0.675f,  -0.10f);
      glVertex2f( -0.709f,  -0.17f);
      glEnd();




      xpos=-0.69f;
      ypos=-0.28f;
      radius=0.04f;




       prex=xpos;
       prey=ypos-radius;

      for(int i=0;i<=steps;i++){
         nex= 0.0;
        nex=-0.69-radius*sinf(angle*i);
         ney =0.0;
        ney=-0.28-radius*cosf(angle*i);

        glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 0.0f, 0.0f);
      if(i%2==0){
        glColor3f(0.1f, 0.1f, 0.1f);
      }
      glVertex3f( -0.69f,  -0.28f,0.0f);
      glVertex3f( prex,prey,0.0f);
      glVertex3f( nex, ney,0.0f);
      glEnd();

      prex=nex;
      prey=ney;


      }

       xpos=-0.43f;
       ypos=-0.28f;

       steps=100;
       angle=3.1415426*2.f/steps;

       prex=xpos;
       prey=ypos-radius;

      for(int i=0;i<=steps;i++){
         float nex= 0.0;
        nex=-0.43-radius*sinf(angle*i);
         float ney =0.0;
        ney=-0.28-radius*cosf(angle*i);

        glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 0.0f, 0.0f);
      if(i%2==0){
        glColor3f(0.1f, 0.1f, 0.1f);
      }
      glVertex3f( -0.43f,  -0.28f,0.0f);
      glVertex3f( prex,prey,0.0f);
      glVertex3f( nex, ney,0.0f);
      glEnd();

      prex=nex;
      prey=ney;

      }

      glPopMatrix();
///end car 1
}

car2(){
    ///Start car 2

glPushMatrix();
glTranslatef(positionCar2,0.0f, 0.0f);

glBegin(GL_QUADS);
      glColor3f(0.5f, 0.0f, 0.0f);
      glVertex2f( 0.3f, -0.28f);
      glVertex2f( 0.79f, -0.28f);
      glVertex2f( 0.79f,  -0.24f);
      glVertex2f( 0.3f,  -0.24f);
      glEnd();

      if(night){ /// night mode
      glBegin(GL_QUADS);
      glColor4f(1.0f, 0.9f, 0.0f, 0.0f);
      glVertex2f( 0.79f, -0.28f);
      glVertex2f( 0.79f, -0.26f);
      glVertex2f( 0.9f,  -0.25f);
      glVertex2f( 0.89f,  -0.35f);
      glEnd();
      }

      glBegin(GL_QUADS);
      glColor3f(0.5f, 0.0f, 0.0f);
      glVertex2f( 0.79f,  -0.24f);
      glVertex2f( 0.69f, -0.17f);
      glVertex2f( 0.38f,  -0.17f);
      glVertex2f( 0.38f,  -0.24f);
      glEnd();


      glBegin(GL_QUADS);
      glColor3f(0.5f, 0.0f, 0.0f);
      glVertex2f( 0.38f,  -0.25f);
      glVertex2f( 0.38f,  -0.17f);
      glVertex2f( 0.3f, -0.20f);
      glVertex2f( 0.3f, -0.25f);

       glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.5f, 0.0f, 0.0f);
       glVertex2f( 0.69f, -0.17f);
      glVertex2f( 0.64f, -0.09f);
      glVertex2f( 0.42f,  -0.09f);
      glVertex2f( 0.38f,  -0.17f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f( 0.55f,  -0.17f);
      glVertex2f( 0.55f,  -0.10f);
       glVertex2f( 0.64f, -0.10f);
      glVertex2f( 0.68f, -0.17f);


      glEnd();

       glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
       glVertex2f( 0.53f, -0.17f);
      glVertex2f( 0.53f, -0.10f);
      glVertex2f( 0.425f,  -0.10f);
      glVertex2f( 0.395f,  -0.17f);
      glEnd();




      //circle(-0.8,-0.29,0.1);

       xpos=0.69f,ypos=-0.28f,radius=0.04f;
       steps=100;
       angle=3.1415426*2.f/steps;

       prex=xpos;
       prey=ypos-radius;

      for(int i=0;i<=steps;i++){
        float nex= 0.0;
        nex=0.69-radius*sinf(angle*i);
        float ney =0.0;
        ney=-0.28-radius*cosf(angle*i);

        glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 0.0f, 0.0f);
      if(i%2==0){
        glColor3f(0.1f, 0.1f, 0.1f);
      }
      glVertex3f( 0.69f,  -0.28f,0.0f);
      glVertex3f( prex,prey,0.0f);
      glVertex3f( nex, ney,0.0f);
      glEnd();

      prex=nex;
      prey=ney;


      }

       xpos=0.43f,ypos=-0.28f,radius=0.04f;
       steps=100;
       angle=3.1415426*2.f/steps;

       prex=xpos;
       prey=ypos-radius;

      for(int i=0;i<=steps;i++){
         float nex= 0.0;
        nex=0.43-radius*sinf(angle*i);
         float ney =0.0;
        ney=-0.28-radius*cosf(angle*i);

        glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 0.0f, 0.0f);
      if(i%2==0){
        glColor3f(0.1f, 0.1f, 0.1f);
      }
      glVertex3f( 0.43f,  -0.28f,0.0f);
      glVertex3f( prex,prey,0.0f);
      glVertex3f( nex, ney,0.0f);
      glEnd();

      prex=nex;
      prey=ney;

      }
      glPopMatrix();
///end car 2
}

car4(){
    ///Start car 4

glPushMatrix();
glTranslatef(positionCar4,0.0f, 0.0f);


glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f( -0.31f, -0.46f);
      glVertex2f( -0.79f, -0.46f);
      glVertex2f( -0.79f,  -0.41f);
      glVertex2f( -0.31f,  -0.41f);
      glEnd();

      if(night){ /// night mode
      glBegin(GL_QUADS);
      glColor4f(1.0f, 0.9f, 0.0f, 0.0f);
      glVertex2f( -0.79f, -0.46f);
      glVertex2f( -0.79f, -0.44f);
      glVertex2f( -0.90f,  -0.45f);
      glVertex2f( -0.89f,  -0.55f);
      glEnd();
      }

      glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f( -0.79f,  -0.41f);
      glVertex2f( -0.69f, -0.35f);
      glVertex2f( -0.38f,  -0.36f);
      glVertex2f( -0.38f,  -0.41f);
      glEnd();


glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f( -0.38f,  -0.43f);
      glVertex2f( -0.38f,  -0.36f);
      glVertex2f( -0.31f, -0.38f);
      glVertex2f( -0.31f, -0.43f);

       glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
       glVertex2f( -0.69f, -0.36f);
      glVertex2f( -0.64f, -0.28f);
      glVertex2f( -0.42f,  -0.28f);
      glVertex2f( -0.38f,  -0.36f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f( -0.54f,  -0.36f);
      glVertex2f( -0.54f,  -0.29f);
       glVertex2f( -0.64f, -0.29f);
      glVertex2f( -0.68f, -0.36f);


      glEnd();

       glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
       glVertex2f( -0.53f, -0.36f);
      glVertex2f( -0.53f, -0.29f);
      glVertex2f( -0.425f,  -0.29f);
      glVertex2f( -0.395f,  -0.36f);
      glEnd();


       xpos=-0.69f,ypos=-0.46f,radius=0.04f;


       prex=xpos;
       prey=ypos-radius;

      for(int i=0;i<=steps;i++){
        float nex= 0.0;
        nex=-0.69-radius*sinf(angle*i);
        float ney =0.0;
        ney=-0.46-radius*cosf(angle*i);

        glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 0.0f, 0.0f);
      if(i%2==0){
        glColor3f(0.1f, 0.1f, 0.1f);
      }
      glVertex3f( -0.69f,  -0.46f,0.0f);
      glVertex3f( prex,prey,0.0f);
      glVertex3f( nex, ney,0.0f);
      glEnd();

      prex=nex;
      prey=ney;


      }

       xpos=-0.43f,ypos=-0.46f,radius=0.04f;

       prex=xpos;
       prey=ypos-radius;

      for(int i=0;i<=steps;i++){
         float nex= 0.0;
        nex=-0.43-radius*sinf(angle*i);
         float ney =0.0;
        ney=-0.46-radius*cosf(angle*i);

        glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 0.0f, 0.0f);
      if(i%2==0){
        glColor3f(0.1f, 0.1f, 0.1f);
      }
      glVertex3f( -0.43f,  -0.46f,0.0f);
      glVertex3f( prex,prey,0.0f);
      glVertex3f( nex, ney,0.0f);
      glEnd();

      prex=nex;
      prey=ney;

      }

      glPopMatrix();
///end car 4
}

car3(){
    ///Start car 3


    glPushMatrix();
glTranslatef(positionCar3,0.0f, 0.0f);

glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f( 0.79f, -0.56f);
      glVertex2f( 0.3f, -0.56f);
      glVertex2f( 0.3f,  -0.51f);
      glVertex2f( 0.79f,  -0.51f);
      glEnd();

      if(night){ /// night mode
      glBegin(GL_QUADS);
      glColor4f(1.0f, 0.9f, 0.0f, 0.0f);
      glVertex2f( 0.3f, -0.56f);
      glVertex2f( 0.3f, -0.54f);
      glVertex2f( 0.19f,  -0.56f);
      glVertex2f( 0.20f,  -0.65f);
      glEnd();
      }

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f( 0.3f,  -0.51f);
      glVertex2f( 0.41f, -0.45f);
      glVertex2f( 0.72f,  -0.46f);
      glVertex2f( 0.72f,  -0.51f);
      glEnd();


      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f( 0.72f,  -0.53f);
      glVertex2f( 0.72f,  -0.46f);
      glVertex2f( 0.79f, -0.49f);
      glVertex2f( 0.79f, -0.53f);


      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
       glVertex2f( 0.41f, -0.46f);
      glVertex2f( 0.47f, -0.38f);
      glVertex2f( 0.68f,  -0.38f);
      glVertex2f( 0.72f,  -0.46f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
       glVertex2f( 0.42f, -0.46f);
      glVertex2f( 0.47f, -0.39f);
      glVertex2f( 0.57f,  -0.39f);
      glVertex2f( 0.57f,  -0.46f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
       glVertex2f( 0.58f, -0.46f);
      glVertex2f( 0.58f, -0.39f);
      glVertex2f( 0.675f,  -0.39f);
      glVertex2f( 0.709f,  -0.46f);
      glEnd();






       xpos=0.69f;
       ypos=-0.56f;
       radius=0.04f;

       prex=xpos;
       prey=ypos-radius;

      for(int i=0;i<=steps;i++){
        float nex= 0.0;
        nex=0.69+radius*sinf(angle*i);
        float ney =0.0;
        ney=-0.56-radius*cosf(angle*i);

        glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 0.0f, 0.0f);
      if(i%2==0){
        glColor3f(0.1f, 0.1f, 0.1f);
      }
      glVertex3f( 0.69f,  -0.56f,0.0f);
      glVertex3f( prex,prey,0.0f);
      glVertex3f( nex, ney,0.0f);
      glEnd();

      prex=nex;
      prey=ney;


      }

       xpos=0.43f,ypos=-0.56f,radius=0.04f;

       prex=xpos;
       prey=ypos-radius;

      for(int i=0;i<=steps;i++){
         float nex= 0.0;
        nex=0.43+radius*sinf(angle*i);
         float ney =0.0;
        ney=-0.56-radius*cosf(angle*i);

        glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 0.0f, 0.0f);
      if(i%2==0){
        glColor3f(0.1f, 0.1f, 0.1f);
      }
      glVertex3f( 0.43f,  -0.56f,0.0f);
      glVertex3f( prex,prey,0.0f);
      glVertex3f( nex, ney,0.0f);
      glEnd();

      prex=nex;
      prey=ney;

      }

      glPopMatrix();
///end car 3

}

RoadsideDivider(){
    ///Divider between river and Road 3(start)

    glBegin(GL_QUADS);               /// Divider 1
      glColor3f(0.5f, 0.5f, 0.5f);
      glVertex2f( -1.0f, -0.7f);
      glVertex2f( -1.0f, -0.65f);
      glVertex2f( 1.0f,  -0.65f);
      glVertex2f(1.0f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);               /// Divider  3
      glColor3f(0.58f, 0.58f, 0.5f);
      glVertex2f( -1.0f, -0.7f);
      glVertex2f( -1.0f, -0.72f);
      glVertex2f( 1.0f,  -0.72f);
      glVertex2f(1.0f,  -0.7f);
    glEnd();

glBegin(GL_QUADS);                 /// divider 2
      glColor3f(0.58f, 0.58f, 0.5f);
      glVertex2f( -1.0f, -0.65f);
      glVertex2f( -1.0f, -0.58f);
      glVertex2f( 1.0f,  -0.58f);
      glVertex2f(1.0f,  -0.65f);
    glEnd();

///River Divider line(Start)

glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.95f, -0.65f);
      glVertex2f( -0.95f, -0.58f);
      glVertex2f( -0.9f,  -0.58f);
      glVertex2f(-0.9f,  -0.65f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.95f, -0.65f);
      glVertex2f( -0.9f, -0.65f);
      glVertex2f( -0.92f,  -0.7f);
      glVertex2f(-0.97f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.97f, -0.7f);
      glVertex2f( -0.92f, -0.7f);
      glVertex2f( -0.92f,  -0.72f);
      glVertex2f(-0.97f,  -0.72f);
    glEnd();



    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.85f, -0.65f);
      glVertex2f( -0.85f, -0.58f);
      glVertex2f( -0.80f,  -0.58f);
      glVertex2f(-0.80f,  -0.65f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.85f, -0.65f);
      glVertex2f( -0.8f, -0.65f);
      glVertex2f( -0.82f,  -0.7f);
      glVertex2f(-0.87f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.87f, -0.7f);
      glVertex2f( -0.82f, -0.7f);
      glVertex2f( -0.82f,  -0.72f);
      glVertex2f(-0.87f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.75f, -0.65f);
      glVertex2f( -0.75f, -0.58f);
      glVertex2f( -0.70f,  -0.58f);
      glVertex2f(-0.70f,  -0.65f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.75f, -0.65f);
      glVertex2f( -0.7f, -0.65f);
      glVertex2f( -0.72f,  -0.7f);
      glVertex2f(-0.77f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.77f, -0.7f);
      glVertex2f( -0.72f, -0.7f);
      glVertex2f( -0.72f,  -0.72f);
      glVertex2f(-0.77f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.65f, -0.65f);
      glVertex2f( -0.65f, -0.58f);
      glVertex2f( -0.60f,  -0.58f);
      glVertex2f(-0.60f,  -0.65f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.65f, -0.65f);
      glVertex2f( -0.6f, -0.65f);
      glVertex2f( -0.62f,  -0.7f);
      glVertex2f(-0.67f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.67f, -0.7f);
      glVertex2f( -0.62f, -0.7f);
      glVertex2f( -0.62f,  -0.72f);
      glVertex2f(-0.67f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.55f, -0.65f);
      glVertex2f( -0.55f, -0.58f);
      glVertex2f( -0.50f,  -0.58f);
      glVertex2f(-0.50f,  -0.65f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.55f, -0.65f);
      glVertex2f( -0.5f, -0.65f);
      glVertex2f( -0.52f,  -0.7f);
      glVertex2f( -0.57f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.57f, -0.7f);
      glVertex2f( -0.52f, -0.7f);
      glVertex2f( -0.52f,  -0.72f);
      glVertex2f(-0.57f,  -0.72f);
    glEnd();


    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.45f, -0.65f);
      glVertex2f( -0.45f, -0.58f);
      glVertex2f( -0.40f,  -0.58f);
      glVertex2f(-0.40f,  -0.65f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.45f, -0.65f);
      glVertex2f( -0.4f, -0.65f);
      glVertex2f( -0.42f,  -0.7f);
      glVertex2f(-0.47f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.47f, -0.7f);
      glVertex2f( -0.42f, -0.7f);
      glVertex2f( -0.42f,  -0.72f);
      glVertex2f(-0.47f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.35f, -0.65f);
      glVertex2f( -0.35f, -0.58f);
      glVertex2f( -0.30f,  -0.58f);
      glVertex2f( -0.30f,  -0.65f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.35f, -0.65f);
      glVertex2f( -0.3f, -0.65f);
      glVertex2f( -0.32f,  -0.7f);
      glVertex2f(-0.37f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.37f, -0.7f);
      glVertex2f( -0.32f, -0.7f);
      glVertex2f( -0.32f,  -0.72f);
      glVertex2f(-0.37f,  -0.72f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.25f, -0.65f);
      glVertex2f( -0.25f, -0.58f);
      glVertex2f( -0.20f,  -0.58f);
      glVertex2f( -0.20f,  -0.65f);
    glEnd();



     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.25f, -0.65f);
      glVertex2f( -0.2f, -0.65f);
      glVertex2f( -0.22f,  -0.7f);
      glVertex2f(-0.27f,  -0.7f);
    glEnd();
     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.27f, -0.7f);
      glVertex2f( -0.22f, -0.7f);
      glVertex2f( -0.22f,  -0.72f);
      glVertex2f(-0.27f,  -0.72f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.15f, -0.65f);
      glVertex2f( -0.15f, -0.58f);
      glVertex2f( -0.10f,  -0.58f);
      glVertex2f( -0.10f,  -0.65f);
    glEnd();


     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.15f, -0.65f);
      glVertex2f( -0.1f, -0.65f);
      glVertex2f( -0.12f,  -0.7f);
      glVertex2f(-0.17f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.17f, -0.7f);
      glVertex2f( -0.12f, -0.7f);
      glVertex2f( -0.12f,  -0.72f);
      glVertex2f(-0.17f,  -0.72f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.05f, -0.65f);
      glVertex2f( -0.05f, -0.58f);
      glVertex2f( 0.0f,  -0.58f);
      glVertex2f( 0.0f,  -0.65f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.05f, -0.65f);
      glVertex2f( -0.0f, -0.65f);
      glVertex2f( -0.02f,  -0.7f);
      glVertex2f(-0.07f,  -0.7f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( -0.07f, -0.7f);
      glVertex2f( -0.02f, -0.7f);
      glVertex2f( -0.02f,  -0.72f);
      glVertex2f(-0.07f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.05f, -0.65f);
      glVertex2f( 0.05f, -0.58f);
      glVertex2f( 0.1f,  -0.58f);
      glVertex2f( 0.1f,  -0.65f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.05f, -0.65f);
      glVertex2f( 0.1f, -0.65f);
      glVertex2f( 0.08f,  -0.7f);
      glVertex2f( 0.03f,  -0.7f);
    glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.08f, -0.7f);
      glVertex2f( 0.03f, -0.7f);
      glVertex2f( 0.03,  -0.72f);
      glVertex2f( 0.08f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.15f, -0.65f);
      glVertex2f( 0.15f, -0.58f);
      glVertex2f( 0.2f,  -0.58f);
      glVertex2f( 0.2f,  -0.65f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.15f, -0.65f);
      glVertex2f( 0.2f, -0.65f);
      glVertex2f( 0.18f,  -0.7f);
      glVertex2f( 0.13f,  -0.7f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.18f, -0.7f);
      glVertex2f( 0.13f, -0.7f);
      glVertex2f( 0.13f,  -0.72f);
      glVertex2f( 0.18f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.25f, -0.65f);
      glVertex2f( 0.25f, -0.58f);
      glVertex2f( 0.3f,  -0.58f);
      glVertex2f( 0.3f,  -0.65f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.28f, -0.7f);
      glVertex2f( 0.23f, -0.7f);
      glVertex2f( 0.23f,  -0.72f);
      glVertex2f( 0.28f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.25f, -0.65f);
      glVertex2f( 0.3f, -0.65f);
      glVertex2f( 0.28f,  -0.7f);
      glVertex2f( 0.23f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.35f, -0.65f);
      glVertex2f( 0.35f, -0.58f);
      glVertex2f( 0.4f,  -0.58f);
      glVertex2f( 0.4f,  -0.65f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.38f, -0.7f);
      glVertex2f( 0.33f, -0.7f);
      glVertex2f( 0.33f,  -0.72f);
      glVertex2f( 0.38f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.35f, -0.65f);
      glVertex2f( 0.4f, -0.65f);
      glVertex2f( 0.38f,  -0.7f);
      glVertex2f( 0.33f,  -0.7f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.45f, -0.65f);
      glVertex2f( 0.45f, -0.58f);
      glVertex2f( 0.5f,  -0.58f);
      glVertex2f( 0.5f,  -0.65f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.48f, -0.7f);
      glVertex2f( 0.43f, -0.7f);
      glVertex2f( 0.43f,  -0.72f);
      glVertex2f( 0.48f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.45f, -0.65f);
      glVertex2f( 0.5f, -0.65f);
      glVertex2f( 0.48f,  -0.7f);
      glVertex2f( 0.43f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.55f, -0.65f);
      glVertex2f( 0.55f, -0.58f);
      glVertex2f( 0.6f,  -0.58f);
      glVertex2f( 0.6f,  -0.65f);
    glEnd();
    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.58f, -0.7f);
      glVertex2f( 0.53f, -0.7f);
      glVertex2f( 0.53f,  -0.72f);
      glVertex2f( 0.58f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.55f, -0.65f);
      glVertex2f( 0.6f, -0.65f);
      glVertex2f( 0.58f,  -0.7f);
      glVertex2f( 0.53f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.65f, -0.65f);
      glVertex2f( 0.65f, -0.58f);
      glVertex2f( 0.7f,  -0.58f);
      glVertex2f( 0.7f,  -0.65f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.68f, -0.7f);
      glVertex2f( 0.63f, -0.7f);
      glVertex2f( 0.63f,  -0.72f);
      glVertex2f( 0.68f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.65f, -0.65f);
      glVertex2f( 0.7f, -0.65f);
      glVertex2f( 0.68f,  -0.7f);
      glVertex2f( 0.63f,  -0.7f);
    glEnd();

     glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.75f, -0.65f);
      glVertex2f( 0.75f, -0.58f);
      glVertex2f( 0.8f,  -0.58f);
      glVertex2f( 0.8f,  -0.65f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.78f, -0.7f);
      glVertex2f( 0.73f, -0.7f);
      glVertex2f( 0.73f,  -0.72f);
      glVertex2f( 0.78f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.75f, -0.65f);
      glVertex2f( 0.8f, -0.65f);
      glVertex2f( 0.78f,  -0.7f);
      glVertex2f( 0.73f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.85f, -0.65f);
      glVertex2f( 0.85f, -0.58f);
      glVertex2f( 0.9f,  -0.58f);
      glVertex2f( 0.9f,  -0.65f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.88f, -0.7f);
      glVertex2f( 0.83f, -0.7f);
      glVertex2f( 0.83f,  -0.72f);
      glVertex2f( 0.88f,  -0.72f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.85f, -0.65f);
      glVertex2f( 0.9f, -0.65f);
      glVertex2f( 0.88f,  -0.7f);
      glVertex2f( 0.83f,  -0.7f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.95f, -0.65f);
      glVertex2f( 0.95f, -0.58f);
      glVertex2f( 0.996f,  -0.58f);
      glVertex2f( 0.996f,  -0.65f);
    glEnd();
    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.98f, -0.7f);
      glVertex2f( 0.93f, -0.7f);
      glVertex2f( 0.93f,  -0.72f);
      glVertex2f( 0.98f,  -0.72f);
    glEnd();


glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.95f, -0.65f);
      glVertex2f( 0.996f, -0.65f);
      glVertex2f( 0.98f,  -0.7f);
      glVertex2f( 0.93f,  -0.7f);
    glEnd();



    ///Divider between river and Road 3(End)


glBegin(GL_QUADS);
glColor3f(0.0f, 0.5f, 0.0f);

      if(night){
        glColor3f(0.0f, 0.18f, 0.0f);
      }
       glVertex2f( -1.0f,0.01f);
      glVertex2f( -1.0f, 0.15f);
      glVertex2f( 1.0f,0.15f);
      glVertex2f( 1.0f,0.01f);
      glEnd();

}


Tree(){
    ///Tree.....

      glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.48f, 0.04f);
      glVertex2f( 0.48f, 0.28f);
      glVertex2f( 0.52f,  0.28f);
      glVertex2f( 0.52f,  0.04f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.48f, 0.28f);
      glVertex2f( 0.44f, 0.34f);
      glVertex2f( 0.45f,  0.35f);
      glVertex2f( 0.50f,  0.28f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.52f, 0.28f);
      glVertex2f( 0.56f, 0.34f);
      glVertex2f( 0.55f,  0.35f);
      glVertex2f( 0.50f,  0.28f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f( 0.495f, 0.28f);
      glVertex2f( 0.495f, 0.35f);
      glVertex2f( 0.505f,  0.36f);
      glVertex2f( 0.505f,  0.28f);
      glEnd();

      treecircle(0.50f,0.39f,0.07f);
      treecircle(0.41f,0.38f,0.06f);

      treecircle(0.46f,0.46f,0.05f);
      treecircle(0.58f,0.38f,0.06f);
      treecircle(0.56f,0.46f,0.05f);
      treecircle(0.51f,0.49f,0.05f);



      ///Tree....end
}

LampPost(){
     ///Lamp post(Start)

      glBegin(GL_QUADS);
      glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f( -0.6f,0.01f);
      glVertex2f( -0.6f, 0.2f);
      glVertex2f( -0.62f,0.2f);
      glVertex2f( -0.62f,0.01f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f( -0.62f,0.2f);
      glVertex2f( -0.65f, 0.26f);
      glVertex2f( -0.64f,0.27f);
      glVertex2f( -0.61f,0.2f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f( -0.65f, 0.25f);
      glVertex2f( -0.69f, 0.28f);
      glVertex2f( -0.68f,0.32f);
      glVertex2f( -0.64f,0.28f);
      glEnd();

 glBegin(GL_QUADS);
      glColor3f(0.5f, 0.5f, 0.5f);
      glVertex2f( -0.6f,0.2f);
      glVertex2f( -0.57f, 0.26f);
      glVertex2f( -0.58f,0.27f);
      glVertex2f( -0.61f,0.2f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f( -0.57f, 0.25f);
      glVertex2f( -0.53f, 0.28f);
      glVertex2f( -0.54f,0.32f);
      glVertex2f( -0.58f,0.28f);
      glEnd();

      ///lamp post 1 (End)


      ///Lamp post 2 (Start)

      glBegin(GL_QUADS);
      glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f( 0.6f,0.01f);
      glVertex2f( 0.6f, 0.2f);
      glVertex2f( 0.62f,0.2f);
      glVertex2f( 0.62f,0.01f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f( 0.62f,0.2f);
      glVertex2f( 0.65f, 0.26f);
      glVertex2f( 0.64f,0.27f);
      glVertex2f( 0.61f,0.2f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f( 0.65f, 0.25f);
      glVertex2f( 0.69f, 0.28f);
      glVertex2f( 0.68f,0.32f);
      glVertex2f( 0.64f,0.28f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.5f, 0.5f, 0.5f);
      glVertex2f( 0.6f,0.2f);
      glVertex2f( 0.57f, 0.26f);
      glVertex2f( 0.58f,0.27f);
      glVertex2f( 0.61f,0.2f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f( 0.57f, 0.25f);
      glVertex2f( 0.53f, 0.28f);
      glVertex2f( 0.54f,0.32f);
      glVertex2f( 0.58f,0.28f);
      glEnd();

      ///lamp post 2 (End)
}

Boat(){
    ///Boat ---

      glPushMatrix();
      glTranslatef(positionBoat,0.0f, 0.0f);

      glBegin(GL_QUADS);
      glColor3f(0.1f, 0.0f, 0.0f);
       glVertex2f( -0.83f, -0.97f);
      glVertex2f( -0.90f, -0.88f);
      glVertex2f( -0.08f,  -0.88f);
      glVertex2f( -0.15f,  -0.97f);
      glEnd();

      glBegin(GL_QUADS);
     glColor3f(1.0f, 0.0f, 1.0f);
      glVertex2f( -0.85f, -0.88f);
      glVertex2f( -0.80f, -0.76f);
      glVertex2f( -0.20f,  -0.76f);
      glVertex2f( -0.15f,  -0.88f);
      glEnd();

      glBegin(GL_TRIANGLES);
     glColor3f(2.0f, 0.5f, 1.0f);
      glVertex2f( -0.65f, -0.76f);
      glVertex2f( -0.55f, -0.6f);
      glVertex2f( -0.45f,  -0.76f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.0f, 1.0f, 1.0f);
      glVertex2f( -0.80f, -0.80f);
      glVertex2f( -0.75f, -0.80f);
      glVertex2f( -0.75f,  -0.85f);
      glVertex2f( -0.80f,  -0.85f);
      glEnd();

 glBegin(GL_QUADS);
      glColor3f(0.5f, 1.0f, 1.0f);
      glVertex2f( -0.70f, -0.80f);
      glVertex2f( -0.65f, -0.80f);
      glVertex2f( -0.65f,  -0.85f);
      glVertex2f( -0.70f,  -0.85f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.5f, 1.0f, 1.0f);
      glVertex2f( -0.60f, -0.80f);
      glVertex2f( -0.65f, -0.80f);
      glVertex2f( -0.65f,  -0.85f);
      glVertex2f( -0.60f,  -0.85f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.5f, 1.0f, 1.0f);
      glVertex2f( -0.50f, -0.80f);
      glVertex2f( -0.55f, -0.80f);
      glVertex2f( -0.55f,  -0.85f);
      glVertex2f( -0.50f,  -0.85f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.5f, 1.0f, 1.0f);
      glVertex2f( -0.45f, -0.80f);
      glVertex2f( -0.35, -0.80f);
      glVertex2f( -0.35f,  -0.85f);
      glVertex2f( -0.45f,  -0.85f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(0.5f, 1.0f, 1.0f);
      glVertex2f( -0.30f, -0.80f);
      glVertex2f( -0.25f, -0.80f);
      glVertex2f( -0.25f,  -0.85f);
      glVertex2f( -0.30f,  -0.85f);
      glEnd();
      glPopMatrix();


      ///Boat End..
}

Banch(){
    glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      if(night)
         glColor3ub(192, 192, 192);
      glVertex2f( 0.75f, 0.01f);
      glVertex2f( 0.75f, 0.08f);
      glVertex2f( 0.76f,  0.08f);
      glVertex2f( 0.76f,  0.01f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      if(night)
         glColor3ub(192, 192, 192);

      glVertex2f( 0.96f, 0.01f);
      glVertex2f( 0.96f, 0.09f);
      glVertex2f( 0.97f,  0.09f);
      glVertex2f( 0.97f,  0.01f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
     if(night)
         glColor3ub(192, 192, 192);
      glVertex2f( 0.73f, 0.06f);
      glVertex2f( 0.76f, 0.1f);
      glVertex2f( 0.98f,  0.1f);
      glVertex2f( 0.95f,  0.06f);
      glEnd();

 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      if(night)
         glColor3ub(192, 192, 192);
      glVertex2f( 0.77f, 0.01f);
      glVertex2f( 0.77f, 0.08f);
      glVertex2f( 0.78f,  0.08f);
      glVertex2f( 0.78f,  0.01f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      if(night)
         glColor3ub(192, 192, 192);
      glVertex2f( 0.93f, 0.01f);
      glVertex2f( 0.93f, 0.09f);
      glVertex2f( 0.94f,  0.09f);
      glVertex2f( 0.94f,  0.01f);
      glEnd();

            glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      if(night)
         glColor3ub(192, 192, 192);
      glVertex2f( 0.97f, 0.1f);
      glVertex2f( 0.97f, 0.15f);
      glVertex2f( 0.98f,  0.15f);
      glVertex2f( 0.98f,  0.1f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      if(night)
         glColor3ub(192, 192, 192);
      glVertex2f( 0.76f, 0.1f);
      glVertex2f( 0.76f, 0.15f);
      glVertex2f( 0.77f,  0.15f);
      glVertex2f( 0.77f,  0.1f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
     if(night)
         glColor3ub(192, 192, 192);
      glVertex2f( 0.86f, 0.1f);
      glVertex2f( 0.86f, 0.15f);
      glVertex2f( 0.87f,  0.15f);
      glVertex2f( 0.87f,  0.1f);
      glEnd();

      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      if(night)
         glColor3ub(192, 192, 192);
      glVertex2f( 0.76f, 0.15f);
      glVertex2f( 0.76f, 0.16f);
      glVertex2f( 0.98f,  0.16f);
      glVertex2f( 0.98f,  0.15f);
      glEnd();

            glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      if(night)
         glColor3ub(192, 192, 192);
      glVertex2f( 0.76f, 0.13f);
      glVertex2f( 0.76f, 0.14f);
      glVertex2f( 0.98f,  0.14f);
      glVertex2f( 0.98f,  0.13f);
      glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      if(night)
         glColor3ub(192, 192, 192);
      glVertex2f( 0.76f, 0.11f);
      glVertex2f( 0.76f, 0.12f);
      glVertex2f( 0.98f,  0.12f);
      glVertex2f( 0.98f,  0.11f);
      glEnd();


}

void init() {


 if(night==false){
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
 }
 else{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
 }



   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, 1000.0, 0.0, 750.0);
   }

void handleMouse(int button, int state, int x, int y) {


	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {


switch (key)
{


case 'r':
rainday = true;
Rain(rain);
break;



case 'e':
rainday = false;
break;

case 'n':
night = true;
init();
break;

case 'd':
night = false;
init();
break;




case 27:
exit(0);
break;


default:
break;
}
glutPostRedisplay();



}






void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();

  /// building

  building();



   glBegin(GL_LINES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-1.0f,0.0f);
   glVertex2f(1.0f, 0.0f);
   glEnd();

  glBegin(GL_QUADS);           ///River

      glColor3f(0.0f, 0.5f, 1.0f);
       if(night){
    glColor3f(0.0f, 0.0f, 1.0f);
  }
      glVertex2f(-1.0f, -1.0f);
      glVertex2f( -1.0f, -0.7f);
      glVertex2f( 1.0f,  -0.7f);
      glVertex2f(1.0f,  -1.00f);
    glEnd();





    Road();/// Road , Road side and walkway


   ///All Cars
   car1();
   car2();
   car4();
   car3();

   RoadsideDivider();

   Tree();


   LampPost();

   Boat();


   Banch();






/// Star----------------////

    star();

///sun..............sun..........


    Sun(0.85f,0.85f,0.08f);



///Cloud...(Start)

     Cloud1();
     Cloud2();
     Cloud3();
     Cloud4();

///cloud..(End)




/// plane



    glPushMatrix();
    glTranslatef(positionplane,0.0f, 0.0f);
    plane();
    glPopMatrix();



   glFlush();
}



int main(int argc, char** argv) {

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(1000, 750);
   glutInitWindowPosition(50, 32);
   glutCreateWindow("...Project...");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(100, update, 0);
  // sndPlaySound(("Car Drive By.wav"),SND_ASYNC);
   glutMainLoop();
   return 0;
}
