#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");

    int soma = 0;

    for (int i = 0; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            soma += i;
            printf("\n%d", i);
        }
    }

    printf("O resultado da soma é : %d", soma);

    return 0;
}