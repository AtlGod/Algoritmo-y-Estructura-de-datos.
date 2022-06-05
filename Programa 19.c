//Cardoso Osorio Atl Yosafat.
//Codigo 19

//Estas son las librerias
#include<stdio.h>
#include<string.h>

//Estas son las estructuras
struct persona{
	char nombre[30];
	int edad;
	char sexo;
};

//Esta es otra estructura
struct elemento{
	struct persona arreglo[5],*ptr;
};

//Esta es la funcion principal
void main(){
	//Declaramos y asignamos
	struct elemento var,*ptrs;
	ptrs = &var;
	
	//Empezamos con un bucle para almacenar por medio de punteros
	for(ptrs->ptr = ptrs->arreglo;ptrs->ptr < &ptrs->arreglo[5];ptrs->ptr++){
		printf("\nIntroduzca un nombre: ");
		gets(ptrs->ptr->nombre);
		//Esta funcion fflush funciona para la limpieza del buffer
		fflush(stdin);
		printf("\nIntroduzca la edad: ");
		scanf("%d",&ptrs->ptr->edad);
		fflush(stdin);
		printf("\nIntroduzca el sexo: ");
		ptrs->ptr->sexo = getchar();
		fflush(stdin);
	}
	
	//Empezamos con un bucle para la impresion de los datos
	for(ptrs->ptr = ptrs->arreglo;ptrs->ptr < &ptrs->arreglo[5];ptrs->ptr++){
		printf("\nEn la celda %d esta la cadena %s en la direccion %lu",(int)(ptrs->ptr-ptrs->arreglo),ptrs->ptr->nombre,&ptrs->ptr->nombre);
	}
}

