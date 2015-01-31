#include <stdio.h>
#include <math.h>

/*
x=1.1 :
x=1.2 :
x=1.3 :
x=1.4 :
*/

float f(float x)
{
    return exp(2.0*x);
}

int main()
{

    float x;
    float h;
    float fx;
    float D;

    //Insira um valor para x
    printf("Digite o valor de 'x' para ser derivado:\n");
    scanf("%f",&x);

    //Insira um valor para a largura do intervalo(quanto menor o valor, mais preciso será o resultado)
    printf("Digite o valor de 'h':\n");
    scanf("%f",&h);

    //Calculando f(x)
    fx=f(x);

    //Diferenças finitas centrais
    D = 1.0/(2*h) * ( f(x+h) - f(x-h));

    //imprimindo a derivada
    printf("\nO valor de f(x) é %f",fx);
    printf("\nO valor da derivada é %f",D);

}

