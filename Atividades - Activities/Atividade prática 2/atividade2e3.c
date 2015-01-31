#include<stdio.h>
main ()
{
    float N,soma=0,i,aux;
    printf("Digite um número: ");
    scanf("%f",&N);
    for (i=1;i<=N;i++)
    {
        aux=1/i;
        soma=soma+aux;
    }
    printf("A soma do inverso dos N primeiros inteiros positivos é: %.2f", soma);
}
