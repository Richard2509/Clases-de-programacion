#include <stdio.h>

/* Cuenta-numeros.
El programa, al recibir como datos un arreglo unidimensional de tipo entero y un numero entero, determina cuantas veces se encuentra el numero en el arreglo. */

void main(void)                                            /*Indica que no se aceptan argumentos*/
{
    int I, NUM, CUE = 0;                                   /* Declara tres variables enteras y CUE tendrá un valor en 0, CUE significa contador */
    int ARRE[100];                                          /* Declaracion del arreglo de 100 elementos*/
    for (I=0; I<100; I++)                                   /* Reconocer que el valor de I ira incrementando */
    {
        printf("Ingrese el elemento %d del arreglo: ", I+1);  /*Mostrar un mensaje y indicar el numero del elemento */
        scanf("%d", &ARRE[I]);                               /* Leer el valor ingresado y lo guarda en I del arreglo */
    }
    printf("\n\nIngrese el numero que se va a buscar en el arreglo: "); /*Mostrar nuevamente un mensaje */
    scanf("%d", &NUM);                                        /*  Se le ingresa valor a la variable NUM */
    for (I=0; I<100; I++)                                     /* Se reconoce otra vez que el valor de I ira incrementando */
        if (ARRE[I] == NUM)                                   /*Comprovar si el elemento actual del arreglo es igual a NUM */

        CUE++;                                                /*si el elemento es igual a NUM incrementara en contador osea CUE */
    printf("\n\nEl %d se encuentra %d veces en el arreglo", NUM, CUE);  /*mostrar nuevamente un mensaje */
}
