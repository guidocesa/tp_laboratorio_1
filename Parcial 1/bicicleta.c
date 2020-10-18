#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bicicleta.h"
#include "funciones.h"


void inicializarListado(eBicicleta bicicletas[], int largo)
{
    for(int i = 0; i < largo; i++)
    {
        bicicletas[i].estaVacio = 1;
        bicicletas[i].idTipo = 0;
        bicicletas[i].idColor = 0;
    }
}

int obtenerIdLibre(eBicicleta bicicletas[] , int largo)
{
    int idNuevo = 1;
    int i = 0;
    while(i < largo && !bicicletas[i].estaVacio)
    {
        if(idNuevo == bicicletas[i].id)
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

void listarTipos(eTipo tipos[], int largo)
{
    int i = 0;
    printf("ID\t DESCRIPCION\n");
    printf("--------------------------------------------------------------------\n\n");
    while(i < largo)
    {
        printf("%i\t%s\n\n", tipos[i].id , tipos[i].descripcion);
        i++;
    }
}

int moverBicicletasDesde(int posicionInicial, eBicicleta bicicletas[], int largo)
{
    int retorno;
    if(bicicletas[(largo - 1)].estaVacio)
    {
        for(int i = (largo - 1) ; i > posicionInicial ; i--)
        {
            bicicletas[i] = bicicletas[i - 1];
        }
        bicicletas[posicionInicial].estaVacio = 1;
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int agregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, char marca[21], int idTipo, int idColor, float rodado)
{
    int retorno = 0;
    int i = 0;
    int fueAgregado = 0;
    int id = obtenerIdLibre(bicicletas ,  largo);
    while(!fueAgregado && i < largo)
    {
        if( idTipo < bicicletas[i].idTipo ||
           bicicletas[i].estaVacio ||
           ((idTipo == bicicletas[i].idTipo) && rodado < bicicletas[i].rodado))
        {
           if(!bicicletas[i].estaVacio)
           {
                if(moverBicicletasDesde(i , bicicletas, largo))
                {
                    bicicletas[i].id = id;
                    strcpy(bicicletas[i].marca , marca);
                    bicicletas[i].idTipo = idTipo;
                    bicicletas[i].idColor = idColor;
                    bicicletas[i].rodado = rodado;
                    bicicletas[i].estaVacio = 0;
                    fueAgregado = 1;
                }
                else
                {
                    retorno = -1;
                }
           }
           else
           {
                    bicicletas[i].id = id;
                    strcpy(bicicletas[i].marca , marca);
                    bicicletas[i].idTipo = idTipo;
                    bicicletas[i].idColor = idColor;
                    bicicletas[i].rodado = rodado;
                    bicicletas[i].estaVacio = 0;
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

void solicitarDatosYAgregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores)
{
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;

    system("cls");
    printf("Por favor ingrese la marca de la bicicleta y luego la tecla enter. \n\n");
    fflush(stdin);
    gets(marca);
    formatearString(marca);

    do
    {
        system("cls");
        printf("Por favor ingrese el id del tipo de bicicleta seguido de la tecla enter. \n\n");
        listarTipos(tipos, largoTipos);
        fflush(stdin);
        scanf("%i" , &idTipo);
    }while(idTipo < 1000 || idTipo > 1003);

    do
    {
        system("cls");
        printf("Por favor ingrese el ID del color seguido de la tecla enter.  \n\n");
        listarColores(colores, largoColores);
        fflush(stdin);
        scanf("%i" , &idColor);
    }while(idColor < 5000 || idColor > 5004);

    do
    {
        system("cls");
        printf("Por favor ingrese el rodado de la bicicleta seguido de la tecla enter.  \n\n");
        fflush(stdin);
        scanf("%f" , &rodado);
    }while(rodado < 20 || rodado > 29);

    agregarBicicletaOrdenada(bicicletas , largo, marca, idTipo, idColor, rodado);
}

void darDeBajaBicicleta(eBicicleta bicicletas[], int largo)
{
    int id;
    system("cls");
    printf("Ingrese el ID de la bicicleta que desea dar de baja y luego presione enter. \n\n");
    fflush(stdin);
    scanf("%i" , &id);

    int fueBorrado = borrarBicicletaPorId(bicicletas , id, largo);

    if(!fueBorrado)
    {
        printf("Ese ID de bicicleta no se encuentra en el sistema, por favor checkee en el listado. /n");
        system("pause");
    }
}

int borrarBicicletaPorId(eBicicleta bicicletas[], int id, int largo)
{
    int fueBorrada = 0;
    for(int i = 0 ; i < largo ; i++)
    {
        if(bicicletas[i].id == id)
        {
            for(int u = i ; u < (largo - 1); u ++)
            {
                bicicletas[u] = bicicletas[u + 1];
            }
            bicicletas[largo - 1].estaVacio = 1;
            fueBorrada = 1;
            break;
        }
    }
    return(fueBorrada);
}

void modificarBicicleta(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores)
{
    system("cls");
    int idAModificar;
    int idEncontrado = 0;
    int i = 0;

    printf("Por favor ingrese el numero de ID de la bicicleta a modificar seguido de la tecla enter.");
    fflush(stdin);
    scanf("%i", &idAModificar);

    while(!idEncontrado && !bicicletas[i].estaVacio)
    {
        if(bicicletas[i].id == idAModificar)
        {
            idEncontrado = 1;
        }
        i++;
    }

    if(idEncontrado)
    {
        borrarBicicletaPorId(bicicletas, idAModificar, largo);
        solicitarDatosYAgregarBicicletaOrdenada(bicicletas, largo, tipos, largoTipos, colores, largoColores);

    }
    else
    {
        printf("No se pudo encontrar una bicicleta con ese Id, por favor confirme que sea el correcto.");
        system("pause");
    }
}

void listarBicicletas(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores)
{
    int i = 0;
    char colorAMostrar[21];
    char tipoAMostrar[21];
    system("cls");
    printf("ID\t MARCA\t\t IDTIPO\t IDCOLOR\t RODADO\n");
    printf("--------------------------------------------------------------------\n\n");
    while(!bicicletas[i].estaVacio)
    {
        strcpy(colorAMostrar, obtenerNombreColor(colores, largoColores, bicicletas[i].idColor) );
        strcpy(tipoAMostrar, obtenerDescTipo(tipos, largoTipos, bicicletas[i].idTipo) );

        printf("%i\t%s\t\t%s\t%s\t%f\n", bicicletas[i].id, bicicletas[i].marca, tipoAMostrar, colorAMostrar, bicicletas[i].rodado);
        i++;
    }
    system("pause");
}

int idEstaEnElListado(int idBicicleta,eBicicleta bicicletas[],int largoBicicletas)
{
    int idEncontrado = 0;
    int i =0;
    while(!idEncontrado && i < largoBicicletas)
    {
        if(idBicicleta == bicicletas[i].id)
        {
            idEncontrado = 1;
        }
    }
    return idEncontrado;
}

char* obtenerDescTipo(eTipo tipos[], int largo, int id)
{
    char* retorno;

    for(int i = 0 ; i < largo ; i++ )
    {
        if(tipos[i].id == id)
        {
            retorno = tipos[i].descripcion;
        }
    }
    return retorno;
}


