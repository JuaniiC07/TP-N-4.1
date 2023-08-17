#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

const int maxC = 3;
const int maxCS = 50;

void cargarMatriz (int M[][maxC], int dimF);
void mostrarMatriz (int M[][maxC], int dimF);
void cargarNumerosRandom (int M[][maxC], int dimF);
int acumuladorMatriz (int M[][maxC], int dimF);
float promedioMatriz(int acumulador, int maxC, int dimF);
int buscarDatoMatriz (int datoaBuscar, int M[][maxC], int dimF);
int cargarString(char stringOrigen[][maxCS], int dimension);
void mostrarString(char stringOrigen[][maxCS], int cantidadDeValidos);
int buscarString(char arreglo[][maxCS], int cantidad, char palabra[]);
void ordenarAlfabeticamente(char arreglo[][maxCS], int cantidad);


int main()
{

    float promedio = 0;
    int acumulador = 0;
    int flag = 0;
    int datoaBuscar = 0;
    int matriz1[2][maxC];
    int dimension = 10;
    char stringOrigen[dimension][maxCS];
    int cantidadDeValidos = 0;
    int indice;

    cargarMatriz(matriz1, 2);
    mostrarMatriz(matriz1, 2);
//cargarNumerosRandom(matriz1, 2);
    /*mostrarMatriz(matriz1, 2);
    acumulador = acumuladorMatriz(matriz1, 2);
    printf("\n La suma de los elementos es: %d", acumulador);
    promedio = promedioMatriz(acumulador, maxC, 2);
    printf("\n El promedio de la matriz es: %g", promedio);
    printf("\nIngrese un elemento a buscar en la matriz: ");
    scanf("%i", &datoaBuscar);
    flag = buscarDatoMatriz(datoaBuscar, matriz1, 2);
    if (flag == 1)
    {
        printf("\nEl elemento: %i se encuentra en la matriz", datoaBuscar);
    }else
        printf("\nEl elemento: %i no se encuentra en la matriz", datoaBuscar);*/
    cantidadDeValidos = cargarString (stringOrigen, dimension);
    printf("\nLa cantidad de palabras cargadas es: %i\n", cantidadDeValidos);
    ordenarAlfabeticamente(stringOrigen, cantidadDeValidos);
    printf("Arreglo ordenado alfabeticamente:\n");
    for (int i = 0; i < cantidadDeValidos; i++) {
        printf("%s\n", stringOrigen[i]);
    }

    // Funcion 9
    /*char palabra[20];
    printf("Ingrese la palabra a buscar: ");
    fflush(stdin);
    gets(palabra);
    indice = buscarString(stringOrigen, cantidadDeValidos, palabra);
    if (indice == -1)
    {
        printf("La palabra no se encontro en el arreglo.\n");
    }
    else
    {
        printf("La palabra: %s se encontro en la posición %d del arreglo.\n", stringOrigen[indice], indice);
    }*/
    mostrarString(stringOrigen, cantidadDeValidos);
    return 0;
}

/// Funciones

// Funcion 1

void cargarMatriz (int M[][maxC], int dimF)
{
    int f = 0;
    int c = 0;

    for(f=0; f<dimF; f++) {

    for(c=0; c<maxC; c++){

    printf("\nIngrese un numero entero: ");
    scanf("%d", &M[f][c]);
    }
}
}

// Funcion 2

void mostrarMatriz (int M[][maxC], int dimF)
{
    int f = 0;
    int c = 0;

    for(f=0; f<dimF; f++) {
        for(c=0; c<maxC; c++) {
            printf("|%i|", M[f][c]);
        }
            printf("\n");
    }

    }



// Funcion 3

void cargarNumerosRandom (int M[][maxC], int dimF)
{
    srand(time(NULL));
    int f = 0;
    int c = 0;
    for(f=0; f<dimF;f++)
{
    for(c=0; c<maxC;c++) {
        M[f][c] = rand()%100;

        }
    }
}

// Funcion 4
int acumuladorMatriz (int M[][maxC], int dimF)
{

    int acumulador = 0;
    int f = 0;
    int c = 0;
    for(f=0; f<dimF;f++)
{
    for(c=0; c<maxC;c++) {
        acumulador += M[f][c];
        }
    }
    return acumulador;
}

// Funcion 5

float promedioMatriz(int acumulador, int maxC, int dimF)
{

    float promedio = 0;
    float elementos = maxC * dimF;
    promedio = acumulador / elementos;
    return promedio;
}

// Funcion 6

int buscarDatoMatriz (int datoaBuscar, int M[][maxC], int dimF)
{
    int flag = 0;
    int f = 0;
    int c = 0;

    for(f; f<dimF && flag == 0; f++){
    for(c; c<maxC && flag == 0; c++){
        if (M[f][c] == datoaBuscar)
            {
                flag = 1;
            }
        }
    }
    return flag;

}

// Funcion 7

int cargarString(char stringOrigen[][maxCS], int dimension)
{
        int seguir = 1;
        int i = 0;
        while (i<dimension && seguir == 1){
            printf("Ingrese una palabra\n");
            fflush(stdin);
            gets(stringOrigen[i]);
            i++;
            printf("Ingrese 1 para cargar otra palabra o 0 para cortar\n");
            fflush(stdin);
            scanf("%i", &seguir);
        }
        return i;
}

// Funcion 8

void mostrarString(char stringOrigen[][maxCS], int cantidadDeValidos)
{
    for (int i = 0; i < cantidadDeValidos; i++)
    {
        printf("\n%s ", stringOrigen[i]);
    }
    printf("\n");
}

// Funcion 9

int buscarString(char arreglo[][maxCS], int cantidad, char palabra[]) {
    int i;
    int pos = -1;
    for (i = 0; i < cantidad && pos == -1; i++) {
        if (strcmp(arreglo[i], palabra) == 0) {
            pos = i; // Se encontró la palabra en la posición i
        }
    }
    return pos; // No se encontró la palabra en el arreglo
}

// Funcion 10

// Funcion 11

void ordenarAlfabeticamente(char arreglo[][maxCS], int cantidad) {
    int i, j, min;
    char aux[20];
    for (i = 0; i < cantidad; i++) {
        min = i;
        for (j = i + 1; j < cantidad; j++) {
            if (strcmp(arreglo[j], arreglo[min]) < 0) {
                min = j;
            }
        }
        if (min != i) {
            strcpy(aux, arreglo[i]);
            strcpy(arreglo[i], arreglo[min]);
            strcpy(arreglo[min], aux);
        }
    }
}


