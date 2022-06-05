//Cardoso Osorio Atl Yosafat.
//Codigo 8

//Estas son las librerias
#include<stdio.h>

//Estas son las declaraciones de la estructura
struct persona{
	//Las variables de la estructura
	char nombre[30];
	int edad;
	char sexo;
};

//Esta es la funcion principal
void main(){
	struct persona arreglo[5],*ptr1,**ptr2;
	//Realizamos la asignacion de la direccion
	ptr1 = arreglo;
	//Realizamos el bucle asignando al puntero la direccion
	for(ptr2 = &ptr1;*ptr2< &arreglo[5];(*ptr2)++){
		//Pedimos los valores usando el puntero
		printf("\nIntroduzca el nombre: ");
		gets((*ptr2)->nombre);
		fflush(stdin);
		printf("\nIntroduzca la edad: ");
		scanf("%d",&(*ptr2)->edad);
		fflush(stdin);
		printf("\nIntroduzca el sexo: ");
		(*ptr2)->sexo = getchar();
		fflush(stdin);
	}
	
	//Realizamos el restablecimiento de la direccion
	ptr1 = arreglo;
	//Realizamos el bucle respecto a la asginacion
	for(ptr2=&ptr1;*ptr2 < &arreglo[5];*ptr2 = *ptr2+1){
		//Realizamos la impresion de los valores
		printf("\nEn la celda %d esta en la cadena %s en la direccion %lu",(int)(*ptr2-arreglo),**ptr2,*ptr2);
	}
	
}
