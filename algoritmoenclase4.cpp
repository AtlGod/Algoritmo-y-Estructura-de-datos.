#include <bits/stdc++.h>
using namespace std;
struct elemento{
	int arreglo[5];
	int *ptr;
};

int main(){
	struct elemento var,*ptrs;
	ptrs=&var;
	for(ptrs->ptr=ptrs->arreglo; ptrs->ptr < &ptrs->arreglo[5]; ptrs->ptr++){
		printf("\n Ingrese entero: ");
		scanf("%d",ptrs->ptr);
	}
	for(ptrs->ptr=ptrs->arreglo; ptrs->ptr < &ptrs->arreglo[5]; ptrs->ptr++){
		printf("\n En la celda %d en el dato %d en la direccion %lu",(int)(ptrs->ptr-ptrs->arreglo),*ptrs->ptr,ptrs->ptr);
	}
}