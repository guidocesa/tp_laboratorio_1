#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "bicicleta.h"
#include "trabajo.h"
#define BICICLETASMAXIMAS 200
#define TOTALTRABAJOS 200
#define TOTALTIPOS 4
#define TOTALCOLORES 5
#define TOTALSERVICIOS 4

int main()
{
    eTrabajo trabajos[TOTALTRABAJOS];
    eTipo tipos[TOTALTIPOS];
    eColor colores[TOTALCOLORES];
    eServicio servicios[TOTALSERVICIOS];
    eBicicleta bicicletas[BICICLETASMAXIMAS];
    hardcodearDatos(tipos, TOTALTIPOS, colores, TOTALCOLORES, servicios, TOTALSERVICIOS);
    inicializarListado(bicicletas, BICICLETASMAXIMAS);
    inicializarTrabajos(trabajos, TOTALTRABAJOS);
    menuPrincipal(bicicletas, BICICLETASMAXIMAS, tipos, TOTALTIPOS, colores, TOTALCOLORES, servicios, TOTALSERVICIOS, trabajos, TOTALTRABAJOS);
}
