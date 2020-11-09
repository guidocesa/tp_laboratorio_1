#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <ctype.h>

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

/** \brief Muestra las opciones del menu y obtiene la seleccionada por el usuario.
 *
 * \return int
 *
 */
int mostrarOpcionesYObtenerSeleccion()
{
    int seleccion;
    int seleccionEsCorrecta = 0;

    while(!seleccionEsCorrecta)
    {

        system("cls");
        printf("Por favor seleccione una opcion y presione la tecla enter: \n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
        printf("3. Alta de empleado \n");
        printf("4. Modificar datos de empleado \n");
        printf("5. Baja de empleado \n");
        printf("6. Listar empleados \n");
        printf("7. Ordenar empleados \n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario). \n");
        printf("10. Salir \n");


        fflush(stdin);

        scanf("%i" , &seleccion );

        if(seleccion < 11 && seleccion > -1)
        {
            seleccionEsCorrecta = 1;
        }
    }

    return seleccion;



}

/** \brief Formatea el string para que solo la primer letra sea mayuscula
 *
 * \param nombre char*
 * \return void
 *
 */
void formatearString(char* nombre)
{
    int i = 0;
    while (*(nombre + i))
    {
        *(nombre + i) = tolower(*(nombre+i));
        i++;
    }
    *nombre = toupper(*nombre);
}



int main()
{
    int option = 0;
    int idAcumulativo = 1;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        option = mostrarOpcionesYObtenerSeleccion();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados, &idAcumulativo);
                break;
            case 2:
                controller_loadFromBinary("prueba.bin", listaEmpleados, &idAcumulativo);
                break;
            case 3:
                controller_addEmployee(listaEmpleados, &idAcumulativo);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("prueba.csv" , listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("prueba.bin", listaEmpleados);
                break;
            case 10:
                break;
        }
    }while(option != 10);
    return 0;
}
