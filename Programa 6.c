//Cardoso Osorio Atl Yosafat.
//Coidgo 6

//Estas son las librerias
#include<stdio.h>

//Esta es la funcion principal
void main(){
	//Realizamos la declaracion de variables y punteros
	int arreglo[5],*ptr1,**ptr2,***ptr3;
	//Realizamos la asignacion de direcciones
	ptr1 = arreglo;
	ptr2 = &ptr1;
	//Realizamos el bucle con la asignacion de la variable
	for(ptr3=&ptr2;**ptr3 < &arreglo[5];(**ptr3)++){
		//Realizamos el ingreso de las variables
		printf("\nIntroduzca un numero: ");
		scanf("%d",**ptr3);
	}
	ptr1 = arreglo;
	//Realizamos el siguiente bucle respecto a la variable usando los punteros
	for(ptr3 = &ptr2;**ptr3 < &arreglo[5];(**ptr3)++){
		//Realizamos la impresion de los compontentes y de sus direcciones
		printf("\nEn la cadena %d esta la cadena %d en la direccion %lu",(int)(**ptr3-arreglo),***ptr3,**ptr3);
	}
	
}
