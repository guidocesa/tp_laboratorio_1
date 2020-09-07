#include <stdio.h>
#include <stdlib.h>

void menuPrincipal(int* elProgramaFianlizo);
int ingresarOperando();
int calcularSuma(int A, int B);
int calcularResta(int A, int B);
int calcularMultiplicacion(int A, int B);
float calcularDivision(int A, int B);
long int calcularFactorial(int i);
int obtenerSeleccion(int A, int B);

int main()
{
    int elProgramaFinalizo = 0;

    while(!elProgramaFinalizo)
    {
        menuPrincipal(&elProgramaFinalizo);
    }

    return 0;
}

void menuPrincipal(int* elProgramaFianlizo)
{
    int A = NULL;
    int B = NULL;
    int suma = 0;
    int resta = 0;
    float division = 0;
    int multiplicacion = 0;
    long int factorialA = 0;
    long int factorialB = 0;
    int opcionSelecionada;

    system("cls");
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
        break;

    case 4:
        informarResultado(suma, resta, division, multiplicacion, factorialA, factorialB);
        break;

    case 5:
        *elProgramaFianlizo = 1;
        printf("%li" , factorialA);
        break;

    default:
        printf("Opcion incorrecta, por favor reingrese");
        system("pause");
    }
    printf("%li" , factorialA);
}

void informarResultado(int suma, int resta, float division, int multiplicacion,long int factorialA,long int factorialB)
{
    system("cls");
    printf("El resultado de la suma es %i \n\n", suma);
    printf("El resultado de la resta es %i \n\n", resta);
    printf("El resultado de la division es %f \n\n", division);
    printf("El resultado de la multiplicacion es %i \n\n", multiplicacion);
    printf("El resultado del factorial A es: %li \n\n", factorialA);
    printf("El resultado del factorial B es: %li \n\n", factorialB);
    system("pause");
}
int ingresarOperando()
{
    system("cls");
    printf("Ingrese el operando: ");
    int ingreso = 0;
    scanf("%i" , &ingreso);
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
        return A/B;
    }
    else
    {
        return 0;
    }

}

long int calcularFactorial(int i)
{
    if(i > 0)
    {
        return (i * calcularFactorial(i -1));
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
    printf("1.Ingresar 1er operando");
    if(A == NULL)
    {
        printf(".\n");
    }
    else
    {
        printf(".  A = %i \n", A);
    }
    printf("2.Ingresar 2do operando");
    if(B == NULL)
    {
        printf(".\n");
    }
    else
    {
        printf(".  B = %i \n", B);
    }
    printf("3.Colcular todas las operaciones entre los operando.\n");
    printf("4.Informar los resultados\n");
    scanf("%i" , &seleccion);
    return seleccion;
}
