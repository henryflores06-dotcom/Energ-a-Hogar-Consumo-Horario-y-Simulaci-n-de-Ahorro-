#ifndef ENERGIA_H
#define ENERGIA_H

#define HORAS 24

// Prototipos de funciones
void capturarConsumo(float consumo[]);
float totalYpico(float consumo[], int *horaPico);
void simularReduccion(float consumo[], float simulado[], float reduccionNoche, float reduccionTarde);
void reporte(float consumo[], float precio);

#endif

