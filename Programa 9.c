//Cardoso Osorio Atl Yosafat.
//Coidgo 9

//Estas son las librerias
#include<stdio.h>

//Esta es la declaracion de la estructura
struct elemento{
	int arreglo[5];
	int i;
};

//Esta funcion es la funcion principal
void main(){
	struct elemento var;
	//Realizamos la inicializacion del bulce 
	for(var.i =0;var.i<5;var.i++){
		printf("\nInruzca un numero: ");
		scanf("%d",&var.arreglo[var.i]);
	}
	//Reaalizamos la inicializacion del bucle 
	for(var.i=0;var.i<5;var.i++){
		printf("\nEn la celda %d esta el entero %d en la direccion %lu",var.i,var.arreglo[var.i],&var.arreglo[var.i]);
	}
}


