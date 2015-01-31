#include<stdio.h>

float f(float y)
{
    return 1-0.4*y;
}

int main()
{

    int N,j;
    float h, x, y,xf;

    //Valor do passo de integração (DELTAx)
    printf("Escolha o passo de integração: \n");
    scanf("%f",&h);

    //Número de pontos de integração
    printf("Escolha o número de pontos de integração: \n");
    scanf("%d",&N);

    //Condições iniciais das variáveis dependente y(x) e independente x
    printf("Informe o valor inicial de x: x0 \n");
    scanf("%f",&x);

    printf("Informe o valor inicial de y: y(x0): \n");
    scanf("%f",&y);

    printf("Informe o valor final de x: x(xf):\n");
    scanf("%f",&xf);



    //Etapa de integração, método de Euler.
    printf("   X        Y   \n");

    j=0;
    while (x<xf)
    {
        j++;
        x=x+h; //Atualiza x em 1 passo
        y=y+h*f(y); //Calcula aproximação de y(x)
        printf("%d  %.10f   %.4f   \n",j,x,y);//Imprime x e y na tela
    }

}
