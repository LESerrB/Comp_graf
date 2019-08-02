//Semestre 2018 - 1 ******************************************//
//************************************************************//
//************************************************************//
//************** Alumno: Serrano Bermúdez Luis Esteban	   ***//
//************** Proyecto Final Computación Gráfica		   ***//
//************** Visual Studio: Versión 2015 14.0.25431.01 ***//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include <windows.h>
#include <mmsystem.h>
#include "cmodel/CModel.h"
//Solo para Visual Studio 2015
#if (_MSC_VER == 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

// VARIABLES PARA ANIMACIONES
float movDx = -6.1, movDy = 28.2, movDz = 18.0, rotD = 90;// MOVIMIENTO DEMONIO
float movMx = -16.3, movMy = 0.0, movMz = 25.2, rotM = 180;// MOVIMIENTO MONSTRUO
float balanceo = 0, extens = 11.4;						// MOVIMIENTO SIERRA
float caida2 = 0.0, caida3 = 0.0, caida4 = 0.0,			// MOVIMIENTO DE CABEZAS
	  desp2 = 0.0, desp3 = 0.0, desp4 = 0.0;;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float pX = 0;
float pY = 0;
float pZ = 0;
float rot = 0;
float tam = 1;
float tam2 = 1;
float tam3 = 1;

float rota = 0.0;
float rotb = 0.0;
float rotc = 0.0;
int arma = 0;

#define MAX_FRAMES 9
int i_max_steps = 90;
int i_curr_steps = 0;
typedef struct _frame
{
	// Variables para Key Frames
	float balanceo, extens;								// MOVIMIENTO SIERRA
	float incbalanceo, incextens;

	float caida2, caida3, caida4,				// MOVIMIENTO DE CABEZAS
		  desp2, desp3, desp4;
	float inccaida2, inccaida3, inccaida4,
		  incdesp2, incdesp3, incdesp4;
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 7;										// NUMERO DE CUADROS DE ANIMACION
bool play = false;
int playIndex = 0;
bool play2 = false;

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

CCamera objCamera;										// CAMARA

GLfloat g_lookupdown = -17.0f;							// Look Position In The Z-Axis

int font = (int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };			// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };			// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };		// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };		// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };			// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = { 22 };

// TEXTURAS
CTexture text1;
CTexture text2;
CTexture tree;
CTexture pared01;
CTexture pared02;
CTexture pared03;
CTexture ventana;
CTexture techo;
CTexture puerta;
CTexture puerta_1;
CTexture puerta02;
CTexture puerta02_1;
CTexture calabozo;
CTexture reja;
CTexture face01;
CTexture face02;
CTexture face03;
CTexture face04;
CTexture headbag;
CTexture piso;
CTexture saw;
CTexture cuadro01;
CTexture cuadro02;
CTexture fuego;
CTexture ojos;
CTexture cuerda;
CTexture madera;
CTexture madera_s;
CTexture madera_g;
CTexture madera_g_2;
CTexture cadena;
CTexture cuerpo;

// FIGURAS PRIMITIVAS
CFiguras fig1;	// Cielo
CFiguras fig2;	// Castillo
CFiguras fig3;	// Pasto
CFiguras fig4;	// Cuartos
CFiguras fig5;	// Fantasmas
CFiguras fig6;	// Cabezas
CFiguras fig7;	// Mesa
CFiguras fig8;	// Cuerpos

// MODELOS
CModel monster;
CModel trex;
CModel shotgun01;
CModel shotgun02;
CModel shotgun03;

// ANIMACION
bool m_animacion = false;
bool m_avanza = true;
bool m_salto = false;
bool m_caida = false;
bool m_giro = false;
bool m_regreso = false;
bool m_giro2 = false;

bool recorrido = false;
bool recorrido1 = true;
bool recorrido2 = false;
bool recorrido3 = false;
bool recorrido4 = false;
bool recorrido5 = false;
bool recorrido6 = false;
bool recorrido7 = false;
bool recorrido8 = false;
bool recorrido9 = false;
bool recorrido10 = false;
bool recorrido11 = false;
bool recorrido12 = false;
bool recorrido13 = false;

bool cambio = false;
bool arma1 = true;
bool arma2 = false;
bool arma3 = false;

void resetElements(void)
{
	balanceo = KeyFrame[0].balanceo;
	extens = KeyFrame[0].extens;

	caida2 = KeyFrame[0].caida2;
	desp2 = KeyFrame[0].desp2;
	caida3 = KeyFrame[0].caida3;
	desp3 = KeyFrame[0].desp3;
	caida4 = KeyFrame[0].caida4;
	desp4 = KeyFrame[0].desp4;
}

void interpolation(void)
{
	KeyFrame[playIndex].incbalanceo = (KeyFrame[playIndex + 1].balanceo - KeyFrame[playIndex].balanceo) / i_max_steps;
	KeyFrame[playIndex].incextens = (KeyFrame[playIndex + 1].extens - KeyFrame[playIndex].extens) / i_max_steps;

	KeyFrame[playIndex].inccaida2 = (KeyFrame[playIndex + 1].caida2 - KeyFrame[playIndex].caida2) / i_max_steps;
	KeyFrame[playIndex].inccaida3 = (KeyFrame[playIndex + 1].caida3 - KeyFrame[playIndex].caida3) / i_max_steps;
	KeyFrame[playIndex].inccaida4 = (KeyFrame[playIndex + 1].caida4 - KeyFrame[playIndex].caida4) / i_max_steps;
	KeyFrame[playIndex].incdesp2 = (KeyFrame[playIndex + 1].desp2 - KeyFrame[playIndex].desp2) / i_max_steps;
	KeyFrame[playIndex].incdesp3 = (KeyFrame[playIndex + 1].desp3 - KeyFrame[playIndex].desp3) / i_max_steps;
	KeyFrame[playIndex].incdesp4 = (KeyFrame[playIndex + 1].desp4 - KeyFrame[playIndex].desp4) / i_max_steps;
}

void pasto()
{
	glPushMatrix();
		glScalef(130, 0.1, 130);
		glDisable(GL_LIGHTING);
		fig3.prisma2(text2.GLindex, 0);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}

void arbol_alpha()
{
	glPushMatrix();
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		glBindTexture(GL_TEXTURE_2D, tree.GLindex);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(45, 0, 1, 0);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(-45, 0, 1, 0);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}

// LUZ, TEXTURAS, KEYFRAMES DE ANIMACION
void InitGL(GLvoid)									    // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);
///////////////////////////////////////////////////// LUZ //////////////////////////////////////////////////
	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
////////////////////////////////////////////////// TEXTURAS ////////////////////////////////////////////////
	text1.LoadBMP("Texturas/02.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadTGA("Texturas/pasto01.tga");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	tree.LoadTGA("Texturas/Terror_tree.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	pared01.LoadTGA("Texturas/Pared01.tga");
	pared01.BuildGLTexture();
	pared01.ReleaseImage();

	ventana.LoadTGA("Texturas/Ventana.tga");
	ventana.BuildGLTexture();
	ventana.ReleaseImage();

	pared02.LoadTGA("Texturas/Pared02.tga");
	pared02.BuildGLTexture();
	pared02.ReleaseImage();

	pared03.LoadTGA("Texturas/Pared03.tga");
	pared03.BuildGLTexture();
	pared03.ReleaseImage();

	techo.LoadTGA("Texturas/Techo.tga");
	techo.BuildGLTexture();
	techo.ReleaseImage();

	puerta.LoadTGA("Texturas/Puerta.tga");
	puerta.BuildGLTexture();
	puerta.ReleaseImage();

	puerta_1.LoadTGA("Texturas/Puerta-1.tga");
	puerta_1.BuildGLTexture();
	puerta_1.ReleaseImage();
	
	puerta02.LoadTGA("Texturas/Puerta02.tga");
	puerta02.BuildGLTexture();
	puerta02.ReleaseImage();

	puerta02_1.LoadTGA("Texturas/Puerta02-1.tga");
	puerta02_1.BuildGLTexture();
	puerta02_1.ReleaseImage();

	calabozo.LoadTGA("Texturas/Calabozo.tga");
	calabozo.BuildGLTexture();
	calabozo.ReleaseImage();

	reja.LoadTGA("Texturas/Reja.tga");
	reja.BuildGLTexture();
	reja.ReleaseImage();

	face01.LoadTGA("Texturas/Zombie_face01.tga");
	face01.BuildGLTexture();
	face01.ReleaseImage();
	
	face02.LoadTGA("Texturas/Zombie_face02.tga");
	face02.BuildGLTexture();
	face02.ReleaseImage();
	
	face03.LoadTGA("Texturas/Zombie_face03.tga");
	face03.BuildGLTexture();
	face03.ReleaseImage();
	
	face04.LoadTGA("Texturas/Zombie_face04.tga");
	face04.BuildGLTexture();
	face04.ReleaseImage();
	
	headbag.LoadTGA("Texturas/Headbag.tga");
	headbag.BuildGLTexture();
	headbag.ReleaseImage();

	piso.LoadTGA("Texturas/Piso_01.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();
	
	saw.LoadTGA("Texturas/Saw.tga");
	saw.BuildGLTexture();
	saw.ReleaseImage();
	
	cuadro01.LoadTGA("Texturas/Cuadro_Terror01.tga");
	cuadro01.BuildGLTexture();
	cuadro01.ReleaseImage();
	
	cuadro02.LoadTGA("Texturas/Cuadro_Terror02.tga");
	cuadro02.BuildGLTexture();
	cuadro02.ReleaseImage();
	
	fuego.LoadTGA("Texturas/Fuego01.tga");
	fuego.BuildGLTexture();
	fuego.ReleaseImage();
	
	cadena.LoadTGA("Texturas/Cadena.tga");
	cadena.BuildGLTexture();
	cadena.ReleaseImage();

	cuerpo.LoadTGA("Texturas/Corpse.tga");
	cuerpo.BuildGLTexture();
	cuerpo.ReleaseImage();

	cuerda.LoadTGA("Texturas/Rope.tga");
	cuerda.BuildGLTexture();
	cuerda.ReleaseImage();
	
	madera.LoadTGA("Texturas/Madera_rustica.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	madera_s.LoadTGA("Texturas/Madera_rustica_1.tga");
	madera_s.BuildGLTexture();
	madera_s.ReleaseImage();

	madera_g.LoadTGA("Texturas/Madera_gillotina.tga");
	madera_g.BuildGLTexture();
	madera_g.ReleaseImage();

	madera_g_2.LoadTGA("Texturas/Madera_gillotina_2.tga");
	madera_g_2.BuildGLTexture();
	madera_g_2.ReleaseImage();
///////////////////////////////////////////////// MODELOS ////////////////////////////////////////////////
	monster._3dsLoad("Modelos/ifrit/ifrit.3ds");		// DEMONIO
	monster.LoadTextureImages();
	monster.GLIniTextures();
	monster.ReleaseTextureImages();

	trex._3dsLoad("Modelos/monster/monster_character.3ds");// MONSTRUO
	trex.LoadTextureImages();
	trex.GLIniTextures();
	trex.ReleaseTextureImages();

	shotgun01._3dsLoad("Modelos/shotguns3ds/shotgun3ds.3ds");

	shotgun02._3dsLoad("Modelos/shotguns3ds/shotgun13ds.3ds");

	shotgun03._3dsLoad("Modelos/shotguns3ds/shotgun23ds.3ds");
////////////////////////////////////////////////// CAMARA ////////////////////////////////////////////////
	objCamera.Position_Camera(0, 10.0f, 65, 0, 10.0f, 62, 0, 1, 0);// POSICION DE LA CAMARA
////////////////////////////////////////// KEYFRAMES PARA ANIMACION //////////////////////////////////////
	KeyFrame[0].balanceo = 5;							// SIERRA
	KeyFrame[0].extens = 11.4;

	KeyFrame[1].balanceo = 20;
	KeyFrame[1].extens = 11.55;

	KeyFrame[2].balanceo = -20;
	KeyFrame[2].extens = 11.7;

	KeyFrame[3].balanceo = 20;
	KeyFrame[3].extens = 11.85;

	KeyFrame[4].balanceo = -20;
	KeyFrame[4].extens = 12.0;

	KeyFrame[5].balanceo = 20;
	KeyFrame[5].extens = 12.3;

	KeyFrame[6].balanceo = 3;
	KeyFrame[6].extens = 12.5;

	KeyFrame[0].caida2 = -26;								// CABEZA 2
	KeyFrame[0].desp2 = -3.0;

	KeyFrame[1].caida2 = -13;
	KeyFrame[1].desp2 = -6.0;

	KeyFrame[2].caida2 = -26;
	KeyFrame[2].desp2 = -9.0;

	KeyFrame[3].caida2 = -6;
	KeyFrame[3].desp2 = -12.0;

	KeyFrame[4].caida2 = -26;
	KeyFrame[4].desp2 = -15.0;

	KeyFrame[5].caida2 = -20;
	KeyFrame[5].desp2 = -18.0;

	KeyFrame[6].caida2 = -26;
	KeyFrame[6].desp2 = -21.0;

	KeyFrame[0].caida3 = -26;								// CABEZA 3
	KeyFrame[0].desp3 = -4.0;

	KeyFrame[1].caida3 = -10;
	KeyFrame[1].desp3 = -7.0;

	KeyFrame[2].caida3 = -26;
	KeyFrame[2].desp3 = -10.0;

	KeyFrame[3].caida3 = -17;
	KeyFrame[3].desp3 = -13.0;

	KeyFrame[4].caida3 = -26;
	KeyFrame[4].desp3 = -16.0;

	KeyFrame[5].caida3 = -22;
	KeyFrame[5].desp3 = -19.0;

	KeyFrame[6].caida3 = -26;
	KeyFrame[6].desp3 = -22.0;

	KeyFrame[0].caida4 = -26;								// CABEZA 4
	KeyFrame[0].desp4 = -5.0;

	KeyFrame[1].caida4 = -12;
	KeyFrame[1].desp4 = -8.0;

	KeyFrame[2].caida4 = -26;
	KeyFrame[2].desp4 = -11.0;

	KeyFrame[3].caida4 = -15;
	KeyFrame[3].desp4 = -14.0;

	KeyFrame[4].caida4 = -26;
	KeyFrame[4].desp4 = -17.0;

	KeyFrame[5].caida4 = -20;
	KeyFrame[5].desp4 = -20.0;

	KeyFrame[6].caida4 = -26;
	KeyFrame[6].desp4 = -23.0;
}

//PONE UNA TEXTURA EN TODA LA EXTENSIÓN DEL PRISMA
void prisma(GLuint textura1, GLuint textura2, GLuint textura3, GLuint textura4, GLuint textura5, GLuint textura6)				//Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 1.0, -0.25, 2.5 },							//Coordenadas Vértice 0 V0
		{ -1.0, -0.25, 2.5 },							//Coordenadas Vértice 1 V1
		{ -1.0, -0.25, -2.5 },							//Coordenadas Vértice 2 V2
		{ 1.0, -0.25, -2.5 },							//Coordenadas Vértice 3 V3
		{ 1.0, 0.25, 2.5 },								//Coordenadas Vértice 4 V4
		{ 1.0, 0.25, -2.5 },							//Coordenadas Vértice 5 V5
		{ -1.0, 0.25, -2.5 },							//Coordenadas Vértice 6 V6
		{ -1.0, 0.25, 2.5 },							//Coordenadas Vértice 7 V7
	};

// Front
	glBindTexture(GL_TEXTURE_2D, textura1);				// choose the texture to use.

	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
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
	glBindTexture(GL_TEXTURE_2D, textura3);				// choose the texture to use.

	glBegin(GL_POLYGON);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

// Left
	glBindTexture(GL_TEXTURE_2D, textura4);				// choose the texture to use.

	glBegin(GL_POLYGON);
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

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;											// Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);								// Posicion apartir del centro de la ventana
	for (c = string; *c != '\0'; c++)					// Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c);					// Imprime
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	glPushMatrix();
		glRotatef(g_lookupdown, 1.0f, 0, 0);

		gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
			objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
			objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
//////////////////////////////////////////////// ESCENARIO ////////////////////////////////////////////////
		glPushMatrix();									// BOSQUE
			glPushMatrix();
				glDisable(GL_LIGHTING);
				glTranslatef(0, 65, 0);
				fig1.skybox(130.0, 130.0, 130.0, text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
				glEnable(GL_COLOR_MATERIAL);
				glColor3f(1, 1, 1);
				pasto();
				glDisable(GL_COLOR_MATERIAL);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-35, 0, 10.5);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(18.2, 0, 40.0);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-18.0, 0, 40.0);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(34.7, 0, 19.4);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(44.8, 0, 12.4);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(54.2, 0, 18.1);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(55.7, 0, -3.2);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(35.1, 0, -3.2);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(35.1, 0, -14.4);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(45.6, 0, -22.9);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-32.0, 0, -22.9);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-53.9, 0, -22.9);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-45.0, 0, -14.9);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-51.2, 0, -5.2);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-55.6, 0, 2.7);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-37.5, 0, -4.3);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-42.2, 0, 28.1);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-51.8, 0, 39.6);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-55.0, 0, 45.4);
				arbol_alpha();
			glPopMatrix();

			glColor3f(1.0, 1.0, 1.0);
		glPopMatrix();
///////////////////////////////////////////////// CASTILLO ////////////////////////////////////////////////
		glPushMatrix(); 
			glTranslatef(0.0, 30.0, 0.0);
			fig2.prisma(60.0, 50.0, 70.0, pared01.GLindex);
			
			glPushMatrix();								// PUERTA
				glTranslatef(0.0, -15.7, 35.0);
				glScalef(7.0, 55.4, 0.05);
				prisma(puerta.GLindex, 0, puerta_1.GLindex, 0, 0, 0);
			glPopMatrix();

			glPushMatrix();								// VENTANAS
				glTranslatef(15.0, 18.0, 35.0);
				glScalef(4.5, 24.0, 0.03);
				prisma(ventana.GLindex, 0, ventana.GLindex, 0, 0, 0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-15.0, 18.0, 35.0);
				glScalef(4.5, 24.0, 0.03);
				prisma(ventana.GLindex, 0, ventana.GLindex, 0, 0, 0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(15.0, -10.0, 35.0);
				glScalef(4.5, 24.0, 0.01);
				prisma(ventana.GLindex, 0, ventana.GLindex, 0, 0, 0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-15.0, -10.0, 35.0);
				glScalef(4.5, 24.0, 0.01);
				prisma(ventana.GLindex, 0, ventana.GLindex, 0, 0, 0);
			glPopMatrix();

		glPopMatrix();
////////////////////////////////////////////////// TORRES /////////////////////////////////////////////////
		glPushMatrix();
			glTranslatef(30.0, 0.0, 35.0);
			fig2.cilindro(5.0, 70.0, 100.0, pared01.GLindex);
			
			glPushMatrix();								// TECHO
				glTranslatef(0.0, 70.0, 0.0);
				fig2.cono(10.0, 5.0, 100.0, techo.GLindex);
			glPopMatrix();

			glTranslatef(-60.0, 0.0, 0.0);
			fig2.cilindro(5.0, 70.0, 100.0, pared01.GLindex);
			
			glPushMatrix();
				glTranslatef(0.0, 70.0, 0.0);
				fig2.cono(10.0, 5.0, 100.0, techo.GLindex);
			glPopMatrix();

		glPopMatrix();
//////////////////////////////////////////////// DIVISIONES ///////////////////////////////////////////////
		glPushMatrix();
			glTranslatef(0.0, 14.6, 0.0);
			fig4.prisma(28.9, 15.0, 69.9, pared02.GLindex);
			
			glPushMatrix();
				glTranslatef(0.0, 29.9, -17.5);
				fig4.prisma(30.8, 49.9, 34.9, pared02.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0, 29.9, 17.5);
				fig4.prisma(30.8, 49.9, 34.9, pared02.GLindex);
			glPopMatrix();

			glPushMatrix();								// PISO
				glTranslatef(-16.0, -14.5, 0.0);
				glScalef(9.0, 0.1, 13.99);
				prisma(0, 0, 0, 0, 0, piso.GLindex);
			glPopMatrix();
////////////////////////////////////////////// PUERTA INTERNA /////////////////////////////////////////////
			glPushMatrix();								
				glTranslatef(7.5, -7.0, 26.0);
				glScalef(0.05, 30.0, 2.0);
				glEnable(GL_BLEND);						// TRANSPARENCIA
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				prisma(0, puerta02_1.GLindex, 0, puerta02.GLindex, 0, 0);
				glDisable(GL_BLEND);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-7.5, -7.0, -26.0);
				glScalef(0.05, 30.0, 2.0);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				prisma(0, puerta02_1.GLindex, 0, puerta02.GLindex, 0, 0);
				glDisable(GL_BLEND);
			glPopMatrix();
///////////////////////////////////////////////// MORGUE /////////////////////////////////////////////////
			glPushMatrix();
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glTranslatef(-18.2, -9.0, 24.8);
				fig8.cilindro(3.0, 19.2, 10.0, cuerpo.GLindex);

				glPushMatrix();
					glTranslatef(0, 18.2, 0);
					fig8.cilindro(0.2, 5.3, 10.0, cadena.GLindex);
				glPopMatrix();

				glDisable(GL_BLEND);
			glPopMatrix();

			glPushMatrix();
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glTranslatef(-12.1, -9.0, 8.9);
				fig8.cilindro(3.0, 19.2, 10.0, cuerpo.GLindex);
				
				glPushMatrix();
					glTranslatef(0, 18.2, 0);
					fig8.cilindro(0.2, 5.3, 10.0, cadena.GLindex);
				glPopMatrix();

				glDisable(GL_BLEND);
			glPopMatrix();

			glPushMatrix();
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glTranslatef(-20.0, -9.0, -2.3);
				fig8.cilindro(3.0, 19.2, 10.0, cuerpo.GLindex);

				glPushMatrix();
					glTranslatef(0, 18.2, 0);
					fig8.cilindro(0.2, 5.3, 10.0, cadena.GLindex);
				glPopMatrix();

				glDisable(GL_BLEND);
			glPopMatrix();

			glPushMatrix();
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glTranslatef(-12.0, -9.0, -15.3);
				fig8.cilindro(3.0, 19.2, 10.0, cuerpo.GLindex);

				glPushMatrix();
					glTranslatef(0, 18.2, 0);
					fig8.cilindro(0.2, 5.3, 10.0, cadena.GLindex);
				glPopMatrix();

				glDisable(GL_BLEND);
			glPopMatrix();
//////////////////////////////////////////////// ESCALERA ////////////////////////////////////////////////
			glPushMatrix();
				glTranslatef(16.2, -13.5, 17.59);
				glScalef(8.65, 5.0, 1.0);
				prisma(piso.GLindex, 0, 0, 0, 0, piso.GLindex);

				glPushMatrix();
					glTranslatef(0.0, 0.5, -5.0);
					prisma(piso.GLindex, 0, 0, 0, 0, piso.GLindex);

					glPushMatrix();						// CUADRO
						glTranslatef(1.02, 3.0, 5.0);
						glScalef(0.01, 5.0, 2.5);
						glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						prisma(0, pared01.GLindex, 0, cuadro02.GLindex, 0, 0);
						glDisable(GL_BLEND);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.0, 0.5, -5.0);
						prisma(piso.GLindex, 0, 0, 0, 0, piso.GLindex);

						glPushMatrix();
							glTranslatef(0.0, 0.5, -5.0);
							prisma(piso.GLindex, 0, 0, 0, 0, piso.GLindex);

							glPushMatrix();
								glTranslatef(0.0, 0.5, -5.0);
								prisma(piso.GLindex, 0, 0, 0, 0, piso.GLindex);

								glPushMatrix();
									glTranslatef(0.0, 0.5, -5.0);
									prisma(piso.GLindex, 0, 0, 0, 0, piso.GLindex);

									glPushMatrix();
										glTranslatef(0.0, 0.5, -5.0);
										prisma(piso.GLindex, 0, 0, 0, 0, piso.GLindex);

										glPushMatrix();
											glTranslatef(0.0, 0.5, -5.0);
											prisma(piso.GLindex, 0, 0, 0, 0, piso.GLindex);

											glPushMatrix();
												glTranslatef(0.0, 0.5, -5.0);
												prisma(piso.GLindex, 0, 0, 0, 0, piso.GLindex);

												glPushMatrix();
													glTranslatef(0.0, 0.5, -5.0);
													prisma(piso.GLindex, 0, 0, 0, 0, piso.GLindex);

													glPushMatrix();
														glTranslatef(0.0, 0.5, -5.0);
														prisma(piso.GLindex, 0, 0, 0, 0, piso.GLindex);
													glPopMatrix();

												glPopMatrix();

											glPopMatrix();

										glPopMatrix();

									glPopMatrix();

								glPopMatrix();

							glPopMatrix();

						glPopMatrix();

					glPopMatrix();

				glPopMatrix();

			glPopMatrix();
//////////////////////////////////////////////// CABEZAS /////////////////////////////////////////////////
			glPushMatrix();								// CABEZA 1
				glTranslatef(-20.7, 41.8, -6.0);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				fig6.esfera(1.0, 100.0, 100.0, face01.GLindex);

				glPushMatrix();							// CABEZA 2
					glTranslatef(-1.5, caida2, desp2);
					fig6.esfera(1.0, 100.0, 100.0, face02.GLindex);
				glPopMatrix();

				glPushMatrix();							// CABEZA 3
					glTranslatef(pX, caida3, desp3);
					fig6.esfera(1.0, 100.0, 100.0, face03.GLindex);
				glPopMatrix();

				glPushMatrix();							// CABEZA 4
					glTranslatef(0.0, caida4, desp4);
					fig6.esfera(1.0, 100.0, 100.0, face04.GLindex);
				glPopMatrix();

				glPushMatrix();							// BOLSA DE CABEZAS
					fig6.esfera(3.3, 100.0, 100.0, headbag.GLindex);
				glPopMatrix();

				glDisable(GL_BLEND);
			glPopMatrix();
//////////////////////////////////////////////// PASILLO /////////////////////////////////////////////////
			/*glPushMatrix();								// VELAS DE MUROS << SOLO DESACTIVAR CUANDO SEA LA PRUEBA FINAL
				glTranslatef(6.5, -0.5, 16.0);
				fig6.cilindro(0.1, 1.5, 100.0, NULL);
				
				glPushMatrix();
					glTranslatef(0.0, 1.6, 0.0);
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					fig6.esfera(0.06, 100.0, 100.0, fuego.GLindex);
					
					glPushMatrix();
						fig6.cono(0.4, 0.06, 100.0, fuego.GLindex);
					glPopMatrix();

					glDisable(GL_BLEND);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.0, 0.0, -10.0);
					fig6.cilindro(0.1, 1.5, 100.0, NULL);

					glPushMatrix();
						glTranslatef(0.0, 1.6, 0.0);
						glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						fig6.esfera(0.06, 100.0, 100.0, fuego.GLindex);

						glPushMatrix();
							fig6.cono(0.4, 0.06, 100.0, fuego.GLindex);
						glPopMatrix();

						glDisable(GL_BLEND);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.0, 0.0, -10.0);
						fig6.cilindro(0.1, 1.5, 100.0, NULL);

						glPushMatrix();
							glTranslatef(0.0, 1.6, 0.0);
							glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							fig6.esfera(0.06, 100.0, 100.0, fuego.GLindex);

							glPushMatrix();
								fig6.cono(0.4, 0.06, 100.0, fuego.GLindex);
							glPopMatrix();

							glDisable(GL_BLEND);
						glPopMatrix();

						glPushMatrix();
							glTranslatef(0.0, 0.0, -10.0);
							fig6.cilindro(0.1, 1.5, 100.0, NULL);

							glPushMatrix();
								glTranslatef(0.0, 1.6, 0.0);
								glEnable(GL_BLEND);
								glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
								fig6.esfera(0.06, 100.0, 100.0, fuego.GLindex);

								glPushMatrix();
									fig6.cono(0.4, 0.06, 100.0, fuego.GLindex);
								glPopMatrix();

								glDisable(GL_BLEND);
							glPopMatrix();

							glPushMatrix();
								glTranslatef(0.0, 0.0, -10.0);
								fig6.cilindro(0.1, 1.5, 100.0, NULL);

								glPushMatrix();
									glTranslatef(0.0, 1.6, 0.0);
									glEnable(GL_BLEND);
									glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
									fig6.esfera(0.06, 100.0, 100.0, fuego.GLindex);

									glPushMatrix();
										fig6.cono(0.4, 0.06, 100.0, fuego.GLindex);
									glPopMatrix();

									glDisable(GL_BLEND);
								glPopMatrix();

							glPopMatrix();

						glPopMatrix();

					glPopMatrix();

				glPopMatrix();

			glPopMatrix();

			glPushMatrix();
				glTranslatef(-6.5, -0.5, 25.0);
				fig6.cilindro(0.1, 1.5, 100.0, NULL);

				glPushMatrix();
					glTranslatef(0.0, 1.6, 0.0);
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					fig6.esfera(0.06, 100.0, 100.0, fuego.GLindex);

					glPushMatrix();
						fig6.cono(0.4, 0.06, 100.0, fuego.GLindex);
					glPopMatrix();

					glDisable(GL_BLEND);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.0, 0.0, -10.0);
					fig6.cilindro(0.1, 1.5, 100.0, NULL);

					glPushMatrix();
						glTranslatef(0.0, 1.6, 0.0);
						glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						fig6.esfera(0.06, 100.0, 100.0, fuego.GLindex);

						glPushMatrix();
							fig6.cono(0.4, 0.06, 100.0, fuego.GLindex);
						glPopMatrix();

						glDisable(GL_BLEND);
				glPopMatrix();

					glPushMatrix();
						glTranslatef(0.0, 0.0, -10.0);
						fig6.cilindro(0.1, 1.5, 100.0, NULL);

						glPushMatrix();
							glTranslatef(0.0, 1.6, 0.0);
							glEnable(GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							fig6.esfera(0.06, 100.0, 100.0, fuego.GLindex);

							glPushMatrix();
								fig6.cono(0.4, 0.06, 100.0, fuego.GLindex);
							glPopMatrix();

							glDisable(GL_BLEND);
						glPopMatrix();

							glPushMatrix();
								glTranslatef(0.0, 0.0, -10.0);
								fig6.cilindro(0.1, 1.5, 100.0, NULL);

								glPushMatrix();
								glTranslatef(0.0, 1.6, 0.0);
								glEnable(GL_BLEND);
								glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
								fig6.esfera(0.06, 100.0, 100.0, fuego.GLindex);

								glPushMatrix();
									fig6.cono(0.4, 0.06, 100.0, fuego.GLindex);
								glPopMatrix();

								glDisable(GL_BLEND);
							glPopMatrix();

							glPushMatrix();
								glTranslatef(0.0, 0.0, -10.0);
								fig6.cilindro(0.1, 1.5, 100.0, NULL);

								glPushMatrix();
									glTranslatef(0.0, 1.6, 0.0);
									glEnable(GL_BLEND);
									glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
									fig6.esfera(0.06, 100.0, 100.0, fuego.GLindex);

									glPushMatrix();
										fig6.cono(0.4, 0.06, 100.0, fuego.GLindex);
									glPopMatrix();

									glDisable(GL_BLEND);
								glPopMatrix();

							glPopMatrix();

						glPopMatrix();

					glPopMatrix();

				glPopMatrix();

			glPopMatrix();*/

			glPushMatrix();								// CUADRO
				glTranslatef(0.0, 3.0, -34.9);
				glScalef(6.5, 20.5, 0.01);
				prisma(cuadro01.GLindex, 0, 0, 0, 0, 0);
			glPopMatrix();
///////////////////////////////////////////// SALA DE TORTURA ////////////////////////////////////////////
			glPushMatrix();
				glTranslatef(-15.0, 18.5, -18.5);		// MESA
				glScalef(2.0, 2.0, 2.0);
				fig7.prisma(0.5, 2.0, 4.0, madera_s.GLindex);
				
				glPushMatrix();
					glTranslatef(0.5, -1.0, 1.5);
					fig7.prisma(1.8, 0.5, 0.5, madera.GLindex);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-0.5, -1.0, 1.5);
					fig7.prisma(1.8, 0.5, 0.5, madera.GLindex);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.5, -1.0, -1.5);
					fig7.prisma(1.8, 0.5, 0.5, madera.GLindex);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-0.5, -1.0, -1.5);
					fig7.prisma(1.8, 0.5, 0.5, madera.GLindex);
				glPopMatrix();

				glPushMatrix();							// 
					glTranslatef(0.0, 11.4, 0.0);
					glRotatef(balanceo, 0.0, 0.0, 1.0);

					glPushMatrix();						// CUERDA
						glTranslatef(0.0, 2.0, -1.0);
						glRotatef(180.0, 1.0, 0.0, 0.0);
						fig7.cilindro(0.2, extens, 10.0, cuerda.GLindex);
					
						glPushMatrix();					// SIERRA
							glTranslatef(0.0, extens, 0.0);
							glRotatef(90.0, 1.0, 0.0, 0.0);
							fig7.cilindro(1.0, 0.1, 10.0, saw.GLindex);
						glPopMatrix();

					glPopMatrix();

				glPopMatrix();

				glPushMatrix();							// ESPOSAS DE MADERA
					glTranslatef(5, 0, -5.5);
					glScalef(1.5, 2.0, 0.1);
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					prisma(madera_g.GLindex, madera.GLindex, madera_g_2.GLindex, madera.GLindex, madera.GLindex, madera.GLindex);
					glDisable(GL_BLEND);

					glPushMatrix();
						glTranslatef(-0.8, -0.6, 1.8);
						fig7.prisma(0.7, 0.2, 1.0, madera.GLindex);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.8, -0.6, 1.8);
						fig7.prisma(0.7, 0.2, 1.0, madera.GLindex);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.8, -0.6, -1.8);
						fig7.prisma(0.7, 0.2, 1.0, madera.GLindex);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(-0.8, -0.6, -1.8);
						fig7.prisma(0.7, 0.2, 1.0, madera.GLindex);
					glPopMatrix();

				glPopMatrix();

				glPushMatrix();							// PUERTA
					glTranslatef(15.5, -2.0, -2.5);
					glScalef(4.0, 0.03, 2.0);
					prisma(0, 0, 0, 0, puerta_1.GLindex, puerta.GLindex);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(4.5, 2.0, 9.25);
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					fig7.prisma(8.0, 5.2, 0.08, puerta02.GLindex);
					glDisable(GL_BLEND);
				glPopMatrix();

				glPushMatrix();							// PARED
					glTranslatef(-4.9, 5.8, 0.5);
					glScalef(0.01, 30.9, 3.5);
					prisma(0, pared03.GLindex, 0, 0, 0, 0);
				glPopMatrix();

			glPopMatrix();
//////////////////////////////////////////////// CALABOZO ////////////////////////////////////////////////
			glPushMatrix();								
				glPushMatrix();
					glTranslatef(23.0, 18.0, 28.5);
					fig7.prisma(0.5, 4.0, 8.0, madera.GLindex);

					glPushMatrix();
						glTranslatef(-1.8, 0.0, 3.5);
						glRotatef(-45.0, 0.0, 0.0, 1.0);
						fig7.cilindro(0.2, 5.0, 10.0, cuerda.GLindex);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(-1.8, 0.0, -3.5);
						glRotatef(-45.0, 0.0, 0.0, 1.0);
						fig7.cilindro(0.2, 5.0, 10.0, cuerda.GLindex);
					glPopMatrix();

				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(0.0, 24.5, 34.9);
					glScalef(8.0, 40.0, 0.01);
					prisma(0, 0, calabozo.GLindex, 0, 0, 0);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.0, 30.0, 22.5);
					glEnable(GL_BLEND);					// TRANSPARENCIA
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					fig7.prisma(30.0, 50.0, 0.1, reja.GLindex);
					glDisable(GL_BLEND);
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();
///////////////////////////////////////////////// MODELOS ////////////////////////////////////////////////
		glPushMatrix();									// DEMONIO
			glTranslatef(movDx, movDy, movDz);
			glScalef(4.8, 4.4, 4.3);
			glRotatef(rotD, 0.0, 1.0, 0.0);
			monster.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();

		glPushMatrix();									// MONSTRUO
			glTranslatef(movMx, movMy, movMz);
			glScalef(0.3, 0.2, 0.3);
			glRotatef(rotM, 0.0, 1.0, 0.0);
			trex.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();

	glPopMatrix();
//////////////////////////////////////////////// 1st PERSON //////////////////////////////////////////////<<<<<<<<<<<<<<<<
	if (arma1)
	{
		glPushMatrix();									
			glTranslatef(1.6, -5.9, 0.1);
			glScalef(0.06, 0.06, 0.04);
			glRotatef(192, 0.0, 1.0, 0.0);
			glRotatef(rota, 1.0, 0.0, 0.0);
			shotgun01.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
	}

	if (arma2)
	{
		glPushMatrix();
			glTranslatef(0.0, -5.5, 0.0);
			glScalef(0.06, 0.06, 0.04);
			glRotatef(192, 0.0, 1.0, 0.0);
			glRotatef(rotb, 1.0, 0.0, 0.0);
			shotgun02.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
	}

	if (arma3)
	{
		glPushMatrix();
			glTranslatef(1.1, -4.7, -1.0);
			glScalef(0.06, 0.06, 0.04);
			glRotatef(12, 0.0, 1.0, 0.0);
			glRotatef(rotc, 1.0, 0.0, 0.0);
			shotgun03.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	pintaTexto(-11, 12.0, -14.0, (void *)font, "Proyecto Final Laboratorio");
	pintaTexto(-11, 8.5, -14, (void *)font, s);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();
}

void animacion()
{
////////////////////////////////////////////// CAMBIO DE ARMA ////////////////////////////////////////////
	if (arma == 1)
	{
		rota -= 5;

		if (rota <= -70)
		{
			arma1 = false;
			arma2 = true;
			arma3 = false;
			rota = 0.0;
		}
	}

	if (arma == 2)
	{
		rotb -= 5;

		if (rotb <= -70)
		{
			arma1 = false;
			arma2 = false;
			arma3 = true;
			rotb = 0.0;
		}
	}

	if (arma == 3)
	{
		rotc += 5;

		if (rotc >= 70)
		{
			arma1 = true;
			arma2 = false;
			arma3 = false;
			rotc = 0.0;
			arma = 0;
		}
	}
//////////////////////////////////////////// RECORRIDO MONSTRUO //////////////////////////////////////////
	if (m_animacion)
	{
		if (m_avanza)
		{
			movMz -= 0.5;

			if (movMz < -2)
			{
				m_avanza = false;
				m_salto = true;
			}
		}

		if (m_salto)
		{
			movMy += 0.5;
			movMz -= 0.5;
			if (movMy > 10.0)
			{
				m_salto = false;
				m_caida = true;
			}
		}

		if (m_caida)
		{
			movMy -= 0.5;
			movMz -= 0.5;
			if (movMy < 0)
			{
				m_caida = false;
				m_giro = true;
			}
		}

		if (m_giro)
		{
			rotM += 5;

			if (rotM == 360)
			{
				m_giro = false;
				m_regreso = true;
			}
		}

		if (m_regreso)
		{
			movMz += 0.4;

			if (movMz > 25.2)
			{
				m_regreso = false;
				m_giro2 = true;
			}
		}

		if (m_giro2)
		{
			rotM += 5;

			if (rotM == 540)
			{
				m_giro2 = false;
			}
		}
	}
//////////////////////////////////////////// RECORRIDO DEMONIO ///////////////////////////////////////////
	if (recorrido)
	{
		if (recorrido1)
		{
			rotD += 1.0;

			if (rotD == 180)
			{
				recorrido1 = false;
				recorrido2 = true;
			}
		}
		if (recorrido2)
		{
			movDx += 0.1;

			if (movDx >= 17.5)
			{
				recorrido2 = false;
				recorrido3 = true;
			}
		}
		
		if (recorrido3)
		{
			rotD += 1.0;

			if (rotD == 270)
			{
				recorrido3 = false;
				recorrido4 = true;
			}
		}

		if (recorrido4)
		{
			movDz -= 0.1;

			if (movDz <= 6.1)
			{
				recorrido4 = false;
				recorrido5 = true;
			}
		}
	
		if (recorrido5)
		{
			rotD += 1.0;

			if (rotD == 360)
			{
				recorrido5 = false;
				recorrido6 = true;
			}
		}

		if (recorrido6)
		{
			movDx -= 0.1;
			
			if (movDx < -18.3)
			{
				recorrido6 = false;
				recorrido7 = true;
			}
		
		}

		if (recorrido7)
		{
			rotD += 1.0;

			if (rotD == 450)
			{
				recorrido7 = false;
				recorrido8 = true;
			}
			
		}

		if (recorrido8)
		{
			movDz += 0.1;

			if (movDz > 17.6)
			{
				recorrido8 = false;
				recorrido9 = true;
			}
		}
		
		if (recorrido9)
		{
			rotD++;

			if (rotD == 540)
			{
				recorrido9 = false;
				recorrido10 = true;
			}
		}

		if (recorrido10)
		{
			movDx += 0.1;

			if (movDx > -6.1)
			{
				recorrido10 = false;
				recorrido11 = true;
			}
		}

		if (recorrido11)
		{
			rotD++;

			if (rotD == 630)
			{
				recorrido11 = false;
				recorrido12 = true;
			}
		}

		if (recorrido12)
		{
			movDz -= 0.1;

			if (movDz <= -18)
			{
				recorrido12 = false;
				recorrido13 = true;
			}
		}

		if (recorrido13)
		{
			rotD++;

			if (rotD == 720)
			{
				rotD == 0;
				recorrido13 = false;
			}
		}
	}
//////////////////////////////////////////// MOVIMIENTO SIERRA ///////////////////////////////////////////
	if (play)
	{
		if (i_curr_steps >= i_max_steps)
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)
			{
				printf("FIN");
				playIndex = 0;
				play = false;
			}
			else
			{
				i_curr_steps = 0;						// Reset counter
								  
				interpolation();						// Interpolation
			}
		}
		else
		{												// Draw animation
			balanceo += KeyFrame[playIndex].incbalanceo;
			extens += KeyFrame[playIndex].incextens;

			i_curr_steps++;
		}
	}
////////////////////////////////////////////// CAIDA CABEZAS /////////////////////////////////////////////
	if (play2)
	{
		if (i_curr_steps >= i_max_steps)
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)
			{
				printf("FIN");
				playIndex = 0;
				play2 = false;
			}
			else
			{
				i_curr_steps = 0;						// Reset counter

				interpolation();						// Interpolation
			}
		}
		else
		{												// Draw animation
			caida2 += KeyFrame[playIndex].inccaida2;
			desp2 += KeyFrame[playIndex].incdesp2;

			caida3 += KeyFrame[playIndex].inccaida3;
			desp3 += KeyFrame[playIndex].incdesp3;

			caida4 += KeyFrame[playIndex].inccaida4;
			desp4 += KeyFrame[playIndex].incdesp4;

			i_curr_steps++;
		}
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)									// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)			// Create Keyboard Function
{
	switch (key) {
////////////////////////////////////////////////////////////////////////////
	case '+':
		tam += 0.01;
	break;

	case '-':
		tam -= 0.01;
	break;

	case '*':
		tam2 += 0.01;
	break;

	case '/':
		tam2 -= 0.01;
	break;

	case '7':
		tam3 += 0.01;
	break;

	case '9':
		tam3 -= 0.01;
	break;

	case '3':
		pX += 0.1;
	break;

	case '1':
		pX -= 0.1;
	break;

	case '4':
		pY += 0.1;
	break;

	case '6':
		pY -= 0.1;
	break;

	case '2':
		pZ += 0.1;
	break;

	case '5':
		pZ -= 0.1;
	break;

	case '0':
		rot += 1.0;
	break;

	case '.':
		rot -= 1.0;
	break;
//////////////////////////////////////////// CONTROL DE CAMARA ///////////////////////////////////////////
	case 'w':
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
	break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
	break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;
///////////////////////////////////////// CONTROL DE ANIMACIONES /////////////////////////////////////////
	case 'O':											// RECORRIDO DEMONIO
	case 'o':
		recorrido ^= true;
	break;

	case 'i':											// ATAQUE DE MONSTRUO
	case 'I':
		m_animacion ^= true;
	break;

	case 'k':											// CAMBIO DE ARMA
	case 'K':
		arma++;
	break;

	case 'l':											//  MOVIMIENTO SIERRA
	case 'L':
		if (play == false && (FrameIndex>1))
		{
			resetElements();							// First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
	break;

	case 'u':											//  CAIDA CABEZAS
	case 'U':
		if (play2 == false && (FrameIndex>1))
		{
			resetElements();							// First Interpolation
			interpolation();

			play2 = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play2 = false;
		}
	break;

	case 'b':
	case 'B':
		//printf("pX: %f \n", movMx);
		printf("pY: %f \n", movMy);
		printf("pZ: %f \n", movMz);
		printf("rot: %f\n", rotM);
	break;

	case 'p':
	case 'P':
		printf("pX: %f \n", pX);
		printf("pY: %f \n", pY);
		printf("pZ: %f \n", pZ);
		printf("rot: %f\n", rot);
		printf("tam: %f \n", tam);
		printf("tam2: %f \n", tam2);
		printf("tam3: %f \n", tam3);
	break;

	case 27:
		exit(0);
	break;

	default:
	break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)				// Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
	break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
	break;

	case GLUT_KEY_UP:
		g_lookupdown -= 1.0f;
	break;

	case GLUT_KEY_DOWN:
		g_lookupdown += 1.0f;
	break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
	break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
	break;

	default:
	break;
}
	glutPostRedisplay();
}

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 1:												// Play animation
		if (play == false && FrameIndex >1)
		{
			resetElements();							// First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;
	}
}

void menu(int id)
{

}

int main(int argc, char** argv)							// Main Function
{
	int submenu;

	glutInit(&argc, argv);								// Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutCreateWindow("Proyecto Final");					// Nombre de la Ventana
	glutFullScreen( );									// Full Screen
	InitGL();											// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);							// Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);							// Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);							// Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);						// Otras
	glutIdleFunc(animacion);

	submenu = glutCreateMenu(menuKeyFrame);
	glutAddMenuEntry("Guardar KeyFrame", 0);
	glutAddMenuEntry("Reproducir Animacion", 1);
	glutCreateMenu(menu);
	glutAddSubMenu("Animacion Monito", submenu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//Música
	PlaySound(NULL, NULL, 0);
	PlaySound("ProyectoCG.wav", NULL, SND_LOOP | SND_ASYNC);

	glutMainLoop();

	return 0;
}