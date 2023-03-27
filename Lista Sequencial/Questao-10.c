#include <stdio.h>
#include <math.h>

int main()
{

    float x1, y1, x2, y2;
    printf("Insira o valor de x do plano 1: ");
    scanf("%f", &x1);
    printf("Insira o valor de y do plano 1: ");
    scanf("%f", &y1);
    printf("Insira o valor de x do plano 2: ");
    scanf("%f", &x2);
    printf("Insira o valor de y do plano 2: ");
    scanf("%f", &y2);

    float distancia = (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
    printf("A distancia entre os dois planos é: %.2f", distancia);

    return 0;
}