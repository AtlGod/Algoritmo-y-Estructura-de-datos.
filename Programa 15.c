//Cardoso Osorio Atl Yosafat.
//Codigo 15

//Esta es la libreria
#include<stdio.h>

//Esta es la declaracion de la estructura
struct elemento{
	int arreglo[5];
	int *ptr,**ptr2;
};

//Esta es la funcion principal
void main(){
	//Declaramos
	struct elemento var,*ptrs;
	ptrs = &var;
	ptrs->ptr = ptrs->arreglo;
	
	//Realizamos los bucles
	for(ptrs->ptr2=&ptrs->ptr;*ptrs->ptr2<&ptrs->arreglo[5];(*ptrs->ptr2)++){
	printf("\nIntroduzca un enetero: ");
	scanf("%d",*ptrs->ptr2);
	}
	
	ptrs->ptr = ptrs->arreglo;
	
	for(ptrs->ptr2=&ptrs->ptr;*ptrs->ptr2<&ptrs->arreglo[5];(*ptrs->ptr2)++){
	printf("\nEn la celda %d esta el entero %d en la direccion %lu",(int)(*ptrs->ptr2-ptrs->arreglo),**ptrs->ptr2,*ptrs->ptr2);
	}
}
