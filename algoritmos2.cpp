#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

struct persona{
	char nombre[30];
	int edad;
	float est;
	char sexo;
};

int main()
{
	struct persona per1, per2;
		printf("\n Introduce el nombre de per1: ");
			gets(per1.nombre);
		printf("\n Introduce la edad de per1: ");
			scanf("%d",&per1.edad);
		printf("\n Introduce la estatura de per1: ");
			scanf("%f",&per2.est);
			fflush(stdin);
		printf("\n Introduce el sexo de per1: ");
			per1.sexo=getchar();
			fflush(stdin);
		printf("\n Introduce el nombre de per2: ");
			gets(per2.nombre);
		printf("\n Introduce la edad de per2: ");
			scanf("%d",&per2.edad);
		printf("\n Introduce la estatura de per2: ");
			scanf("%f",&per2.est);
			fflush(stdin);
		printf("\n Introduce el sexo de per2: ");
			per2.sexo=getchar();
			fflush(stdin);
	
	printf("\n El nombre es: %s y esta en la dirreccion: %lu la edad: %d esta en: %lu, la estatura es: %f y esta en: %lu y el sexo es: %c y esta en: %lu \n",per1.nombre,&per1.nombre,per1.edad,&per1.edad,per1.est,per1.est,per1.sexo,&per1.sexo);	
	printf("\n El nombre es: %s y esta en la dirreccion: %lu la edad: %d esta en: %lu, la estatura es: %f y esta en: %lu y el sexo es: %c y esta en: %lu \n",per2.nombre,&per2.nombre,per2.edad,&per2.edad,per2.est,per2.est,per2.sexo,&per2.sexo);
}