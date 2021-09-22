#include "ecuaciones.h"

float ecuaciones_suma (float numero1,float numero2){
	float resultado;
	resultado=numero1+numero2;
	return resultado;
}

float ecuaciones_resta (float numero1,float numero2){
	float resultado;
	resultado=numero1-numero2;
	return resultado;
}

float ecuaciones_divicion (float numero1,float numero2){
	float resultado;
	if(numero1==0||numero2==0){
		resultado=0;
	}
	else{
		resultado=numero1/numero2;
	}
	return resultado;
}

float ecuaciones_multiplicacion(float numero1,float numero2){
	float resultado;
	resultado=numero1*numero2;
	return resultado;
}

long int ecuaciones_factorisacion(long int numero){
	long int resultado;
	if(numero==0){
		return 1;
	}
	else{
		resultado=numero*ecuaciones_factorisacion(numero-1);
	}
	return resultado;
}
