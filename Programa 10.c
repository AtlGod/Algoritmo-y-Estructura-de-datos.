//Cardoso Osorio Atl Yosafat.
//Codigo 10

//Estas son las librerias
#include<stdio.h>

//Esta es la delclaracion de la estructura
struct elemento{
	int arreglo[5];
	int *ptr;
};

//Estta es la funcion principal
void main(){
	struct elemento var;
	//Esta es la inicializacion del bucle
	for(var.ptr=var.arreglo;var.ptr<&var.arreglo[5];var.ptr = var.ptr + 1){
		//Esta es la impresion
		printf("\nIntroduzca un entero: ");
		scanf("%d",var.ptr);
	}
	//Esta es la incializacion del bucle
	for(var.ptr=var.arreglo;var.ptr<&var.arreglo[5];var.ptr = var.ptr + 1){
		//Estas son las impresiones de los valores
		printf("\nEn la celda %d esta el entero %d en la direccion %lu",(int)(var.ptr-var.arreglo),*var.ptr,var.ptr);
	}
}
