#include <stdio.h>

#define TAM_MATRIZ 5         /* Aqui defino el valor de mi matriz*/

int main(void)              /*Defino la funcion principal que no recibo argumentos sino enteros*/
{
    int matriz[TAM_MATRIZ][TAM_MATRIZ];      /*Declaro mi matriz 5x5*/
    int I, J;                       /* Declaro mis variables enteras que usare en los (for)*/

    int suma_diagonal_principal = 0;   /* donde alamcenare las sumas de las diagonales que comienza en 0*/
    int suma_diagonal_secundaria = 0;

    printf("\nIngresa los valores de la matriz %dx%d: \n", TAM_MATRIZ, TAM_MATRIZ);
    for (I = 0; I < TAM_MATRIZ; I++)  /* Inicio un bucle para I comenzando en 0 e indico que azance segun valla entrando los datos en la fila*/
    {
        for (J = 0; J < TAM_MATRIZ; J++)   /* Inicio un bucle para J comenzando en 0 e indico que avance segun vallan entrando los datos en la columna*/
        {
            printf("Valor en [%d][%d]: ", I, J);    /* Pido que inserten los datos la posicion dada en este caso fila y columnas*/
            scanf("%d", &matriz[I][J]);           /* Almacena los datos de la matriz */
            if (I == J)                        /* Verifico que el numero de filas sea igual al de columnas y me posiciono en la diagonal principal*/
            {
                suma_diagonal_principal += matriz[I][J];   /* Se suma la diagonal principal */
            }
            if (I + J == TAM_MATRIZ - 1)                /* Verifico que el numero de filas sea igual al de columnas menos 1 posicionandome en la diagonal secundaria*/
            {
                suma_diagonal_secundaria += matriz[I][J];   /* Se suma la diagonal secundaria*/
            }
        }
    }
        printf("Matriz %dx%d ingresada:\n", TAM_MATRIZ, TAM_MATRIZ);    /* Se imprime la matriz*/
        for (I = 0; I < TAM_MATRIZ; I++)              /* Inicio un bucle para recorrer las filas comenzando desde 0*/
        {
            for (J = 0; J < TAM_MATRIZ; J++)            /* Inicio un bucle para recorrer las columnas comenzando desde 0*/
            {
                printf("%d\t", matriz[I][J]);          /* \t lo utilizo para que mi matriz se imprima con mas espacio es decir bien separada*/
            }
            printf("\n");
        }
        printf("\nSuma de la diagonal principal: %d\n", suma_diagonal_principal);         /*Se imprime las sumas*/
        printf("\nSuma de la diagonal secundaria: %d\n", suma_diagonal_principal);
        printf("\nGracias por tu tiempo\n");

        return 0;
}
