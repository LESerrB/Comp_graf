//Semestre 2018 - II ******************************************//
//*************************************************************//
//*************************************************************//
//************** Alumno (s): **********************************//
//************************** Serrano Bermúdez Luis Ezsteban	***//
//************** Versión Visual Studio: ***********************//
//************************** VS 2015 14.0.25431.01 ************//
#include "Main.h"
void InitGL(GLvoid)     // Inicializamos parametros
{
//glShadeModel(GL_FLAT);								// Habilitamos Smooth Shading
	glClearColor(0.796875f, 0.57421875f, 0.9765625f, 0.0f);// Fondo
														// glClearDepth(1.0f);			Configuramos Depth Buffer
														// glEnable(GL_DEPTH_TEST);		Habilitamos Depth Testing
														// glDepthFunc(GL_LEQUAL);		Tipo de Depth Testing a realizar


}

void display(void)										// Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

														// Poner aqui codigo ha dibujar
														// glut permite crear interfaz grafica
														// glloadidentity crear matriz identidad / deja todo como estaba inicialmente
														// pixel:unidad minima de una representacion grafica
	glPointSize(1.0);									// TAMANO DE PUNTO (MULTIPLICA PIXEL * 10)

/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.1093, 0.1054, 0.0898);

		glVertex3f(856.0, 689.0, -1.2);	//PTO-I
		glVertex3f(870.0, 670.0, -1.2);	//PTO-1
		glVertex3f(855.0, 673.0, -1.2);	//PTO-2
		glVertex3f(810.0, 681.0, -1.2);	//PTO-3
		glVertex3f(761.0, 685.0, -1.2);	//PTO-4
		glVertex3f(739.0, 687.0, -1.2);	//PTO-5
		glVertex3f(770.0, 699.0, -1.2);	//PTO-6
		glVertex3f(827.0, 696.0, -1.2);	//PTO-7
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.1093, 0.1054, 0.0898);
	
		glVertex3f(761.0, 685.0, -1.2);	//PTO-I
		glVertex3f(810.0, 681.0, -1.2);	//PTO-1
		glVertex3f(836.0, 669.0, -1.2);	//PTO-2
		glVertex3f(842.0, 657.0, -1.2);	//PTO-3
		glVertex3f(771.0, 673.0, -1.2);	//PTO-4
		glVertex3f(767.0, 661.0, -1.2);	//PTO-5
		glVertex3f(772.0, 630.0, -1.2);	//PTO-6
		glVertex3f(733.0, 672.0, -1.2);	//PTO-7
		glVertex3f(739.0, 687.0, -1.2);	//PTO-8
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.1093, 0.1054, 0.0898);

		glVertex3f(793.0, 643.0, -1.2);	//PTO-I
		glVertex3f(767.0, 661.0, -1.2);	//PTO-1
		glVertex3f(772.0, 630.0, -1.2);	//PTO-2
		glVertex3f(778.0, 601.0, -1.2);	//PTO-3
		glVertex3f(783.0, 595.0, -1.2);	//PTO-4
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0, 1.0, 1.0);

		glVertex3f(802.0, 576.0, -1.2);	//PTO-I
		glVertex3f(795.0, 576.0, -1.2);	//PTO-1
		glVertex3f(783.0, 595.0, -1.2);	//PTO-2
		glVertex3f(784.0, 605.0, -1.2);	//PTO-3
		glVertex3f(778.0, 601.0, -1.2);	//PTO-4
		glVertex3f(783.0, 595.0, -1.2);	//PTO-5
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.1601f, 0.1601f, 0.1523f);
		
		glVertex3f(764.0, 242.0, -1.2);	//PTO-I
		glVertex3f(531.0, 198.0, -1.2);	//PTO-1
		glVertex3f(361.0, 182.0, -1.2);	//PTO-2
		glVertex3f(371.0, 212.0, -1.2);	//PTO-3
		glVertex3f(286.0, 236.0, -1.2);	//PTO-4
		glVertex3f(531.0, 300.0, -1.2);	//PTO-5
		glVertex3f(850.0, 420.0, -1.2);	//PTO-6
		glVertex3f(867.0, 447.0, -1.2);	//PTO-7
		glVertex3f(882.0, 447.0, -1.2);	//PTO-8
		glVertex3f(919.0, 425.0, -1.2);	//PTO-9
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.1601f, 0.1601f, 0.1523f);
	
		glVertex3f(531.0, 300.0, -1.2);	//PTO-I
		glVertex3f(286.0, 236.0, -1.2);	//PTO-1
		glVertex3f(377.0, 289.0, -1.2);	//PTO-2
		glVertex3f(787.0, 450.0, -1.2);	//PTO-3
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.1093, 0.1054, 0.0898);

		glVertex3f(960.0, 530.0, -1.2);	//PTO-I
		glVertex3f(938.0, 432.0, -1.2);	//PTO-1
		glVertex3f(930.0, 435.0, -1.2);	//PTO-2
		glVertex3f(919.0, 425.0, -1.2);	//PTO-3
		glVertex3f(882.0, 447.0, -1.2);	//PTO-4
		glVertex3f(867.0, 447.0, -1.2);	//PTO-5
		glVertex3f(880.0, 469.0, -1.2);	//PTO-6
		glVertex3f(892.0, 585.0, -1.2);	//PTO-7
		glVertex3f(908.0, 629.0, -1.2);	//PTO-8
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.1601, 0.1601, 0.1601);

		glVertex3f(939.0, 628.0, -1.2);	//PTO-I
		glVertex3f(941.0, 565.0, -1.2);	//PTO-1
		glVertex3f(908.0, 629.0, -1.2);	//PTO-2
		glVertex3f(868.0, 670.0, -1.2);	//PTO-3
		glVertex3f(856.0, 689.0, -1.2);	//PTO-4
		glVertex3f(896.0, 689.0, -1.2);	//PTO-5
		glVertex3f(916.0, 681.0, -1.2);	//PTO-6
		glVertex3f(925.0, 688.0, -1.2);	//PTO-7
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f, 1.0f, 1.0f);

		glVertex3f(850.0, 420.0, -1.2);	//PTO-I
		glVertex3f(530.0, 300.0, -1.2);	//PTO-1
		glVertex3f(787.0, 450.0, -1.2);	//PTO-2
		glVertex3f(788.0, 466.0, -1.2);	//PTO-3
		glVertex3f(814.0, 492.0, -1.2);	//PTO-4
		glVertex3f(849.0, 506.0, -1.2);	//PTO-5
		glVertex3f(882.0, 468.0, -1.2);	//PTO-6
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f, 1.0f, 1.0f);

		glVertex3f(892.0, 585.0, -1.2);	//PTO-I
		glVertex3f(882.0, 468.0, -1.2);	//PTO-1
		glVertex3f(849.0, 506.0, -1.2);	//PTO-2
		glVertex3f(852.0, 535.0, -1.2);	//PTO-3
		glVertex3f(808.0, 620.0, -1.2);	//PTO-4
		glVertex3f(860.0, 627.0, -1.2);	//PTO-5
		glVertex3f(873.0, 642.0, -1.2);	//PTO-6
		glVertex3f(908.0, 629.0, -1.2);	//PTO-7
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.6875f, 0.6875f, 0.6875f);

		glVertex3f(849.0, 506.0, -1.2); // PTO-I
		glVertex3f(814.0, 492.0, -1.2); // PTO-1
		glVertex3f(842.0, 512.0, -1.2); // PTO-2
		glVertex3f(852.0, 533.0, -1.2); // PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.6875f, 0.6875f, 0.6875f);

		glVertex3f(852.0, 535.0, -1.2); // PTO-I
		glVertex3f(842.0, 492.0, -1.2); // PTO-1
		glVertex3f(783.0, 603.0, -1.2); // PTO-2
		glVertex3f(795.0, 643.0, -1.2); // PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.6875f, 0.6875f, 0.6875f);

		glVertex3f(873.0, 642.0, -1.2);	// PTO-I
		glVertex3f(860.0, 627.0, -1.2);	// PTO-1
		glVertex3f(808.0, 620.0, -1.2);	// PTO-2
		glVertex3f(793.0, 643.0, -1.2);	// PTO-3
		glVertex3f(767.0, 661.0, -1.2);	// PTO-4
		glVertex3f(771.0, 673.0, -1.2);	// PTO-5
		glVertex3f(842.0, 657.0, -1.2);	// PTO-6
		glVertex3f(836.0, 669.0, -1.2);	// PTO-7
		glVertex3f(870.0, 670.0, -1.2);	// PTO-8
		glVertex3f(911.0, 633.0, -1.2);	// PTO-9
		glVertex3f(908.0, 629.0, -1.2);	// PTO-10
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.6875f, 0.6875f, 0.6875f);

		glVertex3f(836.0, 669.0, -1.2);	// PTO-I
		glVertex3f(810.0, 680.0, -1.2);	// PTO-1
		glVertex3f(870.0, 670.0, -1.2);	// PTO-2
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.0429, 0.0039, 0.0);

		glVertex3f(377.0, 289.0, -1.2);	//PTO-0
		glVertex3f(286.0, 236.0, -1.2);	//PTO-1
		glVertex3f(203.0, 286.0, -1.2);	//PTO-2
		glVertex3f(204.0, 325.0, -1.2);	//PTO-3
		glVertex3f(123.0, 477.0, -1.2);	//PTO-4
		glVertex3f(171.0, 473.0, -1.2);	//PTO-5
		glVertex3f(109.0, 564.0, -1.2);	//PTO-6<<INTERSECCION LINEA BLANCA
		glVertex3f(151.0, 517.0, -1.2);	//PTO-7<<INTERSECCION LINEA AMARILLA
		glVertex3f(411.0, 560.0, -1.2);	//PTO-8<<INTERSECCION LINEA BLANCA(BOCA)
		glVertex3f(426.0, 603.0, -1.2);	//PTO-9<<INTERSECCION LINEA BLANCA 2
		glVertex3f(477.0, 601.0, -1.2);	//PTO-10
		glVertex3f(578.0, 628.0, -1.2);	//PTO-11
		glVertex3f(739.0, 687.0, -1.2);	//PTO-12
		glVertex3f(733.0, 672.0, -1.2);	//PTO-13
		glVertex3f(772.0, 630.0, -1.2);	//PTO-14
		glVertex3f(778.0, 601.0, -1.2);	//PTO-15
		glVertex3f(783.0, 595.0, -1.2);	//PTO-16
		glVertex3f(795.0, 576.0, -1.2);	//PTO-17
		glVertex3f(802.0, 576.0, -1.2);	//PTO-18
		glVertex3f(842.0, 512.0, -1.2); //PTO-19
		glVertex3f(814.0, 492.0, -1.2); //PTO-20
		glVertex3f(788.0, 466.0, -1.2);	//PTO-21
		glVertex3f(787.0, 450.0, -1.2);	//PTO-22
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.1171, 0.1015, 0.0898);

		glVertex3f(489.0, 915.0, -1.2);	//PTO-0<<PTO LINEA AMARILLA DERECHA
		glVertex3f(481.0, 1025.0, -1.2);//PTO-1
		glVertex3f(476.0, 1016.0, -1.2);//PTO-2<<INTERSECCION LINEA AMARILLA
		glVertex3f(488.0, 1040.0, -1.2);//PTO-3
		glVertex3f(825.0, 1025.0, -1.2);//PTO-4
		glVertex3f(820.0, 996.0, -1.2); //PTO-5
		glVertex3f(875.0, 942.0, -1.2);	//PTO-6
		glVertex3f(561.0, 931.0, -1.2); //PTO-7<<INTERSECCION LINEA ROSA BOCA
		glVertex3f(428.0, 605.0, -1.2); //PTO-8
		glVertex3f(426.0, 603.0, -1.2); //PTO-9<<INTERSECCION LINEA ROSA BOCA (SUPERIOR)
		glVertex3f(411.0, 560.0, -1.2); //PTO-10<<INTERSECCION LINEA ROSA BOCA (SUPERIOR)
		glVertex3f(387.0, 555.0, -1.2); //PTO-11
		glVertex3f(425.0, 675.0, -1.2); //PTO-12
		glVertex3f(403.0, 729.0, -1.2); //PTO-13
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.0937, 0.0937, 0.0859);

		glVertex3f(227.0, 874.0, -1.2);	//PTO-0
		glVertex3f(140.0, 1105.0, -1.2);//PTO-1
		glVertex3f(130.0, 1132.0, -1.2);//PTO-2<<INTERSECCION LINEA BLANCA
		glVertex3f(110.0, 1193.0, -1.2);//PTO-3
		glVertex3f(122.0, 1221.0, -1.2);//PTO-4
		glVertex3f(198.0, 1174.0, -1.2);//PTO-5 
		glVertex3f(301.0, 1275.0, -1.2);//PTO-6
		glVertex3f(308.0, 1271.0, -1.2);//PTO-7<<INTERSECCION LINEA NARANJA
		glVertex3f(245.0, 1110.0, -1.2);//PTO-8
		glVertex3f(262.0, 1035.0, -1.2);//PTO-9
		glVertex3f(280.0, 1068.0, -1.2);//PTO-10
		glVertex3f(330.0, 982.0, -1.2);	//PTO-11
		glVertex3f(324.0, 976.0, -1.2);	//PTO-12
		glVertex3f(289.0, 1019.0, -1.2);//PTO-13
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.0664, 0.0664, 0.0585);

		glVertex3f(403.0, 729.0, -1.2);	//PTO-0
		glVertex3f(425.0, 675.0, -1.2);	//PTO-1
		glVertex3f(387.0, 555.0, -1.2);	//PTO-2
		glVertex3f(151.0, 517.0, -1.2);	//PTO-3
		glVertex3f(291.0, 963.0, -1.2);	//PTO-4
		glVertex3f(392.0, 843.0, -1.2);	//PTO-5
		glVertex3f(476.0, 1016.0, -1.2);//PTO-6
		glVertex3f(481.0, 1025.0, -1.2);//PTO-7
		glVertex3f(489.0, 915.0, -1.2); //PTO-8
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);

		glVertex3f(151.0, 517.0, -1.2);	//PTO-0
		glVertex3f(132.0, 539.0, -1.2);	//PTO-1<<INTERSECCION LINEA BLANCA (izquierda)
		glVertex3f(188.0, 830.0, -1.2);	//PTO-2<<INTERSECCION LINEA NARANJA
		glVertex3f(227.0, 874.0, -1.2);	//PTO-3<<UNION 2DO RECUADRO AZUL(izquierda) >>INTERSECCION LINEA ROJA
		glVertex3f(288.0, 1020.0, -1.2);//PTO-4<<UNION 3ER RECUADRO AZUL(derecha) >>INTERSECCION LINEA ROJA
		glVertex3f(292.0, 964.0, -1.2);	//PTO-5<<UNION 3DO RECUADRO AZUL(derecha)
	glEnd();
	/**********************************************************************/
	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);

		glVertex3f(188.0, 830.0, -1.2);	//PTO-0
		glVertex3f(227.0, 874.0, -1.2);	//PTO-1
		glVertex3f(140.0, 1105.0, -1.2);//PTO-2<<INTERSECCION LINEA ROJA
		glVertex3f(126.0, 1019.0, -1.2);//PTO-3<<INTERSECCION LINEA BLANCA(izquierda)
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0, 0.0, 0.0);

		glVertex3f(392.0, 843.0, -1.2);	//PTO-I
		glVertex3f(291.0, 962.0, -1.2);	//PTO-1
		glVertex3f(288.0, 1020.0, -1.2);//PTO-2
		glVertex3f(391.0, 888.0, -1.2);	//PTO-3<<INTERSECCION LINEA AMARILLA
		glVertex3f(454.0, 1071.0, -1.2);//PTO-4<<INTERSECCION LINEA ROSA
		glVertex3f(488.0, 1040.0, -1.2);//PTO-5
	glEnd();
	/**********************************************************************/
	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);

		glVertex3f(488.0, 1040.0, -1.2);//PTO-0
		glVertex3f(709.0, 1030.0, -1.2);//PTO-1
		glVertex3f(644.0, 1063.0, -1.2);//PTO-2
		glVertex3f(636.0, 1081.0, -1.2);//PTO-3<<INTERSECCION LINEA NARANJA
		glVertex3f(600.0, 1095.0, -1.2);//PTO-4<<INTERSECCION LINEA ROJA
		glVertex3f(454.0, 1071.0, -1.2);//PTO-5<<INTERSECCION LINEA ROSA
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.0898, 0.0976, 0.0859);

		glVertex3f(132.0, 539.0, -1.2);	//PTO-0
		glVertex3f(79.0, 595.0, -1.2);	//PTO-1
		glVertex3f(126.0, 1019.0, -1.2);//PTO-2
		glVertex3f(188.0, 830.0, -1.2);	//PTO-3
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.0039, 0.0039, 0.0039);

		glVertex3f(76.0, 1279.0, -1.2);	//PTO-0
		glVertex3f(246.0, 1221.0, -1.2);//PTO-1
		glVertex3f(198.0, 1174.0, -1.2);//PTO-2
		glVertex3f(122.0, 1221.0, -1.2);//PTO-3
		glVertex3f(110.0, 1193.0, -1.2);//PTO-4
		glVertex3f(130.0, 1132.0, -1.2);//PTO-5
		glVertex3f(69.0, 1202.0, -1.2);	//PTO-6
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.1601, 0.1601, 0.1601);

		glVertex3f(308.0, 1271.0, -1.2);//PTO-0
		glVertex3f(500.0, 1141.0, -1.2);//PTO-1<<INTERSECCION LINEA ROSA
		glVertex3f(513.0, 1117.0, -1.2);//PTO-2
		glVertex3f(405.0, 1094.0, -1.2);//PTO-3
		glVertex3f(391.0, 888.0, -1.2);	//PTO-4
		glVertex3f(323.0, 975.0, -1.2);	//PTO-5
		glVertex3f(330.0, 982.0, -1.2);	//PTO-6
		glVertex3f(280.0, 1068.0, -1.2);//PTO-7
		glVertex3f(262.0, 1035.0, -1.2);//PTO-8
		glVertex3f(245.0, 1110.0, -1.2);//PTO-8
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.0039, 0.0039, 0.0039);

		glVertex3f(440.0, 1260.0, -1.2);//PTO-0
		glVertex3f(603.0, 1239.0, -1.2);//PTO-1
		glVertex3f(721.0, 1226.0, -1.2);//PTO-2
		glVertex3f(665.0, 1222.0, -1.2);//PTO-3<<INTERSECCION LINEA AZUL
		glVertex3f(601.0, 1238.0, -1.2);//PTO-4
		glVertex3f(458.0, 1226.0, -1.2);//PTO-5
		glVertex3f(500.0, 1141.0, -1.2);//PTO-6
		glVertex3f(367.0, 1230.0, -1.2);//PTO-7
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(458.0, 1226.0, -1.2);//PTO-0
		glVertex3f(601.0, 1238.0, -1.2);//PTO-1
		glVertex3f(730.0, 1208.0, -1.2);//PTO-2
		glVertex3f(526.0, 1193.0, -1.2);//PTO-3
		glVertex3f(543.0, 1176.0, -1.2);//PTO-4		
		glVertex3f(474.0, 1226.0, -1.2);//PTO-5
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.5859, 0.5937, 0.5820);

		glVertex3f(458.0, 1226.0, -1.2);//PTO-0		
		glVertex3f(474.0, 1226.0, -1.2);//PTO-1
		glVertex3f(543.0, 1176.0, -1.2);//PTO-2
		glVertex3f(569.0, 1147.0, -1.2);//PTO-3<<INTERSECCION LINEAS ROJA Y AMARILLA
		glVertex3f(512.0, 1120.0, -1.2);//PTO-4
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.5859, 0.5937, 0.5820);

		glVertex3f(405.0, 1094.0, -1.2);//PTO-0		
		glVertex3f(493.0, 1114.0, -1.2);//PTO-1
		glVertex3f(423.0, 1077.0, -1.2);//PTO-2<<INTERSECCION LINEA AZUL(arriba)
		glVertex3f(410.0, 943.0, -1.2);	//PTO-3
		glVertex3f(391.0, 888.0, -1.2);	//PTO-4
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.2656, 0.2656, 0.2656);

		glVertex3f(454.0, 1071.0, -1.2);//PTO-0
		glVertex3f(410.0, 943.0, -1.2);	//PTO-1
		glVertex3f(423.0, 1077.0, -1.2);//PTO-2
		glVertex3f(493.0, 1114.0, -1.2);//PTO-3
		glVertex3f(513.0, 1117.0, -1.2);//PTO-4	
		glVertex3f(511.0, 1120.0, -1.2);//PTO-5
		glVertex3f(569.0, 1147.0, -1.2);//PTO-6
		glVertex3f(618.0, 1097.0, -1.2);//PTO-7
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.1601, 0.1601, 0.1601);

		glVertex3f(730.0, 1208.0, -1.2);//PTO-0
		glVertex3f(665.0, 1222.0, -1.2);//PTO-1
		glVertex3f(828.0, 1225.0, -1.2);//PTO-2
		glVertex3f(752.0, 1176.0, -1.2);//PTO-3<<INTERSECCION LINEA VERDE
		glVertex3f(648.0, 1182.0, -1.2);//PTO-4
		glVertex3f(569.0, 1147.0, -1.2);//PTO-5
		glVertex3f(543.0, 1176.0, -1.2);//PTO-6
		glVertex3f(526.0, 1193.0, -1.2);//PTO-7
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.0703, 0.0703, 0.0625);

		glVertex3f(656.0, 1139.0, -1.2);//PTO-0
		glVertex3f(660.0, 1104.0, -1.2);//PTO-1
		glVertex3f(636.0, 1081.0, -1.2);//PTO-2
		glVertex3f(623.0, 1074.0, -1.2);//PTO-3
		glVertex3f(600.0, 1095.0, -1.2);//PTO-4
		glVertex3f(618.0, 1097.0, -1.2);//PTO-5
		glVertex3f(569.0, 1147.0, -1.2);//PTO-6
		glVertex3f(648.0, 1182.0, -1.2);//PTO-7
		glVertex3f(752.0, 1176.0, -1.2);//PTO-8
		glVertex3f(729.0, 1163.0, -1.2);//PTO-9
		glVertex3f(729.0, 1159.0, -1.2);//PTO-10
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);

		glVertex3f(561.0, 931.0, -1.2);	//PTO-0
		glVertex3f(846.0, 940.0, -1.2);	//PTO-1
		glVertex3f(858.0, 925.0, -1.2);	//PTO-2
		glVertex3f(833.0, 899.0, -1.2);	//PTO-3
		glVertex3f(702.0, 898.0, -1.2);	//PTO-4
		glVertex3f(597.0, 872.0, -1.2);	//PTO-5
		glVertex3f(534.0, 867.0, -1.2);	//PTO-6
	glEnd();
	/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.4179, 0.2070, 0.58980);

		glVertex3f(475.0, 721.0, -1.2);	//PTO-0
		glVertex3f(678.0, 723.0, -1.2);	//PTO-1
		glVertex3f(843.0, 890.0, -1.2);	//PTO-2
		glVertex3f(833.0, 899.0, -1.2);	//PTO-3
		glVertex3f(872.0, 924.0, -1.2);	//PTO-4
		glVertex3f(936.0, 926.0, -1.2);	//PTO-5
		glVertex3f(1049.0, 898.0, -1.2);//PTO-6
		glVertex3f(1000.0, 889.0, -1.2);//PTO-7
		glVertex3f(882.0, 825.0, -1.2);	//PTO-8
		glVertex3f(851.0, 830.0, -1.2);	//PTO-9
		glVertex3f(677.0, 694.0, -1.2);	//PTO-10
	glEnd();
	/**********************************************************************/
	glBegin(GL_POLYGON);
		glColor3f(0.4179, 0.2070, 0.58980);

		glVertex3f(1049.0, 898.0, -1.2);//PTO-0
		glVertex3f(1059.0, 858.0, -1.2);//PTO-1
		glVertex3f(1059.0, 678.0, -1.2);//PTO-2
		glVertex3f(1036.0, 840.0, -1.2);//PTO-3
		glVertex3f(1000.0, 889.0, -1.2);//PTO-4
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.2265, 0.1171, 0.3164);

		glVertex3f(475.0, 721.0, -1.2);	//PTO-0
		glVertex3f(534.0, 867.0, -1.2);	//PTO-1
		glVertex3f(597.0, 872.0, -1.2);	//PTO-2
		glVertex3f(702.0, 898.0, -1.2);	//PTO-3
		glVertex3f(833.0, 899.0, -1.2);	//PTO-3
		glVertex3f(843.0, 890.0, -1.2);	//PTO-4
		glVertex3f(678.0, 723.0, -1.2);	//PTO-5
		glVertex3f(475.0, 720.0, -1.2);	//PTO-6
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.6796, 0.3437, 0.9726);

		glVertex3f(1000.0, 889.0, -1.2);//PTO-0
		glVertex3f(1036.0, 840.0, -1.2);//PTO-1
		glVertex3f(1059.0, 678.0, -1.2);//PTO-2
		glVertex3f(1035.0, 595.0, -1.2);//PTO-3
		glVertex3f(961.0, 820.0, -1.2);	//PTO-4
		glVertex3f(882.0, 825.0, -1.2);	//PTO-5
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.6796, 0.3437, 0.9726);

		glVertex3f(1040.0, 367.0, -1.2);//PTO-I 
		glVertex3f(1059.0, 407.0, -1.2);//PTO-0
		glVertex3f(1059.0, 678.0, -1.2);//PTO-1
		glVertex3f(1035.0, 595.0, -1.2);//PTO-2
		glVertex3f(990.0, 398.0, -1.2);	//PTO-3
		glVertex3f(769.0, 150.0, -1.2);	//PTO-4
		glVertex3f(795.0, 117.0, -1.2);	//PTO-5
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.6796, 0.3437, 0.9726);

		glVertex3f(610.0, 136.0, -1.2);	//PTO-I
		glVertex3f(769.0, 150.0, -1.2);	//PTO-0
		glVertex3f(795.0, 117.0, -1.2);	//PTO-1
		glVertex3f(615.0, 101.0, -1.2);	//PTO-2
		glVertex3f(562.0, 22.0, -1.2);	//PTO-3
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4414, 0.2187, 0.6210);

		glVertex3f(1055.0, 361.0, -1.2);//PTO-I
		glVertex3f(1059.0, 367.0, -1.2);//PTO-0
		glVertex3f(1059.0, 407.0, -1.2);//PTO-1
		glVertex3f(1040.0, 367.0, -1.2);//PTO-2
		glVertex3f(795.0, 117.0, -1.2);	//PTO-3
		glVertex3f(802.0, 93.0, -1.2);	//PTO-4
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4414, 0.2187, 0.6210);

		glVertex3f(615.0, 101.0, -1.2);	//PTO-I
		glVertex3f(796.0, 117.0, -1.2);	//PTO-0
		glVertex3f(802.0, 93.0, -1.2);	//PTO-1
		glVertex3f(626.0, 79.0, -1.2);	//PTO-2
		glVertex3f(556.0, 3.0, -1.2);	//PTO-3
		glVertex3f(562.0, 22.0, -1.2);	//PTO-4
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.2070, 0.2070, 0.2070);
		
		glVertex3f(826.0, 696.0, -1.2);	//PTO-0
		glVertex3f(847.0, 724.0, -1.2);	//PTO-1
		glVertex3f(897.0, 755.0, -1.2);	//PTO-2
		glVertex3f(939.0, 720.0, -1.2);	//PTO-3
		glVertex3f(916.0, 681.0, -1.2);	//PTO-4
		glVertex3f(896.0, 689.0, -1.2);	//PTO-5
		glVertex3f(856.0, 689.0, -1.2);	//PTO-7
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(441.0, 558.0, -1.2);	//PTO-I
		glVertex3f(507.0, 701.0, -1.2);	//PTO-1
		glVertex3f(471.0, 569.0, -1.2);	//PTO-2
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(471.0, 569.0, -1.2);	//PTO-I
		glVertex3f(507.0, 701.0, -1.2);	//PTO-1
		glVertex3f(510.0, 710.0, -1.2);	//PTO-2
		glVertex3f(489.0, 577.0, -1.2);	//PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(504.0, 584.0, -1.2);	//PTO-I
		glVertex3f(524.0, 589.0, -1.2);	//PTO-1
		glVertex3f(529.0, 607.0, -1.2);	//PTO-2
		glVertex3f(537.0, 734.0, -1.2);	//PTO-3
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(549.0, 597.0, -1.2);	//PTO-I
		glVertex3f(539.0, 749.0, -1.2);	//PTO-1
		glVertex3f(537.0, 734.0, -1.2);	//PTO-2
		glVertex3f(528.0, 605.0, -1.2);	//PTO-3
		glVertex3f(524.0, 591.0, -1.2);	//PTO-4
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(567.0, 609.0, -1.2);	//PTO-I
		glVertex3f(584.0, 614.0, -1.2);	//PTO-1
		glVertex3f(577.0, 623.0, -1.2);	//PTO-2
		glVertex3f(567.0, 689.0, -1.2);	//PTO-3
		glVertex3f(561.0, 697.0, -1.2);	//PTO-4
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(577.0, 623.0, -1.2);	//PTO-I
		glVertex3f(583.0, 615.0, -1.2);	//PTO-1
		glVertex3f(597.0, 619.0, -1.2);	//PTO-2
		glVertex3f(565.0, 691.0, -1.2);	//PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(611.0, 627.0, -1.2);	//PTO-I
		glVertex3f(659.0, 649.0, -1.2);	//PTO-1
		glVertex3f(625.0, 674.0, -1.2);	//PTO-2
		glVertex3f(539.0, 793.0, -1.2);	//PTO-3
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(625.0, 674.0, -1.2);	//PTO-I
		glVertex3f(659.0, 649.0, -1.2);	//PTO-1
		glVertex3f(687.0, 660.0, -1.2);	//PTO-2
		glVertex3f(539.0, 793.0, -1.2);	//PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(694.0, 671.0, -1.2);	//PTO-I
		glVertex3f(718.0, 675.0, -1.2);	//PTO-1
		glVertex3f(707.0, 684.0, -1.2);	//PTO-2
		glVertex3f(674.0, 786.0, -1.2);	//PTO-3
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(707.0, 684.0, -1.2);	//PTO-I
		glVertex3f(718.0, 675.0, -1.2);	//PTO-1
		glVertex3f(729.0, 676.0, -1.2);	//PTO-2
		glVertex3f(674.0, 787.0, -1.2);	//PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(737.0, 685.0, -1.2);	//PTO-I
		glVertex3f(773.0, 701.0, -1.2);	//PTO-1
		glVertex3f(768.0, 721.0, -1.2);	//PTO-2
		glVertex3f(748.0, 837.0, -1.2);	//PTO-3
		glVertex3f(743.0, 844.0, -1.2);	//PTO-4
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(768.0, 721.0, -1.2);	//PTO-I
		glVertex3f(773.0, 701.0, -1.2);	//PTO-1
		glVertex3f(825.0, 697.0, -1.2);	//PTO-2
		glVertex3f(749.0, 835.0, -1.2);	//PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(841.0, 701.0, -1.2);	//PTO-I
		glVertex3f(874.0, 701.0, -1.2);	//PTO-1
		glVertex3f(859.0, 724.0, -1.2);	//PTO-2
		glVertex3f(825.0, 793.0, -1.2);	//PTO-3
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(859.0, 724.0, -1.2);	//PTO-I
		glVertex3f(874.0, 701.0, -1.2);	//PTO-1
		glVertex3f(914.0, 701.0, -1.2);	//PTO-2
		glVertex3f(829.0, 787.0, -1.2);	//PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(887.0, 757.0, -1.2);	//PTO-I
		glVertex3f(896.0, 741.0, -1.2);	//PTO-1
		glVertex3f(899.0, 749.0, -1.2);	//PTO-2
		glVertex3f(933.0, 772.0, -1.2);	//PTO-3
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(899.0, 749.0, -1.2);	//PTO-I
		glVertex3f(896.0, 741.0, -1.2);	//PTO-1
		glVertex3f(904.0, 726.0, -1.2);	//PTO-2
		glVertex3f(923.0, 732.0, -1.2);	//PTO-3
		glVertex3f(933.0, 772.0, -1.2);	//PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(918.0, 716.0, -1.2);	//PTO-I
		glVertex3f(920.0, 715.0, -1.2);	//PTO-1
		glVertex3f(935.0, 719.0, -1.2);	//PTO-2
		glVertex3f(972.0, 769.0, -1.2);	//PTO-3
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(937.0, 695.0, -1.2);	//PTO-I
		glVertex3f(972.0, 769.0, -1.2);	//PTO-1
		glVertex3f(935.0, 719.0, -1.2);	//PTO-2
		glVertex3f(920.0, 715.0, -1.2);	//PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(573.0, 881.0, -1.2);	//PTO-I
		glVertex3f(663.0, 724.0, -1.2);	//PTO-1
		glVertex3f(657.0, 742.0, -1.2);	//PTO-2
		glVertex3f(601.0, 868.0, -1.2);	//PTO-3
		glVertex3f(585.0, 909.0, -1.2);	//PTO-4
		glVertex3f(581.0, 910.0, -1.2);	//PTO-5
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(609.0, 902.0, -1.2);	//PTO-I
		glVertex3f(585.0, 909.0, -1.2);	//PTO-1
		glVertex3f(657.0, 742.0, -1.2);	//PTO-2
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(629.0, 911.0, -1.2);	//PTO-I
		glVertex3f(656.0, 791.0, -1.2);	//PTO-1
		glVertex3f(658.0, 808.0, -1.2);	//PTO-2
		glVertex3f(651.0, 889.0, -1.2);	//PTO-3
		glVertex3f(655.0, 914.0, -1.2);	//PTO-4
		glVertex3f(641.0, 917.0, -1.2);	//PTO-5
		glVertex3f(635.0, 916.0, -1.2);	//PTO-6
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(671.0, 905.0, -1.2);	//PTO-I
		glVertex3f(655.0, 914.0, -1.2);	//PTO-1
		glVertex3f(651.0, 889.0, -1.2);	//PTO-2
		glVertex3f(658.0, 808.0, -1.2);	//PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(685.0, 922.0, -1.2);	//PTO-I
		glVertex3f(709.0, 749.0, -1.2);	//PTO-1
		glVertex3f(706.0, 887.0, -1.2);	//PTO-2
		glVertex3f(717.0, 919.0, -1.2);	//PTO-3
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(735.0, 917.0, -1.2);	//PTO-I
		glVertex3f(717.0, 919.0, -1.2);	//PTO-1
		glVertex3f(706.0, 887.0, -1.2);	//PTO-2
		glVertex3f(709.0, 749.0, -1.2);	//PTO-3
		glVertex3f(712.0, 730.0, -1.2);	//PTO-4
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(750.0, 920.0, -1.2);	//PTO-I
		glVertex3f(855.0, 844.0, -1.2);	//PTO-1
		glVertex3f(793.0, 921.0, -1.2);	//PTO-2
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(814.0, 921.0, -1.2);	//PTO-I
		glVertex3f(793.0, 921.0, -1.2);	//PTO-1
		glVertex3f(855.0, 844.0, -1.2);	//PTO-2
		glVertex3f(893.0, 817.0, -1.2);	//PTO-3
	glEnd();
	/**********************************************************************/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4687, 0.4765, 0.4648);

		glVertex3f(831.0, 914.0, -1.2);	//PTO-I
		glVertex3f(915.0, 862.0, -1.2);	//PTO-1
		glVertex3f(849.0, 921.0, -1.2);	//PTO-2
	glEnd();
	/*--------------------------------------------------------------------*/
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8593, 0.8593, 0.8593);

		glVertex3f(869.0, 927.0, -1.2);	//PTO-I
		glVertex3f(849.0, 921.0, -1.2);	//PTO-1
		glVertex3f(919.0, 860.0, -1.2);	//PTO-2
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4414, 0.2187, 0.6210);

		glVertex3f(1114.0, 596.0, -1.2);	//PTO-I
		glVertex3f(1059.0, 858.0, -1.2);	//PTO-1
		glVertex3f(1059.0, 367.0, -1.2);	//PTO-2
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.6796, 0.3437, 0.9726);

		glVertex3f(1048.0, 471.0, -1.2);	//PTO-I
		glVertex3f(1059.0, 411.0, -1.2);	//PTO-1
		glVertex3f(1059.0, 687.0, -1.2);	//PTO-2
	glEnd();
/////////////////////////////////////////////////////////////////////////////////////
	glFlush();
}

void reshape(int width, int height)				// Creamos funcion Reshape
{
	if (height == 0)							// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);				// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(0, 1200, 1400, 0, 0.1, 2);			// Configuracion puerto de vista y la amplitud/profundidad de la vista
												// Limites inferiores, superiores y profundidad
	glMatrixMode(GL_MODELVIEW);					// Seleccionamos Modelview Matrix
	glLoadIdentity();							// Matriz identidad			
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv);						// Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitWindowSize(1020, 1330);				// Tamaño de la Ventana
	glutInitWindowPosition(200, 0);				// Posicion de la Ventana
	glutCreateWindow("Tarea Dibujo");			// Nombre de la Ventana
	InitGL();									// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);					// Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);					// Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);					// Indicamos a Glut función de manejo de teclado
	glutMainLoop();					// 

	return 0;
}