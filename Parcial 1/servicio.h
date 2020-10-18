#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "bicicleta.h"

typedef struct
{
    int id;
    char descripcion[26];
    float precio;
}eServicio;

void listarServicios(eServicio servicios[], int largo);

char* obtenerDescServicio(eServicio servicios[], int largoServicios, int id);

#endif // SERVICIO_H_INCLUDED
