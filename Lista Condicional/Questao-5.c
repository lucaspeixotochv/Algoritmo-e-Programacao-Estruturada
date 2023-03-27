#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int x;

    printf("Insira um valor : ");
    scanf("%d", &x);

    if (x >= 0)
    {
        printf("%d ao quadrado: %d\nraiz quadrada: %.2f", x, x * x, sqrt(x));
    }

    return 0;
}