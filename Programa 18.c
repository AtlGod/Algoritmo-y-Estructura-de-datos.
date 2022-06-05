//Cardoso Osorio Atl Yosafat.
//Codigo 18

//Esta es la libreria
#include<stdio.h>

//Esta es la declaracion de la estructura
struct persona{
	char nombre[30];
	int edad;
	char sexo;
};

//Otra estructura anidada
struct elemento{
	struct persona arreglo[5];
	int i;
};

//Esta es la funcion principal
void main(){
	//Declaramos y asignamos
	struct elemento var,*ptrs;
	ptrs = &var;
	//Iniciamos con el bucle
	for(ptrs->i=0;ptrs->i<5;ptrs->i++){
		printf("\nIntroduzca su nombre: ");
		gets(ptrs->arreglo[ptrs->i].nombre);
		fflush(stdin);
		printf("\nIntroduzca su edad: ");
		scanf("%d",&ptrs->arreglo[ptrs->i].edad);
		fflush(stdin);
		printf("\nIntroduzca su sexo: ");
		ptrs->arreglo[ptrs->i].sexo=getchar();
		fflush(stdin);
	}
	//Iniciamos con el bucle de impresion
	for(ptrs->i=0;ptrs->i<5;ptrs->i++){
		printf("\nEn la celda %d esta la cadena %s en la direccion %lu",ptrs->i ,ptrs->arreglo[ptrs->i].nombre, &ptrs->arreglo[ptrs->i].nombre);
	}
}
