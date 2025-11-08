#include <stdio.h>
#include "energia.h"

int main() {
    float consumo[HORAS], simulado[HORAS];
    float precio = 0, reduccionNoche = 0, reduccionTarde = 0;
    int opcion, horaPico;

    do {
        printf("\n--- MENU ---\n");
        printf("1) Capturar consumo\n");
        printf("2) Reporte base\n");
        printf("3) Simular ahorro\n");
        printf("4) Comparativo base vs simulado\n");
        printf("5) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el precio por kWh: ");
                scanf("%f", &precio);
                capturarConsumo(consumo);
                break;

            case 2:
                reporte(consumo, precio);
                totalYpico(consumo, &horaPico);
                printf("Hora pico: %02d:00\n", horaPico);
                break;

            case 3:
                printf("Reduccion %% 00–06h: ");
                scanf("%f", &reduccionNoche);
                printf("Reduccion %% 18–23h: ");
                scanf("%f", &reduccionTarde);
                simularReduccion(consumo, simulado, reduccionNoche, reduccionTarde);
                printf("Simulacion completada.\n");
                break;

            case 4:
                printf("\nComparativo Base vs Simulado:\n");
                printf("Hora\tBase(kWh)\tSimulado(kWh)\n");
                int i= 0;
                for (i=0; i < HORAS; i++)
                    printf("%02d\t%.2f\t\t%.2f\n", i, consumo[i], simulado[i]);
                break;
        }
    } while (opcion != 5);

    return 0;
}

