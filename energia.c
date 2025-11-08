#include <stdio.h>
#include "energia.h"

void capturarConsumo(float consumo[]) {
    int i;
    for (i = 0; i < HORAS; i++) {
        do {
            printf("Ingrese el consumo (kWh) de la hora %02d: ", i);
            scanf("%f", &consumo[i]);
            if (consumo[i] < 0)
                printf("Error: el valor no puede ser negativo.\n");
        } while (consumo[i] < 0);
    }
}

float totalYpico(float consumo[], int *horaPico) {
    float total = 0;
    float max = consumo[0];
    *horaPico = 0;
    int i;
    for (i = 0; i < HORAS; i++) {
        total += consumo[i];
        if (consumo[i] > max) {
            max = consumo[i];
            *horaPico = i;
        }
    }
    return total;
}

void simularReduccion(float consumo[], float simulado[], float reduccionNoche, float reduccionTarde) {
    int i;
    for (i = 0; i < HORAS; i++) {
        if (i >= 0 && i <= 6)
            simulado[i] = consumo[i] * (1 - reduccionNoche / 100);
        else if (i >= 18 && i <= 23)
            simulado[i] = consumo[i] * (1 - reduccionTarde / 100);
        else
            simulado[i] = consumo[i];
    }
}

void reporte(float consumo[], float precio) {
    float total = 0;
    printf("\nHora\tConsumo(kWh)\tCosto($)\n");
    int i;
    for (i = 0; i < HORAS; i++) {
        printf("%02d\t%.2f\t\t%.2f\n", i, consumo[i], consumo[i] * precio);
        total += consumo[i] * precio;
    }
    printf("Costo total diario: $%.2f\n", total);
}

