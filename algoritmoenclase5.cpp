#include <bits/stdc++.h>
using namespace std;
struct persona{
	char nombre[30];
	int edad;
	char sexo;
};

struct elemento{
	struct persona arreglo[2];
	struct persona *ptr;
};

int main(){
	struct elemento var,*ptrs;
	ptrs=&var;
	for(ptrs->ptr=ptrs->arreglo; ptrs->ptr < &ptrs->arreglo[2]; ptrs->ptr++){
		printf("\n Ingresa nombre: ");
		gets(ptrs->ptr->nombre);
		printf("\n Ingresa edad: ");
		scanf("%d",&ptrs->ptr->edad);
		fflush(stdin);
		printf("\n Ingrese el sexo: ");
		ptrs->ptr->sexo=getchar();
		fflush(stdin);
	}
	for(ptrs->ptr=ptrs->arreglo; ptrs->ptr < &ptrs->arreglo[2]; ptrs->ptr++){
	printf("\n En la celda: %d esta el nombre: %s en la direccion: %lu",(int)(ptrs->ptr-ptrs->arreglo),ptrs->ptr->nombre,&ptrs->ptr->nombre);	
	printf("\n En la celda: %d esta la edad: %d en la direccion: %lu",(int)(ptrs->ptr-ptrs->arreglo),ptrs->ptr->edad,&ptrs->ptr->edad);
	printf("\n En la celda: %d esta el sexo: %c en la direccion: %lu",(int)(ptrs->ptr-ptrs->arreglo),ptrs->ptr->sexo,&ptrs->ptr->sexo);
	}
}