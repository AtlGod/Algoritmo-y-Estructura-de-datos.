//Cardoso Osorio Atl Yosafat.
//Codigo 11

//Estas son las librerias
#include<stdio.h>

//Esta es la declaracion de la estructura
struct elemento{
	int arreglo[5];
	int i;
};

//Esta es la funcion principal
void main(){
	//Declaremos las variables y establescamos
	struct elemento var,*ptrs;
	ptrs = &var;
	//Esta es la declaracion de el ciclo y establecimiento
	for(ptrs -> i=0;ptrs -> i <5;ptrs->i++){
		//Declaramos las entradas
		printf("\nIntroduzca un entero: ");
		scanf("%d",&ptrs ->arreglo[ptrs->i]);
	}
	//Esta es la declaracion del ciclo y establecimiento
		for(ptrs -> i=0;ptrs -> i <5;ptrs->i++){
		printf("\nEn la celda %d esta el entero %d en la direccion %lu",ptrs->i,ptrs->arreglo[ptrs->i],&ptrs->arreglo[ptrs->i]);
		}		
}
