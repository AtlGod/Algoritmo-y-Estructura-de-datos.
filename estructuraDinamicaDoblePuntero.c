#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrsig;
};


int menu(){
  int i;
  printf("Que quiere hacer? \n 1. Guardar datos \n 2. Exhibir contenido \n 3. Salir\n 4. Eliminar Nodo\n");
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

void meter(struct nodo**ptrRef2, int dato1){
	struct nodo *ptrNew;
	ptrNew=crearNodo(dato1);
	if((*ptrRef2) == NULL){
		(*ptrRef2)= ptrNew;
	}
	else{
		ptrNew->ptrsig=(*ptrRef2);
		(*ptrRef2)=ptrNew;
	}
	return;
}

void impCont (struct nodo** ptrRef2){
 	struct nodo* ptrRec;
	ptrRec=(*ptrRef2);
	while(ptrRec!=NULL){
		printf("%d\n",ptrRec->dato);
		ptrRec=ptrRec->ptrsig;
	}
	return;
 }

int elimNodo(struct nodo **ptrRef2, int* dato){
		struct nodo *ptrBas;
		ptrBas=(*ptrRef2);
		if((*ptrRef2) == NULL)
			return 0;
		else if(ptrBas->ptrsig == NULL){
			(*ptrRef2)=NULL;
			*dato=ptrBas->dato;
			free(ptrBas);
			return 1;
		}
		else{
			(*ptrRef2)=(*ptrRef2)->ptrsig;
			*dato=ptrBas->dato;
			free(ptrBas);
			return 1;
		}
}
int main(){
	int midato;
	struct nodo **miptrRef2,*miptrRef;
	miptrRef=NULL;
	miptrRef2=&miptrRef;

	for(;;){
		switch(menu()){
			case 1:
					printf("Ingresa entero\n");
					scanf("%d",&midato);
					meter(miptrRef2,midato);
			break;
			case 2:
				impCont(miptrRef2);
				break;
			case 3:
				exit(0);
			break;
			case 4:
				if(elimNodo(miptrRef2,&midato))
					printf("El dato recuperado es %d\nSe elimino el nodo\n",midato);
				else
					printf("La lista esta vacia\n");	
			break;
		}
	}
		
	return 0;
	
}