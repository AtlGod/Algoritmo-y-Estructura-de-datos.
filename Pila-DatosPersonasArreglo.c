// Cardoso Osorio Atl Yosafat.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct persona{
	char nombre[30];
	int edad;
	char sexo;
};

struct Pila{
	struct persona arreglo[10];
	struct persona*ptrC;
};

int menu();
void meter(struct Pila*ptrP,struct persona *ptrD);
int estallenalapila(struct Pila*ptrP);
void sacar(struct Pila *ptrP,struct persona *ptrD);
int estavacialapila(struct Pila *ptrP);

void main(){
	struct Pila miPila,*miptrP;
	struct persona miDato,*miptrD;
	miptrP = &miPila;
	miptrD = &miDato;
	miptrP->ptrC = miptrP->arreglo;
	for(;;){
		switch(menu()){
			case 1:
				if(estallenalapila(miptrP)){
					printf("La pila esta llena\n");
				}else{
					printf("Ingrese el nombre: ");
					gets(miptrD->nombre);
					fflush(stdin);
					printf("\nIngrese la edad: ");
					scanf("%d",&miptrD->edad);
					fflush(stdin);
					printf("\nIngrese el sexo: ");
					miptrD->sexo = getchar();
					fflush(stdin);
					meter(miptrP,miptrD);
				}
				break;
			case 2:
				if(estavacialapila(miptrP)){
					printf("La pila esta vacia\n");
				}else{
					sacar(miptrP,miptrD);
					printf("El dato se ha recuperado");
					printf("\nNombre: %s",miptrD->nombre);
					printf("\nEdad: %d",miptrD->edad);
					printf("\nSexo: %c",miptrD->sexo);
				}
				break;
			case 3:
				exit(0);
			default:
				printf("Introduzca una opcion valida\n");
				break;
		}
	}
	
}

int menu(){
	int opcion;
	printf("1.- Meter\n");
	printf("2.- Sacar\n");
	printf("3.- Finalizar el programa\n");
	scanf("%d",&opcion);
	fflush(stdin);
	return opcion;
}

void meter(struct Pila *ptrP,struct persona *ptrD){
	strcpy(ptrP->ptrC->nombre,ptrD->nombre);
	ptrP->ptrC->edad = ptrD -> edad;
	ptrP->ptrC->sexo = ptrD -> sexo;
	ptrP->ptrC++;
}

int estallenalapila(struct Pila*ptrP){
	if(ptrP->ptrC == &ptrP -> arreglo[10]){
		return 1;
	}else{
		return 0;
	}
}

void sacar(struct Pila*ptrP,struct persona *ptrD){
	ptrP->ptrC--;
	strcpy(ptrD->nombre,ptrP->ptrC->nombre);
	ptrD->edad = ptrP->ptrC->edad;
	ptrD->sexo = ptrP->ptrC->sexo;
}

int estavacialapila(struct Pila *ptrP){
	if(ptrP->ptrC == ptrP->arreglo){
		return 1;
	}else{
		return 0;
	}
}
