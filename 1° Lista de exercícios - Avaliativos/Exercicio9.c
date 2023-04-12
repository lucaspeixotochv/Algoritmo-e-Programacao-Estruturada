#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int escolhaFruta, qntFruta, carrinho = 0, continuar = 1;

    do
    {
        printf("------------------------------\n");
        printf("ABACAXI (1)\n");
        printf("MAÇA (2)\n");
        printf("PERA (3)\n");
        printf("------------------------------\n");

        printf("Qual fruta você deseja adicionar ? ");
        scanf("%d", &escolhaFruta);

        if (escolhaFruta == 1)
        {
            printf("Quantos abacaxis deseja comprar ? ");
            scanf("%d", &qntFruta);
            carrinho += qntFruta * 5;
        }
        else if (escolhaFruta == 2)
        {
            printf("Quantas maças deseja comprar ? ");
            scanf("%d", &qntFruta);
            carrinho += qntFruta * 1;
        }
        else if (escolhaFruta == 3)
        {
            printf("Quantas peras deseja comprar ? ");
            scanf("%d", &qntFruta);
            carrinho += qntFruta * 4;
        }
        else
        {
            printf("Fruta inválida!");
        }

        printf("\n\nCarrinho = R$ %d", carrinho);
        printf("\nDeseja continuar comprando ? (1) Continuar (0) Parar : ");
        scanf("%d", &continuar);
    } while (continuar == 1);

    return 0;
}