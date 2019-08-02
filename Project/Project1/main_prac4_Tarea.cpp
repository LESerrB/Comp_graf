//Semestre 2018 - 2 ******************************************//
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//**************	Serrano Bermúdez Luis Esteban		******//
//************** Versión:	 *********************************//
//**************	Visual Studio 2015 14.0.25431.01	******//
//************************************************************//
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;
int screenW = 0.0;
int screenH = 0.0;


void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
		//	glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0 + transX, 0.0 + transY, -5.0 + transZ);		//Transladar el objeto (para vista en ortho)
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);
	glTranslatef(0.0f, 0.0f, transZ);
		
		//CUERPO
		glPushMatrix();
			//(0,0,0)
			glScalef(5.0, 2.5, 2.5);
			glColor3f(1.0, 0.0, 0.0);
			glColor3f(0.824, 0.412, 0.118);
			prisma();
		glPopMatrix();

		//CABEZA
		glPushMatrix();
			//(3.5, 1.5, 0.0)
			glTranslatef(3.5, 1.5, 0.0);
			glScalef(2.0, 1.5, 1.5);
			glColor3f(0.502, 0.000, 0.000);
			prisma();
		glPopMatrix();
		
		//OREJA DERECHA
		glPushMatrix();
			//(-1.75, -2, 1.75)
			glTranslatef(3.0, 1.45, 0.85);
			glScalef(0.5, 0.7, 0.1);
			glColor3f(1.0, 1.0, 1.0);
			prisma();
		glPopMatrix();
		
		//OREJA IZQUIERDA
		glPushMatrix();
		//(-1.75, -2, 1.75)
			glTranslatef(3.0, 1.45, -0.85);
			glScalef(0.5, 0.7, 0.1);
			glColor3f(1.0, 1.0, 1.0);
			prisma();
		glPopMatrix();
		
		//HOCICO
		glPushMatrix();
			//
			glTranslatef(4.8, 1.0, 0.0);
			glScalef(0.6, 0.5, 1.0);
			glColor3f(1.000, 0.973, 0.863);
			prisma();
		glPopMatrix();
		
		//RABO
		glPushMatrix();
			//(-2.5, 1.3, 0.0)
			glTranslatef(-2.75, 1.0, 0.0);
			glScalef(0.5, 0.5, 0.5);
			glColor3f(1.0, 0.0, 0.0);
			prisma();
		glPopMatrix();

		//PATA TRAS DER
		glPushMatrix();
			//(-1.75, -2.0, 1.0)
			glTranslatef(-1.75, -2.0, 1.0);
			glScalef(0.5, 1.5, 0.5);
			glColor3f(0.957, 0.643, 0.376);
			prisma();
		glPopMatrix();

		//PATA DEL DER
		glPushMatrix();
			//(1.75, -2.0, 1.0)
			glTranslatef(1.75, -2.0, 1.0);
			glScalef(0.5, 1.5, 0.5);
			glColor3f(0.957, 0.643, 0.376);
			prisma();
		glPopMatrix();
		 
		//PATA TRAS IZQ
		glPushMatrix();
			//(-1.75, -2.0, -1.0)
			glTranslatef(-1.75, -2.0, -1.0);
			glScalef(0.5, 1.5, 0.5);
			glColor3f(0.957, 0.643, 0.376);
			prisma();
		glPopMatrix();

		//PATA DEL IZQ
		glPushMatrix();
			//(-1.75, -2.0, -1.0)
			glTranslatef(1.75, -2.0, -1.0);
			glScalef(0.5, 1.5, 0.5);
			glColor3f(0.957, 0.643, 0.376);
			prisma();
		glPopMatrix();

		//PIE TRAS DERECHO
		glPushMatrix();
			//(-1.45, -3.0, 1.0)
			glTranslatef(-1.45, -3.0, 1.0);
			glScalef(1.1, 0.5, 0.5);
			glColor3f(0.545, 0.271, 0.075);
			prisma();
		glPopMatrix();

		//PIE DEL DERECHO
		glPushMatrix();
			//(2.05, -3.0, 1.0)
			glTranslatef(2.05, -3.0, 1.0);
			glScalef(1.1, 0.5, 0.5);
			glColor3f(0.545, 0.271, 0.075);
			prisma();
		glPopMatrix();

		//PIE TRAS IZQUIERDO
		glPushMatrix();
			//(-1.45, -3.0, -1.0)
			glTranslatef(-1.45, -3.0, -1.0);
			glScalef(1.1, 0.5, 0.5);
			glColor3f(0.545, 0.271, 0.075);
			prisma();
		glPopMatrix();

		//PIE DEL IZQUIERDO
		glPushMatrix();
			//(2.05, -3.0, -1.0)
			glTranslatef(2.05, -3.0, -1.0);
			glScalef(1.1, 0.5, 0.5);
			glColor3f(0.545, 0.271, 0.075);
			prisma();
		glPopMatrix();

  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch (key) {
	case 't':
	case 'T':
		angleX += 10.0f;
		break;

	case 'g':
	case 'G':
		angleY += 10.0f;
		break;

	case 'f':
	case 'F':
		angleZ += 10.0f;
		break;

	case 'y':
	case 'Y':
		angleX -= 10.0f;
		break;

	case 'h':
	case 'H':
		angleY -= 10.0f;
		break;

	case 'j':
	case 'J':
		angleZ -= 10.0f;
		break;

	case 'q':
	case 'Q':
		transZ += 0.2f;
		break;

	case 'e':
	case 'E':
		transZ -= 0.2f;
		break;

	case 'w':
	case 'W':
		transY += 0.2f;
		break;

	case 's':
	case 'S':
		transY -= 0.2f;
		break;

	case 'a':
	case 'A':
		transX -= 0.2f;
		break;

	case 'd':
	case 'D':
		transX += 0.2f;
		break;

			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
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


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}