#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"


void informarResultado(int suma, int resta, float division, int multiplicacion,long int factorialA,long int factorialB, int A, int B)
{
    system("cls");
    printf("El resultado de la suma es %i \n\n", suma);
    printf("El resultado de la resta es %i \n\n", resta);
    if(B != 0.0)
    {
        printf("El resultado de la division es %f \n\n", division);
    }
    else
    {
        printf("No se pudo realizar la division porque el divisior es 0 \n\n");
    }
    printf("El resultado de la multiplicacion es %i \n\n", multiplicacion);
    if(A < 0)
    {
        printf("El faltorial de A no puede ser calculado. \n\n");
    }else{
        printf("El resultado del factorial A es: %li \n\n", factorialA);
    }
    if(B < 0)
    {
        printf("El faltorial de B no puede ser calculado. \n\n");
    }else{
        printf("El resultado del factorial B es: %li \n\n", factorialB);
    }
    system("pause");
}

int ingresarOperando(int* fueIngresado)
{
    int ingreso = 0;
    system("cls");
    printf("Ingrese el operando: ");
    scanf("%i" , &ingreso);
    *fueIngresado = 1;
    return ingreso;
}

int calcularSuma(int A, int B)
{
    return A + B;
}

int calcularResta(int A, int B)
{
    return A - B;
}

int calcularMultiplicacion(int A, int B)
{
    return A*B;
}

float calcularDivision(int A, int B)
{
    if(B != 0)
    {
        return (float)A/B;
    }
    else
    {
        return 0;
    }

}

int calcularFactorial(int i)
{
    if(i > 0)
    {
        return (i * calcularFactorial(i - 1));
    }
    else
    {
        return 1;
    }
}

int obtenerSeleccion(int A, int B)
{
    int seleccion = 0;
    printf("Por favor elija una opcion y lugo precione enter.\n\n");
    printf("1.Ingresar 1er operando.  A = %i \n", A);
    printf("2.Ingresar 2do operando.  B = %i \n", B);
    printf("3.Colcular todas las operaciones entre los operando.\n");
    printf("4.Informar los resultados\n");
    printf("5.Salir\n");
    scanf("%i" , &seleccion);
    return seleccion;
}
