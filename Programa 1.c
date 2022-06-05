// Cardoso Osorio Atl Yosafat.
//Codigo 1
#include<stdio.h>

void main(){
	int arreglo[5],*ptr;
	for(ptr = arreglo;ptr < &arreglo[5];ptr = ptr + 1){
		printf("Ingresa un entero: ");
		scanf("%d",ptr);
	}
	
	for(ptr=arreglo;ptr< &arreglo[5];ptr = ptr + 1){
		printf("\nEn la celda %d esta el valor %d en la direccion de memoria %lu",(int)(ptr-arreglo),*ptr,ptr);
	}
}
