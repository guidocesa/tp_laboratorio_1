#include "LinkedList.h"
#include "Employee.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/** \brief Crea y devuelve un puntero a Employee vacio.
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
    return nuevoEmpleado;
}

/** \brief Crea un empleado con los datos recibidos y desvuelve un puntero al mismo
 *
 * \param id int
 * \param nombreStr char*
 * \param horasTrabajadasStr int
 * \param sueldo int
 * \return Employee*
 *
 */
Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadasStr, int sueldo)
{

    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = id;
        strcpy(nuevoEmpleado->nombre, nombreStr);
        nuevoEmpleado->horasTrabajadas = horasTrabajadasStr;
        nuevoEmpleado->sueldo = sueldo;
    }
    return nuevoEmpleado;
}

/** \brief Libera la memoria del empleado recibido
 *
 * \param empleado Employee*
 * \return void
 *
 */
void employee_delete(Employee* empleado)
{
    free(empleado);
}

/** \brief Settea el id del empleado.
 *
 * \param empleado Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* empleado,int id)
{
    if(empleado != NULL)
    {
        empleado->id = id;
        return 1;
    }
    else{return 0;}
}

/** \brief escribe el id del empleado a la variable recibida.
 *
 * \param empleado Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* empleado,int* id)
{
    if(empleado!= NULL)
    {
        *id = empleado->id;
        return 1;
    }
    else
    {
        return 0;
    }
}

/** \brief Setea el nombre
 *
 * \param empleado Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* empleado,char* nombre)
{
    if(empleado != NULL)
    {
        strcpy(empleado->nombre, nombre);
        return 1;
    }
    else{return 0;}
}
/** \brief Copia el nombre al punteroa  char recibido.
 *
 * \param empleado Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* empleado,char* nombre)
{
    if(empleado!= NULL)
    {
        strcpy(nombre, empleado->nombre);
        return 1;
    }
    else
    {
        return 0;
    }
}

/** \brief Setea las horas trabajadas
 *
 * \param empleado Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* empleado,int horasTrabajadas)
{
    if(empleado != NULL)
    {
        empleado->horasTrabajadas = horasTrabajadas;
        return 1;
    }
    else{return 0;}
}

/** \brief Escribe las horas trabajadas a la variable del puntero recibido.
 *
 * \param empleado Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* empleado,int* horasTrabajadas)
{
    if(empleado!= NULL)
    {
        *horasTrabajadas = empleado->horasTrabajadas;
        return 1;
    }
    else
    {
        return 0;
    }
}

/** \brief Setea el sueldo de un empleado.
 *
 * \param empleado Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* empleado,int sueldo)
{
    if(empleado != NULL)
    {
        empleado->sueldo = sueldo;
        return 1;
    }
    else{return 0;}
}
/** \brief escribe el valor del sueldo a la variable del puntero recibido.
 *
 * \param empleado Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* empleado,int* sueldo)
{
    if(empleado!= NULL)
    {
        *sueldo = empleado->sueldo;
        return 1;
    }
    else
    {
        return 0;
    }
}

/** \brief Compara dos empleados segun su id
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int compararPorId(void* emp1, void* emp2)
{
    int id1;
    int id2;
    int retorno;

    employee_getId(emp1, &id1);
    employee_getId(emp2, &id2);

    if((id1 - id2) > 0)
    {
        retorno = 1;
    }
    else
    {
        if(id1 - id2 == 0)
        {
            retorno = 0;
        }
        else
        {
            retorno = -1;
        }
    }

    return retorno;
}

/** \brief Compara dos empleados segun su nombre
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int compararPorNombre(void* emp1, void* emp2)
{
    char* nombre1 =(char*) malloc(sizeof(char) * 128);
    char* nombre2 = (char*) malloc(sizeof(char) * 128);

    employee_getNombre(emp1,nombre1);
    employee_getNombre(emp2,nombre2);

    int retorno = strcmp(nombre1 , nombre2);

    free(nombre1);
    free(nombre2);

    return retorno;


}

/** \brief Compara dos empleados segun sus horas trabajadas
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int compararPorHorasTrabajadas(void* emp1, void* emp2)
{
    int horas1;
    int horas2;

    employee_getHorasTrabajadas(emp1, &horas1);
    employee_getHorasTrabajadas(emp2, &horas2);

    int retorno;

    if((horas1 - horas2) > 0)
    {
        retorno = 1;
    }
    else
    {
        if(horas1 - horas2 == 0)
        {
            retorno = 0;
        }
        else
        {
            retorno = -1;
        }
    }

    return retorno;
}

/** \brief Compara dos empleados segun su sueldo.
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int compararPorSueldo(void* emp1, void* emp2)
{
    int sueldo1;
    int sueldo2;
    int retorno;

    employee_getSueldo(emp1, &sueldo1);
    employee_getSueldo(emp2, &sueldo2);

    if((sueldo1 - sueldo2) > 0)
    {
        retorno = 1;
    }
    else
    {
        if(sueldo1 - sueldo2 == 0)
        {
            retorno = 0;
        }
        else
        {
            retorno = -1;
        }
    }

    return retorno;
}
