#include <stdio.h>
#include <stdlib.h>

int main()
{
    float altura, pesoIdeal;
    char sexo;

    printf("Insira sua altura: ");
    scanf("%f", &altura);
    printf("Insira seu sexo (m ou f) : ");
    scanf(" %c", &sexo);

    if (sexo == 'm' || sexo == 'M')
    {
        pesoIdeal = (72.7 * altura) - 58;
    }
    else if (sexo == 'f' || sexo == 'F')
    {
        pesoIdeal = (62.1 * altura) - 44.7;
    }

    printf("Seu peso ideal eh : %.2f", pesoIdeal);

    return 0;
}