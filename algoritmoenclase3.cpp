#include <bits/stdc++.h>
using namespace std;
struct elemento{
	int arreglo[5];
	int i;
};

int main(){
	struct elemento var,*ptrs;
	ptrs=&var;
	for(ptrs->i=0; ptrs->i<5; ptrs->i++){
		printf("\n Ingrese entero: ");
		scanf("%d",&ptrs->arreglo[ptrs->i]);
	}
	for(ptrs->i=0; ptrs->i<5; ptrs->i++){
		printf("\n En la celda %d en el dato %d en la direccion %lu",ptrs->i,ptrs->arreglo[ptrs->i],&ptrs->arreglo[ptrs->i]);
	}
}