//Cola con apuntador simple
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

int elimNodo(struct nodo*ptrRef, int* dato){
		struct nodo *ptrBas,*ptrAv,*ptrRet;
		
		if(ptrRef->ptrsig == NULL)
			return 0;
		else if( (ptrRef->ptrsig)->ptrsig== NULL){
			ptrBas=ptrRef->ptrsig;
			ptrRef->ptrsig=NULL;
			*dato=ptrBas->dato;
			free(ptrBas);
			return 1;
		}
		else{
			ptrAv=ptrRef->ptrsig;
			ptrRet=ptrRef;
			while(ptrAv->ptrsig != NULL){
				ptrAv=ptrAv->ptrsig;
				ptrRet=ptrRet->ptrsig;
			}
			ptrBas=ptrAv;
			ptrRet->ptrsig=NULL;
			ptrAv=ptrRet;
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
