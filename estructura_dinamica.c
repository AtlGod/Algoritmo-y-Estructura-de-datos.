#include <stdio.h>
#include <stdlib.h>



int menu(){
  int i;
  printf("Que quierstruct nodo{
	int dato;
	struct nodo *ptrsig;
};
e hacer? \n 1. Guardar datos \n 2. Exhibir contenido \n 3. Salir\n 4. Eliminar Nodo\n");
  scanf("%d", &i);
  return i;
}

struct nodo* crearNodo(int dato1){
	
	struct nodo*ptrN;
	ptrN=(struct nodo*)malloc(sizeof(struct nodo));
	ptrN->dato=dato1;
	ptrN->ptrsig=NULL;
	return ptrN;
}

void meter(struct nodo*ptrRef, int dato1){
	struct nodo *ptrNew;
	ptrNew=crearNodo(dato1);
	if(ptrRef->ptrsig == NULL){
		ptrRef->ptrsig=ptrNew;
	}
	else{
		ptrNew->ptrsig=ptrRef->ptrsig;
		ptrRef->ptrsig=ptrNew;
	}
	return;
}

void impCont (struct nodo* ptrRef){
 	struct nodo* ptrRec;
	ptrRec=ptrRef->ptrsig;
	while(ptrRec!=NULL){
		printf("%d\n",ptrRec->dato);
		ptrRec=ptrRec->ptrsig;
	}
	return;
 }

int elimNodo(struct nodo* ptrRef, int* dato){
		struct nodo *ptrBas;
		ptrBas=ptrRef->ptrsig;
		if(ptrRef->ptrsig == NULL)
			return 0;
		else if(ptrBas->ptrsig == NULL){
			ptrRef->ptrsig=NULL;
			*dato=ptrBas->dato;
			free(ptrBas);
			return 1;
		}
		else{
			ptrRef->ptrsig=ptrBas->ptrsig;
			*dato=ptrBas->dato;
			free(ptrBas);
			return 1;
		}
}
int main(){
	int midato;
	struct nodo *miptrRef;
	miptrRef=crearNodo(-1000);
	for(;;){
		switch(menu()){
			case 1:
					printf("Ingresa entero\n");
					scanf("%d",&midato);
					meter(miptrRef,midato);
			break;
			case 2:
				impCont(miptrRef);
				break;
			case 3:
				exit(0);
			break;
			case 4:
				if(elimNodo(miptrRef,&midato))
					printf("El dato recuperado es %d\nSe elimino el nodo\n",midato);
				else
					printf("La lista esta vacia\n");	
			break;
		}
	}
		
	return 0;
	
}