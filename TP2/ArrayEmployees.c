#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define EMPLEADOSMAXIMOS 1000

/** \brief Setea todo el array de empleados como vacio.
 *
 * \param empleados[] eEmpleado
 * \param largo int
 * \return void
 *
 */
void inicializarEmpleados(eEmpleado empleados[] , int largo)
{
    for(int i = 0; i < largo; i++)
    {
        empleados[i].estaVacio = 1;
    }
}

/** \brief Devuelve el menor Id libre arrancando en el nomero 1
 *
 * \param empleados[] eEmpleado
 * \param largo int
 * \return int
 *
 */
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

/** \brief Recibe por parametro todos los datos necesarios para cargar un empleado nuevo y lo coloca ordenado dentro del array. En caso de estar lleno devuelve -1.
 *
 * \param empleados[] eEmpleado
 * \param largo int
 * \param nombre[51] char
 * \param apellido[51] char
 * \param sueldo float
 * \param sector int
 * \return int
 *
 */
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

/** \brief Muestra las opciones y devuelve la seleccionada por el usuario.
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

/** \brief Pide confirmar que se desea salir.
 *
 * \return int
 *
 */
int confirmarSalida()
{
    int retorno = 0;
    system("cls");
    printf("Seguro que desea salir del programa? \n 1 : Si \n 0 : No  \n\n Sus cambios o empleados no seran guardados. \n");
    fflush(stdin);
    scanf("%i", &retorno);
    return retorno;
}

/** \brief Recibe por parametro el Id de un empleado y lo quita del array y luego reordena el mismo. Devuelve 1 si fue dado de baja o 0 si no fue encontrado.
 *
 * \param empleados[] eEmpleado
 * \param id int
 * \param largo int
 * \return int
 *
 */
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

/** \brief Pide el Id del empleado a borrar y avisa si no se pudo realizar la baja.
 *
 * \param empleados[] eEmpleado
 * \param largo int
 * \return int
 *
 */
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

/** \brief Normaliza los String ingresados por el usuario para que solo la primer letra sea mayucula. ej: JuAN  --> Juan
 *
 * \param nombre[] char
 * \return void
 *
 */
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

/** \brief Pide todos los datos necesarios para cargar un empleado por consola y luego llama a AgregarEmpleadoOrdenado.
 *
 * \param empleados[] eEmpleado
 * \param largo int
 * \return void
 *
 */
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

/** \brief Muestra el promedio de sueldos, cuantos empleados estan sobre este ppromedio y cuento es la totalidad de salarios. Avisa si el Array esta vacio.
 *
 * \param empleados[] eEmpleado
 * \param largo int
 * \return void
 *
 */
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

/** \brief Muestra los datos de un Empleado por consola.
 *
 * \param empleado eEmpleado
 * \return void
 *
 */
void printEmpleado(eEmpleado empleado)
{
    printf("%d\t%s\t\t%s\t\t%2.f\t\t%d\n", empleado.id, empleado.nombre, empleado.apellido, empleado.sueldo, empleado.sector);
}

/** \brief Muestra a todos los empleados en el array de manera formateada.
 *
 * \param empleados[] eEmpleado
 * \param largo int
 * \return void
 *
 */
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

/** \brief Muestra el menu de la seccion Informacion.
 *
 * \param empleados[] eEmpleado
 * \param largo int
 * \return void
 *
 */
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

/** \brief Pide un Id y muestra al empleado con dicho Id y confirma si desea modificarse ese empleado. Luego llama a Borrar empleado y a agregar uno nuevo.
 *
 * \param empleados[] eEmpleado
 * \param largo int
 * \return void
 *
 */
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

/** \brief Menu interno que llama a las funciones correspondientes segun la seleccion del usuario.
 *
 * \param empleados[] eEmpleado
 * \param largo int
 * \return void
 *
 */
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

/** \brief Si el array no esta lleno, mueve a todos los empleados una posicion hacia adelante para "hacer lugar" y colocar el empleado nuevo ya ordenado.
 *
 * \param posicionInicial int
 * \param empleados[] eEmpleado
 * \param largo int
 * \return int
 *
 */
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
