#include<stdio.h>
#include<GL/glut.h>

float th;

void mydisplay(){
    glBegin(GL_POLYGON);
    glVertex2f(100,100);
    glVertex2f(100,400);
    glVertex2f(300,100);
    glEnd();
    glFlush();
}

void init(){
    //glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(500,-500,500,-500);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv){
    printf("enter the rotation angle");
    scanf("%d",&th);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    init();
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("triangle");
    glutDisplayFunc(mydisplay);
    glutCreateMenu("gf");
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutAddMenuEntry("rotate",1);
    glutAddMenuEntry("ate",1);
    glutAddMenuEntry("r",1);
    glutMainLoop();
    return 0;
}