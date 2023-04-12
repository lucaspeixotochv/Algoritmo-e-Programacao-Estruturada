#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");

    float x, y;

    printf("Informe o valor de x : ");
    scanf("%f", &x);
    printf("Informe o valor de y : ");
    scanf("%f", &y);

    if(x > 0 && y > 0){
        printf("Q1");
    } else if (x < 0 && y > 0){
        printf("Q2");
    } else if (x < 0 && y < 0){
        printf("Q3");
    } else if (x > 0 && y < 0){
        printf("Q4");
    } else if ( x == 0 && y == 0){
        printf("Origem");
    } else if (x == 0 && y != 0){
        printf("Eixo Y");
    } else if (y == 0 && x != 0){
        printf("Eixo X");
    }

    return 0;
}