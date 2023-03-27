#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, C, D;

    printf("Insira o valor de A : ");
    scanf("%d", &A);
    printf("Insira o valor de B : ");
    scanf("%d", &B);
    printf("Insira o valor de C : ");
    scanf("%d", &C);
    printf("Insira o valor de D : ");
    scanf("%d", &D);

    if (B > C && D > A && (C + D) > (A + B) && C >= 0 && D >= 0 && A % 2 == 0)
    {
        printf("Valores Aceitos");
    }
    else
        printf("Valores nao aceitos");

    return 0;
}