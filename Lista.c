//Proyecto colas -Algoritm rohn Robins
//Proyecto de listas una agenda
#include <stdio.h>
#include <stdlib.h>


struct nodo{
	int dato;
	struct nodo *ptrsig;
};

struct nodo* crearNodo(int dato1){
	
	struct nodo*ptrN;
	ptrN=(struct nodo*)malloc(sizeof(struct nodo));
	ptrN->dato=dato1;
	ptrN->ptrsig=NULL;
	return ptrN;
}

int menu(){
  int i;
  printf("Que quiere hacer? \n 1. Guardar datos \n 2. Buscar numero \n 3. Eliminar número\n 4. Imprimir contenido\n 5.Salir\n ");
  scanf("%d", &i);
  return i;
}
void meter(struct nodo*ptrRef, int dato1){
	struct nodo *ptrNew,*ptrAv,*ptrRet;
	ptrNew=crearNodo(dato1);
	if(ptrRef->ptrsig == NULL){
		ptrRef->ptrsig=ptrNew;
	}
	else if((ptrRef->ptrsig)->ptrsig == NULL){
		if((ptrNew->dato)<(ptrRef->ptrsig)->dato){
			ptrNew->ptrsig=ptrRef->ptrsig;
			ptrRef->ptrsig=ptrNew;
		}else{
			(ptrRef->ptrsig)->ptrsig=ptrNew;
		}
	}
	else{
		ptrRet=ptrRef;
		ptrAv=ptrRef->ptrsig;
		while(ptrRet->ptrsig != NULL){
			if(ptrAv->dato == ptrNew->dato){
				printf("El dato esta repetido\n ");
				free(ptrNew);
				return;
			}
			if(ptrAv->dato > ptrNew->dato && (ptrRet->dato <ptrNew->dato || ptrRet==ptrRef)){
				ptrNew->ptrsig=ptrAv;
				ptrRet->ptrsig=ptrNew;
				return;
			}
			ptrAv=ptrAv->ptrsig;
			ptrRet=ptrRet->ptrsig;
			
		}
		ptrRet->ptrsig=ptrNew;
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

int searchNum (struct nodo* ptrRef, int datoSea){
	struct nodo* ptrSea;
	int bool =0;
	ptrSea=ptrRef->ptrsig;
	while(ptrSea!=NULL){
		if(ptrSea->dato == datoSea){
			bool= 1;
		}
		ptrSea=ptrSea->ptrsig;
	}
	return bool;
}

int delnum (struct nodo* ptrRef, int datoSea,int*dato){
	struct nodo *ptrBas,*ptrRec,*ptrRet;
	ptrBas=ptrRef->ptrsig;
	if(ptrRef->ptrsig == NULL){
		printf("La estructura esta vacia\n");
		return 0;
	}
	else if(ptrBas->ptrsig == NULL){
		if(ptrBas->dato == datoSea){
			ptrRef->ptrsig=NULL;
			*dato=ptrBas->dato;
			free(ptrBas);
			printf("El dato %d fue eliminado de la estructura\n",datoSea);
			return 1;
		}
		else{
			printf("El dato no se encuentra en la estrucutra\n");
			return 0;
		}
	}
	else{
		ptrRec=ptrRef->ptrsig;
		ptrRet=ptrRef;
		if(searchNum(ptrRef,datoSea)){
			while(ptrRec!=NULL){
				if(ptrRec->dato == datoSea){
					ptrRet->ptrsig=ptrRec->ptrsig;
					ptrBas=ptrRec;
					*dato=(ptrBas->dato);
					free(ptrBas);
					printf("El dato %d fue eliminado de la estructura\n",datoSea);
					return 1;
				}
				ptrRec=ptrRec->ptrsig;
				ptrRet=ptrRet->ptrsig;
			}
		}else{ 
			printf("El dato no se encuentra en la estrucutra\n");
			return 0;
		}
	}
}
	
int main(){
	int midato,midatoSea;
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
				printf("Ingresa el numero que deseas buscar\n");
				scanf("%d",&midatoSea);
				if(searchNum(miptrRef,midatoSea) == 0)
					printf("No se encontro\n");
				else{
					printf("%d esta en la estructura\n",midatoSea);
				}
				break;
			case 3: 
				printf("Ingresa el numero que deseas eliminar \n");
				scanf("%d",&midatoSea);
				delnum (miptrRef,midatoSea,&midato);
			break;
			case 4:
				impCont(miptrRef);
			break;
			
			case 5:
				exit(0);
			break;

		}
	}
		
	return 0;
	
}