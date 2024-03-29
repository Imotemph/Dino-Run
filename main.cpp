#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>
#include <gl/glut.h>
#define pi (2*acos(0.0))
#include <iostream>
#include<MMSystem.h>
#include <string>
#include <sstream>

///Variables for Projects
using namespace std;
float posX = 20, posY = 0, posZ = 0;
float robX=-18 ,robY=-14;
float legL=0,legR=0;
float mountainX=0;
int l=0,r=0;
float move_unit = 0.1f,cloudX=0,score=0,highscore;
int j=0;
bool gameOver=true;
float eyeR=1,eyeG=0,eyeB=0;

void dino(){

    glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glVertex2f(-0.5, -0.10);
        glVertex2f(-0.5, 0.10);
        glVertex2f(0.5, 0.10);
        glVertex2f(0.5, -0.10);
    glEnd();
    glBegin(GL_QUADS);
        int a=0;
        int b=0;
        glColor3f(0.184, 0.410, 0.310); //dark blue
        glVertex2f(a,b);
        glVertex2f(a+1.5,b);
        glVertex2f(a+1.5,b+3);
        glVertex2f(a,b+3);

        glVertex2f(a+.5,b);
        glVertex2f(a+1.5,b);
        glVertex2f(a+1.5,b+6);
        glVertex2f(a+.5,b+6);

        glVertex2f(a+.3,b);
        glVertex2f(a+1.5,b);
        glVertex2f(a+1.5,b+3.5);
        glVertex2f(a+.3,b+3.5);

        glVertex2f(a-.6,b);
        glVertex2f(a+1.5,b);
        glVertex2f(a+1.5,b+2);
        glVertex2f(a-.6,b+2);

        glVertex2f(a-.3,b);
        glVertex2f(a+1.5,b);
        glVertex2f(a+1.5,b+2.5);
        glVertex2f(a-.3,b+2.5);

        glVertex2f(a+.5,b+3.1);
        glVertex2f(a+3,b+3.1);
        glVertex2f(a+3,b+6);
        glVertex2f(a+.5,b+6);

        glVertex2f(a+.5,b+2.5);
        glVertex2f(a+1.7,b+2.5);
        glVertex2f(a+1.7,b+6);
        glVertex2f(a+.5,b+6);

        glVertex2f(a+.5,b+2.5);
        glVertex2f(a+2.5,b+2.5);
        glVertex2f(a+2.5,b+2.7);
        glVertex2f(a+.5,b+2.7);

        glVertex2f(a+.8,b+6.5);
        glVertex2f(a+2.8,b+6.5);
        glVertex2f(a+2.8,b+6);
        glVertex2f(a+.8,b+6);

        //Tail & Thigh portion
        glVertex2f(a-1.2,b-.6);
        glVertex2f(a+1.2,b-.6);
        glVertex2f(a+1.2,b+1.8);
        glVertex2f(a-1.2,b+1.8);

        glVertex2f(a-.9,b-.6);
        glVertex2f(a+.9,b-.6);
        glVertex2f(a+.9,b-1.2);
        glVertex2f(a-.9,b-1.2);

        glVertex2f(a-.9,b-1.6);
        glVertex2f(a+.7,b-1.6);
        glVertex2f(a+.7,b-1.2);
        glVertex2f(a-.9,b-1.2);

        glVertex2f(a-.7,b+1.6);
        glVertex2f(a+2,b+1.6);
        glVertex2f(a+2,b+2);
        glVertex2f(a-.7,b+2);

        glVertex2f(a+1.8,b+1.1);
        glVertex2f(a+2,b+1.1);
        glVertex2f(a+2,b+2);
        glVertex2f(a+1.8,b+2);

        glVertex2f(a-1.5,b);
        glVertex2f(a-1.1,b);
        glVertex2f(a-1.1,b+2.4);
        glVertex2f(a-1.5,b+2.4);

        glVertex2f(a-1.7,b+.3);
        glVertex2f(a-1.3,b+.3);
        glVertex2f(a-1.3,b+2.9);
        glVertex2f(a-1.7,b+2.9);

        glVertex2f(a-1.9,b+.8);
        glVertex2f(a-1.6,b+.8);
        glVertex2f(a-1.6,b+4);
        glVertex2f(a-1.9,b+4);

        if(eyeG==0)
        {
            glColor3f(rand()/((float)RAND_MAX+1),eyeG,eyeB);
            glVertex2f(a+1,b+5);
            glVertex2f(a+1.4,b+5);
            glVertex2f(a+1.4,b+5.5);
            glVertex2f(a+1,b+5.5);
        }
        else
        {
            glColor3f(eyeR,eyeG,eyeB);
            glVertex2f(a+1,b+5.2);
            glVertex2f(a+1.6,b+5);
            glVertex2f(a+1.6,b+5.5);
            glVertex2f(a+1,b+5.2);
        }
    glColor3f(0.184, 0.410, 0.310);
    glEnd();
}

void triangle()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.420, 0.557, 0.137);
        glVertex2f(-15,3);
        glVertex2f(-25,-15);
        glVertex2f(-4,-15);
    glEnd();
}

void backTriangle()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.333, 0.420, 0.184);
        glVertex2f(2,-1);
        glVertex2f(-5,-15);
        glVertex2f(10,-15);
    glEnd();
}

void backgroundTree()
{
    glBegin(GL_QUADS);
        glColor3f(1.0, .5, 0);
        glVertex2f(-5.5,-15);
        glVertex2f(-5,-15);
        glVertex2f(-5,-10);
        glVertex2f(-5.5,-10);

        glVertex2f(-5.5,-10);
        glVertex2f(-5.2,-10);
        glVertex2f(-5.7,-8);
        glVertex2f(-6,-8);

        glVertex2f(-5,-10);
        glVertex2f(-5.3,-10);
        glVertex2f(-4.8,-8);
        glVertex2f(-4.5,-8);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(255.0/256.0, 183.0/256.0, 203.0/256.0);
        glVertex2f(-7,-8);
        glVertex2f(-6,-3);
        glVertex2f(-4.5,-3);
        glVertex2f(-3.5,-8);
        glVertex2f(-4.9,0);
    glEnd();
}
void leg2()
{
    int a=0;
    int b=0;
    glBegin(GL_POLYGON);
        glVertex2f(a+.7,b-1.6);
        glVertex2f(a+.2,b-1.6);
        glVertex2f(a+.2,b-2);
        glVertex2f(a+.7,b-2);
        glVertex2f(a+.7,b-2);
        glVertex2f(a+.5,b-2);
        glVertex2f(a+.5,b-2.8);
        glVertex2f(a+.7,b-2.8);
        glVertex2f(a+.7,b-2.8);     //
        glVertex2f(a+.9,b-2.8);
        glVertex2f(a+.9,b-2.5);
        glVertex2f(a+.7,b-2.5);
    glEnd();
}

void leg1()
{
    int a=0;
    int b=0;
    glBegin(GL_POLYGON);
        glVertex2f(a-.7,b-1.6);
        glVertex2f(a-.1,b-1.6);
        glVertex2f(a-.1,b-2);
        glVertex2f(a-.7,b-2);
        glVertex2f(a-.7,b-2);
        glVertex2f(a-.5,b-2);
        glVertex2f(a-.5,b-2.8);
        glVertex2f(a-.7,b-2.8);
        glVertex2f(a-.5,b-2.8);     //
        glVertex2f(a-.3,b-2.8);
        glVertex2f(a-.3,b-2.5);
        glVertex2f(a-.5,b-2.5);
    glEnd();
}

void background(){
    glBegin(GL_QUADS);
        glColor3f(1.0,0.627,0.478);
        glVertex2f(-20, -15);
        glVertex2f(20, -15);
        glVertex2f(20, -20);
        glVertex2f(-20, -20);
    glEnd();
}

void tree(){

    glBegin(GL_QUADS);
        glColor3f(0.0, 0.392, 0.0);
        glVertex2f(10,-16);
        glVertex2f(11,-16);
        glVertex2f(11,-9);
        glVertex2f(10, -9);

        glVertex2f(9,-11);
        glVertex2f(10,-11);
        glVertex2f(10,-12);
        glVertex2f(9, -12);

        glVertex2f(9,-11);
        glVertex2f(9.5,-11);
        glVertex2f(9.5,-10);
        glVertex2f(9, -10);

        glVertex2f(11,-14);
        glVertex2f(12,-14);
        glVertex2f(12,-13);
        glVertex2f(11, -13);

        glVertex2f(11.5,-14);
        glVertex2f(12,-14);
        glVertex2f(12,-11);
        glVertex2f(11.5, -11);
    glEnd();

    //dots
    glPointSize(4);
    glBegin(GL_POINTS);
        glColor3f(0.804, 0.361, 0.361);
        glVertex2f(0, -16);
        glVertex2f(2, -16);
        glVertex2f(3, -17);
        glVertex2f(5, -17);
        glVertex2f(7, -18);
        glVertex2f(8, -17);

        glVertex2f(9, -16);
        glVertex2f(11, -16);
        glVertex2f(12, -17);
        glVertex2f(14, -17);
        glVertex2f(15, -18);
        glVertex2f(17, -17);

        glVertex2f(19, -16);
        glVertex2f(20, -16);
        glVertex2f(21, -17);
        glVertex2f(23, -17);
        glVertex2f(25, -18);
        glVertex2f(27, -17);

        glVertex2f(28, -16);
        glVertex2f(29, -16);
        glVertex2f(31, -17);
        glVertex2f(33, -17);
        glVertex2f(34, -18);
        glVertex2f(36, -17);

        glVertex2f(37, -16);
        glVertex2f(39, -16);
        glVertex2f(41, -17);
        glVertex2f(43, -17);
        glVertex2f(44, -18);
        glVertex2f(46, -17);

        glVertex2f(-2, -16);
        glVertex2f(-4, -16);
        glVertex2f(-7, -17);
        glVertex2f(-8, -17);
        glVertex2f(-10, -18);
        glVertex2f(-11, -17);

        glVertex2f(-13, -18);
        glVertex2f(-14, -19);
        glVertex2f(-16, -16);
        glVertex2f(-18, -18);
        glVertex2f(-20, -16);
        glVertex2f(-21, -19);
        glVertex2f(-22, -20);

        glVertex2f(-24, -16);
        glVertex2f(-23, -18);
        glVertex2f(-25, -17);
        glVertex2f(-27, -19);
        glVertex2f(-29, -16);
        glVertex2f(-30, -18);

        glVertex2f(-31, -16);
        glVertex2f(-33, -18);
        glVertex2f(-35, -17);
        glVertex2f(-36, -19);
        glVertex2f(-38, -16);
        glVertex2f(-39, -18);
    glEnd();
 }

void displayText( float x, float y, int r, int g, int b, const char *string)
{
	int j = strlen( string );
	glColor3f( r, g, b );
	glRasterPos2f( x, y );
	for( int i = 0; i < j; i++ )
    {
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}


void cloud()
{
    glBegin(GL_POLYGON);

        glColor3f(197.0/256, 226.0/256, 247.0/256);
        glVertex2f(1.0,0.7);
        glVertex2f(1.5,1.0);
        glVertex2f(0.7,1.5);
        glVertex2f(0.0,2.0);
        glVertex2f(-0.7,1.5);
        glVertex2f(-1.4,1.6);
        glVertex2f(-1.7,1.0);
        glVertex2f(-1.5,0.7);
        glVertex2f(-1.0,0.5);
    glEnd();
}

void display(){
    //Clear Window
    glClear(GL_COLOR_BUFFER_BIT);
    //load the correct matrix -- MODEL-VIEW matrix
    glMatrixMode(GL_MODELVIEW);
    //initialize the matrix
    glLoadIdentity();
    stringstream s;
    stringstream a;
    s <<(int)score;
    a <<(int)highscore;
    glPushMatrix();
        displayText( 15, 18, 0, 0, 1,a.str().c_str());
        background();
    glPopMatrix();
    glPushMatrix();
        displayText( 18, 18, 1, 0, 0,s.str().c_str());
        background();
    glPopMatrix();
    //Background Items
    glPushMatrix();
        glTranslatef(mountainX,0,0);
        backTriangle();
        triangle();
        backgroundTree();
    glPopMatrix();
    //Collision Tree as if 1st tree
    glPushMatrix();
        glTranslatef(posX+25,posY,posZ);
        tree();
    glPopMatrix();
    //Collision Tree as if 2nd Tree
    glPushMatrix();
        glTranslatef(posX,posY,posZ);
        tree();
    glPopMatrix();
    //Cloud
    glPushMatrix();
        glTranslatef(cloudX,0,0);
        cloud();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(robX,robY,0);
        dino();
    glPopMatrix();
    //Dragon Leg with movement
    glPushMatrix();
        glTranslatef(robX,robY+legL,0);
        leg1();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(robX,robY+legR,0);
        leg2();
    glPopMatrix();
    if(gameOver)
    {
        displayText( -3, 4, 0, 0, 1, "Game Over!!!" );
    }
    if(gameOver)
        displayText( -4, 10, 1, 0, 0, "Click anywhere on the screen to Start Game" );
    if (score>=highscore)
    {
        highscore=score;

    }
    glFlush();
}


void init(){

	//clear the screen and set color to black
	glClearColor(1,1,1,0);


	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	//gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
    gluOrtho2D(-20.0, 20.0, -20.0, 20.0);

}


void jump(int i){
   //cout<<robY<<endl;
    if(robY<5 && i==0)
    {
        robY+=1;
        glutPostRedisplay();
        glutTimerFunc(30,jump,i);
    }
    else
        i++;

    if(i>0 && robY>-14)
    {
        robY-=1;
        glutPostRedisplay();
        glutTimerFunc(30,jump,i);
    }
    if(i>0 && robY==-14)//for fixing multiple jump bug
        j=0;
}

void reset(){
    gameOver=false;
    score=0;
    posX = 20, posY = 0 , posZ = 0;
    robX=-18 ,robY=-14;
    legL=0,legR=0;
    mountainX=0;
    l=0,r=0;
    move_unit = 0.1f;
    j=0;
    eyeR=1,eyeG=0,eyeB=0;
}
void keyboardListener(unsigned char key, int x, int y)
{
    if(key==' ')
    {
        if(!gameOver)
        {
            if(j==0)
            {
                j=1;
                PlaySound(TEXT("jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
                glutTimerFunc(0,jump,0);
            }
        }
    }
    if(key=='r')
    {
        reset();
    }
}

void scenerio(int)
{
    cloudX-=.125;

    if(!gameOver)
    {
        posX-=1;
        if(robX<-16)
        {
            robX+=.1;
        }
        legL+=.4;
        mountainX-=.05;
        score+=.09;
        int speed=80;
        // cout<<(int)score<<endl;
        if(score>20)
        {
            speed=65;
        }
        else if(score>30)
        {
            speed=50;
        }
        if(cloudX<-35)
        {
            cloudX=50;
        }
        if(mountainX<-35)
        {
            mountainX=50;
        }
        if(legL>.5)
        {
            legL=0;
        }
        if(legL<.2)
        {
            legR+=.3;
        }
        else
        {
            legR=0;
        }
        glutPostRedisplay();
     //check colide
        if(posX<-55)
        {
            posX=20;
            posY=rand() % 2 + 0;
        }
        if(posX<-23 && posX>-29 )
        {
            if(robY<-9)
            {
                gameOver=true;
                cout<<"colide"<<endl;
                eyeG=1,eyeB=1;
            }
        // cout<<"tree X :"<<posX<<endl;
        }
        if(posX<-47 && posX>-55 )
        {
            if(robY<-9)
            {
                gameOver=true;
                cout<<"colide"<<endl;
                eyeG=1,eyeB=1;
            }
        }

        glutTimerFunc(speed,scenerio,0);
    }
}

void mouseListener(int button,int state,int x,int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
            {
                if(gameOver)
                {
                    reset();
                    glutTimerFunc(0,scenerio,0);
                }
            }
        break;

        default:
            break;
    }
}

int main(int argc, char** argv){


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Dino Run");
    glutDisplayFunc(display);
    init();
    glutMouseFunc(mouseListener);
    glutKeyboardFunc(keyboardListener);
    glutMainLoop();
}


