#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double y)
{
    return 1.0-0.4*y;
}

int main()
{
    int N, j;
    double h, x0, y;

    //Valor do passo de integração (DELTAx)
    printf("Escolha o passo de integração: ");
    scanf("%lf" ,&h);

    //Número de pontos de integração
    printf("\nEscolha o número de pontos de integração: ");
    scanf("%d" ,&N);

    /*Condições iniciais das variáveis dependente y(x) e independente x*/

    printf("\nInforme o valor inicial x0: ");
    scanf("%lf" ,&x0);

    printf("\nInforme o valor inicial y(x0):");
    scanf("%lf" ,&y);

    //Etapa de integração, método de Euler
    printf("   X        Y   \n");

    for(j=0;j<N;j++)
    {
        //Atualiza x em 1 passo
        x0=x0+h;
        //Calcula aproximação de y(x)
        y=y+h*f(y);
        printf("%lf   %lf   \n",x0,y);//Imprime x e y na tela
    }
}
