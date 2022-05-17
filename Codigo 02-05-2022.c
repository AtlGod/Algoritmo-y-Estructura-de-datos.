//Codigo 02-05-2022
//meter/encontrar funcion eliminar
/*1.- Funcion meter igual a los anteriores
2.-Funcion encontrar
pedira un numero   10 si se encontro 
					12 no se encontro
					10 no se envontro
3.- Funcion  eliminar 10 se elimino n:10
pedira el numero    12 no se pudo eliminar el numero por que no existe
*/
#include <stdlib.h>
#include <stdio.h>
struct nodo{
	int dato;
	struct nodo *ptrSig;
};

struct nodo *crearNodo(int dato1){
	struct nodo *ptrN;
	ptrN=(struct nodo*)malloc(sizeof(struct nodo));
	ptrN->dato=dato1;
	ptrN->ptrSig=NULL;
	return ptrN;
};
	
void meter(struct nodo *ptrRef, int dato1){
	struct nodo *ptrNew;
	ptrNew=crearNodo(dato1);
	
	if(ptrRef->ptrSig==NULL)
		ptrRef->ptrSig=ptrNew;
	else{
		ptrNew->ptrSig=ptrRef->ptrSig;
		ptrRef->ptrSig=ptrNew;
	}		
}

void impCont(struct nodo *ptrRef){
	struct nodo *ptrRec;
	ptrRec=ptrRef->ptrSig;
		while(ptrRec!=NULL){
			printf("\n%d", ptrRec->dato);
			ptrRec=ptrRec->ptrSig;
		}
	printf("\n\n");
}
void encontrarNum(struct nodo *ptrRef, int numb){
	struct nodo *ptrRec;
	ptrRec=ptrRef->ptrSig;
		while(ptrRec!=NULL){
			if(ptrRec->dato==numb){
			printf("\nEl numero fue encontrado");
			printf("\n%d", ptrRec->dato);
break;
}
			ptrRec = ptrRec->ptrSig;
		printf("\nEl numero no fue encontrado");
			}
	printf("\n\n");
}

void borrarNodo(struct nodo *ptrRef){
	struct nodo *ptrBas;
	if(ptrRef->ptrSig==NULL){
		printf("\nNo hay nodos creados");
	}
	else{
		ptrBas=ptrRef->ptrSig;
		ptrRef->ptrSig=ptrBas->ptrSig;
		printf("\nEl ultimo dato era: %d\n", ptrBas->dato);
		free(ptrBas);
	}
}

int menu(){
	int op;
	printf("\t\t\tMenu");
	printf("\n1.- Ingresar dato");
	printf("\n2.- Encontrar un numero especifico");
	printf("\n3.- Imprimir datos existentes");
	printf("\n4.- Borrar dato especifico");
	printf("\n5.- Salir\n");
	printf("Teclee el digito de la opcion que desea realizar: ");
	scanf("%d", &op);
	return op;
	fflush(stdin);
}

int main(int argc, char *argv[]) {
	struct nodo *miptrRef;
	int midato, op, numb;
	
	miptrRef=crearNodo(-1000);
	for(;;){
		switch (menu()){
			case 1:
				printf("\nIngrese un entero: ");
				scanf("%d", &midato);
				meter(miptrRef, midato);
				break;
			case 2:
				printf("\nIngrese un entero a buscar: ");
				scanf("%d", &numb);
				encontrarNum(miptrRef, numb);
			case 3:
				impCont(miptrRef);
				break;
			case 4:
				borrarNodo(miptrRef);
				break;
			case 5:
				exit(0);
				break;
				
		}
	}
	return 0;
}
