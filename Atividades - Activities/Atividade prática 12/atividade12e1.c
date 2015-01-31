#include<stdio.h>
#include <stdlib.h>
#include<math.h>

//uso da fórmula (a) para o cálculo de aproximação da interação pela regra dos retângulos

float f(float x)
{
    return exp(x);
}
main ()

{
    int N, i;
    float x0, xN;

    //quantidade de retangulos
    printf("Digite o valor de N: \n");
    scanf("%d",&N);

    //intervalo finitio [x0.xN]
    printf("Digite o valor de x0: \n");
    scanf("%f",&x0);

    printf("Digite o valor de xN: \n");
    scanf("%f",&xN);

    //calcula a largura
    float h=(xN-x0)/N;

    //calculo da area
    float lN=0.0;
    for(i=0;i<=N-1;i++)
    {
        lN=lN+h*f(x0+i*h);
    }

    //imprime o valor da area
    printf("%f",lN);
}
