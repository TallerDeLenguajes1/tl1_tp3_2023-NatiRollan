#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 5
#define M 12

int main(){
    int matriz[N][M], suma, minimo, maximo, anio, mes, mayor=0, menor=1000001, mes_menor, anio_menor;
    float promedio;

    srand(time(NULL));

    //Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matriz[i][j] = rand() % 50000 + 10000;
        }
    }

    //Muestre por pantalla los valores cargados
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%6d ", matriz[i][j]);
        }
        printf("\n");
    }

    //Saque el promedio de ganancia por año y muestrelos por pantalla
    for (int i = 0; i < N; i++)
    {
        suma = 0;
        for (int j = 0; j < M; j++)
        {
           suma = suma + matriz[i][j];
        }
        promedio = suma/M;
        printf("\nPromedio de ganancia del anio %d: %.2f", i+1, promedio);
    }

    //Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matriz[i][j] > mayor)
            {
                mayor = matriz[i][j];
                mes = j+1;
                anio = i+1;
            }

            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
                mes_menor = j+1;
                anio_menor = i+1;
            }
        }
    }
    printf("\n\nEl valor maximo es %d, ocurrio en el mes %d, anio %d", mayor, mes, anio);
    printf("\nEl valor minimo es %d, ocurrio en el mes %d, anio %d", menor, mes_menor, anio_menor);

    return 0;
}