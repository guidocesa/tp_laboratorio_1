#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[21];
}eColor;

void listarColores(eColor colores[], int largo);

char* obtenerNombreColor(eColor colores[], int largo, int id);

#endif // COLOR_H_INCLUDED
