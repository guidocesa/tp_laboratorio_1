#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include <string.h>


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* idAcumulativo)
{
    FILE* archivo = fopen("data.csv", "r");
    *idAcumulativo = (*idAcumulativo +parser_EmployeeFromText(archivo , pArrayListEmployee));
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* idAcumulativo)
{
    FILE* archivoBin;
    Employee* empNuevo = employee_new();
    int cant;

    if((archivoBin=fopen(path, "rb")) == NULL)
    {
        printf("No se pudo abrir el archivo. \n");
        system("pause");
        return -1;
    }

    while(!feof(archivoBin))
    {
        cant = fread(empNuevo, sizeof(Employee), 1, archivoBin);

        if(cant != 1)
        {
            if(feof(archivoBin))
            {
                break;
            }
            else
            {
                printf("No se pudo leer el ultimo registro.");
                system("pause");
                break;
            }
        }

        ll_add(pArrayListEmployee, employee_newParametros(empNuevo->id, empNuevo->nombre, empNuevo->horasTrabajadas, empNuevo->sueldo ));
        *idAcumulativo = (*idAcumulativo + 1);
    }

    free(empNuevo);

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* listaEmpleados, int * idAcumulativo)
{
    char* nombre = (char *) malloc(sizeof(char) * 128);
    int sueldo;
    int horasTrabajadas;

    system("cls");
    printf("Por favor ingrese el nombre completo del empleado y luego la tecla enter. (Solo el nombre) \n\n");
    fflush(stdin);
    gets(nombre);
    formatearString(nombre);

    do
    {
        system("cls");
        printf("Por favor ingrese el sueldo del empleado seguido de la tecla enter. (Solo valores positivos son permitidos.)\n\n");
        fflush(stdin);
        scanf("%i" , &sueldo);
    }while(!(sueldo > 0));

    do
    {
        system("cls");
        printf("Por favor ingrese las horas trabajadas del empleado seguido de la tecla enter. \n\n");
        fflush(stdin);
        scanf("%i" , &horasTrabajadas);
    }while(!(horasTrabajadas > 0 && horasTrabajadas < 500));
    printf("ACA 0");


    Employee* nuevoEmpleado = employee_newParametros(*idAcumulativo, nombre, horasTrabajadas, sueldo);

    free(nombre);

    if(nuevoEmpleado != NULL)
    {
        ll_add(listaEmpleados, nuevoEmpleado);
        *idAcumulativo = (*idAcumulativo + 1);
        return 1;
    }
    else
    {
        return 0;
    }
}

/** \brief Muestra las opciones y devuelve la seleccionada por el ususario.
 *
 * \return int
 *
 */
int mostrarMenuModificacion()
{
    int seleccion;

    do
    {
        system("cls");
        printf("Seleccione que desea modificar:\n\n1. Nombre\n2. Horas Trabajadas\n3. Sueldo");
        fflush(stdin);
        scanf("%i", &seleccion);
    }while(seleccion < 1 || seleccion > 3);

    return seleccion;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    int idAModificar;
    int auxId;
    int idEncontrado = 0;
    int empeladoModificado = 0;
    Node* pNodo = pArrayListEmployee->pFirstNode;

    printf("Por favor ingrese el numero de ID del empleado a modificar seguido de la tecla enter.\n");
    controller_ListEmployee(pArrayListEmployee);
    printf("\n\n");
    fflush(stdin);
    scanf("%i", &idAModificar);

    while(!idEncontrado && pNodo !=NULL)
    {
        employee_getId(pNodo->pElement, &auxId);
        if(auxId == idAModificar)
        {
            idEncontrado = 1;
        }
        else
        {
            pNodo = pNodo->pNextNode;
        }
    }

    if(idEncontrado)
    {
        int horasTrabajadasNuevas = -1;
        int sueldoNuevo = 0;
        char* nombreNuevo = (char*) malloc(sizeof(char) * 128);

        int seleccion = mostrarMenuModificacion();
        switch(seleccion)
        {
            case 1:

                printf("Por favor ingrese el nuevo nombre y luego la tecla enter. \n\n");
                fflush(stdin);
                gets(nombreNuevo);
                formatearString(nombreNuevo);
                employee_setNombre(pNodo->pElement, nombreNuevo);
                break;

            case 2:

                do
                {
                    system("cls");
                    printf("Por favor ingrese el numero de horas trabajadas seguido de la tecla enter. \n\n");
                    fflush(stdin);
                    scanf("%i" , &horasTrabajadasNuevas);
                }while(!(horasTrabajadasNuevas > 0 && horasTrabajadasNuevas < 500));
                employee_setHorasTrabajadas(pNodo->pElement, horasTrabajadasNuevas);
                break;

            case 3:

                do
                {
                    system("cls");
                    printf("Por favor ingrese el nuevo sueldo seguido de la tecla enter.  \n\n");
                    fflush(stdin);
                    scanf("%i" , &sueldoNuevo);
                }while(!(sueldoNuevo > 0));
                employee_setSueldo(pNodo->pElement, sueldoNuevo);
                break;

        }
        empeladoModificado = 1;

    }
    else
    {
        printf("No se pudo encontrar un empleado con ese Id, por favor confirme que sea el correcto.");
        system("pause");
    }

    return empeladoModificado;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    system("cls");
    printf("Ingrese el ID del empleado que desea dar de baja y luego presione enter. \n\n");
    controller_ListEmployee(pArrayListEmployee);
    fflush(stdin);
    scanf("%i" , &id);

    int index = 0;
    int encontrado = 0;
    int auxId;
    Node* auxNodo = pArrayListEmployee->pFirstNode;
    while(auxNodo != NULL && !encontrado)
    {
        employee_getId(auxNodo->pElement, &auxId);
        if(auxId == id)
        {
            encontrado = 1;
        }
        else
        {
            auxNodo = auxNodo->pNextNode;
            index ++;
        }
    }
    if(encontrado)
    {
        ll_remove(pArrayListEmployee, index);
    }

    if(!encontrado)
    {
        printf("Ese ID de empleado no se encuentra en el sistema, por favor checkee en el listado. /n");
        system("pause");
    }
    else
    {
        printf("Baja exitosa, presione cualquier tecla para continuear.");
        system("pause");
    }
    return(encontrado);
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        int i = 0;
        Node* auxNodo = pArrayListEmployee->pFirstNode;
        printf("ID\t NOMBRE\t\t SUELDO\t HORAS TRABAJADAS\t\n");
        printf("--------------------------------------------------------------------\n\n");
        while(auxNodo != NULL)
        {
            Employee* pEmpleado = (Employee*) auxNodo->pElement;
            printf("%i\t%s\t\t%i\t%i\n",pEmpleado->id, pEmpleado->nombre, pEmpleado->sueldo, pEmpleado->horasTrabajadas);
            auxNodo = auxNodo->pNextNode;
            i++;
            if(i == 200)
            {
                system("pause");
                i = 0;
            }
        }
        system("pause");
        return 1;
    }
    else
    {
        return 0;
    }
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    if(!ll_isEmpty(pArrayListEmployee) && pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Por favor seleccione como desea ordenar la lista de empleados:\n");
        printf("1. Por nombre ascendente\n");
        printf("2. Por nombre descendente\n");
        printf("3. Por id ascendente\n");
        printf("4. Por id descendente\n");
        printf("5. Por horas trabajadas ascendente\n");
        printf("6. Por horas trabajadas descendente\n");
        printf("7. Por sueldo ascendente\n");
        printf("8. Por sueldo descendente\n");
        int seleccion;
        scanf("%i", &seleccion);

        switch(seleccion)
        {
        case 1:
            ll_sort(pArrayListEmployee, compararPorNombre , 1);
            break;
        case 2:
            ll_sort(pArrayListEmployee, compararPorNombre, 0);
            break;
        case 3:
            ll_sort(pArrayListEmployee, compararPorId, 1);
            break;
        case 4:
            ll_sort(pArrayListEmployee, compararPorId, 0);
            break;
        case 5:
            ll_sort(pArrayListEmployee, compararPorHorasTrabajadas, 1);
            break;
        case 6:
            ll_sort(pArrayListEmployee, compararPorHorasTrabajadas, 0);
            break;
        case 7:
            ll_sort(pArrayListEmployee, compararPorSueldo, 1);
            break;
        case 8:
            ll_sort(pArrayListEmployee, compararPorSueldo, 0);
            break;

        }

        return 1;
    }
    else
    {
        return 0;
    }


}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* auxE;
    int largoId, largoSueldo, largoHoras;

    if((pArchivo = fopen(path, "w"))== NULL)
    {
        return 0;
    }
    int largo = ll_len(pArrayListEmployee);

    fwrite("ID,NOMBRE,HORASTRABAJADAS,SUELDO\n", sizeof(char), strlen("ID,NOMBRE,HORASTRABAJADAS,SUELDO\n"), pArchivo);

    for(int i = 0; i < largo; i++)
    {
        auxE = ll_get(pArrayListEmployee, i);

        largoId = snprintf(NULL, 0, "%d", auxE->id);
        char* sId = (char*)malloc(largoId + 1);
        snprintf(sId, largoId + 1, "%i", auxE->id );

        largoSueldo = snprintf(NULL, 0, "%d", auxE->sueldo);
        char* sSueldo = (char*)malloc(largoSueldo + 1);
        snprintf(sSueldo, largoSueldo + 1, "%i", auxE->sueldo );

        largoHoras = snprintf(NULL, 0, "%d", auxE->horasTrabajadas);
        char* sHoras = (char*)malloc(largoHoras + 1);
        snprintf(sHoras, largoHoras + 1, "%i", auxE->horasTrabajadas );

        fwrite(sId, sizeof(char), largoId, pArchivo);
        fwrite(",", sizeof(char), 1, pArchivo);
        fwrite(auxE->nombre, sizeof(char), strlen(auxE->nombre), pArchivo);
        fwrite(",", sizeof(char), 1, pArchivo);
        fwrite(sHoras, sizeof(char), largoHoras, pArchivo);
        fwrite(",", sizeof(char), 1, pArchivo);
        fwrite(sSueldo, sizeof(char), largoSueldo, pArchivo);
        fwrite("\n", sizeof(char), 1, pArchivo);
    }

    fclose(pArchivo);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* archivoBin;
    Employee* auxEmp;

    if(pArrayListEmployee != NULL)
    {

        int largo = ll_len(pArrayListEmployee);

        archivoBin = fopen(path, "wb");
        for(int i = 0; i < largo ; i++)
        {
            auxEmp = ll_get(pArrayListEmployee, i);
            fwrite(auxEmp, sizeof(Employee), 1, archivoBin);

        }
        fclose(archivoBin);

        return 1;
    }
    else
    {
        return 0;
    }
}

