//Cardoso Osorio Atl Yosafat.
//Codigo 22

//Estas son las librerias
#include<stdio.h>
#include<string.h>

//Esta es una declaracion de estructura
struct persona{
	char nombre[30];
	int edad;
	char sexo;
};

//Esta es una declaracion de estructura
struct elemento{
	struct 	persona arreglo[5],*ptr;
};

//Estas son las preposciones de las funciones
void meter(struct elemento*ptrs,struct persona *ptrDato);
int arregloLleno(struct elemento *ptrs);
void imprimir(struct elemento *ptrs);
	
//Esta es la funcion principal
void main(){
	//Declramos y asignamos las variables
	struct elemento var,*miptrs;
	struct persona midato,*miptrDato;
	miptrs = &var;
	miptrDato = &midato;
	miptrs->ptr = miptrs->arreglo;
	//Operamos un bucle infinito para hacer las acciones del menu
	int eleccion;
	while(eleccion!=3){
		printf("\nIntroduzca la opcion que dese realizar: ");
		printf("\n1.-Crear nueva persona");
		printf("\n2.-Imprimir personas");
		printf("\n3.-Finalizar el programa");
		scanf("%d",&eleccion);
		fflush(stdin);
		//Usamos un switch para el elegir las acciones a realizar
		switch(eleccion){
			case 1:
				if(arregloLleno(miptrs)){
					printf("\nNo se puede,esta lleno\n");
				}else{
					printf("\nIntroduzca su nombre: ");
					gets(miptrDato->nombre);
					fflush(stdin);
					printf("\nIntroduzca la edad: ");
					scanf("%d",&miptrDato->edad);
					fflush(stdin);
					printf("\nIntroduzca el sexo: ");
					miptrDato->sexo = getchar();
					fflush(stdin);
					meter(miptrs,miptrDato);
				}
				break;
			case 2:
				printf("\nHay en total %d personas en el arreglo hasta el momento: \n",(int)(miptrs->ptr-miptrs->arreglo));
				imprimir(miptrs);
				break;
			case 3:
				printf("\nGracias por su uso\n");
				break;
			default:
				printf("\nOpcion invalida,elije una opcion valida\n");
				break;
		}
	}
	
}

//Esta funcion se encarga de llenar los datos
void meter(struct elemento *ptrs,struct persona *ptrDato){
	//Realizamos los ingresos de las variables
	ptrs->ptr->edad = ptrDato->edad;
	strcpy(ptrs->ptr->nombre,ptrDato->nombre);
	ptrs->ptr->sexo = ptrDato->sexo;
	ptrs->ptr++;
}

//Esta funcion se encarga de rellenar el arreglo
int arregloLleno(struct elemento *ptrs){
	if(ptrs->ptr == &ptrs -> arreglo[5])
		return 1;
	else
		return 0;
}

//Esta funcion se encarga de la impresion de los datos
void imprimir(struct elemento *ptrs){
	//Declaramos y asginamos las variables
	struct persona *ayudaptr;
	ayudaptr = ptrs->ptr;
	//Realizamos el ciclo para imprimir
	for(ptrs->ptr = ptrs->arreglo;ptrs->ptr<ayudaptr;ptrs->ptr++){
		printf("\nEn la celda %d esta el nombre %s en la direccion %lu",(int)(ptrs->ptr-ptrs->arreglo),ptrs->ptr->nombre,&ptrs->ptr->nombre);
		printf("\nEn la celda %d esta la edad %d en la direccion %lu",(int)(ptrs->ptr-ptrs->arreglo),ptrs->ptr->edad,&ptrs->ptr->edad);
		printf("\nEn la celda %d esta el sexo %c en la direccion %lu",(int)(ptrs->ptr-ptrs->arreglo),ptrs->ptr->sexo,&ptrs->ptr->sexo);
	}
}
