#include <stdio.h>

int main()
{
    float a, b, c, d;
    printf("Insira o número A: ");
    scanf("%f", &a);
    printf("Insira o número B: ");
    scanf("%f", &b);
    printf("Insira o número C: ");
    scanf("%f", &c);
    printf("Insira o número D: ");
    scanf("%f", &d);

    float diferenca = (a * b) - (c - d);
    printf("\n DIFERENCA = (%f*%f - %f * %f)", a, b, c, d);
    printf("\n  DIFERENCA = %f", diferenca);

    return 0;
}