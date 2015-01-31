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

    //Valor do passo de integra��o (DELTAx)
    printf("Escolha o passo de integra��o: ");
    scanf("%lf" ,&h);

    //N�mero de pontos de integra��o
    printf("\nEscolha o n�mero de pontos de integra��o: ");
    scanf("%d" ,&N);

    /*Condi��es iniciais das vari�veis dependente y(x) e independente x*/

    printf("\nInforme o valor inicial x0: ");
    scanf("%lf" ,&x0);

    printf("\nInforme o valor inicial y(x0):");
    scanf("%lf" ,&y);

    //Etapa de integra��o, m�todo de Euler
    printf("   X        Y   \n");

    for(j=0;j<N;j++)
    {
        //Atualiza x em 1 passo
        x0=x0+h;
        //Calcula aproxima��o de y(x)
        y=y+h*f(y);
        printf("%lf   %lf   \n",x0,y);//Imprime x e y na tela
    }
}
