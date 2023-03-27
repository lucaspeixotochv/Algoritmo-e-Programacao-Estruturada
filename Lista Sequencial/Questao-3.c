#include <stdio.h>

int main()
{
    int numeroInteiro;
    float numeroRealFloat;
    double numeroRealDouble;
    char umaLetra;
    char umaString[100];
    void *endereco_memoria;

    scanf("%d", &numeroInteiro);
    scanf("%f", &numeroRealFloat);
    scanf("%lf", &numeroRealDouble);
    scanf("%c", &umaLetra);
    scanf("%s", &umaString);
    scanf("%p", &endereco_memoria); 

    gets(umaString);

    fgets(umaString, 100, stdin);

    printf("Numero inteiro: %d", numeroInteiro);
    printf("Numeros reais: \n %.3f \n %.3lf ", numeroRealFloat, numeroRealDouble);
    printf("Letra %c", umaLetra);
    printf("String %s", umaString);
    printf("Endereco do inteiro: %x", &numeroInteiro);

    return 0;
}