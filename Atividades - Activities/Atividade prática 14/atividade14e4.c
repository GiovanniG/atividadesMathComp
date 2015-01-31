#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double y)
{
    return 1.0-0.4*y;
}

int main()
{
    int j;
    double h, x0, y, xf;

    //Valor do passo de integração (DELTAx)
    printf("Escolha o passo de integração: ");
    scanf("%lf" ,&h);

    /*Condições iniciais das variáveis dependente y(x) e independente x*/

    printf("\nInforme o valor inicial x0: ");
    scanf("%lf" ,&x0);

    printf("\nInforme o valor inicial y(x0):");
    scanf("%lf" ,&y);

    /*printf("\nInforme o valor final de x: x(xf):\n");
    scanf("%lf" ,&xf);*/

    //Etapa de integração, método de Euler
    printf("   X        Y   \n");

    j=0;
    while (x0<=40.0)
    {
        j++;
        x0=x0+h; //Atualiza x em 1 passo
        y=y+h*f(y); //Calcula aproximação de y(x)
        printf("%d  %lf   %lf   \n",j,x0,y);//Imprime x e y na tela
    }

}
