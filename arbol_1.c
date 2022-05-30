#include<stdio.h>
#include<stdlib.h>

struct nodo {
	int elemento;
	struct nodo *hijo_izq;
	struct nodo *hijo_der;
};

void insertar(int x, struct nodo **ptra);
void imprimirarbol(struct nodo *ptra, int contador);

int main()
{
	int op, val, contador=1;
	struct nodo *ptr1, **ptr2;
	ptr2=&ptr1;
	ptr1=NULL;
	
	do
	{
		printf ("\n\nIngrese una de las siguientes opciones\n\n");
		printf ("1. Ingresar valores\n");
		printf ("2. Mostrar arbol\n");
		printf ("3. Salir\n");
		
		scanf ("%d",&op);
		switch (op)
		{
			case 1: printf ("Ingrese el valor\n");
					scanf ("%d",&val);
					insertar(val,ptr2);
				break;
			case 2:
					imprimirarbol(ptr1,contador);
				break;
		}
	}
	while (op!=3);
	
	return 0;
}

void insertar(int x, struct nodo **ptra)
{
	if (*ptra==NULL)
	{
		*ptra=(struct nodo *)malloc(sizeof(struct nodo));
		(*ptra)->hijo_izq=NULL;
		(*ptra)->hijo_der=NULL;
		(*ptra)->elemento=x;
	}
	else 
		if (x<(*ptra)->elemento)
			insertar(x,&(*ptra)->hijo_izq);
		else
			insertar(x,&(*ptra)->hijo_der);
}

void imprimirarbol(struct nodo *ptra, int contador)
{
	int i,j;
	i=contador;
	if (ptra!=NULL)
	{
		imprimirarbol(ptra->hijo_der,i+1);
		printf ("\n");
		for (j=1;j<i;j++)
			printf ("-");
		printf ("%d",ptra->elemento);
		imprimirarbol(ptra->hijo_izq,i+1);
	}
}
