/*Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
vez cargados los liste por pantalla*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 5

int main ()
{
    char *V[CANTIDAD];  //vector de punteros char
    char *buff;         //variable auxiliar

    buff = (char *) malloc(100*sizeof(char));

    for (int i = 0; i < CANTIDAD; i++)
    {
        printf("\nIngrese nombre %d: ", i+1);
        gets(buff);
        V[i] = (char *) malloc((strlen(buff)+1) * sizeof(char));
        strcpy(V[i], buff);
    }

    printf("\n----Nombres ingresados----\n");
    for (int i = 0; i < CANTIDAD; i++)
    {
        puts(V[i]);
    }
    
    //Libero memorias dinamicas
    free(buff);
    for (int i = 0; i < CANTIDAD; i++)
    {
        free(V[i]);
    }
    
    return 0;
}