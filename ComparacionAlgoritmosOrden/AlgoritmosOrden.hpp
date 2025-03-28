#pragma once

/**
* \file
*/

/** ALGORITMOS DE ORDENAMIENTO */
enum algoritmos 
{ INSERCION, /**< Algoritmo de Ordenamiento por Inserci&oacute;n. */
BURBUJA, /**< Algoritmo de Ordenamiento por Burbuja. */
BURBUJA_OPTIMIZADO, /**< Algoritmo de Ordenamiento por Burbuja Optimizado. */
SELECCION, /**< Algoritmo de Ordenamiento por Selecci&oacute;n. */
SHELL, /**< Algoritmo de Ordenamiento por Inserci&oacute;n con intervalos decrecientes (Shell Sort) */
HEAP, /**< Algoritmo de Ordenamiento por Mont%iacute;culos (Heap Sort) */
RAPIDO, /**< Algoritmo de Ordenamiento R&aacute;pido (Quick Sort) */
MEZCLA /**< Algoritmo de Ordenamiento Mezcla (Merge Sort) */
}; 

/**
* \brief Algoritmo de Ordenamiento por Inserci&oacute;n.
*
* \param s[] Arreglo de enteros.
* \param inicio &Iacute;ndice del arreglo inicial.
* \param n Dimensi&oacute;n del arreglo.
* \return Nada.
*/
void OrdenamientoPorInsercion(int s[], int inicio, int n);

/**
* \brief Algoritmo de Ordenamiento por Burbuja.
*
* \param s[] Arreglo de enteros.
* \param inicio &Iacute;ndice del arreglo inicial.
* \param n Dimensi&oacute;n del arreglo.
* \return Nada.
*/
void OrdenamientoBurbuja(int s[], int inicio, int n);

/**
* \brief Algoritmo de Ordenamiento por Burbuja Optimizado.
*
* \param s[] Arreglo de enteros.
* \param inicio &Iacute;ndice del arreglo inicial.
* \param n Dimensi&oacute;n del arreglo.
* \return Nada.
*/
void OrdenamientoBurbujaOptimizado(int s[], int inicio, int n);

/**
* \brief Algoritmo de Ordenamiento por Selecci&oacute;n.
*
* \param s[] Arreglo de enteros.
* \param inicio &Iacute;ndice del arreglo inicial.
* \param n Dimensi&oacute;n del arreglo.
* \return Nada.
*/
void OrdenamientoSeleccion(int s[], int inicio, int n);

/**
* \brief Algoritmo de Ordenamiento por Inserci&oacute;n con intervalos decrecientes (Shell Sort)
*
* \param s[] Arreglo de enteros.
* \param inicio &Iacute;ndice del arreglo inicial.
* \param n Dimensi&oacute;n del arreglo.
* \return Nada.
*/
void OrdenamientoShell(int s[], int inicio, int n);

/**
* \brief Algoritmo de Ordenamiento Heap (O mont&iacute;culo)
*
* \param s[] Arreglo de enteros.
* \param inicio &Iacute;ndice del arreglo inicial.
* \param n Dimensi&oacute;n del arreglo.
* \return Nada.
*/
void OrdenamientoHeap(int s[], int inicio, int n);

/**
* \brief Algoritmo de Ordenamiento R&aacute;pido (Quick Sort)
*
* \param s[] Arreglo de enteros.
* \param inicio &Iacute;ndice del arreglo inicial.
* \param fin &Iacute;ndice del arreglo final. Es el tamaño del arreglo-1.
* \param n Dimensi&oacute;n del arreglo.
* \return Nada.
*/
void OrdenamientoRapido(int s[], int inicio, int fin);

/**
* \brief Algoritmo de Ordenamiento Mezcla (Merge Sort)
*
* \param s[] Arreglo de enteros.
* \param inicio &Iacute;ndice del arreglo inicial.
* \param fin &Iacute;ndice del arreglo final. Es el tamaño del arreglo-1.
* \param n Dimensi&oacute;n del arreglo.
* \return Nada.
*/
void OrdenamientoMezcla(int s[], int inicio, int fin);