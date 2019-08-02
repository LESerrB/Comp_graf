//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Func�on creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Func�on creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Func�on creacion cono
	void prisma_anun (GLuint text, GLuint text2);							//Func�on creacion movimiento
	void trianguloRect(float altura, float largo, float profundidad, GLuint text, GLuint text2);//Funcion creacion triangulo 90�
	void piramideRect(float altura, float largo, float profundidad, GLuint text);//Funcion piramide cuadrada 90�
	void prisma (float altura, float largo, float profundidad, GLuint text);//Func�on creacion prisma
	void prisma2 (float altura, float largo, float profundidad, GLuint text, GLuint text2);
	void prisma3(float altura, float largo, float profundidad, GLuint Contorno, GLuint Top, GLuint Bottom);
	void prisma4(float altura, float largo, float profundidad, GLuint Frente, GLuint Atras, GLuint Izq, GLuint Der);
	void prisma5(float altura, float largo, float profundidad, GLuint Frente, GLuint Atras, GLuint Izq, GLuint Der, GLuint Arriba, GLuint Abajo);
    void prisma6(float altura, float largo, float profundidad, GLuint text, GLuint text1, GLuint text2, GLuint text3);
	void prisma7(float altura, float largo, float profundidad, GLuint Frente, GLuint Atras, GLuint Izq, GLuint Der, GLuint Arriba, GLuint Abajo);
	void prisma8(float altura, float largo, float profundidad, GLuint Frente, GLuint Atras, GLuint Izq, GLuint Der, GLuint Arriba, GLuint Abajo);
	void skybox(float largo, float altura, float profundidad, GLuint Front, GLuint Back, GLuint Left, GLuint Right, GLuint Top, GLuint Bottom);	//Funcion creacion cielo
	void skybox2(float altura, float largo, float profundidad, float num_texturas, GLuint text, GLuint text2);
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);
	void medioCilindro(float radio, float altura, int resolucion, GLuint text, GLuint text2);
	void circuContor(float radio, float altura, int resolucion, GLuint text);
	void terCilindro(float radio, float altura, int resolucion, GLuint text);
	void circuContor(float radio, float altura, int resolucion, GLuint text, GLuint text2);
	void terCilindro(float radio, float altura, int resolucion, GLuint text, GLuint text2);
	void cuartoCilindro(float radio, float altura, int resolucion, GLuint text, GLuint text2);
	void cilindromitad(float radio, float altura, int resolucion, GLuint text); //Funcion creacion mitad de un cilindro
	void cilindrocuarto(float radio, float altura, int resolucion, GLuint text); //Funcion creacion mitad de un cilindro


};
