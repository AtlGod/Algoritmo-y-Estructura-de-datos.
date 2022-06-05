// Cardoso Osorio Atl Yosafat.
#include<stdio.h>
#include<stdlib.h>

struct Pila{
	int arreglo[10];
	int *ptrC;
};

void meter(struct Pila *ptrP,int dato);
int estallenoPila(struct Pila *ptrP);
int sacar(struct Pila *ptrP);
int estaVaciaPila(struct Pila *ptrP);
int menu();

void main(){
	struct Pila mipila,*miptrP;
	int midato;
	
	miptrP = &mipila;
	miptrP -> ptrC = miptrP -> arreglo;
	
	for(;;){
		switch(menu()){
			case 1:
				if(estallenaPila(miptrP)){
					printf("la pila esta llena\n");
				}else{
					printf("Introduzca un entero: ");
					scanf("%d",&midato);
					meter(miptrP,midato);
				}
				break;
			case 2:
				if(estaVaciaPila(miptrP)){
					printf("La pila esta vacia\n");
				}else{
					printf("El dato recuperado %d\n",sacar(miptrP));
				}
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("Elige una respuesta valida, gracias\n");
				break;
	}
}
}

void meter(struct Pila *ptrP,int dato){
	*ptrP->ptrC = dato;
	ptrP->ptrC++;
}

int estallenaPila(struct Pila *ptrP){
	if(ptrP->ptrC == &ptrP -> arreglo[10])
		return 1;
	else
		return 0;
	
}

int sacar (struct Pila *ptrP){
	ptrP -> ptrC--;
	return(*ptrP -> ptrC);
}

int estaVaciaPila(struct Pila *ptrP){
	if(ptrP->ptrC == ptrP ->arreglo)
		return 1;
	else
		return 0;
	
}

int menu(){
	int eleccion;
	printf("1.-Meter\n");
	printf("2.-Sacar\n");
	printf("3.-Terminar el programa\n");
	scanf("%d",&eleccion);
	return eleccion;
}
