#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int cantidad;
    printf("Ingrese la cantidad de nombres: ");
    scanf("%d", &cantidad);

    char *V[cantidad];  //vector de punteros char
    char *buff;         //variable auxiliar
    fflush(stdin);
    buff = (char *) malloc(100*sizeof(char));

    for (int i = 0; i < cantidad; i++)
    {
        printf("\nIngrese nombre %d: ", i+1);
        gets(buff);
        V[i] = (char *) malloc((strlen(buff)+1) * sizeof(char));
        strcpy(V[i], buff);
    }

    printf("\n----Nombres ingresados----\n");
    for (int i = 0; i < cantidad; i++)
    {
        puts(V[i]);
    }
    
    //Libero memorias dinamicas
    free(buff);
    for (int i = 0; i < cantidad; i++)
    {
        free(V[i]);
    }
    
    return 0;
}

