#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct nodo{
	int dato;
	struct nodo *ptrsig;
};
struct nodo *crearnodo(int dato1){
	struct nodo *ptrn;
	ptrn=(struct nodo *)malloc(sizeof(struct nodo));
	ptrn->dato=dato1;
	ptrn->ptrsig=NULL;
	return ptrn;
}
void meter(struct nodo *ptrref,int dato1){
	struct nodo *ptrnew;
	ptrnew=crearnodo(dato1);
	if(ptrref->ptrsig==NULL){
		ptrref->ptrsig=ptrnew;
	}
	else{
		ptrnew->ptrsig=ptrref->ptrsig;
		ptrref->ptrsig=ptrnew;
	}
}
int saca (struct nodo *ptrref){
int dato=0;
struct nodo *ptrav=ptrref->ptrsig;
struct nodo *ptrret=ptrref;
if(ptrav->ptrsig==NULL){
	printf ("El nodo esta vacio");
	
}else { 
 while(ptrav->ptrsig!=NULL){
 	ptrav=ptrav->ptrsig;
	 ptrret=ptrret->ptrsig;
	 
 }
 ptrret->ptrsig=NULL;
}
struct nodo *ptrbasura=ptrav;
dato=ptrbasura->dato;

return dato;
}
void impcadena(struct nodo *ptrref){
	struct nodo *ptrrec;
	ptrrec=ptrref->ptrsig;
	while(ptrrec!=NULL){
		printf("%d",ptrrec->dato);
		printf(" ");
		ptrrec=ptrrec->ptrsig;
	}
}
int main(int argc, char *argv[]) {
	struct nodo *miptrref;
	int n,dato;
	miptrref=crearnodo(-1000);
	for(;;){
		printf("\nPara meter dato presione 1\nPara ver todo presiones 2\n Para sacar pulse 3\nPara salir pulse 4\n");
		scanf("%d",&n);
		if(n==1){
			printf("ingrese un entero: ");
			scanf("%d",&dato);
			meter(miptrref,dato);
		}
		else if(n==2){
			impcadena(miptrref);
		}
  else if(n==3){
  if(miptrref->ptrsig!=NULL) {
     printf("%d",saca(miptrref));
    } 
   else printf("no se pudo uwu" ) ;
  }
		else{
			exit(0);
		}
	}
	return 0;
}
