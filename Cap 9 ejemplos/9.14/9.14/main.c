#include <stdio.h>
#include <ctype.h>

/* Letras minusculas y mayusculas.
El programa, al recibir como dato un archivo formado por cadenas de caracteres, determina el numero de letras minusculas y mayusculas que hay en el archivo. */

void minymay(FILE *);

void main(void)
{
    char p;
        FILE *ar;
        if ((ar = fopen("arc5.txt", "r")) != NULL)
        {
            minyway(ar);
            fclose(ar);
        }
        else
            printf("No se pudo abrir el archivo");
}

void minyway(FILE *arc)
{
    int min = 0, may = 0;
    char p;
    while (!feof(arc))
    {
        p = fgetc(arc);
        if (islower(p))
            min++;
        else
            if (isupper(p))
            may++;
    }
    printf("\nNumero de minusculas: %d", min);
    printf("\nNumero de mayusculas: %d", may);
}
