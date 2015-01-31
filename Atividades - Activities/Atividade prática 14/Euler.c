#include<stdio.h>

float f(float y)
{
    return 1-0.4*y;
}

int main()
{

    int N,j;
    float h, x, y;

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

    //Etapa de integração, método de Euler.
    printf("   X        Y   \n");
    for(j=0;j<N;j++)
    {
        *** Preencha aqui *** //Atualiza x em 1 passo
        *** Preencha aqui *** //Calcula aproximação de y(x)
        printf("%.4f   %.4f   \n",x,y);//Imprime x e y na tela
    }

}
