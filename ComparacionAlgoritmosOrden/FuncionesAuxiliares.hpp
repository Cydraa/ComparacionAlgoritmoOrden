#pragma once

/**
* \file
*/

#include <fstream>

/**
* \brief Aleatoriza valores dentro de un rango dado.
*
* \param inicio Inicio del rango.
* \param fin Fin del rango.
* \return Un n&uacute;mero al azar dentro del rango especificado.
*/
int Aleatorizar(int inicio, int fin);

/**
* \brief Imprime un arreglo de enteros.
*
* \param s[] Arreglo de enteros.
* \param n Dimensi&oacute;n del arreglo.
* \return Nada.
*/
void Imprimir(int s[], int n);

/**
* \brief Intercambia los valores a y b.
*
* \param a Valor del n&uacute;mero a.
* \param b Valor del n&uacute;mero b.
* \return Nada.
*/
void Intercambiar(int& a, int& b);

/**
* \brief Componente del algoritmo de ordenamiento por mezcla. Ordena y mezcla los arreglos izquierdo y derecho.
*
* \param s[] Arreglo de enteros.
* \param inicio &Iacute;ndice del arreglo inicial.
* \param medio &Iacute;ndice entre el &iacute;ndice inicial y el final.
* \param fin &Iacute;ndice del arreglo final. Es el tama&ntilde;o del arreglo-1.
* \param n Tama&ntilde;o del arreglo.
* \return Nada.
*/
void Mezclar(int s[], int inicio, int medio, int fin);

/**
* \brief Componente del algoritmo de ordenamiento r&aacute;pido (Quick Sort). Reparte el arreglo en dos particiones.
*
* \param s[] Arreglo de enteros.
* \param inicio &Iacute;ndice del arreglo inicial.
* \param fin &Iacute;ndice del arreglo final. Es el tama&ntilde;o del arreglo-1.
* \param n Tama&ntilde;o del arreglo.
* \return &Iacute;ndice del pivote.
*/
int Particion(int s[], int inicio, int fin);

/**
* \brief Componente del algoritmo de ordenamiento por mont&iacute;culos (Heap Sort). Ajusta la propiedad de mont&iacute;culo.
*
* \param s[] Arreglo de enteros.
* \param i &Iacute;ndice del arreglo inicial.
* \param n Tama&ntilde;o del arreglo.
* \return Nada.
*/
void MaxHeapify(int s[], int i, int n);

/**
* \brief Componente del algoritmo de ordenamiento por mont&iacute;culos (Heap Sort). Crea un heap o mont&iacute;culo o heap m&aacute;ximo.
*
* \param s[] Arreglo de enteros.
* \param i &Iacute;ndice del arreglo inicial.
* \param n Tama&ntilde;o del arreglo.
* \return Nada.
*/
void ConstruirHeapMax(int s[], int n);
