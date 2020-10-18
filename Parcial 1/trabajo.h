#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bicicleta.h"
#include "servicio.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int estaVacio;
}eTrabajo;

void altaTrabajo(eTrabajo trabajos[], int largoTrabajos, eBicicleta bicicletas[], int largoBicicletas,eServicio servicios[],int largoServicios, int trabajosRealizados);

void inicializarTrabajos(eTrabajo trabajos[], int largo);

void agregarTrabajo(eTrabajo trabajos[],int idBicicleta,int  idServicio,int  dia,int  mes,int  anio, int trabajosRealizados);

void listarTrabajos(eTrabajo trabajos[], int largoTrabajos, eServicio servicios[], int largoServicios, int trabajosRealizados );

#endif // TRABAJO_H_INCLUDED
