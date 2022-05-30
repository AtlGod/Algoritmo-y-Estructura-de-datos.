#include <stdio.h>

struct persona{
	char nombre[30];
	int edad;
	char sexo;
};

struct elemento{
	struct persona arreglo[5];
	struct persona *ptr1,**ptr2;
};

int main(){
	struct elemento var,*ptrs1,**ptrs2;
	ptrs1=&var;
	ptrs2=&ptrs1;
	for((*ptrs2)->ptr2=&(*ptrs2)->ptr1; *(*ptrs2)->ptr2<&(*ptrs2)->arreglo[5]; *(*ptrs2)->ptr2++){
		printf("\n Ingresa nombre: ");
		gets((*(*ptrs2)->ptr2)->nombre);
		printf("\n Ingresa edad: ");
		scanf("%d",&(*(*ptrs2)->ptr2)->edad);
		fflush(stdin);
		printf("\n Ingrese el sexo: ");
		(*(*ptrs2)->ptr2)->sexo=getchar();
		fflush(stdin);
	}
	for((*ptrs2)->ptr2=&(*ptrs2)->ptr1; *(*ptrs2)->ptr2<&(*ptrs2)->arreglo[5]; *(*ptrs2)->ptr2++){
	printf("\n En la celda: %d esta el nombre: %s en la direccion: %lu",(int)((*(*ptrs2)->ptr2)-(*ptrs2)->arreglo),(*(*ptrs2)->ptr2)->nombre,&(*(*ptrs2)->ptr2)->nombre);	
	printf("\n En la celda: %d esta la edad: %d en la direccion: %lu",(int)((*(*ptrs2)->ptr2)-(*ptrs2)->arreglo),(*(*ptrs2)->ptr2)->edad,&(*(*ptrs2)->ptr2)->edad);
	printf("\n En la celda: %d esta el sexo: %c en la direccion: %lu",(int)((*(*ptrs2)->ptr2)-(*ptrs2)->arreglo),(*(*ptrs2)->ptr2)->sexo,&(*(*ptrs2)->ptr2)->sexo);
	}
}
