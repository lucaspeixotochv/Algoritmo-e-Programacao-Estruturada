#include <stdio.h>
#include <stdlib.h>

int main()
{

    float salario, prestacao;

    printf("Insira seu salario : ");
    scanf("%f", &salario);
    printf("Insira o valor da prestacao : ");
    scanf("%f", &prestacao);

    if (prestacao > ((salario * 20) / 100))
    {
        printf("Emprestimo nao concedido");
    }
    else
        printf("Emprestimo concedido");

    return 0;
}