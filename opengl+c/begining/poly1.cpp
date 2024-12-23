#include<GL/glut.h>
void init56(){
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1.0,0.0,1.0);
}

void displaysee(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_POLYGON);
      glVertex3f (0.25, 0.25, 0.0);
      glVertex3f (0.75, 0.25, 0.0);
      glVertex3f (0.75, 0.75, 0.0);
      glVertex3f (0.25, 0.75, 0.0);
	glEnd();
	glFlush();
}
int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250,250);
	glutInitWindowPosition(100,100);
	glutCreateWindow("empty");
	init56();
	glutDisplayFunc(displaysee);
	glutMainLoop();
	return 0;
}
