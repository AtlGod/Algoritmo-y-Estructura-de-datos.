#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
	struct nodo *ptrAnt;
};

int menu(){
  int i;
  printf("Que quiere hacer? \n 1. Guardar datos \n 2. Exhibir contenido \n 3. Eliminar nodo\n 4. Salir\n");
  scanf("%d", &i);
  return i;
}

struct nodo* crearNodo(int dato1){
	struct nodo* ptrN;
	ptrN=(struct nodo*)malloc(sizeof(struct nodo));
	ptrN->dato=dato1;
	ptrN->ptrSig=NULL;
	ptrN->ptrAnt=NULL;
	return ptrN;
}

void meter(struct nodo *ptrRef, int dato1){
	struct nodo *ptrNew;
	ptrNew=crearNodo(dato1);
	if(ptrRef->ptrAnt==ptrRef){ //Condición en la que la cola esta vacia
		ptrNew->ptrAnt=ptrRef;
		ptrRef->ptrSig=ptrNew;
		ptrNew->ptrSig=ptrRef;
		ptrRef->ptrAnt=ptrNew;
	}
	else{//Hay más elementos
		ptrNew->ptrSig= ptrRef->ptrSig;
		ptrRef->ptrSig->ptrAnt=ptrNew;
		ptrRef->ptrSig=ptrNew;
		ptrNew->ptrAnt=ptrRef;
	}
	return;
}

void impCont (struct nodo* ptrRef){
 	struct nodo* ptrRec;
	ptrRec=ptrRef->ptrSig;
	while(ptrRec!=ptrRef){
		printf("%d\n",ptrRec->dato);
		ptrRec=ptrRec->ptrSig;
	}
	return;
}
int elimNodo(struct nodo*ptrRef, int* dato){
		struct nodo *ptrBas;
		
		if(ptrRef->ptrAnt==ptrRef)
			return 0;
		else if( (ptrRef->ptrSig)->ptrSig== ptrRef){
			ptrBas=ptrRef->ptrSig;
			ptrRef->ptrSig=ptrRef;
			ptrRef->ptrAnt=ptrRef;
			*dato=ptrBas->dato;
			free(ptrBas);
			return 1;
		}
		else{
			ptrBas=ptrRef->ptrAnt;
			(ptrRef->ptrAnt)->ptrAnt->ptrSig=ptrRef;
			ptrRef->ptrAnt=(ptrRef->ptrAnt)->ptrAnt;
			*dato=ptrBas->dato;
			free(ptrBas);
			return 1;
		}
}
int main(){
	int midato;
	struct nodo *miptrRef;
	miptrRef =crearNodo(-1000);
	miptrRef->ptrSig=miptrRef;
	miptrRef->ptrAnt=miptrRef;
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
				if(elimNodo(miptrRef,&midato))
					printf("El dato recuperado es %d\nSe elimino el nodo\n",midato);
				else
					printf("La lista esta vacia\n");	
				
			break;
			case 4:
					exit(0);
			break;
		}
	}
	return 0;
}