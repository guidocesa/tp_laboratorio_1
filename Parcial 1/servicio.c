#include "servicio.h"

void listarServicios(eServicio servicios[], int largo)
{
    int i = 0;
    printf("ID\t PRECIO\t DESCRIPCION\n");
    printf("--------------------------------------------------------------------\n\n");
    while(i < largo)
    {
        printf("%i\t%f\t%s\n\n", servicios[i].id , servicios[i].precio ,servicios[i].descripcion);
        i++;
    }
}

char* obtenerDescServicio(eServicio servicios[], int largoServicios, int id)
{
    for(int i = 0; i < largoServicios; i ++)
    {
        if(id == servicios[i].id)
        {
            return servicios[i].descripcion;
        }
    }
    return 0;
}
