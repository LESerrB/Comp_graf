//Semestre 2017 - 2
//*************************************************************//
//*************************************************************//
//************** Alumno (s): **********************************//
//************************** Serrano Bermúdez Luis Ezsteban	***//
//***************Versión Visual Studio: ***********************//
//************************** VS 2015 14.0.25431.01 ************//
#include "Main.h"
void InitGL(GLvoid)     // Inicializamos parametros
{
//glShadeModel(GL_FLAT);								// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
														//glClearDepth(1.0f);			Configuramos Depth Buffer
														//glEnable(GL_DEPTH_TEST);		Habilitamos Depth Testing
														//glDepthFunc(GL_LEQUAL);		Tipo de Depth Testing a realizar


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

														//Poner aqui codigo ha dibujar
														//glut permite crear interfaz grafica
														//glloadidentity crear matriz identidad / deja todo como estaba inicialmente
														//pixel:unidad minima de una representacion grafica
	glPointSize(10.0);//TAMANO DE PUNTO (MULTIPLICA PIXEL * 10)
//PRIMER LETRA "L"
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 0.0, 0.0); 

		glVertex3f(-12.0, 12.0, -1.2); //PTO1
		glVertex3f(-12.0, 5.5, -1.2);  //PTO2
		glVertex3f(-8.0, 5.5, -1.2);   //PTO3
		glVertex3f(-8.0, 7.0, -1.2);   //PTO4
		glVertex3f(-10.0, 7.0, -1.2);  //PTO5
		glVertex3f(-10.0, 12.0, -1.2); //PTO6
	glEnd();

//SEGUNDA LETRA "E"
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 0.0);

		glVertex3f(-7.0, 12.0, -1.2);	//PTO1
		glVertex3f(-7.0, 5.5, -1.2);	//PTO2
		glVertex3f(-5.0, 5.5, -1.2);	//PTO3
		glVertex3f(-5.0, 12.0, -1.2);	//PTO4
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.8, 0.3, 0.4);

		glVertex3f(-5.0, 12.0, -1.2);	//PTO4
		glVertex3f(-3.0, 12.0, -1.2);	//PTO5
		glVertex3f(-3.0, 10.5, -1.2);	//PTO6
		glVertex3f(-5.0, 10.5, -1.2);	//PTO7
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.6, 1.0, 0.7);

		glVertex3f(-5.0, 9.5, -1.2);	//PTO8
		glVertex3f(-3.5, 9.5, -1.2);	//PTO9
		glVertex3f(-3.5, 8.0, -1.2);	//PTO10
		glVertex3f(-5.0, 8.0, -1.2);	//PTO11
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.5, 0.1);

		glVertex3f(-5.0, 7.0, -1.2);	//PTO12
		glVertex3f(-3.0, 7.0, -1.2);	//PTO13
		glVertex3f(-3.0, 5.5, -1.2);	//PTO14
		glVertex3f(-5.0, 5.5, -1.2);	//PTO3
	glEnd();

//TERCER LETRA "S"
	glBegin(GL_LINES);
		glColor3f(0.9, 0.8, 0.7);

		glVertex3f(-2.0, 12.0, -1.2);	//PTO1
		glVertex3f(2.0, 12.0, -1.2);	//PTO2

		glVertex3f(2.0, 12.0, -1.2);	//PTO2
		glVertex3f(2.0, 10.5, -1.2);	//PTO3

		glVertex3f(2.0, 10.5, -1.2);	//PTO3
		glVertex3f(-0.5, 10.5, -1.2);	//PTO4

		glVertex3f(-0.5, 10.5, -1.2);	//PTO4
		glVertex3f(-0.5, 9.5, -1.2);	//PTO5

		glVertex3f(-0.5, 9.5, -1.2);	//PTO5
		glVertex3f(2.0, 9.5, -1.2);		//PTO6

		glVertex3f(2.0, 9.5, -1.2);		//PTO6
		glVertex3f(2.0, 5.5, -1.2);		//PTO7

		glVertex3f(2.0, 5.5, -1.2);		//PTO7
		glVertex3f(-2.0, 5.5, -1.2);	//PTO8

		glVertex3f(-2.0, 5.5, -1.2);	//PTO8
		glVertex3f(-2.0, 7.0, -1.2);	//PTO9

		glVertex3f(-2.0, 7.0, -1.2);	//PTO9
		glVertex3f(0.5, 7.0, -1.2);		//PTO10

		glVertex3f(0.5, 7.0, -1.2);		//PTO10
		glVertex3f(0.5, 8.0, -1.2);		//PTO11

		glVertex3f(0.5, 8.0, -1.2);		//PTO11
		glVertex3f(-2.0, 8.0, -1.2);	//PTO12

		glVertex3f(-2.0, 8.0, -1.2);	//PTO12
		glVertex3f(-2.0, 12.0, -1.2);	//PTO1
	glEnd();

//CUARTA LETRA "B"
	glBegin(GL_POLYGON);
		glColor3f(0.4, 0.3, 1.0);

		glVertex3d(3.0, 12.0, -1.2);	//PTO1
		glVertex3d(5.0, 12.0, -1.2);	//PTO2
		glVertex3d(5.0, 5.5, -1.2);		//PTO3
		glVertex3d(3.0, 5.5, -1.2);		//PTO4

		glVertex3d(5.0, 12.0, -1.2);	//PTO2
		glVertex3d(6.0, 12.0, -1.2);	//PTO5
		glVertex3d(6.0, 10.5, -1.2);	//PTO6
		glVertex3d(5.0, 10.5, -1.2);	//PTO7
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.4, 0.8);

		glVertex3d(6.0, 9.5, -1.2);		//PTO10
		glVertex3d(5.0, 9.5, -1.2);		//PTO11
		glVertex3d(5.0, 8.0, -1.2);		//PTO12
		glVertex3d(6.0, 8.0, -1.2);		//PTO13
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.2, 1.0, 0.1);

		glVertex3d(6.0, 7.0, -1.2);		//PTO14
		glVertex3d(6.0, 5.5, -1.2);		//PTO16
		glVertex3d(5.0, 5.5, -1.2);		//PTO3
		glVertex3d(5.0, 7.0, -1.2);		//PTO15
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.3, 0.3, 0.3);

		glVertex3d(6.0, 12.0, -1.2);	//PTO5
		glVertex3d(7.0, 11.0, -1.2);	//PTO8
		glVertex3d(7.0, 9.25, -1.2);	//PTO9
		glVertex3d(6.0, 8.75, -1.2);	//PTO17
	glEnd();
	
	glBegin(GL_POLYGON);
		glColor3f(0.2, 0.9, 0.3);

		glVertex3d(6.0, 8.75, -1.2);	//PTO17
		glVertex3d(7.0, 8.25, -1.2);	//PTO18
		glVertex3d(7.0, 6.25, -1.2);	//PTO19
		glVertex3d(6.0, 5.5, -1.2);		//PTO16
	glEnd();

//ESTRELLA
	glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 1.0);

		glVertex3d(-2.5, 4.0, -1.2);	//PTO1
		glVertex3d(-1.5, 3.0, -1.2);	//PTO2
		glVertex3d(-3.5, 3.0, -1.2);	//PTO3
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);

		glVertex3d(-1.5, 3.0, -1.2);	//PTO2
		glVertex3d(2.5, 3.0, -1.2);		//PTO4
		glVertex3d(-1.0, 2.0, -1.2);	//PTO5
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(0.0, 1.0, 0.0);

		glVertex3d(-1.0, 2.0, -1.2);	//PTO5
		glVertex3d(0.0, 0.0, -1.2);		//PTO6
		glVertex3d(-2.5, 1.0, -1.2);	//PTO7
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.5, 0.0);

		glVertex3d(-2.5, 1.0, -1.2);	//PTO7
		glVertex3d(-5.5, 0.0, -1.2);	//PTO8
		glVertex3d(-4.0, 2.0, -1.2);	//PTO9
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 1.0, 1.0);

		glVertex3d(-4.0, 2.0, -1.2);	//PTO9
		glVertex3d(-7.5, 3.0, -1.2);	//PTO10
		glVertex3d(-3.5, 3.0, -1.2);	//PTO3

	glEnd();

	glFlush();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-14, 14, -14, 14, 0.1, 2); //Configuracion puerto de vista y la amplitud/profundidad de la vista
									  //Limites inferiores, superiores y profundidad
	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();						//matriz identidad			
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
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 2"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutMainLoop();          // 

	return 0;
}