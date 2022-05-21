#include <bits/stdc++.h>
using namespace std;

struct persona {
	char nombre[30];
	int edad;
	float est;
	char sexo;
};

int main(){
	struct persona arreglo[5];
	for(int i=0; i<5; i++){
		printf("\n Ingrese el nombre: ");
		gets(arreglo[i].nombre);
		printf("\n Ingrese la edad: ");
		scanf("%d",&arreglo[i].edad);
		fflush(stdin);
		printf("\n Ingrese el sexo: ");
		arreglo[i].sexo=getchar();
		fflush(stdin);
		printf("\n En la celda %d entra el nombre %s en la localidad de memoria: %lu \t",i,arreglo[i].nombre,&arreglo[i].nombre );
		printf("\n En la celda %d entra la edad %d en la localidad de memoria: %lu\t",i,arreglo[i].edad,&arreglo[i].edad);
		printf("\n En la celda %d entra el sexo %c en la localidad de memoria: %lu\t",i,arreglo[i].sexo,&arreglo[i].sexo);
	}
}