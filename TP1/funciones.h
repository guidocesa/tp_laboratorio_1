#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED


/** \brief Escribe los resultados de todas las operaciones
 *
 * \param suma int resultado de la suma
 * \param resta int resultado de la resta
 * \param division float resultado de la division
 * \param multiplicacion int resultado de la multiplicacion
 * \param factorialA long int resultado del primer factorial
 * \param factorialB long int resultado del segundo factorial
 * \param B valor del divisor para saber si se pudo realizar la division
 * \return void
 *
 */
void informarResultado(int suma, int resta, float division, int multiplicacion,long int factorialA,long int factorialB, int A, int B);

/** \brief Obtiene un numero por consola y lo devuelve
 *
 * \return int
 *
 */
int ingresarOperando();

/** \brief Calcula la suma entre dos numeros recibidos por parametros
 *
 * \param A int primer numero a seumar
 * \param B int segundo numero a sumar
 * \return int resultado
 *
 */
int calcularSuma(int A, int B);

/** \brief Calcula la resta entre dos numeros recibidos por parametros
 *
 * \param A int numero a ser restado
 * \param B int numero a restar
 * \return int resultado
 *
 */
int calcularResta(int A, int B);

/** \brief Devuelve el producto entre dos numeros recibidos por parametro
 *
 * \param A int primer numero
 * \param B int segundo numero
 * \return int resultado
 *
 */
int calcularMultiplicacion(int A, int B);

/** \brief Devuelve la division entre dos numeros recibidos por parametros
 *
 * \param A int Dividendo
 * \param B int Divisor
 * \return int Resultado
 *
 */
float calcularDivision(int A, int B);

/** \brief Calcula el factorial de forma recurrente hasta llegar a 0 caso en el que devuelve 1
 *
 * \param i int numero a calcular el factorial
 * \return int resultado
 *
 */
int calcularFactorial(int i);

/** \brief Obtiene por consola una seleccion luego de haber mostrado las opciones por printf
 *
 * \param A int Numero ya seleccionado que es mostrado en el menu de opciones pero no manipulado.
 * \param B int Numero ya seleccionado que es mostrado en el menu de opciones pero no manipulado.
 * \return int opcion seleccionada
 *
 */
int obtenerSeleccion(int A, int B);


