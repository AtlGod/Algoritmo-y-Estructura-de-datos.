#include <stdio.h>
#include <stdlib.h>

//
// Contreras Ramírez Angel - ARCYNTRAR - 29/04/22
//
// Cola Círcular
//

// ------------------------------------
// Estructuras
// ------------------------------------

struct Nodo{
	int dato;
	struct Nodo *ptrSig;
	struct Nodo *ptrAnt;
};

// ------------------------------------
// Prototipos
// ------------------------------------

struct Nodo * crearNodo(int);
void insertarNodo(struct Nodo *, int);
int sacarNodo(struct Nodo *);
void recorrerNodos(struct Nodo *);
int menu();

// ------------------------------------
// Main
// ------------------------------------

int main(){
	struct Nodo *ptrReferencia;
	int dato, nodoEliminado;
	ptrReferencia = crearNodo(-1000);
	ptrReferencia->ptrSig = ptrReferencia;
	ptrReferencia->ptrAnt = ptrReferencia;
	
	printf("Cola Circular");
	
	for(;;){
		switch(menu()){
			case 1:
				printf("\nIngrese el dato del Nodo: ");
				scanf("%d", &dato);
				fflush(stdin);
				insertarNodo(ptrReferencia, dato);				
				break;
			case 2:
				nodoEliminado = sacarNodo(ptrReferencia);
				if(nodoEliminado == -1000)
					printf("\nLa cola esta vacia");
				else{
					printf("\nNodo eliminado");
					printf("\nEl nodo eliminado contenia el siguiente dato: %d", nodoEliminado);
				}				
				break;
			case 3:
				recorrerNodos(ptrReferencia);
				break;
			case 4:
				exit(0);
				break;
			default:
				break;		
		}
	}

}

// ------------------------------------
// Funciones
// ------------------------------------

int menu(){
	int opcion;
	printf("\n\n----------------------------------------");
	printf("\nMenu de opciones:");
	printf("\n1.- Insertar Nodo");
	printf("\n2.- Sacar Nodo");
	printf("\n3.- Mostrar Nodos");
	printf("\n4.- Salir del programa");
	printf("\n\nOpcion: ");
	scanf("%d", &opcion);
	fflush(stdin);
	
	return opcion;
}

struct Nodo * crearNodo(int fDato){
	struct Nodo *ptrNuevo;	
	ptrNuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	ptrNuevo->dato = fDato;
	ptrNuevo->ptrAnt = NULL;
	ptrNuevo->ptrSig = NULL;
	return ptrNuevo;
}

void insertarNodo(struct Nodo *ptrReferencia, int fDato){
	struct Nodo *ptrNuevo;
	ptrNuevo = crearNodo(fDato);
	
	if(ptrReferencia->ptrSig == ptrReferencia && ptrReferencia->ptrAnt == ptrReferencia){
		ptrNuevo->ptrSig = ptrReferencia;
		ptrNuevo->ptrAnt = ptrReferencia;
		ptrReferencia->ptrSig = ptrNuevo;
		ptrReferencia->ptrAnt = ptrNuevo;
	}else{ 
		ptrNuevo->ptrSig = ptrReferencia->ptrSig;
		ptrNuevo->ptrAnt = ptrReferencia;
		ptrNuevo->ptrSig->ptrAnt = ptrNuevo;
		ptrReferencia->ptrSig = ptrNuevo;
	}
}

int sacarNodo(struct Nodo *ptrReferencia){
	struct Nodo *ptrBasura;
	int dato;
	
	if(ptrReferencia->ptrAnt == ptrReferencia)
		return -1000; 
	else if(ptrReferencia->ptrAnt->ptrAnt == ptrReferencia){
		ptrBasura = ptrReferencia->ptrAnt;
		dato = ptrBasura->dato;
		ptrReferencia->ptrSig = ptrReferencia;
		ptrReferencia->ptrAnt = ptrReferencia;
		free(ptrBasura);
		return dato;
	}else{
		ptrBasura = ptrReferencia->ptrAnt;
		dato = ptrBasura->dato;
		ptrReferencia->ptrAnt = ptrBasura->ptrAnt;
		ptrBasura->ptrAnt->ptrSig = ptrReferencia;
		free(ptrBasura);
		return dato;
	}
}


void recorrerNodos(struct Nodo *ptrReferencia){
	struct Nodo *ptrRecorrer = ptrReferencia->ptrSig;
	
	if(ptrRecorrer == ptrReferencia){
		printf("\nLa cola esta vacia");
		return;
	}
	
	while(ptrRecorrer != ptrReferencia){
		printf("\nDato: %d", ptrRecorrer->dato);
		ptrRecorrer = ptrRecorrer->ptrSig;
	}
		
	
}