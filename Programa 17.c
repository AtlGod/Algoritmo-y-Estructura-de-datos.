//Cardoso Osorio Atl Yosafat.
//Codigo 17

//Esta es la libreria
#include<stdio.h>

//Esta es la definicion de la estructura
struct elemento{
	int arreglo[5];
	int *ptr,**ptr2;
};

//Esta es la funcion principal
void main(){
	//Estas son las declaraciones y asignaciones
	struct elemento var,*ptrs,**ptrs2;
	ptrs = &var;
	ptrs2 = &ptrs;
	(*ptrs2)->ptr = (*ptrs2)->arreglo;
	//Iniciamos bucles
	for((*ptrs2)->ptr2 = &(*ptrs2)->ptr;*(*ptrs2)->ptr2 < &(*ptrs2)->arreglo[5];(*(*ptrs2)->ptr2)++){
		printf("\nIntroduzca un entero: ");
		scanf("%d",*(*ptrs2)->ptr2);
	}
	
	//Reasignamos el valor
	(*ptrs2)->ptr = (*ptrs2)->arreglo;
	
	for((*ptrs2)->ptr2 = &(*ptrs2)->ptr;*(*ptrs2)->ptr2 < &(*ptrs2)->arreglo[5];(*(*ptrs2)->ptr2)++){
		printf("\nEn la celda %d esta el entero %d en la direccion %lu",(int)(*(*ptrs2)->ptr2-(*ptrs2)->arreglo),**(*ptrs2)->ptr2,*(*ptrs2)->ptr2);
	}
}
