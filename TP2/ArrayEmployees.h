#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int estaVacio;
}eEmpleado;

void inicializarEmpleados(eEmpleado empleados[] , int largo);

int obtenerIdLibre(eEmpleado empleados[] , int largo);

int agregarEmpleadoOrdenado(eEmpleado empleados[] , int largo, char nombre[51], char apellido[51], float sueldo, int sector);

int mostrarOpcionesYObtenerSeleccion();

int confirmarSalida();

int borrarEmpleadoPorId(eEmpleado empleados[], int id, int largo);

int darDeBajaEmpleado(eEmpleado empleados[], int largo);

void formatearString(char nombre[]);

void solicitarDatosDeEmpleadoYAgregar(eEmpleado empleados[], int largo);

void mostrarInformacionSueldos(eEmpleado empleados[], int largo);

void printEmpleado(eEmpleado empleado);

void mostrarTodosLosEmpleados(eEmpleado empleados[], int largo);

void mostrarMenuInformacion(eEmpleado empleados[], int largo);

void modificarEmpleado(eEmpleado empleados[], int largo);

void menuPrincipal(eEmpleado empleados[], int largo);

int moverEmpleadosDesde(int posicionInicial , eEmpleado empleados[], int largo);

#endif // ARRAYEMPLOYEES_H_INCLUDED
