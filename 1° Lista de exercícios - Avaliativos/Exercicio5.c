#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAMANHO 60

int main()
{

    // Código feito por Lucas Peixoto

    int numero, listaNumeros[TAMANHO], j = 0;

    printf("Informe um numero : ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++)
    {
        if (numero % i == 0)
        {
            listaNumeros[j] = i;
            j++;
        }
    }

    for (int i = 0; i < j; i++)
    {
        printf("%d%c", listaNumeros[i], (i == j - 1 ? '\0' : ','));
    }

    return 0;
}