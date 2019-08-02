//Semestre 2012 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Serrano Bermúdez Luis Esteban		******//
//*************											******//
//************************************************************//
#include "texture.h"

float pos_camX = -3, pos_camY = -5, pos_camZ = -15; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };				// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position
// TEXTURAS
CTexture t_cemento01;
CTexture t_tabique01;
CTexture t_pasto01;
CTexture t_puerta01;
CTexture t_ventana01;

int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;

void InitGL ( GLvoid )										// Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);					// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);										// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);								// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);									// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// CARGA MAPA DE BITS
	t_cemento01.LoadBMP("cemento.bmp");
	t_cemento01.BuildGLTexture();
	t_cemento01.ReleaseImage();
	
	t_tabique01.LoadBMP("Tabique.bmp");
	t_tabique01.BuildGLTexture();
	t_tabique01.ReleaseImage();

	t_pasto01.LoadBMP("pasto.bmp");
	t_pasto01.BuildGLTexture();
	t_pasto01.ReleaseImage();

	t_puerta01.LoadTGA("puerta_transperencia.tga");
	t_puerta01.BuildGLTexture();
	t_puerta01.ReleaseImage();

	t_ventana01.LoadTGA("ventana_transparencia.tga");
	t_ventana01.BuildGLTexture();
	t_ventana01.ReleaseImage();
}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;													//Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);									//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++)							//Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c);							//imprime
  }
}

void prisma (GLuint textura1, GLuint textura2, GLuint textura3, GLuint textura4, GLuint textura5, GLuint textura6)				//Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{1.0, -0.25, 2.5},							//Coordenadas Vértice 0 V0
				{-1.0, -0.25, 2.5},							//Coordenadas Vértice 1 V1
				{-1.0, -0.25, -2.5},						//Coordenadas Vértice 2 V2
				{1.0, -0.25, -2.5},							//Coordenadas Vértice 3 V3
				{1.0, 0.25, 2.5},							//Coordenadas Vértice 4 V4
				{1.0, 0.25, -2.5},							//Coordenadas Vértice 5 V5
				{-1.0, 0.25, -2.5},							//Coordenadas Vértice 6 V6
				{-1.0, 0.25, 2.5},							//Coordenadas Vértice 7 V7
				};

		// Front
		glBindTexture(GL_TEXTURE_2D, textura1);				// choose the texture to use.
		glBegin(GL_POLYGON);
			glColor3f(1.0,1.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f, 4.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f, 4.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		// Right
		glBindTexture(GL_TEXTURE_2D, textura2);				// choose the texture to use.
		glBegin(GL_POLYGON);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f, 4.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 4.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
		glEnd();

		// Back
		glBindTexture(GL_TEXTURE_2D, textura3);				// choose the texture to use.
		glBegin(GL_POLYGON);
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(4.0f, 4.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 4.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		// Left
		glBindTexture(GL_TEXTURE_2D, textura4);				// choose the texture to use.
		glBegin(GL_POLYGON);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(4.0f, 4.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 4.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		// Bottom
		glBindTexture(GL_TEXTURE_2D, textura5);				// choose the texture to use.
		glBegin(GL_POLYGON);
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f, 4.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(0.0f, 4.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
		glEnd();

		// Top
		glBindTexture(GL_TEXTURE_2D, textura6);				// choose the texture to use.
		glBegin(GL_POLYGON);
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(4.0, 4.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0, 4.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}

void prisma2(GLuint textura1, GLuint textura2, GLuint textura3, GLuint textura4, GLuint textura5, GLuint textura6)				//Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 1.0, -0.25, 2.5 },							//Coordenadas Vértice 0 V0
		{ -1.0, -0.25, 2.5 },							//Coordenadas Vértice 1 V1
		{ -1.0, -0.25, -2.5 },						//Coordenadas Vértice 2 V2
		{ 1.0, -0.25, -2.5 },							//Coordenadas Vértice 3 V3
		{ 1.0, 0.25, 2.5 },							//Coordenadas Vértice 4 V4
		{ 1.0, 0.25, -2.5 },							//Coordenadas Vértice 5 V5
		{ -1.0, 0.25, -2.5 },							//Coordenadas Vértice 6 V6
		{ -1.0, 0.25, 2.5 },							//Coordenadas Vértice 7 V7
	};
	
	// Front
	glBindTexture(GL_TEXTURE_2D, textura1);				// choose the texture to use.
	glBegin(GL_POLYGON);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	// Right
	glBindTexture(GL_TEXTURE_2D, textura2);				// choose the texture to use.
	glBegin(GL_POLYGON);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	// Back
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, textura3);				// choose the texture to use.
		glBegin(GL_POLYGON);
			glColor3f(0.0, 0.0, 1.0);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();
	glPopMatrix();

	// Left
	glBindTexture(GL_TEXTURE_2D, textura4);				// choose the texture to use.
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	// Bottom
	glBindTexture(GL_TEXTURE_2D, textura5);				// choose the texture to use.
	glBegin(GL_POLYGON);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glEnd();

	// Top
	glBindTexture(GL_TEXTURE_2D, textura6);				// choose the texture to use.
	glBegin(GL_POLYGON);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void display ( void )										// Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();

	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);

// CASA
		// PARED TRASERA
		glPushMatrix();
			glRotatef(90.0, 0.0, 0.0, 1.0);
			glScalef(2.0, 16.5, 0.1);
			prisma(0, 0, t_tabique01.GLindex, 0, t_cemento01.GLindex, t_cemento01.GLindex);
		glPopMatrix();

		// PARED IZQUIERDA
		glPushMatrix();
			glTranslatef(-4.0, 0.0, 2.5);
			glScalef(0.1, 8.0, 1.0);
			prisma(t_cemento01.GLindex, 0, 0, t_tabique01.GLindex, 0, 0);
		glPopMatrix();

		// PARED DERECHA
		glPushMatrix();
			glTranslatef(4.0, 0.0, 2.5);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(0.1, 10.0, 0.8);
			prisma(0, t_tabique01.GLindex, 0, 0, 0, t_cemento01.GLindex);
		glPopMatrix();

		// PARED FRONTAL
		glPushMatrix();
			glTranslatef(0.0, 0.0, 5.0);
			glScalef(3.9, 8.0, 0.01);
			prisma(t_tabique01.GLindex, 0, 0, 0, 0, 0);
		glPopMatrix();

		// LOSA
		glPushMatrix();
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glTranslatef(0.0, 2.7, -2.25);
			glScalef(4.1, 12.0, 0.1);
			prisma(t_cemento01.GLindex, t_cemento01.GLindex, t_cemento01.GLindex, t_cemento01.GLindex, t_cemento01.GLindex, t_cemento01.GLindex);
		glPopMatrix();

		// PISO
		glPushMatrix();
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glTranslatef(0.0, 3.0, 2.0);
			glScalef(8.0, 15.0, 0.0);
			prisma(0, 0, t_pasto01.GLindex, 0, 0, 0);
		glPopMatrix();

		// VENTANAS
		glPushMatrix();
			glTranslatef(-2.0, 0.7, 5.08);
			glScalef(0.8, 3.5, 0.001);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			prisma2(t_ventana01.GLindex, 0, 0, 0, 0, 0);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(0.0, 0.7, 5.08);
			glScalef(0.8, 3.5, 0.001);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			prisma2(t_ventana01.GLindex, 0, 0, 0, 0, 0);
		glPopMatrix();
		
		// PUERTA
		glPushMatrix();
			glTranslatef(2.5, 0.0, 5.08);
			glScalef(0.5, 7.0, 0.001);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			prisma2(t_puerta01.GLindex, 0, 0, 0, 0, 0);
		glPopMatrix();
		
	glPopMatrix();


	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 9");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas con Transparencias");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void reshape ( int width , int height )						// Creamos funcion Reshape
{
  if (height==0)											// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);							// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);								// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )			// Create Keyboard Function
{
	switch ( key ) {
		case 'w':											//Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
			break;

		case 27:											// Cuando Esc es presionado...
			exit ( 0 );										// Salimos del programa
			break;        
		default:											// Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )				// Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:										// Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:										// Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )							// Main Function
{
  glutInit            (&argc, argv);						// Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);// Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (5000, 5000);							// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);							//Posicion de la Ventana
  glutCreateWindow    ("Practica 9");						// Nombre de la Ventana
  //glutFullScreen     ( );									// Full Screen
  InitGL ();												// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );							//Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );							//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );							//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );						//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );

  return 0;
}