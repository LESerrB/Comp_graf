//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//*************		Alumno (s): ******************************//
//*************		Romero Hurtado Eduardo David		******//
//*************		Serrano Bermúdez Luis Esteban		******//
//*************											******//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"
#include <windows.h>
#include <mmsystem.h>

#if (_MSC_VER == 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

float pos_camX = 0, pos_camY = 0, pos_camZ = 0;
float abrir = 0.0;
float abrir2 = 0.0;
float pant = 0.0;
float pX = 0.0, pY = 0.0, pZ = 0.0;
float tam = 1.0, tam2 = 1.0, tam3 = 1.0;
float rot = 0;

bool arranca = false;
bool ruta1 = false;
bool ruta2 = false;
bool ruta3 = false;
bool ruta4 = false;
bool ruta5 = false;
bool ruta6 = false;
bool ruta7 = false;
bool ruta8 = false;
bool ruta9 = false;
bool ruta10 = false;
bool ruta11 = false;
bool ruta12 = false;
bool ruta13 = false;
bool ruta14 = false;
bool ruta15 = false;

bool inicia = false;
bool vuelo1 = false;
bool vuelo2 = false;
bool vuelo3 = false;
bool vuelo4 = false;
bool vuelo5 = false;
bool vuelo6 = false;
bool vuelo7 = false;
bool vuelo8 = false;
bool vuelo9 = false;
bool vuelo10 = false;
bool vuelo11 = false;
bool vuelo12 = false;
bool vuelo13 = false;
bool vuelo14 = false;
bool vuelo15 = false;

float batmovX = 0.0, batmovY = 0.0, batmovZ = 0.0;
float batrotX = 0.0, batrotY = 0.0, batrotZ = 0.0;
int playIndex = 0;

bool play = false;


#define MAX_FRAMES 15
int i_max_steps = 100;
int i_curr_steps = 0;
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float movZ;
	float incmovZ;
	float movY;
	float incmovY;
	float movX;
	float incmovX;


}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 8;			//introducir datos

bool puertaentrada = false;
bool puertabano1 = false;
bool puertabano1c = false;

int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;

CCamera vistaCamara;

GLfloat CarroDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat CarroSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat CarroPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat CarroShininess[] = { 50.0 };

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };				// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position

GLfloat CamaraUpDn = 0.0f;
															
// TEXTURAS
CTexture t_cemento01;
CTexture t_metal2;
CTexture t_tabique01;
CTexture t_pasto01;
CTexture t_Sofa;
CTexture t_Madera;
CTexture t_Piso;
CTexture t_Piso2;
CTexture t_Librero;
CTexture TV;
CTexture pantalla;
CTexture bocina;
CTexture ps4u;
CTexture ps4f;
CTexture ps4s;
CTexture tree2;

CTexture libro;
CTexture tapa;
CTexture puerta01;

CTexture Libros_u;
CTexture Vitrina01;
CTexture Cama01;

CTexture aguapicina;
CTexture t_blanco;
CTexture t_blancop;
CTexture pdobleizq;
CTexture pdobleder;
CTexture puertaborde;
CTexture puertaseguro;
CTexture paredpisobajo;
CTexture paredpisobajo2;
CTexture paredpisobajo3;
CTexture paredpisobajo4;
CTexture paredpisobajo5;
CTexture paredpisobajo6;
CTexture tapiz;
CTexture tapiz2;
CTexture tapiz3;
CTexture tapiz4;
CTexture tapiz5;
CTexture ventanaX;
CTexture ventanaX2;
CTexture ventanaX3;
CTexture cemento;
CTexture tablamadera;
CTexture tablamadera2;
CTexture transparencia;
CTexture techo;
CTexture techo2;
CTexture techo3;
CTexture domino;
CTexture barandal;
CTexture barandal2;
CTexture barandal3;
CTexture clay;
CTexture glass;
CTexture vidrioblock;
CTexture puertabano;
CTexture pisobano;
CTexture pisobano2;

CTexture Skybox_ft;
CTexture Skybox_lf;
CTexture Skybox_rt;
CTexture Skybox_bk;
CTexture Skybox_up;
CTexture Skybox_dn;
CTexture cesped;
CTexture tierra;

CTexture maceta;
CTexture flores01;
CTexture flores02;

CTexture porcelana;
CTexture bano01;

CTexture refri01;
CTexture refri02;
CTexture fregadero01;
CTexture microondas01;
CTexture puerta_alacena;
CTexture puerta_alacena01;
CTexture madera_alacena;
CTexture estufa01;
CTexture parrilla01;
CTexture eagle;

CTexture t_madera02;
CTexture t_madera03;
CTexture t_madera04;

CFiguras macetas;
CFiguras refri;
CFiguras fregadero;
CFiguras microondas;
CFiguras alacena;
CFiguras estufa;
CFiguras ps4pro;
CFiguras bano;

CFiguras skybox;
CFiguras objeto1;
CFiguras fig_casa;
CFiguras fig_puerta;
CFiguras fig_picina;
CFiguras faguila;

CFiguras obj1;
CFiguras obj2;
CFiguras obj3;
CFiguras obj4;
CFiguras obj5;

CFiguras Calle;
CFiguras Banqueta;

CModel carro;

int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;

void InitGL ( GLvoid )										// Inicializamos parametros
{
	glClearColor(0.392f, 0.639f, 0.933f, 1.0f);					// fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);										// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);								// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);									// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//Posicion de la camara
	vistaCamara.Position_Camera(-18.0, 1.0, 251.0,
								-18.0, 1.0, 250.0,
								0.0, 1.0, 0.0);

	// CARGA MAPA DE BITS PARA TEXTURA
	t_cemento01.LoadBMP("Texturas/cemento.bmp");
	t_cemento01.BuildGLTexture();
	t_cemento01.ReleaseImage();

	t_metal2.LoadBMP("Texturas/metal2.bmp");
	t_metal2.BuildGLTexture();
	t_metal2.ReleaseImage();
	
	t_tabique01.LoadBMP("Texturas/Tabique.bmp");
	t_tabique01.BuildGLTexture();
	t_tabique01.ReleaseImage();

	t_pasto01.LoadBMP("Texturas/pasto.bmp");
	t_pasto01.BuildGLTexture();
	t_pasto01.ReleaseImage();

	t_Sofa.LoadTGA("Texturas/Sofa.tga");
	t_Sofa.BuildGLTexture();
	t_Sofa.ReleaseImage();

	Libros_u.LoadTGA("Texturas/Libros_u.tga");
	Libros_u.BuildGLTexture();
	Libros_u.ReleaseImage();

	Vitrina01.LoadTGA("Texturas/Vitrina.tga");
	Vitrina01.BuildGLTexture();
	Vitrina01.ReleaseImage();

	Cama01.LoadTGA("Texturas/Cama.tga");
	Cama01.BuildGLTexture();
	Cama01.ReleaseImage();

	t_Madera.LoadTGA("Texturas/Acabado_Madera.tga");
	t_Madera.BuildGLTexture();
	t_Madera.ReleaseImage();

	t_Piso.LoadTGA("Texturas/Piso_Madera01.tga");
	t_Piso.BuildGLTexture();
	t_Piso.ReleaseImage();

	t_Piso2.LoadTGA("Texturas/Piso_Madera02.tga");
	t_Piso2.BuildGLTexture();
	t_Piso2.ReleaseImage();

	t_Librero.LoadTGA("Texturas/Librero.tga");
	t_Librero.BuildGLTexture();
	t_Librero.ReleaseImage();

	Skybox_bk.LoadTGA("Texturas/skybox/pradera_bk.tga");
	Skybox_bk.BuildGLTexture();
	Skybox_bk.ReleaseImage();

	Skybox_ft.LoadTGA("Texturas/skybox/pradera_ft.tga");
	Skybox_ft.BuildGLTexture();
	Skybox_ft.ReleaseImage();

	Skybox_lf.LoadTGA("Texturas/skybox/pradera_lf.tga");
	Skybox_lf.BuildGLTexture();
	Skybox_lf.ReleaseImage();

	Skybox_rt.LoadTGA("Texturas/skybox/pradera_rt.tga");
	Skybox_rt.BuildGLTexture();
	Skybox_rt.ReleaseImage();

	Skybox_up.LoadTGA("Texturas/skybox/pradera_up.tga");
	Skybox_up.BuildGLTexture();
	Skybox_up.ReleaseImage();

	Skybox_dn.LoadTGA("Texturas/skybox/pradera_dn.tga");
	Skybox_dn.BuildGLTexture();
	Skybox_dn.ReleaseImage();

	cesped.LoadTGA("Texturas/skybox/cesped.tga");
	cesped.BuildGLTexture();
	cesped.ReleaseImage();

	tierra.LoadTGA("Texturas/skybox/tierra.tga");
	tierra.BuildGLTexture();
	tierra.ReleaseImage();

	t_blanco.LoadTGA("Texturas/blanco.tga");
	t_blanco.BuildGLTexture();
	t_blanco.ReleaseImage();

	t_blancop.LoadTGA("Texturas/blanco_peque.tga");
	t_blancop.BuildGLTexture();
	t_blancop.ReleaseImage();

	pdobleder.LoadTGA("Texturas/puertader.tga");
	pdobleder.BuildGLTexture();
	pdobleder.ReleaseImage();

	pdobleizq.LoadTGA("Texturas/puertaizq.tga");
	pdobleizq.BuildGLTexture();
	pdobleizq.ReleaseImage();

	puertaborde.LoadTGA("Texturas/puertaborde.tga");
	puertaborde.BuildGLTexture();
	puertaborde.ReleaseImage();
	
	puertaseguro.LoadTGA("Texturas/puertaseguro.tga");
	puertaseguro.BuildGLTexture();
	puertaseguro.ReleaseImage();

	paredpisobajo.LoadTGA("Texturas/paredpisobajo.tga");
	paredpisobajo.BuildGLTexture();
	paredpisobajo.ReleaseImage();

	paredpisobajo2.LoadTGA("Texturas/paredpisobajo2.tga");
	paredpisobajo2.BuildGLTexture();
	paredpisobajo2.ReleaseImage();

	paredpisobajo3.LoadTGA("Texturas/paredpisobajo3.tga");
	paredpisobajo3.BuildGLTexture();
	paredpisobajo3.ReleaseImage();

	paredpisobajo4.LoadTGA("Texturas/paredpisobajo4.tga");
	paredpisobajo4.BuildGLTexture();
	paredpisobajo4.ReleaseImage();

	paredpisobajo5.LoadTGA("Texturas/paredpisobajo5.tga");
	paredpisobajo5.BuildGLTexture();
	paredpisobajo5.ReleaseImage();

	paredpisobajo6.LoadTGA("Texturas/paredpisobajo6.tga");
	paredpisobajo6.BuildGLTexture();
	paredpisobajo6.ReleaseImage();

	tapiz.LoadTGA("Texturas/tapiz.tga");
	tapiz.BuildGLTexture();
	tapiz.ReleaseImage();

	tapiz2.LoadTGA("Texturas/tapiz2.tga");
	tapiz2.BuildGLTexture();
	tapiz2.ReleaseImage();

	ventanaX.LoadTGA("Texturas/ventana.tga");
	ventanaX.BuildGLTexture();
	ventanaX.ReleaseImage();

	ventanaX2.LoadTGA("Texturas/ventana2.tga");
	ventanaX2.BuildGLTexture();
	ventanaX2.ReleaseImage();

	ventanaX3.LoadTGA("Texturas/ventanaX3.tga");
	ventanaX3.BuildGLTexture();
	ventanaX3.ReleaseImage();

	cemento.LoadTGA("Texturas/cemento.tga");
	cemento.BuildGLTexture();
	cemento.ReleaseImage();

	tablamadera.LoadTGA("Texturas/tablamadera.tga");
	tablamadera.BuildGLTexture();
	tablamadera.ReleaseImage();

	tablamadera2.LoadTGA("Texturas/tablamaderaS.tga");
	tablamadera2.BuildGLTexture();
	tablamadera2.ReleaseImage();

	transparencia.LoadTGA("Texturas/transparencia.tga");
	transparencia.BuildGLTexture();
	transparencia.ReleaseImage();

	techo.LoadTGA("Texturas/techo.tga");
	techo.BuildGLTexture();
	techo.ReleaseImage();

	techo2.LoadTGA("Texturas/techo2.tga");
	techo2.BuildGLTexture();
	techo2.ReleaseImage();

	domino.LoadTGA("Texturas/domino.tga");
	domino.BuildGLTexture();
	domino.ReleaseImage();

	barandal.LoadTGA("Texturas/barandal.tga");
	barandal.BuildGLTexture();
	barandal.ReleaseImage();

	barandal2.LoadTGA("Texturas/barandal2.tga");
	barandal2.BuildGLTexture();
	barandal2.ReleaseImage();

	barandal3.LoadTGA("Texturas/barandal3.tga");
	barandal3.BuildGLTexture();
	barandal3.ReleaseImage();

	clay.LoadTGA("Texturas/clay.tga");
	clay.BuildGLTexture();
	clay.ReleaseImage();

	tapiz3.LoadTGA("Texturas/tapiz3.tga");
	tapiz3.BuildGLTexture();
	tapiz3.ReleaseImage();

	tapiz4.LoadTGA("Texturas/tapiz4.tga");
	tapiz4.BuildGLTexture();
	tapiz4.ReleaseImage();

	tapiz5.LoadTGA("Texturas/tapiz5.tga");
	tapiz5.BuildGLTexture();
	tapiz5.ReleaseImage();

	techo3.LoadTGA("Texturas/techo3.tga");
	techo3.BuildGLTexture();
	techo3.ReleaseImage();

	glass.LoadTGA("Texturas/glass.tga");
	glass.BuildGLTexture();
	glass.ReleaseImage();

	vidrioblock.LoadTGA("Texturas/vidrioblock.tga");
	vidrioblock.BuildGLTexture();
	vidrioblock.ReleaseImage();

	puertabano.LoadTGA("Texturas/puertabano.tga");
	puertabano.BuildGLTexture();
	puertabano.ReleaseImage();

	pisobano.LoadTGA("Texturas/pisobano.tga");
	pisobano.BuildGLTexture();
	pisobano.ReleaseImage();

	aguapicina.LoadTGA("Texturas/aguapicina.tga");
	aguapicina.BuildGLTexture();
	aguapicina.ReleaseImage();

	pisobano2.LoadTGA("Texturas/pisobano2.tga");
	pisobano2.BuildGLTexture();
	pisobano2.ReleaseImage();

	maceta.LoadTGA("Texturas/Maceta.tga");
	maceta.BuildGLTexture();
	maceta.ReleaseImage();

	flores01.LoadTGA("Texturas/Flores01.tga");
	flores01.BuildGLTexture();
	flores01.ReleaseImage();

	flores02.LoadTGA("Texturas/Flores02.tga");
	flores02.BuildGLTexture();
	flores02.ReleaseImage();

	refri01.LoadTGA("Texturas/Refri.tga");
	refri01.BuildGLTexture();
	refri01.ReleaseImage();

	refri02.LoadTGA("Texturas/refri_int.tga");
	refri02.BuildGLTexture();
	refri02.ReleaseImage();

	fregadero01.LoadTGA("Texturas/Fregadero.tga");
	fregadero01.BuildGLTexture();
	fregadero01.ReleaseImage();

	microondas01.LoadTGA("Texturas/microondas.tga");
	microondas01.BuildGLTexture();
	microondas01.ReleaseImage();

	puerta_alacena.LoadTGA("Texturas/Puerta_alacena02.tga");
	puerta_alacena.BuildGLTexture();
	puerta_alacena.ReleaseImage();

	puerta_alacena01.LoadTGA("Texturas/Puerta_alacena03.tga");
	puerta_alacena01.BuildGLTexture();
	puerta_alacena01.ReleaseImage();

	madera_alacena.LoadTGA("Texturas/Acabado_alacena.tga");
	madera_alacena.BuildGLTexture();
	madera_alacena.ReleaseImage();

	estufa01.LoadTGA("Texturas/Estufa.tga");
	estufa01.BuildGLTexture();
	estufa01.ReleaseImage();

	parrilla01.LoadTGA("Texturas/Parrilla.tga");
	parrilla01.BuildGLTexture();
	parrilla01.ReleaseImage();

	t_madera02.LoadBMP("Texturas/madera02.bmp");
	t_madera02.BuildGLTexture();
	t_madera02.ReleaseImage();

	t_madera03.LoadBMP("Texturas/madera03.bmp");
	t_madera03.BuildGLTexture();
	t_madera03.ReleaseImage();

	t_madera04.LoadBMP("Texturas/madera04.bmp");
	t_madera04.BuildGLTexture();
	t_madera04.ReleaseImage();

	TV.LoadTGA("Texturas/Tv.tga");
	TV.BuildGLTexture();
	TV.ReleaseImage();

	pantalla.LoadTGA("Texturas/pant.tga");
	pantalla.BuildGLTexture();
	pantalla.ReleaseImage();

	bocina.LoadTGA("Texturas/Bocinas.tga");
	bocina.BuildGLTexture();
	bocina.ReleaseImage();

	ps4f.LoadTGA("Texturas/ps4_pro_front.tga");
	ps4f.BuildGLTexture();
	ps4f.ReleaseImage();

	ps4u.LoadTGA("Texturas/ps4_pro_up.tga");
	ps4u.BuildGLTexture();
	ps4u.ReleaseImage();

	ps4s.LoadTGA("Texturas/ps4_pro_side.tga");
	ps4s.BuildGLTexture();
	ps4s.ReleaseImage();

	porcelana.LoadTGA("Texturas/Porcelana.tga");
	porcelana.BuildGLTexture();
	porcelana.ReleaseImage();

	bano01.LoadTGA("Texturas/bano01.tga");
	bano01.BuildGLTexture();
	bano01.ReleaseImage();

	libro.LoadTGA("Texturas/libros.tga");
	libro.BuildGLTexture();
	libro.ReleaseImage();

	tapa.LoadTGA("Texturas/Tapa_libro.tga");
	tapa.BuildGLTexture();
	tapa.ReleaseImage();

	puerta_alacena01.LoadTGA("Texturas/Puerta_alacena01.tga");
	puerta_alacena01.BuildGLTexture();
	puerta_alacena01.ReleaseImage();

	puerta01.LoadTGA("Texturas/Puerta_alacena01.tga");
	puerta01.BuildGLTexture();
	puerta01.ReleaseImage();

	tree2.LoadTGA("Texturas/tree2.tga");
	tree2.BuildGLTexture();
	tree2.ReleaseImage();

	eagle.LoadTGA("Texturas/eagle.tga");
	eagle.BuildGLTexture();
	eagle.ReleaseImage();


	/*carro._3dsLoad("modelos/carro/CHALLENGER71.3ds");
	carro.LoadTextureImages();
	carro.GLIniTextures();
	carro.ReleaseTextureImages();*/


	/*################	KEYFRAMES MURCIELAGO ####################*/
/*
	KeyFrame[0].posX = 0.0;
	KeyFrame[0].posY = 0.0;
	KeyFrame[0].posZ = 0.0;

	KeyFrame[1].posX = -141.0;
	KeyFrame[1].posY = -1830.0;
	KeyFrame[1].posZ = -39.0;

	KeyFrame[2].posX = -95.0;
	KeyFrame[2].posY = -246.0;
	KeyFrame[2].posZ = -79.0;

	KeyFrame[3].posX = 7.0;
	KeyFrame[3].posY = -264.0;
	KeyFrame[3].posZ = -122.0;

	KeyFrame[4].posX = 111.0;
	KeyFrame[4].posY = -173.0;
	KeyFrame[4].posZ = -168.0;

	KeyFrame[5].posX = 187.0;
	KeyFrame[5].posY = 77.0;
	KeyFrame[5].posZ = -202.0;

	KeyFrame[6].posX = 182.0;
	KeyFrame[6].posY = 160.0;
	KeyFrame[6].posZ = -230.0;

	KeyFrame[7].posX = 76.0;
	KeyFrame[7].posY = 289.0;
	KeyFrame[7].posZ = -275.0;

	KeyFrame[8].posX = -247.0;
	KeyFrame[8].posY = 314.0;
	KeyFrame[8].posZ = -310.0;

	KeyFrame[9].posX = -354.0;
	KeyFrame[9].posY = 165.0;
	KeyFrame[9].posZ = -352.0;

	KeyFrame[10].posX = -393.0;
	KeyFrame[10].posY = 13.0;
	KeyFrame[10].posZ = -395.0;

	KeyFrame[11].posX = -11.0;
	KeyFrame[11].posY = -196.0;
	KeyFrame[11].posZ = -472.0;*/
}

/*void resetElements(void)
{
	batmovX = KeyFrame[0].posX;
	batmovY = KeyFrame[0].posY;
	batmovZ = KeyFrame[0].posZ;

	batrotZ = KeyFrame[0].movZ;
	batrotY = KeyFrame[0].movY;
	batrotX = KeyFrame[0].movX;
}*/

/*void interpolation(void)
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;

	KeyFrame[playIndex].incmovX = (KeyFrame[playIndex + 1].movX - KeyFrame[playIndex].movX) / i_max_steps;
	KeyFrame[playIndex].incmovY = (KeyFrame[playIndex + 1].movY - KeyFrame[playIndex].movY) / i_max_steps;
	KeyFrame[playIndex].incmovZ = (KeyFrame[playIndex + 1].movZ - KeyFrame[playIndex].movZ) / i_max_steps;

}*/

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
/* REPITE LA TEXTURA DENTRO DEL POLIGONO
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
//PONE UNA TEXTURA EN TODA LA EXTENSIÓN DEL PRISMA
void prisma2(GLuint textura1, GLuint textura2, GLuint textura3, GLuint textura4, GLuint textura5, GLuint textura6)				//Funcion creacion prisma
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

void prisma3(GLuint textura1, GLuint textura2, float num1, float num2)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(num1, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(num1, num1); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, num1); glVertex3fv(vertice[1]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(num1, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(num1, num1); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, num1); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(num1, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(num1, num1); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, num1); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(num1, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(num1, num1); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, num1); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(num1, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(num1, num1); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, num1); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(num2, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(num2, num2); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, num2); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void prisma4(GLuint textura1, GLuint textura2, GLuint textura3, GLuint textura4, GLuint textura5, GLuint textura6)				//Funcion creacion prisma
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
	glTexCoord2f(1.0f + pant, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f + pant, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f + pant, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f + pant, 0.0f); glVertex3fv(vertice[2]);
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

	pant += 0.01;
}*/

/*void Mesa()													// MESA
{
	// TABLA
	glPushMatrix();
		glScalef(2.0, 0.5, 0.6);
		prisma2(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();
	// PATAS
	glPushMatrix();
		glTranslatef(-1.8, -1.5, 1.2);
		glScalef(0.2, 6.0, 0.05);
		prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, 0, 0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.8, -1.5, 1.2);
		glScalef(0.2, 6.0, 0.05);
		prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, 0, 0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.8, -1.5, -1.2);
		glScalef(0.2, 6.0, 0.05);
		prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, 0, 0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.8, -1.5, -1.2);
		glScalef(0.2, 6.0, 0.05);
		prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, 0, 0);
	glPopMatrix();
}*/

/*void Sillon()
{	
	// ASIENTO
	glPushMatrix();
		glScalef(3.0, 5.0, 0.55);
		prisma(t_Sofa.GLindex, t_Sofa.GLindex, t_Sofa.GLindex, t_Sofa.GLindex, 0, t_Sofa.GLindex);
	glPopMatrix();
	// RESPALDO
	glPushMatrix();
		glRotatef(-10.0, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 2.60, -0.8);
		glScalef(3.0, 5.5, 0.15);
		prisma(t_Sofa.GLindex, t_Sofa.GLindex, t_Sofa.GLindex, t_Sofa.GLindex, 0, t_Sofa.GLindex);
	glPopMatrix();
	// DESCANZABRAZOS
	glPushMatrix();
		glTranslatef(3.2, 1.5, -1.4);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		objeto1.cilindro(0.5, 2.8, 10.0, t_Sofa.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3.2, 1.5, -1.4);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		objeto1.cilindro(0.5, 2.8, 10.0, t_Sofa.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(3.2, 0.0, 0.0);
		glScalef(0.25, 5.0, 0.55);
		prisma(t_Sofa.GLindex, t_Sofa.GLindex, t_Sofa.GLindex, t_Sofa.GLindex, 0, t_Sofa.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3.2, 0.0, 0.0);
		glScalef(0.25, 5.0, 0.55);
		prisma(t_Sofa.GLindex, t_Sofa.GLindex, t_Sofa.GLindex, t_Sofa.GLindex, 0, t_Sofa.GLindex);
	glPopMatrix();
}*/

/*void MuebleTV() {
	// BASE INFERIOR
	glPushMatrix();
	glScalef(0.9, 0.3, 1.8);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();
	// PAREDES
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 0.3, 1.8);
	glTranslatef(0.0, 14.75, -2.5);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 0.3, 1.8);
	glTranslatef(0.0, -14.75, -2.5);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	// BASE SUPERIOR
	glPushMatrix();
	glScalef(0.9, 0.3, 1.8);
	glTranslatef(0.0, 30.0, 0.0);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	// DIVISION INFERIOR
	glPushMatrix();
	glScalef(0.9, 0.3, 1.8);
	glTranslatef(0.0, 5.0, 0.0);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	// DIVISION SUPERIOR
	glPushMatrix();
	glScalef(0.9, 0.3, 1.8);
	glTranslatef(0.0, 25.0, 0.0);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	// DIVISIONES LATERALES
	glPushMatrix();
	glScalef(0.9, 1.2, 0.3);
	glTranslatef(0.0, 3.8, 10.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 1.2, 0.3);
	glTranslatef(0.0, 3.8, -10.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	// DIVISIONES INTERNAS VERTICALES
	glPushMatrix();
	glScalef(0.9, 0.3, 0.3);
	glTranslatef(0.0, 2.5, 5.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 0.3, 0.3);
	glTranslatef(0.0, 2.5, -5.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 0.3, 0.3);
	glTranslatef(0.0, 27.5, 4.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 0.3, 0.3);
	glTranslatef(0.0, 27.5, -4.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	// DIVISIONES INTERNAS HORIZONTALES
	glPushMatrix();
	glScalef(0.9, 0.3, 0.6);
	glTranslatef(0.0, 2.5, 0.0);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 0.3, 0.5);
	glTranslatef(0.0, 27.5, 0.0);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 0.3, 0.3);
	glTranslatef(0.0, 12.0, 12.5);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 0.3, 0.3);
	glTranslatef(0.0, 19.0, 12.5);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 0.3, 0.3);
	glTranslatef(0.0, 12.0, -12.5);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 0.3, 0.3);
	glTranslatef(0.0, 19.0, -12.5);
	prisma(t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 3.8, 0.0);
	glScalef(0.1, 8.8, 1.1);
	prisma2(t_metal2.GLindex, t_metal2.GLindex, t_metal2.GLindex, TV.GLindex, t_metal2.GLindex, t_metal2.GLindex);

	glPushMatrix();
	glTranslatef(-0.99999999, 0.02, 0.01);
	glScalef(0.01, 0.88, 0.98);
	prisma4(NULL, NULL, NULL, pantalla.GLindex, NULL, NULL);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 2.8, 0.2);
	glTranslatef(-0.1, 2.31, 18.7);
	prisma2(t_metal2.GLindex, t_metal2.GLindex, t_metal2.GLindex, bocina.GLindex, t_metal2.GLindex, t_metal2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 2.8, 0.2);
	glTranslatef(-0.1, 2.31, -18.7);
	prisma2(t_metal2.GLindex, t_metal2.GLindex, t_metal2.GLindex, bocina.GLindex, t_metal2.GLindex, t_metal2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 2.8, 0.2);
	glTranslatef(-0.1, 0.82, 18.7);
	prisma2(t_metal2.GLindex, t_metal2.GLindex, t_metal2.GLindex, bocina.GLindex, t_metal2.GLindex, t_metal2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 2.8, 0.2);
	glTranslatef(-0.1, 0.82, -18.7);
	prisma2(t_metal2.GLindex, t_metal2.GLindex, t_metal2.GLindex, bocina.GLindex, t_metal2.GLindex, t_metal2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 7.8, 0.0);
	ps4pro.prisma5(0.4, 1.3, 1.7, ps4s.GLindex, ps4s.GLindex, ps4f.GLindex, 0, ps4u.GLindex, 0);
	glPopMatrix();
}*/

void puertadoble(float movimiento) {
	glPushMatrix();
		glTranslatef(0.0, 0.0, -10.0);
		glRotatef(-movimiento, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.0, 5.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_puerta.prisma5(25.0, 0.5, 10.0, puertaseguro.GLindex, puertaborde.GLindex, pdobleizq.GLindex, pdobleder.GLindex, puertaborde.GLindex, puertaborde.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, 10.0);
		glRotatef(movimiento, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.0, -5.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_puerta.prisma5(25.0, 0.5, 10.0, puertaborde.GLindex, puertaseguro.GLindex, pdobleder.GLindex, pdobleizq.GLindex, puertaborde.GLindex, puertaborde.GLindex);
	glPopMatrix();
}

/*void Macetas() {
	glPushMatrix();
	//glTranslatef(pX, pY, pZ);
	macetas.cilindro(1.1, 6.1, 20, maceta.GLindex);
	glPopMatrix();
}*/

/*void arbol_alpha(GLuint hojas)
{
	glPushMatrix();
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, hojas);
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
	//glEnable(GL_LIGHTING);

	glPopMatrix();
}*/

/*void bosque() {
	//arbol_blend();
	glPushMatrix();
	glTranslatef(10.0, 0.0, 220.0);
	glScalef(1.5, 3.0, 1.5);
	arbol_alpha(tree2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(3.0, 6.0, 3.0);
	glTranslatef(20.0, 2.0, 100.0);
	arbol_alpha(tree2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.0, 0.0, 130.0);
	glScalef(1.5, 3.0, 1.5);
	arbol_alpha(tree2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 200.0);
	glScalef(5.0, 8.0, 5.0);
	arbol_alpha(tree2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30.0, 0.0, 170.0);
	glScalef(3.0, 7.0, 3.0);
	arbol_alpha(tree2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20.0, 5.0, 50.0);
	glScalef(10.0, 9.0, 10.0);
	arbol_alpha(tree2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30.0, 0.0, 100.0);
	glScalef(3.0, 7.0, 3.0);
	arbol_alpha(tree2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(7.0, 4.0, 7.0);
	glTranslatef(10.0, 2.0, 30.0);
	arbol_alpha(tree2.GLindex);
	glPopMatrix();
}*/

/*void Fregadero() {
	glPushMatrix();
	glTranslatef(-41, -10, 132);
	glScalef(6.0,1.0,1.0);
	fregadero.prisma5(10.2, 5.0, 8.9, cemento.GLindex, cemento.GLindex, cemento.GLindex, cemento.GLindex, fregadero01.GLindex, cemento.GLindex);
	glPopMatrix();
}*/

/*void Cocina1() {
	
	glPushMatrix();
	glTranslatef(-101.5, -1.3, 140.0);
	glScalef(1.85, 1.6, 1.4);
	glRotatef(90.0, 0.0, 1.0, 0.0);

	glTranslatef(0.0, -4.4, 15.8);
	alacena.prisma7(8.3, 8.0, 3.3, puerta_alacena.GLindex, madera_alacena.GLindex, madera_alacena.GLindex, madera_alacena.GLindex, madera_alacena.GLindex, madera_alacena.GLindex);

	glPushMatrix();
	glTranslatef(0.0, 11.5, 0.0);
	alacena.prisma7(3.8, 8.3, 3.4, puerta_alacena01.GLindex, madera_alacena.GLindex, madera_alacena.GLindex, madera_alacena.GLindex, madera_alacena.GLindex, madera_alacena.GLindex);
	glPopMatrix();

	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glTranslatef(2.4, 5.0, -0.6);
	microondas.prisma4(1.6, 2.3, -1.7, microondas01.GLindex, t_metal2.GLindex, t_metal2.GLindex, t_metal2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.9, 3.6, 0.0);
	refri.prisma5(15.0, 7.4, 3.3, refri02.GLindex, t_metal2.GLindex, t_metal2.GLindex, t_metal2.GLindex, t_metal2.GLindex, t_metal2.GLindex);

	glPushMatrix();
	glTranslatef(0.0, -0.3, 1.68);
	refri.prisma(15.0, 7.4, 0.1, refri01.GLindex);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.7, 0.1, 0.1);
	estufa.prisma5(8.6, 5.2, 3.7, estufa01.GLindex, t_metal2.GLindex, t_metal2.GLindex, t_metal2.GLindex, parrilla01.GLindex, t_metal2.GLindex);
	glPopMatrix();
	glPopMatrix();
}*/

/*void Sala() {
	glPushMatrix();
	glTranslatef(-55.1997, -7.4, 28.4);
	glScalef(1.95, 2.5, 2.85);
	glDisable(GL_LIGHTING);
	glPushMatrix();						// MESSA CENTRAL
	glTranslatef(0.0, -1.3, 0.0);
	glScalef(1.5, 0.6, 1.0);
	Mesa();
	glPopMatrix();

	glPushMatrix();						// SILLON 3
	glTranslatef(0.0, -1.8, -6.0);
	Sillon();
	glPopMatrix();

	glPushMatrix();						// SILLON 2
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(0.8, 1.0, 1.0);
	glTranslatef(0.0, -1.8, -8.0);
	Sillon();
	glPopMatrix();

	glPushMatrix();						// SILLON 1
	glRotatef(180, 0.0, 1.0, 0.0);
	glScalef(0.4, 1.0, 0.8);
	glTranslatef(2.0, -1.8, -8.0);
	Sillon();
	glPopMatrix();

	glPushMatrix();						// CENTRO DE ENTRETENIMIENTO
	glTranslatef(14.0, -3.0, 0.0);
	MuebleTV();
	glPopMatrix();

	glPushMatrix();						// MESA ESQUINA
	glTranslatef(-7.0, 0.05, 6.0);
	glScalef(0.6, 1.05, 1.0);
	Mesa();
	glPopMatrix();
	glPopMatrix();
}*/

/*void Piso_Madera() {
	glPushMatrix();
	glScalef(15.0, 0.1, 5.0);
	glTranslatef(0.0, -31.0, 0.0);
	prisma(0, 0, 0, 0, 0, t_Piso.GLindex);
	glPopMatrix();
}*/

/*void Silla() {
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glTranslatef(-9.0, -4.0, 0.0);

	glPushMatrix();		//borde1
	glTranslated(3.25, 0.0, 0.0);
	glScalef(0.5, 0.5, 6.0);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//borde2
	glTranslated(-3.5, 0.0, 0.0);
	glScalef(1.0, 0.5, 6.0);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//borde3
	glTranslated(0.0, 0.0, 3.25);
	glScalef(7.0, 0.5, 0.5);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//borde4
	glTranslated(0.0, 0.0, -3.25);
	glScalef(7.0, 0.5, 0.5);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//asiento
	glScalef(6.0, 0.5, 6.0);
	prisma3(t_madera03.GLindex, t_madera02.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//pata1
	glTranslated(3.25, -3.0, 3.25);
	glScalef(0.5, 5.5, 0.5);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//pata2
	glTranslated(-3.75, -3.0, 3.25);
	glScalef(0.5, 5.5, 0.5);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//pata3
	glTranslated(3.25, -3.0, -3.25);
	glScalef(0.5, 5.5, 0.5);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//pata4
	glTranslated(-3.75, -3.0, -3.25);
	glScalef(0.5, 5.5, 0.5);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//union entre pata4 y asiento
	glTranslated(-3.875, 0.0, -3.3);
	glScalef(0.75, 0.5, 0.60);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//union entre pata2 y asiento
	glTranslated(-3.875, 0.0, 3.3);
	glScalef(0.75, 0.5, 0.60);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//respaldo soporte 1
	glRotatef(10.0, 0.0, 0.0, 1.0);
	glTranslated(-3.75, 4.25, -3.25);
	glScalef(0.5, 7.5, 0.5);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//respaldo soporte 2
	glRotatef(10.0, 0.0, 0.0, 1.0);
	glTranslated(-3.75, 4.25, 3.25);
	glScalef(0.5, 7.5, 0.5);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();		//respaldo
	glRotatef(90.0, 0.0, 0.0, -1.0);
	glRotatef(10.0, 0.0, 0.0, 1.0);
	glTranslated(-5.75, -3.75, 0.0);

	glPushMatrix();	//respaldo soporte inferior 
	glTranslatef(2.0, 0.0, 0.0);
	glScalef(0.5, 0.5, 6.0);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();	//respaldo soporte superior
	glTranslatef(-2.0, 0.0, 0.0);
	glScalef(0.5, 0.5, 6.0);
	prisma3(t_madera04.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();	//parte central
	glScalef(3.5, 0.5, 6.0);
	prisma3(t_madera03.GLindex, t_madera04.GLindex, 1.0, 1.0);
	glPopMatrix();
	glPopMatrix();
}*/

/*void Comedor() {
	glPushMatrix();
		glTranslatef(-51.2, -6, 89.5);
		glScalef(1.1, 1.2, 1.0);
	glPushMatrix();
	glTranslatef(0.0, -1.6, 0.0);
	glScalef(4.6, 2.1, 3.1);
	Mesa();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5, -1.0, 0.0);
	glScalef(0.5, 0.7, 0.4);
	Silla();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -1.0, 0.0);
	glScalef(0.5, 0.7, 0.4);
	Silla();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glTranslatef(-3.5, -1.0, 0.0);
	glScalef(0.5, 0.7, 0.4);
	Silla();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glTranslatef(3.5, -1.0, 0.0);
	glScalef(0.5, 0.7, 0.4);
	Silla();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 5.0);
	glScalef(0.5, 0.8, 0.4);
	Silla();
	glPopMatrix();

	glPushMatrix();
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, .0, 5.0);
	glScalef(0.5, 0.8, 0.4);
	Silla();
	glPopMatrix();
	glPopMatrix();
}*/

/*void Librero() {
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(5.0, 0.0, 2.0);
	glTranslatef(0.0, 0.1, 0.0);
	prisma(0, 0, 0, 0, 0, t_Librero.GLindex);
	glPopMatrix();

	glPushMatrix();						// LATERAL IZQUIERDA
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 4.95, 0.8);
	glScalef(5.0, 0.3, 0.3);
	prisma(t_Madera.GLindex, 0, 0, 0, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();						// LATERAL DERECHA
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -4.95, 0.8);
	glScalef(5.0, 0.3, 0.3);
	prisma(t_Madera.GLindex, 0, 0, 0, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();						// BASE
	glTranslatef(0.0, -5.0, 0.8);
	glScalef(5.02, 0.3, 0.3);
	prisma(t_Madera.GLindex, t_Madera.GLindex, 0, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();						// SUPERIOR
	glTranslatef(0.0, 5.0, 0.8);
	glScalef(5.02, 0.3, 0.3);
	prisma(t_Madera.GLindex, t_Madera.GLindex, 0, t_Madera.GLindex, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();
}*/

/*void Cama() {
	glTranslatef(0.0, -1.1, 0.0);
	obj5.prisma(2.3, 6.1, 8.6, Cama01.GLindex);

	glPushMatrix();
	glTranslatef(-2.8, -2.0, -4.1);
	obj5.cilindro(0.1, 0.9, 20.0, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.8, -2.0, -4.1);
	obj5.cilindro(0.1, 0.9, 20.0, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.8, -2.0, 4.1);
	obj5.cilindro(0.1, 0.9, 20.0, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.8, -2.0, 4.1);
	obj5.cilindro(0.1, 0.9, 20.0, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.9, -4.3);
	obj5.prisma(5.7, 6.3, 0.2, t_Madera.GLindex);
	glPopMatrix();
}*/

/*void LibreroC() {//<<<<<<<<<<<<<<<<<<<<<<<<<<<ESTA ES LA FUNCION QUE LLAMA AL LIBRERO COMPLETO
	glTranslatef(-10.0, 2.0, -12.5);
	Librero();

	glPushMatrix();
	glTranslatef(0.0, 2.4, 0.8);
	glScalef(4.9, 0.4, 0.3);
	prisma2(t_Madera.GLindex, 0, 0, 0, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.7, 0.8);
	glScalef(4.9, 0.4, 0.3);
	prisma2(t_Madera.GLindex, 0, 0, 0, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.7, 0.8);
	glScalef(4.9, 0.4, 0.3);
	prisma2(t_Madera.GLindex, 0, 0, 0, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -2.6, 0.8);
	glScalef(4.9, 0.4, 0.3);
	prisma2(t_Madera.GLindex, 0, 0, 0, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5, 3.1, 1.2);
	glScalef(1.1, 2.4, 0.2);
	prisma2(libro.GLindex, tapa.GLindex, 0, tapa.GLindex, Libros_u.GLindex, Libros_u.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.1, 3.1, 0.9);
	glScalef(1.1, 2.4, 0.2);
	prisma2(libro.GLindex, tapa.GLindex, 0, tapa.GLindex, Libros_u.GLindex, Libros_u.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 1.4, 1.1);
	glScalef(1.1, 2.4, 0.2);
	prisma2(libro.GLindex, tapa.GLindex, 0, tapa.GLindex, Libros_u.GLindex, Libros_u.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.6, 0.0, 0.7);
	glScalef(1.1, 2.4, 0.2);
	prisma2(libro.GLindex, tapa.GLindex, 0, tapa.GLindex, Libros_u.GLindex, Libros_u.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.6, -1.9, 0.9);
	glScalef(1.1, 2.4, 0.2);
	prisma2(libro.GLindex, tapa.GLindex, 0, tapa.GLindex, Libros_u.GLindex, Libros_u.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, -1.8, 0.7);
	glScalef(1.1, 2.4, 0.2);
	prisma2(libro.GLindex, tapa.GLindex, 0, tapa.GLindex, Libros_u.GLindex, Libros_u.GLindex);
	glPopMatrix();
}*/

/*void Alacena() {
	glTranslatef(-17.3, -1.0, -0.7);
	obj3.prisma(3.4, 1.9, 8.8, t_Madera.GLindex);

	glPushMatrix();
	glTranslatef(-0.7, -1.7, 4.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	obj3.cono(0.5, 0.2, 20.0, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.7, -1.7, -4.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	obj3.cono(0.5, 0.2, 20.0, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, -1.7, 4.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	obj3.cono(0.5, 0.2, 20.0, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, -1.7, -4.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	obj3.cono(0.5, 0.2, 20.0, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, 0.0, 0.0);
	glScalef(0.01, 5.0, 1.6);
	prisma2(t_Madera.GLindex, puerta01.GLindex, t_Madera.GLindex, 0, t_Madera.GLindex, t_Madera.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 4.9, 0.0);
	glScalef(1.0, 12.9, 1.2);
	prisma2(t_Madera.GLindex, Vitrina01.GLindex, t_Madera.GLindex, t_Madera.GLindex, 0, t_Madera.GLindex);
	glPopMatrix();
}*/

void puerta(float movPuerta) {
	glPushMatrix();
		glRotatef(-movPuerta, 0.0, 1.0, 0.0);
		glTranslatef(-5.0, 0.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_puerta.prisma(30.0, 10.0, 0.5, puertabano.GLindex);
	glPopMatrix();
}

/*void tazabano() {
	glPushMatrix();
	
	glPopMatrix();
}*/

void casa() {

	glPushMatrix();
		glTranslatef(0.0, 12.5, 0.0);//p10 paredes traseras
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(5.0, 150.0, 2.0, tablamadera.GLindex, paredpisobajo2.GLindex, 0.0, 0.0, tablamadera2.GLindex, tablamadera2.GLindex);
		
		glPushMatrix();
			glTranslatef(65.0, -15.0, 0.0);//p12
			glColor3f(1.0, 1.0, 1.0);
			fig_casa.prisma5(25.0, 20.0, 2.0, tapiz.GLindex, paredpisobajo.GLindex, tablamadera2.GLindex, tablamadera2.GLindex, 0.0, 0.0);
		
			glTranslatef(-40.0, 0.0, 0.0);//p10
			glColor3f(1.0, 1.0, 1.0);
			fig_casa.prisma5(25.0, 20.0, 2.0, tapiz.GLindex, paredpisobajo.GLindex, tablamadera2.GLindex, tablamadera2.GLindex, 0.0, 0.0);
			
			glPushMatrix();
				glTranslatef(-17.5, 0.0, 0.0);
				glColor3f(1.0, 1.0, 1.0);
				fig_casa.prisma5(25.0, 15.0, 2.0, tapiz.GLindex, paredpisobajo.GLindex, tablamadera2.GLindex, tablamadera2.GLindex, 0.0, 0.0);

				glTranslatef(-12.5, 0.0, 0.0);//ventana
				glColor3f(0.0, 1.0, 1.0);
				//fig_casa.prisma3(25.0, 10.0, 2.0, 0.0, 0.0, 0.0);

				glTranslatef(-12.5, 0.0, 0.0);
				glColor3f(1.0, 1.0, 1.0);
				fig_casa.prisma5(25.0, 15.0, 2.0, tapiz.GLindex, paredpisobajo.GLindex, tablamadera2.GLindex, tablamadera2.GLindex, 0.0, 0.0);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-55.0, 0.0, 0.0);
				glColor3f(1.0, 1.0, 1.0);
				//fig_casa.prisma5(25.0, 10.0, 2.0, tapiz.GLindex, paredpisobajo.GLindex, tablamadera2.GLindex, tablamadera2.GLindex, 0.0, 0.0);

				glTranslatef(-20.0, 0.0, 0.0); //ventana
				glColor3f(1.0, 1.0, 1.0);
				//aqui habia una ventana
				//glDisable(GL_ALPHA_TEST);

				glTranslatef(-20.0, 0.0, 0.0);
				glColor3f(1.0, 1.0, 1.0);
				//fig_casa.prisma5(25.0, 10.0, 2.0, tapiz.GLindex, paredpisobajo.GLindex, tablamadera2.GLindex, tablamadera2.GLindex, 0.0, 0.0);
			glPopMatrix();

			glTranslatef(20.0, -2.5, 0.0);//p13
			glColor3f(1.0, 1.0, 1.0);
			//fig_casa.prisma5(20.0, 20.0, 2.0, tapiz.GLindex, paredpisobajo.GLindex, tablamadera2.GLindex, tablamadera2.GLindex, 0.0, 0.0);

			glTranslatef(0.0, 12.5, 0.0);//p11 ventana
			glColor3f(0.0, 1.0, 1.0);
			//fig_casa.prisma3(5.0, 20.0, 2.0, 0.0, 0.0, 0.0);
		glPopMatrix();
	glPopMatrix();

	/*glPushMatrix();//p3 //paredes cochera
		glTranslatef(76.0, 0.0, 59.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 2.0, 120.0, paredpisobajo4.GLindex, paredpisobajo4.GLindex, tapiz.GLindex, paredpisobajo3.GLindex, 0.0, 0.0);

		glTranslatef(-6.0, 0.0, 59.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 10.0, 2.0, paredpisobajo.GLindex, tapiz.GLindex, tablamadera2.GLindex, 0.0, 0.0, 0.0);

		glTranslatef(-54.5, 0.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 21.0, 2.0, paredpisobajo.GLindex, tapiz.GLindex, tapiz.GLindex, tablamadera2.GLindex, 0.0, 0.0);
	glPopMatrix();*/
	
	/*glPushMatrix();//p2 paredes jardin
		glTranslatef(-76.0, 12.5, 79.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(5.0, 2.0, 160.0, tablamadera2.GLindex, paredpisobajo5.GLindex, paredpisobajo2.GLindex, tablamadera.GLindex, 0.0, tablamadera2.GLindex);

		glPushMatrix(); //paredes jardin
			glTranslatef(0.0, -15.0, -60.0);
			glColor3f(1.0, 1.0, 1.0);
			fig_casa.prisma5(25.0, 2.0, 40.0, tablamadera2.GLindex, paredpisobajo4.GLindex, paredpisobajo.GLindex, tapiz.GLindex, 0.0, 0.0);

			/glEnable(GL_BLEND);
			glTranslatef(0.0, 0.0, 25.0);//ventana
			glColor3f(0.0, 1.0, 1.0);
			//fig_casa.prisma3(25.0, 2.0, 10.0, 0.0, 0.0, 0.0);
			//glDisable(GL_BLEND);
			glTranslatef(0.0, 0.0, 15.0);
			glColor3f(1.0, 1.0, 1.0);
			fig_casa.prisma5(25.0, 2.0, 20.0, tablamadera2.GLindex, tablamadera2.GLindex, paredpisobajo.GLindex, tapiz.GLindex, 0.0, 0.0);

			glTranslatef(0.0, 0.0, 20.0);
			puertadoble(abrir);

			glTranslatef(0.0, 0.0, 20.0);
			glColor3f(1.0, 1.0, 1.0);
			fig_casa.prisma5(25.0, 2.0, 20.0, tablamadera2.GLindex, tablamadera2.GLindex, paredpisobajo.GLindex, tapiz.GLindex, 0.0, 0.0);

			glTranslatef(0.0, 0.0, 15.0);//ventana
			glColor3f(0.0, 1.0, 1.0);
			//fig_casa.prisma3(25.0, 2.0, 10.0, 0.0, 0.0, 0.0);

			glTranslatef(0.0, 0.0, 25.0);
			glColor3f(1.0, 1.0, 1.0);
			fig_casa.prisma5(25.0, 2.0, 40.0, tablamadera2.GLindex, tablamadera2.GLindex, paredpisobajo.GLindex, tapiz.GLindex, 0.0, 0.0);
		glPopMatrix();
	glPopMatrix();*/

	/*glPushMatrix();//paredes interiores
		glTranslatef(-25.0, 0.0, 26.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 2.0, 50.0, tapiz.GLindex, 0.0, 0.0);

		glTranslatef(0.0, 0.0, 65.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 2.0, 30.0, tapiz.GLindex, 0.0, 0.0);

		glTranslatef(0.0, 0.0, 50.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 2.0, 36.0, tapiz.GLindex, 0.0, 0.0);
	glPopMatrix();*/

	/*glPushMatrix();//p4 //paredes frente casa
		glTranslatef(-35.0, 12.5, 160.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(5.0, 84.0, 2.0, paredpisobajo2.GLindex, tablamadera.GLindex, paredpisobajo5.GLindex, paredpisobajo5.GLindex, tablamadera2.GLindex, tablamadera2.GLindex);

		glTranslatef(-36.5, -15.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(25.0, 11.0, 2.0, paredpisobajo.GLindex, tapiz.GLindex, paredpisobajo4.GLindex, tablamadera2.GLindex, 0.0, 0.0);

		glTranslatef(20.5, 0.0, 0.0);//ventana
		glColor3f(0.0, 1.0, 1.0);
		//fig_casa.prisma3(25.0, 30.0, 2.0, 0.0, 0.0, 0.0);

		glTranslatef(20.5, 0.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(25.0, 11.0, 2.0, paredpisobajo.GLindex, tapiz.GLindex, tablamadera2.GLindex, tablamadera2.GLindex, 0.0, 0.0);

		glTranslatef(10.5, 0.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(25.0, 10.0, 2.0, paredpisobajo.GLindex, tapiz.GLindex, tablamadera2.GLindex, tablamadera2.GLindex, 0.0, 0.0);

		glTranslatef(11.0, 0.0, 0.0);//ventana
		glColor3f(0.0, 1.0, 1.0);
		//fig_casa.prisma3(25.0, 12.0, 2.0, 0.0, 0.0, 0.0);

		glTranslatef(11.0, 0.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(25.0, 10.0, 2.0, paredpisobajo.GLindex, tapiz.GLindex, tablamadera2.GLindex, paredpisobajo4.GLindex, 0.0, 0.0);

		glTranslatef(4.0, 2.5, -6.0);//paredes puerta
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 2.0, 10.0, 0.0, tablamadera2.GLindex, tapiz.GLindex, paredpisobajo.GLindex, 0.0, 0.0);

		glTranslatef(0.0, -2.5, -15.0);// puerta
		puertadoble(abrir);

		glTranslatef(0.0, 15.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(5.0, 2.0, 20.0, tablamadera2.GLindex, tablamadera2.GLindex, tapiz2.GLindex, paredpisobajo6.GLindex, tapiz.GLindex, paredpisobajo6.GLindex);

		glTranslatef(0.0, -12.5, -15.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 2.0, 10.0, tablamadera2.GLindex, tablamadera2.GLindex, tapiz.GLindex, paredpisobajo.GLindex, 0.0, 0.0);
	glPopMatrix();*/

	/*glPushMatrix();//paredes interiores 2
		glTranslatef(15.0, 0.0, 41.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 2.0, 80.0, tapiz.GLindex, tablamadera.GLindex, 0.0);

		glTranslatef(0.0, 0.0, 63.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 2.0, 26.0, tapiz.GLindex, 0.0, 0.0);
	glPopMatrix();*/

	/*glPushMatrix();//baño piso 1
		glTranslatef(-5.0, 12.5, 45.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(5.0, 40.0, 2.0, tablamadera2.GLindex, 0.0, tablamadera2.GLindex);

		glTranslatef(5.0, -15.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(25.0, 28.0, 2.0, tapiz.GLindex, 0.0, 0.0);

		glPushMatrix();
			glTranslatef(-14.0, 0.0, 0.0);
			glScalef(1.0, 0.83, 1.0);
			puerta(abrir); //puerta baño abajo
		glPopMatrix();
	glPopMatrix();*/

	/*glPushMatrix(); //techos primer piso
		glTranslatef(-39.0, 16.0, 121.0);
		glColor3f(0.8, 0.8, 0.8);
		fig_casa.prisma3(2.0, 110.0, 80.0, techo2.GLindex, t_Piso.GLindex, techo.GLindex);

		glTranslatef(0.0, 0.0, -97.0);
		glColor3f(0.8, 0.8, 0.8);
		fig_casa.prisma3(2.0, 110.0, 50.0, techo2.GLindex, t_Piso.GLindex, techo.GLindex);

		glTranslatef(-15.0, 0.0, 41.0);
		glColor3f(0.8, 0.8, 0.8);
		fig_casa.prisma3(2.0, 80.0, 32.0, techo2.GLindex, t_Piso.GLindex, techo.GLindex);

		glTranslatef(100.5, 0.0, -6.0);
		glColor3f(0.8, 0.8, 0.8);		
		fig_casa.prisma3(2.0, 61.0, 120.0, techo2.GLindex, t_Piso.GLindex, techo.GLindex);
	glPopMatrix();*/

	/*glPushMatrix();//CALLE <<<<POR REALIZAR
		glTranslatef();
		Calle.prismalargo();
	glPopMatrix();*/
}

void casa2() {

	glPushMatrix();
		glTranslatef(-30.0, 22.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(10.0, 90.0, 2.0, tapiz4.GLindex, clay.GLindex, clay.GLindex, clay.GLindex, tablamadera2.GLindex, tablamadera2.GLindex);

		glPushMatrix();//ventana y muros laterales S1
			glTranslatef(0.0, 10.0, 0.0);
			//glColor3f(0.0, 1.0, 1.0);
			//fig_casa.prisma5(10.0, 70.0, 2.0, 0.0, clay.GLindex, clay.GLindex, clay.GLindex, 0.0, 0.0);
			
			/*glPushMatrix();//ventana
				glTranslatef(40.0, 0.0, 0.0);
				//glColor3f(0.0, 0.7, 0.0);
				fig_casa.prisma5(10.0, 10.0, 2.0, tapiz5.GLindex, clay.GLindex, tablamadera2.GLindex, clay.GLindex, clay.GLindex, clay.GLindex);
			glPopMatrix();*/

			glPushMatrix();
				glTranslatef(-40.0, 0.0, 0.0);
				//glColor3f(0.0, 0.7, 0.0);
				//fig_casa.prisma5(10.0, 10.0, 2.0, tapiz5.GLindex, clay.GLindex, clay.GLindex, tablamadera2.GLindex, clay.GLindex, clay.GLindex);
			glPopMatrix();
		glPopMatrix();

		glTranslatef(0.0, 20.0, 0.0);
		//glColor3f(0.0, 0.4, 0.0);
		//fig_casa.prisma5(10.0, 90.0, 2.0, tapiz5.GLindex, clay.GLindex, clay.GLindex, clay.GLindex, tablamadera2.GLindex, tablamadera2.GLindex);

	glPopMatrix();

	glPushMatrix();
		glTranslatef(-29.5, 22.0, 160.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(10.0, 91.0, 2.0, clay.GLindex, tapiz4.GLindex, clay.GLindex, clay.GLindex, tablamadera2.GLindex, tablamadera2.GLindex);

		glPushMatrix();//ventana y muros laterales S1
			glTranslatef(0.0, 10.0, 0.0);//ventana
			glColor3f(0.0, 1.0, 1.0);
			//fig_casa.prisma3(10.0, 71.0, 2.0, 0.0, 0.0, 0.0);

			glPushMatrix();
				glTranslatef(40.5, 0.0, 0.0);
				glColor3f(1.0, 1.0, 1.0);
				fig_casa.prisma5(10.0, 10.0, 2.0, clay.GLindex, tapiz5.GLindex, tablamadera2.GLindex, clay.GLindex, clay.GLindex, clay.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-40.5, 0.0, 0.0);
				glColor3f(1.0, 1.0, 1.0);
				fig_casa.prisma5(10.0, 10.0, 2.0, clay.GLindex, tapiz5.GLindex, clay.GLindex, tablamadera2.GLindex, clay.GLindex, clay.GLindex);
			glPopMatrix();
		glPopMatrix();

		glTranslatef(0.0, 20.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(10.0, 91.0, 2.0, clay.GLindex, tapiz5.GLindex, clay.GLindex, clay.GLindex, tablamadera2.GLindex, tablamadera2.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-76.0, 32.0, 21.5);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 2.0, 45.0, tablamadera2.GLindex, clay.GLindex, clay.GLindex, tapiz3.GLindex, 0.0, 0.0);

		glTranslatef(0.0, 0.0, 42.5);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 2.0, 20.0, tablamadera2.GLindex, tablamadera2.GLindex, clay.GLindex, tapiz3.GLindex, 0.0, 0.0);

		glTranslatef(0.0, 0.0, 15.0);//ventana
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 2.0, 10.0, vidrioblock.GLindex, vidrioblock.GLindex, vidrioblock.GLindex);

		glTranslatef(0.0, 0.0, 15.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 2.0, 20.0, tablamadera2.GLindex, tablamadera2.GLindex, clay.GLindex, tapiz3.GLindex, 0.0, 0.0);

		glTranslatef(0.0, 0.0, 43.5);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 2.0, 47.0, clay.GLindex, tablamadera2.GLindex, clay.GLindex, tapiz3.GLindex, 0.0, 0.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(16.0, 32.0, 14.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 2.0, 30.0, tablamadera2.GLindex, clay.GLindex, tapiz3.GLindex, clay.GLindex, 0.0, 0.0);

		glTranslatef(0.0, 0.0, 30.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 2.0, 10.0, tablamadera2.GLindex, tablamadera2.GLindex, tapiz3.GLindex, clay.GLindex, 0.0, 0.0);
		
		glTranslatef(0.0, 0.0, 20.0);//ventana
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 1.0, 30.0, ventanaX.GLindex, ventanaX.GLindex, ventanaX.GLindex);

		glTranslatef(0.0, 0.0, 20.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 2.0, 10.0, tablamadera2.GLindex, tablamadera2.GLindex, tapiz3.GLindex, clay.GLindex, 0.0, 0.0);

		glTranslatef(0.0, 0.0, 46.45);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma5(30.0, 2.0, 61.0, clay.GLindex, tablamadera2.GLindex, tapiz3.GLindex, clay.GLindex, 0.0, techo2.GLindex);
	glPopMatrix();

	glPushMatrix(); //paredes internas segundo piso
		glTranslatef(-30.0, 32.0, 25.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 2.0, 48.0, tapiz3.GLindex, 0.0, 0.0);

		glTranslatef(0.0, 0.0, 59.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 2.0, 50.0, tapiz3.GLindex, 0.0, 0.0);

		glTranslatef(0.0, 0.0, 55.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 2.0, 40.0, tapiz3.GLindex, 0.0, 0.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-53.0, 32.0, 100.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 44.0, 2.0, tapiz3.GLindex, 0.0, 0.0);

		glTranslatef(5.0, 0.0, -40.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 34.0, 2.0, tapiz3.GLindex, 0.0, 0.0);

		glPushMatrix();
			glTranslatef(-17.0, 0.0, 0.0); 
			glColor3f(0.2, 0.0, 0.0);
			
			puerta(abrir);//puerta baño superior
			//fig_casa.prisma3(30.0, 10.0, 2.0, 0.0, 0.0, 0.0);
			glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.0, 32.0, 48.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(30.0, 34.0, 2.0, tapiz3.GLindex, 0.0, 0.0);

		glTranslatef(-22.0, 0.0, 0.0); //puerta recamara 2
		glColor3f(1.0, 1.0, 1.0);
		//fig_casa.prisma3(30.0, 10.0, 2.0, 0.0, 0.0, 0.0);
	glPopMatrix();

	//Techo
	glPushMatrix();
		glTranslatef(-30.0, 48.0, 80.0);
		glColor3f(0.3, 0.3, 0.3);
		fig_casa.prisma3(2.0, 100.0, 162.0, techo2.GLindex, techo3.GLindex, techo.GLindex);
	glPopMatrix();

	glPushMatrix();//barandal derecha
		glTranslatef(47.0, 22.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(10.0, 60.2, 0.3, barandal.GLindex, tablamadera2.GLindex, 0.0);
	
		glTranslatef(29.5, 0.0, 59.5);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(10.0, 0.3, 119.2, barandal.GLindex, tablamadera2.GLindex, 0.0);

		glPushMatrix();//barandales ala izq
			glTranslatef(-170.0, 0.0, 20.0);
			glColor3f(1.0, 1.0, 1.0);
			fig_casa.prisma3(10.0, 0.3, 160.0, barandal3.GLindex, tablamadera2.GLindex, 0.0);
			
			glPushMatrix();
				glTranslatef(8.0, 0.0, 80.0);
				glColor3f(1.0, 1.0, 1.0);
				fig_casa.prisma3(10.0, 17.0, 0.3, barandal2.GLindex, tablamadera2.GLindex, 0.0);
			glPopMatrix();
			
			glPushMatrix();
				glTranslatef(8.0, 0.0, -80.0);
				glColor3f(1.0, 1.0, 1.0);
				fig_casa.prisma3(10.0, 17.0, 0.3, barandal2.GLindex, tablamadera2.GLindex, 0.0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//postes
			glTranslatef(-170.0, -22.0, 100.0);
			glColor3f(1.0, 1.0, 1.0);
			fig_casa.prisma3(30.0, 1.0, 1.0, tablamadera2.GLindex, 0.0, 0.0);

			glTranslatef(0.0, 0.0, -53.0);
			glColor3f(1.0, 1.0, 1.0);
			fig_casa.prisma3(30.0, 1.0, 1.0, tablamadera2.GLindex, 0.0, 0.0);

			glTranslatef(0.0, 0.0, -53.0);
			glColor3f(1.0, 1.0, 1.0);
			fig_casa.prisma3(30.0, 1.0, 1.0, tablamadera2.GLindex, 0.0, 0.0);

			glTranslatef(0.0, 0.0, -53.0);
			glColor3f(1.0, 1.0, 1.0);
			fig_casa.prisma3(30.0, 1.0, 1.0, tablamadera2.GLindex, 0.0, 0.0);
		glPopMatrix();

		glTranslatef(-30.0, 0.0, 59.0);
		glColor3f(1.0, 1.0, 1.0);
		fig_casa.prisma3(10.0, 59.8, 0.3, barandal.GLindex, tablamadera2.GLindex, 0.0);
	glPopMatrix();
}

/*void aguila() {
	glTranslatef(0.0 + batmovX , 300.0, 0.0 + batmovZ);
	glRotatef(0.0 + batrotX, 0.0 , 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	faguila.prisma3(0.1, 20.0, 20.0, transparencia.GLindex, transparencia.GLindex, eagle.GLindex);
}*/

void picina() {
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(-160.0, -7.8, 75.0);
	glPushMatrix();
		glTranslatef(0.0, -10.5, -7.5);
		glColor3f(1.0, 1.0, 1.0);
		fig_picina.prisma55(20.0, 50.0, 100.0, pisobano2.GLindex, pisobano2.GLindex, pisobano2.GLindex, pisobano2.GLindex, aguapicina.GLindex, pisobano2.GLindex);

		glPushMatrix();
			glTranslatef(0.0, 10.5, 52.5);
			glColor3f(1.0, 1.0, 1.0);
			fig_picina.prisma3(1.5, 60.0, 5.0, pisobano2.GLindex, pisobano2.GLindex, pisobano2.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0, 10.5, -52.5);
			glColor3f(1.0, 1.0, 1.0);
			fig_picina.prisma3(1.5, 60.0, 5.0, pisobano2.GLindex, pisobano2.GLindex, pisobano2.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(27.5, 10.5, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			fig_picina.prisma3(1.5, 5.0, 100.0, pisobano2.GLindex, pisobano2.GLindex, pisobano2.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-27.5, 10.5, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			fig_picina.prisma3(1.5, 5.0, 100.0, pisobano2.GLindex, pisobano2.GLindex, pisobano2.GLindex);
		glPopMatrix();

	glPopMatrix();
	glPopMatrix();

}

/*void escaleras() {
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(-7.0, -10.5, 65.5);
	glScalef(1.4, 1.9, 1.55);
	glPushMatrix();						// ESCALERA
	glScalef(1.0, 2.5, 1.0);
	glTranslatef(0.0, -1.0, -10.0);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(2.5, 0.6, 0.0);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(2.5, 0.6, 0.0);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(2.5, 0.6, 0.0);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(2.5, 0.6, 0.0);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPushMatrix();
	glScalef(2.5, 1.0, 1.0);
	glTranslatef(1.0, 0.6, 0.0);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();						// ESCALERA
	glRotatef(-90.0, 0.0, 1.0, 0.0);
	glScalef(1.0, 2.5, 1.0);
	glTranslatef(-6.0, 2.5, -12.5);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(2.5, 0.6, 0.0);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(2.5, 0.6, 0.0);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(2.5, 0.6, 0.0);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(2.5, 0.6, 0.0);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPushMatrix();
	glScalef(3.0, 1.0, 1.0);
	glTranslatef(1.0, 0.6, 0.0);
	prisma(techo2.GLindex, techo2.GLindex, techo2.GLindex, techo2.GLindex, techo.GLindex, techo.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();						// GUIA
	glTranslatef(12.5, 9.0, -1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(30.0, 0.0, 0.0, 1.0);
	glScalef(10.0, 0.1, 0.2);
	prisma(t_metal2.GLindex, 0, t_metal2.GLindex, 0, t_metal2.GLindex, t_metal2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.0, 1.0, -10.0);
	glRotatef(30.0, 0.0, 0.0, 1.0);
	glScalef(8.0, 0.1, 0.2);
	prisma(t_metal2.GLindex, 0, t_metal2.GLindex, 0, t_metal2.GLindex, t_metal2.GLindex);
	glPopMatrix();
	glPopMatrix();
}*/

void ventana() {
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glTranslatef(-76.8, -2.0, 114.0);
	glColor3f(1.0, 1.0, 1.0);
	fig_casa.prisma(26.0, 0.1, 11.0, ventanaX3.GLindex);

	glTranslatef(0.0, 0.0, -70.0);
	glColor3f(1.0, 1.0, 1.0);
	fig_casa.prisma(26.0, 0.1, 11.0, ventanaX3.GLindex);
	glPopMatrix();

	glPushMatrix(); //ventana trasera
	glTranslatef(-50.0, -2.5, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	fig_casa.prisma(25.0, 30.0, 0.1, ventanaX.GLindex);
	glPopMatrix();

	glPushMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-51.0, -2.5, 160.0);
	glColor3f(1.0, 1.0, 1.0);
	fig_casa.prisma(25.0, 30.0, 0.1, ventanaX.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9.0, -2.5, 160.0);
	glColor3f(1.0, 1.0, 1.0);
	fig_casa.prisma(25.0, 12.0, 0.1, ventanaX2.GLindex);
	glPopMatrix();

	glPushMatrix();//baño
	glTranslatef(-5.0, -2.5, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	fig_casa.prisma(25.0, 10.0, 2.0, vidrioblock.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(45.0, 7.5, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	fig_casa.prisma(5.0, 20.0, 0.1, ventanaX2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-50.0, -2.5, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	fig_casa.prisma(25.0, 30.0, 0.1, ventanaX.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30.0, 32.0, 0.0);
	fig_casa.prisma3(10.0, 70.0, 0.5, glass.GLindex, glass.GLindex, glass.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-29.5, 32.0, 160.0);
	fig_casa.prisma3(10.0, 70.0, 0.5, glass.GLindex, glass.GLindex, glass.GLindex);
	glPopMatrix();

	glEnable(GL_LIGHTING);
}

void display ( void )										// Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	

	glPushMatrix();
		glRotatef(CamaraUpDn, 1.0, 0.0, 0.0);
		gluLookAt(vistaCamara.mPos.x, vistaCamara.mPos.y, vistaCamara.mPos.z,
					vistaCamara.mView.x, vistaCamara.mView.y, vistaCamara.mView.z,
					vistaCamara.mUp.x, vistaCamara.mUp.y, vistaCamara.mUp.z);

/*###########################################################################################################*/
/*----------------------------------------------------- SKYBOX ----------------------------------------------*/
/*###########################################################################################################*/
		glDisable(GL_LIGHTING);

		picina();

			glPushMatrix();
				glTranslatef(0.0, 150.0, 0.0);
				skybox.skybox(2000.0, 2000.0, 2000.0, Skybox_ft.GLindex, Skybox_bk.GLindex, Skybox_lf.GLindex, Skybox_rt.GLindex, Skybox_up.GLindex, Skybox_dn.GLindex);
			glPopMatrix();


			//piso de la casa
			glPushMatrix();
				//glTranslatef(-35.0, -8.5, 80);
				fig_casa.prisma3(1.0, 81.0, 67.0, techo2.GLindex, t_Piso.GLindex, 0.0);//PISO_1
				//glTranslatef(47.0, 0.0, -21.0);
				//fig_casa.prisma3(1.0, 10.0, 120, techo2.GLindex, t_Piso.GLindex, 0.0);
				//glTranslatef(35.0, 0.0, 0.0);
				//fig_casa.prisma6(1.0, 60.0, 120, techo2.GLindex, domino.GLindex, 0.0, 2.0);
				//piso baños
				//glTranslatef(-52.0, 0.1, -35.6);
				//fig_casa.prisma6(1.0, 40.0, 45, techo2.GLindex, pisobano.GLindex, 0.0, 2.0);
				//glTranslatef(-48.0, 32.0, 57.0);
				//fig_casa.prisma6(1.0, 45, 40, techo2.GLindex, pisobano.GLindex, 0.0, 2.0);
			glPopMatrix();

			//SUELO (CESPED)
			// ESTA COMENTADO PARA VER EL MODELO DE LA CASA, DESPUES SE TRASLADARA PARA	QUE EMBONEN
			glPushMatrix();
				glTranslatef(0.0, -10.0, 0.0);
				skybox.skybox2(3.0, 1000.0, 1000.0, 100.0, cesped.GLindex, tierra.GLindex);
			glPopMatrix();
			
/*#############################################################################################################*/
/*---------------------------------------- MODELO   CASA   ----------------------------------------------------*/
/*#############################################################################################################*/

			glPushMatrix();
				glTranslatef(0.0, 7.0, 0.0);
				//glScalef(0.1, 0.1, 0.1);
				casa();
				casa2();
				//escaleras();
				
				//Sala();
				//Comedor();
				//Cocina1();
				//Fregadero();
				
				glPushMatrix();
				glTranslatef(2,23,7);
				glScalef(3, 2, 2);
				glRotatef(-90.0, 0.0, 1.0, 0.0);
				//Cama();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-62, 23, 10);
				glScalef(3, 2, 3);
				glRotatef(90.0, 0.0, 1.0, 0.0);
				//Cama();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-66, 23, 150);
				glScalef(2, 2, 3);
				glRotatef(90.0, 0.0, 1.0, 0.0);
				//Cama();
				glPopMatrix();
				
				glPushMatrix();
				glTranslatef(2.4, 26, 152);
				glScalef(1, 3, 2);
				glRotatef(-90.0, 0.0, 1.0, 0.0);
				//LibreroC();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-49,23,23);
				glScalef(1,2,2);
				glRotatef(-180.0, 0.0, 1.0, 0.0);
				//Alacena();
				glPopMatrix();
				
				glPushMatrix();
				glTranslatef(70.0, -25.0, -50.0);
				glRotatef(90.0, 0.0, 1.0, 0.0);
				//bosque();
				glTranslatef(0.0, 0.0, -200.0);
				//bosque();
				glTranslatef(0.0, 0.0, -300.0);
				//bosque();
				glPopMatrix();
				
				glPushMatrix();
				//aguila();
				glPopMatrix();

				ventana();
				
				/*glPushMatrix();
				glEnable(GL_LIGHTING);
				glLightfv(GL_LIGHT0, GL_POSITION, CarroPosition);
				glTranslatef(46,-15,45);
				glScalef(12, 12, 12);
				glTranslatef(pX, pY, pZ);
				glRotatef(rot, 0.0, 1.0, 0.0);
				carro.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();*/
				//tazabano();
				


				glColor3f(1.0, 1.0, 1.0);
			glPopMatrix();

/*##############	###############################################################################################*/
/*----------------------------------------CODIGO DE ESTEBAN----------------------------------------------------*/
/*#############################################################################################################*/

/*
//SALA
	glPushMatrix();						// MESSA CENTRAL
	glTranslatef(0.0, -1.3, 0.0);
		glScalef(1.5, 0.6, 1.0);
		Mesa();
	glPopMatrix();
	
	glPushMatrix();						// SILLON 3
		glTranslatef(0.0, -1.8, -6.0);
		Sillon();
	glPopMatrix();
	
	glPushMatrix();						// SILLON 2
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(0.8, 1.0, 1.0);
		glTranslatef(0.0, -1.8, -8.0);
		Sillon();
	glPopMatrix();

	glPushMatrix();						// SILLON 1
		glRotatef(180, 0.0, 1.0, 0.0);
		glScalef(0.4, 1.0, 0.8);
		glTranslatef(2.0, -1.8, -8.0);
		Sillon();
	glPopMatrix();
	
	glPushMatrix();						// CENTRO DE ENTRETENIMIENTO
		glTranslatef(14.0, -3.0, 0.0);
		MuebleTV();
	glPopMatrix();

	glPushMatrix();						// MESA ESQUINA
		glTranslatef(-7.0, 0.05, 6.0);
		glScalef(0.6, 1.05, 1.0);
		Mesa();
	glPopMatrix();
	
	glPushMatrix();						// PISO
		glScalef(15.0, 0.1, 5.0);
		glTranslatef(0.0, -31.0, 0.0);
		prisma(0, 0, 0, 0, 0, t_Piso.GLindex);
	glPopMatrix();
	*/
	
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
		//renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Proyecto Final");
		//renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Alpha Ver 0.1.0");
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
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 2200.0);

	glMatrixMode(GL_MODELVIEW);								// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	fig_picina.text_izq -= 0.001;
	fig_picina.text_der -= 0.001;
	if (fig_picina.text_izq < -1)
		fig_picina.text_izq = 0;
	if (fig_picina.text_der < 0)
		fig_picina.text_der = 1;
///////////////////////////////////////////////// PUERTAS ////////////////////////////////////////////////////////////////////
	if (puertaentrada && abrir2 == 0.0) {
		if (abrir < 90.0) {
			abrir += 1.0;
		}
		else
		{
			abrir = 90.0;
			abrir2 = 1.0;
			puertaentrada = false;
		}
	}

	if (puertaentrada && abrir2 == 1.0) {
		if (abrir > 0.0) {
			abrir -= 1.0;
		}
		else {
			abrir == 0.0;
			abrir2 = 0.0;
			puertaentrada = false;
		}
	}

//////////////////////////////////////////// AUNTOMOVIL ////////////////////////////////////////////////////////////////////
	/*if (arranca == true) {
		pZ += 0.1;

		if (pZ >= 17) {
			arranca = false;
			ruta1 = true;
		}
	}

	if (ruta1 == true) {
		pZ += 0.1;
		rot += 0.5;

		if (pZ >= 35) {
			ruta1 = false;
			ruta2 = true;
		}
	}

	if (ruta2 == true) {
		pX += 0.1;

		if (pX >= 15) {
			ruta2 = false;
			ruta3 = true;
		}
	}

	if (ruta3 == true) {
		pX += 0.1;
		rot += 0.5;

		if (pX >= 35) {
			ruta3 = false;
			ruta4 = true;
		}
	}

	if (ruta4 == true) {
		pZ -= 0.1;
		rot -= 0.5;

		if (rot == 180) {
			ruta4 = false;
			ruta5 = true;
		}
	}

	if (ruta5 == true) {
		pZ -= 0.1;

		if (pZ <= -20) {
			ruta5 = false;
			ruta6 = true;
		}
	}

	if (ruta6 == true) {
		pZ -= 0.1;
		rot += 0.5;

		if (pZ <= -40) {
			ruta6 = false;
			ruta7 = true;
		}
	}

	if (ruta7 == true) {
		pX -= 0.1;
		rot -= 0.5;

		if (rot == 270) {
			ruta7 = false;
			ruta8 = true;
		}
	}

	if (ruta8 == true) {
		pX -= 0.1;

		if (pX <= -20) {
			ruta8 = false;
			ruta9 = true;
		}
	}

	if (ruta9 == true) {
		pX -= 0.1;
		rot += 0.5;

		if (pX <= -40) {
			ruta9 = false;
			ruta10 = true;
		}
	}

	if (ruta10 == true) {
		pZ += 0.1;
		rot -= 0.5;

		if (rot == 360) {
			ruta10 = false;
			ruta11 = true;
		}
	}

	if (ruta11 == true) {
		pZ += 0.1;

		if (pZ >= 20) {
			ruta11 = false;
			ruta12 = true;
		}
	}

	if (ruta12 == true) {
		pZ += 0.1;
		rot += 0.5;

		if (pZ >= 35) {
			ruta12 = false;
			ruta13 = true;
		}
	}

	if (ruta13 == true) {
		pX += 0.1;
		pZ -= 0.04;
		rot += 0.5;

		if (rot >= 480) {
			ruta13 = false;
			ruta14 = true;
		}
	}

	if (ruta14 == true) {
		pX += 0.1;
		pZ -= 0.04;

		if (pZ <= 26) {
			ruta14 = false;
			ruta15 = true;
		}
	}

	if (ruta15 == true) {
		pX += 0.1;
		pZ -= 0.04;
		rot -= 0.5;

		if (rot == 360) {
			ruta15 = false;
		}
	}*/
///////////////////////////////////////////////// AGUILA /////////////////////////////////////////////////////////////////
	/*if (inicia == true) {
		batmovX -= 0.5;
		batmovZ -= 0.4;
		printf("0");
		if (batmovX <= -219 || batmovZ <= -219) {
			inicia = false;
			vuelo1 = true;
		}
	}

	if (vuelo1 == true) {
		batmovX += 0.5;
		batmovZ -= 0.6;
		printf("1");
		if (batmovZ <= -245) {
			vuelo1 = false;
			vuelo2 = true;
		}
	}

	if (vuelo2 == true) {
		batmovX += 0.5;
		batmovZ += 0.3;
		printf("2");
		if (batmovX >= 192) {
			vuelo2 = false;
			vuelo3 = true;
		}
	}

	if (vuelo3 == true) {
		batmovX += 0.2;
		batmovZ += 0.6;
		printf("3");
		if (batmovZ >= -88) {
			vuelo3 = false;
			vuelo4 = true;
		}
	}

	if (vuelo4 == true) {
		batmovX -= 0.1;
		batmovZ += 0.2;
		printf("4");
		if (batmovZ >= 122) {
			vuelo4 = false;
			vuelo5 = true;
		}
	}

	if (vuelo5 == true) {
		batmovX -= 1.0;
		batmovZ += 0.8;
		printf("5");
		if (batmovX <= 193) {
			vuelo5 = false;
			vuelo6 = true;
		}
	}

	if (vuelo6 == true) {
		batmovX -= 0.1;
		batmovZ += 1.2;
		printf("6");
		if (batmovZ >= 258) {
			vuelo6 = false;
			vuelo7 = true;
		}
	}

	if (vuelo7 == true) {
		batmovX -= 0.1;
		batmovZ += 2.5;
		printf("7");
		if (batmovZ >= 300) {
			vuelo7 = false;
			vuelo8 = true;
		}
	}

	if (vuelo8 == true) {
		batmovX -= 0.1;
		printf("8");
		if (batmovX <= 18) {
			vuelo8 = false;
			vuelo9 = true;
		}
	}

	if (vuelo9 == true) {
		batmovX -= 0.5;
		batmovZ -= 3;
		printf("9");
		if (batmovZ<= 153) {
			vuelo9 = false;
			vuelo10 = true;
		}
	}

	if (vuelo10 == true) {
		batmovX -= 0.5;
		batmovZ += 5;
		printf("A");
		if (batmovZ >= 228) {
			vuelo10 = false;
			vuelo11 = true;
		}
	}

	if (vuelo11 == true) {
		batmovX -= 1.0;
		batmovZ += 2.0;
		printf("B");
		if (batmovZ >= 267) {
			vuelo11 = false;
			vuelo12 = true;
		}
	}

	if (vuelo12 == true) {
		batmovX += 3.0;
		batmovZ -= 0.5;
		printf("C");
		if (batmovZ >= 225) {
			vuelo12 = false;
			vuelo13 = true;
		}
	}

	if (vuelo13 == true) {
		batmovX += 1.0;
		batmovZ -= 1.0;
		printf("D");
		if (batmovZ <= 175) {
			vuelo13 = false;
			vuelo14 = true;
		}
	}

	if (vuelo14 == true) {
		batmovX -= 1.0;
		batmovZ += 4.0;
		printf("E");
		if (batmovX <= 165) {
			vuelo14 = false;
			vuelo15 = true;
		}
	}

	if (vuelo15 == true) {
		batmovX -= 4.0;
		batmovZ -= 4.0;
		batmovY -= 4.0;
		printf("F");
		if (batmovY < -10) {
			vuelo15 = false;
		}
	}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*if (play)
	{
		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex)	//end of total animation?
			{
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				//interpolation();
			}
		}
		else
		{
			//Draw animation
			batmovX += KeyFrame[playIndex].incX;
			batmovY += KeyFrame[playIndex].incY;
			batmovZ += KeyFrame[playIndex].incZ;
			batrotX += KeyFrame[playIndex].incmovX;
			batrotY += KeyFrame[playIndex].incmovY;
			batrotZ += KeyFrame[playIndex].incmovZ;
			i_curr_steps++;
		}
	}*/

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )			// Create Keyboard Function
{
	switch ( key ) {
		case 'w':											//Movimientos de camara
		case 'W':
			vistaCamara.Move_Camera((CAMERASPEED + 1.0));
			break;

		case 's':
		case 'S':
			vistaCamara.Move_Camera(-(CAMERASPEED + 1.0));
			break;

		case 'a':
		case 'A':
			vistaCamara.Strafe_Camera(-(CAMERASPEED + 1.0));
			break;
		case 'd':
		case 'D':
			vistaCamara.Strafe_Camera((CAMERASPEED + 1.0));
			break;

		case '0':
			//Vista de Prueba
			vistaCamara.Position_Camera(87.757614, 83.599960, 113.741035,
										87.168472, 83.599960, 112.933029,
										0.0, 1.0, 0.0);
			CamaraUpDn = 26.0;
		break;

		case '1':
			//Vista de Frente
			vistaCamara.Position_Camera(-18.0, 1.0, 251.0,
										-18.0, 1.0, 250.0,
										0.0, 1.0, 0.0);
			CamaraUpDn = 0.0;
		break;

		case '2':
			//Cuarto
			vistaCamara.Position_Camera(-36.28, 6.69, 69.32,
										-36.69, 6.69, 69.98,
										0.0, 8.0, 0.0);
			CamaraUpDn = 0.0;
		break;

		case '3':
			//Vista isometrica
			vistaCamara.Position_Camera(86.06, 89.4, 223.44,
										-21.28, 89.4, 53.48,
										0.0, 1.0, 0.0);
			CamaraUpDn = 26.0;
		break;

		case '4':
			//Vista alberca
			vistaCamara.Position_Camera(-206.05, 5.4, 118.2,
										-204.85, 5.4, 117.7,
										0.0, 1.0, 0.0);
			CamaraUpDn = 9.0;
		break;

		case 'o':
		case 'O':
			puertaentrada ^= true;
		break;

		case 'I':
		case 'i':
			arranca ^= true;
			break;

		case 'K':
		case 'k':
			inicia ^= true;
			break;

		case 'u':
			puertabano1 ^= true;
			break;

		case 'U':
			puertabano1c ^= true;
			break;

		case 'b':
			batmovX += 0.1;
			break;
		case 'n':
			batmovX -= 0.1;
			break;
		case 'm':
			batmovZ += 0.1;
			break;
		case 'j':
			batmovZ -= 0.1;
			break;


		/*######################################################*/
		/*////////////Imprimir valores para Debugear////////////*/
		/*######################################################*/
		case 'P':
		case 'p':
			printf("batmovX %f\n", batmovX);
			printf("batmovZ %f\n", batmovZ);
			///printf("batrotX %f\n", batrotX);
			//printf("tam %f\n", tam);
			//printf("tam2 %f\n", tam2);
			//printf("tam3 %f\n", tam3);
			//Para poner las vistas de camara
			
			/*printf("vistaCamara.mPos.x %f\n",vistaCamara.mPos.x);
			printf("vistaCamara.mPos.y %f\n", vistaCamara.mPos.y);
			printf("vistaCamara.mPos.z %f\n", vistaCamara.mPos.z);
			printf("vistaCamara.mView.x %f\n", vistaCamara.mView.x);
			printf("vistaCamara.mView.y %f\n", vistaCamara.mView.y);
			printf("vistaCamara.mView.z %f\n", vistaCamara.mView.z);
			printf("vistaCamara.mUp.x %f\n", vistaCamara.mUp.x);
			printf("vistaCamara.mUp.y %f\n", vistaCamara.mUp.y);
			printf("vistaCamara.mUp.z %f\n", vistaCamara.mUp.z);
			printf("CamaraUpDn %f\n\n", CamaraUpDn);*/
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
		vistaCamara.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		vistaCamara.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:										// Presionamos tecla ARRIBA...
		CamaraUpDn -= 1.0f;
		break;

    case GLUT_KEY_DOWN:										// Presionamos tecla ABAJO...
		CamaraUpDn += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		vistaCamara.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		vistaCamara.Rotate_View(CAMERASPEED);
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
  //glBlendFunc(GL_SRC_uj
  glutInitWindowSize  (5000, 5000);							// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);							//Posicion de la Ventana
  glutCreateWindow    ("Proyecto Final - Casa");			// Nombre de la Ventana
  glutFullScreen     ( );									// Full Screen
  InitGL ();												// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );							//Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );							//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );							//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );						//Otras
  glutIdleFunc		  ( animacion );
  PlaySound(TEXT("sonidos/bosque.wav"), NULL, SND_LOOP || SND_SYNC);
  glutMainLoop        ( );

  return 0;
}