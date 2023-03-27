#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x;

    printf("Insira um numero: ");
    scanf("%d", &x);

    if (x % 2 == 0)
    {
        printf("O numero eh par");
    }
    else
        printf("O numero eh impar");

    return 0;
}