#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Funcion para calcular el costo total del viaje */
float calcular_costo_viaje(float consumo, float precio_gasolina, float kilometros_viaje, float kilometraje_anual, float costo_mantenimiento_mensual, float precio_seguro_anual, float costo_gomas)
{
    /* Calcular el costo de la gasolina */
    float litros_gasolina = (kilometros_viaje / 100) * consumo;
    float costo_gasolina = litros_gasolina * precio_gasolina;

    /* Calcular los costos anuales */
    float costo_mantenimiento_anual = costo_mantenimiento_mensual * 12;
    float costo_gomas_anual = (kilometraje_anual / 20000) * costo_gomas;
    float costo_total_anual = costo_mantenimiento_anual + precio_seguro_anual + costo_gomas_anual;

    /* Calcular el costo total del viaje */
    float costo_total_viaje = costo_gasolina + costo_total_anual * (kilometros_viaje / kilometraje_anual);

    return costo_total_viaje;
}

/* Funcion para calcular el costo por kilometro del vehiculo */
float calcular_costo_por_km(float total_gasolina_anual, float total_vehiculo_anual, float kilometraje_anual)
{
    float costo_por_km = (total_gasolina_anual + total_vehiculo_anual) / kilometraje_anual;
    return costo_por_km;
}

/* Funcion para imprimir el menu de opciones */
void imprimir_menu_opciones() {
    printf("\nOpciones:\n");
    printf("1. Modificar los kilometros del viaje\n");
    printf("2. Mostrar resultados en consola\n");
    printf("3. Guardar resultados en un archivo\n");
    printf("4. Volver al menu inicial\n");
    printf("Seleccione una opcion: ");
}

/* Funcion para imprimir el menu principal */
void imprimir_menu_principal() {
    printf("\n*** Bienvenido al Calculador de Costos de Viaje ***\n");
    printf("1. Comenzar a ingresar los datos\n");
    printf("2. Salir del programa\n");
    printf("Seleccione una opcion: ");
}

/* Funcion para verificar si hay un archivo existente */
bool verificar_archivo_existente() {
    FILE *archivo = fopen("resultados.txt", "r");
    if (archivo) {
        fclose(archivo);
        return true;
    }
    return false;
}

int main()
{
    float precio_gasolina, kilometraje_anual, precio_vehiculo;
    float kilometros_viaje = 0;
    float costo_mantenimiento_mensual, precio_seguro_anual, costo_gomas;
    float inicio_consumo, fin_consumo;
    float costo_total_viaje;
    float total_gasolina_anual, total_vehiculo_anual;
    float costo_por_km;

    char opcion_inicio, opcion_modificar; /*Variable para la opción del usuario*/
    bool archivo_existente = verificar_archivo_existente(); // Variable para controlar si hay un archivo existente
    FILE *archivo_resultados = NULL; // Puntero al archivo de resultados

    /* Menú de inicio*/
    do {
        imprimir_menu_principal();
        scanf(" %c", &opcion_inicio);

        switch (opcion_inicio) {
            case '1':
                if (archivo_existente) { // Si hay un archivo existente, preguntar al usuario qué desea hacer
                    printf("Ya hay un archivo existente.\n");
                    printf("¿Desea usar los datos del archivo o comenzar desde cero? (u/c): ");
                    char opcion_archivo;
                    scanf(" %c", &opcion_archivo);
                    if (opcion_archivo == 'u') { // Usar los datos del archivo
                        // Leer los datos del archivo
                        archivo_resultados = fopen("resultados.txt", "r");
                        if (archivo_resultados == NULL) {
                            printf("Error al abrir el archivo resultados.txt\n");
                            return 1;
                        }

                        fscanf(archivo_resultados, "%*s"); // Leer la primera línea y descartarla
                        fscanf(archivo_resultados, "%*s"); // Leer la segunda línea y descartarla

                        float consumo, costo_por_kilometro, km_por_galon, costo_viaje;
                        while (fscanf(archivo_resultados, "| %f | %f | %f | %f |\n", &consumo, &costo_por_kilometro, &km_por_galon, &costo_viaje) == 4) {
                            printf("| %.2f | %.2f | %.2f | %.2f |\n", consumo, costo_por_kilometro, km_por_galon, costo_viaje);
                        }

                        printf("\nEl costo por kilometro del vehiculo es: %.2f\n", costo_por_km);

                        fclose(archivo_resultados);

                        // Preguntar al usuario para ingresar nuevos kilómetros del viaje
                        printf("Introduce los nuevos kilometros del viaje: ");
                        scanf("%f", &kilometros_viaje);

                    } else if (opcion_archivo == 'c') { // Comenzar desde cero
                        archivo_existente = false; // Establecer que no hay archivo existente
                    } else {
                        printf("Opcion no valida. Volviendo al menu principal.\n");
                        break;
                    }
                }

                if (!archivo_existente) {
                    /*Ingresar los datos y realizar los cálculos*/
                    printf("\nIntroduce el precio del galon de gasolina: ");
                    scanf("%f", &precio_gasolina);

                    printf("Introduce el kilometraje anual del vehiculo: ");
                    scanf("%f", &kilometraje_anual);

                    printf("Introduce el precio del vehiculo: ");
                    scanf("%f", &precio_vehiculo);

                    printf("Introduce el costo del mantenimiento del vehiculo mensual: ");
                    scanf("%f", &costo_mantenimiento_mensual);

                    printf("Introduce el precio del seguro anual: ");
                    scanf("%f", &precio_seguro_anual);

                    printf("Introduce el costo de las gomas cada 20,000km: ");
                    scanf("%f", &costo_gomas);

                    printf("Introduce el consumo de combustible minimo (L/100km): ");
                    scanf("%f", &inicio_consumo);

                    printf("Introduce el consumo de combustible maximo (L/100km): ");
                    scanf("%f", &fin_consumo);
                }

                /* Menú interno */
                do {
                    printf("\nKilometros del viaje actual: %.2f\n", kilometros_viaje);
                    imprimir_menu_opciones();
                    scanf(" %c", &opcion_modificar);

                    switch (opcion_modificar) {
                        case '1':
                            printf("Introduce los nuevos kilometros del viaje: ");
                            scanf("%f", &kilometros_viaje);
                            break;
                        case '2':
                            /* Mostrar resultados en consola */
                            archivo_resultados = fopen("resultados.txt", "r");
                            if (archivo_resultados == NULL) {
                                printf("Error al abrir el archivo resultados.txt\n");
                                return 1;
                            }

                            char buffer[100];
                            while (fgets(buffer, sizeof(buffer), archivo_resultados) != NULL) {
                                printf("%s", buffer);
                            }

                            fclose(archivo_resultados);
                            break;
                        case '3':
                            /* Guardar resultados en un archivo */
                            archivo_resultados = fopen("resultados.txt", "w");
                            if (archivo_resultados == NULL) {
                                printf("Error al abrir el archivo resultados.txt\n");
                                return 1;
                            }

                            fprintf(archivo_resultados, "Tabla de Costos:\n");
                            fprintf(archivo_resultados, "----------------------------------------------------------------------------\n");
                            fprintf(archivo_resultados, "| Consumo (L/100km) | Costo por Kilometro | Km por Galon | Costo Viaje |\n");
                            fprintf(archivo_resultados, "----------------------------------------------------------------------------\n");

                            /* Calculamos y mostramos resultados para cada consumo de combustible dentro del rango dado por el usuario */
                            for (float consumo = inicio_consumo; consumo <= fin_consumo; consumo++)
                            {
                                /* Calcular el costo total del viaje */
                                costo_total_viaje = calcular_costo_viaje(consumo, precio_gasolina, kilometros_viaje, kilometraje_anual,
                                                                        costo_mantenimiento_mensual, precio_seguro_anual, costo_gomas);

                                /* Calcular el costo por kilometro */
                                float costo_por_kilometro = costo_total_viaje / kilometros_viaje;

                                /* Calcular los kilometros por galon */
                                float km_por_galon = 100 / consumo;

                                /* Imprimir los resultados calculados en el archivo */
                                fprintf(archivo_resultados, "| %.2f               | %.2f          | %.2f          | %.2f         |\n",
                                        consumo, costo_por_kilometro, km_por_galon, costo_total_viaje);

                                /* Calculo el costo por kilometro del vehiculo */
                                total_gasolina_anual = (kilometraje_anual / 20) * precio_gasolina;
                                total_vehiculo_anual = (costo_mantenimiento_mensual * 12) + precio_seguro_anual + costo_gomas;
                                costo_por_km = calcular_costo_por_km(total_gasolina_anual, total_vehiculo_anual, kilometraje_anual);
                            }

                            /* Imprimir el costo por kilometro en el archivo*/
                            fprintf(archivo_resultados, "---------------------------------------------------------------------------------------------\n");
                            fprintf(archivo_resultados, "\nEl costo por kilometro del vehiculo es: %.2f\n", costo_por_km);

                            /*Cerrar archivo */
                            fclose(archivo_resultados);

                            printf("Los resultados se han guardado en el archivo resultados.txt\n");
                            archivo_existente = true; // Establecer que hay un archivo existente
                            break;
                        case '4':
                            printf("Volviendo al menu principal...\n");
                            break;
                        default:
                            printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
                            break;
                    }
                } while (opcion_modificar != '4');
                break;

            case '2':
                printf("Saliendo del programa...\n");
                exit(0); /* Salir del programa */
                break;

            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
        }

    } while (1);

    return 0;
}
