#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//cálculo de aproximação da integração pelo método dos trapézios


float f(float x)
{
    return exp(x);
}

main()
{
    int N, i;
    float x0, xN;

    //quantidade de retangulos
    printf("Digite o valor de N: \n");
    scanf("%d",&N);

    //intervalo finitio [x0.xN]
    printf("\nDigite o valor de x0: \n");
    scanf("%f",&x0);

    printf("\nDigite o valor de xN: \n");
    scanf("%f",&xN);

    //calcula a largura do intervalo
    float h=(xN-x0)/N;

    //calcula a largura do trapézio
    float lN=(f(x0)+f(xN))/2;

    //calculo da integral usou-se i no lugar do j)
    for(i=1;i<=N-1;i++)
    {
        lN=lN+f(x0+h*i);
    }
    lN=lN*h;

    //imprime o valor da area
    printf("\n%f",lN);
}
