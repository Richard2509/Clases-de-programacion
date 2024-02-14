#include <stdio.h>

/* Eleccion.
El programa almacena los votos emitidos en una eleccion en la que hubo cinco cantidades e imprime el total de votos que obtuvo cada uno de ellos. */

void main(void)                                   /* Indica que no se aceptan argumentos */
{
    int ELE[5] = {0};                             /*Declaracion del arreglo entero ELE de cinco elementos. Todos sus elementos se inicializan en 0.  */
    int I, VOT;                                   /* Declara 2 variables, I es un contador y VOT almacenara los votos */
    printf("Ingresa el primer voto (0 - Para terminar): "); /* se muestra un mensaje y si se ingresa 0 el los votos terminan */
    scanf("%d", &VOT);                                   /* Lee el valor ingresado y lo guarda en VOT */
    while (VOT)                                         /*Inicia un ciclo que se ejecutara siempre que VOT sea diferente de 0 */
    {
        if ((VOT > 0) && (VOT < 6))                      /* Se verifica que el voto sea correcto. */
            ELE[VOT-1]++;                                /* Los votos se almacenan en el arreglo. Recuerda que la primera posicion del arreglo es 0, por esa razon a la variable VOT se le descuenta 1.
                                                            Los votos del primer candidato se almacenan en la posicion 0. */
        else
            printf("\nEl voto ingresado es incorrecto.\n"); /* Si el voto no esta en el rango, muestra un mensaje de error */
        printf("Ingresa el siguiente voto (0 - Para terminar): "); /* Muestra un mensaje para ingresar el siguiente voto */
        scanf("%d", &VOT);                                    /* Lee el valor ingresado y lo guarda en VOT */
    }
    printf("\n\nResultados de la Eleccion\n");               /* Muestra un mensaje */
    for (I = 0; I <= 4; I++)                                 /* Inicia un ciclo que recorre el arreglo del primer elemento al ultimo */
        printf("\nCandidato %d: %d", I+1, ELE[I]);           /* Se muestra el numero de candidato incrementado en 1 porque los indices comienzan en 0 y la cantidad de votos que recibio */

}
