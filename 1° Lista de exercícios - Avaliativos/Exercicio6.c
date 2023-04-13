#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    // Código feito por Lucas Peixoto

    setlocale(LC_ALL, "");

    long int soma = 0;

    for (int i = 0; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            soma += i;
            printf("\n%d", i);
        }
    }

    printf("\n\nO resultado da soma é : %ld", soma);

    return 0;
}