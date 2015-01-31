#include<stdio.h>
#include<math.h>

float f(float x, float y)
{
    return 8.53*(x- pow(x,3)/3.0-y);
}

float g(float x)
{
    return x/8.53;
}

int main()
{

    int N,j;
    float h, x, y,x1,y1,t;
    FILE *arquivo;

    //Valor do passo de integração (DELTAx)
    printf("Escolha o passo de integração: \n");
    scanf("%f",&h);

    //Número de pontos de integração
    printf("Escolha o número de pontos de integração: \n");
    scanf("%d",&N);

    //Condições iniciais das variáveis dependente y(x) e independente x

    printf("Informe o valor inicial de t: t0 \n");
    scanf("%f",&t);

    printf("Informe o valor inicial de x: x0 \n");
    scanf("%f",&x);

    printf("Informe o valor inicial de y: y(x0): \n");
    scanf("%f",&y);

    //Etapa de integração, método de Euler.
    arquivo = fopen("scilab.dat","w");
    for(j=0;j<N;j++)
    {
        x1 = x + f(x,y) * h; //Atualiza x em 1 passo
        y1 = y + h * g(x); //Calcula aproximação de y(x)
        t = t + h;
        x = x1;
        y = y1;
        fprintf(arquivo,"%f %f %f \n",t,x,y);//Imprime x e y na tela
    }

    fclose(arquivo);

    printf("DONE.");

}
