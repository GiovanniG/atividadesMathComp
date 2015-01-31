#include<stdio.h>
#include<math.h>
float f(float x)
{
    return (1/8.53) * x;
}
float g(float y, float x)
{
    return (8.53) * (x - ((1/3) * pow(x,3))) - y;
}
int main()
{

    int N,j;
    float h, x, y, t=0;
    FILE *arquivo;

    //Valor do passo de integra��o (DELTAx)
    printf("Escolha o passo de integra��o: \n");
    scanf("%f",&h);

    //N�mero de pontos de integra��o
    printf("Escolha o n�mero de pontos de integra��o: \n");
    scanf("%d",&N);

    //Condi��es iniciais das vari�veis dependente y(x) e independente x
    printf("Informe o valor inicial de x: x0 \n");
    scanf("%f",&x);
    printf("Informe o valor inicial de y: y(x0): \n");
    scanf("%f",&y);

    //Etapa de integra��o, m�todo de Euler.
    arquivo = fopen("dados.dat","w");
    for(j=0;j<N;j++)
    {
        x = f(x) * h + x; //Calcula aproxima��o de y(x)
        y = g(y ,x) * h + y; //Calcula aproxima��o de y(x)
        t = t + h; //Atualiza x em 1 passo
        fprintf(arquivo,"%f %f %f\n",x,y,t);//Imprime x e y na tela
    }
    fclose(arquivo);
    printf("DONE.");
}
