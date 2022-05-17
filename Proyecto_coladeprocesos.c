#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h>

struct nodo{
	char nomPro;
	int timeP;
	struct nodo *ptrSig;
	struct nodo *ptrAnt;
};

struct nodo* crearNodo(char name, int numRafa){
	struct nodo*ptrN;
	ptrN=(struct nodo*)malloc(sizeof(struct nodo));
	ptrN->nomPro=name;
	ptrN->timeP=numRafa;
	ptrN->ptrSig=NULL;
	ptrN->ptrAnt=NULL;
	return ptrN;
}

void meter(struct nodo*ptrRef1,struct nodo*ptrRef2, char name, int numRafa){
	struct nodo *ptrNew;
	ptrNew=crearNodo(name, numRafa);
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
	ptrRec=ptrRef2->ptrAnt;
	while(ptrRec!=ptrRef1){
		printf("El proceso %c se le asigno el tiempo %d\n",ptrRec->nomPro,ptrRec->timeP);
		ptrRec=ptrRec->ptrAnt;
	}
	return;
}

int elimNodo(struct nodo*ptrRef1,struct nodo*ptrRef2){
		struct nodo *ptrBas,*ptrAv,*ptrRet;
		if(ptrRef1->ptrSig == ptrRef2 && ptrRef2->ptrAnt == ptrRef1)
			return 0;
		else if( (ptrRef1->ptrSig)->ptrSig== ptrRef2){
			ptrBas=ptrRef1->ptrSig;
			ptrRef1->ptrSig=ptrRef2;
			ptrRef2->ptrAnt=ptrRef1;
			free(ptrBas);
			return 1;
		}
		else{
			ptrBas=ptrRef2->ptrAnt;
			ptrBas->ptrAnt->ptrSig=ptrRef2;
			ptrRef2->ptrAnt=ptrBas->ptrAnt;
			free(ptrBas);
			return 1;
		}
}

void roundRobin (struct nodo* ptrRef1,struct nodo* ptrRef2,int quantium){
	struct nodo* ptrRec;
	int rec=9;
	while(!(ptrRef1->ptrSig == ptrRef2)){
		ptrRec=ptrRef2->ptrAnt;
		int cont=0;
		if(ptrRec->timeP > quantium){
			while(cont != quantium){
				printf("El proceso %c se esta ejecutando- tiempo de ejecuccion %d Segundos\n",ptrRec->nomPro,cont+1);
				cont++;
				sleep(1);
			}
			ptrRec->timeP = (ptrRec->timeP)-quantium;
			(ptrRec->ptrAnt)->ptrSig=ptrRef2; //Se encola de nuevo
			ptrRef2->ptrAnt=ptrRec->ptrAnt;		//Se encola de nuevo
			ptrRec->ptrAnt=ptrRef1;						//Se encola de nuevo
			ptrRec->ptrSig=ptrRef1->ptrSig; 	//Se encola de nuevo
			(ptrRef1->ptrSig)->ptrAnt=ptrRec;	//Se encola de nuevo
			ptrRef1->ptrSig=ptrRec;						//Se encola de nuevo
		}
		
		else if (ptrRec->timeP == quantium){
			while(cont != quantium){
				printf("El proceso %c se esta ejecutando- tiempo de ejecuccion %d Segundos\n",ptrRec->nomPro,cont+1);
				cont++;
				sleep(1);
			}
			elimNodo(ptrRef1,ptrRef2);
		}
		
		else if(ptrRec->timeP < quantium){
			while(cont != ptrRec->timeP){
				printf("El proceso %c se esta ejecutando- tiempo de ejecuccion %d Segundos\n",ptrRec->nomPro,cont+1);
				cont++;
				sleep(1);
			}
			elimNodo(ptrRef1,ptrRef2);
		}
	}
	return;
}

int main(){
	int midato,numProc=0,minumRafa,miquantum;
	char miname;
	struct nodo *miptrRef1,*miptrRef2;
	miptrRef1=crearNodo('y',1000);
	miptrRef2=crearNodo('z',2000);
	miptrRef1->ptrSig=miptrRef2;
	miptrRef2->ptrAnt=miptrRef1;
	printf("Ingrese  procesos a realizar\n");
	scanf("%d",&numProc);
	while(numProc--){
		printf("Ingresa una  letra del abecedario para identificar al proceso\n");
		fflush(stdin);
		miname=getchar();
		fflush(stdin);
		printf("Ingresa el numero de rafagas de CPU\n");
		scanf("%d",&minumRafa);
		meter(miptrRef1,miptrRef2,miname,minumRafa);
	}
	printf("Ingresa el tiempo del quantium\n");
	scanf("%d",&miquantum);
	roundRobin(miptrRef1,miptrRef2,miquantum);
	return 0;
}

