#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "");

    double x1, x2, y1, y2, distancia;

    printf("Informe o eixo x do primeiro ponto : ");
    scanf("%lf", &x1);
    printf("Informe o eixo y do primeiro ponto : ");
    scanf("%lf", &y1);
    printf("Informe o eixo x do segundo ponto : ");
    scanf("%lf", &x2);
    printf("Informe o eixo y do segundo ponto : ");
    scanf("%lf", &y2);

    distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("A distância entre os pontos é %.4lf", distancia);
    return 0;
}