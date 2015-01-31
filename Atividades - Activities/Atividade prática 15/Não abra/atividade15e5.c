#include<stdio.h>

double dxdt(double x, double y)
{
    return 10*(y-x);
}

double dydt(double x, double y, double z)
{
    return x*(28-z)-y;
}

double dzdt(double x, double y, double z)
{
    return x*y-(8/3)*z;
}

int main()
{

    int N,j;
    double h, x, y, t=0.0, p, z, dxdtnovo, dydtnovo, dzdtnovo;
    FILE *arquivo;

    //Valor do passo de integração (DELTAx)
    printf("Escolha o passo de integração: \n");
    scanf("%lf",&h);

    //Número de pontos de integração
    printf("Escolha o número de pontos de integração: \n");
    scanf("%d",&N);

    //Condições iniciais das variáveis dependente y(x) e independente x
    printf("Informe o valor inicial de x: x(t0) \n");
    scanf("%lf",&x);

    printf("Informe o valor inicial de y: y(t0): \n");
    scanf("%lf",&y);

    printf("Informe o valor inicial de z: z(t0): \n");
    scanf("%lf",&z);

    //Etapa de integração, método de Euler.
    arquivo = fopen("dados.dat","w");
    for(j=0;j<N;j++)
    {
        //Calcula aproximação de x(t0)
        dxdtnovo = dxdt(x,y)*h + x;
        //Calcula aproximação de y(t0)
        dydtnovo = dydt(x,y,z)*h + y;
        //Calcula aproximação de z(t0)
        dzdtnovo = dzdt(x,y,z)*h + z;

        //Atualiza t em 1 passo
        t = t + h;

        x=dxdtnovo;
        y=dydtnovo;
        t=dzdtnovo;

        //Imprime t, x, y e z na tela
        fprintf(arquivo,"%lf %lf %lf %lf \n",t ,x ,y ,z ); //memorizar por causa das colunas(1=t;2=x;3=y;4=z)
    }

    fclose(arquivo);

    printf("DONE.");

}
