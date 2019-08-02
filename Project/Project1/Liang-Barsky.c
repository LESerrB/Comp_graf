#include <stdio.h>
#include <stdlib.h>
//***************************************************************************************************************//
int main(void) {
	int CoordX, CoordY, ptoComp, i = 1, j = 0, n = 0, x = 0;
	int *Coord;
	int Xizq, Xder, Yinf, Ysup;
	char c;
//***************************************************************************************************************//
	FILE *archivo; 							// SE DECLARA EL APUNTADOR DE TIPO FILE DE ENTRADA
	FILE *archivosal;						// SE DECLARA EL APUNTADOR DE TIPO FILE DE SALIDA
	Coord =(int *)malloc(n*sizeof(int));	
	archivo = fopen("Input.txt", "a+");		// ARCHIVO DE ENTRADA
	archivosal = fopen("Output.txt", "w");	// ARCHIVO DE SALIDA
//***************************************************************************************************************//
	printf("<<<<<<Algoritmo Liang-Barsky>>>>>>\n\n");
	printf("Dame el limite izquierdo de la ventana: ");
	scanf("%d", &Xizq);
	printf("Dame el limite superior de la ventana: ");
	scanf("%d", &Xder);
	printf("Dame el limite inferior de la ventana: ");
	scanf("%d", &Yinf);
	printf("Dame el limite superior de la ventana: ");
	scanf("%d", &Ysup);
//**************************************LECTURA DE ARCHIVO DE ENTRADA********************************************//
	if(archivo == NULL)
		printf("No se encuentra el archivo\n");
	else {
		printf("\nArchivo abierto correctamente\n");

		while(feof(archivo) == 0) {			//CUENTA LAS LINEAS QUE HAY EN EL ARCHIVO
			c = fgetc(archivo);
			if(c == '\n')
				i++;
		}

		n = 2*i;							//DIMENSIONA EL ARRGLO DE COORDENADAS

		printf("Hay: %d lineas\n\n", i/2);
		rewind(archivo);
		
		while(feof(archivo) == 0) {			//ESCANEA LAS COORDENADAS PUNTO POR PUNTO
			fscanf(archivo, "%d", &CoordX);
			Coord[j] = CoordX;				
			j++;
			fgetc(archivo);
			fscanf(archivo, "%d", &CoordY);
			Coord[j] = CoordY;
			j++;
		}

		fclose(archivo);
	}
//*************************************ESCRITURA DE ARCHIVO DE SALIDA********************************************//
	printf("Archivo de salida creado satisfactoriamente.\n");

	fprintf(archivosal, "%s", "\t\t<<<Resultados Liang - Barsky>>>\n\n");
	fprintf(archivosal, "%s", "<<<Coordenadas de los Puntos>>>\n");
	
	for (int k = 0; k < 16; k++){
		if (k%2 == 0)
			fprintf(archivosal, "X[%d] = %d,\t", k, Coord[k]);
		else
			fprintf(archivosal, "Y[%d] = %d \n", k, Coord[k]);
	}

	fprintf(archivosal, "%s", "\n===============================================================================\n");
	fprintf(archivosal, "%s", "\n\n<<<Resumen de los Puntos>>>\n");
 //**********************************************ANALISIS IZQUIERDO**********************************************//
	j = 0;

	while(x < n){
		ptoComp = analisisIzq(Coord[x], Coord[x+1], Coord[x+2], Coord[x+3], Xizq);

		if (ptoComp != 0)
			fprintf(archivosal, "\nLimite izquierdo de la linea %d: Punto de corte en (%d, %d)", j+1, Xizq, ptoComp);
		else
			fprintf(archivosal, "\nLimite izquierdo  de la linea %d: No hay punto de recorte.", j+1);
//***********************************************ANALISIS DERECHO************************************************//
		ptoComp = analisisDer(Coord[x], Coord[x+1], Coord[x+2], Coord[x+3], Xder);

		if (ptoComp != 0)
			fprintf(archivosal, "\nLimite izquierdo de la linea %d: Punto de corte en (%d, %d)", j+1, Xder, ptoComp);
		else
			fprintf(archivosal, "\nLimite derecho  de la linea %d: No hay punto de recorte.", j+1);
//***********************************************ANALISIS SUPERIOR***********************************************//
		ptoComp = analisisSup(Coord[x], Coord[x+1], Coord[x+2], Coord[x+3], Ysup);

		if (ptoComp != 0)
			fprintf(archivosal, "\nLimite izquierdo de la linea %d: Punto de corte en (%d, %d)", j+1, ptoComp, Ysup);
		else
			fprintf(archivosal, "\nLimite superiror de la linea %d: No hay punto de recorte.", j+1);
//***********************************************ANALISIS INFERIOR***********************************************//
		ptoComp = analisisInf(Coord[x], Coord[x+1], Coord[x+2], Coord[x+3], Yinf);

		if (ptoComp != 0)
			fprintf(archivosal, "\nLimite izquierdo de la linea %d: Punto de corte en (%d, %d)", j+1, ptoComp, Yinf);
		else
			fprintf(archivosal, "\nLimite inferior de la linea %d: No hay punto de recorte.", j+1);

		x = x+4;
		j++;
	}

	fclose(archivosal);
//***************************************************************************************************************//	
	system("PAUSE");
}
//***********************************************ANALISIS DE CORTE***********************************************//
int analisisIzq(int xI, int yI, int xF, int yF, int Xizq) {
	int Vizq, comp, Yizq;

	comp = (xF - xI);

	if (comp == 0)								//PREVIENE LA DIVISIÓN ENTRE O
		return 0;
	else
		Vizq = (Xizq - xI) / comp;				//APLICA LA FORMULA DE ANÁLISIS

	if (Vizq < 0)
		return 0;								//REGRESA EL MISMO PUNTO SI NO SALE DE LA VENTANA
	else
		Yizq = yI + (Vizq*(yF - yI));	
	return 	Yizq;								//CAMBIA POR EL PUNTO SOBRE EL QUE SE CORTA
}
//***************************************************************************************************************//
int analisisDer(int xI, int yI, int xF, int yF, int Xder) {
	int Vder, comp, Yder;

	comp = (xF - xI);

	if (comp == 0)
		return 0;
	else
		Vder = (Xder - xI) / comp;

	if (Vder < 0)
		return 0;
	else
		Yder = yI + (Vder*(yF - yI));
	return 	Yder;
}
//***************************************************************************************************************//
int analisisSup(int xI, int yI, int xF, int yF, int Ysup) {
	int Vsup, comp, Xsup;

	comp = (yF - yI);

	if (comp == 0)
		return 0;
	else
		Vsup = (Ysup - yI) / comp;

	if (Vsup < 0)
		return 0;
	else
		Xsup = yI + (Vsup*(xF - xI));
	return 	Xsup;
}
//***************************************************************************************************************//
int analisisInf(int xI, int yI, int xF, int yF, int Yinf) {
	int Vinf, comp, Xinf;

	comp = (yF - yI);

	if (comp == 0)
		return 0;
	else
		Vinf = (Yinf - yI) / comp;

	if (Vinf < 0)
		return 0;
	else
		Xinf = yI + (Vinf*(xF - xI));
	return 	Xinf;
}