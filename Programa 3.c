//Cardoso Osorio Atl Yosafat.
//Codigo 3

//Estas son las librerias
#include<stdio.h>

//Esta es la estructura que contendra los datos a ingresar
struct persona{
	//Estas son las variables contenidas en la estructura
	char nombre[30];
	int edad;
	char sexo;
};

//Esta es la funcion principal
void main(){
	//Esta es la declaracion de nuestro arreglo con la estructura y el puntero
	struct persona arreglo[5],*ptr;
	
	//Esta es la declaracion del ciclo para el uso del puntero
	for(ptr=arreglo;ptr < &arreglo[5];ptr=ptr+1){
		printf("\nIntroduzca el nombre: ");
		gets(ptr -> nombre);
		//Esta funcion sirve para la limpieza del buffer
		fflush(stdin);
		printf("\nIntroduzca la edad: ");
		scanf("%d",&ptr->edad);
		fflush(stdin);
		printf("\nIntroduzca el sexo: ");
		ptr->sexo = getchar();
		fflush(stdin);
	}
	
	//Esta es la declaracion del ciclo para imprimir la cadena y el lugar en el que se encuentra
	for(ptr=arreglo;ptr < &arreglo[5];ptr = ptr +1){
		printf("\nEn la celda %d esta la cadena %s en la direccion %lu",((int)(ptr-arreglo))+1,ptr->nombre,ptr);
	}
}
