#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int Aleatorizar(int inicio, int fin)
{
    return inicio + rand() % (fin - inicio + 1);
}

void Imprimir(int s[], int n)
{

    cout << "[ ";
    for (int i = 0; i < n; ++i)
    {
        cout << s[i] << " , ";
    }
    cout << "\b\b]" << endl;

}

void Intercambiar(int& a, int& b)
{
    int aux = a;
    a = b;
    b = aux;
}

void Mezclar(int s[], int inicio, int medio, int fin)
{
    const int n1 = medio - inicio + 1; //*
    const int n2 = fin - medio;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
    {
        L[i] = s[inicio + i]; //*
    }

    for (int j = 0; j < n2; ++j)
    {
        R[j] = s[medio + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < n1 && j < n2) //*
    {
        if (L[i] <= R[j])  //*
        {
            s[k] = L[i];
            i++;
        }
        else
        {
            s[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) //*
    {
        s[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) //*
    {
        s[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;

}

int Particion(int s[], int inicio, int fin)
{
    int pivote = s[fin];
    int i = inicio - 1;
    int aux;

    for (int j = inicio; j < fin; ++j)
    {
        if (s[j] <= pivote)
        {
            i++;
            aux = s[j];
            s[j] = s[i];
            s[i] = aux;
        }
    }

    aux = s[fin];
    s[fin] = s[i + 1];
    s[i + 1] = aux;

    return i + 1;
}

void MaxHeapify(int s[], int n, int i)
{
    int izquierdo = 2 * i + 1;
    int derecho = (2 * i) + 2;
    int mayor = i;

    if (izquierdo < n && s[izquierdo] > s[mayor])
    {
        mayor = izquierdo;
    }

    if (derecho < n && s[derecho] > s[mayor])
    {
        mayor = derecho;
    }

    if (mayor != i)
    {
        Intercambiar(s[i], s[mayor]);
        MaxHeapify(s, n, mayor);
    }
}

void ConstruirHeapMax(int s[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        MaxHeapify(s, n, i);
    }
}

