#include<stdio.h>
main ()
{
    int N,soma=0,i,aux;
    printf("Digite um número: ");
    scanf("%d",&N);
    for (i=0;i<=N;i++)
    {
        aux=i*i;
        soma=soma+aux;
    }
    printf("A soma do quadrado de cada N primeiros inteiros positivos é: %d", soma);
}
