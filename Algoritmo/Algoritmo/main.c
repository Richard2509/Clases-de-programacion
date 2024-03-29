/*
  ANSI C program generated by devFlowcharter (https://github.com/albireo77/devflowcharter)
  for BubbleSort_C project
*/

#include <time.h>

#define ARRAY_SIZE 100             /* Se establece una constante llamada ARRAY_SIZE con un valor de 100 para determinar el tama�o del arreglo */

int i;                             /* Declara una variable entera (i), que se utilizara como contador en ciclos */
int change;                        /* Declara una variable entera que se utilizara para ver si se han realizado cambios en el arreglo mientras se ordena */
int n;                             /* Declara una variable entera que almacenara el tama�o del arreglo a */
int a[ARRAY_SIZE];                 /* Declara un arreglo de enteros (a) con un tama�o especificado por ARRAY_SIZE*/
int buf;                           /* Declara una variable entera que se utilizara para intercambiar valores mientras se ordena */
time_t seed;                       /* Declara una variable de tipo time_t llamada seed, que se utilizara como semilla para producir numeros aleatorios */

int main(int argc, char* argv[])   /* La funcion principal del programa se define aqui, aunque en este caso no se utilizan, esta funcion acepta argumentos de linea de comandos */
{
    seed = 0;                      /* Inicia la semilla con valor 0 */
  srand(time(&seed));              /* Se comienzan a generar numeros aleatorios con una semilla de tiempo actual */
  n = sizeof(a) / sizeof(*a);      /* El tama�o del arreglo (sizeof(a)) se divide por el tama�o de un elemento del arreglo (sizeof(*a)) lo que da como resultado el numero total de elementos en el arreglo*/

  for (i = 0; i <= n-1; i++)       /* Inicia un ciclo que recorre el arreglo a y asigna valores aleatorios a cada elemento del arreglo */
  {
    a[i] = rand() % 1000;          /* Se asigna un numero aleatorio entre 0 y 999 a cada elemento del arreglo */
  }
   for (i = 0; i <= n-1; i++)      /* Este ciclo imprime cada elemento del arreglo */
   {
      printf("Element a[%d]: %d\n", i, a[i]); /* Muestra cada elemento del arreglo a junto con su �ndice en pantalla.*/
   }

   change = 1;                     /* Se controla el ciclo de ordenamiento y asegura de que se realicen suficientes interaciones para ordenar completamente el arreglo */
   while(change == 1)              /* Este bucle se encarga de repetir el proceso de ordenamiento hasta que ya no sea necesario realizar mas intercambios de elementos en el arreglo */
   {
         change = 0;               /* indica que no ha habido intercambios durante la iteraci�n actual del proceso de ordenamiento */
    for (i = 0; i <= n-2; i++)     /* Se establece un bucle que se ejecutara n-1 veces, comenzando desde i = 0 hasta i = n-2 */
    {
      if (a[i] > a[i+1])           /* Evalua si cada elemento del arreglo y su siguiente elemento est�n en orden ascendente */
      {
        buf = a[i];                /* Guarda temporalmente el valor del elemento actual a[i] en una variable temporal */
        a[i] = a[i+1];             /* Se asigna el valor del elemento siguiente a[i+1] al elemento actual a[i] */
        a[i+1] = buf;              /* Se asigna el valor guardado en la variable temporal (buf) al elemento siguiente a[i+1] para completar el intercambio de valores entre los dos elementos consecutivos en el arreglo */
        change = 1;                /* Aqui se indica que se realizo al menos un intercambio en esta interacion del bucle, lo que significa que el arreglo aun no esta completamente ordenado y se debe continuar el proceso de ordenamiento*/
      }
    }
   }
   printf("\n----------------------------\n");   /* Se imprime una linea */
   for (i = 0; i <= n-1; i++)                     /* Establece un bucle que se ejecutara n veces comenzando desde i = 0 hasta i = n-1 */
  {
    printf("Element a[%d]: %d\n", i, a[i]);       /* Mostrara el valor de un elemento del arreglo junto con su indice */
  }
  return 0;                                       /* Indica que la funcion ha finalizado correctamente y devuelve un valor de salida igual a 0v*/
}
