#include"parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
	Employee* nuevoEmpleado;
	char id[50];
	char nombre[LEN];
	char horas[50];
	char sueldo[50];
	int retorno;
	retorno=ERROR;
	if(pArrayListEmployee!=NULL){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
		while(!feof(pFile)){
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
			nuevoEmpleado=employee_newParametros(id,nombre,horas,sueldo);
			ll_add(pArrayListEmployee,(Employee*)nuevoEmpleado);
			if(feof(pFile)){
				break;
			}
		}
		retorno=0;
	}
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
	Employee* nuevoEmpleado;
	char id[50];
	char nombre[LEN];
	char horas[50];
	char sueldo[50];
	int retorno;
	retorno=ERROR;
	if(pArrayListEmployee!=NULL){
		fscanf(pFile,"%[^0b]%[^0b]%[^0b]%[^\n]\n",id,nombre,horas,sueldo);
		while(!feof(pFile)){
			fscanf(pFile,"%[^0b]%[^0b]%[^0b]%[^\n]\n",id,nombre,horas,sueldo);
			nuevoEmpleado=employee_newParametros(id,nombre,horas,sueldo);
			ll_add(pArrayListEmployee,(Employee*)nuevoEmpleado);
			if(feof(pFile)){
				break;
			}
		}
		retorno=0;
	}
    return retorno;
}
