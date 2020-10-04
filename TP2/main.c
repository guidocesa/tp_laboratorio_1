#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define EMPLEADOSMAXIMOS 1000

int main()
{
    eEmpleado empleados[EMPLEADOSMAXIMOS];
    inicializarEmpleados(empleados, EMPLEADOSMAXIMOS);
    menuPrincipal(empleados, EMPLEADOSMAXIMOS);
    return 0;
}
