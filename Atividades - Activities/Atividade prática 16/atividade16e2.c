#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * exp(x);
}

int main()
{

    float x;
    float h;
    float erroA;
    float D;

    //Insira um valor para x
    printf("Digite o valor de 'x' para ser derivado:\n");
    scanf("%f",&x);

    //Insira um valor para a largura do intervalo(quanto menor o valor, mais preciso será o resultado)
    printf("Digite o valor de 'h':\n");
    scanf("%f",&h);

    //Diferenças finitas centrais
    D = 1.0/(2*h) * ( f(x+h) - f(x-h));

    //calculo do erro absoluto
    erroA=fabs(22.167168-D);

    //imprimindo a derivada e o erro
    printf("\nO valor da derivada é %f",D);
    printf("\nO valor do erro absoluto é %f\n",erroA);

}
