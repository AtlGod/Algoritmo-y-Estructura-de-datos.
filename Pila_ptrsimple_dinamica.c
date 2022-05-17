#include <stdio.h>
#include <stdlib.h>

struct Dato{
	int edad;
	char sexo;
};

struct nodo{
	struct Dato dato;
	struct nodo *ptrsig;
};

int menu(){
  int i;
  printf("Que quiere hacer? \n 1. Guardar datos \n 2. Exhibir contenido \n 3. Salir\n 4. Eliminar Nodo\n");
  scanf("%d", &i);
  return i;
}

struct nodo* crearNodo(int edad1, char sexo1){
	struct nodo*ptrN;
	ptrN=(struct nodo*)malloc(sizeof(struct nodo));
	ptrN->dato.edad=edad1;
	ptrN->dato.sexo=sexo1;
	ptrN->ptrsig=NULL;
	return ptrN;
}

void meter(struct nodo*ptrRef, int edad1, char sexo1){
	struct nodo *ptrNew;
	ptrNew=crearNodo(edad1,sexo1);
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
		printf("La edad es de %d \nEl sexo es %c\n\n",ptrRec->dato.edad,ptrRec->dato.sexo);
		ptrRec=ptrRec->ptrsig;
	}
	return;
}

int elimNodo(struct nodo* ptrRef, int* edad, char *sexo){
	struct nodo *ptrBas;
	ptrBas=ptrRef->ptrsig;
	if(ptrRef->ptrsig == NULL)
		return 0;
	else if(ptrBas->ptrsig == NULL){
		ptrRef->ptrsig=NULL;
		*edad=ptrBas->dato.edad;
		*sexo=ptrBas->dato.sexo;
		free(ptrBas);
		return 1;
		}
	else{
		ptrRef->ptrsig=ptrBas->ptrsig;
		*edad=ptrBas->dato.edad;
		*sexo=ptrBas->dato.sexo;
			free(ptrBas);
			return 1;
		}
}

int main(){
	int miedad;
	char misexo;
	struct nodo *miptrRef;
	miptrRef=crearNodo(-1000,'M');
	for(;;){
		switch(menu()){
			case 1:
					printf("Ingresa tu edad \n");
					scanf("%d",&miedad);
					printf("Ingresa tu sexo\n");
					fflush(stdin);
					misexo=getchar();
					meter(miptrRef,miedad,misexo);
			break;
			case 2:
				impCont(miptrRef);
				break;
			case 3:
				exit(0);
			break;
			case 4:
				if(elimNodo(miptrRef,&miedad, &misexo))
					printf("La edad recuperada es %d\nEl sexo recuperado es %c \nSe elimino el nodo\n",miedad,misexo);
				else
					printf("La lista esta vacia\n");	
			break;
		}
	}
	
	return 0;
}
