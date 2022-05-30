#include <stdio.h>

struct persona {
	char nombre[30];
	int edad;
	char sex;
};
int main()
{
	struct persona  per1, *ptr;
	ptr=&per1;
	printf("\n Nombre per1: ");
	gets(ptr->nombre);
	printf("\n edad per1: ");
	scanf("%d",&ptr->edad);
	fflush(stdin);
	printf("\n sexo per1: ");
	ptr->sex=getchar();
	fflush(stdin);
	printf("\n El nombre es: %c En el espacio: %lu la edad: %d  en el lugar: %lu y el sexo: %c en el lugar: %lu ",ptr->nombre,&ptr->nombre,ptr->edad,&ptr->edad,ptr->sex,&ptr->sex);
}
