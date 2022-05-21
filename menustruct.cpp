#include <bits/stdc++.h>

struct dato{
  char nombre[30];
  int edad;
  char sexo;
};

struct elemento{
  struct dato arreglo[5];
  struct dato *ptr;
};

int menu(){
  int opcion;
	menu:
		system ("color 0A"); 
 		system ("CLS"); 
		printf ("Menu de Opciones \n");
		printf ("1) Ingresar datos  \n"); 
		printf ("2) Leer datos \n"); 
		printf ("3) EXIT \n"); 
		printf("Ingrese la opcion que quiere hacer: ");
		scanf ("%i", &opcion); 

  return opcion;
}

int meter(struct elemento *ptrs, struct dato *ptrdato){
  strcpy(ptrs->ptr->nombre, ptrdato->nombre);
  ptrs->ptr->edad = ptrdato->edad;
  ptrs->ptr->sexo = ptrdato->sexo;
  ptrs->ptr++;
  return 0;
}


void sacar(struct elemento *ptrs){
	struct dato *ptrmos;
	for(ptrmos=ptrs->arreglo;ptrmos<ptrs->ptr; ptrmos++){
		printf("En la celda %d esta el nombre %s y con la direccion %lu \n",(int)(ptrmos-ptrs->arreglo),ptrmos->nombre,&ptrmos->nombre);
		printf("En la celda %d esta la edad % d y con la direccion %lu \n",(int)(ptrmos-ptrs->arreglo),ptrmos->edad,&ptrmos->edad);
		printf("En la celda %d esta el sexo %c y con la direccion %lu \n\n\n",(int)(ptrmos-ptrs->arreglo),ptrmos->sexo,&ptrmos->sexo);
	}
	return;	
}
int estallenoA(struct elemento *ptrs){
  if(ptrs->ptr == &ptrs->arreglo[5])
    return 1;
  return 0;
}

int main(){
  struct elemento var, *miptrs;
  struct dato midato, *miptrdato;
  miptrs = &var;
  miptrdato = &midato;
  miptrs->ptr = miptrs->arreglo;
  for(;;){
    switch(menu()){
    case 1:
    	system ("color 0A"); 
 		system ("CLS");
      if(estallenoA(miptrs))
        printf("Lo siento, esta lleno\n");
      else{
        printf("Ingrese nombre\n");
        fflush(stdin);
        gets(miptrdato->nombre);
				fflush(stdin);
        printf("Ingrese edad\n");
        scanf("%d", &miptrdato->edad);
        fflush(stdin);
        printf("Ingrese sexo\n");
        miptrdato->sexo = getchar();
        fflush(stdin);
        meter(miptrs,miptrdato);
       }
      break;
    case 2:
    	system ("color 0A"); 
 		system ("CLS");
		sacar(miptrs);
		
		return 0;
      break;
    case 3:
    	system ("color 0A"); 
 		system ("CLS");
      exit(0);
    }
  }
  return 0;
}