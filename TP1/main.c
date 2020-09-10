#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    int elProgramaFinalizo = 0;
    int resultadosCalculados = 0;
    int A = 0;
    int B = 0;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    long int factorialA;
    long int factorialB;
    int opcionSelecionada;

    while(!elProgramaFinalizo)
    {

        system("cls");
        fflush(stdin);
        opcionSelecionada = obtenerSeleccion(A, B);

        switch(opcionSelecionada)
        {
        case 1:
            A = ingresarOperando();
            break;

        case 2:
            B = ingresarOperando();
            break;

        case 3:
            suma = calcularSuma(A , B);
            resta = calcularResta(A , B);
            division = calcularDivision(A , B);
            multiplicacion = calcularMultiplicacion(A , B);
            factorialA = calcularFactorial(A);
            factorialB = calcularFactorial(B);
            resultadosCalculados = 1;
            break;

        case 4:
            if(resultadosCalculados)
            {
                informarResultado(suma, resta, division, multiplicacion, factorialA, factorialB, B);
            }
            else
            {
                system("cls");
                printf("Primero debe calcular los resultados.\n\n");
                system("pause");
            }
            break;

        case 5:
            elProgramaFinalizo = 1;
            break;

        default:
            system("cls");
            printf("Opcion incorrecta, por favor reingrese\n\n");
            system("pause");
        }
    }

    return 0;
}


