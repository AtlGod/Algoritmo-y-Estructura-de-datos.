//Cardoso Osorio Atl Yosafat.
//Codigo 2

//Estas son las librerias
#include<stdio.h>

//Esta es la estructura que contendra los datos a ingresar
struct persona{
	//Estos son las varibales contenidas en la estructura
	char nombre[30];
	int edad;
	char sexo;
};

//Esta es la funcion principal
void main(){
	//Estas son las varibles y el puntero a operar
	struct persona arreglo[5],*ptr;
	//Esat es la declaracion del acumulador
	int i;
	//Inciamos el ciclo ,acorde a los parametros
	for(i=0;i<5;i++){
		printf("Introduzca el nombre: ");
		gets(arreglo[i].nombre);
		//Esta funcion se encarga de la limpieza del buffer
		fflush(stdin);
		printf("\nIntroduzca la edad: ");
		scanf("%d",&arreglo[i].edad);
		fflush(stdin);
		printf("\nIntroduzca el sexo: ");
		arreglo[i].sexo = getchar();
		fflush(stdin);
	}
	
	//ahora realizamos un bucle para obtener los datos ingresados en la estructura persona
	for(i=0;i<5;i++){
		printf("\nEn la celda %d esta la cadena %s en la direccion %lu",i,arreglo[i].nombre,&arreglo[i].nombre);
	}
	
	//Recordemos que en esta funcion no retornamos valor por que el main es void(vacio)
}

