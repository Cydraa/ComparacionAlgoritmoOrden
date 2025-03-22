#pragma once

#include <fstream>


int Aleatorizar(int inicio, int fin);
void Imprimir(int s[], int n);
void Intercambiar(int& a, int& b);
void Mezclar(int s[], int inicio, int medio, int fin);
int Particion(int s[], int inicio, int fin);
void MaxHeapify(int s[], int i, int n);
void ConstruirHeapMax(int s[], int n);
