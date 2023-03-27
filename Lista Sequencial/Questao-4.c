#include <stdio.h>

int main()
{
    int a, b;
    printf("Insira o valor de A e B");
    scanf("%d, %d", &a, &b);
    int x = a + b;
    printf("%d + %d = %d", a, b, x);

    return 0;
}