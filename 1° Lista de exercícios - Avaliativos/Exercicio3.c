#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{

    // Código feito por Lucas Peixoto

    setlocale(LC_ALL, "");

    double raio, volume, area;

    printf("Informe o valor do raio : ");
    scanf("%lf", &raio);

    volume = (4.0 / 3) * 3.14159 * pow(raio, 3);
    area = 4 * 3.14159 * pow(raio, 2);

    printf("A area da suerficie é %lf", area);
    printf("\nO volume da esfera é %lf", volume);

    return 0;
}