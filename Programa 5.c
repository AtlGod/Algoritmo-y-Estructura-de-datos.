//Cardoso Osorio Atl Yosafat.
//Codigo 5

//Estas son las librerias
#include<stdio.h>

//Esta es la funcion principal
void main(){
	//Esta es la declaracion de las variables y los punteros a usar
	int arreglo[5],*ptr1,**ptr2;
	//Se realiza la asginacion de direcciones
	ptr1 = arreglo;
	//Se realiza un ciclo con la respectiva asignacion de la direccion para controlar con un solo puntero
	for(ptr2= &ptr1;*ptr2 < &arreglo[5];*ptr2 = *ptr2+1){
		//Pedimos las variables por medio de un puntero
		printf("\nIntroduzca un numero: ");
		scanf("%d",*ptr2);
	}
	//Realizamos el restablecimiento de la direccion para volver a realizar el bucle
	ptr1 = arreglo;
	for(ptr2 = &ptr1;*ptr2 < &arreglo[5];(*ptr2)++){
		//Realizamos la impresion de los contenidos por medio de punteros
		printf("\nEn la celda %d esta la cadena %d en la direccion %lu",((int)(*ptr2-arreglo))+1,**ptr2,*ptr2);
	}
}
