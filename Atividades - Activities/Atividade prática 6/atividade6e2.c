#include <stdio.h>
#include <math.h>
float fatorial (float f)
{
    if (f<=1.0)
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
        aux=((pow(x,2.0*i+1.0))/fatorial(2.0*i+1.0))*(pow(-1.0,i));
        SN=SN+aux;
    funcao=sin(x);
    }
    diferenca=fabs(funcao-SN);
    printf("O valor de SN é: %.10f \n",SN);
    printf("O valor da função f(x)=sen(x) é: %.10f \n",funcao);
    printf("A diferença de SN e da função f(x) é: %.10f \n",diferenca);
}
/*Nome	Descrição
acos	arco-coseno
asin	arco-seno
atan	arco-tangente
atan2	arco-tangente (círculo cheio)
ceil	Arredonda para cima
cos	co-seno
cosh	co-seno hiperbólico
exp	exponencial
fabs	valor absoluto (módulo de)
floor	Arredonda para baixo
fmod	resto de uma divisão
frexp	fracção norm./parte exp
ldexp	inverso de frexp
log	logaritmo natural
log10	logaritmo base 10
modf(x,p)	retorna a parte fraccionária de x e guarda a parte inteira para onde o apontador p aponta
pow(x,y)	retorna o resultado de x elevado a y
sin	seno
sinh	seno hiperbólico
sqrt	raiz quadrada
tan	tangente
tanh	tangente hiperólica */

