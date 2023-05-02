#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
} typedef Cliente;

//Implemente una función que calcule el costo total de un producto.
float costoTotal (Producto *productos);
void mostrar (Cliente *puntero, int cantidad);

int main ()
{
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

    //Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de clientes.
    int ctdadCliente;
    Cliente *clientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &ctdadCliente);
    clientes = (Cliente *) malloc(ctdadCliente*sizeof(Cliente)); //array de estructuras del tipo Cliente

    //Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.
    srand(time(NULL));

    for (int i = 0; i < ctdadCliente; i++)
    {
        //cargo clientes
        clientes[i].ClienteID = i;
        fflush(stdin);
        char buff[50];     //variable auxiliar
        printf("\nIngrese nombre del cliente: ");
        gets(buff);
        clientes[i].NombreCliente = (char *) malloc((strlen(buff)+1)*sizeof(char)); //memoria dinámica
        strcpy(clientes[i].NombreCliente, buff);
        clientes[i].CantidadProductosAPedir = 1 + rand()%5;
        clientes[i].Productos = (Producto *) malloc(clientes[i].CantidadProductosAPedir*sizeof(Producto)); //memoria dinamica

        //cargo productos
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j;
            clientes[i].Productos[j].Cantidad = 1 + rand()%10;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand()%5];
            clientes[i].Productos[j].PrecioUnitario = 10 + rand()%91;
        }
    }
    mostrar(clientes, ctdadCliente);

    //libero memorias dinamicas
    free(clientes);
    for (int i = 0; i < ctdadCliente; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    
    return 0;
}

float costoTotal (Producto *productos)
{
    float costo;
    costo = productos->Cantidad * productos->PrecioUnitario;

    return costo;
}

void mostrar (Cliente *puntero, int cantidad)
{
    float costoTotalxProd;
    for (int i = 0; i < cantidad; i++)
    {
        float totalFinal=0;
        printf("\n\n------- CLIENTE -------");
        printf("\nID: %d", puntero[i].ClienteID);
        printf("\nNombre del Cliente: %s", puntero[i].NombreCliente);
        printf("\nCantidad de productos a pedir: %d\n", puntero[i].CantidadProductosAPedir);

        for (int j = 0; j < puntero[i].CantidadProductosAPedir; j++)
        {
            printf("\n------- PRODUCTOS %d -------", j+1);
            printf("\nID: %d", puntero[i].Productos[j].ProductoID);
            printf("\nCantidad: %d", puntero[i].Productos[j].Cantidad);
            printf("\nTipo de producto: %s", puntero[i].Productos[j].TipoProducto);
            printf("\nPrecio Unitario: %.2f", puntero[i].Productos[j].PrecioUnitario);

            costoTotalxProd = costoTotal(&puntero[i].Productos[j]);
            printf("\nCosto Total: %.2f", costoTotalxProd);
            totalFinal = totalFinal + costoTotalxProd;
        }

        printf("\nTotal de la suma de todos los productos: %.2f", totalFinal);

    }
}