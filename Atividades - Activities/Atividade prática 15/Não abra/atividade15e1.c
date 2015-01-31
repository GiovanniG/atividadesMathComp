#include<stdio.h>

float f(float y)
{
    return 1-0.4*y;
}

int main()
{

    int N,j;
    float h, x, y;
    FILE *arquivo;

    //Valor do passo de integraÃ§Ã£o (DELTAx)
    printf("Escolha o passo de integraÃ§Ã£o: \n");
    scanf("%f",&h);

    //NÃºmero de pontos de integraÃ§Ã£o
    printf("Escolha o nÃºmero de pontos de integraÃ§Ã£o: \n");
    scanf("%d",&N);

    //CondiÃ§Ãµes iniciais das variÃ¡veis dependente y(x) e independente x
    printf("Informe o valor inicial de x: x0 \n");
    scanf("%f",&x);

    printf("Informe o valor inicial de y: y(x0): \n");
    scanf("%f",&y);

    //Etapa de integraÃ§Ã£o, mÃ©todo de Euler.
    arquivo = fopen("dados.dat","w");
    for(j=0;j<N;j++)
    {
        y = f(y)*h + y; //Calcula aproximaÃ§Ã£o de y(x)
        x = x + h; //Atualiza x em 1 passo
        fprintf(arquivo,"%f %f\n",x,y);//Imprime x e y na tela
    }

    fclose(arquivo);

    printf("DONE.");

}
