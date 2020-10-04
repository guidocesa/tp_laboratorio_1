#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define EMPLEADOSMAXIMOS 1000

void inicializarEmpleados(eEmpleado empleados[] , int largo)
{
    for(int i = 0; i < largo; i++)
    {
        empleados[i].estaVacio = 1;
    }
}

int obtenerIdLibre(eEmpleado empleados[] , int largo)
{
    int idNuevo = 1;
    int i = 0;
    while(i < largo && !empleados[i].estaVacio)
    {
        if(idNuevo == empleados[i].id)
        {
            idNuevo ++;
            i = 0;//Se tiene que hacer ya que no puedo garantizar que el id nuevo no se repita con los que ya cicle
        }
        else
        {
            i++;
        }
    }
    return idNuevo;

}

int agregarEmpleadoOrdenado(eEmpleado empleados[] , int largo, char nombre[51], char apellido[51], float sueldo, int sector)
{
    int retorno = 0;
    int i = 0;
    int fueAgregado = 0;
    int id = obtenerIdLibre(empleados ,  largo);
    while(!fueAgregado && i < largo)
    {
        if(strcmp(apellido , empleados[i].apellido ) < 0  ||
           empleados[i].estaVacio ||
           (strcmp(apellido , empleados[i].apellido ) == 0 && sector - empleados[i].sector <= 0))
        {
           if(!empleados[i].estaVacio)
           {
                if(moverEmpleadosDesde(i , empleados, largo))
                {
                    empleados[i].id = id;
                    strcpy(empleados[i].nombre , nombre);
                    strcpy(empleados[i].apellido , apellido);
                    empleados[i].sueldo = sueldo;
                    empleados[i].sector = sector;
                    empleados[i].estaVacio = 0;
                    fueAgregado = 1;
                }
                else
                {
                    retorno = -1;
                }
           }
           else
           {
                    empleados[i].id = id;
                    strcpy(empleados[i].nombre , nombre);
                    strcpy(empleados[i].apellido , apellido);
                    empleados[i].sueldo = sueldo;
                    empleados[i].sector = sector;
                    empleados[i].estaVacio = 0;
                    fueAgregado = 1;
           }
        }
        i++;
    }
    if( i == 1000 && !fueAgregado)
    {
        retorno = -1;
    }
    return retorno;
}

int mostrarOpcionesYObtenerSeleccion()
{
    int seleccion;
    int seleccionEsCorrecta = 0;

    while(!seleccionEsCorrecta)
    {

        system("cls");
        printf("Por favor seleccione una opcion y presione la tecla enter: \n\n");
        printf("1 - Dar de ALTA un empleado.\n");
        printf("2 - Modificar datos de un empleado. \n");
        printf("3 - Dar de BAJA un empleado. \n");
        printf("4 - Ver informacion de empleados. \n");
        printf("0 - Salir de la base de datos. \n");

        fflush(stdin);

        scanf("%i" , &seleccion );

        if(seleccion < 5 && seleccion > -1)
        {
            seleccionEsCorrecta = 1;
        }
    }

    return seleccion;



}

int confirmarSalida()
{
    int retorno = 0;
    system("cls");
    printf("Seguro que desea salir del programa? \n 1 : Si \n 0 : No  \n\n Sus cambios o empleados no seran guardados. \n");
    fflush(stdin);
    scanf("%i", &retorno);
    return retorno;
}

int borrarEmpleadoPorId(eEmpleado empleados[], int id, int largo)
{
    int fueDadoDeBaja = 0;
    for(int i = 0 ; i < largo ; i++)
    {
        if(empleados[i].id == id)
        {
            for(int u = i ; u < (largo - 1); u ++)
            {
                empleados[u] = empleados[u + 1];
            }
            empleados[largo - 1].estaVacio = 1;
            fueDadoDeBaja = 1;
            break;
        }
    }
    return(fueDadoDeBaja);
}

int darDeBajaEmpleado(eEmpleado empleados[], int largo)
{
    int id;
    system("cls");
    printf("Ingrese el ID del empleado que desea dar de baja y luego presione enter. \n\n");
    fflush(stdin);
    scanf("%i" , &id);

    int fueBorrado = borrarEmpleadoPorId(empleados , id, largo);

    if(!fueBorrado)
    {
        printf("Ese ID de empleado no se se encuentra en el sistema, por favor checkee en la seccion de informacion si es necesario. /n");
        system("pause");
    }
    return !fueBorrado;
}

void formatearString(char nombre[])
{
    int i = 0;
    while (nombre[i])
    {
        nombre[i] = tolower(nombre[i]);
        i++;
    }
    nombre[0] = toupper(nombre[0]);
}

void solicitarDatosDeEmpleadoYAgregar(eEmpleado empleados[], int largo)
{
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;

    system("cls");
    printf("Por favor ingrese el nombre del empleado y luego la tecla enter. (Solo el nombre) \n\n");
    fflush(stdin);
    gets(nombre);
    formatearString(nombre);

    system("cls");
    printf("Por favor ingrese el apellido del empleado y luego la tecla enter. (Solo el apellido) \n\n");
    fflush(stdin);
    gets(apellido);
    formatearString(apellido);

    do
    {
        system("cls");
        printf("Por favor ingrese el sueldo del empleado seguido de la tecla enter. (Solo valores positivos son permitidos.)\n\n");
        fflush(stdin);
        scanf("%f" , &sueldo);
    }while(sueldo < 0);

    do
    {
        system("cls");
        printf("Por favor ingrese el sector del empleado seguido de la tecla enter. (Valores entre 1 y 100) \n\n");
        fflush(stdin);
        scanf("%i" , &sector);
    }while(sector < 1 || sector > 100);

    agregarEmpleadoOrdenado(empleados , largo , nombre, apellido, sueldo, sector);


}

void mostrarInformacionSueldos(eEmpleado empleados[], int largo)
{
    int arrayVacio = 0;
    float sueldosAcumulados = 0;
    int cantEmpleadosActuales = 0;
    int i = 0;

    if(empleados[i].estaVacio)
    {
        arrayVacio = 1;
    }

    if(!arrayVacio)
    {
        while(!empleados[i].estaVacio && i < largo)
        {
            sueldosAcumulados += empleados[i].sueldo;
            cantEmpleadosActuales ++;
            i++;
        }

        float salarioPromedio = (sueldosAcumulados / cantEmpleadosActuales);
        int cantEmpleadosSobreElPromedio = 0;

        i = 0;

        while(!empleados[i].estaVacio && i < largo)
        {
            if(empleados[i].sueldo > salarioPromedio)
            {
                cantEmpleadosSobreElPromedio ++;
            }
            i++;
        }

        printf("La sumatoria total de los sueldos de los empleados es $%f \n\n" , sueldosAcumulados);
        printf("El promedio del salario de los empleados es $%f \n\n", salarioPromedio);
        printf("La cantidad de empleados que cobran mas que el promedio es %i \n\n", cantEmpleadosSobreElPromedio);
        system("pause");
    }
    else
    {
        printf("La lista de empleados se encuentra vacia.");
        system("pause");
    }
}

void printEmpleado(eEmpleado empleado)
{
    printf("%d\t%s\t\t%s\t\t%2.f\t\t%d\n", empleado.id, empleado.nombre, empleado.apellido, empleado.sueldo, empleado.sector);
}

void mostrarTodosLosEmpleados(eEmpleado empleados[], int largo)
{
    int i = 0;
    system("cls");
    printf("ID\t NOMBRE\t\t APELLIDO\t SALARIO\t SECTOR\n");
    printf("--------------------------------------------------------------------\n\n");
    while(!empleados[i].estaVacio)
    {
        printEmpleado(empleados[i]);
        i++;
    }
    system("pause");
}

void mostrarMenuInformacion(eEmpleado empleados[], int largo)
{
    int seleccionEsCorrecta = 0;
    int seleccion;

    while(!seleccionEsCorrecta)
    {
        printf("Por favor seleccione una opcion y presione la tecla enter: \n\n");
        printf("1 - Mostrar todos los datos de los empleados actuales.\n");
        printf("2 - Mostrar datos sobre sueldos. \n");
        printf("0 - Volver al menu principal. \n");

        fflush(stdin);

        scanf("%i" , &seleccion );

        if(seleccion < 3 && seleccion > -1)
        {
            seleccionEsCorrecta = 1;
        }
    }
    switch(seleccion)
    {
    case 1:
        mostrarTodosLosEmpleados(empleados, largo);
        break;
    case 2:
        mostrarInformacionSueldos(empleados, largo);
        break;
    }
}

void modificarEmpleado(eEmpleado empleados[], int largo)
{
    system("cls");
    int idAModificar;
    int idEncontrado = 0;
    int posicionEmpleadoAModificar;
    int i = 0;
    int confimacion = 0;

    printf("Por favor ingrese el numero de ID del empleado a modificar seguido de la tecla enter.");
    fflush(stdin);
    scanf("%i", &idAModificar);

    while(!idEncontrado && !empleados[i].estaVacio)
    {
        if(empleados[i].id == idAModificar)
        {
            idEncontrado = 1;
            posicionEmpleadoAModificar = i;
        }
        i++;
    }

    if(idEncontrado)
    {
        printf("Estos son los datos actuales del empleado: \n\n");
        printf("ID\t NOMBRE\t\t APELLIDO\t SALARIO\t SECTOR\n");
        printf("--------------------------------------------------------------------\n\n");
        printEmpleado(empleados[posicionEmpleadoAModificar]);
        printf("\n Por favor confirme que desea reingresar los datos de el empleado mostrado. ( 1 = Si / 0 = No)\n");
        fflush(stdin);
        scanf("%i" , &confimacion);
        if(confimacion == 1)
        {
            borrarEmpleadoPorId(empleados, idAModificar, largo);
            solicitarDatosDeEmpleadoYAgregar(empleados, largo);
        }
    }
    else
    {
        printf("No se pudo encontrar un empleado con ese Id, por favor confirme que sea el correcto.");
        system("pause");
    }
}

void menuPrincipal(eEmpleado empleados[], int largo)
{
    int programaTerminado = 0;
    int opcionSeleccionada;
    while(!programaTerminado)
    {
        opcionSeleccionada = mostrarOpcionesYObtenerSeleccion();
        switch(opcionSeleccionada)
        {
        case 1:
            solicitarDatosDeEmpleadoYAgregar(empleados, largo);
            break;
        case 2:
            modificarEmpleado(empleados, largo);
            break;
        case 3:
            darDeBajaEmpleado(empleados, largo);
            break;
        case 4:
            mostrarMenuInformacion(empleados, largo);
            break;
        case 0:
            programaTerminado =  confirmarSalida();
            break;
        }
    }


}

int moverEmpleadosDesde(int posicionInicial , eEmpleado empleados[], int largo)
{
    int retorno;
    if(empleados[(largo - 1)].estaVacio)
    {
        for(int i = (largo - 1) ; i > posicionInicial ; i--)
        {
            empleados[i] = empleados[i - 1];
        }
        empleados[posicionInicial].estaVacio = 1;
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}
