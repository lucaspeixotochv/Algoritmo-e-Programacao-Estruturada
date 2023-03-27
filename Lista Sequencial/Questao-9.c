#include <stdio.h>

int main()
{
    char nome[50];
    float salario, vendas, comissao, total;

    printf("Digite o nome: ");
    scanf("%s", nome);

    printf("Digite o salário do vendedor: ");
    scanf("%f", &salario);

    printf("Digite o total de vendas efetuadas pelo vendedor: ");
    scanf("%f", &vendas);

    comissao = 0.15 * vendas;
    total = salario + comissao;

    printf("O vendedor %s receberá R$ %.2f no final do mês.\n", nome, total);

    return 0;
}