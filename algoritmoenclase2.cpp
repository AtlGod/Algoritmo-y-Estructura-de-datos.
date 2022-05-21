#include <bits/stdc++.h>
using namespace std;
struct elemento{
	int arreglo[5];
	int *ptr;
};

int main(){
	struct elemento var;
	for(var.ptr=var.arreglo; var.ptr<&var.arreglo[5]; var.ptr++){
		printf("\n Ingrese entero: ");
		scanf("%d",var.ptr);
	}
	for(var.ptr=var.arreglo; var.ptr<&var.arreglo[5]; var.ptr++){
		printf("\n En la celda %d en el dato %d en la direccion %lu",(int)(var.ptr-var.arreglo),*var.ptr,var.ptr);
	}
}