//Cardoso Osorio Atl Yosafat.
//Codigo 13

//Esta es la libreria
#include<stdio.h>

//Esta es la estructura elemento
struct elemento{
	int arreglo[5];
	int i;
};

//Esta es la funcion principal
void main(){
	//Inicializamos las varibales y fijamos
	struct elemento var,*ptrs1,**ptrs2;
	ptrs1 = &var;
	ptrs2 = &ptrs1;
	
	//Realizamos los bucles
	for((*ptrs2)->i=0;(*ptrs2)->i<5;(*ptrs2)->i++){
	printf("\nIntroduzca un entero: ");
	scanf("%d",&(*ptrs2)->arreglo[(*ptrs2)->i]);
	}
	
	ptrs1 = &var;
	
	for((*ptrs2)->i=0;(*ptrs2)->i<5;(*ptrs2)->i++){
	printf("\nEn la celda %d esta el entero %d en la direccion %lu",(*ptrs2)->i,(*ptrs2)->arreglo[(*ptrs2)->i],&(*ptrs2)->arreglo[(*ptrs2)->i]);
	}
}
