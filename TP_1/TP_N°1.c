#include<stdio.h>
#include<stdlib.h>
#include"inputs.h"
#include"ecuaciones.h"

int main(){
	setbuf(stdout,NULL);
	int eleccion;
	int encendido;
	int bandera;
	float numero1;
	float numero2;
	float suma;
	float resta;
	float cociente;
	float producto;
	long int factorialA;
	long int factorialB;
	numero1=0;
	numero2=0;
	encendido=1;
	bandera=0;
	do{
		printf("1)Ingresar primer operando (A=%.2f)\n"
				"2)Ingrese segundo operando (B=%.2f)\n"
				"3)Calcular todas las operaciones\n"
				"4)Informar resultados\n"
				"5)Salir\n",numero1,numero2);
		eleccion=inputs_entero("Ingrese su eleccion: ",1,5);
		switch(eleccion){
		case 1:
			numero1=inputs_flotante("Ingrese el primer operando: ",-9999,9999);
			bandera=0;
			break;
		case 2:
			numero2=inputs_flotante("Ingrese el segundo operando: ",-9999,9999);
			bandera=0;
			break;
		case 3:
			suma=ecuaciones_suma(numero1,numero2);
			resta=ecuaciones_resta(numero1,numero2);
			cociente=ecuaciones_divicion(numero1,numero2);
			producto=ecuaciones_multiplicacion(numero1,numero2);
			factorialA=ecuaciones_factorisacion((long int)numero1);
			factorialB=ecuaciones_factorisacion((long int)numero2);
			bandera=1;
			break;
		case 4:
			if(bandera==0){
				printf("Las operaciones no se calcularon aun\n");
			}
			else{
				printf("El resultado de A+B es: %.2f\n"
						"El resultado de A-B es: %.2f\n",suma,resta);
				if(cociente==0){
					printf("No es posible divir por 0\n");
				}
				else{
					printf("El resultado de la divicion es: %.2f\n",cociente);
				}
				printf("El resultado de A*B es: %.2f\n",producto);
				if(factorialA==-1){
					printf("El Factorial no puede sen negativo\n");
				}
				else{
					printf("El factorial de A es: %ld\n",factorialA);
				}
				if(factorialB==-1){
					printf("El Factorial no puede sen negativo\n");
				}
				else{
					printf("El factorial de B es: %ld\n",factorialB);
				}
			}
			break;
		default:
			encendido=0;
		}
	}while(encendido);
	return EXIT_SUCCESS;
}
