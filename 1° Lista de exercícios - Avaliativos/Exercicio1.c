#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");

    int A, B, C, D;

    printf("Informe o valor de A : ");
    scanf("%d", &A);
    printf("Informe o valor de B : ");
    scanf("%d", &B);
    printf("Informe o valor de C : ");
    scanf("%d", &C);
    printf("Informe o valor de D : ");
    scanf("%d", &D);

    int diferenca = A * B - C * D;

    printf("%d * %d - %d * %d", A, B, C, D);
    printf("\n O valor é: %d", diferenca);
    return 0;
}