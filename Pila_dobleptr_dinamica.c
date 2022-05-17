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

void meter(struct nodo**ptrRef2, int edad, char sexo){
	struct nodo *ptrNew;
	ptrNew=crearNodo(edad,sexo);
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
		printf("La edad es de %d \nEl sexo es %c\n\n",ptrRec->dato.edad,ptrRec->dato.sexo);
		ptrRec=ptrRec->ptrsig;
	}
	return;
 }
 
 int elimNodo(struct nodo **ptrRef2, int* edad, char* sexo){
		struct nodo *ptrBas;
		ptrBas=(*ptrRef2);
		if((*ptrRef2) == NULL)
			return 0;
		else if(ptrBas->ptrsig == NULL){
			(*ptrRef2)=NULL;
			*edad=ptrBas->dato.edad;
			*sexo=ptrBas->dato.sexo;
			free(ptrBas);
			return 1;
		}
		else{
			(*ptrRef2)=(*ptrRef2)->ptrsig;
			*edad=ptrBas->dato.edad;
			*sexo=ptrBas->dato.sexo;
			free(ptrBas);
			return 1;
		}
}

int main(){
	int miedad;
	char misexo;
	struct nodo **miptrRef2, *miptrRef;
	miptrRef=NULL;
	miptrRef2=&miptrRef;
	for(;;){
		switch(menu()){
			case 1:
					printf("Ingresa tu edad \n");
					scanf("%d",&miedad);
					printf("Ingresa tu sexo\n");
					fflush(stdin);
					misexo=getchar();
					meter(miptrRef2,miedad,misexo);
			break;
			case 2:
				impCont(miptrRef2);
				break;
			case 3:
				exit(0);
			break;
			case 4:
				if(elimNodo(miptrRef2,&miedad, &misexo))
					printf("La edad recuperada es %d\nEl sexo recuperado es %c \nSe elimino el nodo\n\n",miedad,misexo);
				else
					printf("La lista esta vacia\n");	
			break;
		}
	}
	
	return 0;
}
