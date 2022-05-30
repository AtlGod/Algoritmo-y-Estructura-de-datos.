#include <stdio.h>


struct elemento{
	int arreglo[5];
	int i;
};

int main(){
	struct elemento var;
	for(var.i=0; var.i<5; var.i++){
		printf("\n Ingrese entero: ");
		scanf("%d",&var.arreglo[var.i]);
	}
	for(var.i=0; var.i<5; var.i++){
		printf("\n En la celda %d en el dato %d en la direccion %lu",var.i,var.arreglo[var.i],&var.arreglo[var.i]);
	}
}
