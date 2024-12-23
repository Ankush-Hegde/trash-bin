#include<stdio.h>
#include<GL/glut.h>

int x1,y11,x2,y2;

void myInit(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,1);
    gluOrtho2D(500,-500,500,-500);
}

void  display()
{
    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0,1,0);
    glVertex2i(400, 421);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(100,100);
    glVertex2f(100,400);
    glVertex2f(300,100);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    printf( "Enter (x1, y11, x2, y2)\n");
    //scanf("%d %d %d %d", &x1, &y11, &x2, &y2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}