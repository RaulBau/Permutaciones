/***
 * Nombre: Bautista Robles Raúl
 * Fecha: 17/02/2021
 * Tarea: Permutaciones
 * Materia: Estadística
***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cont;

void PermutacionesRec(int n);
void Permuta(char *prmt, int n, int r);
void arregloString(char *prmt, char str[]);

int main(int argc, char *argv[])
{
    cont = 0;
    // Revisamos si hay un parametro para hacer las permutaciones
    if (argc > 1)
    {
        // Obtenemos el parametro
        char *a = argv[1];
        // Lo convertimos a entero para utilizarlo
        int num = atoi(a);
        if (num > 1)
        {
            printf("%d\n", num);
            PermutacionesRec(num);
        }
        else
        {
            if (num > 0)
            {
                printf("Ingresa un número mayor que 1\n");
            }
            else
            {
                printf("Ingresa un número positivo\n");
            }
        }
    }
    // Avisamos que no se realiza la ejecución
    else
    {
        printf("Ingresa un número al ejecutar el programa\n");
    }
    return 0;
}

void PermutacionesRec(int n)
{
    char str[n + 1];
    for (int i = 0; i < n; i++)
    {
        str[i] = (i + 1) + '0';
    }

    str[n] = '\n';
    printf("%s", str);
    Permuta(str, 0, n - 1);
}

void Permuta(char *prmt, int n, int r)
{
    int aux;
    char *l;

    if (n == r)
    {
        printf("%d. %s", (cont + 1), prmt);
        cont++;
    }
    else
    {
        for (int i = n; i <= r; i++)
        {
            aux = prmt[n];
            prmt[n] = prmt[i];
            prmt[i] = aux;

            Permuta(prmt, n + 1, r);

            aux = prmt[n];
            prmt[n] = prmt[i];
            prmt[i] = aux;
        }
    }
}