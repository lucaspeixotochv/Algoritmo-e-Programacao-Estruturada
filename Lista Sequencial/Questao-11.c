#include <stdio.h>

int main()
{
    float pi = 3.14159;
    float raio;

    printf("Insira o raio da esfera em cm: ");
    scanf("%f", &raio);

    float resultado = (((4 / 3) * pi) * (raio * raio * raio));
    printf("O resultado da área do círculo é: %f", resultado);
    return 0;
}