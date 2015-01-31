#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fatorial(int f)
{
    if (f<=1)
        return 1;
    else
        return (f*fatorial(f-1));
}

double taylor_ex (int n_term, double value)
{
    if (n_term <= 1)
        return 1;
    else
        return taylor_ex(n_term-1, value) + pow(value, n_term-1)/fatorial(n_term-1);
}

int main()

{
    double y,N,x;
    y = taylor_ex(N, x);
    printf("Digite um inteiro positivo: \n");
    scanf("%f",&N);
    printf("Digite um valor de x: \n");
    scanf("%f",&x);
    printf("taylor eh %g\n", y);
    return 0;
}
