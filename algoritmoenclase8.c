#include <stdio.h>
#include<stdlib.h>


struct pila{
	int arreglo[10];
	int *ptrc;
};

int estavaciapila(struct pila *ptrp){
	if(ptrp->ptrc==ptrp->arreglo){
		return 1;
	}
	else{
		return 0;
	}
}

void push(struct pila *ptrp, int dato){
	*ptrp->ptrc=dato;
	ptrp->ptrc++;
	
}

int estallenapila(struct pila *ptrp){
	if (ptrp->ptrc== &ptrp->arreglo[10]){
	return 1;
	} 
	else {
		return 0;
	}
}

int pop(struct pila *ptrp){
	ptrp->ptrc--;
	return (*ptrp->ptrc);
	
}

int menu(){
  int opcion;
	menu:
		printf ("Menu de Opciones \n");
		printf ("1) Ingresar datos  \n"); 
		printf ("2) Leer datos \n"); 
		printf ("3) EXIT \n"); 
		printf("Ingrese la opcion que quiere hacer: ");
		scanf ("%i", &opcion); 

  return opcion;
}

int main(){
	int midato;
	struct pila mipila,*miptrp;
	miptrp=&mipila;
	miptrp->ptrc=miptrp->arreglo;
	for(;;){
		switch(menu()){
			case 1: 
				if(estallenapila(miptrp))
				printf("\n La pila ya esta llena ");
				else{
					printf("\n Ingrese un entero: ");
					scanf("%d",&midato);
					push (miptrp,midato);
				}
				break;
				case 2:
				if(estavaciapila(miptrp))
				printf("\n La pila esta vacia ");
				else{
					printf("\n El dato recuperado es: %d",pop(miptrp));
				}
				
				return 0;
				break;
				case 3:
					printf ("\n Exit...");
					exit(0);
		}
	}
	return 0;
}
