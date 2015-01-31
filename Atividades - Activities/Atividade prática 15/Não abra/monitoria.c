#include<stdio.h>

float f(float y, float x)
{
    return 10*(y-x);
}

float g(float x, float y, float z)
{
    return (x*(28-z))-y;
}

float a(float x, float y, float z)
{
    return (x*y)-((8.0/3.0)*z);
}


int main()
{

    int N,j;
    float h, x, y, t, p, z;
    float xnovo, ynovo, znovo;
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

    printf("Informe o valor inicial de z: y(t0): \n");
    scanf("%f",&z);
    //Etapa de integração, método de Euler.
    arquivo = fopen("dados.dat","w");
    for(j=0;j<N;j++)
    {
       xnovo=f(y, x)*h + x;
       ynovo=g(x,y,z)*h + y;
       znovo=a(x, y, z)*h + z;
       t=t+h;
       x=xnovo;
       y=ynovo;
       z=znovo;
        fprintf(arquivo,"%f %f %f %f\n",t,x,y,z);//Imprime x e y na tela
    }

    fclose(arquivo);

    printf("DONE.");

}
