#include "FuncionesAuxiliares.hpp"

void OrdenamientoPorInsercion(int s[], int inicio, int n)
{
    int val(0), j(0);
    for (int i = 1; i < n; ++i)
    {
        val = s[i];
        j = i - 1;

        while (j >= 0 && val < s[j])
        {
            s[j + 1] = s[j];
            j = j - 1;
        }

        s[j + 1] = val;
    }
}

void OrdenamientoBurbuja(int s[], int inicio, int n)
{
    int temp(0);

    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            if (s[j] > s[j + 1])
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void OrdenamientoBurbujaOptimizado(int s[], int inicio, int n)
{
    bool intercambiado = true;

    while (intercambiado)
    {
        intercambiado = false;
        int temp(0);
        for (int j = 0; j < n - 1; ++j)
        {
            if (s[j] > s[j + 1])
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                intercambiado = true;
            }
        }
    }
}

void OrdenamientoSeleccion(int s[], int inicio, int n)
{
    int i_min, temp;

    for (int i = 0; i < n - 1; ++i)
    {
        i_min = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (s[j] < s[i_min])
            {
                i_min = j;
            }
        }

        if (i_min != i)
        {
            temp = s[i];
            s[i] = s[i_min];
            s[i_min] = temp;
        }
    }
}

void OrdenamientoShell(int s[], int inicio, int n)
{
    int gap[2] = { n / 2, 1 };
    int temp, k;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = gap[i]; j < n; ++j)
        {
            temp = s[j];
            k = j;
            while (k >= gap[i] && s[k - gap[i]] > temp)
            {
                s[k] = s[k - gap[i]];
                k = k - gap[i];
            }

            s[k] = temp;
        }
    }
}

void OrdenamientoHeap(int s[], int inicio, int n)
{
    int aux(0);

    ConstruirHeapMax(s, n);

    for (int i = n - 1; i >= 0; --i)
    {
        Intercambiar(s[0], s[i]);

        MaxHeapify(s, i, 0);

    }
}

void OrdenamientoRapido(int s[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int pivote_indx = Particion(s, inicio, fin);
        OrdenamientoRapido(s, inicio, pivote_indx - 1);
        OrdenamientoRapido(s, pivote_indx + 1, fin);
    }
}

void OrdenamientoMezcla(int s[], int inicio, int fin)
{

    if (inicio < fin)
    {

        int medio = (inicio + fin) / 2;
        OrdenamientoMezcla(s, inicio, medio);
        OrdenamientoMezcla(s, medio + 1, fin);
        Mezclar(s, inicio, medio, fin);
    }

}