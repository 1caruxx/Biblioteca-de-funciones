//siempre recordar incluir el funciones.h en el main
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int  identificadorUnivoco, estado, parametro;
    float parametro2;
    char descripcion[30];
}EEstructura;

//-------------------------------------------Inicializacion---------------------------------------------

void inicializarVector (int[] , int);
void inicializarMatriz (int[] , int , int);

//-------------------------------------------Estilizacion-----------------------------------------------

/** \brief Pasa a minuscula todas las letras de un array de chars. La primer letra del array y cada letra despues de un espacio las pasa a mayuscula
 *
 * \ Param Un array de chars
 * \ Param Un entero
 * \ Return Un array de chars
 *
 */
void estilizarArrayDeChars (char[] , int);

//--------------------------------------------Validacion------------------------------------------------

int validarNumero (int);
int validarEdad (int);
float validarRango (float , int , int);

//--------------------------------------------Operaciones-----------------------------------------------

float calcularSuma (float , float);
float calcularResta (float , float);
float calcularMultiplicacion (float , float);
float calcularDivision (float , float);
int calcularPotencia (int , int);
int calcularFactorial (int);

//------------------------------------------------ABM---------------------------------------------------

void menu(void);

/** \brief Carga los campos de la estructura EPersona con valores que se le piden al usuario
 *
 * \ Param Un array del tipo EEstructura
 * \ Param Un entero
 * \ Return No retorna nada (void)
 *
 */
void alta (EEstructura[] , int);

/** \brief Verifica una igualdad entre un valor que ingrese el usuario y el identificador univoco de la estructura EEstructura
 * \ Param Un array del tipo EEstructura
 * \ Param Un entero
 * \ Return Retorna un entero igual o mayor que 0 si se verifico la igualda o -1 si no
 */
int buscarPorIdentificardorUnivoco (EEstructura[] , int);

/** \brief Asigna el valor 0 al campo estado de la variable de tipo EEstructura
 * \ Param Un array del tipo EEstructura
 * \ Param Un entero
 * \ Return No retorna nada (void)
 */
void baja (EEstructura[] , int);

/** \brief Modifica el valor de uno de los campos de la estructura del tipo EEstructura
 * \ Param Un array del tipo EEstructura
 * \ Param Un entero
 * \ Return No retorna nada (void)
 */
void modificacion (EEstructura[] , int);

/** \brief Modificar la posicion de los elementos del array del tipo EEstructura segun [...]
 * \ Param Un array del tipo EEstructura
 * \ Param Un entero
 * \ Return No retorna nada (void)
 */
void ordenamientoMedianteBurbujeo (EEstructura[] , int);

/** \brief Muestra en pantalla un listado de los elementos del array del tipo EEstructura
 * \ Param Un array del tipo EEstructura
 * \ Param Un entero
 * \ Return No retorna nada (void)
 */
void mostrar (EEstructura[] , int);

#endif
