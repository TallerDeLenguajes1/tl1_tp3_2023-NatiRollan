#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 12

void cargarMatriz (int matriz[N][M]);
void mostrarMatriz (int matriz[N][M]);
void promedio (int matriz[N][M]);
void valorMaxMin (int matriz[N][M]);

int main ()
{
    int produccion[N][M];

    //Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
    srand(time(NULL));
    cargarMatriz(produccion);

    //Muestre por pantalla los valores cargados
    mostrarMatriz(produccion);

    //Saque el promedio de ganancia por año y muestrelos por pantalla
    promedio(produccion);

    //Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.
    valorMaxMin(produccion);

    return 0;
}

void cargarMatriz (int matriz[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matriz[i][j] = 10000 + rand()%50000;
        }
    }
}

void mostrarMatriz (int matriz[N][M])
{
    for (int i = 0; i < N; i++)
    {
        printf("\n");
        for (int j = 0; j < M; j++)
        {
            printf("%8d", matriz[i][j]);
        }
    }
}

void promedio (int matriz[N][M])
{
    int suma=0, promedios;
    for (int i = 0; i < N; i++)
    {
        printf("\n");
        for (int j = 0; j < M; j++)
        {
            suma = suma + matriz[i][j];
        }
        promedios = suma/M;
        printf("\nGanacia del anio %d: %d", i+1, promedios);
    }
}

void valorMaxMin (int matriz[N][M])
{
    int valorMax = 10000, valorMin = 50000, anio_min, anio_max, mes_min, mes_max;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matriz[i][j] > valorMax)
            {
                valorMax = matriz[i][j];
                anio_max = i + 1;
                mes_max = j + 1;
            }

            if (matriz[i][j] < valorMin)
            {
                valorMin = matriz[i][j];
                anio_min = i + 1;
                mes_min = j + 1;
            }
        }
    }

    printf("\n\nEl valor maximo es: %d", valorMax);
    printf("\nOcurrio en el anio %d, mes %d", anio_max, mes_max);
    printf("\n\nEl valor minimo es: %d", valorMin);
    printf("\nOcurrio en el anio %d, mes %d", anio_min, mes_min);
}