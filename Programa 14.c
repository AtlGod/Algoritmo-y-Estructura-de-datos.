//Cardoso Osorio Atl Yosafat.
//Codigo 14

//Esta es la libreria
#include<stdio.h>

//Esta es la declaracion de la estructura
struct elemento{
	int arreglo[5];
	int *ptr;
};

//Esta es la funcion principal
void main(){
	//Declaramos
	struct elemento var,*ptrs;
	ptrs = &var;
	//Usando bucles
	for(ptrs->ptr=ptrs->arreglo;ptrs->ptr<&ptrs->arreglo[5];ptrs->ptr++){
	printf("\nIntroduzca un entero: ");
	scanf("%d",ptrs->ptr);	
	}
	
	for(ptrs->ptr=ptrs->arreglo;ptrs->ptr<&ptrs->arreglo[5];ptrs->ptr++){
		printf("\nEn la celda %d esta el entero %d en la direccion %lu",(int)(ptrs->ptr-ptrs->arreglo),*ptrs->ptr,ptrs->ptr);
	}
}
