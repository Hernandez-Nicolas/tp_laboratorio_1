#include"ArrayEmployees.h"

int initEmployees(Employee* list,int len){
	int retorno;
	retorno=ERROR;
	if(list!=NULL){
		for(int i=0;i<len;i++){
			list[i].isEmpty=VACIO;
		}
		retorno=0;
	}
	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[], float salary, int sector){
	int retorno;
	retorno=ERROR;
	if(list!=NULL){
		for(int i=0;i<len;i++){
			if(list[i].isEmpty==VACIO){
				list[i].id=id;
				strcpy(list[i].name,name);
				strcpy(list[i].lastName,lastName);
				list[i].salary=salary;
				list[i].sector=sector;
				list[i].isEmpty=OCUPADO;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int findEmployeeById(Employee* list, int len, int id){
	int retorno;
	retorno=ERROR;
	if(list!=NULL){
		for(int i=0;i<len;i++){
			if(list[i].isEmpty==OCUPADO&&list[i].id==id){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int removeEmployee(Employee* list, int len, int id){
	int retorno;
	int pocicion;
	retorno=ERROR;
	if(list!=NULL){
		pocicion=findEmployeeById(list,len,id);
		if(pocicion!=ERROR){
			list[pocicion].isEmpty=VACIO;
			retorno=0;
		}
	}
	return retorno;
}

int sortEmployees(Employee* list, int len, int order){
	Employee aux;
	int bandera;
	int retorno;
	retorno=ERROR;
	bandera=1;
	if(list!=NULL){
		if(order==1){
			while(bandera){
				bandera=0;
				for(int i=0;i<len-1;i++){
					if(list[i].isEmpty==OCUPADO){
						for(int j=i+1;j<len;j++){
							if(list[j].isEmpty==OCUPADO){
								if(strcmp(list[i].lastName,list[j].lastName)==0){
									if(list[i].sector>list[j].sector){
										aux=list[i];
										list[i]=list[j];
										list[j]=aux;
										bandera=1;
									}
								}
								else{
									if(strcmp(list[i].lastName,list[j].lastName)<0){
										aux=list[i];
										list[i]=list[j];
										list[j]=aux;
										bandera=1;
									}
								}
							}
						}
					}
				}
			}
		}
		else{
			if(order==0){
				while(bandera){
					bandera=0;
					for(int i=0;i<len-1;i++){
						if(list[i].isEmpty==OCUPADO){
							for(int j=i+1;j<len;j++){
								if(list[j].isEmpty==OCUPADO){
									if(strcmp(list[i].lastName,list[j].lastName)==0){
										if(list[i].sector<list[j].sector){
											aux=list[i];
											list[i]=list[j];
											list[j]=aux;
											bandera=1;
										}
									}
									else{
										if(strcmp(list[i].lastName,list[j].lastName)>0){
											aux=list[i];
											list[i]=list[j];
											list[j]=aux;
											bandera=1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

int printEmployees(Employee* list, int length){
	int retorno;
	retorno=ERROR;
	if(list!=NULL){
		printf("\tID \t\tApellido \t\tNombre \t\tSalario \tSector\n");
		for(int i=0;i<length;i++){
			if(list[i].isEmpty==OCUPADO){
				printf("%10d %20s %20s %20.2f %10d\n",list[i].id,list[i].lastName,list[i].name,list[i].salary,list[i].sector);
			}
		}
	}
	return retorno;
}

int modifyEmployee(Employee* list, int len, int id){
	int eleccion;
	int pocicion;
	int retorno;
	retorno=ERROR;
	if(list!=NULL){
		pocicion=findEmployeeById(list,len,id);
		if(pocicion!=ERROR){
		printf("1) Apellido\n2) Nombre\n3) Salario\n4) Sector\n\n");
		eleccion=inputs_entero("Ingrese que campo quiere modificar: ",1,4);
		switch(eleccion){
		case 1:
			inputs_nombre("Apellido: ",list[pocicion].lastName,LEN);
			break;
		case 2:
			inputs_nombre("Nombre: ",list[pocicion].name,LEN);
			break;
		case 3:
			list[pocicion].salary=inputs_flotante("Salario: ",500,5000);
			break;
		default:
			list[pocicion].sector=inputs_entero("Sector: ",1,10);
		}
		retorno=0;
		}
	}
	return retorno;
}

int statusEmployees(Employee* list, int len){
	int retorno;
	retorno=ERROR;
	if(list!=NULL){
		retorno=1;
		for(int i=0;i<len;i++){
			if(list[i].isEmpty==OCUPADO){
				retorno=0;
			}
		}
	}
	return retorno;
}

int salaryEmployees(Employee* list, int len){
	float promedio;
	float salarioTotal;
	int contadorSalarios;
	int contadorMayoresPromedio;
	int retorno;
	contadorMayoresPromedio=0;
	contadorSalarios=0;
	salarioTotal=0;
	retorno=ERROR;
	if(list!=NULL){
		for(int i=0;i<len;i++){
			if(list[i].isEmpty==OCUPADO){
				salarioTotal+=list[i].salary;
				contadorSalarios++;
			}
		}
		promedio=salarioTotal/contadorSalarios;
		for(int i=0;i<len;i++){
			if(list[i].isEmpty==OCUPADO){
				if(list[i].salary>=promedio){
					contadorMayoresPromedio++;
				}
			}
		}
		printf("\nTotal de los salarios: %.2f\n"
				"Promedio de los salarios: %.2f\n"
				"Cantidad de salarios por encima del promedio: %d\n",salarioTotal,promedio,contadorMayoresPromedio);
		retorno=0;
	}
	return retorno;
}
