//Cardoso Osorio Atl Yosafat.
//Codigo 11

//Estas son las librerias
#include<stdio.h>

//Esta es la declaracion de la estructura
struct elemento{
	int arreglo[5];
	int *ptr1,**ptr2;
};

//Esta es la funcion principal
void main(){
	//Declaramos las varibales y tambien fijamos las variables
	struct elemento var;
	var.ptr1 = var.arreglo;
	
	//Declaramos el ciclo para fijar y usar el puntero
	for(var.ptr2 = &var.ptr1;*var.ptr2 < &var.arreglo[5];(*var.ptr2)++){
		//Declaramos lo que se va a ingresar
		printf("\nIntroudzca un entero: ");
		scanf("%d",*var.ptr2);
	}

	//Reiniciamos el bucle
	var.ptr1 = var.arreglo;
	
	//Declramos el ciclo para fijar y usar el puntero
	for(var.ptr2 = &var.ptr1;*var.ptr2 < &var.arreglo[5];(*var.ptr2)++){
		printf("\nEn la celda %d esta el entero %d en la direccion %lu",(int)(*var.ptr2-var.arreglo),**var.ptr2,*var.ptr2);
	}
}
