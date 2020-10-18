#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "bicicleta.h"
#include "trabajo.h"
#include "color.h"
#include "servicio.h"

int confirmarSalida();

int mostrarOpcionesYObtenerSeleccion();

void formatearString(char marca[]);

int menuPrincipal(eBicicleta bicicletas[], int largoBicicletas, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eServicio servicios[], int largoServicios , eTrabajo trabajos[], int largoTrabajos);

void hardcodearDatos(eTipo tipos[], int largoTipos, eColor colores[], int  largoColores,eServicio servicios[], int largoServicios);

#endif // FUNCIONES_H_INCLUDED
