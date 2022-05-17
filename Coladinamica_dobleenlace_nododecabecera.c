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
	struct nodo*ptrN;
	ptrN=(struct nodo*)malloc(sizeof(struct nodo));
	ptrN->dato=dato1;
	ptrN->ptrSig=NULL;
	ptrN->ptrAnt=NULL;
	return ptrN;
}

void meter(struct nodo*ptrRef1,struct nodo*ptrRef2, int dato1){
	struct nodo *ptrNew;
	ptrNew=crearNodo(dato1);
	if(ptrRef1->ptrSig == ptrRef2 && ptrRef2->ptrAnt == ptrRef1){ //Condición en la que la cola esta vacia
		ptrNew->ptrSig=ptrRef2;
		ptrRef2->ptrAnt=ptrNew;
		ptrNew->ptrAnt=ptrRef1;
		ptrRef1->ptrSig=ptrNew;
	}
	else{//Hay más elementos
		ptrNew->ptrSig=ptrRef1->ptrSig;
		ptrRef1->ptrSig->ptrAnt=ptrNew; 
		ptrRef1->ptrSig=ptrNew; 
		ptrNew->ptrAnt=ptrRef1;
	}
	return;
}

void impCont (struct nodo* ptrRef1,struct nodo* ptrRef2){
 	struct nodo* ptrRec;
	ptrRec=ptrRef1->ptrSig;
	while(ptrRec!=ptrRef2){
		printf("%d\n",ptrRec->dato);
		ptrRec=ptrRec->ptrSig;
	}
	return;
}
int elimNodo(struct nodo*ptrRef1,struct nodo*ptrRef2, int*dato){
		struct nodo *ptrBas,*ptrAv,*ptrRet;
		if(ptrRef1->ptrSig == ptrRef2 && ptrRef2->ptrAnt == ptrRef1)
			return 0;
		else if( (ptrRef1->ptrSig)->ptrSig== ptrRef2){
			ptrBas=ptrRef1->ptrSig;
			ptrRef1->ptrSig=ptrRef2;
			ptrRef2->ptrAnt=ptrRef1;
			*dato=ptrBas->dato;
			free(ptrBas);
			return 1;
		}
		else{
			ptrBas=ptrRef2->ptrAnt;
			ptrBas->ptrAnt->ptrSig=ptrRef2;
			ptrRef2->ptrAnt=ptrBas->ptrAnt;
			*dato=ptrBas->dato;
			free(ptrBas);
			return 1;
		}
}
int main(){
	int midato;
	struct nodo *miptrRef1,*miptrRef2;
	miptrRef1=crearNodo(-1000);
	miptrRef2=crearNodo(-2000);
	miptrRef1->ptrSig=miptrRef2;
	miptrRef2->ptrAnt=miptrRef1;
	for(;;){
		switch(menu()){
			case 1:
					printf("Ingresa entero\n");
					scanf("%d",&midato);
					meter(miptrRef1,miptrRef2,midato);
			break;
			case 2:
				impCont(miptrRef1,miptrRef2);
				break;
			case 3:
				if(elimNodo(miptrRef1,miptrRef2,&midato))
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