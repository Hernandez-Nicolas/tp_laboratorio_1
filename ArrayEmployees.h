#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"inputs.h"

#define LEN 51
#define VACIO 1
#define OCUPADO 0
#define ERROR -1

typedef struct{
	int id;
	char name[LEN];
	char lastName[LEN];
	float salary;
	int sector;
	int isEmpty;

}Employee;

int initEmployees(Employee*,int);
/*brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */

int addEmployee(Employee*, int, int, char[],char[], float, int);
/*brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */

int findEmployeeById(Employee*, int, int);
/*brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 */

int removeEmployee(Employee*, int, int);
/*brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 */

int sortEmployees(Employee*, int, int);
/*brief Sort the elements in the array of employees, the argument order
 * indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */

int printEmployees(Employee*, int);
/*brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */

int modifyEmployee(Employee*, int, int);
/*brief Permite modificar un campo a eleccion del empleado
 *
 * \param1	ingresa el vector con los empleados
 * \param2	ingresa el tamaño del vector de los empleados
 * \param3	ingresa el id del empleado para buscarlo y modificar
 * \return	Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */

int statusEmployees(Employee*, int);
/*brief Revisa el estado de los elementos del vector de empleados
 *
 *\param1	ingresa el vector con los empleados
 * \param2	ingresa el tamaño del vector de los empleados
 * \return	Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 * 			(1) si todos los isEmpty estan vacios
 */

int salaryEmployees(Employee*, int);
/*brief	Calcula el total y promedio de los salarios e imprime el total, el promedio y cuantos empleados superan el promedio
 *
 *\param1	ingresa el vector con los empleados
 * \param2	ingresa el tamaño del vector de los empleados
 * \return	Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */

#endif /* ARRAYEMPLOYEES_H_ */
