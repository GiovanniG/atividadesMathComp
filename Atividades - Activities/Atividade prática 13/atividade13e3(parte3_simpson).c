#include <stdio.h>
#include <math.h>
#include<stdlib.h>

//cálculo de aproximação da integração pelo Regra de 1/3 de Simpson Composta

//100 retângulos=4,654888
//real=4,6549(aproximado)

float f(float x)
{
    return 1.0/sqrt(x);
}

main()
{
    int N2, N, j;
    float x0, xn, x2j, x21j;

    //quantidade de intervalos que irá dividir o intervalo [a,b] (ou seja, subintervalos)
    printf("Digite o numero (precisa ser par) de intervalos que deseja utilizar para calcular a area abaixo da curva:\n");
    scanf ("%d", &N2);
    N = N2 / 2;

    //pedindo o valor do valor do intervalo [a,b]
    printf ("Digite o limite inferior do intervalo:\n");
    scanf("%f", &x0);

    printf ("Digite o limite superior do intervalo:\n");
    scanf("%f", &xn);

    //calculo da largura do intervalo
    float h = (xn - x0)/ N2;

    float In = 0.0;

    //somatorio IA
    float Ia = 0;
    for (j=1; j<=N-1; j++)
    {
        x2j = x0 + (2*j*h) ;
        //somatorio de f(x2j)
        Ia = Ia + f(x2j);
    }

    //somatorio IB
    float Ib = 0;
    for (j=1; j<=N; j++)
    {
        x21j = x0 + (2*j-1) * h;
        //somatorio de f(x2j-1)
        Ib = Ib + f(x21j);
    }

    //Regra de 1/3 de Simpson
    In = (h/3) * (f(x0) + 4 * Ib + 2 * Ia + f(xn));

    //imprime o valor da area
    printf("O valor da area abaixo da curva da função f e: %f\n", In);

}
