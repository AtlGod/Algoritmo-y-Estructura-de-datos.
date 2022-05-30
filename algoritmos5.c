#include <stdio.h>

struct persona {
	char nombre[30];
	int edad;
	char sexo;
};

int main(){
	struct persona arreglo[5],*ptr;
	for(ptr=arreglo; ptr<&arreglo[5]; ptr++){
		fflush(stdin);
		printf("\n Ingrese el nombre: ");
		gets(ptr->nombre);
		fflush(stdin);
		printf("\n Ingrese la edad: ");
		scanf("%d",&ptr->edad);
		fflush(stdin);
		printf("\n Ingrese el sexo: ");
		ptr->sexo=getchar();
		fflush(stdin);
		printf("\n En la celda %d entra el nombre %s en la localidad de memoria: %lu \t",(int)(ptr-arreglo),*ptr,ptr);
		printf("\n En la celda %d entra la edad %d en la localidad de memoria: %lu \t",(int)(ptr-arreglo),*ptr,ptr);
		printf("\n En la celda %d entra el sexo %c en la localidad de memoria: %lu \t",(int)(ptr-arreglo),*ptr,ptr);
	}
}
