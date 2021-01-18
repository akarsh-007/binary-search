#include<stdlib.h>
//#include<conio.h>
#include<stdio.h>
#include<GL/freeglut.h>
#include<string.h>
//#include<windows.h>
void myDisplay(void);
int binary_search();
void delay();
void drawstring(GLfloat x,GLfloat y,char *string);
void *currentfont;
int  n,a[10],key;
int lo[10],hi[10],f;
int b=0;
int u=0,g1=0;
char buf[10];
#define CHAR_BITS 16
const char *my_itoa_buf(char *buf, size_t len, int num)
{
  static char loc_buf[sizeof(int) * CHAR_BITS]; /* not thread safe */

  if (!buf)
  {
    buf = loc_buf;
    len = sizeof(loc_buf);
  }

  if (snprintf(buf, len, "%d", num) == -1)
    return ""; /* or whatever */

  return buf;
}

const char *my_itoa(int num)
{ return my_itoa_buf(NULL, 0, num); }

void renderscene()
{

}
void setFont(void *font)
{
	currentfont=font;
}
void init(void)
{
	glClearColor(0,0,0,1);
	glLineWidth(1.5);
	glColor3f(0.65,0.65,0.65);
	gluOrtho2D(0.0,640.0,0.0,480.0);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
}
void delay()
{
     int i,j;
	for(i=0;i<32;i++)
		for(j=0;j<15;j++);
}
void drawstring(GLfloat x,GLfloat y,char *string)
{
    char *c;
	glRasterPos2f(x,y);
	for(c=string;
			*c!='\0';
			c++)
	{
		glutBitmapCharacter(currentfont,*c);
	}
}
void draw_init()
{
	int h,k,l,m;

		h=150+0*50;
		k=200+0*50;
		glBegin(GL_LINE_LOOP);
			glColor3f(1,0,0);
			glVertex2i(h,150);
			glVertex2i(k,150);
			glVertex2i(k,200);
			glVertex2i(h,200);
		glEnd();
	glFlush();
			l=150+(n-1)*50;
		m=200+(n-1)*50;
		glBegin(GL_LINE_LOOP);
			glColor3f(0,0,1);
			glVertex2i(l,150);
			glVertex2i(m,150);
			glVertex2i(m,200);
			glVertex2i(l,200);
		glEnd();
	glFlush();
}
void draw_low()
{
	int i=0,h,k;

	for(i=0;i<b;i++)
	{
		h=150+lo[i]*50;
		k=200+lo[i]*50;
		glBegin(GL_LINE_LOOP);
			glColor3f(1,0,0);
			glVertex2i(h,150);
			glVertex2i(k,150);
			glVertex2i(k,200);
			glVertex2i(h,200);
		glEnd();
	  glFlush();
	  delay();
	  if(i!=(b-1))
	  {
	  		h=150+lo[i]*50;
		k=200+lo[i]*50;
		glBegin(GL_LINE_LOOP);
			glColor3f(1,1,1);
			glVertex2i(h,150);
			glVertex2i(k,150);
			glVertex2i(k,200);
			glVertex2i(h,200);
		glEnd();
	glFlush();
	  }
	}
}
void draw_high()
{
	int i=0,h,k;

	for(i=0;i<u;i++)
	{
		h=150+hi[i]*50;
		k=200+hi[i]*50;
		glBegin(GL_LINE_LOOP);
			glColor3f(0,0,1);
			glVertex2i(h,150);
			glVertex2i(k,150);
			glVertex2i(k,200);
			glVertex2i(h,200);
		glEnd();
		glFlush();
		 delay();
		 if(i!=(u-1))
		 {
		 		glBegin(GL_LINE_LOOP);
			glColor3f(1,1,1);
			glVertex2i(h,150);
			glVertex2i(k,150);
			glVertex2i(k,200);
			glVertex2i(h,200);
		glEnd();
		glFlush();
		 }
	}
}
void draw_key()
{
	int i=0,h,k;

      	h=150+key*50;
		k=200+key*50;
		glBegin(GL_LINE_LOOP);
			glColor3f(0,1,0);
			glVertex2i(h,150);
			glVertex2i(k,150);
			glVertex2i(k,200);
			glVertex2i(h,200);
		glEnd();
			glFlush();
    glColor3f(0,1,0);
	drawstring(50,100,"KEY FOUND");
}
void MOUSE(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON &&state==GLUT_DOWN)
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		   delay();
	glColor3f(1,0.5,0);
	 drawstring(110,400,"***********TOPIC:BINARY SEARCH************ ");
	 glFlush();
	 delay();
	 glColor3f(0,0,1);
	 drawstring(350,350,"SUBMITTED BY ");
	 delay();
	  drawstring(150,325,"AKARSH S AMBLE & PRASHANTH H N");
		delay();
		glFlush();
	drawstring(150,300,"6TH SEM CSE");
	delay();
		glFlush();
	drawstring(150,275,"U.S.N:4MN17CS002 & U.S.N:4MN17CS024");
	delay();
	glFlush();
	glColor3f(1,0,0);
	drawstring(130,210," CLICK RIGHT MOUSE BUTTON ");
	drawstring(150,180,"  FOR FURTHER OPTIONS");
	glFlush();
//glutSwapBuffers();
}
//to display sorted array
void draw_tab()
{
	int i,h,k;
	char s[20],*s1;
	for(i=0;i<n;i++)
	{
		h=150+i*50;
		k=200+i*50;
		glBegin(GL_LINE_LOOP);
			glColor3f(1,1,1);
			glVertex2i(h,150);
			glVertex2i(k,150);
			glVertex2i(k,200);
			glVertex2i(h,200);
		glEnd();
		s1=my_itoa(buf[i]);
		glColor3f(1,1,0);
		drawstring(h+20,170,s1);
		glColor3f(1,1,1);
			glFlush();
	}
}
//to display input array
void input_tab()
{

	int i,h,k;
	char s[20],*s1;
	for(i=0;i<n;i++)
	{
		h=150+i*50;
		k=200+i*50;
		glBegin(GL_LINE_LOOP);
			glColor3f(1,1,1);
			glVertex2i(h,150);
			glVertex2i(k,150);
			glVertex2i(k,200);
			glVertex2i(h,200);
		glEnd();
		s1=my_itoa(a[i]);
		glColor3f(1,1,0);
		drawstring(h+20,170,s1);
		glColor3f(1,1,1);
		glFlush();
	}
}
//to display search array
void search_tab()
{
	int i,h,k;
	char s[20],*s1;
	 glColor3f(0,0,1);
		drawstring(50,310,"HIGH");
	glBegin(GL_POLYGON);
            glColor3f(0,0,1);
			glVertex2i(150,300);
			glVertex2i(150,320);
			glVertex2i(250,320);
			glVertex2i(250,300);
		glEnd();
		    glFlush();
		  glColor3f(0,1,0);
		drawstring(50,360,"KEY");
			glBegin(GL_POLYGON);
    glFlush();
	                    glColor3f(0,1,0);
			glVertex2i(150,350);
			glVertex2i(150,370);
			glVertex2i(250,370);
			glVertex2i(250,350);
		glEnd();
		    glFlush();
		 glColor3f(1,0,0);
		drawstring(50,410,"LOW");
			glBegin(GL_POLYGON);
    glFlush();
	                    glColor3f(1,0,0);
			glVertex2i(150,400);
			glVertex2i(150,420);
			glVertex2i(250,420);
			glVertex2i(250,400);
		glEnd();
	glFlush();
		delay();
	for(i=0;i<n;i++)
	{
		h=150+i*50;
		k=200+i*50;
		glBegin(GL_LINE_LOOP);
			glColor3f(1,1,1);
			glVertex2i(h,150);
			glVertex2i(k,150);
			glVertex2i(k,200);
			glVertex2i(h,200);
		glEnd();
		s1=my_itoa(buf[i]);
		glColor3f(1,1,0);
		drawstring(h+20,170,s1);
		glColor3f(1,1,1);
		    glFlush();
	}
	draw_init();
    draw_low();
    draw_high();
    if(f==1)
    {
  //  draw_low_high();
    draw_key();
    }
    else
    {
        glColor3f(1,0,0);
	drawstring(50,100,"KEY NOT FOUND !");
    }
}
//sorting is done
void swap(char *x,char *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}
int choose_pivot(int i,int j )
{
   return((i+j) /2);
}
void quicksort(char list[],int m,int n)
{
   int key,i,j,k;
   if( m < n)
   {
      k = choose_pivot(m,n);
      swap(&list[m],&list[k]);
      key = list[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i] <= key))
                i++;
         while((j >= m) && (list[j] > key))
                j--;
         if( i < j)
                swap(&list[i],&list[j]);
      }
      swap(&list[m],&list[j]);
      quicksort(list,m,j-1);
      quicksort(list,j+1,n);
   }
}
//to call display of sorted array
void sorted_array(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	  glColor3f(1,1,0);
	drawstring(50,255,"SORTED ARRAY");
	draw_tab();
	glFlush();
//	glutSwapBuffers();
}
//to call display of input array
void input_array(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	  glColor3f(1,0,1);
	drawstring(50,255,"INPUT ARRAY");
	input_tab();
	glFlush();
	glutSwapBuffers();
}
//to call display of search array
void binary_array(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	  glColor3f(0,0,0);
	drawstring(50,255,"SEARCH ARRAY");
    search_tab();
	glFlush();
//	glutSwapBuffers();
}
//search element
int binary_search()
{
   int i,first, last, middle, search, array[100];
   for(i=0;i<n;i++)
   {
                   array[i]=buf[i];
   }
   printf("Enter the search value<-----");
   scanf("%d",&search);
   printf("\n\n\n\n");
   first = 0;lo[b]=first;b++;
   last = n - 1;hi[u]=last;u++;
   middle = (first+last)/2;
   while( first <= last )
   {
      if ( array[middle] < search )
        {
           first = middle + 1;
           lo[b]=first;
           b++;
        }
      else if ( array[middle] == search )
      {
           f=1;
         printf("press ENTER\n\n");key=middle;
         break;
      }
      else
      {
         last = middle - 1;
         hi[u]=last;
         u++;
      }
      middle = (first + last)/2;
   }
   if ( first > last )
      printf("Not found! %d is not present in the list.\n", search);
//   getch();
   return 0;
}
//menu func
void top_menu(int option)
{
     switch(option)
     {
                   case 0:glClear(GL_COLOR_BUFFER_BIT);
                        input_array();
                        glutPostRedisplay();
                        break;
                   case 1:glClear(GL_COLOR_BUFFER_BIT);
                        sorted_array();
                        glutPostRedisplay();
                        break;
                   case 2:glClear(GL_COLOR_BUFFER_BIT);
                        binary_array();
                        glutPostRedisplay();
                        break;
                   case 3:exit(0);
     }
}
//calls quicksort and binary search.
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(800,500);
	glutInitWindowPosition(700,150);
	glutCreateWindow("project");
	glutDisplayFunc(renderscene);
	printf("enter the value of n \n");
	scanf("%d",&n);
	int i=0;
    printf("enter the values \n");
 	for(i=0;i<n;i++)
    {
	scanf("%d",&a[i]);
	buf[i]=a[i];
	}
	printf("\n\n\n\n");
    quicksort(buf,0,n-1);
    binary_search();
   printf("------------GO TO THE WINDOW AND CLICK LEFT MOUSE BUTTON-------------\n\n\n\n\n");
   glutMouseFunc(MOUSE);
   glutCreateMenu(top_menu);
   glutAddMenuEntry("input array",0);
   glutAddMenuEntry("sorted array",1);
   glutAddMenuEntry("binary search",2);
   glutAddMenuEntry("exit",3);
   glutAttachMenu(GLUT_RIGHT_BUTTON);
	init();
	glutMainLoop();
	return 0;
}

