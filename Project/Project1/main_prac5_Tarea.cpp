//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Serrano Bermúdez Luis Esteban	**********//
//************** Visual Studio: ******************************//
//**************	Versión 2015 14.0.25431.01		**********//
//************************************************************//
#include "Main.h"
//*****************//
float transZ = -3.0f;
float transX = 0.0f;
float transY = 3.0f;
//*****************//
float angleX = 0.0f;
float angleY = 270.0f;
float angleZ = 0.0f;
//*********************//
float angleHombro = 0.0f;
float angleCodo = 0.0f;
float angleMano = 0.0f;
//**********************//
float anglePulgar1 = -45.0f;
float anglePulgar2 = 0.0f;
//**********************//
float angleIndice1 = 0.0f;
float angleIndice2 = 0.0f;
//*********************//
float angleMedio1 = 0.0f;
float angleMedio2 = 0.0f;
//**********************//
float angleAnular1 = 0.0f;
float angleAnular2 = 0.0f;
//***********************//
float angleMenique1 = 0.0f;
float angleMenique2 = 0.0f;
//**************//
int screenW = 0.0;
int screenH = 0.0;

GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };		// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };	// Light Position

void InitGL ( void )	// Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);				// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Negro de fondo
	glClearDepth(1.0f);						// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);				// Habilitamos Depth Testing

//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},	//Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},	//Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},	//Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},	//Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},	//Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},	//Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},	//Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},	//Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			//Limpiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0 + transX, 0.0 + transY, -5.0 + transZ);	//Transladar el objeto (para vista en ortho)
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);
	
	//Poner Código Aquí

//BRAZO DETALLADO
	glPushMatrix();
		glRotatef(angleHombro, 0.0, 0.0, 1.0);

		//HOMBRO
		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
		glPopMatrix();
		
		//BICEP
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			glScalef(0.5, 1.0, 1.0);
			prisma();
		glPopMatrix();
		
		//CODO
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angleCodo, 0.0,0.0,1.0);
		glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
		glPopMatrix();
		
		//ANTEBRAZO
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glScalef(0.5, 1.0, 1.0);
			prisma();
		glPopMatrix();
		
		//MANO
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angleMano, 0.0, 0.0, 1.0);
		glPushMatrix();
			glColor3f(0.0, 1.0, 1.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
		glPopMatrix();
		
		//PULGAR
		glPushMatrix();
			glTranslatef(0.25, 0.0, 0.0);
			glRotatef(anglePulgar1, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(0.3, 0.5, 0.0);
			//PARTE 1
				glPushMatrix();
					glScalef(0.2, 0.1, 1.0);
					prisma();
				glPopMatrix();
			glTranslatef(0.1, 0.0, 0.0);
			glRotatef(anglePulgar2, 0.0, 0.0, 1.0);
			glColor3f(0.3, 0.6, 1.0);
			//PARTE 2
			glPushMatrix();
				glScalef(0.2, 0.1, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//INDICE
		glPushMatrix();
			glTranslatef(0.1, -0.4, 0.0);
			glRotatef(angleIndice1, 1.0, 0.0, 0.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(0.3, 0.5, 0.0);
			//PARTE 1
			glPushMatrix();
				glScalef(0.1, 0.3, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.2, 0.0);
			glRotatef(angleIndice2, 1.0, 0.0, 0.0);
			glColor3f(0.3, 0.6, 1.0);
			//PARTE 2
			glPushMatrix();
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//MEDIO
		glPushMatrix();
			glTranslatef(-0.05, -0.4, 0.0);
			glRotatef(angleMedio1, 1.0, 0.0, 0.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(0.3, 0.5, 0.0);
			//PARTE 1
			glPushMatrix();
				glScalef(0.1, 0.3, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.2, 0.0);
			glRotatef(angleMedio2, 1.0, 0.0, 0.0);
			glColor3f(0.3, 0.6, 1.0);
			//PARTE 2
			glPushMatrix();
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//ANULAR
		glPushMatrix();
			glTranslatef(-0.2, -0.4, 0.0);
			glRotatef(angleAnular1, 1.0, 0.0, 0.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(0.3, 0.5, 0.0);
			//PARTE 1
			glPushMatrix();
				glScalef(0.1, 0.3, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.2, 0.0);
			glRotatef(angleAnular2, 1.0, 0.0, 0.0);
			glColor3f(0.3, 0.6, 1.0);
			//PARTE 2
			glPushMatrix();
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//MENIQUE
		glPushMatrix();
			glTranslatef(-0.35, -0.4, 0.0);
			glRotatef(angleMenique1, 1.0, 0.0, 0.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(0.3, 0.5, 0.0);
			//PARTE 1
			glPushMatrix();
				glScalef(0.1, 0.3, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.2, 0.0);
			glRotatef(angleMenique2, 1.0, 0.0, 0.0);
			glColor3f(0.3, 0.6, 1.0);
			//PARTE 2
			glPushMatrix();
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();
						
	glutSwapBuffers ( );
// Swap The Buffers
}

void reshape ( int width , int height )			// Creamos funcion Reshape
{
  if (height==0)								// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);				// Seleccionamos Projection Matrix
	glLoadIdentity();

// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);					// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
//MOVIMIENTO DE CAMARA
		//ROTAR EN X
		case 't':
		case 'T':
			angleX += 10.0f;
		break;
		case 'y':
		case 'Y':
			angleX -= 10.0f;
		break;
		//ROTAR EN Y
		case 'g':
		case 'G':
			angleY += 10.0f;
		break;
		case 'h':
		case 'H':
			angleY -= 10.0f;
		break;
		//ROTAR EN Z
		case 'f':
		case 'F':
			angleZ += 10.0f;
		break;
		case 'j':
		case 'J':
			angleZ -= 10.0f;
		break;
		//ZOOM
		case 'q':
		case 'Q':
			transZ += 0.2f;
		break;
		case 'e':
		case 'E':
			transZ -= 0.2f;
		break;
		//DESPLAZAMIENTO EN Y
		case 'w':
		case 'W':
			transY += 0.2f;
		break;
		case 's':
		case 'S':
			transY -= 0.2f;
		break;
		//DESPLAZAMIENTO EN X
		case 'a':
		case 'A':
			transX -= 0.2f;
		break;
		case 'd':
		case 'D':
			transX += 0.2f;
		break;
//MANIPULACION DE BRAZO
		//MOVIMIENTO HOMBRO
		case 'z':
		case 'Z':
			printf("Posición Hombro: %f\n", angleHombro);
			if(angleHombro < 180)
				angleHombro += 0.5f;
		break;
		case 'x':
		case 'X':
			printf("Posición Hombro: %f\n", angleHombro);
			if(angleHombro > -90)
				angleHombro -= 0.5f;
		break;
		//MOVIMIENTO CODO
		case 'u':
		case 'U':
			printf("Posición Codo: %f\n", angleCodo);
			if(angleCodo < 130)
				angleCodo += 0.5f;
		break;
		case 'i':
		case 'I':
			printf("Posición Codo: %f\n", angleCodo);
			if(angleCodo > 0)
				angleCodo -= 0.5f;
		break;
		//ROTACION MANO
		case 'o':
		case 'O':
			printf("Posición Muneca: %f\n", angleMano);
			if(angleMano < 25)
				angleMano += 0.5f;
		break;
		case 'p':
		case 'P':
			printf("Posición Muneca: %f\n", angleMano);
			if(angleMano > -25)
				angleMano -= 0.5f;
		break;
		//MOVIMIENTO PULGAR 1 <<<<<<<< DEDOS ************************************************
		case 'c':
		case 'C':
			printf("Posición Pulgar 1: %f\n", anglePulgar1);
			if(anglePulgar1 < -45)
				anglePulgar1 += 0.5f;
		break;
		case 'v':
		case 'V':
			printf("Posición Pulgar 1: %f\n", anglePulgar1);
			if(anglePulgar1 > -153)
				anglePulgar1 -= 0.5f;
		break;
		//MOVIMIENTO PULGAR 2
		case 'b':
		case 'B':
			printf("Posición Pulgar 2: %f\n", anglePulgar2);
			if(anglePulgar2 < 0)
				anglePulgar2 += 0.5f;
		break;
		case 'n':
		case 'N':
			printf("Posición Pulgar 2: %f\n", anglePulgar2);
			if (anglePulgar2 > -90)
				anglePulgar2 -= 0.5f;
		break;
		//MOVIMIENTO INDICE 1
		case 55:
			printf("Posición Indice 1: %f\n", angleIndice1);
			if(angleIndice1 < 90)
				angleIndice1 += 0.5f;
		break;
		case 56:
			printf("Posición Indice 1: %f\n", angleIndice1);
			if(angleIndice1 > 0)
				angleIndice1 -= 0.5f;
		break;
		//MOVIMIENTO INDICE 2
		case 52:
			printf("Posición Indice 2: %f\n", angleIndice2);
			if (angleIndice2 < 90)
				angleIndice2 += 0.5f;
		break;
		case 53:
			printf("Posición Indice 2: %f\n", angleIndice2);
			if (angleIndice2 > 0)
				angleIndice2 -= 0.5f;
		break;
		//MOVIMIENTO MEDIO 1
		case 49:
			printf("Posición Medio 1: %f\n", angleMedio1);
			if (angleMedio1 < 90)
					angleMedio1 += 0.5f;
		break;
		case 50:
			printf("Posición Medio 1: %f\n", angleMedio1);
			if (angleMedio1 > 0)
				angleMedio1 -= 0.5f;
		break;
		//MOVIMIENTO MEDIO 2
		case 48:
			printf("Posición Medio 2: %f\n", angleMedio2);
			if (angleMedio2 < 90)
				angleMedio2 += 0.5f;
		break;
		case 46:
			printf("Posición Medio 2: %f\n", angleMedio2);
			if (angleMedio2 > 0)
				angleMedio2 -= 0.5f;
		break;
		//MOVIMIENTO ANULAR 1
		case 47:
			printf("Posición Anular 1: %f\n", angleAnular1);
			if (angleAnular1 < 90)
				angleAnular1 += 0.5f;
		break;
		case 42:
			printf("Posición Anular 1: %f\n", angleAnular1);
			if (angleAnular1 > 0)
				angleAnular1 -= 0.5f;
		break;
		//MOVIMIENTO ANULAR 2
		case 45:
			printf("Posición Anular 2: %f\n", angleAnular2);
			if (angleAnular2 < 90)
				angleAnular2 += 0.5f;
		break;
		case 43:
			printf("Posición Anular 2: %f\n", angleAnular2);
			if (angleAnular2 > 0)
				angleAnular2 -= 0.5f;
		break;
		//MOVIMIENTO MENIQUE 1
		case 123:
			printf("Posición Menique 1: %f\n", angleMenique1);
			if (angleMenique1 < 90)
				angleMenique1 += 0.5f;
		break;
		case 125:
			printf("Posición Menique 1: %f\n", angleMenique1);
			if (angleMenique1 > 0)
				angleMenique1 -= 0.5f;
		break;
		//MOVIMIENTO MENIQUE 2
		case 'm':
		case 'M':
			printf("Posición Menique 2: %f\n", angleMenique2);
			if (angleMenique2 < 90)
				angleMenique2 += 0.5f;
		break;
		case 44:
			printf("Posición Menique 2: %f\n", angleMenique2);
			if (angleMenique2 > 0)
				angleMenique2 -= 0.5f;
		break;
		//SALIR
		case 27:		// Cuando Esc es presionado...
			exit(0);	// Salimos del programa
		break;
		//OTRO
		default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
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
