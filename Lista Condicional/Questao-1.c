#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x, y;

    printf("Insira o primeiro numero: ");
    scanf("%d", &x);
    printf("Insira o segundo numero: ");
    scanf("%d", &y);

    if (x > y)
    {
        printf("O numero %d eh maior", x);
    }
    else if (x < y)
    {
        printf("O numero %d eh maior", y);
    }
    else
        printf("Os numeros sao iguais");

    return 0;
}