#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 1000

int main()
{

    // Código feito por Lucas Peixoto

    int qntTermos, j = 3, qntTermosFixo;

    printf("Quantos termos da sequencia de Fibonacci deseja ver? ");
    scanf("%d", &qntTermos);

    int *FibonacciSequencia = malloc(qntTermos * sizeof(int));

    qntTermosFixo = qntTermos;

    for (int i = 0; i < 3; i++)
    {
        if (i > 0)
        {
            FibonacciSequencia[i] = 1;
        }
        else
            FibonacciSequencia[i] = 0;
    }

    qntTermos -= 3;

    if (qntTermos > 3)
    {
        while (qntTermos != 0)
        {
            FibonacciSequencia[j] = (FibonacciSequencia[j - 1] + FibonacciSequencia[j - 2]);
            j++;
            qntTermos--;
        }
    }

    for (int i = 0; i < qntTermosFixo; i++)
    {
        printf("%d ", FibonacciSequencia[i]);
    }

    return 0;
}
