//Cardoso Osorio Atl Yosafat.
//Codigo 16

//Esta es la libreria
#include<stdio.h>

//Esta es la declaracion de la estructura
struct elemento{
	int arreglo[5];
	int *ptr;
};

//Esta es la funcion principal
void main(){
	//Declaramos y asignamos
	struct elemento var,*ptrs,**ptrs2;
	ptrs = &var;
	ptrs2 = &ptrs;
	
	//Iniciamos los bucles
	for((*ptrs2)->ptr = (*ptrs2)->arreglo;(*ptrs2)->ptr<&(*ptrs2)->arreglo[5];((*ptrs2)->ptr)++){
	printf("\nIntroduzca un numero: ");
	scanf("%d",(*ptrs2)->ptr);	
	}
	
	for((*ptrs2)->ptr = (*ptrs2)->arreglo;(*ptrs2)->ptr<&(*ptrs2)->arreglo[5];((*ptrs2)->ptr)++){
		printf("\nEn la celda %d esta el entero %d en la direccion %lu",(int)((*ptrs2)->ptr-(*ptrs2)->arreglo),*(*ptrs2)->ptr,(*ptrs2)->ptr);
	}
}
