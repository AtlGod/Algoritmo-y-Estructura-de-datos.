// Cardoso Osorio Atl Yosafat.
#include <stdlib.h>
#include <stdio.h>

struct pila
{
	int arreglo[10];
	int *ptrc;
};
	
void meter(struct pila *ptrp, int dato)
{
	int ptr;
	*ptrp -> ptrc = dato;
	ptrp -> ptrc++;
}

int estallenapila(struct pila *ptrp)
{
	if(ptrp->ptrc == &ptrp->arreglo[10])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int sacar(struct pila *ptrp)
{
	ptrp -> ptrc--;
	return *ptrp -> ptrc;
}

int estavaciapila(struct pila*ptrp)
{
	if((ptrp -> ptrc) == (ptrp -> arreglo))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int menu()
{
	int opc;
	
	printf("\t Ingrese 1 para meter \n");
	printf("\t Ingrese 2 para sacar \n");
	printf("\t Ingrese 3 para salir \n");
	
	scanf("%d", &opc);
	return opc;
}

main()
{
	printf("\n\n\t\t\t Programa de pila con 10 espacios \n\n\n");
	
	struct pila mipila, *miptrp;
	int midato;
	
	miptrp = &mipila;
	miptrp -> ptrc = miptrp -> arreglo;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				if(estallenapila(miptrp))
				{
					printf("\t La pila est%c llena \n\n\n", 160);
				}
				else
				{
					printf("\t Ingrese un entero \n");
					scanf("%d", &midato);
					meter(miptrp, midato);
					printf("\t %cHecho! \n\n\n", 173);
				}
			break;
			
			case 2:
				if(estavaciapila(miptrp))
				{
					printf("\t La pila est%c vac%ca \n\n\n", 160, 161);
				}
				else
				{
					printf("\t El dato recuperado es: %d \n\n\n", sacar(miptrp));
				}
			break;
			
			case 3:
				exit(0);
			break;
			
			default:
				printf("\t %c%cINGRESE UNA OPCI%cN V%cLIDA!! \n\n\n", 173, 173, 224, 181);
			break;	
		}
	}
}
