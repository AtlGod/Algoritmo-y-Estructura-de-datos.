//Cardoso Osorio Atl Yosafat.
//Codigo 4

//Estas son las librerias
#include<stdio.h>

//Esta es la funcion principal
void main(){
	int a,b;
	int *ptr1,**ptr2;
	//Aqui se realizan las asignaciones de las dirreciones
	ptr1 = &a;
	a = 5;
	//Aqui se vuelve a designar la direccion sobre el segundo puntero
	ptr2=&ptr1;
	b=**ptr2;
	//Se puede imprrimir por medio de los valores primitivos o tambien por medio de los punteros
	printf("\nEl valor de a: %d",a);
	printf("\nEl valor de b: %d",b);
}
