#ifndef ECUACIONES_H_
#define ECUACIONES_H_
#include <stdio.h>
#include <stdlib.h>

float ecuaciones_suma (float,float);
/*
 * Devuelve la suma de los parametros
 */

float ecuaciones_resta (float,float);
/*
 * Devuelve el resultado del primer parametro menos el segundo
 */

float ecuaciones_divicion (float,float);
/*
 * Devuelve el resultado del primer parametro dividido el segundo
 * En caso de que alguno de los dos parametros sea 0 devuelve 0
 */

float ecuaciones_multiplicacion(float,float);
/*
 * Devuelve el producto entre el primer y segundo parametro
 */

long int ecuaciones_factorisacion(long int);
/*
 * Devuelve el factorial de un numero
 */

#endif /* ECUACIONES_H_ */
