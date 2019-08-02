//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Serrano Bermúdez Luis Esteban	**********//
//************** Visual Studio: ******************************//
//**************	Versión 2015 14.0.25431.01		**********//
//************************************************************//
#include "Main.h"

// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna = 0;
int lunat = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;
int anillo = 0;

int translacion1 = 0;
int translacion2 = 0;
int translacion3 = 0;
int translacion4 = 0;
int translacion5 = 0;
int translacion6 = 0;
int translacion7 = 0;
int translacion8 = 0;

float camaraZ = 0.0;
float camaraX = 0.0;
float camaraY = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };					// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };				// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// TIERRA
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };				// LUNA
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };				// MARTE
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)												// Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);						// Negro de fondo

	glClearDepth(1.0f);											// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);									// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);										// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display(void)												// Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, camaraY, -15.0 + camaraZ);			// camara

	glRotatef(15.0, 1.0, 0.0, 0.0);
	
	glPushMatrix();
		
	// SOL
		glColor3f(1.0, 0.0, 0.2);
		
		glPushMatrix();											// CORONA SOLAR
			glRotatef(sol, 0.0, 1.0, 0.0);						// MOV DE ROTACION DEL SOL
			glutWireSphere(2.5, 30, 30);
		glPopMatrix();
		
		glPushMatrix();											// NUCLEO DEL SOL
			glColor3f(1.0, 1.0, 0.2);
			glutSolidSphere(2.4, 20, 20);
		glPopMatrix();

	// MERCURIO
		glRotatef(45.0, 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotated(translacion1, 0.0, 1.0, 0.0);				// MOV DE TRASLACION
			glTranslatef(3.5, 0.0, 0.0);						// TRASLADA HACIA LA DERECHA
			glColor3f(1.0, 0.647, 0.0);
			glRotated(mercurio, 0.0, 1.0, 0.0);					// MOV DE ROTACIÓN
			glutWireSphere(0.2, 20, 20);						// CUERPO PLANETARIO
		glPopMatrix();
	
	// VENUS
		glPushMatrix();
			glRotated(translacion2, 0.0, 1.0, 0.0);
			glTranslatef(4.5, 0.0, 0.0);
			glColor3f(1.0, 1.0, 0.0);
			glRotated(venus, 0.0, 1.0, 0.0);
			glutWireSphere(0.3, 20, 20);
		glPopMatrix();
		
	// TIERRA
		glPushMatrix();
			glRotated(translacion3, 0.0, 1.0, 0.0);	
			glTranslatef(5.8, 0.0, 0.0);
			
			glColor3f(0.0, 0.0, 1.0);
			
			glPushMatrix();
				glRotated(tierra, 0.0, 1.0, 0.0);
				glutWireSphere(0.4, 20, 20);
			glPopMatrix();
		
		// LUNA
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glRotated(luna, 0.0, 0.1, 0.0);
				glTranslatef(0.6, 0.0, 0.0);
				
				glPushMatrix();
					glRotated(lunat, 1.0, 1.0, 0.0);
					glutWireSphere(0.1, 20, 20);
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();
	
	// MARTE
		glPushMatrix();
			glRotated(translacion4, 0.0, 1.0, 0.0);
			glTranslatef(7.1, 0.0, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			glRotated(marte, 0.0, 1.0, 0.0);
			glutWireSphere(0.3, 20, 20);
		glPopMatrix();

	// JUPITER
		glPushMatrix();
			glRotated(translacion5, 0.0, 1.0, 0.0);
			glTranslatef(9.1, 0.0, 0.0);
			glColor3f(0.627, 0.322, 0.176);

			glPushMatrix();
				glRotated(tierra, 0.0, 1.0, 0.0);
				glutWireSphere(1.0, 20, 20);
			glPopMatrix();

		// LUNA 1 JUPITER
			glPushMatrix();
				glColor3f(0.6, 0.2, 0.0);
				glRotated(translacion5, 0.0, 0.1, 0.0);
				glTranslatef(1.3, 0.0, 0.0);
				
				glPushMatrix();
					glRotated(lunat, 1.0, 1.0, 0.0);
					glutWireSphere(0.1, 20, 20);
				glPopMatrix();

			glPopMatrix();

		// LUNA 2 JUPITER
			glPushMatrix();
				glColor3f(0.9, 0.6, 0.0);
				glRotated(translacion6, 0.0, 0.1, 0.0);
				glTranslatef(1.6, 0.2, 0.0);
			
					glPushMatrix();
						glRotated(lunat, 1.0, 1.0, 0.0);
						glutWireSphere(0.1, 20, 20);
					glPopMatrix();

			glPopMatrix();

		// LUNA 3 JUPITER
			glPushMatrix();
				glColor3f(0.0, 0.2, 0.6);
				glRotated(translacion7, 0.0, 0.1, 0.0);
				glTranslatef(0.0, -0.2, 1.9);
				
				glPushMatrix();
					glRotated(lunat, 1.0, 1.0, 0.0);
					glutWireSphere(0.1, 20, 20);
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();

	// SATURNO
		glRotatef(45.0, 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotated(translacion6, 0.0, 1.0, 0.0);
			glTranslatef(12.6, 0.0, 0.0);
			glColor3f(1.0, 0.871, 0.678);
			glRotated(saturno, 0.0, 1.0, 0.0);
			glutWireSphere(0.9, 20, 20);
		glPopMatrix();
	
		// ANILLO 1 SATURNO
		glPushMatrix();
			glRotated(translacion6, 0.0, 1.0, 0.0);
			glTranslatef(12.6, 0.0, 0.0);
			glColor3f(1.0, 1.0, 0.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(1.0, 1.0, 0.2);
			glRotated(anillo, 0.0, 0.0, -0.9);
			glutWireTorus(0.1, 1.25, 20, 40);
		glPopMatrix();

		// ANILLO 2 SATURNO
		glPushMatrix();
			glRotated(translacion6, 0.0, 1.0, 0.0);
			glTranslatef(12.6, 0.0, 0.0);
		
			glColor3f(0.7, 0.3, 0.5);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(1.0, 1.0, 0.2);
			glRotated(anillo, 0.0, 0.0, -1.0);
			glutWireTorus(0.2, 1.7, 20, 40);
		glPopMatrix();

	// URANO
		glPushMatrix();
			glRotated(translacion7, 0.0, 1.0, 0.0);
			glTranslatef(15.5, 0.0, 0.0);
			glColor3f(0.251, 0.878, 0.816);

			glPushMatrix();
				glRotated(tierra, 0.0, 1.0, 0.0);
				glutWireSphere(0.55, 20, 20);
			glPopMatrix();

		//LUNA 1 URANO
			glPushMatrix();
				glColor3f(0.3,0.3,0.3);
				glRotated(luna, 0.0, 0.1, 0.0);
				glTranslatef(0.6, 0.0, 0.0);
				
				glPushMatrix();
					glRotated(lunat, 1.0, 1.0, 0.0);
					glutWireSphere(0.1, 20, 20);
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();

	// NEPTUNO
		glPushMatrix();
			glRotated(translacion8, 0.0, 1.0, 0.0);
			glTranslatef(17.5, 0.0, 0.0);
			glColor3f(0.098, 0.098, 0.439);
			glRotated(neptuno, 0.0, 1.0, 0.0);
			glutWireSphere(0.5, 20, 20);
		glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount();								// Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 1) % 360;							
		dwLastUpdateTime = dwCurrentTime;
		
		mercurio = (mercurio - 2) % 360;
		dwLastUpdateTime = dwCurrentTime;

		venus = (venus - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;

		tierra = (tierra - 16) % 360;
		dwLastUpdateTime = dwCurrentTime;

		luna = (luna - 5) % 360;
		dwLastUpdateTime = dwCurrentTime;
		
		lunat = (lunat - 3) % 360;
		dwLastUpdateTime = dwCurrentTime;

		marte = (marte - 8) % 360;
		dwLastUpdateTime = dwCurrentTime;

		jupiter = (jupiter - 7) % 360;
		dwLastUpdateTime = dwCurrentTime;

		saturno = (saturno - 6) % 360;
		dwLastUpdateTime = dwCurrentTime;

		urano = (urano - 2) % 360;
		dwLastUpdateTime = dwCurrentTime;

		neptuno = (neptuno - 2) % 360;
		dwLastUpdateTime = dwCurrentTime;

		anillo = (anillo - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
	
		translacion1 = (translacion1 - 8) % 360;
		dwLastUpdateTime = dwCurrentTime;

		translacion2 = (translacion2 - 7) % 360;
		dwLastUpdateTime = dwCurrentTime;

		translacion3 = (translacion3 - 6) % 360;
		dwLastUpdateTime = dwCurrentTime;

		translacion4 = (translacion4 - 5) % 360;
		dwLastUpdateTime = dwCurrentTime;

		translacion5 = (translacion5 - 4) % 360;
		dwLastUpdateTime = dwCurrentTime;

		translacion6 = (translacion6 - 3) % 360;
		dwLastUpdateTime = dwCurrentTime;

		translacion7 = (translacion7 - 2) % 360;
		dwLastUpdateTime = dwCurrentTime;
		
		translacion8 = (translacion8 - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)								// Creamos funcion Reshape
{
	if (height == 0)											// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);								// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);									// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)					// Create Keyboard Function
{
	switch (key) {
	
	case 'w':													//Movimientos de camara
	case 'W':
		camaraZ += 0.2f;
	break;
	
	case 's':
	case 'S':
		camaraZ -= 0.2f;
	break;
	
	case 'a':
	case 'A':
		camaraX += 0.2f;
	break;
	
	case 'd':
	case 'D':
		camaraX -= 0.2f;
	break;


	case 'i':													//Movimientos de Luz
	case 'I':
	break;

	case 'k':
	case 'K':
	break;

	case 'l':													//Activamos/desactivamos luz
	case 'L':
	break;

	case 27:													// Cuando Esc es presionado...
		exit(0);												// Salimos del programa
	break;

	default:													// Cualquier otra
	break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)						// Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:											// Presionamos tecla ARRIBA...
		camaraY -= 0.1f;
	break;

	case GLUT_KEY_DOWN:											// Presionamos tecla ABAJO...
		camaraY += 0.1f;
	break;

	case GLUT_KEY_LEFT:
	break;

	case GLUT_KEY_RIGHT:
	break;

	default:
	break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)									// Main Function
{
	glutInit(&argc, argv);										// Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);	// Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);								// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);								//Posicion de la Ventana
	glutCreateWindow("Practica 6");								// Nombre de la Ventana
	InitGL();													// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);									//Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);									//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);									//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);								//Otras
	glutIdleFunc(animacion);
	glutMainLoop();

	return 0;
}