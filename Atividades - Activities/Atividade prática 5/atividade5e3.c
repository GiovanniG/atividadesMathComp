#include<stdio.h>
#include<math.h>
main ()
{
    float epsilon,i,S,eR,somainfinita;
    printf("Digite um decimal ente 0 e 1: \n");
    scanf("%f",&epsilon);
    i=0;
    S=0.0;
    eR=1.0;
    somainfinita=1.0;
    eR=fabs(somainfinita-S)/S;
    while (eR > epsilon)
    {
        i=i+1;
        S=S+(1.0/(i*(i+1.0)));
        eR=fabs(somainfinita-S)/S;
    }
    printf("O valor final da soma parcial é %.5f: \n",S);
    printf("Quantidade de iterações: %.f",i);
}
