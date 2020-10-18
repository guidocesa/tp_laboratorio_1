#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "color.h"

typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    float rodado;
    int estaVacio;
}eBicicleta;

typedef struct
{
    int id;
    char descripcion[21];
}eTipo;

void inicializarListado(eBicicleta bicicletas[], int largo);

int obtenerIdLibre(eBicicleta bicicletas[] , int largo);

void listarTipos(eTipo tipos[], int largo);

int moverBicicletasDesde(int posicionInicial, eBicicleta bicicletas[], int largo);

int agregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, char marca[21], int idTipo, int idColor, float rodado);

void solicitarDatosYAgregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores);

void darDeBajaBicicleta(eBicicleta bicicletas[], int largo);

int borrarBicicletaPorId(eBicicleta bicicletas[], int id, int largo);

void modificarBicicleta(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores);

void listarBicicletas(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores);

int idEstaEnElListado(int idBicicleta,eBicicleta bicicletas[],int largoBicicletas);

char* obtenerDescTipo(eTipo tipos[], int largo, int id);

#endif // BICICLETA_H_INCLUDED
