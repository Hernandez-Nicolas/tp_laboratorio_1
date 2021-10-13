#include<stdio.h>
#include<stdlib.h>
#include"ArrayEmployees.h"
#include"inputs.h"

#define TAM 3

int main(){
	setbuf(stdout,NULL);
	Employee lista[TAM];
	char apellido[LEN];
	char nombre[LEN];
	float salario;
	int sector;
	int id;
	int contadorId;
	int error;
	int bandera;
	int eleccion;
	int salida;
	contadorId=1;
	bandera=0;
	salida=1;
	initEmployees(lista,TAM);
	do{
		printf("1) Alta\n"
				"2) Modificar\n"
				"3) Baja\n"
				"4) Modificar\n"
				"5) Salir\n\n");
		eleccion=inputs_entero("Ingrese su eleccion: ",1,5);
		switch(eleccion){
			case 1:
				inputs_nombre("\nIngrese los datos del nuevo empleado:\nApellido: ",apellido,LEN);
				inputs_nombre("Nombre: ",nombre,LEN);
				salario=inputs_flotante("Salario: ",500,5000);
				sector=inputs_entero("Sector: ",1,10);
				error=addEmployee(lista,TAM,contadorId,nombre,apellido,salario,sector);
				sortEmployees(lista,TAM,1);
				if(error==ERROR){
					printf("\n\tOCURRIO UN ERROR\n"
							"Puede que no haya espacio para mas empleados\n\n");
				}
				contadorId++;
				bandera=1;
				break;
			case 2:
				if(bandera==1){
					printEmployees(lista,TAM);
					id=inputs_entero("\nIngrese el ID del empleado que quiera modifica: ",1,contadorId);
					error=modifyEmployee(lista,TAM,id);
					if(error==ERROR){
						printf("\n\tOCURRIO UN ERROR\n"
								"Puede que el ID sea incorecto o el empleado se haya dado de baja\n\n");
					}
				}
				else{
					printf("\nPrimero debe ingresar al menos un empleado\n\n");
				}
				break;
			case 3:
				if(bandera==1){
					printEmployees(lista,TAM);
					id=inputs_entero("\nIngrese el ID del empleado que quiera dar de baja: ",1,contadorId);
					error=removeEmployee(lista,TAM,id);
					if(error==ERROR){
						printf("\n\tOCURRIO UN ERROR\n"
								"Puede que el ID sea incorecto o el empleado se haya dado de baja\n\n");
					}
					else{
						if(statusEmployees(lista,TAM)==1){
							bandera=0;
						}
					}
				}
				else{
					printf("\nPrimero debe ingresar al menos un empleado\n\n");
				}
				break;
			case 4:
				if(bandera==1){
					printEmployees(lista,TAM);
					salaryEmployees(lista,TAM);
				}
				else{
					printf("\nPrimero debe ingresar al menos un empleado\n\n");
				}
				break;
			default:
				salida=0;
				break;
		}
	}while(salida==1);
	return EXIT_SUCCESS;
}
