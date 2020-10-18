#include "trabajo.h"
#include "bicicleta.h"
#include "servicio.h"

void inicializarTrabajos(eTrabajo trabajos[], int largo)
{
    for(int i = 0; i < largo; i++)
    {
        trabajos[i].estaVacio = 1;
    }
}

void agregarTrabajo(eTrabajo trabajos[],int idBicicleta,int  idServicio,int  dia,int  mes,int  anio, int trabajosRealizados)
{
    eFecha fecha;
    fecha.dia = dia;
    fecha.mes = mes;
    fecha.anio = anio;

    trabajos[trabajosRealizados].idBicicleta = idBicicleta;
    trabajos[trabajosRealizados].idServicio = idServicio;
    trabajos[trabajosRealizados].fecha = fecha;

    trabajosRealizados ++;
}

void altaTrabajo(eTrabajo trabajos[], int largoTrabajos,eBicicleta bicicletas[], int largoBicicletas,eServicio servicios[],int largoServicios, int trabajosRealizados)
{

    int idBicicleta;
    int idServicio;
    int dia;
    int mes;
    int anio;

    system("cls");
    printf("Por favor ingrese el id de la bicicleta seguido de la tecla enter. \n\n");
    fflush(stdin);
    scanf("%i" , &idBicicleta);

    if(idEstaEnElListado(idBicicleta, bicicletas, largoBicicletas))
    {
        do
        {
            system("cls");
            printf("Por favor ingrese el id del servicio a realizar. \n\n");
            listarServicios(servicios, largoServicios);
            fflush(stdin);
            scanf("%i" , &idServicio);
        }while(idServicio < 20000 || idServicio > 20004);

        do
        {
            system("cls");
            printf("Por favor ingrese el numero de dia de hoy. \n\n");
            fflush(stdin);
            scanf("%i" , &dia);
        }while(dia < 1 || dia > 31);

        do
        {
            system("cls");
            printf("Por favor ingrese el numero de mes. \n\n");
            fflush(stdin);
            scanf("%i" , &mes);
        }while(mes < 1 || mes > 12);

        do
        {
            system("cls");
            printf("Por favor ingrese el anio. \n\n");
            fflush(stdin);
            scanf("%i" , &anio);
        }while(anio < 1980 || anio > 2100);

        agregarTrabajo(trabajos, idBicicleta, idServicio, dia, mes, anio, trabajosRealizados);

    }
    else
    {
        printf("No hay una bicicleta con ese ID. \n\n");
        system("pause");
    }
}

void listarTrabajos(eTrabajo trabajos[], int largoTrabajos, eServicio servicios[], int largoServicios, int trabajosRealizados )
{
    system("cls");
    printf("Trabajos realizados:\n\n");
    printf("ID\tID BICICLETA\tSERVICIO\tFECHA\t\n");
    printf("----------------------------------------------\n");

    int i = 0;

    while(i < trabajosRealizados)
    {
        char descServicio[21];

        strcpy(descServicio, obtenerDescServicio(servicios, largoServicios, trabajos[i].idServicio));

        printf("%i\t%i\t%s\t%i/%i/%i\n", trabajos[i].id, trabajos[i].idBicicleta, descServicio, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);

        i++;
    }

    system("pause");
}
