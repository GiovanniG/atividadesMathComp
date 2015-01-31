#include<stdio.h>
#include<math.h>

float dxdt(float x, float y)
{
    return (8.53) * (x - ((1/3) * pow(x,3))) - y;
}

float dydt(float x)
{
    return (1/8.53) * x;
}


int main()
{

    int N,j;
    float h, x, y, t=0.0;
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
    arquivo = fopen("dados15e2.dat","w");
    for(j=0;j<N;j++)
    {
        x = dydt(x) * h + x; //Calcula aproximação de y(t)
        y = dxdt(x , y) * h + y; //Calcula aproximação de x(t)
        t = t + h; //Atualiza x em 1 passo
        fprintf(arquivo,"%f %f %f\n",x,y,t);//Imprime x e y na tela
    }
    fclose(arquivo);
    printf("DONE.");
}
