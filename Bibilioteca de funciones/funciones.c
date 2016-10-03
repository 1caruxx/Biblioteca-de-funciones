#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define LONGITUD 10

//-------------------------------------------Inicializacion---------------------------------------------

void inicializarVector (int vector[] , int longitud)
{
    int i;

    for (i=0 ; i<longitud ; i++)
    {
       vector[i] = 0;
    }
}

/*void inicializarMatriz (int matriz[] , int fila, int columna)
{
    int i, j;

    for(i=0 ; i<fila ; i++)
    {
        for(j=0 ; j<columna ; j++)
        {
            matriz[i][j] = 0;
        }
    }
}*/

//-------------------------------------------Estilizacion-----------------------------------------------

void estilizarArrayDeChars(char array[] , int longitud)
{
    int i;

    strlwr(array);
    array[0] = toupper(array[0]);
    for(i=0 ; i<longitud ; i++)
    {
        if(array[i] == ' ')
        {
            array[i+1] = toupper(array[i+1]);
        }
    }
}

//--------------------------------------------Validacion------------------------------------------------

int validarNumero (int numero)
{
    int i, longitud;
    char vector[20];

    sprintf(&vector,"d",numero);

    longitud = strlen(vector);
    printf("%d", longitud);

    for(i=0 ; i<longitud ; i++)
    {
       printf("[%d/%d]\n",i,longitud);
        if(isdigit(vector[i]) == 0)
        {
            numero = atoi(vector);
            return 0;
        }

    }

    return 1;

}

int validarEdad (int edad)
{
    while (edad<0 || edad>120)
    {
        printf("Error, edad no valida. Reingrese: ");
        scanf("%d", &edad);
    }
  return edad;
}


float validarRango (float numero , int minimo , int maximo)
{
    while (numero<minimo || numero>maximo)
    {
         printf("Error, el valor no cumple con el rango propuesto. Reingrese: ");
         scanf("%f", &numero);
    }

  return numero;

}

//--------------------------------------------Operaciones-----------------------------------------------

float calcularSuma (float numero1 , float numero2)
{
    float suma;
    suma = numero1+numero2;
    return suma;
}

float calcularResta (float numero1 , float numero2)
{
    float resta;
    resta = numero1-numero2;
    return resta;
}

float calcularDivision (float numero1 , float numero2)
{
    float division;
        if(numero2==0)
     {
        division = printf("Error\n");
        return division;
     }
     division = numero1/numero2;
     return division;
}

float calcularMultiplicacion (float numero1 , float numero2)
{
    float multiplicacion;
    multiplicacion = numero1*numero2;
    return multiplicacion;
}

int calcularPotencia (int numero1 , int numero2)
{
    int potencia = numero1, cont = 1;

    while (cont < numero2)
     {
        potencia = potencia*numero1;
        cont++;
     }

    return potencia;
}

int calcularFactorial (int numero)
{
    int i,factorial = numero, resultado = numero;

    if (numero == 0)
    {
        return 1;
    }

    for(i=0 ; i<numero-1 ; i++)
    {
        resultado = resultado*(factorial-1);
        factorial--;
    }

  return resultado;

}

//------------------------------------------------ABM---------------------------------------------------

void menu(void)
{
    char seguir='s';
    int opcion;

    do
    {
        printf("1- \n");
        printf("2- \n");
        printf("3- \n");
        printf("4- \n");
        printf("5- \n");
        printf("6- Salir\n\n");
        printf("Elija una de las opciones: ");

        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
              break;

            case 2:
              break;

            case 3:
              break;

            case 4:
              break;

            case 5:
              break;

            case 6:
              seguir = 'n';
              break;

            default:
                printf("Error, reingrese.\n");
        }

        system("pause");
        system("cls");

    } while(seguir=='s');

}

void alta(EEstructura dato[] , int longitud)
{
   int i, contador=0;

   for (i=0 ; i<longitud ; i++)
   {
      if (dato[i].estado != 1)
      {
          printf("Ingrese la descripcion: ");
          fflush(stdin);
          gets(dato[i].descripcion);
          estilizarArrayDeChars(dato[i].descripcion , longitud);

          printf("Ingrese un parametro: ");
          scanf("%d", &dato[i].parametro);

          printf("Ingrese el identificador univoco: ");
          scanf("%d", &dato[i].identificadorUnivoco);
          dato[i].estado = 1;
          break;
      }

      else
      {
          contador++;
      }
   }
   if(contador == longitud)
   {
      printf("No hay espacio disponible en el vector.\n");
   }
}

int buscarPorIdentificardorUnivoco (EEstructura dato[], int longitud)
{
    int i, auxiliar, flag=0;

    printf("Ingrese el identificardor univoco de lo que quiere buscar: ");
    scanf("%d", &auxiliar);

    for (i=0 ; i<longitud ; i++)
    {
        if(dato[i].estado==1 && auxiliar==dato[i].identificadorUnivoco)
        {
            return i;
        }
    }

    if(flag == 0)
    {
        printf("El identificador univoco es inexistente\n");
        return -1;
    }
}

void baja(EEstructura dato[] , int longitud)
{
    char opcion;
    int posicion;
    posicion = buscarPorIdentificardorUnivoco (dato, longitud);

    if(posicion == -1)
    {
        return;
    }

    printf("DNI\t\tNombre\t\t\tEdad\n");
    printf("%d\t%s\t\t%d\n", dato[posicion].identificadorUnivoco, dato[posicion].descripcion, dato[posicion].parametro);

    printf("%cDesea dar de baja a esta unidad? [s/n]: ", 168);
    fflush(stdin);
    scanf("%c", &opcion);

    switch (opcion)
    {
       case 's':
       dato[posicion].estado = 0;
       printf("Se ha dado de baja la unidad\n");
       break;

       case 'n':
       printf("Operacion abortada\n");
       break;

       default:
       printf("Error, valor ingresado no valido\n");
    }
}

void modificacion(EEstructura dato[] , int longitud)
{
    int posicion, opcion;

    posicion = buscarPorIdentificardorUnivoco (dato, longitud);

    if(posicion == -1)
    {
        return;
    }

    printf("Identificador univoco\t\tDescripcion\t\t\tParametro\n");
    printf("%d\t%s\t\t%d\n", dato[posicion].identificadorUnivoco, dato[posicion].descripcion, dato[posicion].parametro);

    printf("%cQue parametro desea modificar?\n",168);
    printf("1- Descripcion\n");
    printf("2- Parametro\n");
    printf("3- Cancelar\n");
    printf("Seleccione una de las opciones: ");

    fflush(stdin);
    scanf("%d", &opcion);

    switch (opcion)
    {
       case 1:
         printf("Ingrese la nueva descripcion: ");
         fflush(stdin);
         gets(dato[posicion].descripcion);
         estilizarArrayDeChars(dato[posicion].descripcion , 26);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 2:
         printf("Ingrese el nuevo parametro: ");
         scanf("%d", &dato[posicion].parametro);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 3:
         printf("Operacion abortada\n");
         break;

       default:
         printf("Opcion ingresada no valida\n");
    }
}

void ordenamientoMedianteBurbujeo(EEstructura dato[] , int longitud)
{
    int i, j;
    EEstructura auxiliar;

    for(i=0 ; i<longitud-1 ; i++)
    {
        for(j=i+1 ; j<longitud ; j++)
        {
            if(strcmp(dato[i].descripcion , dato[j].descripcion)>0)//mayor a menor
            {
                auxiliar = dato[i];
                dato[i] = dato[j];
                dato[j] = auxiliar;
            }
        }
    }
}

void mostrar(EEstructura dato[] , int longitud)
{
    int i,contador=0;

    printf("Identificador univoco\t\tDescripcion\t\t\tParametro\n");

    for(i=0 ; i<longitud ; i++)
    {
      if(dato[i].estado == 1)
      {
        printf("%d%d\t%s\t\t%d\n", dato[i].identificadorUnivoco, dato[i].descripcion, dato[i].parametro);
      }
      else
      {
          contador++;
      }
    }

    if(contador == longitud)
    {
        printf("No se ha cargado ningun dato.\n");
    }
}


