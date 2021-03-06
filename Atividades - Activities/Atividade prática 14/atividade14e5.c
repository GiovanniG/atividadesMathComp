#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double y, double x)
{
    return (2.0*y)/(x+1.0)+(pow(x+1.0,3.0));
}

int main()
{
    int j;
    double h, x0, y, xf;

    //Valor do passo de integra��o (DELTAx)
    printf("Escolha o passo de integra��o: ");
    scanf("%lf" ,&h);

    /*Condi��es iniciais das vari�veis dependente y(x) e independente x*/

    printf("\nInforme o valor inicial x0: ");
    scanf("%lf" ,&x0);

    printf("\nInforme o valor inicial y(x0):");
    scanf("%lf" ,&y);

    printf("\nInforme o valor final de x: x(xf):");
    scanf("%lf" ,&xf);

    //Etapa de integra��o, m�todo de Euler
    printf("   X        Y   \n");

    j=0;
    while (x0<=xf)
    {
        j++;
        x0=x0+h; //Atualiza x em 1 passo
        y=y+h*f(y,x0); //Calcula aproxima��o de y(x)
        printf("%d  %lf   %lf   \n",j,x0,y);//Imprime x e y na tela
    }

}
