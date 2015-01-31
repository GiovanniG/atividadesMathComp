#include<stdio.h>
#include<math.h>
float dxdt(float x)
{
    return ;
}
float dydt(float y, float x)
{
    return ;
}

int main()
{

    int N,j;
    float h, x, y, t=0;
    FILE *arquivo;

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
    arquivo = fopen("dados.dat","w");
    for(j=0;j<N;j++)
    {
        x = dxdt(x) * h + x; //Calcula aproximação de x(t)
        y = dydt(y ,x) * h + y; //Calcula aproximação de y(t)
        t = t + h; //Atualiza x em 1 passo
        fprintf(arquivo,"%f %f %f\n",x,y,t);//Imprime x e y na tela
    }
    fclose(arquivo);
    printf("DONE.");
}
