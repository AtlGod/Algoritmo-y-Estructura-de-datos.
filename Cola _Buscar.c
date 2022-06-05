// Cardoso Osorio Atl Yosafat.
#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
};

struct nodo * crearNodo(int dato1){
	struct nodo *ptrN;
	ptrN=(struct nodo *)malloc(sizeof(struct nodo));
	ptrN->dato=dato1;
	ptrN->ptrSig=NULL;
	
	return ptrN;
}

void meter(struct nodo *ptrRef, int dato1){
	struct nodo *ptrN;
	ptrN=crearNodo(dato1);
	if(ptrRef->ptrSig==NULL){
		ptrRef->ptrSig=ptrN;
	} else{
		ptrN->ptrSig=ptrRef->ptrSig;
		ptrRef->ptrSig=ptrN;
	}
}

void buscar(struct nodo *ptrRef,int dato1){
	struct nodo *ptrBusq;
	ptrBusq=ptrRef->ptrSig;
	if(ptrBusq==NULL){
		printf("La cola esta vacia\n\n");
	} else{
		while(ptrBusq->dato!=dato1 && ptrBusq->ptrSig!=NULL){
			ptrBusq=ptrBusq->ptrSig;
		}
		if(ptrBusq->dato!=dato1){
			printf("No encontrado\n\n");
		} else{
			printf("Numero encontrado\n\n");
		}
	}
}

void eliminarNumero(struct nodo *ptrRef,int dato1){
	struct nodo *ptrBas,*ptrRef2;
	ptrBas=ptrRef->ptrSig;
	ptrRef2=ptrRef;
	if(ptrBas==NULL){
		printf("La cola esta vacia\n\n");
	} else{
		while(ptrBas->dato!=dato1 && ptrBas->ptrSig!=NULL){
			ptrBas=ptrBas->ptrSig;
			ptrRef2=ptrRef2->ptrSig;
		}
		if(ptrBas->dato!=dato1){
			printf("El numero no existe en la cola\n\n");
		} else if(ptrBas->ptrSig==NULL){
			ptrRef2->ptrSig=NULL;
			printf("El numero fue eliminado\n\n");
			free(ptrBas);
		} else{
			ptrRef2->ptrSig=ptrBas->ptrSig;
			printf("El numero fue eliminado\n\n");
			free(ptrBas);
		}
	}
}

void impcadena(struct nodo *ptrRef){
	struct nodo *ptrRec;
	ptrRec=ptrRef->ptrSig;
	while(ptrRec!=NULL){
		printf("%d\n",ptrRec->dato);
		ptrRec=ptrRec->ptrSig;
	}
}

int menu(){
	int Opc;
	
	printf("Elija una de las siguientes opciones:\n");
	printf("1.Meter un numero a la cola\n2.Buscar un numero en la cola\n3.Eliminar un numero de la cola\n4.Imprimir todos los numeros de la cola\n");
	scanf("%d",&Opc);
	return Opc;
}

int main(){
	struct nodo *ptrRef;
	int miDato;
	
	ptrRef=crearNodo(-1000);
	ptrRef->ptrSig=NULL;
	
	for(;;){
		switch(menu()){
			case 1:
				printf("Inserta un numero entero\n");
				scanf("%d",&miDato);
				meter(ptrRef,miDato);
				break;
			case 2:
				printf("Inserte el numero que quiere buscar\n");
				scanf("%d",&miDato);
				buscar(ptrRef,miDato);
				break;
			case 3:
				printf("Ingrese el numero que quiere eliminar\n");
				scanf("%d",&miDato);
				eliminarNumero(ptrRef,miDato);
				break;
			case 4:
				printf("Los numeros en la cola son:\n");
				impcadena(ptrRef);
				break;
			default:
				printf("No existe esta opcion\n");
				break;
		}
	}
}


