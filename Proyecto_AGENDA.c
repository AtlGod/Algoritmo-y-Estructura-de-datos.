// Cardoso Osorio Atl Yosafat.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nodo{
	char nombre[100];
	char direccion[100];
	int numero;
	struct nodo*ptrsiguiente;
};
struct nodo*crearn(char*nombre,char*direccion,int numero){
	struct nodo*ptrn;
	ptrn = (struct nodo*)malloc(sizeof(struct nodo));
	strcpy(ptrn->nombre,nombre);
	strcpy(ptrn->direccion,direccion);
	ptrn->numero = numero;
	ptrn->ptrsiguiente = NULL;
	return ptrn;
}
int comp(struct nodo*ptrCmp,struct nodo*ptrnew,int contador){
	if(ptrnew->nombre[contador] > ptrCmp->nombre[contador]){
		return 1;
	}else if(ptrnew->nombre[contador] == ptrCmp->nombre[contador]){
		comp(ptrCmp,ptrnew,contador+1);
	}else{
		return 0;
	}
}
void insertarn(struct nodo*ptrreferencia,char*nombre,char*direccion,int numero){
	struct nodo*ptrnew,*ptrav,*ptrret;
	ptrnew = crearn(nombre,direccion,numero);
	ptrav = ptrreferencia->ptrsiguiente;
	ptrret = ptrreferencia;
	if(ptrreferencia->ptrsiguiente == NULL){
		ptrreferencia->ptrsiguiente = ptrnew;
	}else if(ptrreferencia->ptrsiguiente->ptrsiguiente == NULL){
		if(strcmp(ptrav->nombre,ptrnew->nombre) == 0){
			printf("\nEl contacto ya es existente");
			free(ptrnew);
			return;
		}
		else if(comp(ptrav,ptrnew,0) == 0){
			ptrnew->ptrsiguiente = ptrreferencia->ptrsiguiente;
			ptrreferencia->ptrsiguiente = ptrnew;
		}
		else{
			ptrreferencia->ptrsiguiente->ptrsiguiente = ptrnew;
		}
	}
	else{
		while(ptrret->ptrsiguiente != NULL){
			if(strcmp(ptrav->nombre,ptrnew->nombre) == 0){
				printf("\nEl contacto ya es existente");
				free(ptrnew);
				return;
			}
			else if(comp(ptrav,ptrnew,0) == 0 && comp(ptrret,ptrnew,0) == 1){
				ptrnew->ptrsiguiente = ptrav;
				ptrret->ptrsiguiente = ptrnew;
				return;
			}
			ptrav = ptrav->ptrsiguiente;
			ptrret = ptrret->ptrsiguiente;
		}
		ptrret->ptrsiguiente = ptrnew;
	}
	return;
}
int buscar(struct nodo*ptrreferencia,char*nombre){
	struct nodo*ptrBus;
	ptrBus = ptrreferencia->ptrsiguiente;
	
	if(ptrBus != NULL){
	while(ptrBus != NULL){
		if(strcmp(ptrBus->nombre,nombre) == 0){
			return 1;
		}
		ptrBus = ptrBus->ptrsiguiente;
	}
	}else{
		return 0;
	}
}
void eliminarAgenda(struct nodo*ptrreferencia,char*nombre){
	struct nodo*ptrBas,*ptrav,*ptrret;
	ptrBas = ptrreferencia->ptrsiguiente;
	ptrav = ptrreferencia->ptrsiguiente;
	ptrret = ptrreferencia;
	
	if(ptrBas == NULL){
		printf("\nLa agenda esta totalmente vacia");
		return;
	}else if(ptrBas->ptrsiguiente == NULL){
		if(strcmp(ptrBas->nombre,nombre) == 0){
			ptrreferencia->ptrsiguiente = NULL;
			free(ptrBas);
			printf("\nEl contacto con nombre: %s fue elimninado",nombre);
			return;
		}else{
			printf("\nEl contacto no se encuantra en la agenda");
			return;
		}
	}
	else{
		if(buscar(ptrreferencia,nombre) == 1){
			while(ptrav != NULL){
				if(strcmp(ptrav->nombre,nombre) == 0){
					ptrBas = ptrav;
					ptrret->ptrsiguiente = ptrav->ptrsiguiente;
					free(ptrBas);
					printf("\nEl contacto: %s fue quitado de la agenda",nombre);
					return;
				}
				ptrav = ptrav->ptrsiguiente;
				ptrret = ptrret->ptrsiguiente;
			}
		}
		else{
			printf("\nNadie coincide dentro de la agenda");
			return;
		}
	}
	return;
}
void imprimir(struct nodo*ptrreferencia){
	struct nodo*ptrrec;
	ptrrec = ptrreferencia->ptrsiguiente;
	if(ptrrec == NULL){
		printf("\nLa agenda se encuntra vacia");
	}
	while(ptrrec != NULL){
		printf("\nSu nombre es: %s",ptrrec->nombre);
		printf("\nSu direccion es: %s",ptrrec->direccion);
		printf("\nSu numero: %d",ptrrec->numero);
		printf("\n");
		ptrrec = ptrrec->ptrsiguiente;
		}
}
int main(){
	int numero;
	char nombre [50],direccion[50];
	struct nodo*ptrreferencia;
	ptrreferencia = crearn("NULL","NULL",-1000);
	
	for(;;){
	int op;
	printf("\tBIENVENIDO A LA AGENDA\n");
	
	printf("\n1. Ingresar un contacto");
	printf("\n2. Buscar un contacto");
	printf("\n3. Eliminar un contacto");
	printf("\n4. Imprimir la agenda");
	printf("\n5. Salir\n");
	
	printf("\nElige una opcion: ");
	scanf("%d",&op);
	fflush(stdin);
	if(op==1){	
		printf("\nIntroduzca el nombre: ");
		gets(nombre);
		fflush(stdin);
		printf("\nIntroduzca la direccion: ");
		gets(direccion);
		fflush(stdin);
		printf("\nIntroduzca el numero: ");
		scanf("%d",&numero);
		fflush(stdin);
		insertarn(ptrreferencia,nombre,direccion,numero);
	}
	else if(op==2){
		printf("\nIntroduce el nombre del contacto a econtrar: ");
		gets(nombre);
		fflush(stdin);
		if(buscar(ptrreferencia,nombre) == 0){
			printf("\nEl contacto NO existe en la agenda");
		}else{
			printf("\nEl contacto SI existe en la agenda");
		}
	}
	else if(op==3){
		printf("\nIntroduce el nombre del contacto a eliminar:");
		gets(nombre);
		fflush(stdin);
		eliminarAgenda(ptrreferencia,nombre);
	}
	else if(op==4){
		imprimir(ptrreferencia);

	}
	else if(op==5){
		return(0);
	}
}	
	return 0;
}
