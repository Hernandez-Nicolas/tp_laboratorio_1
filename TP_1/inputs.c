#include "inputs.h"

int inputs_entero(char[],int,int);

int inputs_entero(char cadena[],int inferior, int superior){
	int numero;
	printf("%s",cadena);
	scanf("%d",&numero);
	while(numero<inferior||numero>superior){
		printf("El numero no esta dentro del rango elegido, debe estar entre %d y %d\n",inferior,superior);
		scanf("%d",&numero);
	}
	return numero;
}

float inputs_flotante(char cadena[],float inferior,float superior){
	float numero;
	printf("%s",cadena);
	scanf("%f",&numero);
	while(numero<inferior||numero>superior){
		printf("El numero no esta dentro del rango elegido, debe estar entre %.2f y %.2f\n",inferior,superior);
		scanf("%f",&numero);
	}
	return numero;
}
