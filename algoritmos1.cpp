#include <bits/stdc++.h>

int arreglo[5];
int *ptr;
using namespace std;

int main()
{
	for(ptr=arreglo; ptr<&arreglo[5]; ptr=ptr+1)
	{
		printf("ingrese entero: ");
		scanf("%d",ptr);
		for(ptr=arreglo; ptr<&arreglo[5]; ptr++)
		{
			printf("\n En la celda %d esta el valor %d en %lu",(int)(ptr-arreglo),*ptr,ptr);
		}
	}
}
