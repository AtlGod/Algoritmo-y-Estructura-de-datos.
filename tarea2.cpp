#include <bits/stdc++.h>

struct domicilio{
char calle[30];
int numero;
char colonia[30];

};
struct persona{
char nombre[30];
int edad;
char sexo;
struct domicilio dom;
};
int main()
{
   struct persona arreglo[1],*ptr1,**ptr2;
   ptr1=arreglo;
   for(ptr2=&ptr1;*ptr2<&arreglo[1];*ptr2=*ptr2+1){
    printf("\nIngrese nombre: \n");
    gets((*ptr2)->nombre);
    printf("\nIngrese edad: \n");
    scanf("%d",&(*ptr2)->edad);
    fflush(stdin);
    printf("\nIngrese sexo: \n");
    (*ptr2)->sexo=getchar();
    fflush(stdin);
    printf("\nIngrese calle: \n");
    gets((*ptr2)->dom.calle);
    printf("\nIngrese numero: \n");
    scanf("%d",&(*ptr2)->dom.numero);
    fflush(stdin);
    printf("\nIngrese colonia: \n");
    gets((*ptr2)->dom.colonia);
    fflush(stdin);
   }
   ptr1=arreglo;
   for(ptr2=&ptr1;*ptr2<&arreglo[1];*ptr2=*ptr2+1){
    printf("En la celda %d se guarda el nombre:  %s en la direccion %lu\n",(int)(*ptr2-arreglo),(*ptr2)->nombre,&(*ptr2)->nombre);
    printf("En la celda %d se guarda la edad: %d en la direccion %lu\n",(int)(*ptr2-arreglo),(*ptr2)->edad,&(*ptr2)->edad);
    printf("En la celda %d esta el sexo %c en la direccion %lu\n",(int)(*ptr2-arreglo),(*ptr2)->sexo,&(*ptr2)->sexo);
    printf("En la celda %d se guarda la calle %s en la direccion %lu\n",(int)(*ptr2-arreglo),(*ptr2)->dom.calle,&(*ptr2)->dom.calle);
    printf("En la celda %d esta el numero de casa %d en la direccion %lu\n",(int)(*ptr2-arreglo),(*ptr2)->dom.numero,&(*ptr2)->dom.numero);
    printf("En la celda %d se guarda la colonia %s en la direccion %lu\n",(int)(*ptr2-arreglo),(*ptr2)->dom.colonia,&(*ptr2)->dom.colonia);
   }
    return 0;
}