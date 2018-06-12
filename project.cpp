#include<stdio.h>
#include<GL/glut.h>
void insert();
void delt();
GLfloat red=1.0,green=0.0,blue=0.0;
void myReshape(int w,int h);
int i=0,x=-1,y=-1;
GLfloat angle=-20.0,xaxis=1.0,yaxis=1.0,zaxis=0.0;
char title[] = "3D queue algorithm ";
void cube()
{
glScaled(0.5,0.5,0.5);
glRotated(angle,xaxis,yaxis,zaxis);
glBegin( GL_QUADS);
    // Top face
    glColor3f(0.0f, 1.0f,  0.0f );  
    glVertex3f(  1.0f, 1.0f, -1.0f ); 
    glVertex3f( -1.0f, 1.0f, -1.0f );
    glVertex3f( -1.0f, 1.0f,  1.0f ); 
    glVertex3f(  1.0f, 1.0f,  1.0f );
 // Bottom face
    glColor3f(   1.0f,  1.0f,  0.0f ); 
    glVertex3f(  1.0f, -1.0f, -1.0f ); 
    glVertex3f( -1.0f, -1.0f, -1.0f );
    glVertex3f( -1.0f, -1.0f,  1.0f ); 
    glVertex3f(  1.0f, -1.0f,  1.0f );
 // Front face
    glColor3f(   red,  green, blue ); 
    glVertex3f(  1.0f,  1.0f, 1.0f );
    glVertex3f( -1.0f,  1.0f, 1.0f );
    glVertex3f( -1.0f, -1.0f, 1.0f );
    glVertex3f(  1.0f, -1.0f, 1.0f ); 
 // Back face
    glColor3f(  0.0f,  1.0f,  0.0f ); 
    glVertex3f(  1.0f, -1.0f, -1.0f );
    glVertex3f( -1.0f, -1.0f, -1.0f );
    glVertex3f( -1.0f,  1.0f, -1.0f ); 
    glVertex3f(  1.0f,  1.0f, -1.0f );
 // Left face
    glColor3f(   0.0f,  0.0f,  1.0f);  
    glVertex3f( -1.0f,  1.0f,  1.0f);
    glVertex3f( -1.0f,  1.0f, -1.0f);
    glVertex3f( -1.0f, -1.0f, -1.0f);
    glVertex3f( -1.0f, -1.0f,  1.0f);
  // Right face
    glColor3f(   0.0f,  1.0f,  1.0f);  
    glVertex3f(  1.0f,  1.0f,  1.0f);
    glVertex3f(  1.0f,  1.0f, -1.0f);
    glVertex3f(  1.0f, -1.0f, -1.0f);
    glVertex3f(  1.0f, -1.0f,  1.0f);  
   glEnd();
   }
 void init(){
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,400.0,0.0,400.0);
glMatrixMode(GL_MODELVIEW);
} 
void initGL() {
   glClearColor(0.0f, 0.0f,0.0f, 1.0f);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);
   glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity();
glutSwapBuffers();
}
void submenu(GLint option)
{
 switch(option)
    {
        case 1: xaxis=1.0;yaxis=0.0;zaxis=0.0;
        break;
        case 2: xaxis=0.0;yaxis=1.0;zaxis=0.0;
         break;
        case 3: xaxis=0.0;yaxis=0.0;zaxis=1.0;
         break;
        case 4: xaxis=1.0;yaxis=1.0;zaxis=0.0;
}
glutPostRedisplay();
}



void menu(GLint option)
{
 switch(option)
    {
        case 1: x++;
        if(x>4)
{
char r1[]="Queue Overflow";
glColor3f(1.0,0.0,1.0);
glRasterPos3f(1.0,-1.5,0.2);
for(i=0;r1[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,r1[i]);
}
        if(x<=4)
{
char str3[]="inserted sucessfully";
glColor3f(0.0,1.0,1.0);
glRasterPos3f(-4.0,-1.2,0.2);
for(i=0;str3[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str3[i]);
}if(x>4)
						x=4;
               insert();
                break;
        case 2:
        			delt();
                break;           
    }
 glutPostRedisplay();
}



void insert()
{

if(x==0 && y==0 ||x==1 && y==1 ||x==2 && y==2 ||x==3 && y==3 || x==4 && y==4)
{

char str2[]="Queue Empty";
glColor3f(1.0,0.0,1.0);
glRasterPos3f(1.0,-1.7,0.2);
for(i=0;str2[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[i]);
glutSwapBuffers();
}
 if(x==0 && y==-1)
{ 
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
red=1.0;blue=green=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

}
if(x==1 && y==-1)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');

green=0.0;blue=0.0;red=1.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=0.0;green=1.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 
}
if(x==2 && y==-1)
{   
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 
green=0.0;blue=0.0;red=1.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=0.0;green=1.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 
}
if(x==3 && y==-1)
{ 
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(0.5,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
red=1.0;blue=1.0;green=0.0;

  glPushMatrix();
  glTranslatef(0.5f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 


red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 

green=0.0;blue=0.0;red=1.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=0.0;green=1.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 
}


 if(x==4 && y==-1)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(0.5,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(1.5,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');

 red=0.2;blue=0.6;green=0.5;
glPushMatrix();
  glTranslatef(1.6f, 0.0f, -5.0f);  
  cube();
glPopMatrix();
glutSwapBuffers(); 

red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 

red=1.0;blue=0.0;green=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=0.0;green=1.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 
red=1.0;blue=1.0;green=0.0;
 glPushMatrix();
  glTranslatef(0.5f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 


}
  
    if(x==1 && y==0)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
  red=0.0;blue=0.0;green=1.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

}
    
    if(x==2 && y==0)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
green=1.0;blue=0.0;red=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 

  }
  
      
    if(x==3 && y==0)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
 
red=1.0;blue=1.0;green=0.0;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 
green=1.0;blue=0.0;red=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 
}
if(x==4 && y==0)
{ 
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(0.5,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
red=0.2;blue=0.5;green=0.6;

  glPushMatrix();
  glTranslatef(0.5f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 


red=1.0;blue=1.0;green=0.0;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 

green=1.0;blue=0.0;red=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 

  }
 
 // y=2
 
    
    if(x==2 && y==1)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
  red=0.0;blue=1.0;green=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();


  }
  
       
    if(x==3 && y==1)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
  green=0.0;blue=1.0;red=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

red=1.0;blue=1.0;green=0.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 
  }
if(x==4 && y==1)
{ 
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');

red=0.2;blue=0.5;green=0.6;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 
green=0.0;blue=1.0;red=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

red=1.0;blue=1.0;green=0.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 

 }
 
 
 
       
    if(x==3 && y==2)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2); 
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
red=1.0;blue=1.0;green=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

  }
 
       
    if(x==4 && y==2)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2); 
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
green=0.0;blue=1.0;red=1.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();

red=0.2;blue=0.5;green=0.6;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 cube();
glPopMatrix();
glutSwapBuffers(); 
 }
  if(x==4 && y==3)
{ 
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2); 
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
green=0.6;blue=0.5;red=0.2;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 cube();
glPopMatrix();
glutSwapBuffers();
}
}

void delt()
{
y++;

 if(y<5  && y<=x)
  {char d1[]="deleted sucessfully";
glColor3f(0.0,1.0,1.0);
glRasterPos3f(-4.0,-1.2,0.2);
for(i=0;d1[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,d1[i]);
  }

if(x<y)
{
printf("queue underflow \n");
if(x==-1&&y>-1)
{
y=-1;
}
}
if(x<y)
y=x;
insert();
}

void key(unsigned char key,int a,int b)
{
if(key=='b')
{
angle+=10;
insert();
}
if(key=='B')
{
angle-=10;
insert();
}

if(key=='z')
{


  delt();
  if(y<5  && y<=x)
  {
  printf("%d deleted sucessfully\n",y+1);
  }

}

if(key=='c')
{  x++;

if(x>4)
{
char r1[]="Queue Overflow";
glColor3f(1.0,0.0,1.0);
glRasterPos3f(1.0,-1.5,0.2);
for(i=0;r1[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,r1[i]);

}


if(x<=4)
{
char str3[]="inserted sucessfully";
glColor3f(0.0,1.0,1.0);
glRasterPos3f(-4.0,-1.2,0.2);
for(i=0;str3[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str3[i]);
}
if(x<5)
{
printf("%d inserted sucessfully\n",x+1);
}
if(x>=5)
{
printf("queue overflow \n");
}
if(x>4)
x=4;
   insert();
}

glutPostRedisplay();
}

void display1(void)
{
glLoadIdentity();
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
char str[]="Implementation Of Queue";
char str1[]="FrontEnd                                                                                                                           Rear End";
glColor3f(1.0,1.0,0.0);
glRasterPos3f(-1.0,1.8,0.2);
for(i=0;str[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
glColor3f(0.0,0.0,1.0);
glRasterPos3f(-4.2,0.04,0.2);
for(i=0;str1[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[i]);


glFlush();

}


void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
	 int id=glutGetWindow(); 
	glutDestroyWindow(id);
	
   glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(2000,500);
   glutInitWindowPosition(0,0);
	glutCreateWindow("queue operation");
	
	glutKeyboardFunc(key);
	glutDisplayFunc(display1);
	glutReshapeFunc(myReshape);
	int id1= glutCreateMenu(submenu);
	glutAddMenuEntry("X-axis",1);
	glutAddMenuEntry("Y-axis",2);
	glutAddMenuEntry("Z-axis",3);
	glutAddMenuEntry("Normal",4);
	glutCreateMenu(menu);
    glutAddMenuEntry("Insert",1);
    glutAddMenuEntry("Delete",2);
    glutAddSubMenu("view of cube",id1);
    
    
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
	initGL();
	glFlush();


	}
}




void display(void)
{
glLoadIdentity();
glClear(GL_COLOR_BUFFER_BIT );
 glPushMatrix(); 
char str[]="Moodalakatte Institute Of Technology";
glColor3f(1.0,0.0,0.0);
glTranslatef(15.0,370.0,0.0);
glScaled(0.1,0.2,0.0);

for(i=0;str[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str[i]);
glPopMatrix();
 glPushMatrix(); 
char st[]="A";
glColor3f(1.0,1.5,1.0);
glTranslatef(190.0,351.0,0.0);
glScaled(0.02,0.08,0.0);
for(i=0;st[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,st[i]);
glPopMatrix();
 glPushMatrix(); 
char st1[]="Mini Project Report On";
glColor3f(1.0,1.5,1.0);
glTranslatef(169.0,330.0,0.0);
glScaled(0.02,0.08,0.0);
for(i=0;st1[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,st1[i]);
glPopMatrix();



 glPushMatrix(); 
   
 char str1[]="AN ANIMATION OF WORKING OF QUEUE OPERATION AND ALGORITHM";
glColor3f(1.0,1.0,0.0);
glTranslatef(80.0,305.0,0.0);
glScaled(0.04,0.1,0.0);

for(i=0;str1[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str1[i]);
char st2[]="by";
glPopMatrix();
glPushMatrix();
glColor3f(1.0,1.5,1.0);
glTranslatef(189.0,285.0,0.0);
glScaled(0.02,0.08,0.0);
for(i=0;st2[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,st2[i]);
glPopMatrix();


 glPushMatrix(); 
 char str2[]="Mr. Gurucharana";
 char str3[]="Ms. Sakshi";
 char str4[]="USN:4MK15CS007";
 char str5[]="USN:4MK15CS026";
glColor3f(1.0,0.06,0.576);
glTranslatef(120.0,260.0,0.0);
glScaled(0.04,0.1,0.0);
for(i=0;str2[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str2[i]);
glPopMatrix();

glPushMatrix();
glColor3f(1.0,0.06,0.576);
glTranslatef(120.0,220.0,0.0);
glScaled(0.04,0.1,10.0);
for(i=0;str3[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str3[i]);
glPopMatrix();


glPushMatrix();
glColor3f(0.0,0.5,1.0);
glTranslatef(210.0,260.0,0.0);
glScaled(0.04,0.1,0.0);
for(i=0;str4[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str4[i]);
glPopMatrix();


glPushMatrix();
glColor3f(0.0,0.5,1.0);
glTranslatef(210.0,220.0,0.0);
glScaled(0.04,0.1,0.0);
for(i=0;str5[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str5[i]);
glPopMatrix();

char str6[]="Under the guidance of";
glPushMatrix();
glColor3f(1.0,1.5,1.0);
glTranslatef(169.0,165.0,0.0);
glScaled(0.02,0.08,0.0);
for(i=0;str6[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str6[i]);
glPopMatrix();

char str7[]="Mr. Muralidhara B.K";
glPushMatrix();
glColor3f(1.0,0.5,0.3);
glTranslatef(150.0,132.0,0.0);
glScaled(0.04,0.1,0.0);
for(i=0;str7[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str7[i]);
glPopMatrix();
glutMouseFunc(mouse);
glFlush();
}
void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,10.0,-10.0);
	else
	glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
printf("implimentation of queue\n");
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(2000,500);
   glutInitWindowPosition(0,0);
   glutCreateWindow(title);
   glutDisplayFunc(display); 
   init();
   glutMainLoop();        
   return 0;
}
