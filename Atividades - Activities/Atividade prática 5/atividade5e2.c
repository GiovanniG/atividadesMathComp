#include<stdio.h>
#include<math.h>
main ()
{
    float n,somaparcial=0,i,aux,somainfinita,eA,eR;
    printf("Entre com um inteiro: \n");
    scanf("%f",&n);
    somainfinita=2.0/3.0;
    for (i=0;i<=n;i++)
    {
        aux=1/(pow(-2,i));
        somaparcial=somaparcial+aux;
    }
    eA=fabs(somainfinita-somaparcial);
    eR=eA/somaparcial;
    printf("O valor da soma dos %.f primeiros números é: %.20f \n", n, somaparcial);
    printf("O erro absoluto dessa somatória é: %.20f \n",eA);
    printf("O erro relativo dessa somatória é: %.20f \n",eR);
}
