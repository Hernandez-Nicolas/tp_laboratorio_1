#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inputs_entero(char[],int,int);
/*
 * Resumen: Ingresa y devuelve un entero validado en cierto rango
 * param char[]		Ingresa un mensaje a mostrar
 * param int		ingresa el minimo del rango a validar
 * param int		ingresa el maximo del rango a validar
 */

float inputs_flotante(char[],float,float);
/*
 * Resumen: Ingresa y devuelve un flotante validado en cierto rango
 * param char[]		Ingresa un mensaje a mostrar
 * param float		ingresa el minimo del rango a validar
 * param float		ingresa el maximo del rango a validar
 */

#endif /* INPUTS_H_ */
