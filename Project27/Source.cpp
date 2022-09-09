#include <glut.h>

#define sunRadius 0.1
#define venusRadius 0.02
#define mercuryRadius 0.04
#define earthRadius 0.06
#define moonRadius 0.01
#define marsRadius 0.04
#define jupiterRadius 0.09
#define saturnRadius 0.08
#define uranusRadius 0.05
#define neptuneRadius 0.05


void drawSolarSystem(void);
void Initialization(void);
void displayFunc(void);
void reshapeFunc(int x, int y);
void idleFunc(void);
void resetScene();
void enableLights();
void reshape(GLsizei width, GLsizei height);
void keyboardClick(unsigned char key, int x, int y);  
void mouseClick(int button, int state, int x, int y);    
void mouseMotion(int x, int y);


GLfloat rotationSpeed = 0.1;
GLfloat daysInYear = 360;
GLfloat year1 = 180;
GLfloat day = -180;
GLfloat year2 = 90;
GLfloat year3 = 0;
GLfloat year4 = -60;
GLfloat year5 = -93;
GLfloat year6 = 69;
GLfloat year7 = 90;
GLfloat year8 = 44;
GLfloat moonAroundEarth = 0.0;
GLfloat moonItsSelf = 0.0;
GLfloat venusOrbitRadius = 0.25;
GLfloat earthOrbitRadius = 0.45;
GLfloat mercuryOrbitRadius = 0.35;
GLfloat marsOrbitRadius = 0.55;
GLfloat jupiterOrbitRadius = 0.65;
GLfloat saturnOrbitRadius = 0.75;
GLfloat uranusOrbitRadius = 0.85;
GLfloat neptuneOrbitRadius = 0.95;
GLfloat moonOrbitRadius = 0.1;
GLfloat moonAroundEarthRate = 3 * rotationSpeed;
GLfloat moonRotationItselfRate = 2.0 * rotationSpeed;
GLfloat dayRate = 5.0 * rotationSpeed;
GLfloat yearRate = daysInYear / 360.0 * dayRate * rotationSpeed; 




int main(int argc, char* argv[])


{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Solar system");
	Initialization();
	glutReshapeFunc(reshapeFunc);
	glutDisplayFunc(displayFunc);
	glutIdleFunc(idleFunc);
	glutMainLoop();
	return 0;
}
void drawSolarSystem(void)
{
	//sun, center
	glPushMatrix();
	gluLookAt(0.0, 2.0, -2.0,   
		0.0, 0.0, 0.0,           
		0.0, 3.0, 0.0);
	glColor3f(1.0, 0.8, 0.3);         
	glutSolidSphere(sunRadius, 70, 70); 
	glPushMatrix();

	//venus
	glRotatef(year1, 0.0, 1.0, 0.0);
	glTranslatef(venusOrbitRadius, 0.0, 0.0);
	glRotatef(-year1, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(day, 0.5, 1.0, 0.0);
	glColor3f(0.8, 0.2, 0.0);
	glutSolidSphere(venusRadius, 8, 8);
	glPopMatrix();

	//mercury
	glRotatef(year2, 0.0, 1.0, 0.0);
	glTranslatef(mercuryOrbitRadius, 0.0, 0.0);
	glRotatef(-year2, 0.0, 1, 0.0);
	glPushMatrix();
	glRotatef(day, 0.50, 1.0, 0.0);
	glColor3f(0.9, 0.0, 0.1);
	glutSolidSphere(mercuryRadius, 10, 10);
	glPopMatrix();

	//earth
	glRotatef(year3, 0.0, 1.0, 0.0); 
	glTranslatef(earthOrbitRadius, 0.0, 0.0); 
	glRotatef(-year3,0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(day, 0.5, 1.0, 0.0);
	glColor3f(0.4, 0.6, 0.3);
	glutSolidSphere(earthRadius, 10, 10);
	glPopMatrix();

	//moon
	glRotatef(moonAroundEarth, 0.0, 1.0, 0.0); 
	glTranslatef(moonOrbitRadius, 0.0, 0.0);  
	glRotatef(-moonAroundEarth, 0.0, 0.0, 0.0);  
	glRotatef(moonItsSelf, 0.0, 1.0, 0.0);
	glColor3f(1, 0.0, 0.0);
	glutSolidSphere(moonRadius, 8, 8);   
	glPopMatrix();

	//mars
	glRotatef(year4, 0.0, 1.0, 0.0);
	glTranslatef(marsOrbitRadius, 0.0, 0.0);
	glRotatef(-year4, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(day, 0.50, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(marsRadius, 9, 9);
	glPopMatrix();

	//jupiter
	glRotatef(year5, 0.0, 1.0, 0.0);
	glTranslatef(jupiterOrbitRadius, 0.0, 0.0);
	glRotatef(-year5, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(day, 0.50, 1.0, 0.0);
	glColor3f(0.5, 0.5, 0.0);
	glutSolidSphere(jupiterRadius, 9, 9);
	glPopMatrix();

	//saturn
	glRotatef(year6, 0.0, 1.0, 0.0);
	glTranslatef(saturnOrbitRadius, 0.0, 0.0);
	glRotatef(-year6, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(day, 0.50, 1.0, 0.0);
	glColor3f(0.4, 0.6, 0.0);
	glutSolidSphere(saturnRadius, 9, 9);
	glPopMatrix();

	//uranus
	glRotatef(year7, 0.0, 1.0, 0.0);
	glTranslatef(uranusOrbitRadius, 0.0, 0.0);
	glRotatef(-year7, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(day, 0.50, 1.0, 0.0);
	glColor3f(0.0, 0.2, 0.8);
	glutSolidSphere(uranusRadius, 9, 9);
	glPopMatrix();

	//neptune
	glRotatef(year8, 0.0, 1.0, 0.0);
	glTranslatef(neptuneOrbitRadius, 0.0, 0.0);
	glRotatef(-year8, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(day, 0.50, 1.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere(neptuneRadius, 9, 9);
	glPopMatrix();

	
	glPopMatrix();
}

void Initialization(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void displayFunc(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawSolarSystem();
	glFlush();
	glutSwapBuffers();
}

void reshapeFunc(int x, int y)
{
	if (y == 0 || x == 0) return;

	glLoadIdentity();
	gluPerspective(80.0, (GLdouble)x / (GLdouble)y, 0.5, 80.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);
	displayFunc();
}

void idleFunc(void)
{
	day += dayRate;
	year1 += yearRate;
	year2 += yearRate;
	year3 += yearRate;
	year4 += yearRate;
	year5 += yearRate;
	year6 += yearRate;
	year7 += yearRate;
	year8 += yearRate;
	

	moonItsSelf += moonRotationItselfRate;
	moonAroundEarth += moonAroundEarthRate;
	displayFunc();
}