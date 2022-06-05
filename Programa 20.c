//Cardoso Osorio Atl Yosafat.
//Codigo 20

//Esta es la libreria
#include<stdio.h>

//La declaracion para estructura
struct persona{
	char nombre[30];
	int edad;
	char sexo;
};

//La declaracion de la estructura
struct elemento{
	struct persona arreglo[5],*ptr,**ptr2;
};

//Esta es la funcion principal
void main(){
	//Declaramos y asignamos
	struct elemento var,*ptrs;
	ptrs = &var;
	ptrs->ptr = ptrs->arreglo;
	//Iniciamos el bucle de lectura
	for(ptrs->ptr2 = &ptrs->ptr;*ptrs->ptr2 < &ptrs->arreglo[5];(*ptrs->ptr2)++){
		printf("\nIntroduzca un nombre: ");
		gets((*ptrs->ptr2)->nombre);
		//Esta funcion sirve para realizar la limpieza del buffer
		fflush(stdin);
		printf("\nIntroduzca la edad: ");
		scanf("%d",&(*ptrs->ptr2)->edad);
		fflush(stdin);
		printf("\nIntroduzca el sexo: ");
		(*ptrs->ptr2)->sexo=getchar();
		fflush(stdin);
	}
	
	//Reiniciamos las operaciones
	ptrs->ptr = ptrs->arreglo;
	
	//Iniciamos con el bucle de impresion
	for(ptrs->ptr2 = &ptrs->ptr;*ptrs->ptr2 < &ptrs->arreglo[5];(*ptrs->ptr2)++){
		printf("\nEn la celda %d esta la cadena %s en la direccion %lu",(int)((*ptrs->ptr2)-ptrs->arreglo),(*ptrs->ptr2)->nombre,&(*ptrs->ptr2)->nombre);
	}
}
