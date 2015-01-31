#include <stdio.h>
#include <math.h>
float fatorial (float f) //início da função fatorial;
{
    if (f<=1.0) // se o valor de f<
        return 1.0;
    else
        return (f*fatorial(f-1.0));
}
main ()
{
    float N,x,i,aux,SN,funcao,diferenca;
    printf("Digite um inteiro positivo: \n");
    scanf("%f",&N);
    printf("Digite um valor de x: \n");
    scanf("%f",&x);
    SN=0.0;
    for (i=0.0;i<=N;i++)
    {
        aux=((pow(x,i))/fatorial(i));
        SN=SN+aux;
    }
    funcao=exp(x);
    diferenca=fabs(funcao-SN);
    printf("O valor de SN é: %.10f \n",SN);
    printf("O valor da função f(x)=esp(x) é: %.10f \n",funcao);
    printf("A diferença de SN e da função f(x) é: %.10f \n",diferenca);
}
