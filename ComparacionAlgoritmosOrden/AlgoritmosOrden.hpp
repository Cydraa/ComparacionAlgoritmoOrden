#pragma once

enum algoritmos { INSERCION, BURBUJA, BURBUJA_OPTIMIZADO, SELECCION, SHELL, HEAP, RAPIDO, MEZCLA };

void OrdenamientoPorInsercion(int s[], int inicio, int n);
void OrdenamientoBurbuja(int s[], int inicio, int n);
void OrdenamientoBurbujaOptimizado(int s[], int inicio, int n);
void OrdenamientoSeleccion(int s[], int inicio, int n);
void OrdenamientoShell(int s[], int inicio, int n);
void OrdenamientoHeap(int s[], int inicio, int n);
void OrdenamientoRapido(int s[], int inicio, int fin);
void OrdenamientoMezcla(int s[], int inicio, int fin);