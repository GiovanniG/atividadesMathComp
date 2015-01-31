#include<stdio.h>
#include<math.h>

float dxdt(float x, float y)
{
    return 10.00*(y-x);
}

float dydt(float x, float y, float z)
{
    return x*(28.00-z)-y;
}

float dzdt(float x, float y, float z)
{
    return (x*y)-(8.0/3.0)*z;
}

int main()
{

    int N,j;
    float h, x, y, z, t=0.0;
    FILE *arquivo;

    //Valor do passo de integração (DELTAx)
    printf("Escolha o passo de integração: \n");
    scanf("%f",&h);

    //Número de pontos de integração
    printf("Escolha o número de pontos de integração: \n");
    scanf("%d",&N);

    //Condições iniciais das variáveis dependente y(x) e independente x
    printf("Informe o valor inicial de x: x(t0): \n");
    scanf("%f",&x);
    printf("Informe o valor inicial de y: y(t0): \n");
    scanf("%f",&y);
    printf("Informe o valor inicial de z: z(t0): \n");
    scanf("%f",&z);

    //Etapa de integração, método de Euler.
    arquivo = fopen("dados15e5.dat","w");
    for(j=0;j<N;j++)
    {
        x = dxdt(x, y) * h + x; //Calcula aproximação de x(t)
        y = dydt(x, y, z) * h + y; //Calcula aproximação de y(t)
        z = dzdt(x, y, z) * h + z; //Calcula aproximação de z(t)

        t = t + h; //Atualiza x em 1 passo

        fprintf(arquivo,"%f %f %f %f\n",x,y,z,t);//Imprime x,y,z,t na tela
    }
    fclose(arquivo);
    printf("DONE.");
}
