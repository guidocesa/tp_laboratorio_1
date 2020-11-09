#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int totalcargados = 0;
    char* sNombre = (char*) malloc(sizeof(char) * 128);
    char* sId = (char*) malloc(sizeof(char) * 128);
    char* sHoras = (char*) malloc(sizeof(char) * 128);
    char* sSueldo = (char*) malloc(sizeof(char) * 128);
    int esPrimeraLinea = 1;
    int id, horas, sueldo;

    do
    {
        fscanf(pFile, "%[^,], %[^,], %[^,], %[^,\n]\n", sId, sNombre, sHoras, sSueldo);
        if(!esPrimeraLinea)
        {
            sscanf(sId, "%d", &id);
            sscanf(sHoras, "%d", &horas);
            sscanf(sSueldo, "%d", &sueldo);

            ll_add(pArrayListEmployee, employee_newParametros(id, sNombre, horas, sueldo));
            totalcargados ++;
        }
        esPrimeraLinea = 0;
    }while(!feof(pFile));

    return totalcargados;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
