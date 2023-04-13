#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    // Código feito por Lucas Peixoto

    setlocale(LC_ALL, "Portuguese");

    int num;
    float media = 0;

    for (int i = 1; i < 11; i++)
    {
        printf("Informe o valor do %d° Número : ", i);
        scanf("%d", &num);
        media += num;
    }

    media /= 10;

    printf("A media é : %.2f", media);

    return 0;
}