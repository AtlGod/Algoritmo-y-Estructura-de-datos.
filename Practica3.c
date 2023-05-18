//*****************************************************************
//Equipo: Los cracks, conformado por:
// 1. Cardoso Osorio Atl Yosafat
// 2. Diaz Hernandez Emilio
// 3. Gonzalez Manzano Leonardo
//Curso: Teoría de la Computación
//Mayo 2023
//ESCOM-IPN
//Programa que realiza las operaciones de longitud, igualdad, palindromo, reemplazo de cadenas, 
//quitar espacios en blanco, complemento a 1 y busqueda de subcadenas sobre una cadena del alfabeto {0,1}
//Compilacion: "gcc LosCracks_Practica3.c -o LosCracks_Pract3.exe"
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int estaEnAlfabeto(char *, int );

int main() {
    char cadena1[100],cadena2[100]; //Cadenas en las que se haran las operaciones
    int opcion; //Variable que guardara la opcion del menu
    int i,j,k;
    
	//registra la primera cadena
    printf("Ingresar la primera cadena binaria: ");
    scanf("%[^\n]s",cadena1);
    fflush(stdin);
   	int longitud1 = strlen(cadena1);//determinar la longitud de la cadena 1
    while(!estaEnAlfabeto(cadena1,longitud1)){ //Verifica que las 
    //cadenas esten en el alfabeto, si no lo estan, vuelve a recibir la cadena
        printf("La cadena no forma parte del alfabeto {0,1}, intente de nuevo\n");
        scanf("%[^\n]s",cadena1);
        fflush(stdin);
    }

    //registra la segunda cadena
    printf("Ingresar la primera cadena binaria: ");
    scanf("%[^\n]s",cadena2);
    fflush(stdin);
    int longitud2 = strlen(cadena2);//determinar la longitud de la cadena 2
    while(!estaEnAlfabeto(cadena2,longitud2)){ //Verifica que las 
    //cadenas esten en el alfabeto, si no lo estan, vuelve a recibir la cadena
        printf("La cadena no forma parte del alfabeto {0,1}, intente de nuevo\n");
        scanf("%[^\n]s",cadena2);
        fflush(stdin);
    }

    do{
        char cadSinEsp[100];
        int mitad;
        int bandera=0;
        char compl[100];

        //Menu de opciones
        printf("\n----------------\nMenu de opciones:\n");
        printf("0. Reemplaza las cadenas\n");
        printf("1. Longitud\n");
        printf("2. Igualdad\n");
        printf("3. Palindromo\n");
        printf("4. Quitar espacios en blanco\n");
        printf("5. Complemento a 1\n");
        printf("6. Busqueda de una cadena dentro de otra\n");
        printf("7. Salir\n");

        //registrar la opcion ingresada
        printf("Ingrese una Opcion (1-7): ");
        scanf("%d", &opcion);

        switch(opcion){
            case 0:
                fflush(stdin);
                //registra la primera cadena
                printf("Ingresar la primera cadena binaria: ");
                scanf("%[^\n]s",cadena1);
                fflush(stdin);
                longitud1 = strlen(cadena1);//determinar la longitud de la cadena 1
                while(!estaEnAlfabeto(cadena1,longitud1)){ //Verifica que las 
                //cadenas esten en el alfabeto, si no lo estan, vuelve a recibir la cadena
                    printf("La cadena no forma parte del alfabeto {0,1}, intente de nuevo\n");
                    scanf("%[^\n]s",cadena1);
                    fflush(stdin);
                }

                //registra la segunda cadena
                printf("Ingresar la primera cadena binaria: ");
                scanf("%[^\n]s",cadena2);
                fflush(stdin);
                longitud2 = strlen(cadena2);//determinar la longitud de la cadena 2
                while(!estaEnAlfabeto(cadena2,longitud2)){ //Verifica que las 
                //cadenas esten en el alfabeto, si no lo estan, vuelve a recibir la cadena
                    printf("La cadena no forma parte del alfabeto {0,1}, intente de nuevo\n");
                    scanf("%[^\n]s",cadena2);
                    fflush(stdin);
                }
                break;
            case 1://imprimimos la longitud de las cadenas
                printf("\nLa longitud de la cadena 1: |%s| = %d",cadena1,longitud1);
                printf("\nLa longitud de la cadena 1: |%s| = %d\n",cadena2,longitud2);
                break;
            case 2:
                if(strcmp(cadena1,cadena2)==0){//usamos la funcion strcmp() para comparar ambas cadenas
                    printf("\nLas cadenas 1 y 2 son iguales\n");
                } else{
                    printf("\nLas cadenas 1 y 2 son diferentes\n");
                }
                break;
            case 3://palindromo
                mitad=longitud1/2; //obtenemos la mitad de la longitud de la cadena 1
                for(i=0,j=longitud1-1; i<mitad; i++,j--){ //recorremos y comparamos la cadena 1:
                    if(cadena1[i]!=cadena1[j]){           //de 0 a mitad con la variable i
                        bandera=1;                        //de mitad a 0 con la variable j
                        break; //si son diferentes, rompe el ciclo y asigna 1 a la bandera
                    }
                }
                if(bandera==1){ //si la bandera es 1, la cadena 1 no es palindromo
                    printf("\nLa cadena 1 '%s' no es palindromo\n",cadena1);
                } else{
                    printf("\nLa cadena 1 '%s' es palindromo\n",cadena1);
                }

                mitad=longitud2/2; //obtenemos la mitad de la longitud de la cadena 2
                bandera=0;
                for(i=0,j=longitud2-1; i<mitad; i++,j--){ //recorremos y comparamos la cadena 2:
                    if(cadena2[i]!=cadena2[j]){           //de 0 a mitad con la variable i
                        bandera=1;                        //de mitad a 0 con la variable j
                        break; //si son diferentes, rompe el ciclo y asigna 1 a la bandera
                    }
                }
                if(bandera==1){ //si la bandera es 1, la cadena 2 no es palindromo
                    printf("La cadena 2 '%s' no es palindromo\n",cadena2);
                } else{
                    printf("La cadena 2 '%s' es palindromo\n",cadena2);
                }
                break;
            case 4: //quitar los espacios de las cadenas
                j=0;
                for(i=0;i<longitud1;i++){ //recorre la cadena 1
                    if(cadena1[i]!=' ' && cadena1[i]!='\t'){ //si la posicion i no es espacio ni tabulacion
                        cadSinEsp[j]=cadena1[i]; //copia el caracter i de la cadena 1 a la cadena sin espacios
                        j++;
                    }
                }
                cadSinEsp[j]='\0'; //asigna el caracter nulo al final de la cadena sin espacios
                printf("\nLa cadena 1 sin espacios es: %s\n",cadSinEsp);

                j=0;
                for(i=0;i<longitud2;i++){ //recorre la cadena 2
                    if(cadena2[i]!=' ' && cadena2[i]!='\t'){ //si la posicion i no es espacio ni tabulacion
                        cadSinEsp[j]=cadena2[i]; //copia el caracter i de la cadena 2 a la cadena sin espacios
                        j++;
                    }
                }
                cadSinEsp[j]='\0'; //asigna el caracter nulo al final de la cadena sin espacios
                printf("La cadena 2 sin espacios es: %s\n",cadSinEsp);
                break;
            case 5:
                for(i=0,j=0; i<longitud1; i++,j++){ //recorre la cadena 1 y la cadena complemento
                    if(cadena1[i]=='0'){ //si el caracter i de la cadena 1 es '0', el caracter del complemento es '1'
                        compl[j]='1';
                    } else if(cadena1[i]=='1'){ //si el caracter i de la cadena 1 es '1', el caracter del complemento es '0'
                        compl[j]='0';
                    } else{ //si el caracter i de la cadena 1 es espacio o tabulacion, copia directamente al complemento
                        compl[j]=cadena1[i];
                    }
                }
                compl[longitud1]='\0'; //asigna el caracter nulo al final de la cadena complemento
                printf("\nEl complemento a 1 de la cadena 1 '%s' es: %s",cadena1,compl);
                
                for(i=0,j=0; i<longitud2; i++,j++){ //recorre la cadena 2 y la cadena complemento
                    if(cadena2[i]=='0'){ //si el caracter i de la cadena 2 es '0', el caracter del complemento es '1'
                        compl[j]='1';
                    } else if(cadena2[i]=='1'){ //si el caracter i de la cadena 2 es '1', el caracter del complemento es '0'
                        compl[j]='0';
                    } else{ //si el caracter i de la cadena 2 es espacio o tabulacion, copia directamente al complemento
                        compl[j]=cadena2[i];
                    }
                }
                compl[longitud2]='\0'; //asigna el caracter nulo al final de la cadena complemento
                printf("\nEl complemento a 1 de la cadena 2 '%s' es: %s\n",cadena2,compl);
                break;
            case 6: //busca cadena dentro de otra
                if (strstr(cadena1, cadena2) != NULL)//la funcion strstr permite verificar si una cadena es subcadena de otra
       			    printf("\nLa cadena '%s' es subcadena de la cadena '%s'\n", cadena2, cadena1);//si se cumple entonces imprime que si es subcadena
                else
                    printf("\nLa cadena '%s' no es subcadena de la cadena '%s'\n", cadena2, cadena1);//de lo contrario imprime que no es subcadena
                break;
            case 7://salir
                printf("Saliendo del programa....");
                break;
            default://si ninguna de las opciones se cumple, entonces se imprime el mensaje 
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    }while(opcion!=7);
    
    return 0;
}

int estaEnAlfabeto(char *cad, int lon){//verificar que est� en el alfabeto
    int i,j=0;

    for(i=0; i<lon; i++){//recorre la longitud
        if(cad[i]=='0' || cad[i]=='1' || cad[i]==' ' || cad[i]=='\t' || cad[i]=='\n'){//revisa que sean 0 o 1
            j++;
        }
    }
    if(j==lon)
        return 1;//si son ceros, unos o espacios regresa 1
    else
        return 0;//si no lo son regresa cero
}