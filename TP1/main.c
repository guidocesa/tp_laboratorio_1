#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    int primerOpernadoFueIngresado = 0;
    int segundoOperandoFueIngresado = 0;
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
        opcionSelecionada = obtenerSeleccion(A, B); //A y B solo se pasan para ser mostrados.

        switch(opcionSelecionada)
        {
        case 1:
            A = ingresarOperando(&primerOpernadoFueIngresado);
            resultadosCalculados = 0; //Aca se cambia a falso luego de cambiar un operando para no mostrar resultados viejos
            break;

        case 2:
            B = ingresarOperando(&segundoOperandoFueIngresado);
            resultadosCalculados = 0;
            break;

        case 3:
            /*Aca me gustaria llamar a una sola funcion "realizarCalculos" pero deberia pasar todas
                las variables por parametro y no estaria muy correcto en mi opinion */
            if(primerOpernadoFueIngresado && segundoOperandoFueIngresado)
            {
                suma = calcularSuma(A , B);
                resta = calcularResta(A , B);
                division = calcularDivision(A , B);
                multiplicacion = calcularMultiplicacion(A , B);
                factorialA = calcularFactorial(A);
                factorialB = calcularFactorial(B);
                resultadosCalculados = 1;
            }else{
                system("cls");
                printf("Primero ingrese ambos operandos. \n\n");
                system("pause");
            }

            break;

        case 4:
            if(resultadosCalculados)
            {
                informarResultado(suma, resta, division, multiplicacion, factorialA, factorialB, A, B); //Esta funcion no me termina de gustar tampoco con tantos parametros
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


