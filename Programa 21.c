//Cardoso Osorio Atl Yosafat.
//Codigo 21

//Estas son las librerias
#include<stdio.h>
#include<string.h>

//Estas son las declaraciones de estructura
struct persona{
	char nombre[30];
	int edad;
	char sexo;
};

//Esta es otra declaracion de la estructura
struct elemento{
	struct persona arreglo[5],*ptr,**ptr2;
};

//Esta es la funcion principal
void main(){
	//Declaramos y asignamos
	struct elemento var,*ptrs1,**ptrs2;
	ptrs1=&var;
	ptrs2=&ptrs1;
	(*ptrs2)->ptr = (*ptrs2)->arreglo;
	//Epezamos los ciclos de ingresar
	for((*ptrs2)->ptr2=&(*ptrs2)->ptr;*(*ptrs2)->ptr2 < &(*ptrs2)->arreglo[5];(*(*ptrs2)->ptr2)++){
		printf("\nIntroduzca nombre: ");
		gets((*(*ptrs2)->ptr2)->nombre);
		fflush(stdin);
		printf("\nIntroduzca la edad: ");
		scanf("%d",&(*(*ptrs2)->ptr2)->edad);
		fflush(stdin);
		printf("\nInntroduzca el sexo: ");
		(*(*ptrs2)->ptr2)->sexo=getchar();
		fflush(stdin);
	}
	//Hacemos el otro ciclo pero de impresion
	(*ptrs2)->ptr=(*ptrs2)->arreglo;
	for((*ptrs2)->ptr2=&(*ptrs2)->ptr;*(*ptrs2)->ptr2<&(*ptrs2)->arreglo[5];(*(*ptrs2)->ptr2)++){
		printf("\nEn la celda %d esta la cadena %s en la direccion %lu",(int)(*(*ptrs2)->ptr2-(*ptrs2)->arreglo),(*(*ptrs2)->ptr2)->nombre,&(*(*ptrs2)->ptr2)->nombre);
	}
}
