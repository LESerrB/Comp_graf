//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Serrano Bermudes Luis Esteban			******//
//*************	Versión VS:								******//
//************* Visual Studio 2015 14.0.25431.01		******//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"
#include <stdio.h>

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;

float n1 = 1.0f;
float n2 = 0.0f;
float n3 = 0.0f;

float n4 = 0.0f;
float n5 = 1.0f;
float n6 = 0.0f;

float n7 = 0.0f;
float n8 = 0.0f;
float n9 = 1.0f;

float n10 = 0.0f;
float n11 = 1.0f;
float n12 = 1.0f;

float n13 = 1.0f;
float n14 = 1.0f;
float n15 = 0.0f;

float n16 = 1.0f;
float n17 = 0.0f;
float n18 = 1.0f;

float base = 1.0f;
float altura = 1.0f;
float ancho = 1.0f;


void InitGL ( GLvoid )     // Inicializamos parametros
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
				{base, -0.5, ancho},	//Coordenadas Vértice 0 V0
				{-0.5, -0.5, ancho},	//Coordenadas Vértice 1 V1
				{-0.5, -0.5, -0.5},	//Coordenadas Vértice 2 V2
				{base, -0.5, -0.5},	//Coordenadas Vértice 3 V3
				{base, altura, ancho},	//Coordenadas Vértice 4 V4
				{base, altura, -0.5},	//Coordenadas Vértice 5 V5
				{-0.5, altura, -0.5},	//Coordenadas Vértice 6 V6
				{-0.5, altura, ancho},	//Coordenadas Vértice 7 V7
};

		glBegin(GL_POLYGON);	//Front
			glColor3f(n1,n2,n3);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(n4, n5, n6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(n7, n8, n9);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(n10, n11, n12);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
	
		glColor3f(n13, n14, n15);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(n16, n17, n18);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner Código Aquí.
	glTranslatef(0.0 + transX, 0.0 + transY, -5.0 + transZ);		//Transladar el objeto (para vista en ortho)
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);

	//CUBO
	prisma();
	glTranslatef(0.0, 0.0, 0.0);
	
    glutSwapBuffers ( );
    //glFlush();
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
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 20.0);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	
	//system("cls");

	switch ( key ) {
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
			transZ +=0.2f;
			printf("Posicion en Z: %f\n", transZ);
		break;
		
		case 'e':
		case 'E':
			transZ -=0.2f;
			printf("Posicion en Z: %f\n", transZ);
		break;
		
		case 'w':
		case 'W':
			transY += 0.2f;
			printf("Posicion en Y: %f\n", transY);
		break;
		
		case 's':
		case 'S':
			transY -= 0.2f;
			printf("Posicion en Y: %f\n", transY);
		break;
		
		case 'a':
		case 'A':
			transX -=0.2f;
		break;
		
		case 'd':
		case 'D':
			transX +=0.2f;
		break;
		
		case 'm':
		case 'M':
			printf("Ingresa los valores del color (RGB) de la cara frontal separados por comas: ");
			scanf_s("%f,%f,%f", &n1, &n2, &n3);
			printf("Ingresa los valores del color (RGB) de la cara derecha separados por comas: ");
			scanf_s("%f,%f,%f", &n4, &n5, &n6);
			printf("Ingresa los valores del color (RGB) de la cara trasera separados por comas: ");
			scanf_s("%f,%f,%f", &n7, &n8, &n9);
			printf("Ingresa los valores del color (RGB) de la cara izquierda separados por comas: ");
			scanf_s("%f,%f,%f", &n10, &n11, &n12);
			printf("Ingresa los valores del color (RGB) de la base separados por comas: ");
			scanf_s("%f,%f,%f", &n13, &n14, &n15);
			printf("Ingresa los valores del color (RGB) de la cara superior separados por comas: ");
			scanf_s("%f,%f,%f", &n16, &n17, &n18);
		break;
		
		case 'n':
		case 'N':
			printf("Ingresa el tamanio de la Base: ");
			scanf_s("%f", &base);
			printf("Ingresa el tamanio de la Altura: ");
			scanf_s("%f", &altura);
			printf("Ingresa el tamanio del ancho: ");
			scanf_s("%f", &ancho);
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}