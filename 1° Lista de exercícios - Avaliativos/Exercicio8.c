#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    // Código feito por Lucas Peixoto

    setlocale(LC_ALL, "Portuguese");

    int numero, maiorNumero = 0;

    while (numero >= 0)
    {
        printf("Informe um numero : ");
        scanf("%d", &numero);

        if (numero > maiorNumero)
        {
            maiorNumero = numero;
        }
    }

    printf("O maior numero dentre os numeros informados foi o numero %d", maiorNumero);

    return 0;
}