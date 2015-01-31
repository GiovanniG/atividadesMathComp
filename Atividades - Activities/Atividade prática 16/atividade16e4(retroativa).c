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

    //Diferenças finitas retroativas
    D = 1.0/(2*h) * ( f(x-2*h) - 4*f(x-h) + 3*f(x));

    //imprimindo a derivada
    printf("\nO valor de f(x) é %f",fx);
    printf("\nO valor da derivada é %f",D);

}

