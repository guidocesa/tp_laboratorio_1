#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "funciones.h"

int confirmarSalida()
{
    int retorno = 0;
    system("cls");
    printf("Seguro que desea salir del programa? \n 1 : Si \n 0 : No  \n\n Sus cambios o bicicletas no seran guardados. \n");
    fflush(stdin);
    scanf("%i", &retorno);
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
        printf("1 - Dar de ALTA una bicicleta.\n");
        printf("2 - Modificar datos de una bicicleta. \n");
        printf("3 - Dar de BAJA una bicicleta. \n");
        printf("4 - Ver todas las bicicletas. \n");
        printf("5 - Ver todas los tipos de bicicletas. \n");
        printf("6 - Ver todas los colores de bicicletas. \n");
        printf("7 - Ver todas los servicios para bicicletas. \n");
        printf("8 - Dar de ALTA un trabajo realizado.\n");
        printf("9 - Ver todos los trabajos realizados.\n");
        printf("0 - Salir de la base de datos. \n");

        fflush(stdin);

        scanf("%i" , &seleccion );

        if(seleccion < 10 && seleccion > -1)
        {
            seleccionEsCorrecta = 1;
        }
    }

    return seleccion;
}

void formatearString(char marca[])
{
    int i = 0;
    while (marca[i])
    {
        marca[i] = tolower(marca[i]);
        i++;
    }
    marca[0] = toupper(marca[0]);
}

int menuPrincipal(eBicicleta bicicletas[], int largoBicicletas, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eServicio servicios[], int largoServicios , eTrabajo trabajos[], int largoTrabajos)
{
    int trabajosRealizados = 0;
    int programaTerminado = 0;
    int opcionSeleccionada;
    while(!programaTerminado)
    {
        opcionSeleccionada = mostrarOpcionesYObtenerSeleccion();
        switch(opcionSeleccionada)
        {
        case 1:
            solicitarDatosYAgregarBicicletaOrdenada(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores);
            break;
        case 2:
            modificarBicicleta(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores);
            break;
        case 3:
            darDeBajaBicicleta(bicicletas, largoBicicletas);
            break;
        case 4:
            listarBicicletas(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores);
            break;
        case 5:
            system("cls");
            listarTipos(tipos, largoTipos);
            system("pause");
            break;
        case 6:
            system("cls");
            listarColores(colores, largoColores);
            system("pause");
            break;
        case 7:
            system("cls");
            listarServicios(servicios, largoServicios);
            system("pause");
            break;
        case 8:
            altaTrabajo(trabajos, largoTrabajos, bicicletas, largoBicicletas, servicios, largoServicios, trabajosRealizados);
            trabajosRealizados ++;
            break;
        case 9:
            listarTrabajos(trabajos, largoTrabajos, servicios, largoServicios, trabajosRealizados);
            break;
        case 0:
            programaTerminado =  confirmarSalida();
            break;
        }
    }

    return 0;

}

void hardcodearDatos(eTipo tipos[], int largoTipos, eColor colores[], int  largoColores,eServicio servicios[], int largoServicios)
{
    strcpy(tipos[0].descripcion , "Rutera");
    tipos[0].id = 1000;
    strcpy(tipos[1].descripcion , "Carrera");
    tipos[1].id = 1001;
    strcpy(tipos[2].descripcion , "Mountain");
    tipos[2].id = 1002;
    strcpy(tipos[3].descripcion , "BMX");
    tipos[3].id = 1003;

    strcpy(colores[0].nombreColor , "Gris");
    colores[0].id = 5000;
    strcpy(colores[1].nombreColor , "Negro");
    colores[1].id = 5001;
    strcpy(colores[2].nombreColor , "Blanco");
    colores[2].id =5002;
    strcpy(colores[3].nombreColor , "Azul");
    colores[3].id =5003;
    strcpy(colores[4].nombreColor , "Rojo");
    colores[4].id =5004;

    strcpy(servicios[0].descripcion , "Limpieza");
    servicios[0].precio = 250;
    servicios[0].id = 20000;
    strcpy(servicios[1].descripcion , "Parche");
    servicios[1].precio = 300;
    servicios[1].id = 20001;
    strcpy(servicios[2].descripcion , "Centrado");
    servicios[2].precio = 400;
    servicios[2].id = 20002;
    strcpy(servicios[3].descripcion , "Cadena");
    servicios[3].precio = 350;
    servicios[3].id = 20003;

}
