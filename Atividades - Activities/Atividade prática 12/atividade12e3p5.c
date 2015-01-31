#include<stdio.h>
#include <stdlib.h>
#include<math.h>

//uso da fórmula (c)(metade do retangulo) para o cálculo de aproximação da integração pela regra dos retângulos

//4 retângulos=3,792948
//100 retângulos=4,636454
//real=4,6667(aproximado)

float f(float x)
{
    return sqrt(x);
}

main()
{
    int N, i;
    float x0, xN;

    //quantidade de retangulos
    printf("Digite o valor de N: ");
    scanf("%d",&N);

    //intervalo finitio [x0.xN]
    printf("\nDigite o valor de x0: ");
    scanf("%f",&x0);

    printf("\nDigite o valor de xN: ");
    scanf("%f",&xN);

    //calcula a largura
    float h=(xN-x0)/N;

    //calculo da area(usou-se i no lugar do j)
    float lN=0.0;
    for(i=1;i<=N-1;i++)
    {
        lN=lN+h*f((x0+(2*i+1)*h/2));
    }

    //imprime o valor da area
    printf("\nResultado: %f",lN);
}
