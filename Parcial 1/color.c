#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"

void listarColores(eColor colores[], int largo)
{
    int i = 0;
    printf("ID\t COLOR\n");
    printf("--------------------------------------------------------------------\n\n");
    while(i < largo)
    {
        printf("%i\t%s\n\n", colores[i].id , colores[i].nombreColor);
        i++;
    }
}

char* obtenerNombreColor(eColor colores[], int largo, int id)
{
    char* retorno;

    for(int i = 0 ; i < largo ; i++ )
    {
        if(colores[i].id == id)
        {
            retorno = colores[i].nombreColor;
        }
    }
    return retorno;
}
