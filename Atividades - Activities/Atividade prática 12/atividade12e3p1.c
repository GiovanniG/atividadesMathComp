#include<stdio.h>
#include <stdlib.h>
#include<math.h>

//uso da fórmula (b)(extremo intervalo esquerdo) para o cálculo de aproximação da integração pela regra dos retângulos

//4 retângulos=3,431659
//100 retângulos=4,620276
//real=4,6708(aproximado)

float f(float x)
{
    return exp(x);
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
        lN=lN+h*f(x0+i*h);
    }

    //imprime o valor da area
    printf("\nResultado: %f",lN);
}
