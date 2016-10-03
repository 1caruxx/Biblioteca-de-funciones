#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int loQueSea[30], loQueSea1[30];

    printf("introduzca un numero: ");
    scanf("%d", &loQueSea);



    while(validarNumero(loQueSea)==0)
    {
        printf("Error debe ingresar un numero, reingrese: ");
        scanf("%d", &loQueSea);
    }

    printf("%d", loQueSea);


    return 0;
}
