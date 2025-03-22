#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <vector>

#include "FuncionesAuxiliares.hpp"
#include "AlgoritmosOrden.hpp"

using namespace std;
using namespace std::chrono;

using fn = void(int[], int, int);

#define MIN_TAMANO 10
#define MAX_TAMANO 1000 // Columnas
#define NUM_PRUEBAS 1000 // Filas
#define INCREMENTO 10
#define NUM_ALGORITMOS 8


int main()
{
    srand(time(NULL));
    int dimension;
    nanoseconds suma;
    nanoseconds promedio;

    // 1) Definicion de todos los arreglos a usar
    //Arreglo de funciones
    fn* algoritmos[NUM_ALGORITMOS] = { OrdenamientoPorInsercion, OrdenamientoBurbuja, OrdenamientoBurbujaOptimizado, OrdenamientoSeleccion, OrdenamientoShell, OrdenamientoHeap, OrdenamientoRapido, OrdenamientoMezcla };

    //Arreglo de datos para descargar datos al CSV
    int** datos = new int* [NUM_PRUEBAS + 1];
    for (int i = 0; i < NUM_PRUEBAS + 1; ++i) {
        datos[i] = new int[MAX_TAMANO];
    }

    //Arreglo de la lista de numeros aleatorios
    int** listaNumerosAleatorios = new int* [MAX_TAMANO];
    for (int i = 0; i < MAX_TAMANO; ++i) {
        listaNumerosAleatorios[i] = new int[MAX_TAMANO];
    }

    //Arreglo prueba
    int listaPrueba[5];

    //Vector de nombres del archivo CSV
    std::vector<std::string> nombresCSV = { "1_Insercion_Ordenamiento.csv", "2_Burbuja_Ordenamiento.csv", "3_BurbujaOptimizado_Ordenamiento.csv", "4_Seleccion_Ordenamiento.csv", "5_Shell_Ordenamiento.csv", "6_Heap_Ordenamiento.csv", "7_Rapido_Ordenamiento.csv", "8_Mezcla_Ordenamiento.csv" };

    //Vector de nombres del algoritmo
    std::vector<std::string> nombresAlgoritmo = { "INSERCION", "BURBUJA", "BURBUJA OPTIMIZADO", "SELECCION", "SHELL", "HEAP", "RAPIDO", "MEZCLA" };

    // 2) Generacion del arreglo de pruebas
    for (int i = 0; i < (MAX_TAMANO / INCREMENTO); ++i)
    {
        for (int elementos = 0; elementos < ((i + 1) * INCREMENTO); ++elementos)
        {
            listaNumerosAleatorios[i][elementos] = Aleatorizar(1, 1000);
        }
    }

    // 3) Demostracion de ordenamiento de cada algoritmo

    cout << "ORDENAMIENTO DE UNA LISTA DE PRUEBAS" << endl;
    for (int a = 0; a < NUM_ALGORITMOS; ++a)
    {
        int dim = 5;

        for (int i = 0; i < dim; ++i)
        {
            listaPrueba[i] = Aleatorizar(1, 10);
        }

        std::cout << "\n>> Algoritmo " << nombresAlgoritmo[a] << endl;
        std::cout << "\n  Lista original: ";
        Imprimir(listaPrueba, dim);

        if (a == RAPIDO || a == MEZCLA)
        {
            --dim;
        }

        algoritmos[a](listaPrueba, 0, dim);

        std::cout << "\n  Lista ordenada: ";
        Imprimir(listaPrueba, 5);

    }

    cout << "\nPresione cualquier tecla para iniciar el analisis de rendimiento." << endl;
    system("pause");


    // 4) Bucle de algoritmos
    for (int a = 0; a < NUM_ALGORITMOS; ++a)
    {
        system("cls");

        // 5) Bucle de tamaño
        for (int t = 0; t < (MAX_TAMANO / INCREMENTO); ++t)
        {
            dimension = (t + 1) * INCREMENTO;

            if (a == RAPIDO || a == MEZCLA)
            {
                --dimension;
            }

            suma = nanoseconds(0);
            promedio = nanoseconds(0);

            std::cout << ">> Algoritmo " << nombresAlgoritmo[a] << endl;
            std::cout << ">> Procesando datos de la lista de dimension " << (t + 1) * INCREMENTO << "..." << endl;
            datos[0][t] = dimension; //Asignacion de la fila de etiquetas

            // 6) Bucle de pruebas
            for (int p = 1; p <= NUM_PRUEBAS; p++)
            {
                //Copia de la lista de numeros original
                int* copiaLista = new int[MAX_TAMANO];
                memcpy(copiaLista, listaNumerosAleatorios[t], dimension);


                //Medicion del algorimo
                nanoseconds inicio = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
                algoritmos[a](copiaLista, 0, dimension);
                nanoseconds fin = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
                nanoseconds duracion = (fin - inicio);

                suma += duracion;

                //Recoleccion de los datos
                datos[p][t] = duracion.count();

                delete[] copiaLista;
            }

            promedio = suma / NUM_PRUEBAS;
            std::cout << "Terminado. Duracion promedio: " << promedio.count() << " nanosegundos.\n" << endl;

        }

        //7) Impresion de datos
        ofstream InsercionTiempos(nombresCSV[a]);

        for (int fila = 0; fila <= NUM_PRUEBAS; ++fila)
        {
            int columna = 0;
            for (int dimension = MIN_TAMANO; dimension <= MAX_TAMANO; dimension += INCREMENTO, ++columna)
            {
                InsercionTiempos << datos[fila][columna];
                InsercionTiempos << ",";
            }

            InsercionTiempos << endl;
        }

        InsercionTiempos.close();
    }

    system("pause");
    return 0;
}