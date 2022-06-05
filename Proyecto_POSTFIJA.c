// Cardoso Osorio Atl Yosafat.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct pila{
	
	char caracteres[100];
	char *ptr;
	
	float numeros[100];
	float *ptrn;
	
};

// Prototipos de las funciones
void menu(struct pila *ptrp);
void meterDato(struct pila *ptrp, char dato);
char cima(struct pila *ptrp);
void recorrerCadena(char *ptr_infija, char *ptr_postfija, struct pila *ptrp);
int precedencia(char simbolo);

void meterDato_flotante(struct pila *ptrp, float dato);
float sacarDato_flotante(struct pila *ptrp);
void evaluarPostfija(char *ptr_postfija, struct pila *ptrp);
float operaciones(float a, float b, char operador);
void limpiarCadena(char *cadena);


int main(){
	
	struct pila mipila, *miptrp;
	// Inicializamos los apuntadores
	miptrp = &mipila;
	miptrp->ptr = miptrp->caracteres;
	miptrp->ptrn = miptrp->numeros;
	
	menu(miptrp);
	
	return 0;
}

void menu(struct pila *ptrp){
	
	int opcion;
	char infija[100], postfija[100];
	
	while(1){
		
		printf("\nCONVERTIDOR INFIJA A POSTFIJA\n\n");
		printf("1.Convertir expresion infija a postfija\n2.Salir\n\n");
		printf("Elija una opcion: ");
		scanf("%d",&opcion);
		
		switch(opcion){
			
			case 1: 
				
				fflush(stdin);
				printf("\nIngrese la expresion en notacion infija: ");
				gets(infija);
	
				// Agregamos el parentesis ")" a la cadena infija
				strcat(infija,")");
				// Agregamos el paréntesis "(" a la pila
				meterDato(ptrp,'(');
	
				recorrerCadena(infija,postfija,ptrp);
	
				printf("\nLa notacion en postfija es: ");
				puts(postfija);

				// Evaluamos la notación postfija
				evaluarPostfija(postfija,ptrp);
				printf("\n");
				
				system("PAUSE");
				system("cls");
				
				break;
				
				case 2: 
					exit(1);
					break;
					
				default: 
					printf("\nOpcion incorrecto\n");
					system("PAUSE");
					system("cls");
					
					break;
					
		}
		
	}
	
	
}

void meterDato(struct pila *ptrp, char dato){
	
	*(ptrp->ptr) = dato;
	 ptrp->ptr++;
}

void meterDato_flotante(struct pila *ptrp, float dato){
	
	*(ptrp->ptrn) = dato;
	 ptrp->ptrn++;
}

char sacarDato(struct pila *ptrp){
	
	// Decrementamos el apuntador
	ptrp->ptr--;
	return *(ptrp->ptr);	
}

float sacarDato_flotante(struct pila *ptrp){
	
	// Decrementamos el apuntador
	ptrp->ptrn--;
	return *(ptrp->ptrn);	
}

char cima(struct pila *ptrp){
	
	ptrp->ptr--;
	char cima = *(ptrp->ptr);
	ptrp->ptr++;
	
	return cima;
}

void recorrerCadena(char *ptr_infija, char *ptr_postfija, struct pila *ptrp){
	
		while(*ptr_infija != '\0'){	
		
		// analizamos los diferentes casos
	    if(*ptr_infija == '(')
			meterDato(ptrp,*ptr_infija);
			
		
		else if((*ptr_infija >= '*' && *ptr_infija<'.') || *ptr_infija == '^' || *ptr_infija == '/'){
		
			*ptr_postfija = ' ';
			 ptr_postfija++;
			
			// Verificamos la precedencia de los operadores
			while(precedencia(cima(ptrp)) >= precedencia(*ptr_infija)){
				
				*ptr_postfija = sacarDato(ptrp);
				 ptr_postfija++;
				
				*ptr_postfija = ' ';
				 ptr_postfija++;
			}
		    
			meterDato(ptrp,*ptr_infija);
		}
		
		else if(*ptr_infija == ')'){
					
			while(cima(ptrp) != '('){
				
				*ptr_postfija = ' ';
				 ptr_postfija++;
				
				*ptr_postfija = sacarDato(ptrp);
				 ptr_postfija++;
			}
			
			sacarDato(ptrp);
		}
		
		else{
			
			*ptr_postfija = *ptr_infija;
		   	 ptr_postfija++;
		}
		
			ptr_infija++;	
	}
	
}

int precedencia(char simbolo){
	
	int precedencia;
	
	switch(simbolo){
		
		case '^':
			precedencia = 3;
		break;
		
		case '*':
			precedencia = 2;
		break;
		
		case '/':
			precedencia = 2;
		break;
		
		case '+':
			precedencia = 1;
		break;
		
		case '-':
			precedencia = 1;
		break;
		
		default: 
			precedencia = 0;
	
	}
	
	return precedencia;
}


void evaluarPostfija(char *ptr_postfija, struct pila *ptrp){
	
	char cad_temporal[10], *ptr;
	ptr = cad_temporal;
	
	while(*ptr_postfija != '\0'){
		
		if((*ptr_postfija >= '*' && *ptr_postfija<'.') || *ptr_postfija == '^' || *ptr_postfija == '/'){
			
			float b = sacarDato_flotante(ptrp);
			float a = sacarDato_flotante(ptrp);
			
			meterDato_flotante(ptrp,operaciones(a,b,*ptr_postfija));
			ptr_postfija++;
			
		}else{ 
			
			// Es un número flotante
		    if(*ptr_postfija == ' '){
		    	
		    	meterDato_flotante(ptrp,atof(cad_temporal));
		    	limpiarCadena(cad_temporal);
		    	ptr = cad_temporal;
		    	
			}else{
				
				*ptr = *ptr_postfija;
				 ptr++;
			}
									
		}
		
			ptr_postfija++;
	  	
	}
	
	printf("\nLa evaluacion de la expresion postfija: %.2f ", sacarDato_flotante(ptrp));
	
}


void limpiarCadena(char *cadena){
	
	while(*cadena != '\0'){		
		*cadena = 0.0;
		 cadena++;
	}
}

float operaciones(float a, float b, char operador){
	
	switch(operador){
		
		case '^':
			return pow(a,b);
		break;
		
		case '*':
			return a*b;
		break;
		
		case '/':
			return a/b;
		break;
		
		case '+':
			return a+b;
		break;
		
		case '-':
			return a-b;
		break;
		
		default: 
			return 0.0;
			
	}	
}
