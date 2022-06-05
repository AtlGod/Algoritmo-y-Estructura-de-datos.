//Cardoso Osorio Atl Yosafat.
//Codigo 7

//Estas son las librerias
#include<stdio.h>

//Esta es la funcion principal
void main(){
	//Estas son las variables
	int arreglo[5],*ptr1,**ptr2,***ptr3,****ptr4;
	//Se realizan las asignaciones de las direcciones
	ptr1 = arreglo;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	//Se empieza el bucle con la asignacion
	for(ptr4 = &ptr3;***ptr4 < &arreglo[5];(***ptr4)++){
		//Realizamos la entrada de los valores
		printf("\nIntroduzca un numero: ");
		scanf("%d",***ptr4);
	}
	//Realizamos el restablecimiento de la direccion
	ptr1 = arreglo;
	//Se empieza el bucle con la respectiva asignacion
	for(ptr4 = &ptr3;***ptr4 < &arreglo[5];(***ptr4)++){
		//Sacamos los valores por medio de las intrucciones y los valores de los punteros
		printf("\nEn la celda %d esta la cadena %d en la direccion %lu",(int)(***ptr4-arreglo),****ptr4,***ptr4);
	}
}
