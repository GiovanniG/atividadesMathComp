#include<stdio.h>
main ()
{
    int N,soma=0,i;
    printf("Digite um número: ");
    scanf("%d",&N);
    for (i=0;i<=N;i++)
    {
        soma=soma+i;
    }
    printf("A soma dos N primeiros inteiros positivos é: %d", soma);
}
